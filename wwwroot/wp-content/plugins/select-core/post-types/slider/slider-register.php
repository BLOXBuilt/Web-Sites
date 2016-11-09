<?php
namespace QodeCore\CPT\Slider;

use QodeCore\Lib;

/**
 * Class SliderRegister
 * @package QodeCore\CPT\Slider
 */
class SliderRegister implements Lib\PostTypeInterface {
    /**
     * @var string
     */
    private $base;

    public function __construct() {
        $this->base = 'slides';
        $this->taxBase = 'slides_category';
    }

    /**
     * @return string
     */
    public function getBase() {
        return $this->base;
    }

    /**
     * Registers custom post type with WordPress
     */
    public function register() {
        $this->registerPostType();
        $this->registerTax();
    }

    /**
     * Registers custom post type with WordPress
     */
    private function registerPostType() {
        global $qode_pitch_Framework;

        $menuPosition = 5;
        $menuIcon = 'dashicons-admin-post';

        if(qode_pitch_core_theme_installed()) {
            $menuPosition = $qode_pitch_Framework->getSkin()->getMenuItemPosition('slider');
            $menuIcon = $qode_pitch_Framework->getSkin()->getMenuIcon('slider');
        }

        register_post_type($this->base,
            array(
                'labels' 		=> array(
                    'name' 				=> esc_html__('Select Slider','qode_core' ),
                    'menu_name'	=> esc_html__('Select Slider','qode_core' ),
                    'all_items'	=> esc_html__('Slides','qode_core' ),
                    'add_new' =>  esc_html__('Add New Slide','qode_core'),
                    'singular_name' 	=> esc_html__('Slide','qode_core' ),
                    'add_item'			=> esc_html__('New Slide','qode_core'),
                    'add_new_item' 		=> esc_html__('Add New Slide','qode_core'),
                    'edit_item' 		=> esc_html__('Edit Slide','qode_core')
                ),
                'public'		=>	false,
                'show_in_menu'	=>	true,
                'rewrite' 		=> 	array('slug' => 'slides'),
                'menu_position' => 	$menuPosition,
                'show_ui'		=>	true,
                'has_archive'	=>	false,
                'hierarchical'	=>	false,
                'supports'		=>	array('title', 'thumbnail', 'page-attributes'),
                'menu_icon'  =>  $menuIcon
            )
        );
    }

    /**
     * Registers custom taxonomy with WordPress
     */
    private function registerTax() {
        $labels = array(
            'name' => esc_html__( 'Sliders', 'taxonomy general name' ),
            'singular_name' => esc_html__( 'Slider', 'taxonomy singular name' ),
            'search_items' =>  esc_html__( 'Search Sliders','qode_core' ),
            'all_items' => esc_html__( 'All Sliders','qode_core' ),
            'parent_item' => esc_html__( 'Parent Slider','qode_core' ),
            'parent_item_colon' => esc_html__( 'Parent Slider:','qode_core' ),
            'edit_item' => esc_html__( 'Edit Slider','qode_core' ),
            'update_item' => esc_html__( 'Update Slider','qode_core' ),
            'add_new_item' => esc_html__( 'Add New Slider','qode_core' ),
            'new_item_name' => esc_html__( 'New Slider Name','qode_core' ),
            'menu_name' => esc_html__( 'Sliders','qode_core' ),
        );

        register_taxonomy($this->taxBase, array($this->base), array(
            'hierarchical' => true,
            'labels' => $labels,
            'show_ui' => true,
            'query_var' => true,
            'show_admin_column' => true,
            'rewrite' => array( 'slug' => 'slides-category' ),
        ));
    }
}