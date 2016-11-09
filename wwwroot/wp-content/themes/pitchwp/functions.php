<?php

//$qode_pitch_toolbar = true;

if(isset($qode_pitch_toolbar)):
    add_action('after_setup_theme', 'qode_pitch_StartSession', 10);
    add_action('wp_logout', 'qode_pitch_EndSession');
    add_action('wp_login', 'qode_pitch_EndSession');
    /* Start session */
	
    if (!function_exists('qode_pitch_StartSession')) {
        function qode_pitch_StartSession($classes) {
            global $qode_pitch_options;
            if(!session_id()) {
                session_start();
            }
			
			$classes[] = 'toolbar_sesion_on';
			
            if (isset($_SESSION['enable_popup_menu'])) {
                if ($_SESSION['enable_popup_menu'] == "yes" || $_SESSION['enable_popup_menu'] == "no") {
                    $qode_pitch_options["enable_popup_menu"] = $_SESSION['enable_popup_menu'];
                }
				
				if ($_SESSION['enable_popup_menu'] == "yes") {
                    $classes[] = 'landing_fullscreen_menu_on';
                }
            }
			if (isset($_SESSION['enable_side_area'])) {
                if ($_SESSION['enable_side_area'] == "yes" || $_SESSION['enable_side_area'] == "no") {
                    $qode_pitch_options["enable_side_area"] = $_SESSION['enable_side_area'];
                }
				if ($_SESSION['enable_side_area'] == "yes") {
                    $classes[] = 'landing_side_area_on';
                }
				
            }
			if (isset($_SESSION['menu_appearance'])) {
                if ($_SESSION['menu_appearance'] == "default" || $_SESSION['menu_appearance'] == "top_menu_slide_down") {
                    $qode_pitch_options["menu_appearance"] = $_SESSION['menu_appearance'];
                }
				if ($_SESSION['menu_appearance'] == "top_menu_slide_down") {
                    $classes[] = 'top_menu_slide_down_on';
                }
            }
			return $classes;
        }
		add_filter('body_class', 'qode_pitch_StartSession');
	}
    /* End session */
    if (!function_exists('qode_pitch_EndSession')) {
        function qode_pitch_EndSession() {
            session_destroy ();
        }
    }
endif;

add_filter('widget_text', 'do_shortcode');

define('QODE_ROOT', get_template_directory_uri());
define('QODE_VAR_PREFIX', 'qode_');

include_once get_template_directory().'/framework/qode-framework.php';
include_once get_template_directory().'/includes/shortcodes/shortcodes.php';
include_once get_template_directory().'/includes/qode-breadcrumbs.php';
include_once get_template_directory().'/includes/nav_menu/qode-menu.php';
include_once get_template_directory().'/includes/sidebar/qode-custom-sidebar.php';
include_once get_template_directory().'/includes/qode-like.php';
include_once get_template_directory().'/includes/header/qode-header-functions.php';
include_once get_template_directory().'/includes/title/qode-title-functions.php';
include_once get_template_directory().'/includes/qode-portfolio-functions.php';
include_once get_template_directory().'/includes/qode-loading-spinners.php';
include_once get_template_directory().'/includes/qode-options-helper-functions.php';
/* Include comment functionality */
include_once get_template_directory().'/includes/comment/comment.php';
/* Include sidebar functionality */
include_once get_template_directory().'/includes/sidebar/sidebar.php';
/* Include pagination functionality */
include_once get_template_directory().'/includes/pagination/pagination.php';
/** Include the TGM_Plugin_Activation class. */
include_once get_template_directory().'/includes/plugins/class-tgm-plugin-activation.php';

/* Include visual composer initialization */
include_once get_template_directory().'/includes/plugins/visual-composer.php';
/* Include activation for layer slider */

include_once get_template_directory().'/includes/plugins/layer-slider.php';
include_once get_template_directory().'/includes/plugins/qode-core.php';
include_once get_template_directory().'/includes/instagram/qode-instagram-api.php';
include_once get_template_directory().'/includes/qode-blog-functions.php';
include_once get_template_directory().'/includes/qode-plugin-helper-functions.php';
include_once get_template_directory().'/widgets/qode-call-to-action-widget.php';
include_once get_template_directory().'/widgets/qode-sticky-sidebar.php';
include_once get_template_directory().'/widgets/qode-latest-posts-widget.php';
include_once get_template_directory().'/widgets/qode-latest-posts-menu-widget.php';
include_once get_template_directory().'/widgets/qode-instagram-widget.php';
include_once get_template_directory().'/includes/plugins/qode-twitter-feed.php';


//does woocommerce function exists?
if(function_exists("is_woocommerce")){
	//include woocommerce configuration
	include_once get_template_directory().'/woocommerce/woocommerce_configuration.php';
	//include cart dropdown widget
	include_once get_template_directory().'/widgets/qode-woocommerce-dropdown-cart.php';
}

add_filter( 'call_to_action_widget', 'do_shortcode');

if(!function_exists('qode_pitch_load_theme_text_domain')) {
	/**
	 * Function that sets theme domain. Hooks to after_setup_theme action
	 *
	 * @see load_theme_textdomain()
	 */
	function qode_pitch_load_theme_text_domain() {
		load_theme_textdomain( 'pitchwp', get_template_directory().'/languages' );
	}

	add_action('after_setup_theme', 'qode_pitch_load_theme_text_domain');
}


if (!function_exists('qode_pitch_styles')) {
	/**
	 * Function that includes theme's core styles
	 */
	function qode_pitch_styles() {
		global $qode_pitch_options;
        global $qode_pitch_landing;
		global $qode_pitch_IconCollections;

		//init variables
		$responsiveness = 'yes';
		$vertical_area_hidden = '';

		wp_register_style("qode_pitch_blog", QODE_ROOT . "/css/blog.min.css");

		//include theme's core styles
		wp_enqueue_style("qode_pitch_default_style", QODE_ROOT . "/style.css");		
		wp_enqueue_style("qode_pitch_stylesheet", QODE_ROOT . "/css/stylesheet.min.css");

		if(qode_pitch_load_blog_assets()) {
			wp_enqueue_style('qode_pitch_blog');
		}
		
		//define files afer which style dynamic needs to be included. It should be included last so it can override other files
		$style_dynamic_deps_array = array();
		if(qode_pitch_load_woo_assets()) {
			$style_dynamic_deps_array = array('qode_pitch_woocommerce', 'qode_pitch_woocommerce_responsive');
		}


		if (file_exists(get_template_directory() ."/css/style_dynamic.css") && qode_pitch_is_css_folder_writable() && !is_multisite()) {
            wp_enqueue_style("qode_pitch_style_dynamic", QODE_ROOT . "/css/style_dynamic.css", $style_dynamic_deps_array, filemtime(get_template_directory() ."/css/style_dynamic.css")); //it must be included after woocommerce styles so it can override it
        } else {
            wp_enqueue_style("qode_pitch_style_dynamic", QODE_ROOT . "/css/style_dynamic.php", $style_dynamic_deps_array); //it must be included after woocommerce styles so it can override it
        }

		
		
		//include icon collections styles
		if(is_array($qode_pitch_IconCollections->iconCollections) && count($qode_pitch_IconCollections->iconCollections)) {
			foreach ($qode_pitch_IconCollections->iconCollections as $collection_key => $collection_obj) {
				wp_enqueue_style('qode_pitch_'.$collection_key, $collection_obj->styleUrl);
			}
		}

		//does responsive option exists?
		if (isset($qode_pitch_options['responsiveness'])) {
			$responsiveness = $qode_pitch_options['responsiveness'];
		}

		//is responsive option turned on?
		if ($responsiveness != "no") {
			//include proper styles
			wp_enqueue_style("qode_pitch_responsive", QODE_ROOT . "/css/responsive.min.css");

			if (file_exists(get_template_directory() ."/css/style_dynamic_responsive.css") && qode_pitch_is_css_folder_writable() && !is_multisite()){
                wp_enqueue_style("qode_pitch_style_dynamic_responsive", QODE_ROOT . "/css/style_dynamic_responsive.css", array(), filemtime(get_template_directory() ."/css/style_dynamic_responsive.css"));
            } else {
                wp_enqueue_style("qode_pitch_style_dynamic_responsive", QODE_ROOT . "/css/style_dynamic_responsive.php");
            }
            
		}
		
		//is hidden menu enabled?
		if (isset($qode_pitch_options['vertical_area_type'])){
			$vertical_area_hidden = $qode_pitch_options['vertical_area_type'];
		}

		//is left menu activated and is responsive turned on?
		if(qode_pitch_is_side_header() && $responsiveness != "no" && $vertical_area_hidden!='hidden'){
			wp_enqueue_style("qode_pitch_vertical_responsive", QODE_ROOT . "/css/vertical_responsive.min.css");
		}

        //is landing turned on?
        if (isset($qode_pitch_landing)) {
            //include ladnding specific styles
            wp_enqueue_style("qode_pitch_landing_fancybox", get_home_url() . "/demo-files/landing/css/jquery.fancybox.css");
            wp_enqueue_style("qode_pitch_landing", get_home_url() . "/demo-files/landing/css/landing_stylesheet_stripped.css");

        }

		//include Visual Composer styles
		if (class_exists('WPBakeryVisualComposerAbstract')) {
			wp_enqueue_style( 'js_composer_front' );
		}
		
		if (file_exists(get_template_directory() ."/css/custom_css.css") && qode_pitch_is_css_folder_writable() && !is_multisite()){
            wp_enqueue_style("qode_pitch_custom_css", QODE_ROOT . "/css/custom_css.css", array(), filemtime(get_template_directory() ."/css/custom_css.css"));
        } else {
            wp_enqueue_style("qode_pitch_custom_css", QODE_ROOT . "/css/custom_css.php");
        }
        
	}

	add_action('wp_enqueue_scripts', 'qode_pitch_styles');
}


