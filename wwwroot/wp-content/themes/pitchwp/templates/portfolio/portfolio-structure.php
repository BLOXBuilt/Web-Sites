<?php
//get global variables
global $wp_query;
global $qode_pitch_options;

//init variables
$id 						= $wp_query->get_queried_object_id();
$content_style = "";

//is page background color set for current page?
if(get_post_meta($id, "qode_page_background_color", true) != ""){
	$background_color = 'background-color: '.esc_attr(get_post_meta($id, "qode_page_background_color", true));
}else{
	$background_color = "";
}

//get current portfolio template
$portfolio_template = 'floating-right';
if(get_post_meta($id, "qode_choose-portfolio-single-view", true) != "") {
	$portfolio_template = get_post_meta($id, "qode_choose-portfolio-single-view", true);
} elseif($qode_pitch_options['portfolio_style'] !== '') {
	$portfolio_template = $qode_pitch_options['portfolio_style'];
}

//get current portfolio template
$portfolio_image_animation = '';
if(get_post_meta($id, "qode_portfolio-enable_animation", true) == "yes") {
	$portfolio_image_animation = ' animate';
} 

if((get_post_meta($id, "qode_portfolio-enable_animation", true) == "") && (isset($qode_pitch_options['portfolio_enable_animation'])) && ($qode_pitch_options['portfolio_enable_animation']=="yes")) {
	$portfolio_image_animation = ' animate';
} 

if(get_post_meta($id, "qode_content-top-padding", true) != ""){
	if(get_post_meta($id, "qode_content-top-padding-mobile", true) == 'yes'){
		$content_style = "padding-top:".esc_attr(get_post_meta($id, "qode_content-top-padding", true))."px !important";
	}else{
		$content_style = "padding-top:".esc_attr(get_post_meta($id, "qode_content-top-padding", true))."px";
	}
}

?>

<div class="full_width" <?php qode_pitch_inline_style($background_color); ?>>
	<div class="full_width_inner" <?php qode_pitch_inline_style($content_style); ?>>
		<div class="portfolio_single <?php echo esc_attr($portfolio_image_animation); ?> <?php echo esc_attr($portfolio_template); ?>">
			<?php
				if (post_password_required()) {
					echo get_the_password_form();
				} else {
					//load proper portfolio file based on portfolio template
					get_template_part('templates/portfolio/portfolio', $portfolio_template);

					get_template_part('templates/portfolio/parts/portfolio-related-projects');

					get_template_part('templates/portfolio/parts/portfolio-navigation');

					get_template_part('templates/portfolio/parts/portfolio-comments');
				}
			?>
		</div> <!-- close div.portfolio single -->
	</div> <!-- close div.container inner -->
</div> <!-- close div.container -->