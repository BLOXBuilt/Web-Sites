<?php
global $qode_pitch_options;
global $more;
$more = 0;


$blog_show_categories = "no";
if (isset($qode_pitch_options['blog_masonry_show_categories'])){
	$blog_show_categories = $qode_pitch_options['blog_masonry_show_categories'];
}
$blog_show_comments = "no";
if (isset($qode_pitch_options['blog_masonry_show_comments'])){
	$blog_show_comments = $qode_pitch_options['blog_masonry_show_comments'];
}

$blog_show_author = "no";
if (isset($qode_pitch_options['blog_masonry_show_author'])){
	$blog_show_author = $qode_pitch_options['blog_masonry_show_author'];
}
$blog_show_like = "no";
if (isset($qode_pitch_options['blog_masonry_show_like'])) {
	$blog_show_like = $qode_pitch_options['blog_masonry_show_like'];
}
$blog_show_ql_icon_mark = "yes";
$blog_title_holder_icon_class = "";
if (isset($qode_pitch_options['blog_masonry_show_ql_mark'])) {
	$blog_show_ql_icon_mark = $qode_pitch_options['blog_masonry_show_ql_mark'];
}

if ($blog_show_ql_icon_mark == "yes") {
	$blog_title_holder_icon_class = " with_icon";
}

$blog_show_date = "no";
if (isset($qode_pitch_options['blog_masonry_show_date'])) {
	$blog_show_date = $qode_pitch_options['blog_masonry_show_date'];
}

$blog_show_read_more_button = "no";
if (isset($qode_pitch_options['blog_masonry_read_more_button'])) {
	$blog_show_read_more_button = $qode_pitch_options['blog_masonry_read_more_button'];
}

