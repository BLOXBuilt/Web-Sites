<?php
//get global variables
global $wp_query;
global $qode_pitch_options;
global $wpdb;
global $wp_filesystem;

//init variables
$portfolio_images 			= get_post_meta(get_the_ID(), "qode_portfolio_images", true);
$lightbox_single_project 	= 'no';
$portfolio_title_tag            = 'h3';
$portfolio_title_style          = '';
$portfolio_gallery_hover_type 	= 'magnifier';
$portfolio_gallery_image_hover_separator = '';
$container_styles = '';

//is page background color set for current page?
if(get_post_meta($id, "qode_page_background_color", true) != ""){
	$container_styles .= 'background-color: '. esc_attr(get_post_meta($id, "qode_page_background_color", true)).';';
}


//is lightbox turned on for single project?
if (isset($qode_pitch_options['lightbox_single_project'])) {
	$lightbox_single_project = $qode_pitch_options['lightbox_single_project'];
}

//set title tag
if (isset($qode_pitch_options['portfolio_title_tag']) && !empty($qode_pitch_options['portfolio_title_tag'])) {
    $portfolio_title_tag = $qode_pitch_options['portfolio_title_tag'];
}

//gallery hover type (image, or text)
if (isset($qode_pitch_options['portfolio_gallery_image_hover_style'])) {
    $portfolio_gallery_hover_type = $qode_pitch_options['portfolio_gallery_image_hover_style'];
}

