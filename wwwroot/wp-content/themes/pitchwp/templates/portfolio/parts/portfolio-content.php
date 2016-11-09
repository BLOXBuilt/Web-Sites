<?php

global $qode_pitch_options;

$portfolio_title_tag            = 'h3';
$portfolio_title_style          = '';

//set title tag
if (isset($qode_pitch_options['portfolio_title_tag']) && !empty($qode_pitch_options['portfolio_title_tag'])) {
$portfolio_title_tag = $qode_pitch_options['portfolio_title_tag'];
}

//set style for title
if ((isset($qode_pitch_options['portfolio_title_margin_bottom']) && $qode_pitch_options['portfolio_title_margin_bottom'] != '')
	|| (isset($qode_pitch_options['portfolio_title_color']) && !empty($qode_pitch_options['portfolio_title_color']))){

	if (isset($qode_pitch_options['portfolio_title_margin_bottom']) && $qode_pitch_options['portfolio_title_margin_bottom'] != '') {
		$portfolio_title_style .= 'margin-bottom:'.esc_attr($qode_pitch_options['portfolio_title_margin_bottom']).'px;';
	}

	if (isset($qode_pitch_options['portfolio_title_color']) && !empty($qode_pitch_options['portfolio_title_color'])) {
		$portfolio_title_style .= 'color:'.esc_attr($qode_pitch_options['portfolio_title_color']).';';
	}

}

//check if title is hidden in info section
$portfolio_hide_title = false;
if(get_post_meta($id, "qode_portfolio_hide_title_in_info", true) == "yes") {
	$portfolio_hide_title = true;
}

if(!$portfolio_hide_title) { ?>
	<<?php echo esc_attr($portfolio_title_tag); ?> class="portfolio_single_text_title" <?php qode_pitch_inline_style($portfolio_title_style); ?>><span><?php the_title(); ?></span></<?php echo esc_attr($portfolio_title_tag); ?>>
<?php } ?>

<div class="info portfolio_single_content">
	<?php the_content(); ?>
</div> <!-- close div.portfolio_content -->