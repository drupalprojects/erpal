<?php

/**
 * Plugin to export Docs as .odt file.
 */
$plugin = array(
  'type' => 'OpenDocument',
  'handler' => array(
    'class' => 'DocumentOdtExport',
  ),
);


/**
 * Class to export Docs as .odt file.
 */
class DocumentOdtExport extends document_export {

	public $available_html_tags =
	  '<p>
		 <ul>
		 <li>
		 <table>
		 <tr>
		 <th>
		 <td>
		 <h1>
		 <h2>
		 <h3>
		 <h4>
		 <h5>
		 <h6>
		 <b>
		 <strong>
		 <img>
		 <end>
		 <em>';

	public $odf_file = FALSE;
	
	// 1 cm = 38px.
	public $cm = 38;
	
	// Max weight for image will be.
	public $maxWidth = 10.04;

	// Max height for image will be.
	public $maxHeight = 14.04;

	/**
	 * Class constructur.
	 */
  function __construct($options){
    parent::__construct($options);
    if($this->requireOdtApi()){

			// Load All needed classes.
			Odf_Class_Autoloader::init();
      $this->file_path = $this->createDocument($options);  
    }
		else {
      throw new Exception("Error loading the odt_api libraries");
    }
  }

	/**
	 * Save file in drupal and attach it to node.
	 */
  public function save($uri, $filename){
    if($this->requireOdtApi()){
      	global $user;

	    $filepath = drupal_realpath($uri.$filename);
	    $filepath = file_destination($filepath, FILE_EXISTS_RENAME);

	    copy($this->file_path, $filepath);

	    // Begin building file object.
	    $file = new stdClass();
	    $file->uid      = $user->uid;
	    $file->status   = 1; //final!
	    $file->filename = $filename;
	    $file->uri      = $uri.basename($filepath);
	    $file->filemime = file_get_mimetype($filepath);
	    $file->filesize = filesize($filepath);   
	    file_save($file);
	    return $file;  	
	
    } else {
    	return false;
    }
      
  }


	/**
	 * Output file to user.
	 */
  public function stream($filename){
  	if($this->requireOdtApi()){
	    $this->stream_file($filename, $this->file_path, 'application/vnd.oasis.opendocument.text');
  	}
		else{
  		return FALSE;
  	}
  }


	/**
	 * Extension of file which generate this plugin.
	 */
	public function fileExtension(){
  	return 'odt';
  }


