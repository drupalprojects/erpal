<?php

/**
 * @file
 * Example of ODF file creation.
 */

/**
 * Mandatory step!
 * Register class autoloader for the ODF documents.
 */

include 'Odf_Class_Autoloader.php';
Odf_Class_Autoloader::init();

/**
 * CREATE ODF FILE.
 */

$odf_file = new Odf_File('example.odt');

// Add 10 empty paragraphs to the text.
$odf_file->newLines(10);

/**
 * CREATE IMAGE.
 */

// Create image style.
$image_style = new Odf_Style_Image();
$image_style->setHeight('6.4cm');
$image_style->setWidth('14cm');
$image_style->setOffsetX('1.5cm');
$image_style->setOffsetY('0.5cm');

// Create new image.
$image = new Odf_Element_Image('images/bs_1.jpg');
$image->applyStyle($image_style);

// Add image to the document.
$paragraph = new Odf_Element_Text_Paragraph($image);
$odf_file->addElement($paragraph);
$odf_file->newLines(10);

/**
 * CREATE DEFAULT TEXT STYLE.
 */

$default_text_style = new Odf_Style_Text_Paragraph();
$default_text_style->setFontSize('10pt');
$default_text_style->setFontFamily('Verdana');
$default_text_style->setLineHeight('150%');

/**
 * CREATE TEXT.
 */

// Create a style for a title.
$title_style = new Odf_Style_Text_Paragraph();
$title_style->setTextColor('#808080');
$title_style->setFontSize('28pt');
$title_style->setFontFamily('Sansation');

// Create new text.
$title = new Odf_Element_Text_Paragraph('Titel');
$title->applyStyle($title_style);
$odf_file->addElement($title);
$odf_file->newLines(10);

// Create new style for the text.
$text_bold_style = new Odf_Style_Text_Paragraph();
$text_bold_style->setFontSize('12pt');
$text_bold_style->setFontWeight('bold');
$text_bold_style->setFontFamily('Sansation');
$text_bold_style->setTextColor('#7e0021');

// Create new text.
$paragraph = new Odf_Element_Text_Paragraph('Datum');
$paragraph->applyStyle($text_bold_style);
$odf_file->addElement($paragraph);
$odf_file->newLine();

/**
 * CREATE DATE ELEMENT.
 */

// Create new date.
$date = new Odf_Element_Text_Date('04.09.13', time());

// Create a style for a date display.
$date_style = new Odf_Style_Date();
$date_style->setDayStyle('long');
$date_style->setMonthStyle('long');
$date->applyStyle($date_style);

// Add date element to the text.
$paragraph = new Odf_Element_Text_Paragraph($date);
$odf_file->addElement($paragraph);
$odf_file->newLine();

/**
 * CREATE OTHER TEXT ELEMENTS.
 */

$paragraph = new Odf_Element_Text_Paragraph('Kunde');
$paragraph->applyStyle($text_bold_style);
$odf_file->addElement($paragraph);
$odf_file->newLine();

$paragraph = new Odf_Element_Text_Paragraph('Kunde');
$paragraph->applyStyle($default_text_style);
$odf_file->addElement($paragraph);

$paragraph = new Odf_Element_Text_Paragraph('Straße');
$paragraph->applyStyle($default_text_style);
$odf_file->addElement($paragraph);

$paragraph = new Odf_Element_Text_Paragraph('PLZ Ort');
$paragraph->applyStyle($default_text_style);
$odf_file->addElement($paragraph);
$odf_file->pageBreak();

/**
 * CREATE TABLE OF CONTENT.
 */

$toc = new Odf_Element_Toc('Inhaltsverzeichnis');

// Set style for heading items.
$toc_style = new Odf_Style_Text_Paragraph();
$toc_style->setFontSize('10pt');
$toc_style->setFontFamily('Verdana');
$toc_style->setLineHeight('150%');
$toc_style->includeTabStops();
$toc->applyStyle($toc_style);

// Add Table of content to the document.
$odf_file->addElement($toc);
$odf_file->pageBreak();

/**
 * CREATE HEADINGS.
 */

$heading1 = new Odf_Element_Text_Heading('Beispielinhalt - Dies ist eine Überschrift mit zwei Zeilen Text', 1, TRUE, $toc);
$odf_file->addElement($heading1);

$text = new Odf_Element_Text_Paragraph('Das hier ist ganz normaler Inhalt der nach einer Überschrift kommt.');
$text->applyStyle($default_text_style);
$odf_file->addElement($text);

$heading11 = new Odf_Element_Text_Heading('Tabelle', 2, TRUE, $toc);
$odf_file->addElement($heading11);

$text = new Odf_Element_Text_Paragraph('Das hier ist ganz normaler Inhalt der nach einer Überschrift kommt.');
$text->applyStyle($default_text_style);
$odf_file->addElement($text);
$odf_file->newLine();

/**
 * CREATE TABLE ELEMENT.
 */

// Create style for a table.
$table_style = new Odf_Style_Table();
$table_style->setWidth('15cm');

