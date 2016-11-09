<?php
global $qode_pitch_options;
global $more;
$more = 0;


$blog_show_categories = "no";

$blog_show_comments = "no";

$blog_show_author = "yes";

$blog_show_like = "yes";

$blog_show_ql_icon_mark = "yes";
$blog_title_holder_icon_class = "";

if($blog_show_ql_icon_mark == "yes"){
    $blog_title_holder_icon_class = " with_icon";
}

$blog_show_date = "yes";

$blog_show_social_share = "yes";
$blog_social_share_type = "list";


$blog_image_size = 'full';
$image_html = get_the_post_thumbnail(get_the_ID(), $blog_image_size);


$blog_ql_background_image = "no";

$background_image_object = wp_get_attachment_image_src(get_post_thumbnail_id( get_the_ID()), 'qode-pitch-blog_image_format_link_quote');
$background_image_src = $background_image_object[0];

$blog_show_read_more_button = "yes";

$_post_format = get_post_format();

$pagination_classes = '';
if( isset($qode_pitch_options['pagination_type']) && $qode_pitch_options['pagination_type'] == 'standard' ) {
	if( isset($qode_pitch_options['pagination_standard_position']) && $qode_pitch_options['pagination_standard_position'] !== '' ) {
		$pagination_classes .= "standard_".esc_attr($qode_pitch_options['pagination_standard_position']);
	}
}
elseif ( isset($qode_pitch_options['pagination_type']) && $qode_pitch_options['pagination_type'] == 'arrows_on_sides' ) {
	$pagination_classes .= "arrows_on_sides";
}
?>