if(!function_exists('qode_pitch_browser_specific_styles')) {
	/**
	 * Function that includes browser specific styles. Works for Chrome on Mac and for webkit browsers
	 */
	function qode_pitch_browser_specific_styles() {
		global $is_chrome;
		global $is_safari;

		//check Chrome version
		preg_match( "#Chrome/(.+?)\.#", $_SERVER['HTTP_USER_AGENT'], $match );
		if(!empty($match)) {
			$chrome_version = $match[1];
		} else{
			$chrome_version = 0;
		}

		//is Mac OS X?
		$mac_os = strpos($_SERVER['HTTP_USER_AGENT'], "Macintosh; Intel Mac OS X");

		//is Chrome on Mac with version greater than 21
		if($is_chrome && ($mac_os !== false) && ($chrome_version > 21)) {
			//include mac specific styles
			wp_enqueue_style("qode_pitch_mac_stylesheet", QODE_ROOT . "/css/mac_stylesheet.css");
		}

		//is Chrome or Safari?
		if($is_chrome || $is_safari) {
			//include style for webkit browsers only
			wp_enqueue_style("qode_pitch_webkit", QODE_ROOT . "/css/webkit_stylesheet.css");
		}
	}

	add_action('wp_enqueue_scripts', 'qode_pitch_browser_specific_styles');
}

if(!function_exists('qode_pitch_add_meta_data')) {
    /**
     * Function that includes styles for IE9
     */

    function qode_pitch_add_meta_data(){
        echo '<!--[if IE 9]><link rel="stylesheet" type="text/css" href="' . esc_url(QODE_ROOT) . '/css/ie9_stylesheet.css" media="screen"><![endif]-->';
    }

    add_action( 'wp_head', 'qode_pitch_add_meta_data' );
}

/* Page ID */

if(!function_exists('qode_pitch_init_page_id')) {
	/**
	 * Function that initializes global variable that holds current page id
	 */
	function qode_pitch_init_page_id() {
		global $wp_query;
		global $qode_pitch_page_id;

		$qode_pitch_page_id = $wp_query->get_queried_object_id();
	}

	add_action('get_header', 'qode_pitch_init_page_id');
}


if(!function_exists('qode_pitch_google_fonts_styles')) {
	/**
	 * Function that includes google fonts defined anywhere in the theme
	 */
	function qode_pitch_google_fonts_styles() {
		global $qode_pitch_options;
		global $qode_pitch_Framework;

		$font_sipmle_field_array = array();
		if(is_array($qode_pitch_Framework->qodeOptions->getOptionsByType('fontsimple')) && count($qode_pitch_Framework->qodeOptions->getOptionsByType('fontsimple')) > 0){
			$font_sipmle_field_array = $qode_pitch_Framework->qodeOptions->getOptionsByType('fontsimple');
		}
		$font_field_array = array();
		if(is_array($qode_pitch_Framework->qodeOptions->getOptionsByType('font')) && count($qode_pitch_Framework->qodeOptions->getOptionsByType('font')) > 0){
			$font_field_array = $qode_pitch_Framework->qodeOptions->getOptionsByType('font');
		}
		$available_font_options = array_merge($font_sipmle_field_array, $font_field_array);
		$font_weight_str = '100,100italic,200,200italic,300,300italic,400,400italic,500,500italic,600,600italic,700,700italic,800,800italic,900,900italic';

		//define available font options array
		$fonts_array = array();
		foreach($available_font_options as $font_option) {
			//is font set and not set to default and not empty?
			if(isset($qode_pitch_options[$font_option]) && $qode_pitch_options[$font_option] !== '-1' && $qode_pitch_options[$font_option] !== '' && !qode_pitch_is_native_font($qode_pitch_options[$font_option])) {
				$font_option_string = $qode_pitch_options[$font_option].':'.$font_weight_str;
				if(!in_array($font_option_string, $fonts_array)) {
					$fonts_array[] = $font_option_string;
				}
			}
		}

		//add google fonts set in slider
		$args = array( 'post_type' => 'slides', 'posts_per_page' => -1);
		$loop = new WP_Query( $args );

		//for each slide defined
		while ( $loop->have_posts() ) : $loop->the_post();

			//is font family for title option chosen?
			if(get_post_meta(get_the_ID(), "qode_slide-title-font-family", true) != "" && !qode_pitch_is_native_font(get_post_meta(get_the_ID(), "qode_slide-title-font-family", true))) {
				$slide_title_font_string = get_post_meta(get_the_ID(), "qode_slide-title-font-family", true) . ":".$font_weight_str;
				if(!in_array($slide_title_font_string, $fonts_array)) {
					//include that font
					array_push($fonts_array, $slide_title_font_string);
				}
			}

			//is font family defined for slide's text?
			if(get_post_meta(get_the_ID(), "qode_slide-text-font-family", true) != "" && !qode_pitch_is_native_font(get_post_meta(get_the_ID(), "qode_slide-text-font-family", true))) {
				$slide_text_font_string = get_post_meta(get_the_ID(), "qode_slide-text-font-family", true) . ":".$font_weight_str;
				if(!in_array($slide_text_font_string, $fonts_array)) {
					//include that font
					array_push($fonts_array, $slide_text_font_string);
				}
			}

			//is font family defined for slide's subtitle?
			if(get_post_meta(get_the_ID(), "qode_slide-subtitle-font-family", true) != "" && !qode_pitch_is_native_font(get_post_meta(get_the_ID(), "qode_slide-subtitle-font-family", true))) {
				$slide_subtitle_font_string = get_post_meta(get_the_ID(), "qode_slide-subtitle-font-family", true) .":".$font_weight_str;
				if(!in_array($slide_subtitle_font_string, $fonts_array)) {
					//include that font
					array_push($fonts_array, $slide_subtitle_font_string);
				}
			}
		endwhile;

		wp_reset_postdata();


		$fonts_array = array_diff($fonts_array, array("-1:".$font_weight_str));
		$google_fonts_string = implode( '|', $fonts_array);

		 //default fonts should be separated with |
		$default_font_string = 'Open Sans:'.$font_weight_str.'|Montserrat:'.$font_weight_str;
		
		//is google font option checked anywhere in theme?
        if (count($fonts_array) > 0) {
            //include all checked fonts
			$fonts_full_list = $default_font_string . '|' . str_replace('+', ' ', $google_fonts_string);
			$fonts_full_list_args = array(
				'family' => urlencode($fonts_full_list),
				'subset' => urlencode('latin,latin-ext'),
			);

			$qode_fonts = add_query_arg( $fonts_full_list_args, 'https://fonts.googleapis.com/css' );
			wp_enqueue_style( 'qode_pitch_google_fonts', esc_url_raw($qode_fonts), array(), '1.0.0' );
        } else {
            //include default google font that theme is using
			$default_fonts_args = array(
				'family' => urlencode($default_font_string),
				'subset' => urlencode('latin,latin-ext'),
			);
			$qode_fonts = add_query_arg( $default_fonts_args, 'https://fonts.googleapis.com/css' );
			wp_enqueue_style( 'qode_pitch_google_fonts', esc_url_raw($qode_fonts), array(), '1.0.0' );
        }

    }

	add_action('wp_enqueue_scripts', 'qode_pitch_google_fonts_styles');
}


if (!function_exists('qode_pitch_scripts')) {
	/**
	 * Function that includes all necessary scripts
	 */
	function qode_pitch_scripts() {
		global $qode_pitch_options;
        global $qode_pitch_landing;
		global $qode_pitch_toolbar;
		global $wp_scripts;

		//init variables
		$smooth_scroll 	= true;
		$has_ajax 		= false;
		$qode_animation = "";

		//is smooth scroll option turned on?
		if(isset($qode_pitch_options['smooth_scroll']) && $qode_pitch_options['smooth_scroll'] == "no"){
			$smooth_scroll = false;
		}

		//init theme core scripts
		wp_enqueue_script("qode_pitch_plugins", QODE_ROOT."/js/plugins.js",array("jquery"),false,true);
		wp_enqueue_script("carouFredSel", QODE_ROOT."/js/jquery.carouFredSel-6.2.1.js",array("jquery"),false,true);
		wp_enqueue_script("one_page_scroll", QODE_ROOT."/js/jquery.fullPage.min.js",array("jquery"),false,true);
		wp_enqueue_script("lemmonSlider", QODE_ROOT."/js/lemmon-slider.js",array("jquery"),false,true);
		wp_enqueue_script("owl_carousel", QODE_ROOT."/js/owl.carousel.min.js",array("jquery"),false,true);
		wp_enqueue_script("mousewheel", QODE_ROOT."/js/jquery.mousewheel.min.js",array("jquery"),false,true);
		wp_enqueue_script("touchSwipe", QODE_ROOT."/js/jquery.touchSwipe.min.js",array("jquery"),false,true);
		wp_enqueue_script("isotope", QODE_ROOT."/js/jquery.isotope.min.js",array("jquery"),false,true);

        //include google map api script
		if( (isset($qode_pitch_options['google_maps_api_key']) && $qode_pitch_options['google_maps_api_key'] != "")) {

				$google_maps_api_key = $qode_pitch_options['google_maps_api_key'];
				wp_enqueue_script("google_map_api", "https://maps.googleapis.com/maps/api/js?key=" . $google_maps_api_key,array(),false,true);

			} else {

				wp_enqueue_script("google_map_api", "https://maps.googleapis.com/maps/api/js",array(),false,true);

			}

        wp_enqueue_script("qode_pitch_default_dynamic", QODE_ROOT."/js/default_dynamic.php", array("jquery"), false, true);

        wp_enqueue_script("qode_pitch_default", QODE_ROOT."/js/default.min.js", array("jquery"), false, true);

		if(qode_pitch_load_blog_assets()) {
			wp_enqueue_script('qode_pitch_blog', QODE_ROOT."/js/blog.min.js", array("jquery"), false, true);
		}


        wp_enqueue_script("qode_pitch_custom_js", QODE_ROOT."/js/custom_js.php", array("jquery"), false, true);
        

        //is smooth scroll enabled enabled and not Mac device?
        $mac_os = strpos($_SERVER['HTTP_USER_AGENT'], "Macintosh; Intel Mac OS X");
        if($smooth_scroll && $mac_os == false){
            wp_enqueue_script("TweenLite", QODE_ROOT."/js/TweenLite.min.js",array("jquery"),false,true);
            wp_enqueue_script("ScrollToPlugin", QODE_ROOT."/js/ScrollToPlugin.min.js",array("jquery"),false,true);
            wp_enqueue_script("smoothPageScroll", QODE_ROOT."/js/smoothPageScroll.js",array("jquery"),false,true);
        }

		//include comment reply script
		$wp_scripts->add_data('comment-reply', 'group', 1 );
		if (is_singular()) {
			wp_enqueue_script( "comment-reply");
		}

		if (($qode_pitch_options['page_transitions'] != "0") && (empty($qode_animation) || ($qode_animation != "no"))) {
			$has_ajax = true;
		} elseif (!empty($qode_animation) && ($qode_animation != "no"))
			$has_ajax = true;

		if ($has_ajax) {
			wp_enqueue_script("qode_pitch_ajax", QODE_ROOT."/js/ajax.min.js",array("jquery"),false,true);
		}

		//include Visual Composer script
		if (class_exists('WPBakeryVisualComposerAbstract')) {
			wp_enqueue_script( 'wpb_composer_front_js' );
		}

        //is landing enabled?
        if(isset($qode_pitch_landing)) {
            wp_enqueue_script("qode_pitch_landing_fancybox", get_home_url() . "/demo-files/landing/js/jquery.fancybox.js",array("jquery"),false,true);
            wp_enqueue_script("qode_pitch_landing", get_home_url() . "/demo-files/landing/js/landing_default.js",array("jquery"),false,true);
        }
		
		if(isset($qode_pitch_toolbar)){
         wp_enqueue_script("qode_pitch_toolbar", get_home_url() . "/toolbar/toolbar.js",array("jquery"),false,true);
		}

	}

	add_action('wp_enqueue_scripts', 'qode_pitch_scripts');
}