// Create style for a table cell.
$table_cell_style = new Odf_Style_Table_Cell();
$table_cell_style->setBackgroundColor('#e6e6e6');
$table_cell_style->setPadding('0.2cm');
$table_cell_style->setBorderLeft('0.035cm solid #ffffff');
$table_cell_style->setBorderRight('none');
$table_cell_style->setBorderTop('0.035cm solid #ffffff');
$table_cell_style->setBorderBottom('0.035cm solid #ffffff');

// Create style for a table text.
$table_text_style = new Odf_Style_Text_Paragraph();
$table_text_style->setFontFamily('Verdana');
$table_text_style->setFontWeight('bold');
$table_text_style->setFontSize('10pt');
$table_text_style->setLineHeight('150%');

// Create one table row and apply styles for it.
$table_row_head = new Odf_Element_Table_Row(array_fill(0, 4, 'Head'));
$table_row_head->applyStyle($table_cell_style);
$table_row_head->applyStyle($table_text_style);

// Clone table cell style and change some attribute.
$table_cell_style = clone $table_cell_style;
$table_cell_style->setBackgroundColor('#f6f6f6');

// Clone table text style and change some attribute.
$table_text_style = clone $table_text_style;
$table_text_style->setFontWeight('normal');

// Create another one row and apply changed styles for them.
$table_row_body = new Odf_Element_Table_Row(array_fill(0, 4, 'Content'));
$table_row_body->applyStyle($table_cell_style);
$table_row_body->applyStyle($table_text_style);

// Create the array which consists of table rows.
$table_rows = array();
$table_rows[] = $table_row_head;
$table_rows[] = $table_row_body;
$table_rows[] = $table_row_body;

// Create a new table.
$table = new Odf_Element_Table($table_rows, 4);
$table->applyStyle($table_style);

// Add a table to the ODF document.
$odf_file->addElement($table);
$odf_file->newLine();

// Add a text under table.
$text = new Odf_Element_Text_Paragraph('Das ist eine Tabelle. Sollte das oben beschriebene Vorgehen zur Formatierung einer Tabelle nicht funktionieren, kann man diese hier kopieren und verwenden');
$text->applyStyle($default_text_style);
$odf_file->addElement($text);

// Add a headings.
$heading12 = new Odf_Element_Text_Heading('Listen', 2, TRUE, $toc);
$odf_file->addElement($heading12);

$heading121 = new Odf_Element_Text_Heading('Aufzählungsliste', 3, TRUE, $toc);
$odf_file->addElement($heading121);

$text = new Odf_Element_Text_Paragraph('Hier kommt eine Aufzählungsliste');
$text->applyStyle($default_text_style);
$odf_file->addElement($text);

/**
 * CREATE LISTS ELEMENTS.
 */

// Create first level of list.
$first_lvl_list = new Odf_Element_List();

$text = new Odf_Element_Text_Paragraph('Das ist eine Aufzählungsliste die sowohl einzeilige als auch zweizeilige Aufzählungspunkte haben kann.');
$text->applyStyle($default_text_style);
$first_lvl_list[] = $text;

$text = new Odf_Element_Text_Paragraph('Erste Ebene lange Zeile um den Einzug von rechts feststellen zu können und dann geht es in die zweite Zeile');
$text->applyStyle($default_text_style);
$first_lvl_list[] = $text;

// Create second level of list.
$text = new Odf_Element_Text_Paragraph('Zweite Ebenelange Zeile um den Einzug von rechts feststellen zu können und dann geht es in die zweite Zeile');
$text->applyStyle($default_text_style);
$sec_lvl_list = new Odf_Element_List();
$sec_lvl_list[] = $text;

// Create third level of list.
$text = new Odf_Element_Text_Paragraph('Dritte Ebene lange Zeile um den Einzug von rechts feststellen zu können und dann geht es in die zweite Zeile');
$text->applyStyle($default_text_style);
$third_lvl_list = new Odf_Element_List();
$third_lvl_list[] = $text;

// Create fourth level of list.
$text = new Odf_Element_Text_Paragraph('Vierte Ebene lange Zeile um den Einzug von rechts feststellen zu können und dann geht es in die zweite Zeile');
$text->applyStyle($default_text_style);
$fourth_lvl_list = new Odf_Element_List();
$fourth_lvl_list[] = $text;

// Create fifth level of list.
$text = new Odf_Element_Text_Paragraph('Fünfte Ebene lange Zeile um den Einzug von rechts feststellen zu können und dann geht es in die zweite Zeile');
$text->applyStyle($default_text_style);
$fifth_lvl_list = new Odf_Element_List();
$fifth_lvl_list[] = $text;

// Create sixth level of list.
$text = new Odf_Element_Text_Paragraph('Sechste Ebene lange Zeile um den Einzug von rechts feststellen zu können und dann geht es in die zweite Zeile');
$text->applyStyle($default_text_style);
$sixth_lvl_list = new Odf_Element_List();
$sixth_lvl_list[] = $text;