	/**
	 * Create and render document.
	 */
  private function createDocument($options){

    // Create a new odt Document and add data.
		$file_path = variable_get('file_public_path', conf_path() . '/files') .'/' . REQUEST_TIME . $this->fileExtension();
    $odf_template_fid = variable_get('document_export_odf_template_fid', false);
    
    //get an individual template odt file if one was uploaded at the document exporter
    $document_fid = variable_get('document_export_odf_template_fid', false);
    $template_path = false;
    
    if ($document_fid) {
      $file = file_load($document_fid);
      $template_path = drupal_realpath($file->uri);
    } else {
      //show a hint to the user if he has not yet uploaded an individual template for ODF export
      $basic_config_link = l(t('ERPAL basic settings'), 'admin/erpal/basic');
      drupal_set_message(t('You can upload your own ODT file as a template for the export in the !link', array('!link' => $basic_config_link)));
    }
    
    $this->odf_file = new Odf_File($file_path, '', $template_path);

		// Create default style for paragraph.
		$default_text_style = $this->createDefaultTextStyle();
		
		// Create front page.
		if (!empty($options['frontpage'])) {
			$this->createFrontPage($options);
		}
		
		// Create Table of contents.
		$this->toc = NULL;
    if (!empty($options['toc'])) {
			$this->createTableOfContent();
		}
		
		// Automatically nummerize titles.
		$this->title_count = FALSE;
		if (!empty($options['options']['title_count'])) {
			$this->title_count = TRUE;
		}

		// Render pages.
		foreach ($this->pages as $key => $page) {
			
			// Default depth is 1.
			if (empty($page['depth'])) {
				$page['depth'] = 1;
			}

			// Add title of page.
			if (!empty($page['comment'])) {
				$header = new Odf_Element_Text_Heading($page['title'], $page['depth'], FALSE);
				$header->applyStyle($this->createHeaderTextStyle($page['depth']));
				$this->odf_file->addElement($header);
			}
			else {
				$header = new Odf_Element_Text_Heading($page['title'], $page['depth'], $this->title_count, $this->toc);
				$header->applyStyle($this->createHeaderTextStyle($page['depth']));
				$this->odf_file->addElement($header);
			}

			// Add nids of node.
			if (!empty($page['add_nids']) && !empty($page['nid'])) {
				$text = new Odf_Element_Text_Paragraph(t('NID: !nid', array('!nid' => $page['nid'])));
				$text->applyStyle($default_text_style);
				$this->odf_file->addElement($text);
				$this->odf_file->newLine();
			}

			// Add text of body.
			// Remove html special chars, because odt not works with it.
			$page['body'] = str_replace('&nbsp;', ' ', $page['body']);
			$page['body'] = preg_replace("/&#?[a-z0-9]+;/i"," ",$page['body']);
			
			// Add tag <end> to file.
			$page['body'] .= '<end></end>';
			$this->parseHtml(strip_tags($page['body'], $this->available_html_tags));
			$this->odf_file->newLine();

			// Add estimation.
			if (!empty($page['estimation'])) {
				$text = new Odf_Element_Text_Paragraph(t('Estimated time: !time h', array('!time' => $page['estimation'])));
				$text->applyStyle($default_text_style);
				$this->odf_file->addElement($text);
				$this->odf_file->newLine();
			}

			// Add Page break after each book page.
			$keys = array_keys($this->pages);
			if (!empty($options['page_breaks']) && $key != end($keys)) {
				if (empty($this->pages[$key + 1]['comment'])) {
					$this->odf_file->pageBreak();
				}
			}

		}

		// File save.
		$this->odf_file->save();

    return $file_path;   
  }
	
	
	/**
	 * Create a front page.
	 */
  private function createFrontPage($options){
		
		// Add logo to front page.
		if (!empty($options['frontpage']['logo'])) {
      $this->addLogo($options);
		}
		
		// Add title to front page.
		$this->addTitle($options);
		
		// Add date to front page.
		if (!empty($options['frontpage']['date'])) {
		  $this->addDate($options);
		}
		
		// Add customer to front page.
		if (!empty($options['frontpage']['address'])) {
		  $this->addCustomer($options);
		}
		
    $this->odf_file->pageBreak();
  }


	/**
	 * Add logo to front page.
	 */
  private function addLogo($options){

    // Create image style.
		$this->odf_file->newLines(5);
		$image_style = new Odf_Style_Image();
		$image_style->setHeight('6.4cm');
		$image_style->setWidth('14cm');
		$image_style->setOffsetX('1.5cm');
		$image_style->setOffsetY('0.5cm');

		// Create new image.
		$image = new Odf_Element_Image($this->getImagePath($options['frontpage']['logo']));
		$image->applyStyle($image_style);

		// Add image to the document.
		$paragraph = new Odf_Element_Text_Paragraph($image);
		$this->odf_file->addElement($paragraph);
		$this->odf_file->newLines(5);
  }
	
	
	/**
	 * Add title to front page.
	 */
  private function addTitle($options){

    // Create a style for a title.
		$title_style = new Odf_Style_Text_Paragraph();
		$title_style->setTextColor('#808080');
		$title_style->setFontSize('28pt');
		$title_style->setFontFamily('Sansation');
		$this->addMarginToParagraph($title_style);
		
		// Create new text.
		$title = new Odf_Element_Text_Paragraph($options['frontpage']['title']);
		$title->applyStyle($title_style);
		$this->odf_file->addElement($title);
		$this->odf_file->newLines(5);
  }


