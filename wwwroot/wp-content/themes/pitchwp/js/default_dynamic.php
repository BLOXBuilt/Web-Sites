<?php

$absolute_path = explode('wp-content', $_SERVER['SCRIPT_FILENAME']);

if(count($absolute_path) == 1) {
    $absolute_path = explode('wp-admin', $_SERVER['SCRIPT_FILENAME']);
}

$wp_load = $absolute_path[0] . 'wp-load.php';
require_once($wp_load);

header('Content-type: application/x-javascript');
?>

var header_height = 90;
var min_header_height_scroll = 57;
var header_one_scroll_resize = false;
var min_header_height_sticky = 60;
var scroll_amount_for_sticky = 85;
var min_header_height_fixed_hidden = 45;
var header_bottom_border_weight = 1;
var scroll_amount_for_fixed_hiding = 200;
var menu_item_margin = 0;
var large_menu_item_border = 0;
var element_appear_amount = -150;
var paspartu_width_init = 0.02;
var directionNavArrows = 'arrow_carrot-';
var directionNavArrowsTestimonials = 'fa fa-angle-';
var enable_navigation_on_full_screen_section = false;
<?php
if(is_admin_bar_showing()){
?>
var add_for_admin_bar = 32;
<?php
}else{
?>
var add_for_admin_bar = 0;
<?php
}
?>
<?php if(isset($qode_pitch_options['header_height'])){
	if ($qode_pitch_options['header_height'] !== '') { ?>
	header_height = <?php echo esc_attr($qode_pitch_options['header_height']); ?>;
<?php } } ?>
<?php if(isset($qode_pitch_options['header_height_scroll'])){
	if ($qode_pitch_options['header_height_scroll'] !== "") { ?>
	min_header_height_scroll = <?php echo esc_attr($qode_pitch_options['header_height_scroll']); ?>;
<?php } } ?>
<?php if(isset($qode_pitch_options['header_one_scroll_resize'])){
	if ($qode_pitch_options['header_one_scroll_resize'] === "yes") { ?>
	header_one_scroll_resize = true;
<?php } } ?>
<?php if(isset($qode_pitch_options['header_height_sticky'])){
	if ($qode_pitch_options['header_height_sticky'] !== "") { ?>
	min_header_height_sticky = <?php echo esc_attr($qode_pitch_options['header_height_sticky']); ?>;
<?php } } ?>
<?php if(isset($qode_pitch_options['scroll_amount_for_sticky'])){
	if (!empty($qode_pitch_options['scroll_amount_for_sticky'])) { ?>
	scroll_amount_for_sticky = <?php echo esc_attr($qode_pitch_options['scroll_amount_for_sticky']); ?>;
<?php } } ?>
<?php if(isset($qode_pitch_options['header_height_scroll_hidden'])){
    if (!empty($qode_pitch_options['header_height_scroll_hidden'])) { ?>
    min_header_height_fixed_hidden = <?php echo esc_attr($qode_pitch_options['header_height_scroll_hidden']); ?>;
<?php } } ?>

<?php if(isset($qode_pitch_options['scroll_amount_for_fixed_hiding'])){
    if (!empty($qode_pitch_options['scroll_amount_for_fixed_hiding'])) { ?>
        scroll_amount_for_fixed_hiding = <?php echo esc_attr($qode_pitch_options['scroll_amount_for_fixed_hiding']); ?>;
<?php } } ?>

<?php
if(isset($qode_pitch_options['enable_manu_item_border']) && $qode_pitch_options['enable_manu_item_border']=='yes' && isset($qode_pitch_options['menu_item_style']) && $qode_pitch_options['menu_item_style']=='large_item'){
    if(isset($qode_pitch_options['menu_item_border_style']) && $qode_pitch_options['menu_item_border_style']=='all_borders'){ ?>
		large_menu_item_border = <?php echo esc_attr($qode_pitch_options['menu_item_border_width'])*2;
	} ?>
	<?php if(isset($qode_pitch_options['menu_item_border_style']) && $qode_pitch_options['menu_item_border_style']=='top_bottom_borders'){ ?>
		large_menu_item_border = <?php echo esc_attr($qode_pitch_options['menu_item_border_width'])*2;
	} ?>
	<?php if(isset($qode_pitch_options['menu_item_border_style']) && ($qode_pitch_options['menu_item_border_style']=='bottom_border' || $qode_pitch_options['menu_item_border_style']=='top_border')){ ?>
		large_menu_item_border = <?php  echo esc_attr($qode_pitch_options['menu_item_border_width']);
	} ?>
<?php } ?>