if(!function_exists('qode_pitch_browser_specific_scripts')) {
	/**
	 * Function that loads browser specific scripts
	 */
	function qode_pitch_browser_specific_scripts() {
		global $is_IE;

		//is ie?
		if ($is_IE) {
			wp_enqueue_script("qode_html5", QODE_ROOT."/js/html5.js",array("jquery"),false,false);
		}
	}

	add_action('wp_enqueue_scripts', 'qode_pitch_browser_specific_scripts');
}

if(!function_exists('qode_pitch_woocommerce_assets')) {
	/**
	 * Function that includes all necessary scripts for WooCommerce if installed
	 */
	function qode_pitch_woocommerce_assets() {
		global $qode_pitch_options;

		//is woocommerce installed?
		if(qode_pitch_is_woocommerce_installed()) {
			if(qode_pitch_load_woo_assets()) {
				//get woocommerce specific scripts
				wp_enqueue_script("qode_pitch_woocommerce_script", QODE_ROOT . "/js/woocommerce.min.js", array("jquery"), false, true);
				wp_enqueue_script("qode_pitch_select2", QODE_ROOT . "/js/select2.min.js", array("jquery"), false, true);

				//include theme's woocommerce styles
				wp_enqueue_style("qode_pitch_woocommerce", QODE_ROOT . "/css/woocommerce.min.css");

				//is responsive option turned on?
				if ($qode_pitch_options['responsiveness'] == 'yes') {
					//include theme's woocommerce responsive styles
					wp_enqueue_style("qode_pitch_woocommerce_responsive", QODE_ROOT . "/css/woocommerce_responsive.min.css");
				}
			}
		}
	}

	add_action('wp_enqueue_scripts', 'qode_pitch_woocommerce_assets');
}

//defined content width variable
if (!isset( $content_width )) $content_width = 1300;

if (!function_exists('qode_pitch_register_menus')) {
	/**
	 * Function that registers menu locations
	 */
	function qode_pitch_register_menus() {
        global $qode_pitch_options;

        if((isset($qode_pitch_options['header_bottom_appearance']) && $qode_pitch_options['header_bottom_appearance'] != "stick_with_left_right_menu") || (qode_pitch_is_side_header())){
            //header and left menu location
            register_nav_menus(
                array('top-navigation' => esc_html__( 'Top Navigation', 'pitchwp')
                )
            );
        }

		if((isset($qode_pitch_options['enable_popup_menu']) && $qode_pitch_options['enable_popup_menu'] == "yes") && (!qode_pitch_is_side_header())){
			//popup menu location
			register_nav_menus(
				array('popup-navigation' => esc_html__( 'Fullscreen Navigation', 'pitchwp')
				)
			);
		}

        if((isset($qode_pitch_options['header_bottom_appearance']) && $qode_pitch_options['header_bottom_appearance'] == "stick_with_left_right_menu") && (!qode_pitch_is_side_header())){
            //header left menu location
            register_nav_menus(
                array('left-top-navigation' => esc_html__( 'Left Top Navigation', 'pitchwp')
                )
            );

            //header right menu location
            register_nav_menus(
                array('right-top-navigation' => esc_html__( 'Right Top Navigation', 'pitchwp')
                )
            );
        }
	}

	add_action( 'after_setup_theme', 'qode_pitch_register_menus' );
}

if(!function_exists('qode_pitch_add_theme_support')) {
	/**
	 * Function that adds various features to theme. Also defines image sizes that are used in a theme
	 */
	function qode_pitch_add_theme_support() {
		//add support for feed links
		add_theme_support( 'automatic-feed-links' );

		//add support for post formats
		add_theme_support('post-formats', array('gallery', 'link', 'quote', 'video', 'audio'));

		//add theme support for post thumbnails
		add_theme_support( 'post-thumbnails' );

        //add theme support for title tag
        if(function_exists('_wp_render_title_tag')) {
            add_theme_support('title-tag');
        }

		//define thumbnail sizes
		add_image_size( 'qode-pitch-portfolio-related', 306, 229, true );
		add_image_size( 'qode-pitch-portfolio-square', 550, 550, true );
		add_image_size( 'qode-pitch-portfolio-landscape', 800, 600, true );
		add_image_size( 'qode-pitch-portfolio-portrait', 600, 800, true );
		add_image_size( 'qode-pitch-portfolio_masonry_wide', 1000, 500, true );
		add_image_size( 'qode-pitch-portfolio_masonry_tall', 500, 1000, true );
		add_image_size( 'qode-pitch-portfolio_masonry_large', 1000, 1000, true );
		add_image_size( 'qode-pitch-portfolio_masonry_with_space', 700);
		add_image_size( 'qode-pitch-blog_image_format_link_quote', 1100, 500, true);

	}

	add_action('after_setup_theme', 'qode_pitch_add_theme_support');
}

if (!function_exists('qode_pitch_ajax_classes')) {
	/**
	 * Function that adds classes on body for ajax transitions
	 */
	function qode_pitch_ajax_classes($classes) {
		global $qode_pitch_options;


		//is ajax animation turned off in options?
		if(($qode_pitch_options['page_transitions'] === "0")) {
			$classes[] = '';
		}

		//is up down animation type set?
		elseif($qode_pitch_options['page_transitions'] === "1") {
			$classes[] = 'ajax_updown';
			$classes[] = 'page_not_loaded';
		}

		//is fade animation type set?
		elseif($qode_pitch_options['page_transitions'] === "2") {
			$classes[] = 'ajax_fade';
			$classes[] = 'page_not_loaded';
		}

		//is up down fade animation type set?
		elseif($qode_pitch_options['page_transitions'] === "3") {
			$classes[] = 'ajax_updown_fade';
			$classes[] = 'page_not_loaded';
		}

		//is left / right animation type set?
		elseif($qode_pitch_options['page_transitions'] === "4") {
			$classes[] = 'ajax_leftright';
			$classes[] = 'page_not_loaded';
		}

		//animation is turned off in options
		else {
			$classes[] ="";
		}

		return $classes;
	}

	add_filter('body_class', 'qode_pitch_ajax_classes');
}

if (!function_exists('qode_pitch_boxed_class')) {
	/**
	 * Function that adds classes on body for boxed layout
	 */
	function qode_pitch_boxed_class($classes) {
		global $qode_pitch_options;

		//is boxed layout turned on?
		if(isset($qode_pitch_options['boxed']) && $qode_pitch_options['boxed'] == "yes" && isset($qode_pitch_options['transparent_content']) && $qode_pitch_options['transparent_content'] == 'no') {
			$classes[] = 'boxed';
		} else {
			$classes[] ="";
		}

		return $classes;
	}

	add_filter('body_class', 'qode_pitch_boxed_class');
}

if (!function_exists('qode_pitch_padding_class')) {
	/**
	 * Function that adds classes on body for boxed layout with padding
	 */
	function qode_pitch_padding_class($classes) {
		global $qode_pitch_options;

		//is boxed layout turned on?
		if(isset($qode_pitch_options['boxed']) && $qode_pitch_options['boxed'] == "yes" && isset($qode_pitch_options['boxed_padding_general']) && !empty($qode_pitch_options['boxed_padding_general'])) {
			$classes[] = 'has_general_padding';
		} else {
			$classes[] ="";
		}

		return $classes;
	}

	add_filter('body_class', 'qode_pitch_padding_class');
}


if(!function_exists('qode_pitch_rgba_color')) {
    /**
     * Function that generates rgba part of css color property
     * @param $color string hex color
     * @param $transparency float transparency value between 0 and 1
     * @return string generated rgba string
     */
    function qode_pitch_rgba_color($color, $transparency) {
        if($color !== '' && $transparency !== '') {
            $rgba_color = '';

            $rgb_color_array = qode_pitch_hex2rgb($color);
            $rgba_color .= 'rgba('.implode(', ', $rgb_color_array).', '.$transparency.')';

            return $rgba_color;
        }
    }
}



