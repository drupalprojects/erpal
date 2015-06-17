<?php

/**
 * Renders the content using the original Quicktabs mechanism of previous versions.
 * But we dont change tabs with javascript only with complete page reload
 */
class ErpalNoJsTabs extends QuickQuicktabs {
  
  public function render() {
    //we will always only render the current active tab in this render handler    
    $quickset = $this->quickset;

    $render_array = array();

    $active_tab = $quickset->getActiveTab();
    
    //check if there is a tab referenced in URL
    $tab_by_url = false;
    foreach ($_GET as $name => $value) {
      $pos = strpos($name, 'qt-');
      if ($pos === 0) {
        //this is a qucick tab current-tab parameter
        $tab_by_url = true;
        break;
      }
    }
    
    //if there is an active tab set in the last 
    $path = current_path();
    $session_tab = isset($_SESSION['ErpalNoJsTabs'][$quickset->getName()][$path]) ? $_SESSION['ErpalNoJsTabs'][$quickset->getName()][$path] : false;

    if (!$active_tab && !$tab_by_url) {
      $active_tab = $session_tab;
    } else {
      $_SESSION['ErpalNoJsTabs'][$quickset->getName()][$path] = $active_tab;
    }
    
    if ($tabs = $this->build_tablinks($active_tab)) {
      $render_array['#attached'] = $this->add_attached();

      $qt_name = $quickset->getName();
      $settings = $quickset->getSettings();
      $contents = $quickset->getContents();

      $render_array['content'] = array(
        '#theme' => 'qt_quicktabs',
        '#options' => array('attributes' => array(
          'id' => 'quicktabs-' . $qt_name,
          'class' => 'quicktabs-wrapper quicktabs-style-' . drupal_strtolower($settings['style']),
        )),
        'tabs' => array('#theme' => 'qt_quicktabs_tabset', '#options' => array('active' => $active_tab, 'style' => drupal_strtolower($settings['style'])), 'tablinks' => $tabs),
        // The main content area, each quicktab container needs a unique id.
        'container' => array(
          '#prefix' => '<div id="quicktabs-container-' . $qt_name .'" class="quicktabs_main quicktabs-style-' . drupal_strtolower($settings['style']) .'">',
          '#suffix' => '</div>',
          'divs' => array(),
        ),
      );

      // we render only the current active tab, not the others!
      $tabs_to_render = array($active_tab => $contents[$active_tab]);

      foreach ($tabs_to_render as $key => $tab) {
        if (!empty($tab)) {
          $attribs = array(
            'id' => 'quicktabs-tabpage-'. $qt_name . '-'. $key,
            'class' => array('quicktabs-tabpage', ($active_tab == $key ? '' : 'quicktabs-hide')),
          );
          $render_array['content']['container']['divs'][] = array(
            '#prefix' => '<div '. drupal_attributes($attribs) .'>',
            '#suffix' => '</div>',
            'content' => $tab->render(),
          );          
        }
      }
    }
    return $render_array;
  }

  /**
   * Build the actual tab links, with appropriate href, title and attributes.
   * 
   * @param $active_tab The index of the active tab.
   */
  protected function build_tablinks($active_tab) {
    $quickset = $this->quickset;
    $settings = $quickset->getSettings();
    $tabs = array();
    foreach ($quickset->getContents() as $i => $tab) {
      if (!empty($tab)) {
        $tablink = array(
          '#type' => 'link',
          '#title' => $quickset->translateString($tab->getTitle(), 'tab', $i),
          '#href' =>  $_GET['q'],
          '#options' => $this->construct_link_options($i),
        );
        
        $tabs[$i] = $tablink;
      }
    }
    return $tabs;
  }

  /**
   * Add any necessary js, css and libraries for the render array.
   */
  protected function add_attached() {
    $attached = parent::add_attached();
    
    //to always have page reload on tab click in order not to load big views if not needed, unset js
    unset($attached['js']);
    return $attached;
  }
  
  /**
   * Helper function to construct link options for tab links.
   */
  protected function construct_link_options($tabkey) {
    $qt_name = $this->quickset->getName();
    $id = 'quicktabs-tab-' . implode('-', array($qt_name, $tabkey));
  
    // Need to construct the correct querystring for the tab links.
    $query = drupal_get_query_parameters(NULL, array("qt-$qt_name", 'q', 'page'));
    $query["qt-{$qt_name}"] = $tabkey;

    //if there is an operation set, unset it
    unset($query['op']);
    
    $link_options = array(
      'attributes' => array(
        'id' => $id,
      ),
      'query' => $query,
      //'fragment' => 'qt-' . $qt_name,
    );
    return $link_options;
  }
}