<?php

class Odf_File_Manifest {

  /**
   * DOM document containing the manifest.
   */
  protected $dom;

  /**
   * Root node to add file entries to.
   */
  protected $fileroot;

  /**
   * List of media files.
   */
  protected $mediaFiles = array();

  /**
   * List of media files that should be imported from
   * default template to a new created document.
   */
  protected $templateMediaFiles = array();

  /**
   * Create a DOMDocument with basic data for manifest file.
   */
  public function __construct(ZipArchive $zip) {

    $this->dom = new DOMDocument('1.0', 'utf-8');
    $this->dom->formatOutput = TRUE;

    $this->fileroot = $this->dom->createElementNS(
      Odf_File::NS_MANIFEST,
      'manifest:manifest'
    );

    $this->dom->appendChild($this->fileroot);

    // Read old media files.
    $file = $zip->getFromIndex($zip->locateName('META-INF/manifest.xml'));

    $old_manifest = new DOMDocument();
    $old_manifest->loadXML($file);
    $xpath = new DOMXPath($old_manifest);
    $entries = $xpath->query('/manifest:manifest/manifest:file-entry');
    foreach ($entries as $entry) {
      $mimetype = $entry->attributes->getNamedItem('media-type');
      if (!empty($mimetype->value) && in_array($mimetype->value, array('image/jpeg', 'image/png'))) {
        $filepath = $entry->attributes->getNamedItem('full-path');
        if (!empty($filepath)) {
          $index = $zip->locateName($filepath->value);
          $this->templateMediaFiles[$filepath->value] = array(
            'content' => $zip->getFromIndex($index),
            'mimetype' => $mimetype->value,
          );
        }
      }
    }
  }


  /**
   * Add a file to the manifest.
   */
  public function addFile($file, $mimetype) {

    $entry = $this->dom->createElementNS(
      Odf_File::NS_MANIFEST,
      'manifest:file-entry'
    );

    $entry->setAttributeNS(
      Odf_File::NS_MANIFEST,
      'manifest:full-path',
      $file
    );

    $entry->setAttributeNS(
      Odf_File::NS_MANIFEST,
      'manifest:media-type',
      $mimetype
    );

    $this->fileroot->appendChild($entry);
  }

  /**
   * Add a file and keeps its name.
   */
  public function addFileMedia($filepath, $filename, $mimetype) {
    $this->addFile($filename, $mimetype);
    $this->mediaFiles[$filename] = $filepath;
  }

  public function getMediaFiles() {
    return $this->mediaFiles;
  }

  public function importDefaultMediaFiles(ZipArchive $zip) {
    foreach ($this->templateMediaFiles as $filepath => $data) {
      $zip->addFromString($filepath, $data['content']);
      $this->addFile($filepath, $data['mimetype']);
    }
  }

  /**
   * Add mime type entry to manifest.
   */
  public function addMimeType($mimetype) {

    $entry = $this->dom->createElementNS(
      Odf_File::NS_MANIFEST,
      'manifest:file-entry'
    );

    $entry->setAttributeNS(
      Odf_File::NS_MANIFEST,
      'manifest:full-path',
      '/'
    );

    $entry->setAttributeNS(
      Odf_File::NS_MANIFEST,
      'manifest:media-type',
      $mimetype
    );

    $entry->setAttributeNS(
      Odf_File::NS_MANIFEST,
      'manifest:version',
      '1.2'
    );

    $this->fileroot->appendChild($entry);
  }

  /**
   * Returns the full XML representation of the manifest.
   */
  public function render() {
    return $this->dom->saveXML();
  }

}