	/**
	 * Get image path.
	 */
  private function getImagePath($url){
		$private_url = url('system/files', array('absolute' => TRUE));
		$public_url = url(variable_get('file_public_path', conf_path() . '/files'), array('absolute' => TRUE));

		if (strpos($url, $private_url) === 0) {
		  $uri = 'private://' . substr($url, strlen($private_url) + 1);
		}
		elseif (strpos($url, $public_url) === 0) {
		  $uri = 'public://' . substr($url, strlen($public_url) + 1);
		}
		else {      
			return $url;
		}

		return drupal_realpath($uri);
  }


	/**
	 * Add date to front page.
	 */
  private function addDate($options){

    $paragraph = new Odf_Element_Text_Paragraph(t('Date'));
		$paragraph->applyStyle($this->createBoldTextStyle());
		$this->odf_file->addElement($paragraph);
		$this->odf_file->newLine();
		
		$date = new Odf_Element_Text_Date($options['frontpage']['date'], time());

		// Create a style for a date display.
		$date_style = new Odf_Style_Date();
		$date_style->setDayStyle('long');
		$date_style->setMonthStyle('long');
		$date->applyStyle($date_style);
		
		// Add date element to the text.
		$paragraph = new Odf_Element_Text_Paragraph($date);
		$paragraph->applyStyle($this->createDefaultTextStyle());
		$this->odf_file->addElement($paragraph);
		$this->odf_file->newLine();
  }
	
	
	/**
	 * Add customer to front page.
	 */
  private function addCustomer($options){

    $paragraph = new Odf_Element_Text_Paragraph(t('Customer'));
		$paragraph->applyStyle($this->createBoldTextStyle());
		$this->odf_file->addElement($paragraph);
		$this->odf_file->newLine();
		
		foreach ($options['frontpage']['address'] as $item) {
			$paragraph = new Odf_Element_Text_Paragraph($item);
			$paragraph->applyStyle($this->createDefaultTextStyle());
			$this->odf_file->addElement($paragraph);
		}
  }
	

	/**
	 * Create Table of contents.
	 */
  private function createTableOfContent(){
    $toc = new Odf_Element_Toc(t('Table of contents'));

		// Set style for heading items.
		$toc_style = new Odf_Style_Text_Paragraph();
		$toc_style->setFontSize('10pt');
		$toc_style->setFontFamily('Verdana');
		$toc_style->setLineHeight('150%');
		$toc_style->includeTabStops();
		$toc->applyStyle($toc_style);

		// Add Table of content to the document.
		$this->odf_file->addElement($toc);
		$this->odf_file->pageBreak();
		$this->toc = $toc;
  }


  /**
	 * Create heading style for paragraph.
	 */
  private function createHeaderTextStyle($depth, $type = 'paragraph'){
		// The deeper  - the smaller font.
		$pt = 18 - 2 * $depth;
    $header_text_style = new Odf_Style_Text_Paragraph();
		$this->addMarginToParagraph($header_text_style);
		if ($type == 'span') {
			$header_text_style = new Odf_Style_Text_Span();
		}
		$header_text_style->setFontSize($pt . '.pt');
		$header_text_style->setFontWeight('bold');
		$header_text_style->setFontFamily('Sansation');
	  $header_text_style->setLineHeight('150%');
		$text_indent = -1.4 ;	
    if ($depth > 2) {
			$text_indent = $text_indent / 3;
		}
		$header_text_style->setTextIndent($text_indent . 'cm');
		$margin_left = 2.1 - $text_indent;
		$header_text_style->setMarginLeft($margin_left . 'cm');
		return $header_text_style;
  }

