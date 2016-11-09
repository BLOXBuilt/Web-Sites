<?php
namespace QodeCore\CPT\Carousels;

use QodeCore\Lib;

/**
 * Class CarouselRegister
 * @package QodeCore\CPT\Carousels
 */
class CarouselRegister implements Lib\PostTypeInterface {
    /**
     * @var string
     */
    private $base;
    /**
     * @var string
     */
    private $taxBase;

    public function __construct() {
        $this->base = 'carousels';
        $this->taxBase = 'carousels_category';
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
            $menuPosition = $qode_pitch_Framework->getSkin()->getMenuItemPosition('carousel');
            $menuIcon = $qode_pitch_Framework->getSkin()->getMenuIcon('carousel');
        }

        register_post_type($this->base,
            array(
                'labels'    => array(
                    'name'        => esc_html__('Select Carousel','qode_core' ),
                    'menu_name' => esc_html__('Select Carousel','qode_core' ),
                    'all_items' => esc_html__('Carousel Items','qode_core' ),
                    'add_new' =>  esc_html__('Add New Carousel Item','qode_core'),
                    'singular_name'   => esc_html__('Carousel Item','qode_core' ),
                    'add_item'      => esc_html__('New Carousel Item','qode_core'),
                    'add_new_item'    => esc_html__('Add New Carousel Item','qode_core'),
                    'edit_item'     => esc_html__('Edit Carousel Item','qode_core')
                ),
                'public'    =>  false,
                'show_in_menu'  =>  true,
                'rewrite'     =>  array('slug' => 'carousels'),
                'menu_position' =>  $menuPosition,
                'show_ui'   =>  true,
                'has_archive' =>  false,
                'hierarchical'  =>  false,
                'supports'    =>  array('title'),
                'menu_icon'  =>  $menuIcon
            )
        );
    }

    /**
     * Registers custom taxonomy with WordPress
     */
    private function registerTax() {
        $labels = array(
            'name' => esc_html__( 'Carousels', 'taxonomy general name' ),
            'singular_name' => esc_html__( 'Carousel', 'taxonomy singular name' ),
            'search_items' =>  esc_html__( 'Search Carousels','qode_core' ),
            'all_items' => esc_html__( 'All Carousels','qode_core' ),
            'parent_item' => esc_html__( 'Parent Carousel','qode_core' ),
            'parent_item_colon' => esc_html__( 'Parent Carousel:','qode_core' ),
            'edit_item' => esc_html__( 'Edit Carousel','qode_core' ),
            'update_item' => esc_html__( 'Update Carousel','qode_core' ),
            'add_new_item' => esc_html__( 'Add New Carousel','qode_core' ),
            'new_item_name' => esc_html__( 'New Carousel Name','qode_core' ),
            'menu_name' => esc_html__( 'Carousels','qode_core' ),
        );

        register_taxonomy($this->taxBase, array($this->base), array(
            'hierarchical' => true,
            'labels' => $labels,
            'show_ui' => true,
            'query_var' => true,
            'show_admin_column' => true,
            'rewrite' => array( 'slug' => 'carousels-category' ),
        ));
    }

}