$blog_social_share_type = "dropdown";
if(isset($qode_pitch_options['blog_masonry_select_share_options_masonry_type'])){
	$blog_social_share_type = $qode_pitch_options['blog_masonry_select_share_options_masonry_type'];
}
$blog_show_social_share = "no";
if (isset($qode_pitch_options['enable_social_share'])&& $qode_pitch_options['enable_social_share'] =="yes"){
	if (isset($qode_pitch_options['post_types_names_post'])&& $qode_pitch_options['post_types_names_post'] =="post"){
		if (isset($qode_pitch_options['blog_masonry_show_share'])&& $blog_social_share_type == "dropdown") {
					$blog_show_social_share = $qode_pitch_options['blog_masonry_show_share'];
		}
	}
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

$blog_read_more_button_classes = '';
if (isset($qode_pitch_options['blog_masonry_read_more_button_icon']) && $qode_pitch_options['blog_masonry_read_more_button_icon'] == 'yes'){
    $blog_read_more_button_classes .= 'with_icon';
}

$_post_format = get_post_format();

$blog_masonry_type = "post_info_below_title";
if(isset($qode_pitch_options['blog_masonry_type'])){
	$blog_masonry_type = $qode_pitch_options['blog_masonry_type'];
}

$blog_ql_background_image = "no";
if(isset($qode_pitch_options['blog_masonry_ql_background_image'])){
	$blog_ql_background_image = $qode_pitch_options['blog_masonry_ql_background_image'];
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
			<div class="post_image">
				<?php get_template_part('templates/blog/parts/post-format-video'); ?>
			</div>
			<div class="post_text">
				<div class="post_text_inner">
					<?php if($blog_masonry_type == "post_info_below_title"){
						if($blog_show_date == "yes" || $blog_show_categories == "yes" || $blog_show_author == "yes" || $blog_show_comments == "yes" || $blog_show_like == "yes") { ?>
							<div class="post_info post_info_top">
								<?php qode_pitch_post_info(array('date' => $blog_show_date, 'category' => $blog_show_categories, 'author' => $blog_show_author, 'comments' => $blog_show_comments, 'like' => $blog_show_like)) ?>
							</div>
					<?php }} ?>
					<h4>
						<a href="<?php the_permalink(); ?>" target="_self" title="<?php the_title_attribute(); ?>"><?php the_title(); ?></a>
					</h4>
					<?php
						qode_pitch_excerpt();
						wp_link_pages($args_pages);
						if($blog_show_read_more_button == "yes"){?>
							<a href="<?php the_permalink(); ?>" target="_self" class="qbutton small read_more_button"><?php esc_html_e('Read More','pitchwp'); ?></a>
						<?php }
						if(isset($qode_pitch_options['blog_masonry_show_share']) && $qode_pitch_options['blog_masonry_show_share'] == "yes" && $blog_social_share_type == "list") {
							echo do_shortcode('[no_social_share_list]'); // XSS OK
						}
					?>

					<?php if($blog_masonry_type == "post_info_at_bottom"){ 
						if($blog_show_author == "yes" || $blog_show_date == "yes" || $blog_show_social_share == "yes" || $blog_show_categories == "yes" || $blog_show_comments == "yes" || $blog_show_like == "yes") { ?>
							<div class="post_info post_info_bottom">
								<?php qode_pitch_post_info(array('date' => $blog_show_date, 'author' => $blog_show_author, 'share' => $blog_show_social_share, 'category' => $blog_show_categories, 'comments' => $blog_show_comments, 'like' => $blog_show_like)); ?>
							</div>
					<?php }} ?>
				</div>
			</div>
		</article>

		<?php
		break;
	case "audio":
		?>
		<article id="post-<?php the_ID(); ?>" <?php post_class(); ?>>
			<div class="post_content_holder">
				<?php if ( has_post_thumbnail() ) { ?>
					<div class="post_image">
						<a href="<?php the_permalink(); ?>" title="<?php the_title_attribute(); ?>">
							<?php the_post_thumbnail('full'); ?>
						</a>
					</div>
				<?php } ?>
				<div class="audio_image">
					<audio class="blog_audio" src="<?php echo esc_url(get_post_meta(get_the_ID(), "audio_link", true)) ?>" controls="controls">
						<?php esc_html_e("Your browser don't support audio player","pitchwp"); ?>
					</audio>
				</div>
				<div class="post_text">
					<div class="post_text_inner">
						<?php if($blog_masonry_type == "post_info_below_title"){
							if($blog_show_date == "yes" || $blog_show_categories == "yes" || $blog_show_author == "yes" || $blog_show_comments == "yes" || $blog_show_like == "yes") { ?>
								<div class="post_info post_info_top">
									<?php qode_pitch_post_info(array('date' => $blog_show_date, 'category' => $blog_show_categories, 'author' => $blog_show_author, 'comments' => $blog_show_comments, 'like' => $blog_show_like)) ?>
								</div>
						<?php }} ?>
						<h4>
							<a href="<?php the_permalink(); ?>" target="_self" title="<?php the_title_attribute(); ?>"><?php the_title(); ?></a>
						</h4>
						<?php
							qode_pitch_excerpt();
							wp_link_pages($args_pages);
							if($blog_show_read_more_button == "yes"){?>
								<a href="<?php the_permalink(); ?>" target="_self" class="qbutton small read_more_button"><?php esc_html_e('Read More','pitchwp'); ?></a>
							<?php }
							if(isset($qode_pitch_options['blog_masonry_show_share']) && $qode_pitch_options['blog_masonry_show_share'] == "yes" && $blog_social_share_type == "list") {
								echo do_shortcode('[no_social_share_list]'); // XSS OK
							}
						?>

						<?php if($blog_masonry_type == "post_info_at_bottom"){
							if($blog_show_author == "yes" || $blog_show_date == "yes" || $blog_show_social_share == "yes" || $blog_show_categories == "yes" || $blog_show_comments == "yes" || $blog_show_like == "yes") { ?>
							<div class="post_info post_info_bottom">
								<?php qode_pitch_post_info(array('date' => $blog_show_date, 'author' => $blog_show_author, 'share' => $blog_show_social_share, 'category' => $blog_show_categories, 'comments' => $blog_show_comments, 'like' => $blog_show_like)); ?>
							</div>
						<?php }} ?>
					</div>
				</div>
		</article>
		<?php
		break;
	case "link":
		?>
		<article id="post-<?php the_ID(); ?>" <?php post_class(); ?>>
			<div class="post_content_holder">
				<div class="post_text  <?php if($blog_ql_background_image == "yes") { if ( has_post_thumbnail() ) { ?> link_image" style="background:url(<?php  echo wp_get_attachment_url(get_post_thumbnail_id()); ?>); <?php }} ?>">
					<div class="post_text_inner">
						<?php if($blog_show_date == "yes" || $blog_show_categories == "yes" || $blog_show_author == "yes" || $blog_show_comments == "yes" || $blog_show_like == "yes") { ?>
							<div class="post_info post_info_top">
								<?php qode_pitch_post_info(array('date' => $blog_show_date, 'category' => $blog_show_categories, 'author' => $blog_show_author, 'comments' => $blog_show_comments, 'like' => $blog_show_like)) ?>
							</div>
						<?php } ?>
						<div class="post_title<?php echo esc_attr($blog_title_holder_icon_class); ?>">
							<h3><a href="<?php the_permalink(); ?>" title="<?php the_title_attribute(); ?>"><?php the_title(); ?></a></h3>
						</div>
						<?php wp_link_pages($args_pages); ?> 
					</div>
				</div>
			</div>
		</article>
		<?php
		break;
	case "gallery":
		?>
		<article id="post-<?php the_ID(); ?>" <?php post_class(); ?>>
			<div class="post_image">
				<?php get_template_part('templates/blog/parts/post-format-gallery-slider'); ?>
			</div>
			<div class="post_text">
				<div class="post_text_inner">
					<?php if($blog_masonry_type == "post_info_below_title"){
						if($blog_show_date == "yes" || $blog_show_categories == "yes" || $blog_show_author == "yes" || $blog_show_comments == "yes" || $blog_show_like == "yes") { ?>
							<div class="post_info post_info_top">
								<?php qode_pitch_post_info(array('date' => $blog_show_date, 'category' => $blog_show_categories, 'author' => $blog_show_author, 'comments' => $blog_show_comments, 'like' => $blog_show_like)) ?>
							</div>
					<?php }} ?>
					<h4>
						<a href="<?php the_permalink(); ?>" target="_self" title="<?php the_title_attribute(); ?>"><?php the_title(); ?></a>
					</h4>
					<?php
						qode_pitch_excerpt();
						wp_link_pages($args_pages);
					if($blog_show_read_more_button == "yes"){?>
						<a href="<?php the_permalink(); ?>" target="_self" class="qbutton small read_more_button"><?php esc_html_e('Read More','pitchwp'); ?></a>
					<?php }
						if(isset($qode_pitch_options['blog_masonry_show_share']) && $qode_pitch_options['blog_masonry_show_share'] == "yes" && $blog_social_share_type == "list") {
							echo do_shortcode('[no_social_share_list]'); // XSS OK
						}
					?>

					<?php if($blog_masonry_type == "post_info_at_bottom"){ ?>
						<?php if($blog_show_author == "yes" || $blog_show_date == "yes" || $blog_show_social_share == "yes" || $blog_show_categories == "yes" || $blog_show_comments == "yes" || $blog_show_like == "yes") { ?>	
							<div class="post_info post_info_bottom">
								<?php qode_pitch_post_info(array('date' => $blog_show_date, 'author' => $blog_show_author, 'share' => $blog_show_social_share, 'category' => $blog_show_categories, 'comments' => $blog_show_comments, 'like' => $blog_show_like)); ?>
							</div>
					<?php }} ?>
				</div>
			</div>
		</article>
		<?php
		break;
	case "quote":
		?>
		<article id="post-<?php the_ID(); ?>" <?php post_class(); ?>>
			<div class="post_content_holder">
				<div class="post_text  <?php if($blog_ql_background_image == "yes") { if ( has_post_thumbnail() ) { ?> quote_image" style="background:url(<?php  echo wp_get_attachment_url(get_post_thumbnail_id()); ?>);<?php }} ?>">
					<div class="post_text_inner">
						<?php if($blog_show_date == "yes" || $blog_show_categories == "yes" || $blog_show_author == "yes" || $blog_show_comments == "yes" || $blog_show_like == "yes") { ?>
							<div class="post_info post_info_top">
								<?php qode_pitch_post_info(array('date' => $blog_show_date, 'category' => $blog_show_categories, 'author' => $blog_show_author, 'comments' => $blog_show_comments, 'like' => $blog_show_like)) ?>
							</div>
						<?php } ?>
						<div class="post_title<?php echo esc_attr($blog_title_holder_icon_class); ?>">
							<h3><a href="<?php the_permalink(); ?>" title="<?php the_title_attribute(); ?>">
									<?php echo esc_html(get_post_meta(get_the_ID(), "quote_format", true)); ?>
								</a>
							</h3>
							<span class="quote_author">&ndash; <?php the_title(); ?></span>
						</div>
						<?php wp_link_pages($args_pages); ?> 
					</div>
				</div>
			</div>
		</article>
		<?php
		break;
	default:
		?>
			<article id="post-<?php the_ID(); ?>" <?php post_class(); ?>>
				<?php if ( has_post_thumbnail() ) { ?>
					<div class="post_image">
						<a href="<?php the_permalink(); ?>" target="_self" title="<?php the_title_attribute(); ?>">
							<?php the_post_thumbnail('full'); ?>
						</a>
					</div>
				<?php } ?>
				<div class="post_text">
					<div class="post_text_inner">
						<?php if($blog_masonry_type == "post_info_below_title"){
						  if($blog_show_date == "yes" || $blog_show_categories == "yes" || $blog_show_author == "yes" || $blog_show_comments == "yes" || $blog_show_like == "yes") { ?>
							<div class="post_info post_info_top">
								<?php qode_pitch_post_info(array('date' => $blog_show_date, 'category' => $blog_show_categories, 'author' => $blog_show_author, 'comments' => $blog_show_comments, 'like' => $blog_show_like)) ?>
							</div>
						<?php }} ?>
						<h4>
							<a href="<?php the_permalink(); ?>" target="_self" title="<?php the_title_attribute(); ?>"><?php the_title(); ?></a>
						</h4>
						<?php
							qode_pitch_excerpt();
							wp_link_pages($args_pages);
							if($blog_show_read_more_button == "yes"){?>
								<a href="<?php the_permalink(); ?>" target="_self" class="qbutton small read_more_button"><?php esc_html_e('Read More','pitchwp'); ?></a>
							<?php }
							if(isset($qode_pitch_options['blog_masonry_show_share']) && $qode_pitch_options['blog_masonry_show_share'] == "yes" && $blog_social_share_type == "list") {
								echo do_shortcode('[no_social_share_list]'); // XSS OK
							}
						?>
													
						<?php if($blog_masonry_type == "post_info_at_bottom"){ 
							if($blog_show_author == "yes" || $blog_show_date == "yes" || $blog_show_social_share == "yes" || $blog_show_categories == "yes" || $blog_show_comments == "yes" || $blog_show_like == "yes") { ?>	
								<div class="post_info post_info_bottom">
									<?php qode_pitch_post_info(array('date' => $blog_show_date, 'author' => $blog_show_author, 'share' => $blog_show_social_share, 'category' => $blog_show_categories, 'comments' => $blog_show_comments, 'like' => $blog_show_like)); ?>
								</div>
						<?php }} ?>
					</div>
				</div>
			</article>
		<?php
}
?>

