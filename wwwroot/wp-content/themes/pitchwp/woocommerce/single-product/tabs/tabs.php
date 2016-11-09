<?php
/**
 * Single Product tabs
 *
 * This template can be overridden by copying it to yourtheme/woocommerce/single-product/tabs/tabs.php.
 *
 * HOWEVER, on occasion WooCommerce will need to update template files and you
 * (the theme developer) will need to copy the new files to your theme to
 * maintain compatibility. We try to do this as little as possible, but it does
 * happen. When this occurs the version of the template file will be bumped and
 * the readme will list any important changes.
 *
 * @see 	https://docs.woothemes.com/document/template-structure/
 * @author  WooThemes
 * @package WooCommerce/Templates
 * @version 2.4.0
 */

if ( ! defined( 'ABSPATH' ) ) exit; // Exit if accessed directly

global $qode_pitch_options;

/**
 * Filter tabs and allow third parties to add their own
 *
 * Each tab is an array containing title, callback and priority.
 * @see woocommerce_default_product_tabs()
 */
$tabs = apply_filters( 'woocommerce_product_tabs', array() );


	

if ( ! empty( $tabs ) ) : ?>

    <?php if(isset($qode_pitch_options['woo_products_info_style']) && ($qode_pitch_options['woo_products_info_style'])=="vertical_tabs"){?>
		<div class="q_tabs horizontal tab_with_text left default woocommerce-tabs">
			<ul class="tabs clearfix tabs-nav">
				<?php foreach ( $tabs as $key => $tab ) : ?>

					<li class="<?php echo esc_attr($key); ?>_tab">
						<a href="#tab-<?php echo esc_attr($key); ?>"><?php echo apply_filters( 'woocommerce_product_' . $key . '_tab_title', $tab['title'], $key ) ?></a>
					</li>

				<?php endforeach; ?>
			</ul>
			<?php foreach ( $tabs as $key => $tab ) : ?>

				<div class="panel entry-content tabs-container" id="tab-<?php echo esc_attr($key); ?>">
					<?php call_user_func( $tab['callback'], $key, $tab ) ?>
				</div>

			<?php endforeach; ?>
		</div>
	<?php }  else {?>
		<div class="q_accordion_holder toggle boxed woocommerce-accordion <?php if(isset($qode_pitch_options['accordion_toggle_boxed_background_pattern']) && $qode_pitch_options['accordion_toggle_boxed_background_pattern']!='no'){ echo "has_pattern";} ?>">
			<?php foreach ( $tabs as $key => $tab ) : ?>

				<h6 class="title-holder clearfix <?php echo esc_attr($key); ?>_tab">
					<span class="tab-title"><?php echo apply_filters( 'woocommerce_product_' . $key . '_tab_title', $tab['title'], $key ) ?></span>
				</h6>
				<div class="accordion_content">
					<div class="accordion_content_inner">
						<?php call_user_func( $tab['callback'], $key, $tab ) ?>
					</div>
				</div>

			<?php endforeach; ?>
		</div>
	<?php } ?>

<?php endif; ?>