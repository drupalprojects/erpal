<h1><?php print $node->title; ?></h1>
<div class="print body"><?php print isset($node->body[LANGUAGE_NONE][0]) ? $node->body[LANGUAGE_NONE][0] : false; ?></div>