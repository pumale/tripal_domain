<?php

/**
 * Implements hook_node_view().
 *
 * @ingroup tripal_domain
 */
function tripal_domain_node_view($node, $view_mode, $langcode) {
  switch ($node->type) {
    case 'chado_domain':
      // Show feature browser and counts
      if ($view_mode == 'full') {          
        $node->content['tripal_domain_description'] = array(
          '#markup' => theme('tripal_domain_description', array('node' => $node)),
          '#tripal_toc_id'    => 'description',
          '#tripal_toc_title' => 'description',
          '#weight' => -100,
        );
        
      }
      break;
  }
}
