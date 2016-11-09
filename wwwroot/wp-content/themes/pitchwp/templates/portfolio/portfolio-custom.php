<?php
//get global variables
global $qode_pitch_options;
$container_styles = '';
//is page background color set for current page?
if(get_post_meta($id, "qode_page_background_color", true) != ""){
	$container_styles .= 'background-color: '. esc_attr(get_post_meta($id, "qode_page_background_color", true)).';';
}

?>

<div class="container" <?php qode_pitch_inline_style($container_styles); ?>>
	<div class="container_inner default_template_holder clearfix">
		<?php the_content(); ?>
	</div>
</div>