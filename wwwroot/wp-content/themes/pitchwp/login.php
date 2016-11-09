<?php
/*
Template Name: Login
*/
?>

<?php
if ( is_user_logged_in() ) {
	wp_redirect( site_url( '/' ) );
}
?>

<?php
global $wp_query, $qode_pitch_options;
$id = $wp_query->get_queried_object_id();
$sidebar = get_post_meta($id, "qode_show-sidebar", true);

$enable_page_comments = false;
if(get_post_meta($id, "qode_enable-page-comments", true) == 'yes') {
	$enable_page_comments = true;
}

if(get_post_meta($id, "qode_page_background_color", true) != ""){
	$background_color = 'background-color: '.esc_attr(get_post_meta($id, "qode_page_background_color", true));
}else{
	$background_color = "";
}

$content_style = "";
if(get_post_meta($id, "qode_content-top-padding", true) != ""){
	if(get_post_meta($id, "qode_content-top-padding-mobile", true) == 'yes'){
		$content_style = "padding-top:".esc_attr(get_post_meta($id, "qode_content-top-padding", true))."px !important";
	}else{
		$content_style = "padding-top:".esc_attr(get_post_meta($id, "qode_content-top-padding", true))."px";
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

$background_style = '';
if(isset($qode_pitch_options['login_page_image']) && $qode_pitch_options['login_page_image'] !== '' ) {
	$background_style .= 'style=background-image:url('. esc_url($qode_pitch_options['login_page_image']) .')';
}


if ( get_query_var('paged') ) { $paged = get_query_var('paged'); }
elseif ( get_query_var('page') ) { $paged = get_query_var('page'); }
else { $paged = 1; }

?>
<?php get_header(); ?>
	<script>
		<?php if(get_post_meta($id, "qode_page_scroll_amount_for_sticky", true)) { ?>
		page_scroll_amount_for_sticky = <?php echo esc_attr(get_post_meta($id, "qode_page_scroll_amount_for_sticky", true)); ?>;
		<?php }else{ ?>
		page_scroll_amount_for_sticky = undefined
		<?php } ?>
	</script>

<?php get_template_part( 'title' ); ?>
<?php get_template_part('slider'); ?>
	<div class="full_width" <?php qode_pitch_inline_style($background_color); ?>>
		<div class="full_width_inner" <?php qode_pitch_inline_style($content_style); ?>>
			<div class="login_holder" <?php echo esc_attr($background_style); ?>>
				<div class="login_holder_inner">
			<?php if(($sidebar == "default")||($sidebar == "")) : ?>
				<?php if (have_posts()) :
					while (have_posts()) : the_post(); ?>
						<?php if(isset($qode_pitch_options['login_page_title']) && $qode_pitch_options['login_page_title'] != '' ) { ?>
						<div class="login_title_holder">
							<h2 class="login_title"><?php echo esc_attr($qode_pitch_options['login_page_title']); ?></h2>
						</div>
						<?php } ?>
						<?php if(isset($qode_pitch_options['login_page_subtitle']) && $qode_pitch_options['login_page_subtitle'] != '' ) { ?>
						<div class="login_subtitle_holder">
							<h5 class="login_subtitle"><?php echo esc_attr($qode_pitch_options['login_page_subtitle']); ?></h5>
						</div>
						<?php } ?>
						<?php the_content(); ?>
						<div class="loginform_holder">
							<div class="loginform_holder_inner">
								<form name="loginform" id="loginform" action="<?php echo site_url( '/wp-login.php' ) ?>" method="post">
										<span class="form_input_holder">
											<i class="icon-user icons"></i>
											<input type="text" name="log" id="user_login" class="input" value="" size="20" tabindex="10" placeholder="<?php esc_html_e('Username', 'pitchwp') ?>"/>
										</span>
										<span class="form_input_holder">
											<i class="icon-lock icons"></i>
											<input type="password" name="pwd" id="user_pass" class="input" value="" size="20" tabindex="20" placeholder="<?php esc_html_e('Password', 'pitchwp') ?>" />
										</span>
									<p class="submit">
										<input type="submit" name="wp-submit" id="wp-submit" class="button-primary qbutton" value="<?php esc_html_e('Log in', 'pitchwp') ?>" tabindex="100" />
										<input type="hidden" name="redirect_to" value="<?php echo esc_url( home_url( '/' )); ?>/wp-admin/" />
										<input type="hidden" name="testcookie" value="1" />
									</p>
									<p class="forgetmenot">
										<label>
											<input name="rememberme" type="checkbox" id="rememberme" value="forever" tabindex="90" />
											<?php esc_html_e('Remember me', 'pitchwp') ?>
										</label>
									</p>
								</form>
							</div>
						</div>
						<?php
						$args_pages = array(
							'before'           => '<div class="single_links_pages ' .$pagination_classes. '"><div class="single_links_pages_inner">',
							'after'            => '</div></div>',
							'pagelink'         => '<span>%</span>'
						);

						wp_link_pages($args_pages); ?>
						<?php
						if($enable_page_comments){
							?>
							<div class="container">
								<div class="container_inner">
									<?php
									comments_template('', true);
									?>
								</div>
							</div>
							<?php
						}
						?>
					<?php endwhile; ?>
				<?php endif; ?>
			<?php elseif($sidebar == "1" || $sidebar == "2"): ?>

			<?php if($sidebar == "1") : ?>
			<div class="two_columns_66_33 clearfix grid2">
				<div class="column1 content_left_from_sidebar">
					<?php elseif($sidebar == "2") : ?>
					<div class="two_columns_75_25 clearfix grid2">
						<div class="column1 content_left_from_sidebar">
							<?php endif; ?>
							<?php if (have_posts()) :
								while (have_posts()) : the_post(); ?>
									<div class="column_inner">
										<div class="login_title_holder">
											<h2 class="login_title"><?php esc_html_e("Log in to your account","pitchwp"); ?></h2>
										</div>
										<div class="login_subtitle_holder">
											<h5 class="login_subtitle"><?php esc_html_e("Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat","pitchwp"); ?></h5>
										</div>
										<?php the_content(); ?>
										<div class="loginform_holder">
											<div class="loginform_holder_inner">
												<form name="loginform" id="loginform" action="<?php echo site_url( '/wp-login.php' ) ?>" method="post">
												<span class="form_input_holder">
													<i class="icon-user icons"></i>
													<input type="text" name="log" id="user_login" class="input" value="" size="20" tabindex="10" placeholder="<?php esc_html_e('Username', 'pitchwp') ?>"/>
												</span>
												<span class="form_input_holder">
													<i class="icon-lock icons"></i>
													<input type="password" name="pwd" id="user_pass" class="input" value="" size="20" tabindex="20" placeholder="<?php esc_html_e('Password', 'pitchwp') ?>" />
												</span>
													<p class="submit">
														<input type="submit" name="wp-submit" id="wp-submit" class="button-primary qbutton" value="<?php esc_html_e('Log in', 'pitchwp') ?>" tabindex="100" />
														<input type="hidden" name="redirect_to" value="<?php echo esc_url( home_url( '/' )); ?>/wp-admin/" />
														<input type="hidden" name="testcookie" value="1" />
													</p>
													<p class="forgetmenot">
														<label>
															<input name="rememberme" type="checkbox" id="rememberme" value="forever" tabindex="90" />
															<?php esc_html_e('Remember me', 'pitchwp') ?>
														</label>
													</p>
												</form>
											</div>
										</div>
										<?php
										$args_pages = array(
											'before'           => '<div class="single_links_pages ' .$pagination_classes. '"><div class="single_links_pages_inner">',
											'after'            => '</div></div>',
											'pagelink'         => '<span>%</span>'
										);

										wp_link_pages($args_pages); ?>
										<?php
										if($enable_page_comments){
											?>
											<div class="container">
												<div class="container_inner">
													<?php
													comments_template('', true);
													?>
												</div>
											</div>
											<?php
										}
										?>
									</div>
								<?php endwhile; ?>
							<?php endif; ?>


						</div>
						<div class="column2"><?php get_sidebar();?></div>
					</div>
					<?php elseif($sidebar == "3" || $sidebar == "4"): ?>
					<?php if($sidebar == "3") : ?>
					<div class="two_columns_33_66 clearfix grid2">
						<div class="column1"><?php get_sidebar();?></div>
						<div class="column2 content_right_from_sidebar">
							<?php elseif($sidebar == "4") : ?>
							<div class="two_columns_25_75 clearfix grid2">
								<div class="column1"><?php get_sidebar();?></div>
								<div class="column2 content_right_from_sidebar">
									<?php endif; ?>
									<?php if (have_posts()) :
										while (have_posts()) : the_post(); ?>
											<div class="column_inner">
												<div class="login_title_holder">
													<h2 class="login_title"><?php esc_html_e("Log in to your account","pitchwp"); ?></h2>
												</div>
												<div class="login_subtitle_holder">
													<h5 class="login_subtitle"><?php esc_html_e("Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat","pitchwp"); ?></h5>
												</div>
												<?php the_content(); ?>
												<div class="loginform_holder">
													<div class="loginform_holder_inner">
														<form name="loginform" id="loginform" action="<?php echo site_url( '/wp-login.php' ) ?>" method="post">
															<span class="form_input_holder">
																<i class="icon-user icons"></i>
																<input type="text" name="log" id="user_login" class="input" value="" size="20" tabindex="10" placeholder="<?php esc_html_e('Username', 'pitchwp') ?>"/>
															</span>
															<span class="form_input_holder">
																<i class="icon-lock icons"></i>
																<input type="password" name="pwd" id="user_pass" class="input" value="" size="20" tabindex="20" placeholder="<?php esc_html_e('Password', 'pitchwp') ?>" />
															</span>
															<p class="submit">
																<input type="submit" name="wp-submit" id="wp-submit" class="button-primary qbutton" value="<?php esc_html_e('Log in', 'pitchwp') ?>" tabindex="100" />
																<input type="hidden" name="redirect_to" value="<?php echo esc_url( home_url( '/' )); ?>/wp-admin/" />
																<input type="hidden" name="testcookie" value="1" />
															</p>
															<p class="forgetmenot">
																<label>
																	<input name="rememberme" type="checkbox" id="rememberme" value="forever" tabindex="90" />
																	<?php esc_html_e('Remember me', 'pitchwp') ?>
																</label>
															</p>
														</form>
													</div>
												</div>
												<?php
												$args_pages = array(
													'before'           => '<div class="single_links_pages ' .$pagination_classes. '"><div class="single_links_pages_inner">',
													'after'            => '</div></div>',
													'pagelink'         => '<span>%</span>'
												);

												wp_link_pages($args_pages); ?>
												<?php
												if($enable_page_comments){
													?>
													<div class="container">
														<div class="container_inner">
															<?php
															comments_template('', true);
															?>
														</div>
													</div>
													<?php
												}
												?>
											</div>
										<?php endwhile; ?>
									<?php endif; ?>


								</div>

							</div>
							<?php endif; ?>
							</div>
						</div>
					</div>
				</div>
<?php get_footer(); ?>