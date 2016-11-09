<?php
global $qode_pitch_options;

$enable_navigation = true;
if (isset($qode_pitch_options['portfolio_hide_pagination']) && $qode_pitch_options['portfolio_hide_pagination'] == "yes"){
    $enable_navigation = false;
}

$navigation_through_category = false;
if (isset($qode_pitch_options['portfolio_navigation_through_same_category']) && $qode_pitch_options['portfolio_navigation_through_same_category'] == "yes")
    $navigation_through_category = true;
?>

<?php

$icon_navigation_class = "fa fa-chevron-";

$direction_nav_classes = qode_pitch_horizontal_slider_icon_classes($icon_navigation_class);


$back_to_button_code = '<i class="fa fa-th"></i>';

?>

<?php if($enable_navigation){ ?>
    <div class="portfolio_navigation">
        <div class="portfolio_navigation_inner">
            <?php if(get_previous_post() != ""){ ?>
                <div class="portfolio_prev">
                    <?php
					$prevPost = get_previous_post();
					$prevThumbnail = get_the_post_thumbnail( $prevPost->ID, array(130,130)); 
                    if($navigation_through_category){
                        previous_post_link('%link','<span class="nav_arrow"><span class="' .$direction_nav_classes['left_icon_class']. '"></span></span><span class="thumb">'.$prevThumbnail.'</span>', true,'','portfolio_category');
                    } else {
                        previous_post_link('%link','<span class="nav_arrow"><span class="' .$direction_nav_classes['left_icon_class']. '"></span></span><span class="thumb">'.$prevThumbnail.'</span>');
                    }
					
                    ?>
                </div> <!-- close div.portfolio_prev -->
            <?php } ?>
            <?php if(get_post_meta(get_the_ID(), "qode_choose-portfolio-list-page", true) != "") { ?>
                <div class="portfolio_button">
                    <a href="<?php echo esc_url(get_permalink(get_post_meta(get_the_ID(), "qode_choose-portfolio-list-page", true))); ?>"><?php echo wp_kses($back_to_button_code,array(
                        'span' => array("class" => true),
                        'i' => array("class"=> true)
                    ));?></a>
                </div> <!-- close div.portfolio_button -->
            <?php } ?>
            <?php if(get_next_post() != ""){ ?>
                <div class="portfolio_next">
                    <?php
					$nextPost = get_next_post();
					$nextThumbnail = get_the_post_thumbnail( $nextPost->ID, array(130,130));
                    if($navigation_through_category){
                        next_post_link('%link','<span class="thumb">'.$nextThumbnail.'</span><span class="nav_arrow"><span class="' .$direction_nav_classes['right_icon_class']. '"></span></span>', true,'','portfolio_category');
                    } else {
                        next_post_link('%link','<span class="thumb">'.$nextThumbnail.'</span><span class="nav_arrow"><span class="' .$direction_nav_classes['right_icon_class']. '"></span></span>');
                    }
                    ?>
                </div> <!-- close div.portfolio_next -->
            <?php } ?>
        </div>
    </div> <!-- close div.portfolio_navigation -->
<?php } ?>	