// Create seventh level of list.
$text = new Odf_Element_Text_Paragraph('Siebte Ebene lange Zeile um den Einzug von rechts feststellen zu können und dann geht es in die zweite Zeile');
$text->applyStyle($default_text_style);
$seventh_lvl_list = new Odf_Element_List();
$seventh_lvl_list[] = $text;

// Create eighth level of list.
$text = new Odf_Element_Text_Paragraph('Achte Ebene lange Zeile um den Einzug von rechts feststellen zu können und dann geht es in die zweite Zeile');
$text->applyStyle($default_text_style);
$eighth_lvl_list = new Odf_Element_List();
$eighth_lvl_list[] = $text;

// Create ninth level of list.
$text = new Odf_Element_Text_Paragraph('Neunte Ebene lange Zeile um den Einzug von rechts feststellen zu können und dann geht es in die zweite Zeile');
$text->applyStyle($default_text_style);
$ninth_lvl_list = new Odf_Element_List();
$ninth_lvl_list[] = $text;

// Create tenth level of list.
$text = new Odf_Element_Text_Paragraph('Zehnte Ebene lange Zeile um den Einzug von rechts feststellen zu können und dann geht es in die zweite Zeile');
$text->applyStyle($default_text_style);
$tenth_lvl_list = new Odf_Element_List();
$tenth_lvl_list[] = $text;

// Create list hierarchy.
$ninth_lvl_list[0]->setChildren($tenth_lvl_list);
$eighth_lvl_list[0]->setChildren($ninth_lvl_list);
$seventh_lvl_list[0]->setChildren($eighth_lvl_list);
$sixth_lvl_list[0]->setChildren($seventh_lvl_list);
$fifth_lvl_list[0]->setChildren($sixth_lvl_list);
$fourth_lvl_list[0]->setChildren($fifth_lvl_list);
$third_lvl_list[0]->setChildren($fourth_lvl_list);
$sec_lvl_list[0]->setChildren($third_lvl_list);
$first_lvl_list[1]->setChildren($sec_lvl_list);

// Create styles for bullet list.
$list_style = new Odf_Style_List('bullet');
$first_lvl_list->applyStyle($list_style);
$odf_file->addElement($first_lvl_list);
$odf_file->newLine();

$text = new Odf_Element_Text_Paragraph('Dies ist ein Absatz, der nach einer Liste kommt');
$text->applyStyle($default_text_style);
$odf_file->addElement($text);

/**
 * CREATE NUMERIC LIST.
 */

$heading122 = new Odf_Element_Text_Heading('Nummerierte Liste', 3, TRUE, $toc);
$odf_file->addElement($heading122);

$first_lvl_list = new Odf_Element_List();

$text = new Odf_Element_Text_Paragraph('Erste Ebene');
$text->applyStyle($default_text_style);
$first_lvl_list[] = $text;

$text = new Odf_Element_Text_Paragraph('Noch ein Aufzählungspunkt');
$text->applyStyle($default_text_style);
$first_lvl_list[] = $text;

$secont_lvl_list = new Odf_Element_List();

$text = new Odf_Element_Text_Paragraph('Zweite Ebene');
$text->applyStyle($default_text_style);
$secont_lvl_list[] = $text;

$text = new Odf_Element_Text_Paragraph('Noch ein Aufzählungspunkt');
$text->applyStyle($default_text_style);
$secont_lvl_list[] = $text;

$third_lvl_list = new Odf_Element_List();

$text = new Odf_Element_Text_Paragraph('Dritte Ebene');
$text->applyStyle($default_text_style);
$third_lvl_list[] = $text;

$text = new Odf_Element_Text_Paragraph('Von der Verwendung der Vierten Ebene wird abgeraten');
$text->applyStyle($default_text_style);
$third_lvl_list[] = $text;

$secont_lvl_list[0]->setChildren($third_lvl_list);
$first_lvl_list[0]->setChildren($secont_lvl_list);

$list_style = new Odf_Style_List('number');
$first_lvl_list->applyStyle($list_style);
$odf_file->addElement($first_lvl_list);
$odf_file->pageBreak();

/**
 * CREATE IMAGE WITH TITLE.
 */

$heading13 = new Odf_Element_Text_Heading('Bilder', 2, TRUE, $toc);
$odf_file->addElement($heading13);

// Create image style.
$image_style = new Odf_Style_Image();
$image_style->setHeight('5.13cm');
$image_style->setWidth('11.18cm');
$image_style->setRelHeight('scale');
$image_style->setRelWidth('100%');

// Create new image.
$image = new Odf_Element_Image_Box('images/bs_1.jpg', 'Abbildung @sequence: Das ist das Logo von Bright Solutions');
$image->applyStyle($image_style);

// Add image to the document.
$paragraph = new Odf_Element_Text_Paragraph($image);
$odf_file->addElement($paragraph);

/**
 * SAVE ODF DOCUMENT.
 */

// Save the ODF document.
$odf_file->save();

// Just a message if everything is OK.
print 'ok';
return;