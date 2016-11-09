<?php

add_action('after_setup_theme', 'qode_pitch_admin_map_init', 0);
function qode_pitch_admin_map_init() {
	global $qode_pitch_options;
	global $qode_pitch_Framework;
	global $qode_pitch_options_fontstyle;
	global $qode_pitch_options_fontweight;
	global $qode_pitch_options_texttransform;
	global $qode_pitch_options_fontdecoration;
	global $qode_pitch_options_arrows_type;
	global $qode_pitch_options_blockquote_type;
	global $qode_pitch_options_double_arrows_type;
	global $qode_pitch_options_arrows_up_type;
	require_once(get_template_directory().'/framework/admin/options/10.general/map.inc');
	require_once(get_template_directory().'/framework/admin/options/20.logo/map.inc');
	require_once(get_template_directory().'/framework/admin/options/30.header/map.inc');
	require_once(get_template_directory().'/framework/admin/options/40.footer/map.inc');
	require_once(get_template_directory().'/framework/admin/options/50.title/map.inc');
	require_once(get_template_directory().'/framework/admin/options/60.fonts/map.inc');
	require_once(get_template_directory().'/framework/admin/options/70.elements/map.inc');
	require_once(get_template_directory().'/framework/admin/options/75.sidebar/map.inc');
	require_once(get_template_directory().'/framework/admin/options/80.blog/map.inc');
	require_once(get_template_directory().'/framework/admin/options/90.portfolio/map.inc');
	require_once(get_template_directory().'/framework/admin/options/95.slider/map.inc');
	require_once(get_template_directory().'/framework/admin/options/96.verticalsplitslider/map.inc');
	require_once(get_template_directory().'/framework/admin/options/100.social/map.inc');
	require_once(get_template_directory().'/framework/admin/options/110.error404/map.inc');
	require_once(get_template_directory().'/framework/admin/options/130.parallax/map.inc');
	require_once(get_template_directory().'/framework/admin/options/140.contentbottom/map.inc');
	
	if(qode_pitch_visual_composer_installed() && version_compare(qode_pitch_get_vc_version(), '4.4.2') >= 0) {
		require_once(get_template_directory().'/framework/admin/options/144.visualcomposer/map.inc');
	} else {
		$qode_pitch_Framework->qodeOptions->addOption("enable_grid_elements","no");
	}
    if(qode_pitch_contact_form_7_installed()) {
		require_once(get_template_directory().'/framework/admin/options/145.contactform7/map.inc');
    }
	
	require_once(get_template_directory().'/framework/admin/options/146.maintenance/map.inc');
	require_once(get_template_directory().'/framework/admin/options/147.login/map.inc');
	
	if(function_exists("is_woocommerce")){
		require_once(get_template_directory().'/framework/admin/options/150.woocommerce/map.inc');
	}
	require_once(get_template_directory().'/framework/admin/options/160.reset/map.inc');
}