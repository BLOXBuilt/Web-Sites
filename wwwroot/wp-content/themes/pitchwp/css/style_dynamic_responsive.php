<?php
$absolute_path = explode('wp-content', $_SERVER['SCRIPT_FILENAME']);

if(count($absolute_path) == 1) {
    $absolute_path = explode('wp-admin', $_SERVER['SCRIPT_FILENAME']);
}

$wp_load = $absolute_path[0] . 'wp-load.php';
require_once($wp_load);

header("Content-type: text/css; charset=utf-8");
?>

@media only screen and (max-width: 1000px){
	
	<?php if (!empty($qode_pitch_options['header_background_color'])) { ?>
	.header_bottom {
		background-color: <?php echo esc_attr($qode_pitch_options['header_background_color']);  ?>;
	}
	<?php } ?>
	<?php if (!empty($qode_pitch_options['mobile_background_color'])) { ?>
		.header_bottom,
		nav.mobile_menu{
				background-color: <?php echo esc_attr($qode_pitch_options['mobile_background_color']);  ?> !important;
		}
	<?php } ?>
	
	 <?php if (isset($qode_pitch_options['page_subtitle_fontsize']) && ($qode_pitch_options['page_subtitle_fontsize']) < 28 && ($qode_pitch_options['page_subtitle_fontsize']) !== '') { ?>
		.subtitle{
			font-size: <?php echo esc_attr($qode_pitch_options['page_subtitle_fontsize']) *0.8;  ?>px;
		}
	 <?php }?>
		
	<?php if(isset($qode_pitch_options['h1_fontsize']) && ($qode_pitch_options['h1_fontsize'])>80) { ?>
		.title h1,
		.title h1.title_like_separator .vc_text_separator.full .separator_content{
			font-size:<?php echo esc_attr($qode_pitch_options['h1_fontsize'])*0.8; ?>px;
		}
	<?php } ?>
	<?php if(isset($qode_pitch_options['page_title_fontsize']) && ($qode_pitch_options['page_title_fontsize'])>80) { ?>
		.title h1,
		.title h1.title_like_separator .vc_text_separator.full .separator_content{
			font-size:<?php echo esc_attr($qode_pitch_options['page_title_fontsize'])*0.8; ?>px;
		}
	<?php } ?>
	<?php if(isset($qode_pitch_options['h2_fontsize']) && ($qode_pitch_options['h2_fontsize'])>70) { ?>
		.content h2{
			font-size:<?php echo esc_attr($qode_pitch_options['h2_fontsize'])*0.8; ?>px;
		}
	<?php } ?>
	<?php if(isset($qode_pitch_options['h2_lineheight']) && ($qode_pitch_options['h2_lineheight'])>70) { ?>
		.content h2{
			line-height: 1.3em;
		}
	<?php } ?>
	<?php if(isset($qode_pitch_options['h3_fontsize']) && ($qode_pitch_options['h3_fontsize'])>70) { ?>
		.content h3{
			font-size:<?php echo esc_attr($qode_pitch_options['h3_fontsize'])*0.8; ?>px;
		}
	<?php } ?>
	<?php if(isset($qode_pitch_options['h4_fontsize']) && ($qode_pitch_options['h4_fontsize'])>70) { ?>
		.content h4:not(.blockquote_text){
			font-size:<?php echo esc_attr($qode_pitch_options['h4_fontsize'])*0.8; ?>px;
		}
	<?php } ?>
	<?php if(isset($qode_pitch_options['h5_fontsize']) && ($qode_pitch_options['h5_fontsize'])>70) { ?>
		.content h5{
			font-size:<?php echo esc_attr($qode_pitch_options['h5_fontsize'])*0.8; ?>px;
		}
	<?php } ?>
	<?php if(isset($qode_pitch_options['h6_fontsize']) && ($qode_pitch_options['h6_fontsize'])>70) { ?>
		.content h6{
			font-size:<?php echo esc_attr($qode_pitch_options['h6_fontsize'])*0.8; ?>px;
		}
	<?php } ?>

	<?php if(isset($qode_pitch_options['portfolio_list_filter_height']) && $qode_pitch_options['portfolio_list_filter_height'] !== '') { ?>
		.filter_outer.filter_portfolio{
			line-height: 2em;
		}
	<?php } ?>
}

