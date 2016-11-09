<?php
namespace QodeCore\CPT\Testimonials;

use QodeCore\Lib;


/**
 * Class TestimonialsRegister
 * @package QodeCore\CPT\Testimonials
 */
class TestimonialsRegister implements Lib\PostTypeInterface {
    /**
     * @var string
     */
    private $base;

    public function __construct() {
        $this->base = 'testimonials';
        $this->taxBase = 'testimonials_category';
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
     * Regsiters custom post type with WordPress
     */
    private function registerPostType() {
        global $qode_pitch_Framework;

        $menuPosition = 5;
        $menuIcon = 'dashicons-admin-post';

        if(qode_pitch_core_theme_installed()) {
            $menuPosition = $qode_pitch_Framework->getSkin()->getMenuItemPosition('testimonial');
            $menuIcon = $qode_pitch_Framework->getSkin()->getMenuIcon('testimonial');
        }

        register_post_type('testimonials',
            array(
                'labels' 		=> array(
                    'name' 				=> esc_html__('Testimonials','qode_core' ),
                    'singular_name' 	=> esc_html__('Testimonial','qode_core' ),
                    'add_item'			=> esc_html__('New Testimonial','qode_core'),
                    'add_new_item' 		=> esc_html__('Add New Testimonial','qode_core'),
                    'edit_item' 		=> esc_html__('Edit Testimonial','qode_core')
                ),
                'public'		=>	false,
                'show_in_menu'	=>	true,
                'rewrite' 		=> 	array('slug' => 'testimonials'),
                'menu_position' => 	$menuPosition,
                'show_ui'		=>	true,
                'has_archive'	=>	false,
                'hierarchical'	=>	false,
                'supports'		=>	array('title', 'thumbnail'),
                'menu_icon'  =>  $menuIcon
            )
        );
    }

    /**
     * Registers custom taxonomy with WordPress
     */
    private function registerTax() {
        $labels = array(
            'name' => esc_html__( 'Testimonials Categories', 'taxonomy general name' ),
            'singular_name' => esc_html__( 'Testimonial Category', 'taxonomy singular name' ),
            'search_items' =>  esc_html__( 'Search Testimonials Categories','qode_core' ),
            'all_items' => esc_html__( 'All Testimonials Categories','qode_core' ),
            'parent_item' => esc_html__( 'Parent Testimonial Category','qode_core' ),
            'parent_item_colon' => esc_html__( 'Parent Testimonial Category:','qode_core' ),
            'edit_item' => esc_html__( 'Edit Testimonials Category','qode_core' ),
            'update_item' => esc_html__( 'Update Testimonials Category','qode_core' ),
            'add_new_item' => esc_html__( 'Add New Testimonials Category','qode_core' ),
            'new_item_name' => esc_html__( 'New Testimonials Category Name','qode_core' ),
            'menu_name' => esc_html__( 'Testimonials Categories','qode_core' ),
        );

        register_taxonomy($this->taxBase, array($this->base), array(
            'hierarchical' => true,
            'labels' => $labels,
            'show_ui' => true,
            'query_var' => true,
            'show_admin_column' => true,
            'rewrite' => array( 'slug' => 'testimonials-category' ),
        ));
    }

}