<?php

/**
 * @file
 * Administrative page callbacks for the wechat_api module.
 */
 /**
  * Returns a listing of all defined wechat api.
  */
 function wechat_api_admin_overview($keys = NULL) {
   $alias_exists = (bool) db_query_range('SELECT 1 FROM {wechat_account}', 0, 1)->fetchField();

   $header = array();
   $header[] = array('data' => t('Wechat ID'));
   $header[] = array('data' => t('Name'));
   $header[] = array('data' => t('APP ID'));
   $header[] = array('data' => t('APP SECRET'));
   $header[] = array('data' => t('APP TOKEN'));
   $header[] = array('data' => t('EncodingAESKey'));
   $header[] = array('data' => t('Operations'));

   $query = db_select('wechat_account')->extend('PagerDefault')->extend('TableSort');

   $result = $query
     ->fields('wechat_account')
     ->orderByHeader($header)
     ->limit(50)
     ->execute();

   $rows = array();
   $destination = drupal_get_destination();
   foreach ($result as $data) {
     $row = array();

     $row['data']['wechat_id'] = $data->wechat_id;
     $row['data']['screen_name'] = $data->screen_name;
     $row['data']['app_id'] = $data->app_id;
     $row['data']['app_secret'] = $data->app_secret;
     $row['data']['app_token'] = $data->app_token;
     $row['data']['encodingaeskey'] = $data->encodingaeskey;

     $operations = array();
     $operations['edit'] = array(
       'title' => t('edit'),
       'href' => "admin/config/wechat/apinew/edit/$data->wechat_id",
       'query' => $destination,
     );
     $operations['delete'] = array(
       'title' => t('delete'),
       'href' => "admin/config/wechat/apinew/delete/$data->wechat_id",
       'query' => $destination,
     );
     $row['data']['operations'] = array(
       'data' => array(
         '#theme' => 'links',
         '#links' => $operations,
         '#attributes' => array('class' => array('links', 'inline', 'nowrap')),
       ),
     );

     $rows[] = $row;
   }

   $build['wechat_api_table'] = array(
     '#theme' => 'table',
     '#header' => $header,
     '#rows' => $rows,
     '#empty' => t('No wechat api available. <a href="@link">Add Wechat Api</a>.', array('@link' => url('admin/config/wechat/apinew/add'))),
   );
   $build['wechat_pager'] = array('#theme' => 'pager');

   return $build;
 }


 /**
  * Page callback: Returns a form creating or editing wechat api.
  *
  * @param $wechat_api
  *
  * @return
  *   A form for adding or editing a wechat account.
  *
  * @see wechat_api_menu()
  */
 function wechat_api_admin_edit($wechat_api = array()) {
   if ($wechat_api) {
     drupal_set_title($wechat_api['screen_name']);
     $output = drupal_get_form('wechat_api_admin_form', $wechat_api);
   }
   else {
     $output = drupal_get_form('wechat_api_admin_form');
   }

   return $output;
 }


 /**
  * Form constructor for the wechat api administration form.
  *
  * @param $wechat_api
  *
  * @ingroup forms
  * @see wechat_api_admin_form_validate()
  * @see wechat_api_admin_form_submit()
  * @see wechat_api_admin_form_delete_submit()
  */
 function wechat_api_admin_form($form, &$form_state, $wechat_api_key = array('app_id' => '', 'app_secret' => '', 'screen_name' => '' , 'api_key' => '', 'app_token' => '','encodingaeskey' => '', 'wechat_id' => NULL)) {
   $form['screen_name'] = array(
     '#type' => 'textfield',
     '#title' => t('Wechat api screen name'),
     '#default_value' => $wechat_api_key['screen_name'],
     '#maxlength' => 255,
     '#size' => 45,
     '#required' => TRUE,
   );

   $form['app_id'] = array(
     '#type' => 'textfield',
     '#title' => t('Wechat api id'),
     '#default_value' => $wechat_api_key['app_id'],
     '#maxlength' => 255,
     '#size' => 45,
     '#required' => TRUE,
   );

   $form['app_secret'] = array(
     '#type' => 'textfield',
     '#title' => t('Wechat api secret'),
     '#default_value' => $wechat_api_key['app_secret'],
     '#maxlength' => 255,
     '#size' => 45,
     '#required' => TRUE,
   );
   $form['app_token'] = array(
     '#type' => 'textfield',
     '#title' => t('Wechat api token'),
     '#default_value' => $wechat_api_key['app_token'],
     '#maxlength' => 255,
     '#size' => 45,
     '#required' => TRUE,
   );
   $form['encodingaeskey'] = array(
     '#type' => 'textfield',
     '#title' => t('Wechat EncodingAESKey'),
     '#default_value' => $wechat_api_key['encodingaeskey'],
     '#maxlength' => 255,
     '#size' => 45,
     '#required' => TRUE,
   );

   $form['api_key'] = array(
     '#type' => 'textfield',
     '#title' => t('Wechat api access key'),
     '#default_value' => $wechat_api_key['api_key'],
     '#maxlength' => 255,
     '#size' => 45,
     '#required' => TRUE,
   );

   $form['actions'] = array('#type' => 'actions');
   $form['actions']['submit'] = array(
     '#type' => 'submit',
     '#value' => t('Save'),
   );
   if ($wechat_api_key['wechat_id']) {
     $form['wechat_id'] = array(
       '#type' => 'hidden',
       '#value' => $wechat_api_key['wechat_id'],
     );
     $form['actions']['delete'] = array(
       '#type' => 'submit',
       '#value' => t('Delete'),
       '#submit' => array('wechat_api_admin_form_delete_submit'),
     );
   }

   return $form;
 }

 /**
 * Form submission handler for wechat_api_admin_form().
 *
 * @see wechat_api_admin_form_validate()
 * @see wechat_api_admin_form_delete_submit()
 */
function wechat_api_admin_form_submit($form, &$form_state) {
  // Remove unnecessary values.
  form_state_values_clean($form_state);

  wechat_api_save($form_state['values']);

  drupal_set_message(t('The wechat api has been saved.'));
  $form_state['redirect'] = 'admin/config/wechat/apinew';
}

/**
 * Form constructor for the wechat api deletion form.
 *
 * @param $wechat_api
 *
 * @see wechat_api_admin_delete_confirm_submit()
 */
function wechat_api_admin_delete_confirm($form, &$form_state, $wechat_api) {
  if (user_access('administer wechat configuration')) {
    $form_state['wechat_api'] = $wechat_api;
    return confirm_form(
      $form,
      t('Are you sure you want to delete wechat api %title?',
      array('%title' => $wechat_api['screen_name'])),
      'admin/config/wechat/apinew'
    );
  }
  return array();
}

/**
 * Form submission handler for wechat_api_admin_delete_confirm().
 */
function wechat_api_admin_delete_confirm_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    wechat_api_delete($form_state['wechat_api']['wechat_id']);
    $form_state['redirect'] = 'admin/config/wechat/apinew';
  }
}