if (!function_exists('qode_pitch_theme_version_class')) {
	/**
	 * Function that adds classes on body for version of theme
	 */
	function qode_pitch_theme_version_class($classes) {
        $current_theme = wp_get_theme();

        //is child theme activated?
        if($current_theme->parent()) {
            //add child theme version
            $classes[] = strtolower($current_theme->get('Name')).'-child-ver-'.$current_theme->get('Version');

            //get parent theme
            $current_theme = $current_theme->parent();
        }

        if($current_theme->exists() && $current_theme->get('Version') != "") {
            $classes[] = strtolower($current_theme->get('Name')).'-ver-'.$current_theme->get('Version');
        }

        return $classes;
	}

	add_filter('body_class', 'qode_pitch_theme_version_class');
}

if (!function_exists('qode_pitch_vertical_menu_class')) {
	/**
	 * Function that adds classes on body element for left menu area
	 */
	function qode_pitch_vertical_menu_class($classes) {
		global $qode_pitch_options;
		global $wp_query;

		//is left menu area turned on?
		if(qode_pitch_is_side_header()) {
			$classes[] = 'vertical_menu_enabled';

            //left menu type class?
            if(isset($qode_pitch_options['vertical_area_type']) && $qode_pitch_options['vertical_area_type'] != '') {
                switch ($qode_pitch_options['vertical_area_type']) {
                    case 'hidden':
                        $classes[] = ' vertical_menu_hidden';

						if(isset($qode_pitch_options['vertical_logo_bottom']) && $qode_pitch_options['vertical_logo_bottom'] !== '') {
							$classes[] = 'vertical_menu_hidden_with_logo';
						}
                        break;
						
					 case 'hidden_with_icons':
                        $classes[] = ' vertical_menu_hidden vertical_menu_hidden_with_icons';

						if(isset($qode_pitch_options['vertical_logo_bottom']) && $qode_pitch_options['vertical_logo_bottom'] !== '') {
							$classes[] = 'vertical_menu_hidden_with_logo';
						}
                        break;
                }
            }

			if(isset($qode_pitch_options['vertical_area_position'])){
				if($qode_pitch_options['vertical_area_position'] == 'right'){
					$classes[] = ' vertical_menu_right';
				}elseif($qode_pitch_options['vertical_area_position'] == 'left'){
					$classes[] = ' vertical_menu_left';
				}				
			}  
			
			if(isset($qode_pitch_options['vertical_area_width']) && $qode_pitch_options['vertical_area_width']=='width_350'){
				 $classes[] = ' vertical_menu_width_350';
			} 
			elseif(isset($qode_pitch_options['vertical_area_width']) && $qode_pitch_options['vertical_area_width']=='width_400'){
				 $classes[] = ' vertical_menu_width_400';
			} 
			else{
				$classes[] = ' vertical_menu_width_290';
			}
		}

		//get current page id
		$id = $wp_query->get_queried_object_id();

		if(qode_pitch_is_woocommerce_page()) {
			$id = get_option('woocommerce_shop_page_id');
		}

		if(isset($qode_pitch_options['vertical_area_transparency']) && $qode_pitch_options['vertical_area_transparency'] =='yes' && get_post_meta($id, "qode_page_vertical_area_transparency", true) != "no" && isset($qode_pitch_options['vertical_area_dropdown_showing']) && $qode_pitch_options['vertical_area_dropdown_showing'] != "side"){
			$classes[] = ' vertical_menu_transparency vertical_menu_transparency_on';
		}else if(get_post_meta($id, "qode_page_vertical_area_transparency", true) == "yes" && isset($qode_pitch_options['vertical_area_dropdown_showing']) && $qode_pitch_options['vertical_area_dropdown_showing'] != "side"){
			$classes[] = ' vertical_menu_transparency vertical_menu_transparency_on';
		}
		
		if(isset($qode_pitch_options['vertical_area_transparency_over_slider']) && $qode_pitch_options['vertical_area_transparency_over_slider'] =='yes' && get_post_meta($id, "qode_page_vertical_area_transparency_over_slider", true) != "no" && isset($qode_pitch_options['vertical_area_dropdown_showing']) && $qode_pitch_options['vertical_area_dropdown_showing'] != "side"){
			$classes[] = 'vertical_menu_background_opacity_over_slider vertical_menu_transparency_on  vertical_menu_background_opacity_over_slider_on';
		}else if(get_post_meta($id, "qode_page_vertical_area_transparency_over_slider", true) == "yes" && isset($qode_pitch_options['vertical_area_dropdown_showing']) && $qode_pitch_options['vertical_area_dropdown_showing'] != "side"){
			$classes[] = ' vertical_menu_background_opacity_over_slider vertical_menu_transparency_on vertical_menu_background_opacity_over_slider_on';
		}
		
		if(isset($qode_pitch_options['vertical_area_background_transparency']) && $qode_pitch_options['vertical_area_background_transparency'] !=='' && $qode_pitch_options['vertical_area_background_transparency'] !=='1' && get_post_meta($id, "qode_page_vertical_area_background_opacity", true) == "" && isset($qode_pitch_options['vertical_area_dropdown_showing']) && $qode_pitch_options['vertical_area_dropdown_showing'] != "side"){
			$classes[] = 'vertical_menu_background_opacity';
		}else if(get_post_meta($id, "qode_page_vertical_area_background_opacity", true) !== "" && get_post_meta($id, "qode_page_vertical_area_background_opacity", true) !== "1" && isset($qode_pitch_options['vertical_area_dropdown_showing']) && $qode_pitch_options['vertical_area_dropdown_showing'] != "side"){
			$classes[] = ' vertical_menu_background_opacity';
		}

		if(isset($qode_pitch_options['vertical_area_dropdown_showing']) && $qode_pitch_options['vertical_area_dropdown_showing'] != "to_content"){
			$classes[] = ' vertical_menu_with_scroll';
		}

		
		return $classes;
	}

	add_filter('body_class', 'qode_pitch_vertical_menu_class');
}

if (!function_exists('qode_pitch_smooth_scroll_class')) {
    /**
     * Function that adds classes on body for smooth scroll
     */
    function qode_pitch_smooth_scroll_class($classes) {
        global $qode_pitch_options;
		
		$mac_os = strpos($_SERVER['HTTP_USER_AGENT'], "Macintosh; Intel Mac OS X");

        //is smooth_scroll turned on?
        if(isset($qode_pitch_options['smooth_scroll']) && $qode_pitch_options['smooth_scroll'] == "yes" && $mac_os == false) {
            $classes[] = 'smooth_scroll';
        } else {
            $classes[] ="";
        }

        return $classes;
    }

    add_filter('body_class', 'qode_pitch_smooth_scroll_class');
}

if(!function_exists('qode_pitch_wp_title_text')) {
	/**
	 * Function that sets page's title. Hooks to wp_title filter
	 * @param $title string current page title
	 * @param $sep string title separator
	 * @return string changed title text if SEO plugins aren't installed
	 */
	function qode_pitch_wp_title_text($title, $sep) {
		global $qode_pitch_options;

		//is SEO plugin installed?
		if(qode_pitch_seo_plugin_installed()) {
			//don't do anything, seo plugin will take care of it
		} else {
			//get current post id
            $id = qode_pitch_get_page_id();
			$sep = ' | ';
			$title_prefix = get_bloginfo('name');
			$title_suffix = '';

			//is WooCommerce installed and is current page shop page?
			if(qode_pitch_is_woocommerce_installed() && qode_pitch_is_woocommerce_shop()) {
				//get shop page id
				$id = qode_pitch_get_woo_shop_page_id();
			}

            //is WP 4.1 at least?
            if(function_exists('_wp_render_title_tag')) {
                //set unchanged title variable so we can use it later
                $title_array = explode($sep, $title);
                $unchanged_title = array_shift($title_array);
            }

            //pre 4.1 version of WP
            else {
                //set unchanged title variable so we can use it later
                $unchanged_title = $title;
            }

			//is qode seo enabled?
			if(isset($qode_pitch_options['disable_qode_seo']) && $qode_pitch_options['disable_qode_seo'] !== 'yes') {
				//get current post seo title
				$seo_title = esc_attr(get_post_meta($id, "qode_seo_title", true));

				//is current post seo title set?
				if($seo_title !== '') {
					$title_suffix = $seo_title;
				}
			}

			//title suffix is empty, which means that it wasn't set by qode seo
			if(empty($title_suffix)) {
				//if current page is front page append site description, else take original title string
				$title_suffix = is_front_page() ? get_bloginfo('description') : $unchanged_title;
			}

			//concatenate title string
			$title  = $title_prefix.$sep.$title_suffix;

			//return generated title string
			return $title;
		}
	}

	add_filter('wp_title', 'qode_pitch_wp_title_text', 10, 2);
}

if(!function_exists('qode_pitch_wp_title')) {
    /**
     * Function that outputs title tag. It checks if _wp_render_title_tag function exists
     * and if it does'nt it generates output. Compatible with versions of WP prior to 4.1
     */
    function qode_pitch_wp_title() {
        if(!function_exists('_wp_render_title_tag')) { ?>
            <title><?php wp_title(''); ?></title>
        <?php }
    }
}

