<?php
global $qode_pitch_options;

//get portfolio date value
$portfolio_hide_date = "";
if(isset($qode_pitch_options['portfolio_hide_date'])){
	$portfolio_hide_date = $qode_pitch_options['portfolio_hide_date'];
}

if($portfolio_hide_date != "yes"){

    $portfolio_info_tag             = 'h6';
    $portfolio_info_style           = '';

    //set info tag
    if (isset($qode_pitch_options['portfolio_info_tag'])) {
    	$portfolio_info_tag = $qode_pitch_options['portfolio_info_tag'];
    }

    //set style for info
    if ((isset($qode_pitch_options['portfolio_info_margin_bottom']) && $qode_pitch_options['portfolio_info_margin_bottom'] != '')
    || (isset($qode_pitch_options['portfolio_info_color']) && !empty($qode_pitch_options['portfolio_info_color']))) {

		if (isset($qode_pitch_options['portfolio_info_margin_bottom']) && $qode_pitch_options['portfolio_info_margin_bottom'] != '') {
			$portfolio_info_style .= 'margin-bottom:' . esc_attr($qode_pitch_options['portfolio_info_margin_bottom']) . 'px;';
		}

		if (isset($qode_pitch_options['portfolio_info_color']) && !empty($qode_pitch_options['portfolio_info_color'])) {
			$portfolio_info_style .= 'color:'.esc_attr($qode_pitch_options['portfolio_info_color']).';';
		}

    }

   ?>


	<div class="info portfolio_single_custom_date">
		<<?php echo esc_attr($portfolio_info_tag); ?> class="info_section_title" <?php qode_pitch_inline_style($portfolio_info_style); ?>><?php esc_html_e('Date:','pitchwp'); ?></<?php echo esc_attr($portfolio_info_tag); ?>>
        <p><?php the_time(get_option('date_format')); ?></p>
	</div>
<?php } ?>