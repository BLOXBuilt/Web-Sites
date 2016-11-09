<?php
namespace QodeCore\CPT\Portfolio;

use QodeCore\Lib\PostTypeInterface;

/**
 * Class PortfolioRegister
 * @package QodeCore\CPT\Portfolio
 */
class PortfolioRegister implements PostTypeInterface {
    /**
     * @var string
     */
    private $base;

    public function __construct() {
        $this->base = 'portfolio_page';
        $this->taxBase = 'portfolio_category';

        add_filter('single_template', array($this, 'registerSingleTemplate'));
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
        $this->registerTagTax();
    }

    /**
     * Registers portfolio single template if one does'nt exists in theme.
     * Hooked to single_template filter
     * @param $single string current template
     * @return string string changed template
     */
    public function registerSingleTemplate($single) {
        global $post;

        if($post->post_type == $this->base) {
            if(!file_exists(get_template_directory().'/single-portfolio_page.php')) {
                return QODE_CORE_CPT_PATH.'/portfolio/templates/single-'.$this->base.'.php';
            }
        }

        return $single;
    }

    /**
     * Registers custom post type with WordPress
     */
    private function registerPostType() {
        global $qode_pitch_Framework, $qode_pitch_options;

        $menuPosition = 5;
        $menuIcon = 'dashicons-admin-post';
        $slug = 'portfolio_page';

        if(qode_pitch_core_theme_installed()) {
            $menuPosition = $qode_pitch_Framework->getSkin()->getMenuItemPosition('portfolio');
            $menuIcon = $qode_pitch_Framework->getSkin()->getMenuIcon('portfolio');

            if(isset($qode_pitch_options['portfolio_single_slug'])) {
                if($qode_pitch_options['portfolio_single_slug'] != ""){
                    $slug = $qode_pitch_options['portfolio_single_slug'];
                }
            }
        }

        register_post_type( 'portfolio_page',
            array(
                'labels' => array(
                    'name' => esc_html__( 'Portfolio','qode_core' ),
                    'singular_name' => esc_html__( 'Portfolio Item','qode_core' ),
                    'add_item' => esc_html__('New Portfolio Item','qode_core'),
                    'add_new_item' => esc_html__('Add New Portfolio Item','qode_core'),
                    'edit_item' => esc_html__('Edit Portfolio Item','qode_core')
                ),
                'public' => true,
                'has_archive' => true,
                'rewrite' => array('slug' => $slug),
                'menu_position' => $menuPosition,
                'show_ui' => true,
                'supports' => array('author', 'title', 'editor', 'thumbnail', 'excerpt', 'page-attributes', 'comments'),
                'menu_icon'  =>  $menuIcon
            )
        );
    }

    /**
     * Registers custom taxonomy with WordPress
     */
    private function registerTax() {
        $labels = array(
            'name' => esc_html__( 'Portfolio Categories', 'taxonomy general name' ),
            'singular_name' => esc_html__( 'Portfolio Category', 'taxonomy singular name' ),
            'search_items' =>  esc_html__( 'Search Portfolio Categories','qode_core' ),
            'all_items' => esc_html__( 'All Portfolio Categories','qode_core' ),
            'parent_item' => esc_html__( 'Parent Portfolio Category','qode_core' ),
            'parent_item_colon' => esc_html__( 'Parent Portfolio Category:','qode_core' ),
            'edit_item' => esc_html__( 'Edit Portfolio Category','qode_core' ),
            'update_item' => esc_html__( 'Update Portfolio Category','qode_core' ),
            'add_new_item' => esc_html__( 'Add New Portfolio Category','qode_core' ),
            'new_item_name' => esc_html__( 'New Portfolio Category Name','qode_core' ),
            'menu_name' => esc_html__( 'Portfolio Categories','qode_core' ),
        );

        register_taxonomy($this->taxBase, array($this->base), array(
            'hierarchical' => true,
            'labels' => $labels,
            'show_ui' => true,
            'query_var' => true,
            'rewrite' => array( 'slug' => 'portfolio-category' ),
        ));
    }

    /**
     * Registers custom tag taxonomy with WordPress
     */
    private function registerTagTax() {
        $labels = array(
            'name' => esc_html__( 'Portfolio Tags', 'taxonomy general name' ),
            'singular_name' => esc_html__( 'Portfolio Tag', 'taxonomy singular name' ),
            'search_items' =>  esc_html__( 'Search Portfolio Tags','qode_core' ),
            'all_items' => esc_html__( 'All Portfolio Tags','qode_core' ),
            'parent_item' => esc_html__( 'Parent Portfolio Tag','qode_core' ),
            'parent_item_colon' => esc_html__( 'Parent Portfolio Tags:','qode_core' ),
            'edit_item' => esc_html__( 'Edit Portfolio Tag','qode_core' ),
            'update_item' => esc_html__( 'Update Portfolio Tag','qode_core' ),
            'add_new_item' => esc_html__( 'Add New Portfolio Tag','qode_core' ),
            'new_item_name' => esc_html__( 'New Portfolio Tag Name','qode_core' ),
            'menu_name' => esc_html__( 'Portfolio Tags','qode_core' ),
        );

        register_taxonomy('portfolio_tag',array($this->base), array(
            'hierarchical' => false,
            'labels' => $labels,
            'show_ui' => true,
            'query_var' => true,
            'rewrite' => array( 'slug' => 'portfolio-tag' ),
        ));
    }
}