if(!function_exists('qode_pitch_ajax_meta')) {
	/**
	 * Function that echoes meta data for ajax
	 *
	 * @since 4.3
	 * @version 0.2
	 */
	function qode_pitch_ajax_meta() {
		global $qode_pitch_options;
		
		$seo_description = get_post_meta(qode_pitch_get_page_id(), "qode_seo_description", true);
		$seo_keywords = get_post_meta(qode_pitch_get_page_id(), "qode_seo_keywords", true);
		?>

        <div class="seo_title"><?php wp_title('|', true, 'right'); ?></div>

		<?php if($seo_description !== ''){ ?>
			<div class="seo_description"><?php echo esc_html($seo_description); ?></div>
		<?php } else if($qode_pitch_options['meta_description']){?>
			<div class="seo_description"><?php echo esc_html($qode_pitch_options['meta_description']); ?></div>
		<?php } ?>
		<?php if($seo_keywords !== ''){ ?>
			<div class="seo_keywords"><?php echo esc_html($seo_keywords); ?></div>
		<?php }else if($qode_pitch_options['meta_keywords']){?>
			<div class="seo_keywords"><?php echo esc_html($qode_pitch_options['meta_keywords']); ?></div>
		<?php }
	}

	add_action('qode_pitch_ajax_meta', 'qode_pitch_ajax_meta');
}

if(!function_exists('qode_pitch_header_meta')) {
	/**
	 * Function that echoes meta data if our seo is enabled
	 */
	function qode_pitch_header_meta() {
		global $qode_pitch_options;
		
		if(qode_pitch_is_seo_enabled()) {
			$seo_description = get_post_meta(qode_pitch_get_page_id(), "qode_seo_description", true);
			$seo_keywords = get_post_meta(qode_pitch_get_page_id(), "qode_seo_keywords", true);
			?>

			<?php if($seo_description) { ?>
				<meta name="description" content="<?php echo esc_html($seo_description); ?>">
			<?php } else if($qode_pitch_options['meta_description']){ ?>
				<meta name="description" content="<?php echo esc_html($qode_pitch_options['meta_description']) ?>">
			<?php } ?>

			<?php if($seo_keywords) { ?>
				<meta name="keywords" content="<?php echo esc_html($seo_keywords); ?>">
			<?php } else if($qode_pitch_options['meta_keywords']){ ?>
				<meta name="keywords" content="<?php echo esc_html($qode_pitch_options['meta_keywords']) ?>">
			<?php }
		}

		if(qode_pitch_is_ios_format_detection_disabled()){ ?>
			<meta name="format-detection" content="telephone=no">
		<?php } ?>

        <meta charset="<?php bloginfo( 'charset' ); ?>" />
        <?php
        if (isset($_SERVER['HTTP_USER_AGENT']) && (strpos($_SERVER['HTTP_USER_AGENT'], 'MSIE') !== false))
            echo('<meta content="IE=edge,chrome=1" http-equiv="X-UA-Compatible">');
        ?>

        <link rel="profile" href="http://gmpg.org/xfn/11" />
        <link rel="pingback" href="<?php bloginfo( 'pingback_url' ); ?>" />
		
		<?php if ( ! function_exists( 'has_site_icon' ) || ! has_site_icon() ) { ?>
			<link rel="shortcut icon" type="image/x-icon" href="<?php echo esc_url($qode_pitch_options['favicon_image']); ?>">
			<link rel="apple-touch-icon" href="<?php echo esc_url($qode_pitch_options['favicon_image']); ?>"/>
		<?php } ?>
	<?php }

	add_action('qode_pitch_header_meta', 'qode_pitch_header_meta');
}

if(!function_exists('qode_pitch_user_scalable_meta')) {
    /**
     * Function that outputs user scalable meta if responsiveness is turned on
     * Hooked to qode_pitch_header_meta action
     */
    function qode_pitch_user_scalable_meta() {
        //is responsiveness option is chosen?
        if (qode_pitch_is_responsive_on()) { ?>
            <meta name="viewport" content="width=device-width,initial-scale=1,user-scalable=no">
        <?php }	else { ?>
            <meta name="viewport" content="width=1200,user-scalable=no">
        <?php }
    }

    add_action('qode_pitch_header_meta', 'qode_pitch_user_scalable_meta');
}

if(!function_exists('qode_pitch_get_page_id')) {
	/**
	 * Function that returns current page / post id.
	 * Checks if current page is woocommerce page and returns that id if it is.
	 * Checks if current page is any archive page (category, tag, date, author etc.) and returns -1 because that isn't
	 * page that is created in WP admin.
	 *
	 * @return int
	 *
	 * @version 0.1
	 *
	 * @see qode_pitch_is_woocommerce_installed()
	 * @see qode_pitch_is_woocommerce_shop()
	 */
	function qode_pitch_get_page_id() {
		if(qode_pitch_is_woocommerce_installed() && (qode_pitch_is_woocommerce_shop() || is_singular('product'))) {
			return qode_pitch_get_woo_shop_page_id();
		}

		if(is_archive() || is_search() || is_404()) {
			return -1;
		}

		return get_queried_object_id();
	}
}



if (!function_exists('qode_pitch_elements_animation_on_touch_class')) {
	/**
	 * Function that adds classes on body when touch is disabled on touch devices
	 * @param $classes array classes array
	 * @return array array with added classes
	 */
	function qode_pitch_elements_animation_on_touch_class($classes) {
		global $qode_pitch_options;

		//check if current client is on mobile
		$isMobile = (bool)preg_match('#\b(ip(hone|od|ad)|android|opera m(ob|in)i|windows (phone|ce)|blackberry|tablet'.
			'|s(ymbian|eries60|amsung)|p(laybook|alm|rofile/midp|laystation portable)|nokia|fennec|htc[\-_]'.
			'|mobile|up\.browser|[1-4][0-9]{2}x[1-4][0-9]{2})\b#i', $_SERVER['HTTP_USER_AGENT'] );

		//are animations turned off on touch and client is on mobile?
		if(isset($qode_pitch_options['elements_animation_on_touch']) && $qode_pitch_options['elements_animation_on_touch'] == "no" && $isMobile == true) {
			$classes[] = 'no_animation_on_touch';
		} else {
			$classes[] ="";
		}

		return $classes;
	}

	add_filter('body_class', 'qode_pitch_elements_animation_on_touch_class');
}

if(!function_exists('qode_pitch_side_menu_body_class')) {
	/**
	 * Function that adds body classes for different side menu styles
	 * @param $classes array original array of body classes
	 * @return array modified array of classes
	 */
    function qode_pitch_side_menu_body_class($classes) {
            global $qode_pitch_options;

			if(isset($qode_pitch_options['enable_side_area']) && $qode_pitch_options['enable_side_area'] == 'yes') {
					if(isset($qode_pitch_options['side_area_type']) && $qode_pitch_options['side_area_type'] == 'side_menu_slide_from_right') {
						$classes[] = 'side_menu_slide_from_right';
					}

					else if(isset($qode_pitch_options['side_area_type']) && $qode_pitch_options['side_area_type'] == 'side_menu_slide_with_content') {
						$classes[] = 'side_menu_slide_with_content';
						$classes[] = $qode_pitch_options['side_area_slide_with_content_width'];
				   }
				   
				   if(isset($qode_pitch_options['side_area_type']) && $qode_pitch_options['side_area_type'] == 'side_area_uncovered_from_content') {
						$classes[] = 'side_area_uncovered_from_content';
					}
			}

        return $classes;
    }

    add_filter('body_class', 'qode_pitch_side_menu_body_class');
}

if(!function_exists('qode_pitch_top_menu_body_class')) {
	/**
	 * Function that adds body classes for different side menu styles
	 * @param $classes array original array of body classes
	 * @return array modified array of classes
	 */
    function qode_pitch_top_menu_body_class($classes) {
            global $qode_pitch_options;

			if(isset($qode_pitch_options['menu_appearance']) && $qode_pitch_options['menu_appearance'] != 'default') {
				$classes[] = $qode_pitch_options['menu_appearance'];
			}

        return $classes;
    }

    add_filter('body_class', 'qode_pitch_top_menu_body_class');
}


if(!function_exists('qode_pitch_full_screen_menu_body_class')) {
    /**
     * Function that adds body classes for different full screen menu types
     * @param $classes array original array of body classes
     * @return array modified array of classes
     */
    function qode_pitch_full_screen_menu_body_class($classes) {
        global $qode_pitch_options;

        if(isset($qode_pitch_options['enable_popup_menu']) && $qode_pitch_options['enable_popup_menu'] == 'yes') {
            if(isset($qode_pitch_options['popup_menu_animation_style'])) {
                $classes[] = $qode_pitch_options['popup_menu_animation_style'];
            }
        }

        return $classes;
    }

    add_filter('body_class', 'qode_pitch_full_screen_menu_body_class');
}

if(!function_exists('qode_pitch_paspartu_body_class')) {
    /**
    * Function that adds paspartu class to body.
    * @param $classes array of body classes
    * @return array with paspartu body class added
    */
    function qode_pitch_paspartu_body_class($classes) {
        global $qode_pitch_options;

        if(isset($qode_pitch_options['paspartu']) && $qode_pitch_options['paspartu'] == 'yes') {
			$classes[] = 'paspartu_enabled';
			
			if((isset($qode_pitch_options['paspartu_on_top']) && $qode_pitch_options['paspartu_on_top'] == 'yes' && isset($qode_pitch_options['paspartu_on_top_fixed']) && $qode_pitch_options['paspartu_on_top_fixed'] == 'yes') ||
			(qode_pitch_is_side_header() && isset($qode_pitch_options['vertical_menu_inside_paspartu']) && $qode_pitch_options['vertical_menu_inside_paspartu'] == 'yes')) {
				$classes[] = 'paspartu_on_top_fixed';
			}
			
			if(($qode_pitch_options['paspartu_on_bottom'] == 'yes' && $qode_pitch_options['paspartu_on_bottom_fixed'] == 'yes') ||
			(qode_pitch_is_side_header() && isset($qode_pitch_options['vertical_menu_inside_paspartu']) && $qode_pitch_options['vertical_menu_inside_paspartu'] == 'yes')) {
				$classes[] = 'paspartu_on_bottom_fixed';
			}
			
			if(isset($qode_pitch_options['paspartu_header_alignment']) && $qode_pitch_options['paspartu_header_alignment'] == 'yes'){
				$classes[] = 'paspartu_header_aligned';
			}

			if(isset($qode_pitch_options['paspartu_header_inside']) && $qode_pitch_options['paspartu_header_inside'] == 'yes'){
				$classes[] = 'paspartu_header_set_inside';
			}
			
			if(qode_pitch_is_side_header() && isset($qode_pitch_options['vertical_menu_inside_paspartu']) && $qode_pitch_options['vertical_menu_inside_paspartu'] == 'no') {
				$classes[] = 'vertical_menu_outside_paspartu';
			}
			
			if(qode_pitch_is_side_header() && isset($qode_pitch_options['vertical_menu_inside_paspartu']) && $qode_pitch_options['vertical_menu_inside_paspartu'] == 'yes') {
				$classes[] = 'vertical_menu_inside_paspartu';
			}
			
			if($qode_pitch_options['paspartu_border_on_edges'] == 'yes' &&
				$qode_pitch_options['paspartu_on_top'] == 'yes' && $qode_pitch_options['paspartu_on_top_fixed'] == 'yes' &&
				$qode_pitch_options['paspartu_on_bottom'] == 'yes' && $qode_pitch_options['paspartu_on_bottom_fixed'] == 'yes' ) {
				$classes[] = 'paspartu_border_on_edges';
			}
        }

        return $classes;
    }

    add_filter('body_class', 'qode_pitch_paspartu_body_class');
}