	/**
	 * Create default style for paragraph.
	 */
  private function createDefaultTextStyle($type = 'paragraph', $list = FALSE){
		$default_text_style = new Odf_Style_Text_Paragraph();
		$this->addMarginToParagraph($default_text_style);
		if ($type == 'span') {
			$default_text_style = new Odf_Style_Text_Span();
		}
		$default_text_style->setFontSize('10pt');
		$default_text_style->setFontFamily('Verdana');
	  $default_text_style->setLineHeight('150%');
		// If paragraph is list we just add text indent.
		if ($list) {
			$default_text_style->setMarginLeft('2.9cm');
			$default_text_style->setTextIndent('-0.8cm');
		}
		return $default_text_style;
  }
	
	
	/**
	 * Create Bold style for paragraph.
	 */
  private function createBoldTextStyle($type = 'paragraph'){
		$text_bold_style = new Odf_Style_Text_Paragraph();
		$this->addMarginToParagraph($text_bold_style);
		if ($type == 'span') {
			$text_bold_style = new Odf_Style_Text_Span();
		}
		$text_bold_style->setFontSize('12pt');
		$text_bold_style->setFontWeight('bold');
		$text_bold_style->setFontFamily('Sansation');
		return $text_bold_style;
  }

	/**
	 * Add margins to Paragraph.
	 */
  private function addMarginToParagraph(&$style){
		$style->setMarginLeft('2.1cm');
		$style->setMarginRight('1.4cm');
  }


	/**
	 * Parse htms and add to odt document.
	 */
  private function parseHtml($html){
		$html_dom = new simple_html_dom();
    $html_dom->set_callback(array($this, 'renderHtmlTag'));
    $html_dom->load($html);
    $html_dom->__toString();
  }


	/**
	 * Render html tag.
	 */
  public function renderHtmlTag($tag){
    
		// Group html tags.
		$header = array('h1', 'h2', 'h3', 'h4', 'h5', 'h6');
		$table = array('table', 'tr', 'th', 'td');
		$list = array('ul', 'li');
		$bold = array('b', 'strong');

		// Route tags.
		if (in_array($tag->tag, $header)) {
			$this->htmlTag_Header($tag);
		}
		elseif (in_array($tag->tag, $table)) {
			$this->htmlTag_Table($tag);
		}
		elseif (in_array($tag->tag, $list)) {
			$this->htmlTag_List($tag);
		}
		elseif (in_array($tag->tag, $bold)) {
			$this->htmlTag_b($tag);
		}
		else {
			$method_name = "htmlTag_{$tag->tag}";
			$this->$method_name($tag);
		}

		$this->addParagraphToFile($tag);
		
		// Save current tag as last which rendered.
		$this->last_tag = $tag;
  }
	
	/**
	 * Add Paragraph to file.
	 */
  public function addParagraphToFile(&$tag){

		//If last tag text and current tag not text then add new Paragraph.
		if (!empty($this->last_text) && !empty($this->last_tag)) {
			$paragraph_tags = array('b', 'strong', 'text', 'em');
			if(!in_array($tag->tag, $paragraph_tags)) {
				$this->odf_file->addElement($this->last_text);
				unset($this->last_text);
			}
		}
  }
	
	/**
	 * Create new Paragraph.
	 */
  public function createNewParagraph(){
    if (empty($this->last_text)) {
			$this->last_text = new Odf_Element_Text_Paragraph();
			$this->last_text->applyStyle($this->createDefaultTextStyle());
		}
  }


	/**
	 * Render html tag text.
	 */
  public function htmlTag_text(&$tag){
		if (!empty($this->last_tag->rendered)) {
			return;
		}
    if (trim($tag->text())) {
		  $this->createNewParagraph();
			$text = new Odf_Element_Text_Span($tag->text());
			$text->applyStyle($this->createDefaultTextStyle('span'));
			$this->last_text->addData($text);
		}
  }

