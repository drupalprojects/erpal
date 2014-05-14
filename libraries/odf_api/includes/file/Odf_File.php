<?php

class Odf_File {

  /**
   * Manifest namespace URI.
   */
  const NS_MANIFEST = 'urn:oasis:names:tc:opendocument:xmlns:manifest:1.0';

  /**
   * Text namespace URI.
   */
  const NS_TEXT = 'urn:oasis:names:tc:opendocument:xmlns:text:1.0';

  /**
   * Style namespace URI.
   */
  const NS_STYLE = 'urn:oasis:names:tc:opendocument:xmlns:style:1.0';

  /**
   * Fo namespace URI.
   */
  const NS_FO = 'urn:oasis:names:tc:opendocument:xmlns:xsl-fo-compatible:1.0';

  /**
   * Office namespace URI.
   */
  const NS_OFFICE = 'urn:oasis:names:tc:opendocument:xmlns:office:1.0';

  /**
   * SVG namespace URI.
   */
  const NS_SVG = 'urn:oasis:names:tc:opendocument:xmlns:svg-compatible:1.0';

  /**
   * Xlink namespace URI.
   */
  const NS_XLINK = 'http://www.w3.org/1999/xlink';

  /**
   * Path to the folder with default template for ODF file.
   */
  private $odf_template = '/template/default.odt';

  /**
   * Params for a new ODF file.
   */
  private $odf_file_path;
  private $odf_file_name;

  /**
   * File mimetype.
   */
  private $mimetype = 'application/vnd.oasis.opendocument.text';


  public $content;
  public $meta;
  public $settings;
  public $styles;
  public $manifest;

  public function __construct($file_name, $file_path = '', $odf_template_file = false) {
    $this->odf_file_path = $file_path ? $file_path . '/' : '';
    $this->odf_file_name = $file_name;

    $zip = new ZipArchive();
    $this->odf_template = $odf_template_file ? $odf_template_file : dirname(dirname(__DIR__)).$this->odf_template;
    $zip->open($this->odf_template);

    // Get the template data of ODF document.
    $this->content  = new Odf_File_Content($zip);
    $this->meta     = new Odf_File_Meta($zip);
    $this->settings = new Odf_File_Settings($zip);
    $this->styles   = new Odf_File_Styles($zip);
    $this->manifest = new Odf_File_Manifest($zip);

    $zip->close();
  }

  /**
   * Add any element to the odf file.
   */
  public function addElement(Odf_Element $element) {
    $element->render($this);
  }

  /**
   * Save the ODF file.
   */
  public function save() {

    $zip_file_path = $this->odf_file_path . $this->odf_file_name;

    $zip = new ZipArchive();
    $zip->open($zip_file_path, ZIPARCHIVE::CREATE | ZIPARCHIVE::OVERWRITE);

    // Add a mimetype to a manifest.
    $this->manifest->addMimeType($this->mimetype);

    // Save content xml.
    $this->manifest->addFile($this->content->filename, 'text/xml');
    $this->content->save($zip);

    // Save meta xml.
    $this->manifest->addFile($this->meta->filename, 'text/xml');
    $this->meta->save($zip);

    // Save styles xml.
    $this->manifest->addFile($this->styles->filename, 'text/xml');
    $this->styles->save($zip);

    // Save settings xml.
    $this->manifest->addFile($this->settings->filename, 'text/xml');
    $this->settings->save($zip);

    // Import media files from default template.
    $this->manifest->importDefaultMediaFiles($zip);

    // Add file with manifest to the ODF document.
    $zip->addFromString('META-INF/manifest.xml', $this->manifest->render());

    // Add file with mime type to the ODF document.
    $zip->addFromString('mimetype', $this->mimetype);

    // Add media files listed in manifest to the archive.
    $files = $this->manifest->getMediaFiles();
    foreach ($files as $archive_filepath => $current_filepath) {
      $zip->addFromString($archive_filepath, file_get_contents($current_filepath));
    }

    $zip->close();
  }

  /**
   * Increase lines counter.
   */
  public function newLine() {
    $empty_p = new Odf_Element_Text_Paragraph();
    $empty_p->render($this);
  }

  /**
   * Add an empty lines.
   */
  public function newLines($count = 2) {
    for ($i = 0; $i < $count; $i++) {
      $this->newLine();
    }
  }

  /**
   * Add a page break.
   */
  public function pageBreak() {
    $break_p = new Odf_Element_Text_Paragraph();
    $break_p_style = new Odf_Style_Text_Paragraph();
    $break_p_style->setBreak();
    $break_p->applyStyle($break_p_style);
    $break_p->render($this);
  }

}