if(!function_exists('qode_pitch_transparent_content_body_class')) {
    /**
     * Function that adds transparent content class to body.
     * @param $classes array of body classes
     * @return array with transparent content body class added
     */
    function qode_pitch_transparent_content_body_class($classes) {
        global $qode_pitch_options;

        if(isset($qode_pitch_options['transparent_content']) && $qode_pitch_options['transparent_content'] == 'yes') {
            $classes[] = 'transparent_content';
        }

        return $classes;
    }

    add_filter('body_class', 'qode_pitch_transparent_content_body_class');
}

if(!function_exists('qode_pitch_overlapping_content_body_class')) {
    /**
     * Function that adds transparent content class to body.
     * @param $classes array of body classes
     * @return array with transparent content body class added
     */
    function qode_pitch_overlapping_content_body_class($classes) {
        global $qode_pitch_options;

        if(isset($qode_pitch_options['overlapping_content']) && $qode_pitch_options['overlapping_content'] == 'yes') {
            $classes[] = 'overlapping_content';

            if(isset($qode_pitch_options['animate_overlapping_content']) && $qode_pitch_options['animate_overlapping_content'] == 'yes') {
                $classes[] = 'animate_overlapping_content';
            }

            if(isset($qode_pitch_options['frame_around_overlapping_content']) && $qode_pitch_options['frame_around_overlapping_content'] == 'yes') {
                $classes[] = 'frame_around_overlapping_content';
            }
        }

        return $classes;
    }

    add_filter('body_class', 'qode_pitch_overlapping_content_body_class');
}

if(!function_exists('qode_pitch_content_initial_width_body_class')) {
    /**
     * Function that adds transparent content class to body.
     * @param $classes array of body classes
     * @return array with transparent content body class added
     */
    function qode_pitch_content_initial_width_body_class($classes) {
        global $qode_pitch_options;

        if(isset($qode_pitch_options['content_predefined_width']) && $qode_pitch_options['content_predefined_width'] !== '') {
            $classes[] = $qode_pitch_options['content_predefined_width'];
        }

        return $classes;
    }

    add_filter('body_class', 'qode_pitch_content_initial_width_body_class');
}

if(!function_exists('qode_pitch_set_woocommerce_body_class')) {
    /**
     * Function that adds woocommerce class to body if woocommerce is installed.
     * @param $classes array of body classes
     * @return array with woocommerce body class added
     */
    function qode_pitch_set_woocommerce_body_class($classes) {

        if(qode_pitch_is_woocommerce_installed()){
            $classes[] = "woocommerce_installed";
        }
		
        return $classes;
		
    }

    add_filter('body_class', 'qode_pitch_set_woocommerce_body_class');
}

if(!function_exists('qode_pitch_set_blog_body_class')) {
    /**
     * Function that adds blog class to body if blog template, shortcodes or widgets are used on site.
     * @param $classes array of body classes
     * @return array with blog body class added
     */
    function qode_pitch_set_blog_body_class($classes) {

        if(qode_pitch_load_blog_assets()){
            $classes[] = "blog_installed";
        }
		
        return $classes;
		
    }

    add_filter('body_class', 'qode_pitch_set_blog_body_class');
}

if(!function_exists('qode_pitch_hide_initial_sticky_body_class')) {
    /**
     * Function that adds hidden initial sticky class to body.
     * @param $classes array of body classes
     * @return hidden initial sticky body class
     */
    function qode_pitch_hide_initial_sticky_body_class($classes) {
        global $qode_pitch_options;

        if(isset($qode_pitch_options['header_bottom_appearance']) && ($qode_pitch_options['header_bottom_appearance'] == "stick" || $qode_pitch_options['header_bottom_appearance'] == "stick menu_bottom" || $qode_pitch_options['header_bottom_appearance'] == "stick_with_left_right_menu" || $qode_pitch_options['header_bottom_appearance'] == "stick compound")){
			if(get_post_meta(qode_pitch_get_page_id(), "qode_page_hide_initial_sticky", true) !== ''){
				if(get_post_meta(qode_pitch_get_page_id(), "qode_page_hide_initial_sticky", true) == 'yes'){
					$classes[] = 'hide_inital_sticky';
				}
			}else if(isset($qode_pitch_options['hide_initial_sticky']) && $qode_pitch_options['hide_initial_sticky'] == 'yes') {
				$classes[] = 'hide_inital_sticky';
			}
        }

        return $classes;
    }

    add_filter('body_class', 'qode_pitch_hide_initial_sticky_body_class');
}

if(!function_exists('qode_pitch_full_screen_sections_on_small_screens_class')) {
    /**
     * Function that adds full screen section class for small screens to body.
     * @param $classes array of body classes
     * @return full screen section class for small screens body class
     */
    function qode_pitch_full_screen_sections_on_small_screens_class($classes) {
        global $qode_pitch_options;
        
		if(get_post_meta(qode_pitch_get_page_id(), "qode_full_screen_sections_on_small_screens", true) !== ''){
			if(get_post_meta(qode_pitch_get_page_id(), "qode_full_screen_sections_on_small_screens", true) == 'yes'){
				$classes[] = 'enable_full_screen_sections_on_small_screens';
			}
		}else if(isset($qode_pitch_options['full_screen_sections_on_small_screens']) && $qode_pitch_options['full_screen_sections_on_small_screens'] == 'yes') {
			$classes[] = 'enable_full_screen_sections_on_small_screens';
		}        

        return $classes;
    }

    add_filter('body_class', 'qode_pitch_full_screen_sections_on_small_screens_class');
}

if(!function_exists('qode_pitch_set_logo_sizes')) {
	/**
	 * Function that sets logo image dimensions to global qode options array so it can be used in the theme
	 */
	function qode_pitch_set_logo_sizes() {
		global $qode_pitch_options;

		if (!empty($qode_pitch_options['logo_image'])){
			//get logo image size
			$logo_image_sizes = qode_pitch_get_image_dimensions($qode_pitch_options['logo_image']);
			$qode_pitch_options['logo_width'] = 280;
			$qode_pitch_options['logo_height'] = 130;
	
			//is image width and height set?
			if(isset($logo_image_sizes['width']) && isset($logo_image_sizes['height'])) {
				//set those variables in global array
				$qode_pitch_options['logo_width'] = $logo_image_sizes['width'];
				$qode_pitch_options['logo_height'] = $logo_image_sizes['height'];
			}
		}
	}

	add_action('init', 'qode_pitch_set_logo_sizes', 0);
}


if(!function_exists('qode_pitch_is_default_wp_template')) {
	/**
	 * Function that checks if current page archive page, search, 404 or default home blog page
	 * @return bool
	 *
	 * @see is_archive()
	 * @see is_search()
	 * @see is_404()
	 * @see is_front_page()
	 * @see is_home()
	 */
	function qode_pitch_is_default_wp_template() {
		return is_archive() || is_search() || is_404() || (is_front_page() && is_home());
	}
}

if(!function_exists('qode_pitch_get_page_template_name')) {
	/**
	 * Returns current template file name without extension
	 * @return string name of current template file
	 */
	function qode_pitch_get_page_template_name() {
		$file_name = '';

		if(!qode_pitch_is_default_wp_template()) {
			$file_name_without_ext = preg_replace('/\\.[^.\\s]{3,4}$/', '', basename(get_page_template()));

			if($file_name_without_ext !== '') {
				$file_name = $file_name_without_ext;
			}
		}

		return $file_name;
	}
}

if(!function_exists('qode_pitch_is_main_menu_set')) {
    /**
     * Function that checks if any of main menu locations are set.
     * Checks whether top-navigation location is set, or left-top-navigation and right-top-navigation is set
     * @return bool
     *
     * @version 0.1
     */
    function qode_pitch_is_main_menu_set() {
        $has_top_nav = has_nav_menu('top-navigation');
        $has_divided_nav = has_nav_menu('left-top-navigation') && has_nav_menu('right-top-navigation');

        return $has_top_nav || $has_divided_nav;
    }
}

if(!function_exists('qode_pitch_has_shortcode')) {
	/**
	 * Function that checks whether shortcode exists on current page / post
	 * @param string shortcode to find
	 * @param string content to check. If isn't passed current post content will be used
	 * @return bool whether content has shortcode or not
	 */
	function qode_pitch_has_shortcode($shortcode, $content = '')
	{
		$has_shortcode = false;

		if ($shortcode) {
			//if content variable isn't past
			if ($content == '') {
				//take content from current post
				$page_id = qode_pitch_get_page_id();
				if (!empty($page_id)) {
					$current_post = get_post($page_id);

					if (is_object($current_post) && property_exists($current_post, 'post_content')) {
						$content = $current_post->post_content;
					}

				}
			}

			//does content has shortcode added?
			if (stripos($content, '[' . $shortcode) !== false) {
				$has_shortcode = true;
			}
		}

		return $has_shortcode;
	}
}