@media only screen and (min-width: 480px) and (max-width: 768px){

<?php if(isset($qode_pitch_options['overlapping_content']) && $qode_pitch_options['overlapping_content'] == 'yes' && isset($qode_pitch_options['overlapping_top_content_amount']) && $qode_pitch_options['overlapping_top_content_amount'] > 30){ ?>
    .overlapping_content .content .content_inner > .container .overlapping_content,
    .overlapping_content .content .content_inner > .full_width .full_width_inner{
    margin-top: -30px;
    }

    .overlapping_content .title .title_holder .container{
    padding-bottom: 30px;
    }

    .animate_overlapping_content .overlapping_content,
    .animate_overlapping_content .full_width {
    -webkit-transform: translateY(30px);
    transform: translateY(30px);
    }
<?php }	?>
}

@media only screen and (min-width: 600px) and (max-width: 768px){
	<?php if(isset($qode_pitch_options['h1_fontsize']) && $qode_pitch_options['h1_fontsize'] != '') {
		$title_font_size = $qode_pitch_options['h1_fontsize'];
		if (($qode_pitch_options['h1_fontsize'])>80) {
			$title_font_size *= 0.5;
		}
		elseif (($qode_pitch_options['h1_fontsize'])>65) {
		 	$title_font_size *= 0.6;
		}
		elseif (($qode_pitch_options['h1_fontsize'])>50) {
		 	$title_font_size *= 0.7;
		}
		elseif (($qode_pitch_options['h1_fontsize'])>35) {
		 	$title_font_size *= 0.8;
		} ?>
		.title h1,
		.title h1.title_like_separator .vc_text_separator.full .separator_content,
		.title.title_size_large h1,
		.title.title_size_large h1.title_like_separator .vc_text_separator.full .separator_content{
			font-size:<?php echo esc_attr($title_font_size); ?>px;
		}
	<?php } ?>
	<?php if(isset($qode_pitch_options['h1_lineheight']) && ($qode_pitch_options['h1_lineheight'])>35) { ?>
		.title h1,
		.title h1.title_like_separator .vc_text_separator.full .separator_content,
		.title.title_size_large h1,
		.title.title_size_large h1.title_like_separator .vc_text_separator.full .separator_content{
			line-height: 1.3em;
		}
	<?php } ?>
	<?php if(isset($qode_pitch_options['page_title_fontsize']) && ($qode_pitch_options['page_title_fontsize']) !== "") {
		$page_title_font_size = $qode_pitch_options['page_title_fontsize'];
		if (($qode_pitch_options['page_title_fontsize'])>80) {
			$page_title_font_size *= 0.5;
		}
		elseif (($qode_pitch_options['page_title_fontsize'])>65) {
		 	$page_title_font_size *= 0.6;
		}
		elseif (($qode_pitch_options['page_title_fontsize'])>50) {
		 	$page_title_font_size *= 0.7;
		}
		elseif (($qode_pitch_options['page_title_fontsize'])>35) {
		 	$page_title_font_size *= 0.8;
		} ?>
		.title h1,
		.title h1.title_like_separator .vc_text_separator.full .separator_content,
		.title.title_size_large h1,
		.title.title_size_large h1.title_like_separator .vc_text_separator.full .separator_content{
			font-size:<?php echo esc_attr($page_title_font_size); ?>px;
		}
	<?php } ?>
	<?php if(isset($qode_pitch_options['page_title_lineheight']) && ($qode_pitch_options['page_title_lineheight'])>35) { ?>
		.title h1,
		.title h1.title_like_separator .vc_text_separator.full .separator_content,
		.title.title_size_large h1,
		.title.title_size_large h1.title_like_separator .vc_text_separator.full .separator_content{
		line-height: 1.3em;
		}
	<?php } ?>
	<?php if(isset($qode_pitch_options['h2_fontsize']) && ($qode_pitch_options['h2_fontsize'])>35) { ?>
		.content h2{
			font-size:<?php echo esc_attr($qode_pitch_options['h2_fontsize'])*0.7; ?>px;
		}
	<?php } ?>
	<?php if(isset($qode_pitch_options['h2_lineheight']) && ($qode_pitch_options['h2_lineheight'])>45) { ?>
		.content h2{
			line-height: 1.3em;
		}
	<?php } ?>
	<?php if(isset($qode_pitch_options['h3_fontsize']) && ($qode_pitch_options['h3_fontsize'])>35) { ?>
		.content h3{
			font-size:<?php echo esc_attr($qode_pitch_options['h3_fontsize'])*0.7; ?>px;
		}
	<?php } ?>
	<?php if(isset($qode_pitch_options['h4_fontsize']) && ($qode_pitch_options['h4_fontsize'])>35) { ?>
		.content h4{
			font-size:<?php echo esc_attr($qode_pitch_options['h4_fontsize'])*0.7; ?>px;
		}
	<?php } ?>
	<?php if(isset($qode_pitch_options['h5_fontsize']) && ($qode_pitch_options['h5_fontsize'])>35) { ?>
		.content h5{
			font-size:<?php echo esc_attr($qode_pitch_options['h5_fontsize'])*0.7; ?>px;
		}
	<?php } ?>
	<?php if(isset($qode_pitch_options['h6_fontsize']) && ($qode_pitch_options['h6_fontsize'])>35) { ?>
		.content h6{
			font-size:<?php echo esc_attr($qode_pitch_options['h6_fontsize'])*0.7; ?>px;
		}
	<?php } ?>
	
	<?php if (isset($qode_pitch_options['page_subtitle_fontsize']) && ($qode_pitch_options['page_subtitle_fontsize']) < 28 && ($qode_pitch_options['page_subtitle_fontsize']) !== '') { ?>
		.subtitle{
			font-size: <?php echo esc_attr($qode_pitch_options['page_subtitle_fontsize']) *0.8;  ?>px;
		}
	 <?php } ?>
}