	/**
	 * Render html tag h1 - h6.
	 */
  public function htmlTag_Header(&$tag){
    $text = new Odf_Element_Text_Paragraph($tag->text());
		$style = $this->createBoldTextStyle();
		$size = 24 - $tag->tag[1] * 2;
		$style->setFontSize($size . 'pt');
		$text->applyStyle($style);
		$this->odf_file->addElement($text);
		$tag->rendered = TRUE;
  }

  /**
	 * Render html tag p.
	 */
  public function htmlTag_p(&$tag){
		$this->addParagraphToFile($tag);
		$this->createNewParagraph();
  }

	/**
	 * Render html tag b, strong.
	 */
  public function htmlTag_b(&$tag){
		$this->createNewParagraph();
    $text = new Odf_Element_Text_Span($tag->text());
		$text->applyStyle($this->createBoldTextStyle('span'));
		$this->last_text->addData($text);
		$tag->rendered = TRUE;
  }
	
	/**
	 * Render html tag em.
	 */
  public function htmlTag_em(&$tag){
		$this->createNewParagraph();
    $text = new Odf_Element_Text_Span($tag->text());
		$style = $this->createDefaultTextStyle('span');
		$style->setFontStyle('italic');
		$text->applyStyle($style);
		$this->last_text->addData($text);
		$tag->rendered = TRUE;
  }
	
	/**
	 * Render html tag ul, li.
	 */
  public function htmlTag_List(&$tag){

		// Create list.
		if ($tag->tag == 'ul') {
			$this->last_list = new Odf_Element_List();
		}

		if ($tag->tag == 'li' && !empty($this->last_list)) {

			// Add text to list
			$text = new Odf_Element_Text_Paragraph($tag->text());
		  $text->applyStyle($this->createDefaultTextStyle('paragraph', TRUE));
			$this->last_list[] = $text;

			// Create styles for bullet list.
			if (!$tag->next_sibling()) {
				$list_style = new Odf_Style_List('bullet');
				$this->last_list->applyStyle($list_style);
				$this->odf_file->addElement($this->last_list);
				unset($this->last_list);
			}
		}
    $tag->rendered = TRUE;
  }
	
	/**
	 * Render html tag table.
	 */
  public function htmlTag_Table(&$tag){

		// Create table.
		if ($tag->tag == 'table') {
			$this->table = array();
			// Create style for a table.
			$this->table['table_style'] = new Odf_Style_Table();
			$this->table['table_style']->setWidth('5.2465in');
			$this->table['table_style']->setAlign('left');
			$this->table['table_style']->setMarginLeft('0.8319in');

			// Create style for a table cell.
			$this->table['table_cell_style'] = new Odf_Style_Table_Cell();
			$this->table['table_cell_style']->setBackgroundColor('#e6e6e6');
			$this->table['table_cell_style']->setPadding('0.2cm');
			$border_style = '0.035cm solid #ffffff';
			$this->table['table_cell_style']->setBorderLeft($border_style);
			$this->table['table_cell_style']->setBorderRight($border_style);
			$this->table['table_cell_style']->setBorderTop($border_style);
			$this->table['table_cell_style']->setBorderBottom($border_style);

			// Create style for a table text.
			$this->table['table_text_style'] = new Odf_Style_Text_Paragraph();
			$this->table['table_text_style']->setFontFamily('Verdana');
			$this->table['table_text_style']->setFontWeight('bold');
			$this->table['table_text_style']->setFontSize('10pt');
			$this->table['table_text_style']->setLineHeight('150%');
			$this->table['rows'] = array();
		}

		if ($tag->tag == 'tr' && !empty($this->table)) {
      $this->table['tr'] = array();
			if (!$tag->next_sibling()) {
				$this->table['last_tr'] = TRUE;
			}
		}

		if ($tag->tag == 'th' && isset($this->table['tr'])) {
			$this->table['head_row'][] = $tag->text();
			if (!$tag->next_sibling()) {
				// Create one table row and apply styles for it.
				$this->table['table_row_head'] = new Odf_Element_Table_Row($this->table['head_row']);
				$this->table['table_row_head']->applyStyle($this->table['table_cell_style']);
				$this->table['table_row_head']->applyStyle($this->table['table_text_style']);
			}
		}
		
		if ($tag->tag == 'td' && isset($this->table['tr'])) {
			$this->table['tr'][] = $tag->text();
			if (!$tag->next_sibling()) {

				// Clone table cell style and change some attribute.
				$table_cell_style = clone $this->table['table_cell_style'];
				$table_cell_style->setBackgroundColor('#f6f6f6');
				
				// Clone table text style and change some attribute.
				$table_text_style = clone $this->table['table_text_style'];
				$table_text_style->setFontWeight('normal');
				
				// Create another one row and apply changed styles for them.
				$table_row_body = new Odf_Element_Table_Row($this->table['tr']);
				$table_row_body->applyStyle($table_cell_style);
				$table_row_body->applyStyle($table_text_style);
				$this->table['rows'][] = $table_row_body;
				if (!empty($this->table['last_tr'])) {
					if (!empty($this->table['table_row_head'])) {
						array_unshift($this->table['rows'], $this->table['table_row_head']);
					}

					// Create a new table.
					$table = new Odf_Element_Table($this->table['rows'], count($this->table['tr']));
					$table->applyStyle($this->table['table_style']);
					
					// Add a table to the ODF document.
					$this->odf_file->newLine();
					$this->odf_file->addElement($table);
				}
			}
		}
    $tag->rendered = TRUE;
  }


