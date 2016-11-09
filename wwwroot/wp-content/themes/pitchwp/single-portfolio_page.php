<?php

//init variables
$id 				= get_the_ID();
$portfolio_template = 'floating-right';

//is portfolio template set for current portfolio?
if(get_post_meta(get_the_ID(), "qode_choose-portfolio-single-view", true) != "") {
	$portfolio_template = get_post_meta(get_the_ID(), "qode_choose-portfolio-single-view", true);
} elseif($qode_pitch_options['portfolio_style'] !== '') {
	//get default portfolio template if set in theme's options
	$portfolio_template = $qode_pitch_options['portfolio_style'];
}
?>

<?php get_header(); ?>
	<?php if (have_posts()) : ?>
		<?php while (have_posts()) : the_post(); ?>
			<script>
				<?php if(get_post_meta($id, "qode_page_scroll_amount_for_sticky", true)) { ?>
				page_scroll_amount_for_sticky = <?php echo esc_attr(get_post_meta($id, "qode_page_scroll_amount_for_sticky", true)); ?>;
				<?php }else{ ?>
				page_scroll_amount_for_sticky = undefined
				<?php } ?>
			</script>

			<?php get_template_part( 'title' ); ?>
			<?php get_template_part('slider'); ?>

			<?php

				//load general portfolio structure which will load proper template
				get_template_part('templates/portfolio/portfolio-structure');
			
			?>
		<?php endwhile; ?>
	<?php endif; ?>	
<?php get_footer(); ?>	