@media only screen and (min-width: 480px) and (max-width: 768px){
	<?php if (isset($qode_pitch_options['parallax_minheight']) && !empty($qode_pitch_options['parallax_minheight'])) { ?>
        section.parallax_section_holder{
		height: auto !important;
		min-height: <?php echo esc_attr($qode_pitch_options['parallax_minheight']); ?>px !important;
	}
	<?php } ?>
	
	<?php if (isset($qode_pitch_options['header_background_color_mobile']) &&  !empty($qode_pitch_options['header_background_color_mobile'])) { ?>
	header
	{
		 background-color: <?php echo esc_attr($qode_pitch_options['header_background_color_mobile']);  ?> !important;
		 background-image:none;
	}
	<?php } ?>
}

@media only screen and (max-width: 600px){
	<?php if(isset($qode_pitch_options['h1_fontsize']) && $qode_pitch_options['h1_fontsize'] !== '') {
		$title_font_size = $qode_pitch_options['h1_fontsize'];
		if (($qode_pitch_options['h1_fontsize'])>80) {
			$title_font_size *= 0.4;
		}
		elseif (($qode_pitch_options['h1_fontsize'])>65) {
		 	$title_font_size *= 0.5;
		}
		elseif (($qode_pitch_options['h1_fontsize'])>50) {
		 	$title_font_size *= 0.6;
		}
		elseif (($qode_pitch_options['h1_fontsize'])>35) {
		 	$title_font_size *= 0.7;
		} ?>
		.title h1,
		.title h1.title_like_separator .vc_text_separator.full .separator_content,
		.title.title_size_large h1,
		.title.title_size_large h1.title_like_separator .vc_text_separator.full .separator_content{
			font-size:<?php echo esc_attr($title_font_size); ?>px;
		}
	<?php } ?>
	<?php if(isset($qode_pitch_options['h1_lineheight']) && ($qode_pitch_options['h1_lineheight'])>35) { ?>
		.title h1,
		.title h1.title_like_separator .vc_text_separator.full .separator_content,
		.title.title_size_large h1,
		.title.title_size_large h1.title_like_separator .vc_text_separator.full .separator_content{
		line-height: 1.3em;
		}
	<?php } ?>
	<?php if(isset($qode_pitch_options['page_title_fontsize']) && ($qode_pitch_options['page_title_fontsize']) !== '') {
		$page_title_font_size = $qode_pitch_options['page_title_fontsize'];
		if (($qode_pitch_options['page_title_fontsize'])>80) {
			$page_title_font_size *= 0.4;
		}
		elseif (($qode_pitch_options['page_title_fontsize'])>65) {
		 	$page_title_font_size *= 0.5;
		}
		elseif (($qode_pitch_options['page_title_fontsize'])>50) {
		 	$page_title_font_size *= 0.6;
		}
		elseif (($qode_pitch_options['page_title_fontsize'])>35) {
		 	$page_title_font_size *= 0.7;
		} ?>
		.title h1,
		.title h1.title_like_separator .vc_text_separator.full .separator_content,
		.title.title_size_large h1,
		.title.title_size_large h1.title_like_separator .vc_text_separator.full .separator_content{
			font-size:<?php echo esc_attr($page_title_font_size); ?>px;
		}
	<?php } ?>
	<?php if(isset($qode_pitch_options['page_title_lineheight']) && ($qode_pitch_options['page_title_lineheight'])>35) { ?>
		.title h1,
		.title h1.title_like_separator .vc_text_separator.full .separator_content,
		.title.title_size_large h1,
		.title.title_size_large h1.title_like_separator .vc_text_separator.full .separator_content{
		line-height: 1.3em;
		}
	<?php } ?>
	<?php if(isset($qode_pitch_options['h2_fontsize']) && ($qode_pitch_options['h2_fontsize'])>35) { ?>
			.content h2{
				font-size:<?php echo esc_attr($qode_pitch_options['h2_fontsize'])*0.5; ?>px;
			}
	<?php } ?>
	<?php if(isset($qode_pitch_options['h2_lineheight']) && ($qode_pitch_options['h2_lineheight'])>45) { ?>
		.content h2{
			line-height: 1.3em;
		}
	<?php } ?>
	<?php if(isset($qode_pitch_options['h3_fontsize']) && ($qode_pitch_options['h3_fontsize'])>35) { ?>
		.content h3{
			font-size:<?php echo esc_attr($qode_pitch_options['h3_fontsize'])*0.5; ?>px;
		}
	<?php } ?>
	<?php if(isset($qode_pitch_options['h4_fontsize']) && ($qode_pitch_options['h4_fontsize'])>35) { ?>
		.content h4{
			font-size:<?php echo esc_attr($qode_pitch_options['h4_fontsize'])*0.5; ?>px;
		}
	<?php } ?>
	<?php if(isset($qode_pitch_options['h5_fontsize']) && ($qode_pitch_options['h5_fontsize'])>35) { ?>
		.content h5{
			font-size:<?php echo esc_attr($qode_pitch_options['h5_fontsize'])*0.5; ?>px;
		}
	<?php } ?>
	<?php if(isset($qode_pitch_options['h6_fontsize']) && ($qode_pitch_options['h6_fontsize'])>35) { ?>
		.content h6{
			font-size:<?php echo esc_attr($qode_pitch_options['h6_fontsize'])*0.5; ?>px;
		}
	<?php } ?>
	<?php if(isset($qode_pitch_options['title_span_background_color']) && !empty($qode_pitch_options['title_span_background_color'])) { ?>
		.title h1 span{
			padding: 0 5px;
		}
	<?php } ?>

	<?php if(isset($qode_pitch_options['portfolio_list_filter_height']) && $qode_pitch_options['portfolio_list_filter_height'] !== '') { ?>
		.filter_outer.filter_portfolio{
			height:auto;
		}
	<?php } ?>
}

