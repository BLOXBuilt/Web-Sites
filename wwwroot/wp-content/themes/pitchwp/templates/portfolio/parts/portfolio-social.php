<?php
global $qode_pitch_options;
?>

<?php if(isset($qode_pitch_options['enable_social_share'])  && $qode_pitch_options['enable_social_share'] == "yes") { ?>
	<div class="portfolio_social_holder">
		<?php echo do_shortcode('[no_social_share_list]'); // XSS OK ?>
	</div> <!-- close div.portfolio_social_holder -->
<?php } ?>