if(!function_exists('qode_pitch_is_ajax')) {
    /**
     * Function that checks if current request is ajax request
     * @return bool whether it's ajax request or not
     *
     * @version 0.1
     */
    function qode_pitch_is_ajax() {
        return !empty( $_SERVER[ 'HTTP_X_REQUESTED_WITH' ]) && strtolower( $_SERVER[ 'HTTP_X_REQUESTED_WITH' ]) == 'xmlhttprequest';
    }
}

if(!function_exists('qode_pitch_localize_no_ajax_pages')) {
    /**
     * Function that outputs no_ajax_obj javascript variable that is used default_dynamic.php.
     * It is used for no ajax pages functionality
     *
     * Function hooks to wp_enqueue_scripts and uses wp_localize_script
     *
     * @see http://codex.wordpress.org/Function_Reference/wp_localize_script
     *
     * @uses qode_get_posts_without_ajax()
     * @uses qode_get_pages_without_ajax()
     * @uses qode_pitch_get_wpml_pages_for_current_page()
     * @uses qode_pitch_get_woocommerce_pages()
     *
     * @version 0.1
     */
    function qode_pitch_localize_no_ajax_pages() {
        global $qode_pitch_options;

        //is ajax enabled?
        if(qode_pitch_is_ajax_enabled()) {
            $no_ajax_pages = array();

            //get posts that have ajax disabled and merge with main array
            $no_ajax_pages = array_merge($no_ajax_pages, qode_pitch_get_objects_without_ajax());

            //is wpml installed?
            if(qode_pitch_is_wpml_installed()) {
                //get translation pages for current page and merge with main array
                $no_ajax_pages = array_merge($no_ajax_pages, qode_pitch_get_wpml_pages_for_current_page());
            }

            //is woocommerce installed?
            if(qode_pitch_is_woocommerce_installed()) {
                //get all woocommerce pages and products and merge with main array
                $no_ajax_pages = array_merge($no_ajax_pages, qode_pitch_get_woocommerce_pages());
            }

			//is login page set
			if (isset($qode_pitch_options['qode_enable_login_page']) && $qode_pitch_options['qode_enable_login_page'] == 'yes' && isset($qode_pitch_options['qode_login_page']) && $qode_pitch_options['qode_login_page'] != "") {
				$no_ajax_pages[] = get_permalink($qode_pitch_options['qode_login_page']);
			}

            //do we have some internal pages that won't to be without ajax?
            if (isset($qode_pitch_options['internal_no_ajax_links'])) {
                //get array of those pages
                $options_no_ajax_pages_array = explode(',', $qode_pitch_options['internal_no_ajax_links']);

                if(is_array($options_no_ajax_pages_array) && count($options_no_ajax_pages_array)) {
                    $no_ajax_pages = array_merge($no_ajax_pages, $options_no_ajax_pages_array);
                }
            }

            //add logout url to main array
            $no_ajax_pages[] = htmlspecialchars_decode(wp_logout_url());

            //finally localize script so we can use it in default_dynamic
            wp_localize_script( 'qode_pitch_default_dynamic', 'no_ajax_obj', array(
                'no_ajax_pages' => $no_ajax_pages
            ));
        }
    }

    add_action('wp_enqueue_scripts', 'qode_pitch_localize_no_ajax_pages');
}

if(!function_exists('qode_pitch_get_objects_without_ajax')) {
    /**
     * Function that returns urls of objects that have ajax disabled.
     * Works for posts, pages and portfolio pages.
     * @return array array of urls of posts that have ajax disabled
     *
     * @version 0.1
     */
    function qode_pitch_get_objects_without_ajax() {
        $posts_without_ajax = array();

        $posts_args =  array(
            'post_type'  => array('post', 'portfolio_page', 'page'),
            'post_status' => 'publish',
            'meta_key' => 'qode_show-animation',
            'meta_value' => 'no_animation'
        );

        $posts_query = new WP_Query($posts_args);

        if($posts_query->have_posts()) {
            while($posts_query->have_posts()) {
                $posts_query->the_post();
                $posts_without_ajax[] = get_permalink(get_the_ID());
            }
        }

        wp_reset_postdata();

        return $posts_without_ajax;
    }
}

if(!function_exists('qode_pitch_is_ajax_enabled')) {
    /**
     * Function that checks if ajax is enabled.
     * @return bool
     *
     * @version 0.1
     */
    function qode_pitch_is_ajax_enabled() {
        global $qode_pitch_options;

        $has_ajax = false;

        if(isset($qode_pitch_options['page_transitions']) && $qode_pitch_options['page_transitions'] !== '0') {
            $has_ajax = true;
        }

        return $has_ajax;
    }
}

if(!function_exists('qode_pitch_is_ajax_header_animation_enabled')) {
    /**
     * Function that checks if header animation with ajax is enabled.
     * @return boolean
     *
     * @version 0.1
     */
    function qode_pitch_is_ajax_header_animation_enabled() {
        global $qode_pitch_options;

        $has_header_animation = false;

        if(isset($qode_pitch_options['page_transitions']) && $qode_pitch_options['page_transitions'] !== '0' && isset($qode_pitch_options['ajax_animate_header']) && $qode_pitch_options['ajax_animate_header'] == 'yes') {
            $has_header_animation = true;
        }

        return $has_header_animation;
    }
}

if(!function_exists('qode_pitch_maintenance_mode')) {
    /**
     * Function that redirects user to desired landing page if maintenance mode is turned on in options
     */
    function qode_pitch_maintenance_mode() {
        global $qode_pitch_options;

        $protocol = is_ssl() ? "https://" : "http://";
        if(isset($qode_pitch_options['qode_maintenance_mode']) && $qode_pitch_options['qode_maintenance_mode'] == 'yes' && isset($qode_pitch_options['qode_maintenance_page']) && $qode_pitch_options['qode_maintenance_page'] != ""
            && !in_array($GLOBALS['pagenow'], array('wp-login.php', 'wp-register.php'))
            && !is_admin()
            && !is_user_logged_in()
            && $protocol.$_SERVER['HTTP_HOST'].$_SERVER['REQUEST_URI'] != get_permalink($qode_pitch_options['qode_maintenance_page'])
        ) {

            wp_redirect(get_permalink($qode_pitch_options['qode_maintenance_page']));
            exit;
        }
    }
}

if(!function_exists('qode_pitch_initial_maintenance')) {
	/**
	 * Function that initalize maintenance function
	 */
	function qode_pitch_initial_maintenance() {
		global $qode_pitch_options;

		if(isset($qode_pitch_options['qode_maintenance_mode']) && $qode_pitch_options['qode_maintenance_mode'] == 'yes') {
			add_action('init', 'qode_pitch_maintenance_mode', 2);
		}
	}

	add_action('init', 'qode_pitch_initial_maintenance', 1);
}

if(!function_exists('qode_pitch_horizontal_slider_icon_classes')) {
	/**
	 * Returns classes for left and right arrow for sliders
	 *
	 * @param $icon_class
	 * @return array
	 */
	function qode_pitch_horizontal_slider_icon_classes($icon_class) {

		switch($icon_class) {
			case 'arrow_carrot-left_alt2':
				$left_icon_class = 'arrow_carrot-left_alt2';
				$right_icon_class = 'arrow_carrot-right_alt2';
				break;
			case 'arrow_carrot-2left_alt2':
				$left_icon_class = 'arrow_carrot-2left_alt2';
				$right_icon_class = 'arrow_carrot-2right_alt2';
				break;
			case 'arrow_triangle-left_alt2':
				$left_icon_class = 'arrow_triangle-left_alt2';
				$right_icon_class = 'arrow_triangle-right_alt2';
				break;
			case 'icon-arrows-drag-left-dashed':
				$left_icon_class = 'icon-arrows-drag-left-dashed';
				$right_icon_class = 'icon-arrows-drag-right-dashed';
				break;
			case 'icon-arrows-drag-left-dashed':
				$left_icon_class = 'icon-arrows-drag-left-dashed';
				$right_icon_class = 'icon-arrows-drag-right-dashed';
				break;
			case 'icon-arrows-left-double-32':
				$left_icon_class = 'icon-arrows-left-double-32';
				$right_icon_class = 'icon-arrows-right-double';
				break;
			case 'icon-arrows-slide-left1':
				$left_icon_class = 'icon-arrows-slide-left1';
				$right_icon_class = 'icon-arrows-slide-right1';
				break;
			case 'icon-arrows-slide-left2':
				$left_icon_class = 'icon-arrows-slide-left2';
				$right_icon_class = 'icon-arrows-slide-right2';
				break;
			case 'icon-arrows-slim-left-dashed':
				$left_icon_class = 'icon-arrows-slim-left-dashed';
				$right_icon_class = 'icon-arrows-slim-right-dashed';
				break;
			case 'ion-arrow-left-a':
				$left_icon_class = 'ion-arrow-left-a';
				$right_icon_class = 'ion-arrow-right-a';
				break;
			case 'ion-arrow-left-b':
				$left_icon_class = 'ion-arrow-left-b';
				$right_icon_class = 'ion-arrow-right-b';
				break;
			case 'ion-arrow-left-c':
				$left_icon_class = 'ion-arrow-left-c';
				$right_icon_class = 'ion-arrow-right-c';
				break;
			case 'ion-ios-arrow-':
				$left_icon_class = $icon_class.'back';
				$right_icon_class = $icon_class.'forward';
				break;
			case 'ion-ios-fastforward':
				$left_icon_class = 'ion-ios-rewind';
				$right_icon_class = 'ion-ios-fastforward';
				break;
			case 'ion-ios-fastforward-outline':
				$left_icon_class = 'ion-ios-rewind-outline';
				$right_icon_class = 'ion-ios-fastforward-outline';
				break;
			case 'ion-ios-skipbackward':
				$left_icon_class = 'ion-ios-skipbackward';
				$right_icon_class = 'ion-ios-skipforward';
				break;
			case 'ion-ios-skipbackward-outline':
				$left_icon_class = 'ion-ios-skipbackward-outline';
				$right_icon_class = 'ion-ios-skipforward-outline';
				break;
			case 'ion-android-arrow-':
				$left_icon_class = $icon_class.'back';
				$right_icon_class = $icon_class.'forward';
				break;
			case 'ion-android-arrow-dropleft-circle':
				$left_icon_class = 'ion-android-arrow-dropleft-circle';
				$right_icon_class = 'ion-android-arrow-dropright-circle';
				break;
			default:
				$left_icon_class = $icon_class.'left';
				$right_icon_class = $icon_class.'right';
		}

		$icon_classes = array(
			'left_icon_class' => $left_icon_class,
			'right_icon_class' => $right_icon_class
		);

    	return $icon_classes;

	}

}