  /**
	 * Render html tag img.
	 */
  public function htmlTag_img(&$tag){
		// Create image style.
		$image_style = new Odf_Style_Image();
		
		if($size = getimagesize(urldecode($this->getImagePath($tag->getAttribute('src'))))) {

			// Prepare image size.
			$width = round($size[0]/$this->cm, 2);
			$height = round($size[1]/$this->cm, 2);

			$image_style->setHeight($height . 'cm');
			$image_style->setWidth($width . 'cm');

			// Add scale cases for images.
			if ($width >= $height && $width >= $this->maxWidth) {
				$image_style->setRelHeight('scale');
				$image_style->setRelWidth('75%');
			}
			if ($width < $height && $height >= $this->maxHeight) {
				$image_style->setRelHeight('50%');
				$image_style->setRelWidth('scale');
			}

			$alt = '';
			if ($tag->hasAttribute('alt')) {
				$alt = $tag->getAttribute('alt');
			}

			// Create new image.
			$image = new Odf_Element_Image_Box($this->getImagePath($tag->getAttribute('src')), $alt);
			$image->applyStyle($image_style);

			// Add image to the document.
			$paragraph = new Odf_Element_Text_Paragraph($image);
			$this->odf_file->addElement($paragraph);
		}

		$tag->rendered = TRUE;
  }
	
	/**
	 * Render html tag end.
	 */
  public function htmlTag_end(&$tag){}

  /**
	 * Check if librarie exists.
	 */
  private function requireOdtApi(){
		$path = libraries_get_path('odf_api');
    $htmltodocx = libraries_get_path('htmltodocx');
		if(file_exists($path . '/Odf_Class_Autoloader.php') && file_exists($htmltodocx . '/simplehtmldom/simple_html_dom.php')){
      require_once($path . '/Odf_Class_Autoloader.php');
			require_once($htmltodocx . '/simplehtmldom/simple_html_dom.php');
			return true;
		}
		else {
			$link = l('htmltodocx', 'http://htmltodocx.codeplex.com/downloads/get/615101');
			drupal_set_message(t('The libraries are not installed correctly. Please download and extract !link to your libraries folder', array('!link' => $link)), 'warning');
			$link = l('odf_api', 'https://github.com/spleshka/modules/tree/odf_api');
			drupal_set_message(t('The libraries are not installed correctly. Please download and extract !link to your libraries folder', array('!link' => $link)), 'warning');
			return false;
		}
  }

}