<?php if(isset($qode_pitch_options['element_appear_amount']) && $qode_pitch_options['element_appear_amount'] !== ""){ ?>
    element_appear_amount = -<?php echo esc_attr($qode_pitch_options['element_appear_amount']); ?>;
<?php } ?>

<?php if(isset($qode_pitch_options['paspartu_width']) && $qode_pitch_options['paspartu_width'] !== ""){ ?>
    paspartu_width_init = <?php echo esc_attr($qode_pitch_options['paspartu_width'])/100; ?>;
<?php } ?>

var logo_height = 130; // pitch logo height
var logo_width = 280; // pitch logo width
	<?php 
		$logo_width = $qode_pitch_options['logo_width'];
		$logo_height = $qode_pitch_options['logo_height'];
	?>
    logo_width = <?php echo esc_attr($logo_width); ?>;
    logo_height = <?php echo esc_attr($logo_height); ?>;

<?php if(isset($qode_pitch_options['menu_margin_left_right'])){
	if ($qode_pitch_options['menu_margin_left_right'] !== '') { ?>
		menu_item_margin = <?php echo esc_attr($qode_pitch_options['menu_margin_left_right']); ?>;
<?php } } ?>
	
<?php if(isset($qode_pitch_options['header_top_area'])){
if ($qode_pitch_options['header_top_area'] == "yes") { ?>
<?php if(isset($qode_pitch_options['header_top_height']) && $qode_pitch_options['header_top_height'] !== ""){?>
header_top_height= <?php echo esc_attr($qode_pitch_options['header_top_height']);?>;
<?php } else { ?>
header_top_height = 36;
<?php } ?>
<?php } else { ?>
	header_top_height = 0;
<?php } }?>
var loading_text;
loading_text = '<?php esc_html_e('Loading new posts...', 'pitchwp'); ?>';
var finished_text;
finished_text = '<?php esc_html_e('No more posts', 'pitchwp'); ?>';

var piechartcolor;
piechartcolor	= "#279eff";

<?php if(isset($qode_pitch_options['first_color']) && !empty($qode_pitch_options['first_color'])){ ?>
	piechartcolor = "<?php echo esc_attr($qode_pitch_options['first_color']); ?>";
<?php } ?>

<?php if(isset($qode_pitch_options['single_slider_navigation_arrows_type']) && $qode_pitch_options['single_slider_navigation_arrows_type'] != '') { ?>
	directionNavArrows = '<?php echo esc_attr($qode_pitch_options['single_slider_navigation_arrows_type']); ?>';
<?php } ?>

<?php if(isset($qode_pitch_options['testimonials_arrows_type']) && $qode_pitch_options['testimonials_arrows_type'] != '') { ?>
	directionNavArrowsTestimonials = '<?php echo esc_attr($qode_pitch_options['testimonials_arrows_type']); ?>';
<?php } ?>

<?php if(isset($qode_pitch_options['fs_navigation_slider_vertical_section_type']) && ($qode_pitch_options['fs_navigation_slider_vertical_section_type'] == 'bullets') || ($qode_pitch_options['fs_navigation_slider_vertical_section_type'] == 'both')) { ?>
    enable_navigation_on_full_screen_section = true;
<?php } ?>


var no_ajax_pages = [];
var qode_root = '<?php echo esc_url( home_url( '/' )); ?>';
var theme_root = '<?php echo QODE_ROOT; ?>/';
<?php if($qode_pitch_options['header_style'] != ''){ ?>
var header_style_admin = "<?php echo esc_attr($qode_pitch_options['header_style']); ?>";
<?php }else{ ?>
var header_style_admin = "";
<?php } ?>
if(typeof no_ajax_obj !== 'undefined') {
no_ajax_pages = no_ajax_obj.no_ajax_pages;
}

var login_page = <?php echo qode_pitch_replace_menu_name(); ?>;
var logoutString = "<?php esc_html_e("Logout", "pitchwp"); ?>";