@media only screen and (max-width: 480px){

	<?php if(isset($qode_pitch_options['h1_fontsize']) && $qode_pitch_options['h1_fontsize'] !== '') {
		$title_font_size = $qode_pitch_options['h1_fontsize'];
		if (($qode_pitch_options['h1_fontsize'])>65) {
		 	$title_font_size *= 0.4;
		}
		elseif (($qode_pitch_options['h1_fontsize'])>50) {
		 	$title_font_size *= 0.5;
		}
		elseif (($qode_pitch_options['h1_fontsize'])>35) {
		 	$title_font_size *= 0.6;
		} ?>
		.title h1,
		.title h1.title_like_separator .vc_text_separator.full .separator_content,
		.title.title_size_large h1,
		.title.title_size_large h1.title_like_separator .vc_text_separator.full .separator_content{
			font-size:<?php echo esc_attr($title_font_size); ?>px;
		}
	<?php } ?>
	<?php if(isset($qode_pitch_options['page_title_lineheight']) && ($qode_pitch_options['page_title_lineheight'])>35) { ?>
		.title h1,
		.title h1.title_like_separator .vc_text_separator.full .separator_content,
		.title.title_size_large h1,
		.title.title_size_large h1.title_like_separator .vc_text_separator.full .separator_content{
		line-height: 1.3em;
		}
	<?php } ?>
	<?php if(isset($qode_pitch_options['page_title_fontsize']) && ($qode_pitch_options['page_title_fontsize']) !== '') {
		$page_title_font_size = $qode_pitch_options['page_title_fontsize'];
		if (($qode_pitch_options['page_title_fontsize'])>65) {
		 	$page_title_font_size *= 0.4;
		}
		elseif (($qode_pitch_options['page_title_fontsize'])>50) {
		 	$page_title_font_size *= 0.5;
		}
		elseif (($qode_pitch_options['page_title_fontsize'])>35) {
		 	$page_title_font_size *= 0.6;
		} ?>
		.title h1,
		.title h1.title_like_separator .vc_text_separator.full .separator_content,
		.title.title_size_large h1,
		.title.title_size_large h1.title_like_separator .vc_text_separator.full .separator_content{
			font-size:<?php echo esc_attr($page_title_font_size); ?>px;
		}
	<?php } ?>
	<?php if(isset($qode_pitch_options['page_title_lineheight']) && ($qode_pitch_options['page_title_lineheight'])>35) { ?>
		.title h1,
		.title h1.title_like_separator .vc_text_separator.full .separator_content,
		.title.title_size_large h1,
		.title.title_size_large h1.title_like_separator .vc_text_separator.full .separator_content{
		line-height: 1.3em;
		}
	<?php } ?>
	<?php if(isset($qode_pitch_options['h2_fontsize']) && ($qode_pitch_options['h2_fontsize'])>35) { ?>
			.content h2{
				font-size:<?php echo esc_attr($qode_pitch_options['h2_fontsize'])*0.4; ?>px;
			}
	<?php } ?>
	<?php if(isset($qode_pitch_options['h3_fontsize']) && ($qode_pitch_options['h3_fontsize'])>35) { ?>
		.content h3{
			font-size:<?php echo esc_attr($qode_pitch_options['h3_fontsize'])*0.4; ?>px;
		}
	<?php } ?>
	<?php if(isset($qode_pitch_options['h4_fontsize']) && ($qode_pitch_options['h4_fontsize'])>35) { ?>
		.content h4{
			font-size:<?php echo esc_attr($qode_pitch_options['h4_fontsize'])*0.4; ?>px;
		}
	<?php } ?>
	<?php if(isset($qode_pitch_options['h5_fontsize']) && ($qode_pitch_options['h5_fontsize'])>35) { ?>
		.content h5{
			font-size:<?php echo esc_attr($qode_pitch_options['h5_fontsize'])*0.4; ?>px;
		}
	<?php } ?>
	<?php if(isset($qode_pitch_options['h6_fontsize']) && ($qode_pitch_options['h6_fontsize'])>35) { ?>
		.content h6{
			font-size:<?php echo esc_attr($qode_pitch_options['h6_fontsize'])*0.4; ?>px;
		}
	<?php } ?>
		
	<?php if (isset($qode_pitch_options['parallax_minheight']) && !empty($qode_pitch_options['parallax_minheight'])) { ?>
	section.parallax_section_holder{
		height: auto !important;
		min-height: <?php echo esc_attr($qode_pitch_options['parallax_minheight']); ?>px !important;
	}
	<?php } ?>
	
	
	<?php if (isset($qode_pitch_options['header_background_color_mobile']) &&  !empty($qode_pitch_options['header_background_color_mobile'])) { ?>
	header
	{
		 background-color: <?php echo esc_attr($qode_pitch_options['header_background_color_mobile']);  ?> !important;
		 background-image:none;
	}
	<?php } ?>

	<?php
		if(isset($qode_pitch_options['masonry_gallery_square_big_title_font_size']) && ($qode_pitch_options['masonry_gallery_square_big_title_font_size']) > 30) { ?>
		        .masonry_gallery_item.square_big h3 {
	        		font-size: <?php echo esc_attr($qode_pitch_options['masonry_gallery_square_big_title_font_size'])*0.7; ?>px;
	    		}
		<?php }
	?>
}