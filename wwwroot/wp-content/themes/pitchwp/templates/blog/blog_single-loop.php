<?php
global $qode_pitch_options;

$title_tag="h5";
if(isset($qode_pitch_options['blog_single_title_tags'])){
    $title_tag = $qode_pitch_options['blog_single_title_tags'];
}
$headings_array = array('h2', 'h3', 'h4', 'h5', 'h6');
//get correct heading value
$title_tag = (in_array($title_tag, $headings_array)) ? $title_tag : 'h5';

$blog_author_info="no";
if (isset($qode_pitch_options['blog_author_info'])) {
    $blog_author_info = $qode_pitch_options['blog_author_info'];
}
$blog_single_loop = "blog_standard_type";
if (isset($qode_pitch_options['blog_single_style'])&&($qode_pitch_options['blog_single_style'] !== "")) {
    $blog_single_loop = $qode_pitch_options['blog_single_style'];
}

$pagination_classes = '';
if( isset($qode_pitch_options['pagination_type']) && $qode_pitch_options['pagination_type'] == 'standard' ) {
	if( isset($qode_pitch_options['pagination_standard_position']) && $qode_pitch_options['pagination_standard_position'] !== '' ) {
		$pagination_classes .= "standard_".esc_attr($qode_pitch_options['pagination_standard_position']);
	}
}
elseif ( isset($qode_pitch_options['pagination_type']) && $qode_pitch_options['pagination_type'] == 'arrows_on_sides' ) {
	$pagination_classes .= "arrows_on_sides";
}

$author_facebook_page = $author_twitter_page = $author_instagram_page = $author_dribbble_page  = $author_linkedin_page = '';
if(get_the_author_meta('facebook') != ''){
    $author_facebook_page = get_the_author_meta('facebook');
}
if(get_the_author_meta('twitter') != ''){
    $author_twitter_page = get_the_author_meta('twitter');
}
if(get_the_author_meta('instagram') != ''){
    $author_instagram_page = get_the_author_meta('instagram');
}
if(get_the_author_meta('dribbble') != ''){
    $author_dribbble_page = get_the_author_meta('dribbble');
}
if(get_the_author_meta('linkedin') != ''){
    $author_linkedin_page = get_the_author_meta('linkedin');
}

$email = '';
if(get_the_author_meta('email') != ''){
    $email = get_the_author_meta('email');
}

?>
<?php
get_template_part('templates/blog/blog_single/'.$blog_single_loop.'_single', 'loop');
?>

<?php if( has_tag()) { ?>
    <div class="single_tags clearfix">
        <div class="tags_text">
            <<?php echo esc_attr($title_tag);?> class="single_tags_heading"><?php esc_html_e('Tags:', 'pitchwp'); ?></<?php echo esc_attr($title_tag);?>>
            <?php the_tags('', '', ''); ?>
        </div>
    </div>
<?php } ?>
<?php
$args_pages = array(
    'before'           => '<div class="single_links_pages ' .$pagination_classes. '"><div class="single_links_pages_inner">',
    'after'            => '</div></div>',
    'link_before'      => '<span>',
    'link_after'       => '</span>',
    'pagelink'         => '%'
);

wp_link_pages($args_pages);
get_template_part('templates/blog/blog_single/blog-navigation');
?>
<?php if($blog_author_info == "yes") {

    $enable_author_info_email = "no";
    if (isset($qode_pitch_options['enable_author_info_email']) && $qode_pitch_options['enable_author_info_email'] == "yes") {
        $enable_author_info_email = "yes";
    }

    ?>
    <div class="author_description">
        <div class="author_description_inner">
            <div class="image">
                <?php echo qode_pitch_kses_img(qode_pitch_get_gravatar($email, 128, 'mm', 'g', true)); ?>
            </div>
            <div class="author_text_holder">
                <<?php echo esc_attr($title_tag); ?> class="author_name">
                    <?php
                    if(get_the_author_meta('first_name') != "" || get_the_author_meta('last_name') != "") {
                        echo esc_attr(get_the_author_meta('first_name')) . " " . esc_attr(get_the_author_meta('last_name'));
                        ?>
                        <span><?php esc_html_e('About the author', 'pitchwp'); ?></span>
                    <?php
                    } else {
                        echo esc_attr(get_the_author_meta('display_name'));
                    }
                    ?>
                </<?php echo esc_attr($title_tag);?>>
                <?php if($enable_author_info_email == "yes" && is_email(get_the_author_meta('email'))){ ?>
                    <span class="author_email"><?php echo sanitize_email(get_the_author_meta('email')); ?></span>
                <?php } ?>
                <?php if(get_the_author_meta('description') != "") { ?>
                    <div class="author_text">
                        <p><?php echo esc_attr(get_the_author_meta('description')); ?></p>
                    </div>
                <?php } ?>
                <?php if($author_facebook_page != '' || $author_twitter_page !='' || $author_instagram_page !='' || $author_dribbble_page != '' || $author_linkedin_page !=''){ ?>
					<div class ="author_social_holder clearfix">
						<?php if($author_facebook_page != '') { ?>
							<div class="author_social_inner facebook_inner">
								<a href="<?php echo esc_attr($author_facebook_page)?>" target="blank">
									<span class="social_facebook"></span>
								</a>
							</div>
						<?php } ?>
						<?php if($author_twitter_page != '') { ?>
							<div class="author_social_inner twitter_inner">
								<a href="<?php echo esc_attr($author_twitter_page)?>" target="blank">
									<span class="social_twitter"></span>
								</a>
							</div>
						<?php } ?>
						<?php if($author_instagram_page != '') { ?>
							<div class="author_social_inner twitter_inner">
								<a href="<?php echo esc_attr($author_instagram_page)?>" target="blank">
									<span class="social_instagram"></span>
								</a>
							</div>
						<?php } ?>
						<?php if($author_dribbble_page != '') { ?>
							<div class="author_social_inner twitter_inner">
								<a href="<?php echo esc_attr($author_dribbble_page)?>" target="blank">
									<span class="social_dribbble"></span>
								</a>
							</div>
						<?php } ?>
						<?php if($author_linkedin_page != '') { ?>
							<div class="author_social_inner twitter_inner">
								<a href="<?php echo esc_attr($author_linkedin_page)?>" target="blank">
									<span class="social_linkedin"></span>
								</a>
							</div>
						<?php } ?>
					</div>
				<?php } ?>
            </div>
        </div>
    </div>
<?php } ?>