//gallery hover separator with text
if (isset($qode_pitch_options['portfolio_gallery_image_hover_separator'])) {
    $portfolio_gallery_image_hover_separator = $qode_pitch_options['portfolio_gallery_image_hover_separator'];
}
//is lightbox turned on for video single project?
if (isset($qode_pitch_options['lightbox_video_single_project'])) {
    $lightbox_video_single_project = $qode_pitch_options['lightbox_video_single_project'];
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


//sort portfolio images by user defined input
if (is_array($portfolio_images)){
	usort($portfolio_images, "qode_pitch_comparePortfolioImages");
}

?>
<div class="container" <?php qode_pitch_inline_style($container_styles); ?>>
	<div class="container_inner default_template_holder clearfix">
		<div class="two_columns_33_66 clearfix portfolio_container">
			<div class="column1">
				<div class="column_inner">
					<div class="portfolio_detail clearfix">
						<?php
							//get portfolio content section
							get_template_part('templates/portfolio/parts/portfolio-content');

							//get portfolio custom fields section
							get_template_part('templates/portfolio/parts/portfolio-custom-fields');

							//get portfolio date section
							get_template_part('templates/portfolio/parts/portfolio-date');

							//get portfolio categories section
							get_template_part('templates/portfolio/parts/portfolio-categories');

							//get portfolio tags section
							get_template_part('templates/portfolio/parts/portfolio-tags');

							//get portfolio share section
							get_template_part('templates/portfolio/parts/portfolio-social');
						?>
					</div>
					
				</div>
			</div>
			<div class="column2">
				<div class="column_inner">
					<div class="portfolio_gallery portfolio_masonry_gallery">
						<div class="single_masonry_grid_sizer"></div>
						<?php
						$portfolio_m_images = get_post_meta(get_the_ID(), "qode_portfolio-image-gallery", true);
						if ($portfolio_m_images){
							$portfolio_image_gallery_array=explode(',',$portfolio_m_images);
							foreach($portfolio_image_gallery_array as $gimg_id){
								$title = get_the_title($gimg_id);
								$alt = get_post_meta($gimg_id, '_wp_attachment_image_alt', true);
								$portfolio_gallery_thumb_size = get_post_meta(get_the_ID(), 'qode_choose-portfolio-image-size', true);
								$portfolio_gallery_thumb_size = (!empty($portfolio_gallery_thumb_size)) ? get_post_meta(get_the_ID(), 'qode_choose-portfolio-image-size', true) : 'full';
								$image_src = wp_get_attachment_image_src( $gimg_id, $portfolio_gallery_thumb_size );
								if (is_array($image_src)) $image_src = $image_src[0];
								$image_light_src = wp_get_attachment_image_src( $gimg_id, 'full' );
								$image_predefined_size = get_post_meta($gimg_id,'qode_portfolio_single_predefined_size',true);
								if (is_array($image_light_src)) $image_light_src = $image_light_src[0];
								?>
								<?php if($lightbox_single_project == "yes"){ ?>
									<a class="lightbox_single_portfolio mix <?php echo esc_attr($image_predefined_size); ?>" title="<?php echo esc_attr($title); ?>" href="<?php echo esc_url($image_light_src); ?>" data-rel="prettyPhoto[single_pretty_photo]">
										<span class="inner">
										 <?php if($portfolio_gallery_hover_type !== "disable"){ ?>
											   <span class="gallery_text_holder"><span class="gallery_text_outer"><span class="gallery_text_inner">
													<?php
													if($portfolio_gallery_hover_type == "icon"){ ?>
														<i class="fa fa-plus"></i>
													<?php }
													elseif($portfolio_gallery_hover_type == "text"){ ?>
														<h4><?php echo esc_html($title); ?></h4>
														<?php if($portfolio_gallery_image_hover_separator == "yes"){ ?>
															<span class="separator animate"></span>
														<?php } ?>
													<?php }
													else{ ?>
														<i class="fa fa-2x fa-search"></i>
													<?php  } ?>

												</span></span></span>
											 <?php  }?>
											<img src="<?php echo esc_url($image_src); ?>" alt="<?php echo esc_attr($alt); ?>" />
										</span>
									</a>
								<?php } else { ?>
									<a class="lightbox_single_portfolio mix" href="#">
										<span class="inner">
											<span class="gallery_text_holder"><span class="gallery_text_outer"><span class="gallery_text_inner"><h4><?php echo esc_html($title); ?></h4></span></span></span>
											<img src="<?php echo esc_url($image_src); ?>" alt="<?php echo esc_attr($alt); ?>" />
										</span>
									</a>
								<?php }
							}
						}

						if (is_array($portfolio_images) && count($portfolio_images)){
							foreach($portfolio_images as $portfolio_image){
								?>

								<?php if($portfolio_image['portfolioimg'] != ""){ ?>
									<?php

									list($id, $title, $alt) = qode_pitch_get_portfolio_image_meta($portfolio_image['portfolioimg']);

									$single_image_id = qode_pitch_get_attachment_id_from_url($portfolio_image['portfolioimg']);
									if(!empty($single_image_id)){
										$single_image_gallery_thumb_size = get_post_meta(get_the_ID(), 'qode_choose-portfolio-image-size', true);
										$single_image_size = (!empty($single_image_gallery_thumb_size)) ? get_post_meta(get_the_ID(), 'qode_choose-portfolio-image-size', true) : 'full';
										$single_image_src = wp_get_attachment_image_src( $single_image_id, $single_image_size );
										$image_predefined_size = get_post_meta($single_image_id,'qode_portfolio_single_predefined_size',true);
										if (is_array($single_image_src)) $single_image_src = $single_image_src[0];
									} else {
										$single_image_src = esc_url($portfolio_image['portfolioimg']);
									}

									?>
									<?php if($lightbox_single_project == "yes"){ ?>
										<a class="lightbox_single_portfolio mix <?php echo esc_attr($image_predefined_size); ?>" title="<?php echo esc_attr($portfolio_image['portfoliotitle']); ?>" href="<?php echo esc_url($portfolio_image['portfolioimg']); ?>" data-rel="prettyPhoto[single_pretty_photo]">
											<span class="inner">
												<?php if($portfolio_gallery_hover_type !== "disable"){ ?>
													<span class="gallery_text_holder"><span class="gallery_text_outer"><span class="gallery_text_inner">
													<?php
													if($portfolio_gallery_hover_type == "icon"){ ?>
														<i class="fa fa-plus"></i>
													<?php }
													elseif($portfolio_gallery_hover_type == "text"){ ?>
														<h4><?php echo esc_html($title); ?></h4>
														<?php if($portfolio_gallery_image_hover_separator == "yes"){ ?>
															<span class="separator animate"></span>
														<?php } ?>
													<?php }
													else{ ?>
														<i class="fa fa-2x fa-search"></i>
													<?php  } ?>

												</span></span></span>
												<?php  }?>
												<img src="<?php echo esc_url($single_image_src); ?>" alt="<?php echo esc_attr($alt); ?>" />
											</span>
										</a>
									<?php } else { ?>
										<a class="lightbox_single_portfolio mix <?php echo esc_attr($image_predefined_size); ?>" href="#">
										<span class="inner">
											<?php if($portfolio_gallery_hover_type !== "disable"){ ?>
												<span class="gallery_text_holder"><span class="gallery_text_outer"><span class="gallery_text_inner">
												<?php
												if($portfolio_gallery_hover_type == "icon"){ ?>
													<i class="fa fa-plus"></i>
												<?php }
												elseif($portfolio_gallery_hover_type == "text"){ ?>
													<h4><?php echo esc_html($title); ?></h4>
													<?php if($portfolio_gallery_image_hover_separator == "yes"){ ?>
														<span class="separator animate"></span>
													<?php } ?>
												<?php }
												else{ ?>
													<i class="fa fa-2x fa-search"></i>
												<?php  } ?>

											</span></span></span>
											<?php  }?>
										<img src="<?php echo esc_url($single_image_src); ?>" alt="<?php echo esc_attr($alt); ?>" />
										</span>
										</a>
									<?php } ?>

								<?php }
								else{ ?>
								<?php
								$portfolio_video_type = "";
								if (isset($portfolio_image['portfoliovideotype'])) $portfolio_video_type = $portfolio_image['portfoliovideotype'];
								switch ($portfolio_video_type){
								case "youtube": ?>
									<?php if($lightbox_video_single_project == "yes"){ ?>
										<?php
										WP_Filesystem();
										$vidID = esc_attr($portfolio_image['portfoliovideoid']);
										$url = "http://gdata.youtube.com/feeds/api/videos/".$vidID."?alt=json";
										$xml = unserialize($wp_filesystem->get_contents($url));

										if(is_array($xml['entry']['title'])){
											$video_title = array_shift($xml['entry']['title']);
										} else {
											$video_title = "";
										}

										$thumbnail = "//img.youtube.com/vi/".$vidID."/maxresdefault.jpg";
										?>
										<a class="lightbox_single_portfolio mix" title="<?php echo esc_attr($video_title); ?>" href="//www.youtube.com/watch?feature=player_embedded&v=<?php echo esc_attr($vidID); ?>" data-rel="prettyPhoto[single_pretty_photo]">
											<span class="inner">
												<i class="fa fa-play"></i>
												<img width="100%" src="<?php echo esc_url($thumbnail); ?>"/>
											</span>
										</a>
									<?php } else { ?>
										<a class="lightbox_single_portfolio mix">
											<span class="inner">
												<iframe width="100%" src="//www.youtube.com/embed/<?php echo esc_attr($portfolio_image['portfoliovideoid']);  ?>?wmode=transparent" wmode="Opaque" frameborder="0" allowfullscreen></iframe>
											</span>
										</a>
									<?php } ?>
									<?php	break;
								case "vimeo": ?>
									<?php if($lightbox_video_single_project == "yes"){ ?>
										<?php
										WP_Filesystem();
										$vidID = esc_attr($portfolio_image['portfoliovideoid']);
										$url = "http://vimeo.com/api/v2/video/".$vidID.".php";
										$xml = unserialize($wp_filesystem->get_contents($url));

										$video_title = $xml[0]['title'];
										$thumbnail = $xml[0]['thumbnail_large'];
										?>
										<a class="lightbox_single_portfolio mix" title="<?php echo esc_attr($video_title); ?>" href="http://vimeo.com/<?php echo esc_attr($vidID); ?>" data-rel="prettyPhoto[single_pretty_photo]">
											<span class="inner">
												<i class="fa fa-play"></i>
												<img width="100%" src="<?php echo esc_url($thumbnail); ?>"/>
											</span>
										</a>
									<?php } else { ?>
										<a class="lightbox_single_portfolio mix">
											<span class="inner">
												<iframe src="//player.vimeo.com/video/<?php echo esc_attr($portfolio_image['portfoliovideoid']); ?>?title=0&amp;byline=0&amp;portrait=0" width="100%" frameborder="0" webkitAllowFullScreen mozallowfullscreen allowFullScreen></iframe>
											</span>
										</a>
									<?php } ?>
									<?php break;
								case "self": ?>
								<?php if($lightbox_video_single_project == "yes"){ ?>
								<a class="lightbox_single_portfolio mix" onclick='return false;' href="#">
									<span class="inner">
										<?php } else { ?>
												<a class="lightbox_single_portfolio mix">
											<span>
										<?php } ?>
										<div class="video">
											<div class="mobile-video-image" style="background-image: url(<?php echo esc_url($portfolio_image['portfoliovideoimage']); ?>);"></div>
											<div class="video-wrap">
												<video class="video" poster="<?php echo esc_url($portfolio_image['portfoliovideoimage']); ?>" preload="auto">
													<?php if(!empty($portfolio_image['portfoliovideowebm'])) { ?> <source type="video/webm" src="<?php echo esc_url($portfolio_image['portfoliovideowebm']); ?>"> <?php } ?>
													<?php if(!empty($portfolio_image['portfoliovideomp4'])) { ?> <source type="video/mp4" src="<?php echo esc_url($portfolio_image['portfoliovideomp4']); ?>"> <?php } ?>
													<?php if(!empty($portfolio_image['portfoliovideoogv'])) { ?> <source type="video/ogg" src="<?php echo esc_url($portfolio_image['portfoliovideoogv']); ?>"> <?php } ?>
													<object width="320" height="240" type="application/x-shockwave-flash" data="<?php echo esc_url(get_template_directory_uri().'/js/flashmediaelement.swf'); ?>">
														<param name="movie" value="<?php echo esc_url(get_template_directory_uri().'/js/flashmediaelement.swf'); ?>" />
														<param name="flashvars" value="controls=true&file=<?php echo esc_url($portfolio_image['portfoliovideomp4']); ?>" />
														<img src="<?php echo esc_url($portfolio_image['portfoliovideoimage']); ?>" width="1920" height="800" title="No video playback capabilities" alt="Video thumb" />
													</object>
												</video>
											</div>
										</div>
									</span>
								</a>
								<?php break;
									} //close switch
								} //close video section
							}
						}
						?>
					</div>
				</div>
			</div>
		</div>
	</div>
</div>