if(!function_exists('qode_pitch_get_side_menu_icon_html')) {
	/**
	 * Function that outputs html for side area icon opener.
	 * Uses $qode_pitch_IconCollections global variable
	 * @return string generated html
	 */
	function qode_pitch_get_side_menu_icon_html() {
		global $qode_pitch_IconCollections, $qode_pitch_options;

		$icon_html = '';

		if(isset($qode_pitch_options['side_area_button_icon_pack']) && $qode_pitch_options['side_area_button_icon_pack'] !== '') {
			$icon_pack = $qode_pitch_options['side_area_button_icon_pack'];
			if ($icon_pack !== '') {
				$icon_collection_obj = $qode_pitch_IconCollections->getIconCollection($icon_pack);
				$icon_field_name = 'side_area_icon_'. $icon_collection_obj->param;

				if(isset($qode_pitch_options[$icon_field_name]) && $qode_pitch_options[$icon_field_name] !== ''){
					$icon_single = $qode_pitch_options[$icon_field_name];

					if (method_exists($icon_collection_obj, 'render')) {
						$icon_html = $icon_collection_obj->render($icon_single);
					}
				}
			}
		}

		return $icon_html;
	}
}

if(!function_exists('qode_pitch_rewrite_rules_on_theme_activation')) {
	/**
	 * Function that flushes rewrite rules on deactivation
	 */
	function qode_pitch_rewrite_rules_on_theme_activation() {
		flush_rewrite_rules();
	}

	add_action( 'after_switch_theme', 'qode_pitch_rewrite_rules_on_theme_activation' );
}

if (!function_exists('qode_pitch_vc_grid_elements_enabled')) {

	/**
	 * Function that checks if Visual Composer Grid Elements are enabled
	 *
	 * @return bool
	 */
	function qode_pitch_vc_grid_elements_enabled() {

		global $qode_pitch_options;
		$vc_grid_enabled = false;

		if (isset($qode_pitch_options['enable_grid_elements']) && $qode_pitch_options['enable_grid_elements'] == 'yes') {

			$vc_grid_enabled = true;

		}

		return $vc_grid_enabled;

	}

}

if(!function_exists('qode_pitch_visual_composer_grid_elements')) {

	/**
	 * Removes Visual Composer Grid Elements post type if VC Grid option disabled
	 * and enables Visual Composer Grid Elements post type
	 * if VC Grid option enabled
	 */
	function qode_pitch_visual_composer_grid_elements() {

		if(!qode_pitch_vc_grid_elements_enabled()){

			remove_action( 'init', 'vc_grid_item_editor_create_post_type' );

		}
	}

	add_action('vc_after_init', 'qode_pitch_visual_composer_grid_elements', 12);
}

if(!function_exists('qode_pitch_grid_elements_ajax_disable')) {
	/**
	 * Function that disables ajax transitions if grid elements are enabled in theme options
	 */
	function qode_pitch_grid_elements_ajax_disable() {
		global $qode_pitch_options;

		if(qode_pitch_vc_grid_elements_enabled()) {
			$qode_pitch_options['page_transitions'] = '0';
		}
	}

	add_action('wp', 'qode_pitch_grid_elements_ajax_disable');
}


if(!function_exists('qode_pitch_get_vc_version')) {
	/**
	 * Return Visual Composer version string
	 *
	 * @return bool|string
	 */
	function qode_pitch_get_vc_version() {
		if(qode_pitch_visual_composer_installed()) {
			return WPB_VC_VERSION;
		}

		return false;
	}
}

if(!function_exists('qode_pitch_get_dynamic_sidebar')){
	/**
	 * Return Custom Widget Area content
	 *
	 * @return string
	 */
	function qode_pitch_get_dynamic_sidebar($index = 1){
		$sidebar_contents = "";
		ob_start();
		dynamic_sidebar($index);
		$sidebar_contents = ob_get_clean();
		return $sidebar_contents;
	}
}

if(!function_exists('qode_pitch_attachment_field_custom_size')) {

	function qode_pitch_attachment_field_custom_size($form_fields, $post)
	{
		$field_value = get_post_meta($post->ID, 'qode_portfolio_single_predefined_size', true);
		$form_fields['qode_portfolio_single_predefined_size'] = array(
			'label' => 'Masonry Size',
			'input' => 'text',
			'value' => $field_value ? $field_value : ''
		);
		$form_fields["qode_portfolio_single_predefined_size"]["extra_rows"] = array(
			"row1" => "Enter 'large' (twice the size of default image) or 'huge' (three times the size of default image) for Masonry Gallery templates on Portfolio Single Pages."
		);

		return $form_fields;
	}
}

add_filter( 'attachment_fields_to_edit', 'qode_pitch_attachment_field_custom_size', 10, 2 );


if(!function_exists('qode_pitch_attachment_field_custom_size_save')) {


	function qode_pitch_attachment_field_custom_size_save($post, $attachment)
	{
		if (isset($attachment['qode_portfolio_single_predefined_size'])) {
			update_post_meta($post['ID'], 'qode_portfolio_single_predefined_size', $attachment['qode_portfolio_single_predefined_size']);
		}
		return $post;
	}
}

add_filter( 'attachment_fields_to_save', 'qode_pitch_attachment_field_custom_size_save', 10, 2 );


if(!function_exists('qode_pitch_is_in_menu')) {
	function qode_pitch_is_in_menu( $menu = null, $object_id = null ) {

		$nav = wp_get_nav_menu_items($menu);
		$result = 0;
		foreach ( $nav as $item ) {

			if ( $object_id == $item->object_id ) {
				$result = $item;
			}
		}
		return $result;
	}
}

if(!function_exists('qode_pitch_replace_menu_name')) {
	function qode_pitch_replace_menu_name(){
		global $qode_pitch_options;
		$result = 0;
		if (isset($qode_pitch_options['qode_enable_login_page']) && $qode_pitch_options['qode_enable_login_page'] == 'yes' && isset($qode_pitch_options['qode_login_page']) && $qode_pitch_options['qode_login_page'] != "") {
			if ( is_user_logged_in() ) {
				$menus = wp_get_nav_menus();
				$menu_item = null;
				foreach ($menus as $menu) {
					$menu_item = qode_pitch_is_in_menu($menu->term_id, $qode_pitch_options['qode_login_page']);
				}
				if($menu_item != null) {
					$result = $menu_item->ID;
				}
			}
		}

		return $result;
	}
}
add_action('get_header', 'qode_pitch_replace_menu_name');

if(!function_exists('qode_pitch_redirect_logout')) {
	function qode_pitch_redirect_logout()
	{
		global $qode_pitch_options;
		if (isset($qode_pitch_options['qode_enable_login_page']) && $qode_pitch_options['qode_enable_login_page'] == 'yes' && isset($qode_pitch_options['qode_login_page']) && $qode_pitch_options['qode_login_page'] != "") {
			wp_redirect(get_permalink($qode_pitch_options['qode_login_page']));
			exit();
		}
	}
}
add_action('wp_logout', 'qode_pitch_redirect_logout');

if(!function_exists('qode_pitch_add_user_custom_fields')) {
	function qode_pitch_add_user_custom_fields($user_contact) {
		/**
		 * Function that add custom user fields
		 **/
		$user_contact['facebook']   = esc_html__( 'Facebook', 'pitchwp');
		$user_contact['twitter'] = esc_html__( 'Twitter', 'pitchwp');
		$user_contact['instagram'] = esc_html__( 'Instagram', 'pitchwp');
		$user_contact['dribbble'] = esc_html__( 'Dribbble', 'pitchwp');
		$user_contact['linkedin'] = esc_html__( 'LinkedIn', 'pitchwp' );

		return $user_contact;
	}
}
add_filter( 'user_contactmethods', 'qode_pitch_add_user_custom_fields' );

if(!function_exists('qode_pitch_get_gravatar')) {
	function qode_pitch_get_gravatar($email, $s = 80, $d = 'mm', $r = 'g', $img = false, $atts = array())
	{
		$url = 'http://www.gravatar.com/avatar/';
		$url .= md5(strtolower(trim($email)));
		$url .= "?s=$s&d=$d&r=$r";
		if ($img) {
			$url = '<img src="' . $url . '"';
			foreach ($atts as $key => $val)
				$url .= ' ' . $key . '="' . $val . '"';
			$url .= ' />';
		}
		return $url;
	}
}

if(!function_exists('qode_pitch_localizeLogin')) {
	function qode_pitch_localizeLogin()
	{
		if (is_user_logged_in()) {
			wp_localize_script('qode_pitch_default', 'qodef_logout_url', array(
				'url' => wp_logout_url()
			));
		}
	}
}

add_action('wp_enqueue_scripts', 'qode_pitch_localizeLogin');