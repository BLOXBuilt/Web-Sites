<?php
global $qode_pitch_options;
global $qode_pitch_IconCollections;

if(isset($qode_pitch_options['enable_social_sidebar']) && $qode_pitch_options['enable_social_sidebar'] == 'yes') {
	$icons_param_array = array();

	if(isset($qode_pitch_options['social_sidebar_icon_pack']) && $qode_pitch_options['social_sidebar_icon_pack'] !== '' ) {
		$icon_pack = "icon_pack='".$qode_pitch_options['social_sidebar_icon_pack']."'";

		$collection_obj = $qode_pitch_IconCollections->getIconCollection($qode_pitch_options['social_sidebar_icon_pack']);

		if(property_exists($collection_obj, 'param')) {
			$icon_param = $collection_obj->param;
		}
	}

	if(isset($qode_pitch_options['social_sidebar_icon_style']) && $qode_pitch_options['social_sidebar_icon_style'] !== '') {
		$icons_param_array[] = "type='".$qode_pitch_options['social_sidebar_icon_style']."'";
	}
	if(isset($qode_pitch_options['social_sidebar_icon_size']) && $qode_pitch_options['social_sidebar_icon_size'] !== '') {
		$icons_param_array[] = "custom_size='".esc_attr($qode_pitch_options['social_sidebar_icon_size'])."'";
	}
	else{
		$icons_param_array[] = "custom_size='20'";
	}
	if(isset($qode_pitch_options['social_sidebar_icon_shape_size']) && $qode_pitch_options['social_sidebar_icon_shape_size'] !== '') {
		$icons_param_array[] = "shape_size='".esc_attr($qode_pitch_options['social_sidebar_icon_shape_size'])."'";
	}
	if(!empty($qode_pitch_options['social_sidebar_icon_color'])){
		$icons_param_array[] = "icon_color='".esc_attr($qode_pitch_options['social_sidebar_icon_color'])."'";
	}
	if(!empty($qode_pitch_options['social_sidebar_icon_hover_color'])){
		$icons_param_array[] = "hover_icon_color='".esc_attr($qode_pitch_options['social_sidebar_icon_hover_color'])."'";
	}
	if(!empty($qode_pitch_options['social_sidebar_icon_background_color'])){
		$icons_param_array[] = "background_color='".esc_attr($qode_pitch_options['social_sidebar_icon_background_color'])."'";
	}
	if(!empty($qode_pitch_options['social_sidebar_icon_background_hover_color'])){
		$icons_param_array[] = "hover_background_color='".esc_attr($qode_pitch_options['social_sidebar_icon_background_hover_color'])."'";
	}
	if(!empty($qode_pitch_options['social_sidebar_icon_border_color'])){
		$icons_param_array[] = "border_color='".esc_attr($qode_pitch_options['social_sidebar_icon_border_color'])."'";
	}
	if(!empty($qode_pitch_options['social_sidebar_icon_border_hover_color'])){
		$icons_param_array[] = "hover_border_color='".esc_attr($qode_pitch_options['social_sidebar_icon_border_hover_color'])."'";
	}
	if(isset($qode_pitch_options['social_sidebar_icon_border_width']) && $qode_pitch_options['social_sidebar_icon_border_width'] !== '') {
		$icons_param_array[] = "border_width='".esc_attr($qode_pitch_options['social_sidebar_icon_border_width'])."'";
	}
	$icons_param_array[] = "target='_self'";

	?>
	<div id="social_icons_widget">
		<div class="social_icons_widget_inner">
			<?php
			if(isset($qode_pitch_options['social_sidebar_facebook_icon']) && $qode_pitch_options['social_sidebar_facebook_icon'] == 'yes') {
				$icon = $qode_pitch_IconCollections->getFacebookIcon($qode_pitch_options['social_sidebar_icon_pack']);
				$social_link = "#";
				if(isset($qode_pitch_options['social_sidebar_facebook_icon_link']) && $qode_pitch_options['social_sidebar_facebook_icon_link'] !== ''){
					$social_link = esc_url($qode_pitch_options['social_sidebar_facebook_icon_link']);
				}
				?> <div class="q_social_icon_holder"> <?php
					echo do_shortcode('[no_icons '.$icon_pack.' '.$icon_param.'="'.$icon.'" link="'.$social_link.'" '.implode(' ', $icons_param_array).']'); // XSS OK
					?> </div> <?php
			}
			if(isset($qode_pitch_options['social_sidebar_twitter_icon']) && $qode_pitch_options['social_sidebar_twitter_icon'] == 'yes') {
				$icon = $qode_pitch_IconCollections->getTwitterIcon($qode_pitch_options['social_sidebar_icon_pack']);
				$social_link = "#";
				if(isset($qode_pitch_options['social_sidebar_twitter_icon_link']) && $qode_pitch_options['social_sidebar_twitter_icon_link'] !== ''){
					$social_link = esc_url($qode_pitch_options['social_sidebar_twitter_icon_link']);
				}
				?> <div class="q_social_icon_holder"> <?php
					echo do_shortcode('[no_icons '.$icon_pack.' '.$icon_param.'="'.$icon.'" link="'.$social_link.'" '.implode(' ', $icons_param_array).']'); // XSS OK
					?> </div> <?php
			}
			if(isset($qode_pitch_options['social_sidebar_google_plus_icon']) && $qode_pitch_options['social_sidebar_google_plus_icon'] == 'yes') {
				$icon = $qode_pitch_IconCollections->getGooglePlusIcon($qode_pitch_options['social_sidebar_icon_pack']);
				$social_link = "#";
				if(isset($qode_pitch_options['social_sidebar_google_plus_icon_link']) && $qode_pitch_options['social_sidebar_google_plus_icon_link'] !== ''){
					$social_link = esc_url($qode_pitch_options['social_sidebar_google_plus_icon_link']);
				}
				?> <div class="q_social_icon_holder"> <?php
					echo do_shortcode('[no_icons '.$icon_pack.' '.$icon_param.'="'.$icon.'" link="'.$social_link.'" '.implode(' ', $icons_param_array).']'); // XSS OK
					?> </div> <?php
			}
			if(isset($qode_pitch_options['social_sidebar_linkedIn_icon']) && $qode_pitch_options['social_sidebar_linkedIn_icon'] == 'yes') {
				$icon = $qode_pitch_IconCollections->getLinkedInIcon($qode_pitch_options['social_sidebar_icon_pack']);
				$social_link = "#";
				if(isset($qode_pitch_options['social_sidebar_linkedIn_icon_link']) && $qode_pitch_options['social_sidebar_linkedIn_icon_link'] !== ''){
					$social_link = esc_url($qode_pitch_options['social_sidebar_linkedIn_icon_link']);
				}
				?> <div class="q_social_icon_holder"> <?php
					echo do_shortcode('[no_icons '.$icon_pack.' '.$icon_param.'="'.$icon.'" link="'.$social_link.'" '.implode(' ', $icons_param_array).']'); // XSS OK
					?> </div> <?php
			}
			if(isset($qode_pitch_options['social_sidebar_tumblr_icon']) && $qode_pitch_options['social_sidebar_tumblr_icon'] == 'yes') {
				$icon = $qode_pitch_IconCollections->getTumblrIcon($qode_pitch_options['social_sidebar_icon_pack']);
				$social_link = "#";
				if(isset($qode_pitch_options['social_sidebar_tumblr_icon_link']) && $qode_pitch_options['social_sidebar_tumblr_icon_link'] !== ''){
					$social_link = esc_url($qode_pitch_options['social_sidebar_tumblr_icon_link']);
				}
				?> <div class="q_social_icon_holder"> <?php
					echo do_shortcode('[no_icons '.$icon_pack.' '.$icon_param.'="'.$icon.'" link="'.$social_link.'" '.implode(' ', $icons_param_array).']'); // XSS OK
					?> </div> <?php
			}
			if(isset($qode_pitch_options['social_sidebar_pinterest_icon']) && $qode_pitch_options['social_sidebar_pinterest_icon'] == 'yes') {
				$icon = $qode_pitch_IconCollections->getPinterestIcon($qode_pitch_options['social_sidebar_icon_pack']);
				$social_link = "#";
				if(isset($qode_pitch_options['social_sidebar_pinterest_icon_link']) && $qode_pitch_options['social_sidebar_pinterest_icon_link'] !== ''){
					$social_link = esc_url($qode_pitch_options['social_sidebar_pinterest_icon_link']);
				}
				?> <div class="q_social_icon_holder"> <?php
					echo do_shortcode('[no_icons '.$icon_pack.' '.$icon_param.'="'.$icon.'" link="'.$social_link.'" '.implode(' ', $icons_param_array).']'); // XSS OK
					?> </div> <?php
			}
			if (isset($qode_pitch_options['social_sidebar_vk_icon']) && $qode_pitch_options['social_sidebar_vk_icon'] == 'yes') {
				$social_link = "#";
				if (isset($qode_pitch_options['social_sidebar_vk_icon_link']) && $qode_pitch_options['social_sidebar_vk_icon_link'] !== '') {
					$social_link = esc_url($qode_pitch_options['social_sidebar_vk_icon_link']);
				}
				?>
				<div class="q_social_icon_holder"> <?php
					echo do_shortcode('[no_icons icon_pack="font_awesome" fa_icon="fa-vk" link="' . $social_link . '" ' . implode(' ', $icons_param_array) . ']'); // XSS OK
					?> </div> <?php
			}
			?>
		</div>
	</div>
<?php } ?>