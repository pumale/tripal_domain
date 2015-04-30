<?php

/**
 * Implements hook_node_view().
 *
 * @ingroup tripal_domain
 */

function tripal_domain_node_info() {
  $nodes = array();
$nodes['chado_domain'] = array(
    'name'        => t('Domain'),
    'base'        => 'chado_domain',
    'description' => t('A record from the chado domain table'),
    'has_title'   => TRUE,
    'locked'      => TRUE,
     'chado_node_api' => array(
      'base_table' => 'domain',       // the base table name (e.g. example, example, contact)
      'hook_prefix' => 'chado_domain',// the node type hook prefix
      'record_type_title' => array(
        'singular' => t('Domain'),    // how to refer to the record
        'plural' => t('Domains')      // how to refer to the record in plurals
      ),
      'sync_filters' => array(
        'feature_feature_id' => TRUE,             // if the record has a feature_id set to TRUE
        'feature_name' => TRUE          // if the record has a name set to TRUE
      ),
    )
  );
return $nodes;
}



function tripal_domain_node_view($node, $view_mode, $langcode) {
  switch ($node->type) {
    case 'chado_domain':
      // Show feature browser and counts
      if ($view_mode == 'full') {          
        $node->content['tripal_domain_base'] = array(
          '#markup' => theme('tripal_domain_base', array('node' => $node)),
          '#tripal_toc_id'    => 'base',
          '#tripal_toc_title' => 'Overview',
          '#weight' => -100,
        );
        
      }
      break;
  }
}
