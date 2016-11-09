<?php
global $qode_pitch_options;
global $wp_query;

$enable_related_projects = true;
if (isset($qode_pitch_options['portfolio_related_projects']) && $qode_pitch_options['portfolio_related_projects'] == "no"){
    $enable_related_projects = false;
}

$id = $wp_query->get_queried_object_id();
$portfolio_categories = wp_get_post_terms($id,'portfolio_category');

if($enable_related_projects) {

    if(is_array($portfolio_categories) && count($portfolio_categories)) {
        $portfolio_categories_array = array();
        foreach($portfolio_categories as $portfolio_category) {
            $portfolio_categories_array[] = $portfolio_category->slug;
        }
        $args = array(
            'post_type' => 'portfolio_page',
            'posts_per_page' => -1,
            'post__not_in' => array($id),
            'tax_query' => array(
                array(
                    'taxonomy' => 'portfolio_category',
                    'field' => 'slug',
                    'terms' => $portfolio_categories_array
                )
            )
        );

        $my_query = new WP_Query( $args );

        if( $my_query->have_posts() ) { ?>
            <div class="portfolio_related_projects_holder">
                <div class="portfolio_related_projects_title">
                    <p><?php esc_html_e("Related Projects:","pitchwp"); ?></p>
                </div>
                <div class="portfolio_related_projects">
                    <ul class="related_projects">
        <?php
            while ($my_query->have_posts()) : $my_query->the_post(); ?>
                    <?php $image_html = get_the_post_thumbnail(get_the_ID(), 'qode-pitch-portfolio-related'); ?>
                    <li class="projects">
                        <div class="projects_holder">
                            <?php if ( has_post_thumbnail() ) { ?>
                            <a href="<?php the_permalink(); ?>" title="<?php the_title_attribute(); ?>">
                                <div class="project_image">
                                    <span class="image">
                                        <?php echo wp_kses($image_html, array(
                                            'img' => array(
                                                'src' => true,
                                                'alt' => true,
                                                'width' => true,
                                                'height' => true,
                                                'draggable' => true
                                            )
                                        )); ?>
                                    </span>
                                    <span class="project_overlay_holder">
                                        <span class="project_overlay_outer">
                                            <span class="project_overlay_inner">
                                                <i class="fa fa-plus"></i>
								            </span>
                                        </span>
                                    </span>
                                </div>
                                <?php } ?>
                            </a>
                        </div>
                    </li>
        <?php
            endwhile;
        ?>
                    </ul>
                    <?php
                    $icon_navigation_class = 'arrow_carrot-';
                    if (isset($qode_pitch_options['carousel_navigation_arrows_type']) && $qode_pitch_options['carousel_navigation_arrows_type'] != '') {
                        $icon_navigation_class = $qode_pitch_options['carousel_navigation_arrows_type'];
                    }

                    $direction_nav_classes = qode_pitch_horizontal_slider_icon_classes($icon_navigation_class);
                    $random_number = rand(); ?>

                    <ul class="caroufredsel-direction-nav">
                        <li>
                            <a id="caroufredsel-prev-<?php echo esc_attr($random_number); ?>" class="caroufredsel-prev" href="#">
                                <span class="<?php echo esc_attr($direction_nav_classes['left_icon_class']);?>"></span>
                            </a>
                        </li>
                        <li>
                            <a class="caroufredsel-next" id="caroufredsel-next-<?php echo esc_attr($random_number); ?>" href="#">
                                <span class="<?php echo esc_attr($direction_nav_classes['right_icon_class']);?>"></span>
                            </a>
                        </li>
                    </ul>
                </div>
            </div>
        <?php
        }
        else { ?>
            <div class="portfolio_related_projects_holder no_related">
                <div class="portfolio_related_projects_title">
                    <p><?php esc_html_e('No related posts found', 'pitchwp'); ?></p>
                </div>
            </div>
            <?php
        }
    }
    else { ?>
        <div class="portfolio_related_projects_holder no_related">
            <div class="portfolio_related_projects_title">
                <p><?php esc_html_e('No related posts found', 'pitchwp'); ?></p>
            </div>
        </div>
<?php
    }
}
wp_reset_postdata();
?>