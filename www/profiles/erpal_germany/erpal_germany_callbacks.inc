<?php
/**
 * @file
 * Contains Batch API callbacks used during installation.
 */
 
 
/**
 * BatchAPI callback
 * reverts all features
 */ 
function _erpal_germany_revert_features(&$context){
  $context['message'] = st('Reverted all features');
  features_revert();
}
 
/**
 * BatchAPI callback
 * rebuilds content access 
 */
function _erpal_germany_rebuild_content_access(&$context){
  $context['message'] = st('Rebuilded content access permissions');
  node_access_rebuild();
}