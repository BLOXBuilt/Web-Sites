<?php

add_action('after_setup_theme', 'qode_pitch_meta_boxes_map_init', 1);
function qode_pitch_meta_boxes_map_init() {
	global $qode_pitch_options;
	global $qode_pitch_Framework;
	global $qode_pitch_options_fontstyle;
	global $qode_pitch_options_fontweight;
	global $qode_pitch_options_texttransform;
	global $qode_pitch_options_fontdecoration;
	global $qode_pitch_options_arrows_type;
	global $qode_pitch_options_blockquote_type;
	require_once(get_template_directory().'/framework/admin/meta-boxes/page/map.inc');
	require_once(get_template_directory().'/framework/admin/meta-boxes/portfolio/map.inc');
	require_once(get_template_directory().'/framework/admin/meta-boxes/slides/map.inc');
	require_once(get_template_directory().'/framework/admin/meta-boxes/post/map.inc');
	require_once(get_template_directory().'/framework/admin/meta-boxes/testimonials/map.inc');
	require_once(get_template_directory().'/framework/admin/meta-boxes/carousels/map.inc');
	require_once(get_template_directory().'/framework/admin/meta-boxes/masonry_gallery/map.inc');
	
}