<?php
$args_pages = array(
    'before'           => '<div class="single_links_pages ' .$pagination_classes. '"><div class="single_links_pages_inner">',
    'after'            => '</div></div>',
    'link_before'      => '<span>',
    'link_after'       => '</span>',
    'pagelink'         => '%'
);
?>
<?php
switch ($_post_format) {
    case "video":
        ?>
        <article id="post-<?php the_ID(); ?>" <?php post_class(); ?>>
            <div class="post_content_holder">
                <h2>
                    <a href="<?php the_permalink(); ?>" title="<?php the_title_attribute(); ?>"><?php the_title(); ?></a>
                </h2>
                <h4 class="post_subtitle">
                    <?php qode_pitch_excerpt(); ?>
                </h4>
                <div class="post_image">
                    <?php $_video_type = get_post_meta(get_the_ID(), "video_format_choose", true);?>
                    <?php if($_video_type == "youtube") { ?>
                        <iframe  src="//www.youtube.com/embed/<?php echo esc_attr(get_post_meta(get_the_ID(), "video_format_link", true));  ?>?wmode=transparent" wmode="Opaque" frameborder="0" allowfullscreen></iframe>
                    <?php } elseif ($_video_type == "vimeo"){ ?>
                        <iframe src="//player.vimeo.com/video/<?php echo esc_attr(get_post_meta(get_the_ID(), "video_format_link", true));  ?>?title=0&amp;byline=0&amp;portrait=0" frameborder="0" webkitAllowFullScreen mozallowfullscreen allowFullScreen></iframe>
                    <?php } elseif ($_video_type == "self"){ ?>
                        <div class="video">
                            <div class="mobile-video-image" style="background-image: url(<?php echo esc_url(get_post_meta(get_the_ID(), "video_format_image", true));  ?>);"></div>
                            <div class="video-wrap"  >
                                <video class="video" poster="<?php echo esc_url(get_post_meta(get_the_ID(), "video_format_image", true));  ?>" preload="auto">
                                    <?php if(get_post_meta(get_the_ID(), "video_format_webm", true) != "") { ?> <source type="video/webm" src="<?php echo esc_url(get_post_meta(get_the_ID(), "video_format_webm", true));  ?>"> <?php } ?>
                                    <?php if(get_post_meta(get_the_ID(), "video_format_mp4", true) != "") { ?> <source type="video/mp4" src="<?php echo esc_url(get_post_meta(get_the_ID(), "video_format_mp4", true));  ?>"> <?php } ?>
                                    <?php if(get_post_meta(get_the_ID(), "video_format_ogv", true) != "") { ?> <source type="video/ogg" src="<?php echo esc_url(get_post_meta(get_the_ID(), "video_format_ogv", true));  ?>"> <?php } ?>
                                    <object width="320" height="240" type="application/x-shockwave-flash" data="<?php echo esc_url(get_template_directory_uri().'/js/flashmediaelement.swf'); ?>">
                                        <param name="movie" value="<?php echo esc_url(get_template_directory_uri().'/js/flashmediaelement.swf'); ?>" />
                                        <param name="flashvars" value="controls=true&file=<?php echo esc_url(get_post_meta(get_the_ID(), "video_format_mp4", true));  ?>" />
                                        <img src="<?php echo esc_url(get_post_meta(get_the_ID(), "video_format_image", true));  ?>" width="1920" height="800" title="No video playback capabilities" alt="Video thumb" />
                                    </object>
                                </video>
                            </div>
                        </div>
                    <?php } ?>
                </div>
                <div class="post_text">
                    <div class="post_text_inner container_inner">
                        <div class="post_info post_info_left">
                            <?php if(isset($qode_pitch_options['blog_single_show_social_share']) && $qode_pitch_options['blog_single_show_social_share'] == "yes" && $blog_social_share_type == "list") { ?>
                                <div class="post_info_left_item_holder">
                                    <h5><?php esc_html_e("Share:","pitchwp"); ?></h5>
                                    <?php  echo do_shortcode('[no_social_share_list]'); // XSS OK ?>
                                </div>
                            <?php } ?>
                            <?php if($blog_show_author == "yes") { ?>
                                <div class="post_info_left_item_holder">
                                    <h5><?php esc_html_e("Written by:","pitchwp"); ?></h5>
                                    <span>
                                    <?php
                                    if(get_the_author_meta('first_name') != "" || get_the_author_meta('last_name') != "") {
                                        echo esc_attr(get_the_author_meta('first_name')) . " " . esc_attr(get_the_author_meta('last_name'));
                                    } else {
                                        echo esc_attr(get_the_author_meta('display_name'));
                                    }?>
                                    </span>
                                </div>
                            <?php } ?>
                            <?php if($blog_show_author == "yes") { ?>
                                <div class="post_info_left_item_holder">
                                    <h5> <?php esc_html_e("Date:","pitchwp"); ?></h5>
                                    <span class="date"><?php the_time(get_option('date_format')); ?></span>
                                </div>
                                <?php
                            }
                            ?>
                            <?php if($blog_show_categories == "yes") { ?>
                                <div class="post_info_left_item_holder">
                                    <h5> <?php esc_html_e("Categories:","pitchwp"); ?></h5>
                                    <?php the_category(', '); ?>
                                </div>
                                <?php
                            }
                            ?>
                            <?php if($blog_show_comments == "yes") { ?>
                                <div class="post_info_left_item_holder">
                                    <h5> <?php esc_html_e("Comments:","pitchwp"); ?></h5>
                                    <?php qode_pitch_post_info(array('comments' => $blog_show_comments)); ?>
                                </div>
                            <?php } ?>
                            <?php if( has_tag()) { ?>
                                <div class="single_tags clearfix">
                                    <div class="tags_text">
                                        <h5 class="single_tags_heading"><?php esc_html_e('Tags:', 'pitchwp'); ?></h5>
                                        <div class="single_tags_holder">
                                            <?php the_tags('', ',', ''); ?>
                                        </div>
                                    </div>
                                </div>
                            <?php } ?>
                        </div>
                        <div class="post_info_right">
                            <?php the_content(); ?>
                            <div class="post_info post_info_bottom">
                                <?php qode_pitch_post_info(array('like' => $blog_show_like)) ?>
                                <?php if(isset($qode_pitch_options['blog_single_show_social_share']) && $qode_pitch_options['blog_single_show_social_share'] == "yes" && $blog_social_share_type == "list") { ?>
                                <div class="social_share_list_standard_post_holder">
                                    <i class="fa fa-share"></i>
                                    <span><?php esc_html_e("Share:","pitchwp"); ?></span>
                                    <?php
                                    echo do_shortcode('[no_social_share_list]'); // XSS OK
                                    ?>
                                </div>
                                <?php }; ?>
                                <?php if(isset($qode_pitch_options['blog_single_show_social_share']) && $qode_pitch_options['blog_single_show_social_share'] == "yes" && $blog_social_share_type == "dropdown") {
                                    qode_pitch_post_info(array('share' => $blog_show_social_share));
                                }; ?>
                            </div>
							<?php wp_link_pages($args_pages); ?> 
                            <?php
                            if($blog_show_read_more_button == "yes"){?>
                                <a href="<?php the_permalink(); ?>" target="_self" class="qbutton small read_more_button"><?php esc_html_e("Continue Reading", "pitchwp"); ?></a>
                            <?php } ?>
                        </div>
                    </div>
                </div>
            </div>
        </article>
        <?php
        break;
    case "audio":
        ?>
        <article id="post-<?php the_ID(); ?>" <?php post_class(); ?>>
            <div class="post_content_holder">
                <h2>
                    <a href="<?php the_permalink(); ?>" title="<?php the_title_attribute(); ?>"><?php the_title(); ?></a>
                </h2>
                <div class="post_subtitle">
                    <?php qode_pitch_excerpt(); ?>
                </div>
                <?php if ( has_post_thumbnail() ) { ?>
                    <div class="post_image">
                        <a href="<?php the_permalink(); ?>" title="<?php the_title_attribute(); ?>">
                            <?php echo wp_kses($image_html, array(
                                'img' => array(
                                    'src' => true,
                                    'alt' => true,
                                    'width' => true,
                                    'height' => true,
                                    'draggable' => true
                                )
                            )); ?>
                        </a>
                    </div>
                <?php } ?>
                <div class="audio_image">
                    <audio class="blog_audio" src="<?php echo esc_url(get_post_meta(get_the_ID(), "audio_link", true)) ?>" controls="controls">
                        <?php esc_html_e("Your browser don't support audio player","pitchwp"); ?>
                    </audio>
                </div>
                <div class="post_text">
                    <div class="post_text_inner container_inner">
                        <div class="post_info post_info_left">
                            <?php if(isset($qode_pitch_options['blog_single_show_social_share']) && $qode_pitch_options['blog_single_show_social_share'] == "yes" && $blog_social_share_type == "list") { ?>
                                <div class="post_info_left_item_holder">
                                    <h5><?php esc_html_e("Share:","pitchwp"); ?></h5>
                                    <?php  echo do_shortcode('[no_social_share_list]'); // XSS OK ?>
                                </div>
                            <?php } ?>
                            <?php if($blog_show_author == "yes") { ?>
                                <div class="post_info_left_item_holder">
                                    <h5><?php esc_html_e("Written by:","pitchwp"); ?></h5>
                                    <span>
                                    <?php
                                    if(get_the_author_meta('first_name') != "" || get_the_author_meta('last_name') != "") {
                                        echo esc_attr(get_the_author_meta('first_name')) . " " . esc_attr(get_the_author_meta('last_name'));
                                    } else {
                                        echo esc_attr(get_the_author_meta('display_name'));
                                    }?>
                                    </span>
                                </div>
                            <?php } ?>
                            <?php if($blog_show_author == "yes") { ?>
                                <div class="post_info_left_item_holder">
                                    <h5> <?php esc_html_e("Date:","pitchwp"); ?></h5>
                                    <span class="date"><?php the_time(get_option('date_format')); ?></span>
                                </div>
                                <?php
                            }
                            ?>
                            <?php if($blog_show_categories == "yes") { ?>
                                <div class="post_info_left_item_holder">
                                    <h5> <?php esc_html_e("Categories:","pitchwp"); ?></h5>
                                    <?php the_category(', '); ?>
                                </div>
                                <?php
                            }
                            ?>
                            <?php if($blog_show_comments == "yes") { ?>
                                <div class="post_info_left_item_holder">
                                    <h5> <?php esc_html_e("Comments:","pitchwp"); ?></h5>
                                    <?php qode_pitch_post_info(array('comments' => $blog_show_comments)); ?>
                                </div>
                            <?php } ?>
                            <?php if( has_tag()) { ?>
                                <div class="single_tags clearfix">
                                    <div class="tags_text">
                                        <h5 class="single_tags_heading"><?php esc_html_e('Tags:', 'pitchwp'); ?></h5>
                                        <div class="single_tags_holder">
                                            <?php the_tags('', ',', ''); ?>
                                        </div>
                                    </div>
                                </div>
                            <?php } ?>
                        </div>
                        <div class="post_info_right">
                            <?php the_content(); ?>
                            <div class="post_info post_info_bottom">
                                <?php qode_pitch_post_info(array('like' => $blog_show_like)) ?>
                                <?php if(isset($qode_pitch_options['blog_single_show_social_share']) && $qode_pitch_options['blog_single_show_social_share'] == "yes" && $blog_social_share_type == "list") { ?>
                                <div class="social_share_list_standard_post_holder">
                                    <i class="fa fa-share"></i>
                                    <span><?php esc_html_e("Share:","pitchwp"); ?></span>
                                    <?php
                                    echo do_shortcode('[no_social_share_list]'); // XSS OK
                                    ?>
                                </div>
                                <?php }; ?>
                                <?php if(isset($qode_pitch_options['blog_single_show_social_share']) && $qode_pitch_options['blog_single_show_social_share'] == "yes" && $blog_social_share_type == "dropdown") {
                                    qode_pitch_post_info(array('share' => $blog_show_social_share));
                                }; ?>
                            </div>
							<?php wp_link_pages($args_pages); ?> 
                            <?php
                            if($blog_show_read_more_button == "yes"){?>
                                <a href="<?php the_permalink(); ?>" target="_self" class="qbutton small read_more_button"><?php esc_html_e("Continue Reading", "pitchwp"); ?></a>
                            <?php } ?>
                        </div>
                    </div>
                </div>
            </div>
        </article>
        <?php
        break;
    case "link":
        ?>
        <article id="post-<?php the_ID(); ?>" <?php post_class(); ?>>
            <div class="post_content_holder">
                <div class="post_text_columns">
                    <div class="post_text  <?php if($blog_ql_background_image == "yes") {if ( has_post_thumbnail() ) { ?> link_image" style="background:url(<?php echo esc_url($background_image_src); ?>); <?php } } ?>">
                        <div class="post_text_inner container_inner">
                            <?php if($blog_show_date == "yes" || $blog_show_categories == "yes" || $blog_show_author == "yes" || $blog_show_comments == "yes") { ?>
                                <div class="post_info post_info_top">
                                    <?php qode_pitch_post_info(array('date' => $blog_show_date, 'category' => $blog_show_categories, 'author' => $blog_show_author, 'comments' => $blog_show_comments)) ?>
                                </div>
                            <?php } ?>
                            <div class="post_title<?php echo esc_attr($blog_title_holder_icon_class); ?>">
                                <h3><a href="<?php the_permalink(); ?>" title="<?php the_title_attribute(); ?>"><?php the_title(); ?></a></h3>
                            </div>
                            <div class="post_info post_info_bottom">
                                <?php qode_pitch_post_info(array('like' => $blog_show_like)) ?>
                                <?php if(isset($qode_pitch_options['blog_single_show_social_share']) && $qode_pitch_options['blog_single_show_social_share'] == "yes" && $blog_social_share_type == "list") { ?>
                                <div class="social_share_list_standard_post_holder">
                                    <i class="fa fa-share"></i>
                                    <span><?php esc_html_e("Share:","pitchwp"); ?></span>
                                    <?php
                                    echo do_shortcode('[no_social_share_list]'); // XSS OK
                                    ?>
                                    </div>
                                <?php }; ?>
                                    <?php if(isset($qode_pitch_options['blog_single_show_social_share']) && $qode_pitch_options['blog_single_show_social_share'] == "yes" && $blog_social_share_type == "dropdown") {
                                    qode_pitch_post_info(array('share' => $blog_show_social_share));
                                }; ?>
                            </div>
							<?php wp_link_pages($args_pages); ?> 
                        </div>
                    </div>
                </div>
            </div>
        </article>
        <?php
        break;
    case "gallery":
        ?>
        <article id="post-<?php the_ID(); ?>" <?php post_class(); ?>>
            <div class="post_content_holder">
                <h2>
                    <a href="<?php the_permalink(); ?>" title="<?php the_title_attribute(); ?>"><?php the_title(); ?></a>
                </h2>
                <h4 class="post_subtitle">
                    <?php qode_pitch_excerpt(); ?>
                </h4>
                <div class="post_image">
                    <?php get_template_part('templates/blog/parts/post-format-gallery-slider'); ?>
                </div>
                <div class="post_text">
                    <div class="post_text_inner container_inner">
                        <div class="post_info post_info_left">
                            <?php if(isset($qode_pitch_options['blog_single_show_social_share']) && $qode_pitch_options['blog_single_show_social_share'] == "yes" && $blog_social_share_type == "list") { ?>
                                <div class="post_info_left_item_holder">
                                    <h5><?php esc_html_e("Share:","pitchwp"); ?></h5>
                                    <?php  echo do_shortcode('[no_social_share_list]'); // XSS OK ?>
                                </div>
                            <?php } ?>
                            <?php if($blog_show_author == "yes") { ?>
                                <div class="post_info_left_item_holder">
                                    <h5><?php esc_html_e("Written by:","pitchwp"); ?></h5>
                                    <span>
                                    <?php
                                    if(get_the_author_meta('first_name') != "" || get_the_author_meta('last_name') != "") {
                                        echo esc_attr(get_the_author_meta('first_name')) . " " . esc_attr(get_the_author_meta('last_name'));
                                    } else {
                                        echo esc_attr(get_the_author_meta('display_name'));
                                    }?>
                                    </span>
                                </div>
                            <?php } ?>
                            <?php if($blog_show_author == "yes") { ?>
                                <div class="post_info_left_item_holder">
                                    <h5> <?php esc_html_e("Date:","pitchwp"); ?></h5>
                                    <span class="date"><?php the_time(get_option('date_format')); ?></span>
                                </div>
                                <?php
                            }
                            ?>
                            <?php if($blog_show_categories == "yes") { ?>
                                <div class="post_info_left_item_holder">
                                    <h5> <?php esc_html_e("Categories:","pitchwp"); ?></h5>
                                    <?php the_category(', '); ?>
                                </div>
                                <?php
                            }
                            ?>
                            <?php if($blog_show_comments == "yes") { ?>
                                <div class="post_info_left_item_holder">
                                    <h5> <?php esc_html_e("Comments:","pitchwp"); ?></h5>
                                    <?php qode_pitch_post_info(array('comments' => $blog_show_comments)); ?>
                                </div>
                            <?php } ?>
                            <?php if( has_tag()) { ?>
                                <div class="single_tags clearfix">
                                    <div class="tags_text">
                                        <h5 class="single_tags_heading"><?php esc_html_e('Tags:', 'pitchwp'); ?></h5>
                                        <div class="single_tags_holder">
                                            <?php the_tags('', ',', ''); ?>
                                        </div>
                                    </div>
                                </div>
                            <?php } ?>
                        </div>
                        <div class="post_info_right">
                            <?php the_content(); ?>
                            <div class="post_info post_info_bottom">
                                <?php qode_pitch_post_info(array('like' => $blog_show_like)) ?>
                                <?php if(isset($qode_pitch_options['blog_single_show_social_share']) && $qode_pitch_options['blog_single_show_social_share'] == "yes" && $blog_social_share_type == "list") { ?>
                                <div class="social_share_list_standard_post_holder">
                                    <i class="fa fa-share"></i>
                                    <span><?php esc_html_e("Share:","pitchwp"); ?></span>
                                    <?php
                                    echo do_shortcode('[no_social_share_list]'); // XSS OK
                                    ?>
                                </div>
                                <?php }; ?>
                                <?php if(isset($qode_pitch_options['blog_single_show_social_share']) && $qode_pitch_options['blog_single_show_social_share'] == "yes" && $blog_social_share_type == "dropdown") {
                                    qode_pitch_post_info(array('share' => $blog_show_social_share));
                                }; ?>
                            </div>
							<?php wp_link_pages($args_pages); ?> 
                            <?php
                            if($blog_show_read_more_button == "yes"){?>
                                <a href="<?php the_permalink(); ?>" target="_self" class="qbutton small read_more_button"><?php esc_html_e("Continue Reading", "pitchwp"); ?></a>
                            <?php } ?>
                        </div>
                    </div>
                </div>
            </div>
        </article>
        <?php
        break;
    case "quote":
        ?>
        <article id="post-<?php the_ID(); ?>" <?php post_class(); ?>>
            <div class="post_content_holder">
                <div class="post_text_columns">
                    <div class="post_text  <?php if($blog_ql_background_image == "yes") {if ( has_post_thumbnail() ) { ?> quote_image" style="background:url(<?php echo esc_url($background_image_src); ?>); <?php } } ?>">
                        <div class="post_text_inner container_inner">
                            <?php if($blog_show_date == "yes" || $blog_show_categories == "yes" || $blog_show_author == "yes" || $blog_show_comments == "yes") { ?>
                                <div class="post_info post_info_top">
                                    <?php qode_pitch_post_info(array('date' => $blog_show_date, 'category' => $blog_show_categories, 'author' => $blog_show_author, 'comments' => $blog_show_comments)) ?>
                                </div>
                            <?php } ?>
                            <div class="post_title<?php echo esc_attr($blog_title_holder_icon_class); ?>">
                                <h3>
                                    <a href="<?php the_permalink(); ?>" title="<?php the_title_attribute(); ?>"><?php echo esc_html(get_post_meta(get_the_ID(), "quote_format", true)); ?></a>
                                </h3>
                                <span class="quote_author">&ndash; <?php the_title(); ?></span>
                            </div>
                            <div class="post_info post_info_bottom">
                                <?php qode_pitch_post_info(array('like' => $blog_show_like)) ?>
                                <?php if(isset($qode_pitch_options['blog_single_show_social_share']) && $qode_pitch_options['blog_single_show_social_share'] == "yes" && $blog_social_share_type == "list") { ?>
                                <div class="social_share_list_standard_post_holder">
                                    <i class="fa fa-share"></i>
                                    <span><?php esc_html_e("Share:","pitchwp"); ?></span>
                                    <?php
                                    echo do_shortcode('[no_social_share_list]'); // XSS OK
                                    ?>
                                </div>
                                <?php }; ?>
                                <?php if(isset($qode_pitch_options['blog_single_show_social_share']) && $qode_pitch_options['blog_single_show_social_share'] == "yes" && $blog_social_share_type == "dropdown") {
                                    qode_pitch_post_info(array('share' => $blog_show_social_share));
                                }; ?>
                            </div>
							<?php wp_link_pages($args_pages); ?> 
                        </div>
                    </div>
                </div>
            </div>
        </article>
        <?php
        break;
    default:
        ?>
        <article id="post-<?php the_ID(); ?>" <?php post_class(); ?>>
            <div class="post_content_holder">
                <h2>
                    <a href="<?php the_permalink(); ?>" title="<?php the_title_attribute(); ?>"><?php the_title(); ?></a>
                </h2>
                <h4 class="post_subtitle">
                    <?php qode_pitch_excerpt(); ?>
                </h4>
                <?php if ( has_post_thumbnail() ) { ?>
                    <div class="post_image">
                        <a href="<?php the_permalink(); ?>" title="<?php the_title_attribute(); ?>">
                            <?php echo wp_kses($image_html, array(
                                'img' => array(
                                    'src' => true,
                                    'alt' => true,
                                    'width' => true,
                                    'height' => true,
                                    'draggable' => true
                                )
                            )); ?>
                        </a>
                    </div>
                <?php } ?>
                <div class="post_text">
                    <div class="post_text_inner container_inner">
                        <div class="post_info post_info_left">
                            <?php if(isset($qode_pitch_options['blog_single_show_social_share']) && $qode_pitch_options['blog_single_show_social_share'] == "yes" && $blog_social_share_type == "list") { ?>
                                <div class="post_info_left_item_holder">
                                    <h5><?php esc_html_e("Share:","pitchwp"); ?></h5>
                                    <?php  echo do_shortcode('[no_social_share_list]'); // XSS OK ?>
                                </div>
                            <?php } ?>
                            <?php if($blog_show_author == "yes") { ?>
                                <div class="post_info_left_item_holder">
                                    <h5><?php esc_html_e("Written by:","pitchwp"); ?></h5>
                                    <span>
                                    <?php
                                    if(get_the_author_meta('first_name') != "" || get_the_author_meta('last_name') != "") {
                                        echo esc_attr(get_the_author_meta('first_name')) . " " . esc_attr(get_the_author_meta('last_name'));
                                    } else {
                                        echo esc_attr(get_the_author_meta('display_name'));
                                    }?>
                                    </span>
                                </div>
                            <?php } ?>
                            <?php if($blog_show_author == "yes") { ?>
                                <div class="post_info_left_item_holder">
                                    <h5> <?php esc_html_e("Date:","pitchwp"); ?></h5>
                                    <span class="date"><?php the_time(get_option('date_format')); ?></span>
                                </div>
                            <?php
                            }
                            ?>
                            <?php if($blog_show_categories == "yes") { ?>
                                <div class="post_info_left_item_holder">
                                    <h5> <?php esc_html_e("Categories:","pitchwp"); ?></h5>
                                    <?php the_category(', '); ?>
                                </div>
                            <?php
                            }
                            ?>
                            <?php if($blog_show_comments == "yes") { ?>
                                <div class="post_info_left_item_holder">
                                    <h5> <?php esc_html_e("Comments:","pitchwp"); ?></h5>
                                    <?php qode_pitch_post_info(array('comments' => $blog_show_comments)); ?>
                                </div>
                            <?php } ?>
                            <?php if( has_tag()) { ?>
                            <div class="single_tags clearfix">
                                <div class="tags_text">
                                    <h5 class="single_tags_heading"><?php esc_html_e('Tags:', 'pitchwp'); ?></h5>
                                    <div class="single_tags_holder">
                                        <?php the_tags('', ',', ''); ?>
                                    </div>
                                 </div>
                            </div>
                            <?php } ?>
                        </div>
                        <div class="post_info_right">
                            <?php the_content(); ?>
                            <div class="post_info post_info_bottom">
                                <?php qode_pitch_post_info(array('like' => $blog_show_like)) ?>
                                <?php if(isset($qode_pitch_options['blog_single_show_social_share']) && $qode_pitch_options['blog_single_show_social_share'] == "yes" && $blog_social_share_type == "list") { ?>
                                <div class="social_share_list_standard_post_holder">
                                    <i class="fa fa-share"></i>
                                    <span><?php esc_html_e("Share:","pitchwp"); ?></span>
                                    <?php
                                    echo do_shortcode('[no_social_share_list]'); // XSS OK
                                    ?>
                                </div>
                                <?php }; ?>
                                <?php if(isset($qode_pitch_options['blog_single_show_social_share']) && $qode_pitch_options['blog_single_show_social_share'] == "yes" && $blog_social_share_type == "dropdown") {
                                    qode_pitch_post_info(array('share' => $blog_show_social_share));
                                }; ?>
                            </div>
							<?php wp_link_pages($args_pages); ?> 
                            <?php
                            if($blog_show_read_more_button == "yes"){?>
                                <a href="<?php the_permalink(); ?>" target="_self" class="qbutton small read_more_button"><?php esc_html_e("Continue Reading", "pitchwp"); ?></a>
                            <?php } ?>
                        </div>
                    </div>
                </div>
            </div>
        </article>
        <?php
}
?>

