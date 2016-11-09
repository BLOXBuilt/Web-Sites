<?php
global $qode_pitch_IconCollections;

$headerandfooterPage = new QodePitchAdminPage("2", "Header", "fa fa-header");
$qode_pitch_Framework->qodeOptions->addAdminPage("headerandfooter",$headerandfooterPage);

// Header Position

$panel6 = new QodePitchPanel("Header Type", "header_type_panel");
$headerandfooterPage->addChild("panel6",$panel6);
	$header_type = new QodePitchField("select","header_type","top","Choose Header Type","Select the type of header you would like to use", array(
			"top" => "Top",
			"side" => "Side"
		),
		array(
            "dependence" => true,
			"hide" => array(
				"top"=>"#qodef_vertical_areas_panel",
				"side"=>"#qodef_header_panel,#qodef_top_menu_panel,#qodef_header_top_panel,#qodef_enable_search_panel,#qodef_enable_side_area_panel,#qodef_enable_popup_menu_panel",
				),
			"show" => array(
				"top"=>"#qodef_header_panel,#qodef_top_menu_panel,#qodef_header_top_panel,#qodef_enable_search_panel,#qodef_enable_side_area_panel,#qodef_enable_popup_menu_panel",
				"side"=>"#qodef_vertical_areas_panel",
			)
		));
	$panel6->addChild("header_type",$header_type);

// Header

$panel5 = new QodePitchPanel("Header","header_panel","header_type","",array( "side"));
$headerandfooterPage->addChild("panel5",$panel5);

	$header_in_grid = new QodePitchField("yesno","header_in_grid","yes","Header in Grid","Enabling this option will display header content in grid",array(), array("dependence" => true, "dependence_hide_on_yes" => "#qodef_header_padding_container", "dependence_show_on_yes" => "#qodef_header_in_grid_container"));
	$panel5->addChild("header_in_grid",$header_in_grid);

	$header_bottom_appearance = new QodePitchField("select","header_bottom_appearance","fixed","Header Type","Choose the header layout & behavior", array(
        "regular" => "Regular",
        "fixed" => "Fixed",
		"fixed fixed_minimal" => "Fixed Minimal",
        "fixed_hiding" => "Fixed Advanced",
		"fixed_top_header" => "Fixed Header Top",
        "stick" => "Sticky",
        "stick menu_bottom" => "Sticky Expanded",
        "stick_with_left_right_menu" => "Sticky Divided",
		"stick compound" => "Sticky Compound"
      ),
      array("dependence" => true,
      	"hide" => array(
      		"regular"=>"#qodef_search_left_sidearea_right_container,#qodef_menu_vertical_position_for_sticky_container,#qodef_menu_background_color_container,#qodef_scroll_amount_for_sticky_container,#qodef_header_height_scroll,#qodef_header_one_scroll_resize,#qodef_header_height_sticky,#qodef_header_height_scroll_hidden,#qodef_header_background_color_scroll,#qodef_header_grid_background_color_scroll,#qodef_header_background_color_sticky,#qodef_header_grid_background_color_sticky,#qodef_header_background_transparency_scroll,#qodef_header_grid_background_transparency_scroll,#qodef_header_background_transparency_sticky,#qodef_header_grid_background_transparency_sticky,#qodef_scroll_amount_for_fixed_hiding_container,#qodef_menu_items_position_container",
	        "fixed"=>"#qodef_search_left_sidearea_right_container,#qodef_menu_vertical_position_for_sticky_container,#qodef_menu_background_color_container,#qodef_scroll_amount_for_sticky_container,#qodef_header_height_sticky,#qodef_header_height_scroll_hidden,#qodef_header_background_color_sticky,#qodef_header_grid_background_color_sticky,#qodef_header_background_transparency_sticky,#qodef_header_grid_background_transparency_sticky,#qodef_scroll_amount_for_fixed_hiding_container,#qodef_menu_items_position_container",
	        "fixed_hiding"=>"#qodef_menu_vertical_position_for_sticky_container,#qodef_scroll_amount_for_sticky_container,#qodef_menu_position_container,#qodef_header_height_scroll,#qodef_header_one_scroll_resize,#qodef_header_height_sticky,#qodef_header_background_color_sticky,#qodef_header_grid_background_color_sticky,#qodef_header_background_transparency_sticky,#qodef_header_grid_background_transparency_sticky,#qodef_menu_items_position_container",
      		"stick menu_bottom"=>"#qodef_search_left_sidearea_right_container,#qodef_menu_vertical_position_for_sticky_container,#qodef_menu_position_container,#qodef_header_height_scroll,#qodef_header_one_scroll_resize,#qodef_header_height_scroll_hidden,#qodef_header_background_transparency_scroll,#qodef_header_grid_background_transparency_scroll,#qodef_header_background_color_scroll,#qodef_header_grid_background_color_scroll,#qodef_scroll_amount_for_fixed_hiding_container,#qodef_menu_items_position_container",
            "stick_with_left_right_menu"=>"#qodef_search_left_sidearea_right_container,#qodef_menu_background_color_container,#qodef_menu_position_container,#qodef_header_height_scroll,#qodef_header_one_scroll_resize,#qodef_header_height_scroll_hidden,#qodef_header_background_transparency_scroll,#qodef_header_grid_background_transparency_scroll,#qodef_header_background_color_scroll,#qodef_scroll_amount_for_fixed_hiding_container",
      		"stick"=>"#qodef_search_left_sidearea_right_container,#qodef_menu_vertical_position_for_sticky_container,#qodef_menu_background_color_container,#qodef_header_height_scroll,#qodef_header_one_scroll_resize,#qodef_header_height_scroll_hidden,#qodef_header_background_color_scroll,#qodef_header_grid_background_color_scroll,#qodef_header_background_transparency_scroll,#qodef_header_grid_background_transparency_scroll,#qodef_scroll_amount_for_fixed_hiding_container,#qodef_menu_items_position_container",
			"fixed_top_header"=>"#qodef_search_left_sidearea_right_container,#qodef_menu_vertical_position_for_sticky_container,#qodef_menu_vertical_position_for_sticky_container,#qodef_header_height_container,#qodef_disable_text_shadow_for_sticky_container,#qodef_menu_background_color_container,#qodef_menu_position_container,#qodef_header_top_area_scroll_container,#qodef_scroll_amount_for_sticky_container,#qodef_header_height_scroll,#qodef_header_one_scroll_resize,#qodef_header_height_sticky,#qodef_header_height_scroll_hidden,#qodef_header_background_color_scroll,#qodef_header_grid_background_color_scroll,#qodef_header_background_color_sticky,#qodef_header_grid_background_color_sticky,#qodef_header_background_transparency_scroll,#qodef_header_grid_background_transparency_scroll,#qodef_header_background_transparency_sticky,#qodef_header_grid_background_transparency_sticky,#qodef_scroll_amount_for_fixed_hiding_container,#qodef_menu_items_position_container,#enable_border_for_sticky_container",
			"fixed fixed_minimal"=>"#qodef_search_left_sidearea_right_container,#qodef_menu_vertical_position_for_sticky_container,#qodef_menu_position_container,#qodef_menu_background_color_container,#qodef_scroll_amount_for_sticky_container,#qodef_header_height_sticky,#qodef_header_height_scroll_hidden,#qodef_header_background_color_sticky,#qodef_header_grid_background_color_sticky,#qodef_header_background_transparency_sticky,#qodef_header_grid_background_transparency_sticky,#qodef_scroll_amount_for_fixed_hiding_container,#qodef_menu_items_position_container",
			"stick compound"=>"#qodef_search_left_sidearea_right_container,#qodef_menu_vertical_position_for_sticky_container,#qodef_menu_background_color_container,#qodef_menu_position_container,#qodef_header_height_scroll,#qodef_header_one_scroll_resize,#qodef_header_height_scroll_hidden,#qodef_header_background_color_scroll,#qodef_header_grid_background_color_scroll,#qodef_header_background_transparency_scroll,#qodef_header_grid_background_transparency_scroll,#qodef_scroll_amount_for_fixed_hiding_container,#qodef_menu_items_position_container",
			),
      	"show" => array(
      		"regular"=>"#qodef_header_height_container,#qodef_menu_position_container,#qodef_disable_text_shadow_for_sticky_container,#enable_border_for_sticky_container",
      		"fixed"=>"#qodef_header_height_container,#qodef_menu_position_container,#qodef_header_height_scroll,#qodef_header_one_scroll_resize,#qodef_header_background_color_scroll,#qodef_header_grid_background_color_scroll,#qodef_header_background_transparency_scroll,#qodef_header_grid_background_transparency_scroll,#qodef_disable_text_shadow_for_sticky_container,#enable_border_for_sticky_container",
      		"stick"=>"#qodef_header_height_container,#qodef_scroll_amount_for_sticky_container,#qodef_menu_position_container,#qodef_header_height_sticky,#qodef_header_background_color_sticky,#qodef_header_grid_background_color_sticky,#qodef_header_background_transparency_sticky,#qodef_header_grid_background_transparency_sticky,#qodef_disable_text_shadow_for_sticky_container,#enable_border_for_sticky_container",
      		"stick menu_bottom"=>"#qodef_header_height_container,#qodef_menu_background_color_container,#qodef_scroll_amount_for_sticky_container,#qodef_header_height_sticky,#qodef_header_background_color_sticky,#qodef_header_grid_background_color_sticky,#qodef_header_background_transparency_sticky,#qodef_header_grid_background_transparency_sticky,#qodef_disable_text_shadow_for_sticky_container,#enable_border_for_sticky_container",
            "stick_with_left_right_menu"=>"#qodef_menu_vertical_position_for_sticky_container,#qodef_header_height_container,#qodef_scroll_amount_for_sticky_container,#qodef_header_height_sticky,#qodef_header_background_color_sticky,#qodef_header_grid_background_color_sticky,#qodef_header_background_transparency_sticky,#qodef_header_grid_background_transparency_sticky,#qodef_menu_items_position_container,#qodef_disable_text_shadow_for_sticky_container,#enable_border_for_sticky_container",
      		"fixed_hiding"=>"#qodef_search_left_sidearea_right_container,#qodef_header_height_container,#qodef_menu_background_color_container,#qodef_header_height_scroll_hidden,#qodef_header_background_color_scroll,#qodef_header_grid_background_color_scroll,#qodef_header_background_transparency_scroll,#qodef_header_grid_background_transparency_scroll,#qodef_scroll_amount_for_fixed_hiding_container,#qodef_disable_text_shadow_for_sticky_container,#enable_border_for_sticky_container",
			"fixed_top_header"=>"",
			"fixed fixed_minimal"=>"#qodef_header_height_container,#qodef_header_height_scroll,#qodef_header_one_scroll_resize,#qodef_header_background_color_scroll,#qodef_header_grid_background_color_scroll,#qodef_header_background_transparency_scroll,#qodef_header_grid_background_transparency_scroll,#qodef_disable_text_shadow_for_sticky_container,#enable_border_for_sticky_container",
			"stick compound"=>"#qodef_header_height_container,#qodef_scroll_amount_for_sticky_container,#qodef_header_height_sticky,#qodef_header_background_color_sticky,#qodef_header_grid_background_color_sticky,#qodef_header_background_transparency_sticky,#qodef_header_grid_background_transparency_sticky,#qodef_disable_text_shadow_for_sticky_container,#enable_border_for_sticky_container"
			) ));
	
	$panel5->addChild("header_bottom_appearance",$header_bottom_appearance);
			
			
	
	$search_left_sidearea_right_container = new QodePitchContainer("search_left_sidearea_right_container","header_bottom_appearance","",array( "regular","fixed","fixed_top_header","fixed fixed_minimal","stick","stick menu_bottom","stick_with_left_right_menu","fixed_top_header","fixed fixed_minimal","stick compound"));
    $panel5->addChild("search_left_sidearea_right_container",$search_left_sidearea_right_container);
	
		$search_left_sidearea_right = new QodePitchField("yesno","search_left_sidearea_right","no","Place Search and Side Area Icons to Separate Sides of Header ","Enabling this option will set search icon to left side of header and side area icon to right side of header");
		$search_left_sidearea_right_container->addChild("search_left_sidearea_right",$search_left_sidearea_right);
		
		
	$scroll_amount_for_sticky_container = new QodePitchContainer("scroll_amount_for_sticky_container","header_bottom_appearance","", array( "regular","fixed","fixed_hiding","fixed_top_header","fixed fixed_minimal") );
	$panel5->addChild("scroll_amount_for_sticky_container",$scroll_amount_for_sticky_container);

		$scroll_amount_for_sticky = new QodePitchField("text","scroll_amount_for_sticky","","Scroll Amount for Sticky (px)","Enter scroll amount (in pixels) for Sticky Menu to appear", array(), array("col_width" => 3));
		$scroll_amount_for_sticky_container->addChild("scroll_amount_for_sticky",$scroll_amount_for_sticky);
		
		$hide_initial_sticky = new QodePitchField("yesno","hide_initial_sticky","no","Hide Header Initially","Enabling this option will initially hide the header, and it will only be displayed when the user scrolls down the page");
		$scroll_amount_for_sticky_container->addChild("hide_initial_sticky",$hide_initial_sticky);
		
	$menu_items_position_container = new QodePitchContainer("menu_items_position_container","header_bottom_appearance","", array( "regular","fixed","fixed_hiding","fixed_top_header","fixed fixed_minimal","stick","stick menu_bottom","stick compound"));
	$panel5->addChild("menu_items_position_container",$menu_items_position_container);
		
		$menu_items_position = new QodePitchField("select","menu_items_position","","Menu Items Position","Choose whether you would like the menu items to start from center of screen and extend outwards, or from the edges of the grid and extend inward",
			array(	"from_center" => "From Center",
					"from_edges" => "From Edges of Grid"
		));
		$menu_items_position_container->addChild("menu_items_position",$menu_items_position);

		$widgets_position = new QodePitchField("yesno","widgets_position","no","Position Widgets on Edges of Grid","Enabling this option will position header bottom widgets to the left/right edges of the grid");
		$menu_items_position_container->addChild("widgets_position",$widgets_position);
		
	$menu_vertical_position_for_sticky_container = new QodePitchContainer("menu_vertical_position_for_sticky_container","header_bottom_appearance","", array( "regular","fixed","fixed_hiding","fixed_top_header","fixed fixed_minimal","stick menu_bottom","stick compound","stick") );
	$panel5->addChild("menu_vertical_position_for_sticky_container",$menu_vertical_position_for_sticky_container);
		
		$menu_vertical_position_for_sticky = new QodePitchField("select","menu_vertical_position_for_sticky","","Menu Vertical Alignment","Choose the vertical alignment for the menu in the Sticky Divided header",
			array(	"default" => "Default",
					"bottom" => "Bottom"
		),
		 array("dependence" => true,
      	"hide" => array(
			"default"=>"#qodef_menu_bottom_position_container"
		),
      	"show" => array(
			"bottom"=>"#qodef_menu_bottom_position_container"
		) ));
		$menu_vertical_position_for_sticky_container->addChild("menu_vertical_position_for_sticky",$menu_vertical_position_for_sticky);
	
		
	$menu_bottom_position_container = new QodePitchContainer("menu_bottom_position_container","menu_vertical_position_for_sticky","", array( "default"));
	$panel5->addChild("menu_bottom_position_container",$menu_bottom_position_container);

		$menu_bottom_position = new QodePitchField("text","menu_bottom_position","","Menu Bottom Offset (px)","Enter the amount of pixels you would like to move the menu from bottom of header", array(), array("col_width" => 3));
		$menu_bottom_position_container->addChild("menu_bottom_position",$menu_bottom_position);
		
    $scroll_amount_for_fixed_hiding_container = new QodePitchContainer("scroll_amount_for_fixed_hiding_container","header_bottom_appearance","", array( "regular","fixed","stick", "stick menu_bottom", "stick_with_left_right_menu","fixed_top_header","fixed fixed_minimal","stick compound") );
    $panel5->addChild("scroll_amount_for_fixed_hiding_container",$scroll_amount_for_fixed_hiding_container);
        $scroll_amount_for_fixed_hiding = new QodePitchField("text","scroll_amount_for_fixed_hiding","","Scroll Amount (px)","Enter scroll amount (in pixels) for menu to hide", array(), array("col_width" => 3));
        $scroll_amount_for_fixed_hiding_container->addChild("scroll_amount_for_fixed_hiding",$scroll_amount_for_fixed_hiding);

	$menu_position_container = new QodePitchContainer("menu_position_container","header_bottom_appearance","", array( "stick menu_bottom","stick_with_left_right_menu","fixed_hiding","fixed_top_header","stick compound") );
	$panel5->addChild("menu_position_container",$menu_position_container);

		$menu_position = new QodePitchField("select","menu_position","","Menu Position","Choose a menu position (default is right alignment)", array(
			"-1" => "Right",
			"center" => "Center",
			"left" => "Left"
		));
		$menu_position_container->addChild("menu_position",$menu_position);

	    $center_logo_image = new QodePitchField("yesno","center_logo_image","no","Center Logo","Enabling this option will center logo and position it above menu", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#qodef_center_logo_image_container"));
	    $menu_position_container->addChild("center_logo_image",$center_logo_image);

    	$center_logo_image_container = new QodePitchContainer("center_logo_image_container","center_logo_image","no");
    	$menu_position_container->addChild("center_logo_image_container",$center_logo_image_container);
	
		$search_left_sidearea_right_regular = new QodePitchField("yesno","search_left_sidearea_right_regular","no","Place Search and Side Area Icons to Separate Sides of Header ","Enabling this option will set search icon to left side of header and side area icon to right side of header");
		$center_logo_image_container->addChild("search_left_sidearea_right_regular",$search_left_sidearea_right_regular);
		
        $enable_border_top_bottom_menu = new QodePitchField("yesno","enable_border_top_bottom_menu","no","Enable Top/Bottom Border in Menu","", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#qodef_menu_border_container"));
        $center_logo_image_container->addChild("enable_border_top_bottom_menu",$enable_border_top_bottom_menu);

            $menu_border_container = new QodePitchContainer("menu_border_container","enable_border_top_bottom_menu","no");
            $center_logo_image_container->addChild("menu_border_container",$menu_border_container);

                $color_border_top_bottom_menu = new QodePitchField("color","color_border_top_bottom_menu","","Border Color","Choose a color for the top/bottom border in menu.");
                $menu_border_container->addChild("color_border_top_bottom_menu",$color_border_top_bottom_menu); 

    $disable_text_shadow_for_sticky_container = new QodePitchContainer("disable_text_shadow_for_sticky_container","header_bottom_appearance","", array("fixed_top_header") );
	$panel5->addChild("disable_text_shadow_for_sticky_container",$disable_text_shadow_for_sticky_container);
	
		$disable_text_shadow_for_sticky = new QodePitchField("yesno","disable_text_shadow_for_sticky","yes","Disable Shadow For Scrolled Header","Enabling this option will display text shadow for scrolled/sticky header");
		$disable_text_shadow_for_sticky_container->addChild("disable_text_shadow_for_sticky",$disable_text_shadow_for_sticky);

    $enable_border_for_sticky_container = new QodePitchContainer("enable_border_for_sticky_container","header_bottom_appearance","", array("fixed_top_header") );
    $panel5->addChild("enable_border_for_sticky_container",$enable_border_for_sticky_container);

        $enable_border_for_sticky = new QodePitchField("yesno","enable_border_for_sticky","no","Enable Border For Scrolled Header","Enabling this option will display border for scrolled/sticky header", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#qodef_enable_border_bottom_color_for_sticky_container"));
        $enable_border_for_sticky_container->addChild("enable_border_for_sticky",$enable_border_for_sticky);

        $enable_border_bottom_color_for_sticky_container = new QodePitchContainer("enable_border_bottom_color_for_sticky_container","enable_border_for_sticky","no");
        $panel5->addChild("enable_border_color_for_sticky_container",$enable_border_bottom_color_for_sticky_container);

            $group1 = new QodePitchGroup("Border Style","Choose style for border for scrolled/sticky header");
            $enable_border_bottom_color_for_sticky_container->addChild("group1",$group1);

                $row1 = new QodePitchRow();
                $group1->addChild("row1",$row1);

                    $border_bottom_color_for_sticky = new QodePitchField("colorsimple","border_bottom_color_for_sticky","","Border Color","This is some description");
                    $row1->addChild("border_bottom_color_for_sticky",$border_bottom_color_for_sticky);

                    $border_bottom_width_for_sticky = new QodePitchField("textsimple","border_bottom_width_for_sticky","","Border Width","This is some description");
                    $row1->addChild("border_bottom_width_for_sticky",$border_bottom_width_for_sticky);

                    $border_bottom_for_sticky_in_grid = new QodePitchField("yesnosimple","border_bottom_for_sticky_in_grid","no","Border in Grid","This is some description");
                    $row1->addChild("border_bottom_for_sticky_in_grid",$border_bottom_for_sticky_in_grid);

	
	$header_height_container = new QodePitchContainerNoStyle("header_height_container","header_bottom_appearance","", array("fixed_top_header"));
    $panel5->addChild("header_height_container",$header_height_container);
	
		$group1 = new QodePitchGroup("Header Height","Enter header height in pixels");
		$header_height_container->addChild("group1",$group1);

			$row1 = new QodePitchRow();
			$group1->addChild("row1",$row1);

				$header_height = new QodePitchField("textsimple","header_height","","Initial (px)","Initial header (px)");
				$row1->addChild("header_height",$header_height);

				$header_height_scroll = new QodePitchField("textsimple","header_height_scroll","","After Scroll (px)","This is some description", array(), array(),"header_bottom_appearance", array( "regular","stick","stick menu_bottom","stick_with_left_right_menu","fixed_hiding","fixed_top_header","stick compound"));
				$row1->addChild("header_height_scroll",$header_height_scroll);

				$header_one_scroll_resize = new QodePitchField("yesnosimple","header_one_scroll_resize","no","Resize Header on Single Scroll","This is some description", array(), array(),"header_bottom_appearance", array( "regular","stick","stick menu_bottom","stick_with_left_right_menu","fixed_hiding","fixed_top_header","stick compound"));
				$row1->addChild("header_one_scroll_resize",$header_one_scroll_resize);

				$header_height_sticky = new QodePitchField("textsimple","header_height_sticky","","After Scroll (px)","This is some description", array(), array(),"header_bottom_appearance", array( "regular","fixed","fixed_hiding","fixed_top_header","fixed fixed_minimal"));
				$row1->addChild("header_height_sticky",$header_height_sticky);

				$header_height_scroll_hidden = new QodePitchField("textsimple","header_height_scroll_hidden","","After Scroll (px)","This is some description", array(), array(),"header_bottom_appearance", array( "regular","fixed","stick","stick menu_bottom","stick_with_left_right_menu","fixed_top_header","fixed fixed_minimal","stick compound"));
				$row1->addChild("header_height_scroll_hidden",$header_height_scroll_hidden);

			
	$header_padding_container = new QodePitchContainer("header_padding_container","header_in_grid","yes");
    $panel5->addChild("header_padding_container",$header_padding_container);
	
		$header_left_padding = new QodePitchField("text","header_left_padding","","Header Left Padding","Set left padding for header bottom appearance in px or % (default value is 45px)", array(), array("col_width" => 3));
		$header_padding_container->addChild("header_left_padding",$header_left_padding);
		
		$header_right_padding = new QodePitchField("text","header_right_padding","","Header Right Padding","Set right padding for header bottom appearance in px or % (default value is 45px)", array(), array("col_width" => 3));
		$header_padding_container->addChild("header_right_padding",$header_right_padding);
		
	
	$header_style = new QodePitchField("select","header_style","","Header Skin","Choose a header style to make header elements (logo, main menu, side menu button) in that predefined style", array(
        "-1" => "",
        "light" => "Light",
        "dark" => "Dark"
    ));
    $panel5->addChild("header_style",$header_style);

	
	
    $enable_header_style_on_scroll = new QodePitchField("yesno","enable_header_style_on_scroll","no","Enable Header Style on Scroll","Enabling this option, header will change style depending on row settings for dark/light style");
    $panel5->addChild("enable_header_style_on_scroll",$enable_header_style_on_scroll);
	


    $group2 = new QodePitchGroup("Header Background Color","Choose a background color for header area");
    $panel5->addChild("group2",$group2);

        $row1 = new QodePitchRow();
        $group2->addChild("row1",$row1);

            $header_background_color = new QodePitchField("colorsimple","header_background_color","","Initial","");
            $row1->addChild("header_background_color",$header_background_color);

            $header_background_color_scroll = new QodePitchField("colorsimple","header_background_color_scroll","","After Scroll","", array(), array(),"header_bottom_appearance", array( "regular","stick","stick menu_bottom","stick_with_left_right_menu","fixed_top_header","stick compound"));
            $row1->addChild("header_background_color_scroll",$header_background_color_scroll);

            $header_background_color_sticky = new QodePitchField("colorsimple","header_background_color_sticky","","After Scroll","", array(), array(),"header_bottom_appearance", array( "regular","fixed","fixed_hiding","fixed_top_header","fixed fixed_minimal"));
            $row1->addChild("header_background_color_sticky",$header_background_color_sticky);

    $group3 = new QodePitchGroup("Header Transparency","Choose a transparency for the header background color (0 = fully transparent, 1 = opaque)");
    $panel5->addChild("group3",$group3);

        $row1 = new QodePitchRow();
        $group3->addChild("row1",$row1);

            $header_background_transparency_initial = new QodePitchField("textsimple","header_background_transparency_initial","","Initial","This is some description");
            $row1->addChild("header_background_transparency_initial",$header_background_transparency_initial);

            $header_background_transparency_scroll = new QodePitchField("textsimple","header_background_transparency_scroll","","After Scroll","This is some description", array(), array(),"header_bottom_appearance", array( "regular","stick","stick menu_bottom","stick_with_left_right_menu","fixed_top_header","stick compound"));
            $row1->addChild("header_background_transparency_scroll",$header_background_transparency_scroll);

            $header_background_transparency_sticky = new QodePitchField("textsimple","header_background_transparency_sticky","","After Scroll","This is some description", array(), array(),"header_bottom_appearance", array( "regular","fixed","fixed_hiding","fixed_top_header","fixed fixed_minimal"));
            $row1->addChild("header_background_transparency_sticky",$header_background_transparency_sticky);

    $group4 = new QodePitchGroup("Header Background Pattern","Choose a pattern for the header background");
    $panel5->addChild("group4",$group4);

        $row1 = new QodePitchRow();
        $group4->addChild("row1",$row1);

            $header_pattern_image_initial = new QodePitchField("imagesimple","header_pattern_image_initial","","Initial","");
            $row1->addChild("header_pattern_image_initial",$header_pattern_image_initial);

            $header_pattern_image_scroll = new QodePitchField("imagesimple","header_pattern_image_scroll","","After Scroll","");
            $row1->addChild("header_pattern_image_scroll",$header_pattern_image_scroll);

	$header_in_grid_container = new QodePitchContainerNoStyle('header_in_grid_container', 'header_in_grid', 'no');
	$panel5->addChild('header_in_grid_container', $header_in_grid_container);

	$group6 = new QodePitchGroup('Header Grid Content Background Color', 'Choose a background color for header grid content area');
	$header_in_grid_container->addChild('group6', $group6);

		$row1 = new QodePitchRow();
		$group6->addChild('row1', $row1);

			$header_grid_background_color = new QodePitchField("colorsimple","header_grid_background_color","","Initial","");
			$row1->addChild("header_grid_background_color",$header_grid_background_color);

			$header_grid_background_color_scroll = new QodePitchField("colorsimple","header_grid_background_color_scroll","","After Scroll","", array(), array(),"header_bottom_appearance", array( "regular","stick","stick menu_bottom","stick_with_left_right_menu","fixed_top_header","stick compound"));
			$row1->addChild("header_grid_background_color_scroll",$header_grid_background_color_scroll);

			$header_grid_background_color_sticky = new QodePitchField("colorsimple","header_grid_background_color_sticky","","After Scroll","", array(), array(),"header_bottom_appearance", array( "regular","fixed","fixed_hiding","fixed_top_header","fixed fixed_minimal"));
			$row1->addChild("header_grid_background_color_sticky",$header_grid_background_color_sticky);

	$group7 = new QodePitchGroup('Header Grid Content Transparency', 'Choose a transparency for the header background color (0 = fully transparent, 1 = opaque');
	$header_in_grid_container->addChild('group7', $group7);

		$row2 = new QodePitchRow();
		$group7->addChild("row2",$row2);

			$header_grid_background_transparency_initial = new QodePitchField("textsimple","header_grid_background_transparency_initial","","Initial","");
			$row2->addChild("header_grid_background_transparency_initial",$header_grid_background_transparency_initial);

			$header_grid_background_transparency_scroll = new QodePitchField("textsimple","header_grid_background_transparency_scroll","","After Scroll","", array(), array(),"header_bottom_appearance", array( "regular","stick","stick menu_bottom","stick_with_left_right_menu","fixed_top_header","stick compound"));
			$row2->addChild("header_grid_background_transparency_scroll",$header_grid_background_transparency_scroll);

			$header_grid_background_transparency_sticky = new QodePitchField("textsimple","header_grid_background_transparency_sticky","","After Scroll","", array(), array(),"header_bottom_appearance", array( "regular","fixed","fixed_hiding","fixed_top_header","fixed fixed_minimal"));
			$row2->addChild("header_grid_background_transparency_sticky",$header_grid_background_transparency_sticky);

	$group8 = new QodePitchGroup('Header in Grid Padding', 'Left and right padding for header in grid');
	$header_in_grid_container->addChild('group8', $group8);

		$row3 = new QodePitchRow();
		$group8->addChild('row3', $row3);

			$header_in_grid_padding_left = new QodePitchField('textsimple', 'header_in_grid_padding_left', '', 'Left (px)', '');
			$row3->addChild('header_in_grid_padding_left', $header_in_grid_padding_left);

			$header_in_grid_padding_right = new QodePitchField('textsimple', 'header_in_grid_padding_right', '', 'Right (px)', '');
			$row3->addChild('header_in_grid_padding_right', $header_in_grid_padding_right);

    $enable_header_top_border = new QodePitchField("yesno","enable_header_top_border","no","Enable Header Top Border","", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#qodef_header_top_border_container"));
    $panel5->addChild("enable_header_top_border",$enable_header_top_border);

        $header_top_border_container = new QodePitchContainer("header_top_border_container","enable_header_top_border","no");
        $panel5->addChild("header_top_border_container",$header_top_border_container);

            $header_top_border_width = new QodePitchField("text","header_top_border_width","","Header Top Border Width (px)","Choose a width for the header top border. Note: If width has not been set, border top will not be displayed", array(), array("col_width" => 3));
            $header_top_border_container->addChild("header_top_border_width",$header_top_border_width);
			
			$header_top_border_color = new QodePitchField("color","header_top_border_color","","Header Top Border Color","Choose a color for the header top border. ");
            $header_top_border_container->addChild("header_top_border_color",$header_top_border_color);

            $header_top_border_transparency = new QodePitchField("text","header_top_border_transparency","","Header Top Border Transparency","Choose a transparency for the header border color (0 = fully transparent, 1 = opaque). Note: Works only if Header top Border Color is filled", array(), array("col_width" => 3));
            $header_top_border_container->addChild("header_top_border_transparency",$header_top_border_transparency);
	
	$enable_header_bottom_border = new QodePitchField("yesno","enable_header_bottom_border","no","Enable Header Bottom Border","", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#qodef_header_bottom_border_container"));
    $panel5->addChild("enable_header_bottom_border",$enable_header_bottom_border);

        $header_bottom_border_container = new QodePitchContainer("header_bottom_border_container","enable_header_bottom_border","no");
        $panel5->addChild("header_bottom_border_container",$header_bottom_border_container);

            $header_bottom_border_width = new QodePitchField("text","header_bottom_border_width","","Header Bottom Border Width (px)","Choose a width for the header bottom  border. Note: If width has not been set, border bottom will not be displayed", array(), array("col_width" => 3));
            $header_bottom_border_container->addChild("header_bottom_border_width",$header_bottom_border_width);
			
			$header_bottom_border_color = new QodePitchField("color","header_bottom_border_color","","Header Bottom Border Color","Choose a color for the header bottom border.");
            $header_bottom_border_container->addChild("header_bottom_border_color",$header_bottom_border_color);

            $header_botom_border_transparency = new QodePitchField("text","header_botom_border_transparency","","Header Bottom Border Transparency","Choose a transparency for the header border color (0 = fully transparent, 1 = opaque). Note: Works only if Header Bottom Border Color is filled", array(), array("col_width" => 3));
            $header_bottom_border_container->addChild("header_botom_border_transparency",$header_botom_border_transparency);

            $header_botom_border_in_grid = new QodePitchField("yesno","header_botom_border_in_grid","no","Enable Header Bottom Border in Grid","Enabling this option will set header border bottom width in grid");
            $header_bottom_border_container->addChild("header_botom_border_in_grid",$header_botom_border_in_grid);     
	
// Menu

$panel4 = new QodePitchPanel("Top Menu", "top_menu_panel","header_type","",array( "side"));
$headerandfooterPage->addChild("panel4",$panel4);

	$menu_appearance = new QodePitchField("select","menu_appearance","default","Menu Appearance","Choose menu appearance style", array(
			"default" => "Default",
			"top_menu_slide_down" => "Slide Down"
		));
	$panel4->addChild("menu_appearance",$menu_appearance);
	
	$menu_background_color_container = new QodePitchContainer("menu_background_color_container","header_bottom_appearance","", array( "regular","fixed","stick","stick_with_left_right_menu","fixed_top_header","fixed fixed_minimal","stick compound") );
	$panel4->addChild("menu_background_color_container",$menu_background_color_container);
	
		$menu_background_color = new QodePitchField("color","menu_background_color","","Background Color of 1st Level Menu","Choose a color for the menu background (works only for Fixed Advanced and Sticky Expanded header types)");
		$menu_background_color_container->addChild("menu_background_color",$menu_background_color);
		
		$enable_menu_top_bottom_border = new QodePitchField("yesno","enable_menu_top_bottom_border","no","Enable Top/Bottom Borders in 1st Level Menu","Enabling this option will display top and bottom borders around 1st level menu (works only for Fixed Advanced and Sticky Expanded header types)", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#qodef_menu_top_bottom_border_container"));
		$menu_background_color_container->addChild("enable_menu_top_bottom_border",$enable_menu_top_bottom_border);
			$menu_top_bottom_border_container = new QodePitchContainer("menu_top_bottom_border_container","enable_menu_top_bottom_border","no");
			$menu_background_color_container->addChild("menu_top_bottom_border_container",$menu_top_bottom_border_container);
				$color_menu_top_bottom_border = new QodePitchField("color","color_menu_top_bottom_border","","Border Color","Choose a color for the top/bottom border in 1st level menu.");
				$menu_top_bottom_border_container->addChild("color_menu_top_bottom_border",$color_menu_top_bottom_border);
		
		$enable_menu_wide_background = new QodePitchField("yesno","enable_menu_wide_background","no","Enable wide background in 1st Level Menu","Enabling this option will show wide background or borders in 1st level menu (works only for Fixed Advanced and Sticky Expanded header types)", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => ""));
		$menu_background_color_container->addChild("enable_menu_wide_background",$enable_menu_wide_background);
			

	$menu_item_icon_position = new QodePitchField("select","menu_item_icon_position","left","Icon Position in 1st Level Menu","Choose position of icon selected in Appearance->Menu->Menu Structure", array(
			"left" => "Left",
			"top" => "Top"
		),
		array("dependence" => true, 
			"hide" => array(
      		"left"=>"#qodef_menu_item_icon_position_container"),
			"show" => array(
      		"top"=>"#qodef_menu_item_icon_position_container")
		));	
		$panel4->addChild("menu_item_icon_position",$menu_item_icon_position);
			$menu_item_icon_position_container = new QodePitchContainer("menu_item_icon_position_container","menu_item_icon_position","left");
			$panel4->addChild("menu_item_icon_position_container",$menu_item_icon_position_container);
				
				$menu_item_icon_size = new QodePitchField("text","menu_item_icon_size","","Icon Size (px)","Enter icon size in pixels", array(), array("col_width" => 3));
				$menu_item_icon_position_container->addChild("menu_item_icon_size",$menu_item_icon_size);

	$menu_item_style = new QodePitchField("select","menu_item_style","small_item","Item Height in 1st Level Menu","Choose menu item height", array(
			"small_item" => "Small",
			"large_item" => "Big"
		));
	$panel4->addChild("menu_item_style",$menu_item_style);
	
	$menu_item_hover_animation = new QodePitchField("select","menu_item_hover_animation","","Hover Animation in 1st Level Menu","Choose hover animation for items in 1st level", array(
			"default" => "Default",
			"underline_follow" => "Underline Follows",
			"roll" => "Spinning",
			"line_under" => "Underline Lift",
			"line_spread" => "Underline Stretch"
	));
	$panel4->addChild("menu_item_hover_animation",$menu_item_hover_animation);

	$enable_manu_item_border = new QodePitchField("yesno","enable_manu_item_border","no","Enable 1st Level Menu Item Borders","Enabling this option will display border around menu items", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#qodef_menu_item_border_container"));
	$panel4->addChild("enable_manu_item_border",$enable_manu_item_border);
	
        $menu_item_border_container = new QodePitchContainer("menu_item_border_container","enable_manu_item_border","no");
		$panel4->addChild("menu_item_border_container",$menu_item_border_container);
			
			$menu_item_border_style = new QodePitchField("select","menu_item_border_style","","Menu Item Border","Visible only if border width and one of the border color fields are filled.", array(
				   "all_borders" => "All Borders",
				   "top_bottom_borders" => "Top/Bottom Borders",
				   "top_border" => "Top Border",
				   "right_border" => "Right Border",
				   "bottom_border" => "Bottom Border",
				   "bottom_border_double" => "Bottom Double Borders"
				  ),
				array("dependence" => true,
					"hide" => array(
						"bottom_border_double"=>"#qodef_menu_item_border_width_container"
						),
					"show" => array(
						"all_borders"=>"#qodef_menu_item_border_width_container",
						"top_bottom_borders"=>"#qodef_menu_item_border_width_container",
						"top_border"=>"#qodef_menu_item_border_width_container",
						"right_border"=>"#qodef_menu_item_border_width_container",
						"bottom_border"=>"#qodef_menu_item_border_width_container"
					)
				));
			$menu_item_border_container->addChild("menu_item_border_style",$menu_item_border_style);
			
			$menu_item_border_width_container = new QodePitchContainer("menu_item_border_width_container","menu_item_border_style","bottom_border_double");
			$menu_item_border_container->addChild("menu_item_border_width_container",$menu_item_border_width_container);
				$menu_item_border_width = new QodePitchField("text","menu_item_border_width","","Border Width (px)","Enter border width (in pixels) ", array(), array("col_width" => 3));
				$menu_item_border_width_container->addChild("menu_item_border_width",$menu_item_border_width);

				$menu_item_border_radius= new QodePitchField("text","menu_item_border_radius","","Border Radius","Enter border radius (px)", array(), array("col_width" => 3));
				$menu_item_border_width_container->addChild("menu_item_border_radius",$menu_item_border_radius);
				
				$menu_item_border_style_style = new QodePitchField("select","menu_item_border_style_style","solid","Border Style","Choose border style", array(
						"solid" => "Solid",
						"dotted" => "Dotted",
						"dashed" => "Dashed"
					));
				$menu_item_border_width_container->addChild("menu_item_border_style_style",$menu_item_border_style_style);
			$group1 = new QodePitchGroup("Border Color","Choose a color for border");
            $menu_item_border_container->addChild("group1",$group1);
				$row1 = new QodePitchRow();
                $group1->addChild("row1",$row1);
					$menu_item_border_color = new QodePitchField("colorsimple","menu_item_border_color","","Border Color","Choose border color");
					$row1->addChild("menu_item_border_color",$menu_item_border_color);
					$menu_item_hover_border_color = new QodePitchField("colorsimple","menu_item_hover_border_color","","Border Hover Color","Choose border color on menu item hover");
					$row1->addChild("menu_item_hover_border_color",$menu_item_hover_border_color);	
					$menu_item_active_border_color = new QodePitchField("colorsimple","menu_item_active_border_color","","Border Active Color","Choose border color on active menu item");
					$row1->addChild("menu_item_active_border_color",$menu_item_active_border_color);	
					
	$enable_menu_item_separators = new QodePitchField("yesno","enable_menu_item_separators","no","Enable 1st Level Menu Item Separators","Enabling this option will display separators between menu items", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#qodef_menu_item_separators_container"));
	$panel4->addChild("enable_menu_item_separators",$enable_menu_item_separators);
        $menu_item_separators_container = new QodePitchContainer("menu_item_separators_container","enable_menu_item_separators","no");
		$panel4->addChild("menu_item_separators_container",$menu_item_separators_container);
            $group1 = new QodePitchGroup("Menu Item Separators Style","");
            $menu_item_separators_container->addChild("group1",$group1);
                $row1 = new QodePitchRow();
                $group1->addChild("row1",$row1);
				$menu_item_separators_color = new QodePitchField("colorsimple","menu_item_separators_color","","Separators Color","Enter separators color");
				$row1->addChild("menu_item_separators_color",$menu_item_separators_color);
				
	
	$enable_menu_item_text_decoration = new QodePitchField("yesno","enable_menu_item_text_decoration","no","Enable 1st Level Menu Item Text Decoration","Enable this option and choose a text decoration for menu items in first level", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#qodef_menu_item_text_decoration_container"));
	$panel4->addChild("enable_menu_item_text_decoration",$enable_menu_item_text_decoration);
	
	$menu_item_text_decoration_container = new QodePitchContainer("menu_item_text_decoration_container","enable_menu_item_text_decoration","no");
	$panel4->addChild("menu_item_text_decoration_container",$menu_item_text_decoration_container);

		$group1 = new QodePitchGroup("Menu Item Text Decoration","");
		$menu_item_text_decoration_container->addChild("group1",$group1);
			$row1 = new QodePitchRow();
			$group1->addChild("row1",$row1);
			
			$menu_item_text_decoration_style = new QodePitchField("selectsimple","menu_item_text_decoration_style","none","Hover Item Text Decoration","Choose text decoration type for hover menu items", array(
			   "none" => "None",
			   "underline" => "Underline",
			   "line-through" => "Line-through",
			   "overline" => "Overline"
			  ));
			$row1->addChild("menu_item_text_decoration_style",$menu_item_text_decoration_style);
			
			$menu_item_active_text_decoration_style = new QodePitchField("selectsimple","menu_item_active_text_decoration_style","none","Active Item Text Decoration","Choose text decoration type for active menu items", array(
			   "none" => "None",
			   "underline" => "Underline",
			   "line-through" => "Line-through",
			   "overline" => "Overline"
			  ));
			$row1->addChild("menu_item_active_text_decoration_style",$menu_item_active_text_decoration_style);
			
	
    $group1 = new QodePitchGroup("Main Dropdown Menu","Choose a color and transparency for the main menu background (0 = fully transparent, 1 = opaque)");
    $panel4->addChild("group1",$group1);

        $row1 = new QodePitchRow();
        $group1->addChild("row1",$row1);

            $dropdown_background_color = new QodePitchField("colorsimple","dropdown_background_color","","Background Color","This is some description");
            $row1->addChild("dropdown_background_color",$dropdown_background_color);

            $dropdown_background_transparency = new QodePitchField("textsimple","dropdown_background_transparency","","Transparency","This is some description");
            $row1->addChild("dropdown_background_transparency",$dropdown_background_transparency);

            $dropdown_separator_color = new QodePitchField("colorsimple","dropdown_separator_color","","Item Bottom Separator Color","This is some description");
            $row1->addChild("dropdown_separator_color",$dropdown_separator_color);
			
			$dropdown_vertical_separator_color = new QodePitchField("colorsimple","dropdown_vertical_separator_color","","Item Vertical Separator Color","This is some description");
            $row1->addChild("dropdown_vertical_separator_color",$dropdown_vertical_separator_color);

		$row2 = new QodePitchRow();
		$group1->addChild("row2",$row2);

			$enable_dropdown_separator_full_width = new QodePitchField("yesnosimple","enable_dropdown_separator_full_width","no","Item Separator Full Width","This is some description");
			$row2->addChild("enable_dropdown_separator_full_width",$enable_dropdown_separator_full_width);

			
	$group2 = new QodePitchGroup("Main Dropdown Menu Padding","Choose a top/bottom padding for dropdown menu");
    $panel4->addChild("group2",$group2);

        $row1 = new QodePitchRow();
        $group2->addChild("row1",$row1);

            $dropdown_top_padding = new QodePitchField("textsimple","dropdown_top_padding","","Top Padding (px)","This is some description");
            $row1->addChild("dropdown_top_padding",$dropdown_top_padding);
			
			$dropdown_bottom_padding = new QodePitchField("textsimple","dropdown_bottom_padding","","Bottom Padding (px)","This is some description");
            $row1->addChild("dropdown_bottom_padding",$dropdown_bottom_padding);
	
	$menu_dropdown_appearance = new QodePitchField("select","menu_dropdown_appearance","default","Main Dropdown Menu Appearance","Choose appearance for dropdown menu", array(
        "default" => "Default",
        "slide_from_bottom" => "Slide From Bottom",
		"slide_from_top" => "Slide From Top",
		"animate_height" => "Animate Height",
		"slide_from_left" => "Slide From Left"
    ));
    $panel4->addChild("menu_dropdown_appearance",$menu_dropdown_appearance);

	$dropdown_top_position = new QodePitchField("text","dropdown_top_position", "", "Dropdown position", "Enter value in percentage of entire header height", array(), array("col_width" => 3));
	$panel4->addChild("dropdown_top_position", $dropdown_top_position);
	
	$enable_dropdown_menu_item_icon = new QodePitchField("yesno","enable_dropdown_menu_item_icon","no","Enable Arrow Icon for Dropdown Menu","Enabling this option will display an arrow icon for 1st level menu items which have a dropdown menu");
    $panel4->addChild("enable_dropdown_menu_item_icon",$enable_dropdown_menu_item_icon);
			
    $enable_dropdown_top_separator = new QodePitchField("yesno","enable_dropdown_top_separator","no","Enable Dropdown Top Separator","Enabling this option will display top separator for second level in dropdown menu", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#qodef_disable_dropdown_top_separator_container"));
    $panel4->addChild("enable_dropdown_top_separator",$enable_dropdown_top_separator);

        $disable_dropdown_top_separator_container = new QodePitchContainer("disable_dropdown_top_separator_container","enable_dropdown_top_separator","no");
        $panel4->addChild("disable_dropdown_top_separator_container",$disable_dropdown_top_separator_container);

                $dropdown_top_separator_color = new QodePitchField("color","dropdown_top_separator_color","","Dropdown Top Separator Color","Choose color for top separator");
				$disable_dropdown_top_separator_container->addChild("dropdown_top_separator_color",$dropdown_top_separator_color);

    $dropdown_border_around = new QodePitchField("yesno","dropdown_border_around","yes","Enable Dropdown Menu Border","Enabling this option will display border around dropdown menu", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#qodef_dropdown_border_around_container"));
    $panel4->addChild("dropdown_border_around",$dropdown_border_around);

        $dropdown_border_around_container = new QodePitchContainer("dropdown_border_around_container","dropdown_border_around","no");
        $panel4->addChild("dropdown_border_around_container",$dropdown_border_around_container);

                $dropdown_border_around_color = new QodePitchField("color","dropdown_border_around_color","","Dropdown Border Color","Choose a color for border around dropdown menu");
				$dropdown_border_around_container->addChild("dropdown_border_around_color",$dropdown_border_around_color);

    $wide_menu_styles = new QodePitchTitle("wide_menu_styles","Wide Menu");
    $panel4->addChild("wide_menu_styles",$wide_menu_styles);
	
	$enable_wide_manu_background= new QodePitchField("yesno","enable_wide_manu_background","no","Enable Full Width Background for Wide Dropdown Type","Enabling this option will show full width background  for wide dropdown type", array());
	$panel4->addChild("enable_wide_manu_background",$enable_wide_manu_background);

	$wide_image_background= new QodePitchField("image","wide_image_background","","Set Background Image for Wide Dropdown Type","", array());
	$panel4->addChild("wide_image_background",$wide_image_background);

    $group6 = new QodePitchGroup("Wide Dropdown Menu Padding","Choose a top/bottom padding for dropdown wide menu");
    $panel4->addChild("group6",$group6);

        $row1 = new QodePitchRow();
        $group6->addChild("row1",$row1);

            $wide_dropdown_top_padding = new QodePitchField("textsimple","wide_dropdown_top_padding","","Top Padding (px)","This is some description");
            $row1->addChild("wide_dropdown_top_padding",$wide_dropdown_top_padding);

            $wide_dropdown_bottom_padding = new QodePitchField("textsimple","wide_dropdown_bottom_padding","","Bottom Padding (px)","This is some description");
            $row1->addChild("wide_dropdown_bottom_padding",$wide_dropdown_bottom_padding);

    $group3 = new QodePitchGroup("Wide Menu Size","Set size for wide menu width. Note: Wide menu is disabled on mobile menu.");
    $panel4->addChild("group3",$group3);

        $row1 = new QodePitchRow();
        $group3->addChild("row1",$row1);

            $wide_menu_width = new QodePitchField("textsimple","wide_menu_width","","Width (px)","");
            $row1->addChild("wide_menu_width",$wide_menu_width);

            $wide_menu_width_under_1400 = new QodePitchField("textsimple","wide_menu_width_under_1400","","Width (px) under 1400px screen size","");
            $row1->addChild("wide_menu_width_under_1400",$wide_menu_width_under_1400);

            $wide_menu_width_under_1200 = new QodePitchField("textsimple","wide_menu_width_under_1200","","Width (px) under 1200px screen size","");
            $row1->addChild("wide_menu_width_under_1200",$wide_menu_width_under_1200);

    $group4 = new QodePitchGroup("Wide Floating Menu Size ","Set size for floating wide menu width. (Left and Right) Note: Wide menu is disabled on mobile menu.");
    $panel4->addChild("group4",$group4);

        $row1 = new QodePitchRow();
        $group4->addChild("row1",$row1);

            $wide_floating_menu_width = new QodePitchField("textsimple","wide_floating_menu_width","","Width (px)","");
            $row1->addChild("wide_floating_menu_width",$wide_floating_menu_width);

            $wide_floating_menu_width_under_1400 = new QodePitchField("textsimple","wide_floating_menu_width_under_1400","","Width under 1400px screen size (px)","");
            $row1->addChild("wide_floating_menu_width_under_1400",$wide_floating_menu_width_under_1400);

            $wide_floating_menu_width_under_1200 = new QodePitchField("textsimple","wide_floating_menu_width_under_1200","","Width under 1200px screen size (px)","");
            $row1->addChild("wide_floating_menu_width_under_1200",$wide_floating_menu_width_under_1200);

    $group5 = new QodePitchGroup("Wide Floating Menu Position","Set position for floating wide menu on smaller screen");
    $panel4->addChild("group5",$group5);

        $row1 = new QodePitchRow();
        $group5->addChild("row1",$row1);

            $wide_floating_menu_position_1400 = new QodePitchField("textsimple","wide_floating_menu_position_1400","","Position between 1300px and 1400px of screen size (px)","");
            $row1->addChild("wide_floating_menu_position_1400",$wide_floating_menu_position_1400);

            $wide_floating_menu_position_1300 = new QodePitchField("textsimple","wide_floating_menu_position_1300","","Position between 1200px and 1300px of screen size (px)","");
            $row1->addChild("wide_floating_menu_position_1300",$wide_floating_menu_position_1300);

            $wide_floating_menu_position_1200 = new QodePitchField("textsimple","wide_floating_menu_position_1200","","Position between 1100px and 1200px of screen size (px)","");
            $row1->addChild("wide_floating_menu_position_1200",$wide_floating_menu_position_1200);

            $wide_floating_menu_position_1100 = new QodePitchField("textsimple","wide_floating_menu_position_1100","","Position between 1000px and 1100px of screen size (px)","");
            $row1->addChild("wide_floating_menu_position_1100",$wide_floating_menu_position_1100);


$panel3 = new QodePitchPanel("Select Search","enable_search_panel","header_type","",array( "side"));
$headerandfooterPage->addChild("panel3",$panel3);

        $enable_search = new QodePitchField("yesno","enable_search","no","Enable Select Search Bar","This option enables Select Search functionality (search icon will appear next to main navigation)
        ", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#qodef_enable_search_container"));
        $panel3->addChild("enable_search",$enable_search);

        $enable_search_container = new QodePitchContainer("enable_search_container","enable_search","no");
        $panel3->addChild("enable_search_container",$enable_search_container);
			
			$search_type = new QodePitchField("select","search_type","search_slides_from_header_bottom","Select Search Type","Choose a type of Select search bar (Note: Slide From Header Bottom search type doesn't work with transparent header)", array(
				"search_slides_from_header_bottom" => "Slide From Header Bottom",
				"search_covers_header" => "Search Covers Header",
				"fullscreen_search" => "Fullscreen Search",
				"search_slides_from_window_top" => "Slide from Window Top"
			),
			array("dependence" => true,
				"hide" => array(
					"search_covers_header"=>"#qodef_search_height_container,#qodef_search_animation_container",
					"fullscreen_search"=>"#qodef_search_height_container,#qodef_search_cover_header_container",
					"search_slides_from_header_bottom"=>"#qodef_search_animation_container,#qodef_search_cover_header_container",
					"search_slides_from_window_top"=>"#qodef_search_animation_container,#qodef_search_cover_header_container,#qodef_search_height_container"
					),
				"show" => array(
					"search_slides_from_header_bottom"=>"#qodef_search_height_container",
					"fullscreen_search"=>"#qodef_search_animation_container",
					"search_covers_header" => "#qodef_search_cover_header_container",
					"search_slides_from_window_top"=> ""
				)
			));
			$enable_search_container->addChild("search_type",$search_type);

            $search_height_container = new QodePitchContainer("search_height_container","search_type","", array( "search_covers_header","fullscreen_search","search_slides_from_window_top"));
            $enable_search_container->addChild("search_height_container",$search_height_container);

                $search_height= new QodePitchField("text","search_height","","Search bar height","Set search bar height (in pixels)",  array(), array("col_width" => 3));
                $search_height_container->addChild("search_height",$search_height);	
				
			$search_animation_container = new QodePitchContainer("search_animation_container","search_type","", array("search_covers_header","search_slides_from_header_bottom","search_slides_from_window_top"));
	        $enable_search_container->addChild("search_animation_container",$search_animation_container);	
					
				$search_animation = new QodePitchField("select","search_animation","fade","Fullscreen Search Overlay Animation","Choose animation for fullscreen search overlay", array(
					"fade" => "Fade",
					"from_circle" => "Circle appear"
				));
				$search_animation_container->addChild("search_animation",$search_animation);

			$search_cover_header_container = new QodePitchContainer("search_cover_header_container","search_type","",array("fullscreen_search","search_slides_from_header_bottom","search_slides_from_window_top"));
			$enable_search_container->addChild("search_cover_header_container",$search_cover_header_container);

				$search_cover_only_bottom_yesno = new QodePitchField("yesno","search_cover_only_bottom_yesno","no","Cover Only Header Bottom","Enable this option to make search cover only header bottom");
				$search_cover_header_container->addChild("search_cover_only_bottom_yesno",$search_cover_only_bottom_yesno);

			$search_icon_pack = new QodePitchField("select", "search_icon_pack", "font_awesome", "Search Icon Pack", "Choose icon pack for search icon", $qode_pitch_IconCollections->getIconCollectionsExclude('linea_icons'));
			$enable_search_container->addChild("search_icon_pack", $search_icon_pack);

			$search_icon_in_header_top = new QodePitchField("yesno","search_icon_in_header_top","no","Search in Header Top","Enable this option to put search in Header Top");
			$enable_search_container->addChild("search_icon_in_header_top",$search_icon_in_header_top);
			
			
			$initial_header_icon_title = new QodePitchTitle("initial_header_icon_title", "Initial Search Icon in Header");
			$enable_search_container->addChild("initial_header_icon_title", $initial_header_icon_title);
			
			$group7 = new QodePitchGroup("Initial Search Icon","Define size for Search icon in Header");
			$enable_search_container->addChild("group7",$group7);
				$row1 = new QodePitchRow();
				$group7->addChild("row1",$row1);
					$header_search_icon_size= new QodePitchField("textsimple","header_search_icon_size","","Icon Size","Set size for icon (ix pixels)",  array(), array("col_width" => 3));
					$row1->addChild("header_search_icon_size",$header_search_icon_size);

			$group8 = new QodePitchGroup("Icon Background Style","Define background style for icon");
			$enable_search_container->addChild("group8",$group8);

				$row1 = new QodePitchRow();
				$group8->addChild("row1",$row1);

					$search_icon_background_color = new QodePitchField("colorsimple","search_icon_background_color","","Background Color","Choose a background color for Select search icon");
					$row1->addChild("search_icon_background_color",$search_icon_background_color);

					$search_icon_background_hover_color = new QodePitchField("colorsimple","search_icon_background_hover_color","","Background Hover Color","Choose a background hover color for Select search icon");
					$row1->addChild("search_icon_background_hover_color",$search_icon_background_hover_color);

					$search_icon_background_full_height = new QodePitchField("yesnosimple","search_icon_background_full_height","no","Icon Background Full Height","Enabling this option will make seacrh icon background to go full height");
					$row1->addChild("search_icon_background_full_height",$search_icon_background_full_height);
					
					
			$enable_search_icon_text = new QodePitchField("yesno","enable_search_icon_text","no","Enable Search Icon Text","Enable this option to show 'Search' text next to search icon in header", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#qodef_enable_search_icon_text_container"));
			$enable_search_container->addChild("enable_search_icon_text",$enable_search_icon_text);

			$enable_search_icon_text_container = new QodePitchContainer("enable_search_icon_text_container","enable_search_icon_text","no");
			$enable_search_container->addChild("enable_search_icon_text_container",$enable_search_icon_text_container);

				$group1 = new QodePitchGroup("Search Icon Text","Define Style for Search Icon Text");
				$enable_search_icon_text_container->addChild("group1",$group1);

					$row1 = new QodePitchRow();
					$group1->addChild("row1",$row1);

						$search_icon_text_color = new QodePitchField("colorsimple","search_icon_text_color","","Text Color","This is some description");
						$row1->addChild("search_icon_text_color",$search_icon_text_color);
						$search_icon_text_color_hover = new QodePitchField("colorsimple","search_icon_text_color_hover","","Text Hover Color","This is some description");
						$row1->addChild("search_icon_text_color_hover",$search_icon_text_color_hover);
						$search_icon_text_fontsize = new QodePitchField("textsimple","search_icon_text_fontsize","","Font Size (px)","This is some description");
						$row1->addChild("search_icon_text_fontsize",$search_icon_text_fontsize);
						$search_icon_text_lineheight = new QodePitchField("textsimple","search_icon_text_lineheight","","Line Height (px)","This is some description");
						$row1->addChild("search_icon_text_lineheight",$search_icon_text_lineheight);						

					$row2 = new QodePitchRow(true);
					$group1->addChild("row2",$row2);					
					
						$search_icon_text_texttransform = new QodePitchField("selectblanksimple","search_icon_text_texttransform","","Text Transform","This is some description",$qode_pitch_options_texttransform);
						$row2->addChild("search_icon_text_texttransform",$search_icon_text_texttransform);
						$search_icon_text_google_fonts = new QodePitchField("Fontsimple","search_icon_text_google_fonts","-1","Font Family","This is some description");
						$row2->addChild("search_icon_text_google_fonts",$search_icon_text_google_fonts);
						$search_icon_text_fontstyle = new QodePitchField("selectblanksimple","search_icon_text_fontstyle","","Font Style","This is some description",$qode_pitch_options_fontstyle);
						$row2->addChild("search_icon_text_fontstyle",$search_icon_text_fontstyle);
						$search_icon_text_fontweight = new QodePitchField("selectblanksimple","search_icon_text_fontweight","","Font Weight","This is some description",$qode_pitch_options_fontweight);
						$row2->addChild("search_icon_text_fontweight",$search_icon_text_fontweight);						
						
					$row3 = new QodePitchRow(true);
					$group1->addChild("row3",$row3);			
					
						$search_icon_text_letterspacing = new QodePitchField("textsimple","search_icon_text_letterspacing","","Letter Spacing (px)","This is some description");
						$row3->addChild("search_icon_text_letterspacing",$search_icon_text_letterspacing);		
						
			$group6 = new QodePitchGroup("Icon Spacing","Define padding and margins for Search icon");
			$enable_search_container->addChild("group6",$group6);

				$row1 = new QodePitchRow();
				$group6->addChild("row1",$row1);

					$search_padding_left = new QodePitchField("textsimple","search_padding_left","","Padding Left (px)","This is some description");
					$row1->addChild("search_padding_left",$search_padding_left);

					$search_padding_right = new QodePitchField("textsimple","search_padding_right","","Padding Right (px)","This is some description");
					$row1->addChild("search_padding_right",$search_padding_right);
				
					$search_margin_left = new QodePitchField("textsimple","search_margin_left","","Margin Left (px)","This is some description");
					$row1->addChild("search_margin_left",$search_margin_left);

					$search_margin_right = new QodePitchField("textsimple","search_margin_right","","Margin Right (px)","This is some description");
					$row1->addChild("search_margin_right",$search_margin_right);
					
					
			$search_form_title = new QodePitchTitle("search_form_title", "Select Search Bar");
			$enable_search_container->addChild("search_form_title", $search_form_title);		
					
			$search_background_color = new QodePitchField("color","search_background_color","","Background Color","Choose a background color for Select search bar");
			$enable_search_container->addChild("search_background_color",$search_background_color);
			
			$group1 = new QodePitchGroup("Search Input Text","Define Style for Search text");
			$enable_search_container->addChild("group1",$group1);
				$row1 = new QodePitchRow();
				$group1->addChild("row1",$row1);
					$search_text_color = new QodePitchField("colorsimple","search_text_color","","Text Color","This is some description");
					$row1->addChild("search_text_color",$search_text_color);
					$search_text_disabled_color = new QodePitchField("colorsimple","search_text_disabled_color","","Disabled Text Color","This is some description");
					$row1->addChild("search_text_disabled_color",$search_text_disabled_color);
					$search_text_fontsize = new QodePitchField("textsimple","search_text_fontsize","","Font Size (px)","This is some description");
					$row1->addChild("search_text_fontsize",$search_text_fontsize);
					$search_text_texttransform = new QodePitchField("selectblanksimple","search_text_texttransform","","Text Transform","This is some description",$qode_pitch_options_texttransform);
					$row1->addChild("search_text_texttransform",$search_text_texttransform);
					
				$row2 = new QodePitchRow(true);
				$group1->addChild("row2",$row2);
					$search_text_google_fonts = new QodePitchField("fontsimple","search_text_google_fonts","-1","Font Family","This is some description");
					$row2->addChild("search_text_google_fonts",$search_text_google_fonts);
					$search_text_fontstyle = new QodePitchField("selectblanksimple","search_text_fontstyle","","Font Style","This is some description",$qode_pitch_options_fontstyle);
					$row2->addChild("search_text_fontstyle",$search_text_fontstyle);
					$search_text_fontweight = new QodePitchField("selectblanksimple","search_text_fontweight","","Font Weight","This is some description",$qode_pitch_options_fontweight);
					$row2->addChild("search_text_fontweight",$search_text_fontweight);
					$search_text_letterspacing = new QodePitchField("textsimple","search_text_letterspacing","","Letter Spacing (px)","This is some description");
					$row2->addChild("search_text_letterspacing",$search_text_letterspacing);
					
			$group5 = new QodePitchGroup("Search Label Text","Define Style for Search label text");
			$enable_search_container->addChild("group5",$group5);
				$row1 = new QodePitchRow();
				$group5->addChild("row1",$row1);
					$search_label_text_color = new QodePitchField("colorsimple","search_label_text_color","","Text Color","This is some description");
					$row1->addChild("search_label_text_color",$search_label_text_color);
					$search_label_text_fontsize = new QodePitchField("textsimple","search_label_text_fontsize","","Font Size (px)","This is some description");
					$row1->addChild("search_label_text_fontsize",$search_label_text_fontsize);
					$search_label_text_texttransform = new QodePitchField("selectblanksimple","search_label_text_texttransform","","Text Transform","This is some description",$qode_pitch_options_texttransform);
					$row1->addChild("search_label_text_texttransform",$search_label_text_texttransform);
					
				$row2 = new QodePitchRow(true);
				$group5->addChild("row2",$row2);
					$search_label_text_google_fonts = new QodePitchField("fontsimple","search_label_text_google_fonts","-1","Font Family","This is some description");
					$row2->addChild("search_label_text_google_fonts",$search_label_text_google_fonts);
					$search_label_text_fontstyle = new QodePitchField("selectblanksimple","search_label_text_fontstyle","","Font Style","This is some description",$qode_pitch_options_fontstyle);
					$row2->addChild("search_label_text_fontstyle",$search_label_text_fontstyle);
					$search_label_text_fontweight = new QodePitchField("selectblanksimple","search_label_text_fontweight","","Font Weight","This is some description",$qode_pitch_options_fontweight);
					$row2->addChild("search_label_text_fontweight",$search_label_text_fontweight);
					$search_label_text_letterspacing = new QodePitchField("textsimple","search_label_text_letterspacing","","Letter Spacing (px)","This is some description");
					$row2->addChild("search_label_text_letterspacing",$search_label_text_letterspacing);
			
			
			
			$group2 = new QodePitchGroup("Search Icon","Define Style for Search icon");
			$enable_search_container->addChild("group2",$group2);
				$row1 = new QodePitchRow();
				$group2->addChild("row1",$row1);
					$search_icon_color = new QodePitchField("colorsimple","search_icon_color","","Icon Color","Choose icon color for Select search bar");
					$row1->addChild("search_icon_color",$search_icon_color);
					$search_icon_hover_color = new QodePitchField("colorsimple","search_icon_hover_color","","Icon Hover Color","Choose icon hover color for Select search bar");
					$row1->addChild("search_icon_hover_color",$search_icon_hover_color);
					$search_icon_disabled_color = new QodePitchField("colorsimple","search_icon_disabled_color","","Icon Disabled Color","Choose icon disabled color for Select search bar");
					$row1->addChild("search_icon_disabled_color",$search_icon_disabled_color);
					$search_icon_size= new QodePitchField("textsimple","search_icon_size","","Icon Size","Set size for icon (ix pixels)",  array(), array("col_width" => 3));
					$row1->addChild("search_icon_size",$search_icon_size);
					
			
					
			
					
			$group4 = new QodePitchGroup("Search Close","Define style for Search close icon");
			$enable_search_container->addChild("group4",$group4);
				$row1 = new QodePitchRow();
				$group4->addChild("row1",$row1);
					$search_close_color = new QodePitchField("colorsimple","search_close_color","","Icon Color","Choose color for search close icon");
					$row1->addChild("search_close_color",$search_close_color);
					$search_close_hover_color = new QodePitchField("colorsimple","search_close_hover_color","","Icon Hover Color","Choose hover color for search close icon");
					$row1->addChild("search_close_hover_color",$search_close_hover_color);
					$search_close_size = new QodePitchField("textsimple","search_close_size","","Icon Size","Choose size for search close icon");
					$row1->addChild("search_close_size",$search_close_size);
					
			$group3 = new QodePitchGroup("Search Bottom Border","Define style for Search text input bottom border (for Fullscreen search type)");
			$enable_search_container->addChild("group3",$group3);
				$row1 = new QodePitchRow();
				$group3->addChild("row1",$row1);
					$search_border_color = new QodePitchField("colorsimple","search_border_color","","Border Color","Choose border color for search text input");
					$row1->addChild("search_border_color",$search_border_color);
					$search_border_focus_color = new QodePitchField("colorsimple","search_border_focus_color","","Border Focus Color","Choose focus color for search text input");
					$row1->addChild("search_border_focus_color",$search_border_focus_color);
					
							


$panel11 = new QodePitchPanel("Side Area","enable_side_area_panel","header_type","",array( "side"));
$headerandfooterPage->addChild("panel11",$panel11);

    $enable_side_area = new QodePitchField("yesno","enable_side_area","yes","Enable Side Area","This option enables a side area to be opened from main menu navigation", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#qodef_enable_side_area_container"));
    $panel11->addChild("enable_side_area",$enable_side_area);

    $enable_side_area_container = new QodePitchContainer("enable_side_area_container","enable_side_area","no");
    $panel11->addChild("enable_side_area_container",$enable_side_area_container);
		
		$side_area_type = new QodePitchField("select","side_area_type","side_menu_slide_from_right","Side Area Type","Choose a type of Side Area", array(
				"side_menu_slide_from_right" => "Slide from Right Over Content",
				"side_menu_slide_with_content" => "Slide from Right With Content",
				"side_area_uncovered_from_content" => "Side Area Uncovered from Content"
			),
			array("dependence" => true,
			"hide" => array(
      		    "side_menu_slide_from_right"=>"#qodef_side_area_slide_with_content_container",
                "side_menu_slide_with_content"=>"#qodef_side_area_width_container",
				 "side_area_uncovered_from_content"=>"#qodef_side_area_width_container,#qodef_side_area_slide_with_content_container"
				),
			"show" => array(
      		    "side_menu_slide_from_right"=>"#qodef_side_area_width_container",
                "side_menu_slide_with_content"=>"#qodef_side_area_slide_with_content_container",
				 "side_area_uncovered_from_content"=>""
				)
			));
		
		$enable_side_area_container->addChild("side_area_type",$side_area_type);
		
			$side_area_width_container = new QodePitchContainer("side_area_width_container","side_area_type","",array("side_menu_slide_with_content","side_area_uncovered_from_content"));
			$enable_side_area_container->addChild("side_area_width_container",$side_area_width_container);
		
				$side_area_width = new QodePitchField("text","side_area_width","","Side Area Width","Enter a width for Side Area (in percentages, enter more than 30)", array(), array("col_width" => 3));
				$side_area_width_container->addChild("side_area_width",$side_area_width);
				
				$side_area_content_overlay_color= new QodePitchField("color","side_area_content_overlay_color","","Content Overlay Background Color","Choose a background color for a content overlay", array(), array("col_width" => 3));
				$side_area_width_container->addChild("side_area_content_overlay_color",$side_area_content_overlay_color);
				
				$side_area_content_overlay_opacity = new QodePitchField("text","side_area_content_overlay_opacity","","Content Overlay Background Transparency","Choose a transparency for the content overlay background color (0 = fully transparent, 1 = opaque)", array(), array("col_width" => 3));
				$side_area_width_container->addChild("side_area_content_overlay_opacity",$side_area_content_overlay_opacity);

            $side_area_slide_with_content_container = new QodePitchContainer("side_area_slide_with_content_container","side_area_type","",array("side_menu_slide_from_right","side_area_uncovered_from_content"));
            $enable_side_area_container->addChild("side_area_slide_with_content_container",$side_area_slide_with_content_container);

                $side_area_slide_with_content_width = new QodePitchField("select","side_area_slide_with_content_width","width_470","Side Area Width","Choose width for Side Area", array(
                    "width_270" => "270px",
                    "width_370" => "370px",
                    "width_470" => "470px"
                ));
                $side_area_slide_with_content_container->addChild("side_area_slide_with_content_width",$side_area_slide_with_content_width);


		//init icon pack hide and show array. It will be populated dinamically from collections array
		$side_area_icon_pack_hide_array = array();
		$side_area_icon_pack_show_array = array();

		//do we have some collection added in collections array?
		if(is_array($qode_pitch_IconCollections->iconCollections) && count($qode_pitch_IconCollections->iconCollections)) {
			//get collections params array. It will contain values of 'param' property for each collection
			$side_area_icon_collections_params = $qode_pitch_IconCollections->getIconCollectionsParams();

			//foreach collection generate hide and show array
			foreach ($qode_pitch_IconCollections->iconCollections as $dep_collection_key => $dep_collection_object) {
				$side_area_icon_pack_hide_array[$dep_collection_key] = '';

				//we need to include only current collection in show string as it is the only one that needs to show
				$side_area_icon_pack_show_array[$dep_collection_key] = '#qodef_side_area_icon_'.$dep_collection_object->param.'_container';

				//for all collections param generate hide string
				foreach ($side_area_icon_collections_params as $side_area_icon_collections_param) {
					//we don't need to include current one, because it needs to be shown, not hidden
					if($side_area_icon_collections_param !== $dep_collection_object->param) {
						$side_area_icon_pack_hide_array[$dep_collection_key].= '#qodef_side_area_icon_'.$side_area_icon_collections_param.'_container,';
					}
				}

				//remove remaining ',' character
				$side_area_icon_pack_hide_array[$dep_collection_key] = rtrim($side_area_icon_pack_hide_array[$dep_collection_key], ',');
			}

		}

		$side_area_button_icon_pack = new QodePitchField(
			"select",
			"side_area_button_icon_pack",
			"font_awesome",
			"Side Area Button Icon Pack",
			"Choose icon pack for side area button",
			$qode_pitch_IconCollections->getIconCollections(),
			array(
				"dependence" => true,
				"hide" => $side_area_icon_pack_hide_array,
				"show" => $side_area_icon_pack_show_array
			));

		$enable_side_area_container->addChild("side_area_button_icon_pack", $side_area_button_icon_pack);

		if(is_array($qode_pitch_IconCollections->iconCollections) && count($qode_pitch_IconCollections->iconCollections)) {
			//foreach icon collection we need to generate separate container that will have dependency set
			//it will have one field inside with icons dropdown
			foreach ($qode_pitch_IconCollections->iconCollections as $collection_key => $collection_object) {
				$icons_array = $collection_object->getIconsArray();

				//get icon collection keys (keys from collections array, e.g 'font_awesome', 'font_elegant' etc.)
				$icon_collections_keys = $qode_pitch_IconCollections->getIconCollectionsKeys();

				//unset current one, because it doesn't have to be included in dependency that hides icon container
				unset($icon_collections_keys[array_search($collection_key, $icon_collections_keys)]);

				$side_area_icon_hide_values = $icon_collections_keys;
				$side_area_icon_container = new QodePitchContainer("side_area_icon_".$collection_object->param."_container", "side_area_button_icon_pack", "", $side_area_icon_hide_values);
				$side_area_button_icon = new QodePitchField("select", "side_area_icon_".$collection_object->param, "fa-bars", "Side Area Icon","Choose Side Area Icon", $icons_array, array("col_width" => 3));
				$side_area_icon_container->addChild("side_area_icon_".$collection_object->param, $side_area_button_icon);

				$enable_side_area_container->addChild("side_area_icon_".$collection_object->param."_container", $side_area_icon_container);
			}

		}

		$group6 = new QodePitchGroup("Side Area Icon Spacing","Define padding and margin for side area icon");
		$enable_side_area_container->addChild("group6",$group6);

				$row1 = new QodePitchRow();
				$group6->addChild("row1",$row1);

					$side_area_icon_padding_left = new QodePitchField("textsimple","side_area_icon_padding_left","","Padding Left (px)","This is some description");
					$row1->addChild("side_area_icon_padding_left",$side_area_icon_padding_left);

					$side_area_icon_padding_right = new QodePitchField("textsimple","side_area_icon_padding_right","","Padding Right (px)","This is some description");
					$row1->addChild("side_area_icon_padding_right",$side_area_icon_padding_right);
				
					$side_area_icon_margin_left = new QodePitchField("textsimple","side_area_icon_margin_left","","Margin Left (px)","This is some description");
					$row1->addChild("side_area_icon_margin_left",$side_area_icon_margin_left);

					$side_area_icon_margin_right = new QodePitchField("textsimple","side_area_icon_margin_right","","Margin Right (px)","This is some description");
					$row1->addChild("side_area_icon_margin_right",$side_area_icon_margin_right);

		$side_area_icon_border_yesno = new QodePitchField("yesno","side_area_icon_border_yesno","no","Icon Border","Enable border around icon",array(),array(
			"dependence" => true,
			"dependence_hide_on_yes" => "",
			"dependence_show_on_yes" => "#qodef_side_area_icon_border_container"
			));
		$enable_side_area_container->addChild("side_area_icon_border_yesno",$side_area_icon_border_yesno);

		$side_area_icon_border_container = new QodePitchContainer("side_area_icon_border_container","side_area_icon_border_yesno","no");
		$enable_side_area_container->addChild("side_area_icon_border_container",$side_area_icon_border_container);

			$group1 = new QodePitchGroup("Border Style","Define styling for border around icon");
			$side_area_icon_border_container->addChild("group1",$group1);

					$row1 = new QodePitchRow();
					$group1->addChild("row1",$row1);

						$side_area_icon_border_color = new QodePitchField("colorsimple","side_area_icon_border_color","","Color","This is some description");
						$row1->addChild("side_area_icon_border_color",$side_area_icon_border_color);

						$side_area_icon_border_hover_color = new QodePitchField("colorsimple","side_area_icon_border_hover_color","","Hover Color","This is some description");
						$row1->addChild("side_area_icon_border_hover_color",$side_area_icon_border_hover_color);

					$row2 = new QodePitchRow();
					$group1->addChild("row2",$row2);

						$side_area_icon_border_width = new QodePitchField("textsimple","side_area_icon_border_width","","Width (px)","This is some description");
						$row2->addChild("side_area_icon_border_width",$side_area_icon_border_width);

						$side_area_icon_border_radius = new QodePitchField("textsimple","side_area_icon_border_radius","","Radius (px)","This is some description");
						$row2->addChild("side_area_icon_border_radius",$side_area_icon_border_radius);

						$side_area_icon_border_style = new QodePitchField("selectsimple","side_area_icon_border_style","","Style","This is some description",array(
							"solid" => "Solid",
							"dashed" => "Dashed",
							"dotted" => "Dotted"
							));
						$row2->addChild("side_area_icon_border_style",$side_area_icon_border_style);

		$side_area_aligment = new QodePitchField("selectblank","side_area_aligment","","Text Aligment","Choose text aligment for side area", array(
				"center" => "Center",
				"left" => "Left",
				"right" => "Right"

			));

		$enable_side_area_container->addChild("side_area_aligment",$side_area_aligment);
		
		
        $side_area_title = new QodePitchField("text","side_area_title","","Side Area Title","Enter a title to appear in Side Area", array(), array("col_width" => 3));
        $enable_side_area_container->addChild("side_area_title",$side_area_title);

        $side_area_background_color = new QodePitchField("color","side_area_background_color","","Background Color","Choose a background color for Side Area");
        $enable_side_area_container->addChild("side_area_background_color",$side_area_background_color);

		$group5 = new QodePitchGroup("Padding","Define padding for Side Area");
		$enable_side_area_container->addChild("group5",$group5);
			$row1 = new QodePitchRow(true);
			$group5->addChild("row1",$row1);
			$side_area_padding_top = new QodePitchField("textsimple","side_area_padding_top","","Top Padding (px)","This is some description");
				$row1->addChild("side_area_padding_top",$side_area_padding_top);
				$side_area_padding_right = new QodePitchField("textsimple","side_area_padding_right","","Right Padding (px)","This is some description");
				$row1->addChild("side_area_padding_right",$side_area_padding_right);
				$side_area_padding_bottom = new QodePitchField("textsimple","side_area_padding_bottom","","Bottom Padding (px)","This is some description");
				$row1->addChild("side_area_padding_bottom",$side_area_padding_bottom);
				$side_area_padding_left = new QodePitchField("textsimple","side_area_padding_left","","Left Padding (px)","This is some description");
				$row1->addChild("side_area_padding_left",$side_area_padding_left);

		
		$side_area_close_icon = new QodePitchField("select","side_area_close_icon","light","Close Icon Style","Choose a type of close icon", array(
				"light" => "Light",
				"dark" => "Dark"
			));
		
		$enable_side_area_container->addChild("side_area_close_icon",$side_area_close_icon);
		
		$side_area_close_icon_size = new QodePitchField("text","side_area_close_icon_size","","Close Icon Size (px)","Define close icon size",array(), array("col_width" => 3));
		$enable_side_area_container->addChild("side_area_close_icon_size",$side_area_close_icon_size);

        $group1 = new QodePitchGroup("Title","Define Style for Side Area title");
        $enable_side_area_container->addChild("group1",$group1);

            $row1 = new QodePitchRow();
            $group1->addChild("row1",$row1);
                $side_area_title_color = new QodePitchField("colorsimple","side_area_title_color","","Text Color","This is some description");
                $row1->addChild("side_area_title_color",$side_area_title_color);
                $side_area_title_fontsize = new QodePitchField("textsimple","side_area_title_fontsize","","Font Size (px)","This is some description");
                $row1->addChild("side_area_title_fontsize",$side_area_title_fontsize);
                $side_area_title_lineheight = new QodePitchField("textsimple","side_area_title_lineheight","","Line Height (px)","This is some description");
                $row1->addChild("side_area_title_lineheight",$side_area_title_lineheight);
                $side_area_title_texttransform = new QodePitchField("selectblanksimple","side_area_title_texttransform","","Text Transform","This is some description",$qode_pitch_options_texttransform);
                $row1->addChild("side_area_title_texttransform",$side_area_title_texttransform);
            $row2 = new QodePitchRow(true);
            $group1->addChild("row2",$row2);
                $side_area_title_google_fonts = new QodePitchField("fontsimple","side_area_title_google_fonts","-1","Font Family","This is some description");
                $row2->addChild("side_area_title_google_fonts",$side_area_title_google_fonts);
                $side_area_title_fontstyle = new QodePitchField("selectblanksimple","side_area_title_fontstyle","","Font Style","This is some description",$qode_pitch_options_fontstyle);
                $row2->addChild("side_area_title_fontstyle",$side_area_title_fontstyle);
                $side_area_title_fontweight = new QodePitchField("selectblanksimple","side_area_title_fontweight","","Font Weight","This is some description",$qode_pitch_options_fontweight);
                $row2->addChild("side_area_title_fontweight",$side_area_title_fontweight);
                $side_area_title_letterspacing = new QodePitchField("textsimple","side_area_title_letterspacing","","Letter Spacing (px)","This is some description");
                $row2->addChild("side_area_title_letterspacing",$side_area_title_letterspacing);

		$group3 = new QodePitchGroup("Text","Define Style for Side Area text");
        $enable_side_area_container->addChild("group3",$group3);

            $row1 = new QodePitchRow();
            $group3->addChild("row1",$row1);
                $side_area_text_color = new QodePitchField("colorsimple","side_area_text_color","","Text Color","This is some description");
                $row1->addChild("side_area_text_color",$side_area_text_color);
                $side_area_text_fontsize = new QodePitchField("textsimple","side_area_text_fontsize","","Font Size (px)","This is some description");
                $row1->addChild("side_area_text_fontsize",$side_area_text_fontsize);
                $side_area_text_lineheight = new QodePitchField("textsimple","side_area_text_lineheight","","Line Height (px)","This is some description");
                $row1->addChild("side_area_text_lineheight",$side_area_text_lineheight);
                $side_area_text_texttransform = new QodePitchField("selectblanksimple","side_area_text_texttransform","","Text Transform","This is some description",$qode_pitch_options_texttransform);
                $row1->addChild("side_area_text_texttransform",$side_area_text_texttransform);
            $row2 = new QodePitchRow(true);
            $group3->addChild("row2",$row2);
                $side_area_text_google_fonts = new QodePitchField("fontsimple","side_area_text_google_fonts","-1","Font Family","This is some description");
                $row2->addChild("side_area_text_google_fonts",$side_area_text_google_fonts);
                $side_area_text_fontstyle = new QodePitchField("selectblanksimple","side_area_text_fontstyle","","Font Style","This is some description",$qode_pitch_options_fontstyle);
                $row2->addChild("side_area_text_fontstyle",$side_area_text_fontstyle);
                $side_area_text_fontweight = new QodePitchField("selectblanksimple","side_area_text_fontweight","","Font Weight","This is some description",$qode_pitch_options_fontweight);
                $row2->addChild("side_area_text_fontweight",$side_area_text_fontweight);
                $side_area_text_letterspacing = new QodePitchField("textsimple","side_area_text_letterspacing","","Letter Spacing (px)","This is some description");
                $row2->addChild("side_area_text_letterspacing",$side_area_text_letterspacing);


        $group2 = new QodePitchGroup("Link Style","Define styles for side area widget links");
        $enable_side_area_container->addChild("group2",$group2);
            $row1 = new QodePitchRow();
            $group2->addChild("row1",$row1);
                $sidearea_link_color = new QodePitchField("colorsimple","sidearea_link_color","","Text Color","This is some description");
                $row1->addChild("sidearea_link_color",$sidearea_link_color);

                $sidearea_link_font_size = new QodePitchField("textsimple","sidearea_link_font_size","","Font Size (px)","This is some description");
                $row1->addChild("sidearea_link_font_size",$sidearea_link_font_size);

                $sidearea_link_line_height = new QodePitchField("textsimple","sidearea_link_line_height","","Line Height (px)","This is some description");
                $row1->addChild("sidearea_link_line_height",$sidearea_link_line_height);

                $sidearea_link_text_transform = new QodePitchField("selectblanksimple","sidearea_link_text_transform","","Text Transform","This is some description",$qode_pitch_options_texttransform);
                $row1->addChild("sidearea_link_text_transform",$sidearea_link_text_transform);

            $row2 = new QodePitchRow(true);
            $group2->addChild("row2",$row2);
                $sidearea_link_font_family = new QodePitchField("fontsimple","sidearea_link_font_family","-1","Font Family","This is some description");
                $row2->addChild("sidearea_link_font_family",$sidearea_link_font_family);

                $sidearea_link_font_style = new QodePitchField("selectblanksimple","sidearea_link_font_style","","Font Style","This is some description",$qode_pitch_options_fontstyle);
                $row2->addChild("sidearea_link_font_style",$sidearea_link_font_style);

                $sidearea_link_font_weight = new QodePitchField("selectblanksimple","sidearea_link_font_weight","","Font Weight","This is some description",$qode_pitch_options_fontweight);
                $row2->addChild("sidearea_link_font_weight",$sidearea_link_font_weight);

                $sidearea_link_letter_spacing = new QodePitchField("textsimple","sidearea_link_letter_spacing","","Letter Spacing (px)","This is some description");
                $row2->addChild("sidearea_link_letter_spacing",$sidearea_link_letter_spacing);

            $row3 = new QodePitchRow(true);
            $group2->addChild("row3",$row3);
                $sidearea_link_hover_color = new QodePitchField("colorsimple","sidearea_link_hover_color","","Hover Color","This is some description");
                $row3->addChild("sidearea_link_hover_color",$sidearea_link_hover_color);

        $side_area_enable_bottom_border = new QodePitchField("yesno","side_area_enable_bottom_border","no","Border Bottom on Elements","Enable border bottom on elements in side area",array(),array(
            "dependence" => true,
            "dependence_hide_on_yes" => "",
            "dependence_show_on_yes" => "#qodef_side_area_bottom_border_container"
            ));
        $enable_side_area_container->addChild("side_area_enable_bottom_border",$side_area_enable_bottom_border);

        $side_area_bottom_border_container = new QodePitchContainer("side_area_bottom_border_container","side_area_enable_bottom_border","no");
        $enable_side_area_container->addChild("side_area_bottom_border_container",$side_area_bottom_border_container);

            $side_area_bottom_border_color = new QodePitchField("color","side_area_bottom_border_color","","Choose Color for Border Bottom","Choose color for border bottom on elements in sidearea");
            $side_area_bottom_border_container->addChild("side_area_bottom_border_color",$side_area_bottom_border_color);
        
// Fullscreen Menu

$panel12 = new QodePitchPanel("Fullscreen Menu","enable_popup_menu_panel","header_type","",array( "side"));
$headerandfooterPage->addChild("panel12",$panel12);

    $enable_popup_menu = new QodePitchField("yesno","enable_popup_menu","no","Enable Fullscreen Menu","This option enables a fullscreen menu to be opened from main menu navigation", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#qodef_enable_popup_menu_container"));
    $panel12->addChild("enable_popup_menu",$enable_popup_menu);

    $enable_popup_menu_container = new QodePitchContainer("enable_popup_menu_container","enable_popup_menu","no");
    $panel12->addChild("enable_popup_menu_container",$enable_popup_menu_container);

	$popup_menu_animation_style = new QodePitchField("select", "popup_menu_animation_style", "appear_from_bottom", "Fullscreen Menu Overlay Animation", "Choose animation type for fullscreen menu overlay", array(
		'fade_push_text_right' => 'Fade Push Text Right',
		'fade_push_text_top' => 'Fade Push Text Top',
		'fade_text_scaledown' => 'Fade Text Scaledown'
	));
	$enable_popup_menu_container->addChild("popup_menu_animation_style", $popup_menu_animation_style);

    $logo_image_popup = new QodePitchField("image","logo_image_popup","","Logo in Fullscreen Menu Overlay","Place logo in top left corner of fullscreen menu overlay");
    $enable_popup_menu_container->addChild("logo_image_popup",$logo_image_popup);

    $popup_in_grid = new QodePitchField("yesno","popup_in_grid","no","Fullscreen Menu in Grid","Enabling this option will put fullscreen menu content in grid");
    $enable_popup_menu_container->addChild("popup_in_grid",$popup_in_grid);

    $popup_alignment = new QodePitchField("selectblank","popup_alignment","","Fullscreen Menu Alignment","Choose alignment for fullscreen menu content",array(
        "left" => "Left",
        "center" => "Center",
        "right" => "Right"
        ));
    $enable_popup_menu_container->addChild("popup_alignment",$popup_alignment);

    $group4 = new QodePitchGroup("Background","Select a background color and transparency for Fullscreen Menu (0 = fully transparent, 1 = opaque)");
    $enable_popup_menu_container->addChild("group4",$group4);

        $row1 = new QodePitchRow(true);
        $group4->addChild("row1",$row1);

        $popup_menu_background_color = new QodePitchField("colorsimple","popup_menu_background_color","","Background Color","This is some description");
        $row1->addChild("popup_menu_background_color",$popup_menu_background_color);
        $popup_menu_background_transparency = new QodePitchField("textsimple","popup_menu_background_transparency","","Transparency (values:0-1)","This is some description");
        $row1->addChild("popup_menu_background_transparency",$popup_menu_background_transparency);

    $background_image_popup = new QodePitchField("image","background_image_popup","","Background Image","Choose a background image for Fullscreen Menu background");
    $enable_popup_menu_container->addChild("background_image_popup",$background_image_popup);

    $pattern_image_popup = new QodePitchField("image","pattern_image_popup","","Pattern Background Image","Choose a pattern image for Fullscreen Menu background");
    $enable_popup_menu_container->addChild("pattern_image_popup",$pattern_image_popup);

    $group1 = new QodePitchGroup("1st Level Style","Define styles for 1st level in Fullscreen Menu");
    $enable_popup_menu_container->addChild("group1",$group1);

        $row1 = new QodePitchRow();
        $group1->addChild("row1",$row1);

            $popup_menu_color = new QodePitchField("colorsimple","popup_menu_color","","Text Color","This is some description");
            $row1->addChild("popup_menu_color",$popup_menu_color);
            $popup_menu_hover_color = new QodePitchField("colorsimple","popup_menu_hover_color","","Hover Text Color","This is some description");
            $row1->addChild("popup_menu_hover_color",$popup_menu_hover_color);
			$popup_menu_active_color = new QodePitchField("colorsimple","popup_menu_active_color","","Active Text Color","This is some description");
            $row1->addChild("popup_menu_active_color",$popup_menu_active_color);
        
		$row4 = new QodePitchRow();
        $group1->addChild("row4",$row4);
            $popup_menu_hover_background_color = new QodePitchField("colorsimple","popup_menu_hover_background_color","","Background Hover Color","This is some description");
            $row4->addChild("popup_menu_hover_background_color",$popup_menu_hover_background_color);
			$popup_menu_active_background_color = new QodePitchField("colorsimple","popup_menu_active_background_color","","Background Active Color","This is some description");
            $row4->addChild("popup_menu_active_background_color",$popup_menu_active_background_color);
			
		$row2 = new QodePitchRow(true);
        $group1->addChild("row2",$row2);

            $popup_menu_google_fonts = new QodePitchField("fontsimple","popup_menu_google_fonts","-1","Font Family","This is some description");
            $row2->addChild("popup_menu_google_fonts",$popup_menu_google_fonts);
            $popup_menu_fontsize = new QodePitchField("textsimple","popup_menu_fontsize","","Font Size (px)","This is some description");
            $row2->addChild("popup_menu_fontsize",$popup_menu_fontsize);
            $popup_menu_lineheight = new QodePitchField("textsimple","popup_menu_lineheight","","Line Height (px)","This is some description");
            $row2->addChild("popup_menu_lineheight",$popup_menu_lineheight);

        $row3 = new QodePitchRow(true);
        $group1->addChild("row3",$row3);

            $popup_menu_fontstyle = new QodePitchField("selectblanksimple","popup_menu_fontstyle","","Font Style","This is some description",$qode_pitch_options_fontstyle);
            $row3->addChild("popup_menu_fontstyle",$popup_menu_fontstyle);
            $popup_menu_fontweight = new QodePitchField("selectblanksimple","popup_menu_fontweight","","Font Weight","This is some description",$qode_pitch_options_fontweight);
            $row3->addChild("popup_menu_fontweight",$popup_menu_fontweight);
            $popup_menu_letterspacing = new QodePitchField("textsimple","popup_menu_letterspacing","","Letter Spacing (px)","This is some description");
            $row3->addChild("popup_menu_letterspacing",$popup_menu_letterspacing);
            $popup_menu_texttransform = new QodePitchField("selectblanksimple","popup_menu_texttransform","","Text Transform","This is some description",$qode_pitch_options_texttransform);
            $row3->addChild("popup_menu_texttransform",$popup_menu_texttransform);

    $group2 = new QodePitchGroup("2nd Level Style","Define styles for 2nd level in Fullscreen Menu");
    $enable_popup_menu_container->addChild("group2",$group2);

        $row1 = new QodePitchRow();
        $group2->addChild("row1",$row1);

            $popup_menu_color_2nd = new QodePitchField("colorsimple","popup_menu_color_2nd","","Text Color","This is some description");
            $row1->addChild("popup_menu_color_2nd",$popup_menu_color_2nd);
            $popup_menu_hover_color_2nd = new QodePitchField("colorsimple","popup_menu_hover_color_2nd","","Hover Text Color","This is some description");
            $row1->addChild("popup_menu_hover_color_2nd",$popup_menu_hover_color_2nd);
            $popup_menu_hover_background_color_2nd = new QodePitchField("colorsimple","popup_menu_hover_background_color_2nd","","Background Hover Color","This is some description");
            $row1->addChild("popup_menu_hover_background_color_2nd",$popup_menu_hover_background_color_2nd);

        $row2 = new QodePitchRow(true);
        $group2->addChild("row2",$row2);

            $popup_menu_google_fonts_2nd = new QodePitchField("fontsimple","popup_menu_google_fonts_2nd","-1","Font Family","This is some description");
            $row2->addChild("popup_menu_google_fonts_2nd",$popup_menu_google_fonts_2nd);
            $popup_menu_fontsize_2nd = new QodePitchField("textsimple","popup_menu_fontsize_2nd","","Font Size (px)","This is some description");
            $row2->addChild("popup_menu_fontsize_2nd",$popup_menu_fontsize_2nd);
            $popup_menu_lineheight_2nd = new QodePitchField("textsimple","popup_menu_lineheight_2nd","","Line Height (px)","This is some description");
            $row2->addChild("popup_menu_lineheight_2nd",$popup_menu_lineheight_2nd);

        $row3 = new QodePitchRow(true);
        $group2->addChild("row3",$row3);

            $popup_menu_fontstyle_2nd = new QodePitchField("selectblanksimple","popup_menu_fontstyle_2nd","","Font Style","This is some description",$qode_pitch_options_fontstyle);
            $row3->addChild("popup_menu_fontstyle_2nd",$popup_menu_fontstyle_2nd);
            $popup_menu_fontweight_2nd = new QodePitchField("selectblanksimple","popup_menu_fontweight_2nd","","Font Weight","This is some description",$qode_pitch_options_fontweight);
            $row3->addChild("popup_menu_fontweight_2nd",$popup_menu_fontweight_2nd);
            $popup_menu_letterspacing_2nd = new QodePitchField("textsimple","popup_menu_letterspacing_2nd","","Letter Spacing (px)","This is some description");
            $row3->addChild("popup_menu_letterspacing_2nd",$popup_menu_letterspacing_2nd);
            $popup_menu_texttransform_2nd = new QodePitchField("selectblanksimple","popup_menu_texttransform_2nd","","Text Transform","This is some description",$qode_pitch_options_texttransform);
            $row3->addChild("popup_menu_texttransform_2nd",$popup_menu_texttransform_2nd);

    $group3 = new QodePitchGroup("3rd Level Style","Define styles for 3rd level in Fullscreen Menu");
    $enable_popup_menu_container->addChild("group3",$group3);

        $row1 = new QodePitchRow();
        $group3->addChild("row1",$row1);

            $popup_menu_3rd_color = new QodePitchField("colorsimple","popup_menu_3rd_color","","Text Color","This is some description");
            $row1->addChild("popup_menu_3rd_color",$popup_menu_3rd_color);
            $popup_menu_3rd_hover_color = new QodePitchField("colorsimple","popup_menu_3rd_hover_color","","Hover Text Color","This is some description");
            $row1->addChild("popup_menu_3rd_hover_color",$popup_menu_3rd_hover_color);
            $popup_menu_3rd_hover_background_color = new QodePitchField("colorsimple","popup_menu_3rd_hover_background_color","","Background Hover Color","This is some description");
            $row1->addChild("popup_menu_3rd_hover_background_color",$popup_menu_3rd_hover_background_color);

        $row2 = new QodePitchRow(true);
        $group3->addChild("row2",$row2);

            $popup_menu_3rd_google_fonts = new QodePitchField("fontsimple","popup_menu_3rd_google_fonts","-1","Font Family","This is some description");
            $row2->addChild("popup_menu_3rd_google_fonts",$popup_menu_3rd_google_fonts);
            $popup_menu_3rd_fontsize = new QodePitchField("textsimple","popup_menu_3rd_fontsize","","Font Size (px)","This is some description");
            $row2->addChild("popup_menu_3rd_fontsize",$popup_menu_3rd_fontsize);
            $popup_menu_3rd_lineheight = new QodePitchField("textsimple","popup_menu_3rd_lineheight","","Line Height (px)","This is some description");
            $popup_menu_3rd_lineheight = new QodePitchField("textsimple","popup_menu_3rd_lineheight","","Line Height (px)","This is some description");
            $row2->addChild("popup_menu_3rd_lineheight",$popup_menu_3rd_lineheight);

        $row3 = new QodePitchRow(true);
        $group3->addChild("row3",$row3);

            $popup_menu_3rd_fontstyle = new QodePitchField("selectblanksimple","popup_menu_3rd_fontstyle","","Font Style","This is some description",$qode_pitch_options_fontstyle);
            $row3->addChild("popup_menu_3rd_fontstyle",$popup_menu_3rd_fontstyle);
            $popup_menu_3rd_fontweight = new QodePitchField("selectblanksimple","popup_menu_3rd_fontweight","","Font Weight","This is some description",$qode_pitch_options_fontweight);
            $row3->addChild("popup_menu_3rd_fontweight",$popup_menu_3rd_fontweight);
            $popup_menu_3rd_letterspacing = new QodePitchField("textsimple","popup_menu_3rd_letterspacing","","Letter Spacing (px)","This is some description");
            $row3->addChild("popup_menu_3rd_letterspacing",$popup_menu_3rd_letterspacing);
            $popup_menu_3rd_texttransform = new QodePitchField("selectblanksimple","popup_menu_3rd_texttransform","","Text Transform","This is some description",$qode_pitch_options_texttransform);
            $row3->addChild("popup_menu_3rd_texttransform",$popup_menu_3rd_texttransform);


	$group5 = new QodePitchGroup("Full Screen Menu Icon Spacing","Define padding and margin for full screen menu icon");
	$enable_popup_menu_container->addChild("group5",$group5);

			$row1 = new QodePitchRow();
			$group5->addChild("row1",$row1);

				$popup_menu_icon_padding_left = new QodePitchField("textsimple","popup_menu_icon_padding_left","","Padding Left (px)","This is some description");
				$row1->addChild("popup_menu_icon_padding_left",$popup_menu_icon_padding_left);

				$popup_menu_icon_padding_right = new QodePitchField("textsimple","popup_menu_icon_padding_right","","Padding Right (px)","This is some description");
				$row1->addChild("popup_menu_icon_padding_right",$popup_menu_icon_padding_right);
			
				$popup_menu_icon_margin_left = new QodePitchField("textsimple","popup_menu_icon_margin_left","","Margin Left (px)","This is some description");
				$row1->addChild("popup_menu_icon_margin_left",$popup_menu_icon_margin_left);

				$popup_menu_icon_margin_right = new QodePitchField("textsimple","popup_menu_icon_margin_right","","Margin Right (px)","This is some description");
				$row1->addChild("popup_menu_icon_margin_right",$popup_menu_icon_margin_right);


$panel2 = new QodePitchPanel("Header Top","header_top_panel","header_type","",array( "side"));
$headerandfooterPage->addChild("panel2",$panel2);

    $header_top_area = new QodePitchField("yesno","header_top_area","no","Show Header Top Area","Enabling this option will show Header Top area (this setting applies to Header Left and Header Right widgets)
    ", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#qodef_header_top_area_container"));
    $panel2->addChild("header_top_area",$header_top_area);

    $header_top_area_container = new QodePitchContainer("header_top_area_container","header_top_area","no");
    $panel2->addChild("header_top_area_container",$header_top_area_container);

		$header_top_area_scroll_container = new QodePitchContainer("header_top_area_scroll_container","header_bottom_appearance","", array( "fixed_top_header") );
		$header_top_area_container->addChild("header_top_area_scroll_container",$header_top_area_scroll_container);
		
			$header_top_area_scroll = new QodePitchField("yesno","header_top_area_scroll","no","Hide on Scroll","Enabling this option will hide Header Top on scroll (if fixed header types are chosen)");
			$header_top_area_scroll_container->addChild("header_top_area_scroll",$header_top_area_scroll);

        
		$header_top_height = new QodePitchField("text","header_top_height","","Header Top Height","Enter height for header top", array(), array("col_width" => 3));
        $header_top_area_container->addChild("header_top_height",$header_top_height);
		
		$header_top_has_background_pattern= new QodePitchField("yesno","header_top_has_background_pattern","no","Background Pattern Image","Enabling this option will display background pattern image in header top area.
		", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#qodef_header_top_background_pattern_image_container"));
		$header_top_area_container->addChild("header_top_has_background_pattern",$header_top_has_background_pattern);
		
		$header_top_background_pattern_image_container = new QodePitchContainer("header_top_background_pattern_image_container","header_top_has_background_pattern","no");
		$header_top_area_container->addChild("header_top_background_pattern_image_container",$header_top_background_pattern_image_container);
		
			$group10 = new QodePitchGroup("Image","Choose pattern image for header top background");
			$header_top_background_pattern_image_container->addChild("group10",$group10);
				$row1 = new QodePitchRow();
				$group10->addChild("row1",$row1);
				
					$header_top_background_pattern_image = new QodePitchField("imagesimple","header_top_background_pattern_image","","Pattern Image","");
					$row1->addChild("header_top_background_pattern_image",$header_top_background_pattern_image);
		
		$header_top_background_color = new QodePitchField("color","header_top_background_color","","Background Color","Choose a background color for Header Top area");
        $header_top_area_container->addChild("header_top_background_color",$header_top_background_color);
		
		$header_top_transparency = new QodePitchField("text","header_top_transparency","","Header Top Transparency","Choose a transparency for the Header Top background color (0 = fully transparent, 1 = opaque)",array(), array("col_width" => 3));
        $header_top_area_container->addChild("header_top_transparency",$header_top_transparency);

        $top_header_border_color = new QodePitchField("color","top_header_border_color","","Border Bottom Color","Set a color for the bottom border of the Header Top Area.");
        $header_top_area_container->addChild("top_header_border_color",$top_header_border_color);

        $top_header_border_weight = new QodePitchField("text","top_header_border_weight","","Border Width (px)","Set a border width for the bottom border of the Header Top Area.",array(), array("col_width" => 3));
        $header_top_area_container->addChild("top_header_border_weight",$top_header_border_weight);

		$group_header_top_menu = new QodePitchGroup("Menu Item Text Decoration","");
		$header_top_area_container->addChild("group_header_top_menu",$group_header_top_menu);
		
			$row1 = new QodePitchRow();
			$group_header_top_menu->addChild("row1",$row1);
			
			$header_top_menu_item_text_decoration_style = new QodePitchField("selectsimple","header_top_menu_item_text_decoration_style","none","Hover Item Text Decoration","Choose text decoration type for hover menu items", array(
			   "none" => "None",
			   "underline" => "Underline",
			   "line-through" => "Line-through",
			   "overline" => "Overline"
			  ));
			$row1->addChild("header_top_menu_item_text_decoration_style",$header_top_menu_item_text_decoration_style);
			
			$header_top_menu_active_text_decoration_style = new QodePitchField("selectsimple","header_top_menu_active_text_decoration_style","none","Active Item Text Decoration","Choose text decoration type for active menu items", array(
			   "none" => "None",
			   "underline" => "Underline",
			   "line-through" => "Line-through",
			   "overline" => "Overline"
			  ));
			$row1->addChild("header_top_menu_active_text_decoration_style",$header_top_menu_active_text_decoration_style);


        $widget_elements_header_top = new QodePitchTitle("widget_elements_header_top", "Widget Elements");
        $header_top_area_container->addChild("widget_elements_header_top", $widget_elements_header_top);

            $group9 = new QodePitchGroup("Search","Define styles for search in widget");
            $header_top_area_container->addChild("group9",$group9);
            
                $row1 = new QodePitchRow();
                $group9->addChild("row1",$row1);
                
                    $header_top_search_height = new QodePitchField("textsimple","header_top_search_height","","Height (px)","This is some description");
                    $row1->addChild("header_top_search_height",$header_top_search_height);
                    
                    $header_top_search_border_color = new QodePitchField("colorsimple","header_top_search_border_color","","Border Color","This is some description");
                    $row1->addChild("header_top_search_border_color",$header_top_search_border_color);

                    $header_top_search_loupe_color = new QodePitchField("colorsimple","header_top_search_loupe_color","","Magnifier Color","This is some description");
                    $row1->addChild("header_top_search_loupe_color",$header_top_search_loupe_color);
                    
                    $header_top_search_loupe_background_color = new QodePitchField("colorsimple","header_top_search_loupe_background_color","","Magnifier Area Background Color","This is some description");
                    $row1->addChild("header_top_search_loupe_background_color",$header_top_search_loupe_background_color);

                $row2 = new QodePitchRow();
                $group9->addChild("row2",$row2);

                    $header_top_search_text_color = new QodePitchField("colorsimple","header_top_search_text_color","","Text Color","This is some description");
                    $row2->addChild("header_top_search_text_color",$header_top_search_text_color);

                    $header_top_search_focus_text_color = new QodePitchField("colorsimple","header_top_search_focus_text_color","","Focus Text Color","This is some description");
                    $row2->addChild("header_top_search_focus_text_color",$header_top_search_focus_text_color);

                    $header_top_search_text_font_size = new QodePitchField("textsimple","header_top_search_text_font_size","","Font Size (px)","This is some description");
                    $row2->addChild("header_top_search_text_font_size",$header_top_search_text_font_size);

                    $header_top_search_text_line_height = new QodePitchField("textsimple","header_top_search_text_line_height","","Line Height (px)","This is some description");
                    $row2->addChild("header_top_search_text_line_height",$header_top_search_text_line_height);

                $row3 = new QodePitchRow(true);
                $group9->addChild("row3",$row3);

                    $header_top_search_text_text_transform = new QodePitchField("selectblanksimple","header_top_search_text_text_transform","","Text Transform","This is some description",$qode_pitch_options_texttransform);
                    $row3->addChild("header_top_search_text_text_transform",$header_top_search_text_text_transform);

                    $header_top_search_text_font_family = new QodePitchField("fontsimple","header_top_search_text_font_family","-1","Font Family","This is some description");
                    $row3->addChild("header_top_search_text_font_family",$header_top_search_text_font_family);

                    $header_top_search_text_font_style = new QodePitchField("selectblanksimple","header_top_search_text_font_style","","Font Style","This is some description",$qode_pitch_options_fontstyle);
                    $row3->addChild("header_top_search_text_font_style",$header_top_search_text_font_style);

                    $header_top_search_text_font_weight = new QodePitchField("selectblanksimple","header_top_search_text_font_weight","","Font Weight","This is some description",$qode_pitch_options_fontweight);
                    $row3->addChild("header_top_search_text_font_weight",$header_top_search_text_font_weight);

                $row4 = new QodePitchRow(true);
                $group9->addChild("row4",$row4);

                    $header_top_search_text_letter_spacing = new QodePitchField("textsimple","header_top_search_text_letter_spacing","","Letter Spacing (px)","This is some description");
                    $row4->addChild("header_top_search_text_letter_spacing",$header_top_search_text_letter_spacing);

                    $header_top_search_border_around = new QodePitchField("selectsimple","header_top_search_border_around","","Border Around","This is some description",array(
                        "around_everything" => "Around Everything",
                        "around_search_text" => "Around Search Text"
                        ));
                    $row4->addChild("header_top_search_border_around",$header_top_search_border_around);

                $row5 = new QodePitchRow(true);
                $group9->addChild("row5",$row5);

                    $header_top_search_width = new QodePitchField("textsimple","header_top_search_width","","Width (px)","This is some description");
                    $row5->addChild("header_top_search_text_font_size",$header_top_search_width);

                    $header_top_search_margin_left = new QodePitchField("textsimple","header_top_search_margin_left","","Left Margin (px)","This is some description");
                    $row5->addChild("header_top_search_margin_left",$header_top_search_margin_left);

                    $header_top_search_margin_right = new QodePitchField("textsimple","header_top_search_margin_right","","Right Margin (px)","This is some description");
                    $row5->addChild("header_top_search_margin_right",$header_top_search_margin_right);

	
	$panel7 = new QodePitchPanel("Side Menu Area","vertical_areas_panel","header_type","",array( "top"));
    $headerandfooterPage->addChild("panel7",$panel7);

    $vertical_area_type = new QodePitchField("select","vertical_area_type","left","Side Menu Area Type","Specify menu type", array(
        "" => "Always Opened (Default)",
        "hidden" => "Initially Hidden",
		"hidden_with_icons" => "Initially Hidden With Visible Icons"
    ),
    array("dependence" => true,
       "hide" => array(
            ""=>"#qodef_vertical_area_hidden_button_color_container",
            "hidden"=>"",
			"hidden_with_icons"=>"#qodef_enable_vertical_menu_item_left_border_container"),
        "show" => array(
            ""=>"#qodef_enable_vertical_menu_item_left_border_container",
            "hidden"=>"#qodef_vertical_area_hidden_button_color_container, #qodef_enable_vertical_menu_item_left_border_container",
			"hidden_with_icons"=>"#qodef_vertical_area_hidden_button_color_container")
    ));
    $panel7->addChild("vertical_area_type",$vertical_area_type);

    $vertical_area_hidden_button_color_container = new QodePitchContainer("vertical_area_hidden_button_color_container","vertical_area_type","");
    $panel7->addChild("vertical_area_hidden_button_color_container",$vertical_area_hidden_button_color_container);

        $vertical_area_hidden_button_color = new QodePitchField("color","vertical_area_hidden_button_color","","Button Color","Choose a color for button that opens/closes Hidden Side Menu Area");
        $vertical_area_hidden_button_color_container->addChild("vertical_area_hidden_button_color",$vertical_area_hidden_button_color);

	$vertical_area_width = new QodePitchField("select","vertical_area_width","width_290","Side Menu Area Width","Choose width for side menu area.", array(
        "width_290" => "290px",
        "width_350" => "350px",
		"width_400" => "400px"
    ));
    $panel7->addChild("vertical_area_width",$vertical_area_width);
	
	$vertical_area_position = new QodePitchField("select","vertical_area_position","left","Side Menu Area Position","Choose side menu position relative to browser screen", array(
        "left" => "Left",
        "right" => "Right"
    ));
    $panel7->addChild("vertical_area_position",$vertical_area_position);

    $vertical_area_dropdown_showing = new QodePitchField("select","vertical_area_dropdown_showing","hover","Submenu Opening Behaviour","Specify 2nd and 3rd level menu opening style", array(
        "hover" => "On Hover",
        "click" => "On Click",
        "side" => "Slide In",
        "to_content" => "Float"
    ),
    array("dependence" => true,
        "hide" => array(
            "hover"=>"#qodef_vertical_area_dropdown_background_container, #qodef_vertical_menu_dd_separator_container",
            "click"=>"#qodef_vertical_area_dropdown_background_container, #qodef_vertical_menu_dd_separator_container",
            "side"=>"#qodef_vertical_area_transparency_container, #qodef_vertical_area_background_container, #qodef_vertical_area_dropdown_background_container, #qodef_vertical_menu_dd_separator_container",
            "to_content" => ""),
        "show" => array(
            "hover"=>"#qodef_vertical_area_transparency_container, #qodef_vertical_area_background_container",
            "click"=>"#qodef_vertical_area_transparency_container, #qodef_vertical_area_background_container",
            "side"=>"",
            "to_content" => "#qodef_vertical_area_transparency_container, #qodef_vertical_area_background_container, #qodef_vertical_area_dropdown_background_container, #qodef_vertical_menu_dd_separator_container"
        )
    ));
    $panel7->addChild("vertical_area_dropdown_showing",$vertical_area_dropdown_showing);

	$vertical_area_background = new QodePitchField("color","vertical_area_background","","Side Menu Area Background Color","Choose a color for Side Menu Area background");
	$panel7->addChild("vertical_area_background",$vertical_area_background);

    $vertical_area_transparency_container = new QodePitchContainer("vertical_area_transparency_container","vertical_area_dropdown_showing","side");
    $panel7->addChild("vertical_area_transparency_container",$vertical_area_transparency_container);
	
		$vertical_area_background_transparency = new QodePitchField("text","vertical_area_background_transparency","","Side Menu Area Background Opacity","Choose a opacity for the Side Menu Area Background (0 = fully transparent, 1 = opaque)", array(), array("col_width" => 3));
		$vertical_area_transparency_container->addChild("vertical_area_background_transparency",$vertical_area_background_transparency);

		$vertical_area_background_container = new QodePitchContainer("vertical_area_background_container","vertical_area_dropdown_showing","side");
		$vertical_area_transparency_container->addChild("vertical_area_background_container",$vertical_area_background_container);

			$vertical_area_background_image = new QodePitchField("image","vertical_area_background_image","","Side Menu Area Background Image","Choose an image for Side Menu background");
			$vertical_area_background_container->addChild("vertical_area_background_image",$vertical_area_background_image);

        
		
		$vertical_area_transparency_over_slider = new QodePitchField("yesno","vertical_area_transparency_over_slider","no","Transparency Setting Takes Effect Only on Select Slider","Enabling this option will ensure that the transparency set in the 'Side Menu Area Background Opacity' takes effect only when the side menu area is over the Qode Slider",  array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => ""));
        $vertical_area_transparency_container->addChild("vertical_area_transparency_over_slider",$vertical_area_transparency_over_slider);
		
		
		$vertical_area_transparency = new QodePitchField("yesno","vertical_area_transparency","no","Enable Fully Transparent Side Menu Area Over Qode Slider","Enabling this option will make Side Menu Area background over Qode Slider fully transparent",  array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#qodef_vertical_area_transparency_fonts_container"));
        $vertical_area_transparency_container->addChild("vertical_area_transparency",$vertical_area_transparency);
			
			$vertical_area_transparency_fonts_container = new QodePitchContainer("vertical_area_transparency_fonts_container","vertical_area_transparency","no");
			$vertical_area_transparency_container->addChild("vertical_area_transparency_fonts_container",$vertical_area_transparency_fonts_container);
			
				$group1 = new QodePitchGroup("1st Level Transparent Menu Style","Define styles for 1st level in Transparent Side Menu");
				$vertical_area_transparency_fonts_container->addChild("group1",$group1);

					$row1 = new QodePitchRow();
					$group1->addChild("row1",$row1);

						$vertical_transparent_menu_color = new QodePitchField("colorsimple","vertical_transparent_menu_color","","Text Color","This is some description");
						$row1->addChild("vertical_transparent_menu_color",$vertical_transparent_menu_color);
						$vertical_transparent_menu_hovercolor = new QodePitchField("colorsimple","vertical_transparent_menu_hovercolor","","Hover Color","This is some description");
						$row1->addChild("vertical_transparent_menu_hovercolor",$vertical_transparent_menu_hovercolor);
						$vertical_transparent_menu_activecolor = new QodePitchField("colorsimple","vertical_transparent_menu_activecolor","","Active Color","This is some description");
						$row1->addChild("vertical_transparent_menu_activecolor",$vertical_transparent_menu_activecolor);

					$row2 = new QodePitchRow(true);
					$group1->addChild("row2",$row2);

						$vertical_transparent_menu_google_fonts = new QodePitchField("fontsimple","vertical_transparent_menu_google_fonts","-1","Font family","This is some description");
						$row2->addChild("vertical_transparent_menu_google_fonts",$vertical_transparent_menu_google_fonts);
						$vertical_transparent_menu_fontsize = new QodePitchField("textsimple","vertical_transparent_menu_fontsize","","Font size (px)","This is some description");
						$row2->addChild("vertical_transparent_menu_fontsize",$vertical_transparent_menu_fontsize);
						$vertical_transparent_menu_lineheight = new QodePitchField("textsimple","vertical_transparent_menu_lineheight","","Line Height (px)","This is some description");
						$row2->addChild("vertical_transparent_menu_lineheight",$vertical_transparent_menu_lineheight);
					
					$row3 = new QodePitchRow(true);
					$group1->addChild("row3",$row3);

						$vertical_transparent_menu_fontstyle = new QodePitchField("selectblanksimple","vertical_transparent_menu_fontstyle","","Font Style","This is some description",$qode_pitch_options_fontstyle);
						$row3->addChild("vertical_transparent_menu_fontstyle",$vertical_transparent_menu_fontstyle);
						$vertical_transparent_menu_fontweight = new QodePitchField("selectblanksimple","vertical_transparent_menu_fontweight","","Font Weight","This is some description",$qode_pitch_options_fontweight);
						$row3->addChild("vertical_transparent_menu_fontweight",$vertical_transparent_menu_fontweight);
						$vertical_transparent_menu_letterspacing = new QodePitchField("textsimple","vertical_transparent_menu_letterspacing","","Letter Spacing (px)","This is some description");
						$row3->addChild("vertical_transparent_menu_letterspacing",$vertical_transparent_menu_letterspacing);
						$vertical_transparent_menu_texttransform = new QodePitchField("selectblanksimple","vertical_transparent_menu_texttransform","","Text Transform","This is some description",$qode_pitch_options_texttransform);
						$row3->addChild("vertical_transparent_menu_texttransform",$vertical_transparent_menu_texttransform);
	
				$group2 = new QodePitchGroup("2nd Level Transparent Menu Style","Define styles for 2nd level in Transparent Side Menu");
				$vertical_area_transparency_fonts_container->addChild("group2",$group2);

					$row1 = new QodePitchRow();
					$group2->addChild("row1",$row1);

						$vertical_transparent_dropdown_color = new QodePitchField("colorsimple","vertical_transparent_dropdown_color","","Text Color","This is some description");
						$row1->addChild("vertical_transparent_dropdown_color",$vertical_transparent_dropdown_color);
						$vertical_transparent_dropdown_hovercolor = new QodePitchField("colorsimple","vertical_transparent_dropdown_hovercolor","","Hover Color","This is some description");
						$row1->addChild("vertical_transparent_dropdown_hovercolor",$vertical_transparent_dropdown_hovercolor);

					$row2 = new QodePitchRow(true);
					$group2->addChild("row2",$row2);

						$vertical_transparent_dropdown_google_fonts = new QodePitchField("fontsimple","vertical_transparent_dropdown_google_fonts","-1","Font Family","This is some description");
						$row2->addChild("vertical_transparent_dropdown_google_fonts",$vertical_transparent_dropdown_google_fonts);
						$vertical_transparent_dropdown_fontsize = new QodePitchField("textsimple","vertical_transparent_dropdown_fontsize","","Font Size (px)","This is some description");
						$row2->addChild("vertical_transparent_dropdown_fontsize",$vertical_transparent_dropdown_fontsize);
						$vertical_transparent_dropdown_lineheight = new QodePitchField("textsimple","vertical_transparent_dropdown_lineheight","","Line Height (px)","This is some description");
						$row2->addChild("vertical_transparent_dropdown_lineheight",$vertical_transparent_dropdown_lineheight);
					
					$row3 = new QodePitchRow(true);
					$group2->addChild("row3",$row3);

						$vertical_transparent_dropdown_fontstyle = new QodePitchField("selectblanksimple","vertical_transparent_dropdown_fontstyle","","Font Style","This is some description",$qode_pitch_options_fontstyle);
						$row3->addChild("vertical_transparent_dropdown_fontstyle",$vertical_transparent_dropdown_fontstyle);
						$vertical_transparent_dropdown_fontweight = new QodePitchField("selectblanksimple","vertical_transparent_dropdown_fontweight","","Font Weight","This is some description",$qode_pitch_options_fontweight);
						$row3->addChild("vertical_transparent_dropdown_fontweight",$vertical_transparent_dropdown_fontweight);
						$vertical_transparent_dropdown_letterspacing = new QodePitchField("textsimple","vertical_transparent_dropdown_letterspacing","","Letter Spacing (px)","This is some description");
						$row3->addChild("vertical_transparent_dropdown_letterspacing",$vertical_transparent_dropdown_letterspacing);
						$vertical_transparent_dropdown_texttransform = new QodePitchField("selectblanksimple","vertical_transparent_dropdown_texttransform","","Text Transform","This is some description",$qode_pitch_options_texttransform);
						$row3->addChild("vertical_transparent_dropdown_texttransform",$vertical_transparent_dropdown_texttransform);

				$group3 = new QodePitchGroup("3rd Level Transparent Menu Style","Define styles for 3rd level in Transparent Side Menu");
				$vertical_area_transparency_fonts_container->addChild("group3",$group3);

					$row1 = new QodePitchRow();
					$group3->addChild("row1",$row1);

						$vertical_transparent_dropdown_color_thirdlvl = new QodePitchField("colorsimple","vertical_transparent_dropdown_color_thirdlvl","","Text Color","This is some description");
						$row1->addChild("vertical_transparent_dropdown_color_thirdlvl",$vertical_transparent_dropdown_color_thirdlvl);
						$vertical_transparent_dropdown_hovercolor_thirdlvl = new QodePitchField("colorsimple","vertical_transparent_dropdown_hovercolor_thirdlvl","","Hover Color","This is some description");
						$row1->addChild("vertical_transparent_dropdown_hovercolor_thirdlvl",$vertical_transparent_dropdown_hovercolor_thirdlvl);

					$row2 = new QodePitchRow(true);
					$group3->addChild("row2",$row2);

						$vertical_transparent_dropdown_google_fonts_thirdlvl = new QodePitchField("fontsimple","vertical_transparent_dropdown_google_fonts_thirdlvl","-1","Font Family","This is some description");
						$row2->addChild("vertical_transparent_dropdown_google_fonts_thirdlvl",$vertical_transparent_dropdown_google_fonts_thirdlvl);
						$vertical_transparent_dropdown_fontsize_thirdlvl = new QodePitchField("textsimple","vertical_transparent_dropdown_fontsize_thirdlvl","","Font Size (px)","This is some description");
						$row2->addChild("vertical_transparent_dropdown_fontsize_thirdlvl",$vertical_transparent_dropdown_fontsize_thirdlvl);
						$vertical_transparent_dropdown_lineheight_thirdlvl = new QodePitchField("textsimple","vertical_transparent_dropdown_lineheight_thirdlvl","","Line Height (px)","This is some description");
						$row2->addChild("vertical_transparent_dropdown_lineheight_thirdlvl",$vertical_transparent_dropdown_lineheight_thirdlvl);
					
					$row3 = new QodePitchRow(true);
					$group3->addChild("row3",$row3);

						$vertical_transparent_dropdown_fontstyle_thirdlvl = new QodePitchField("selectblanksimple","vertical_transparent_dropdown_fontstyle_thirdlvl","","Font Style","This is some description",$qode_pitch_options_fontstyle);
						$row3->addChild("vertical_transparent_dropdown_fontstyle_thirdlvl",$vertical_transparent_dropdown_fontstyle_thirdlvl);
						$vertical_transparent_dropdown_fontweight_thirdlvl = new QodePitchField("selectblanksimple","vertical_transparent_dropdown_fontweight_thirdlvl","","Font Weight","This is some description",$qode_pitch_options_fontweight);
						$row3->addChild("vertical_transparent_dropdown_fontweight_thirdlvl",$vertical_transparent_dropdown_fontweight_thirdlvl);
						$vertical_transparent_dropdown_letterspacing_thirdlvl = new QodePitchField("textsimple","vertical_transparent_dropdown_letterspacing_thirdlvl","","Letter Spacing (px)","This is some description");
						$row3->addChild("vertical_transparent_dropdown_letterspacing_thirdlvl",$vertical_transparent_dropdown_letterspacing_thirdlvl);
						$vertical_transparent_dropdown_texttransform_thirdlvl = new QodePitchField("selectblanksimple","vertical_transparent_dropdown_texttransform_thirdlvl","","Text Transform","This is some description",$qode_pitch_options_texttransform);
						$row3->addChild("vertical_transparent_dropdown_texttransform_thirdlvl",$vertical_transparent_dropdown_texttransform_thirdlvl);     
		
		

    $vertical_area_dropdown_background_container = new QodePitchContainer("vertical_area_dropdown_background_container","vertical_area_dropdown_showing","side",array("side","hover","click"));
    $panel7->addChild("vertical_area_dropdown_background_container",$vertical_area_dropdown_background_container);

        $group1 = new QodePitchGroup("Dropdown Menu Background","Choose Background for dropdown menu");
        $vertical_area_dropdown_background_container->addChild("group1",$group1);

            $row1 = new QodePitchRow();
            $group1->addChild("row1",$row1);

                $vertical_area_dropdown_menu_bckg_color = new QodePitchField("colorsimple","vertical_area_dropdown_menu_bckg_color","","Background Color","This is some description");
                $row1->addChild("vertical_area_dropdown_menu_bckg_color",$vertical_area_dropdown_menu_bckg_color);

                $vertical_area_dropdown_menu_bckg_opacity = new QodePitchField("textsimple","vertical_area_dropdown_menu_bckg_opacity","","Opacity (0-1)","This is some description");
                $row1->addChild("vertical_area_dropdown_menu_bckg_opacity",$vertical_area_dropdown_menu_bckg_opacity);

        $vertical_area_menu_items_arrow= new QodePitchField("yesno","vertical_area_menu_items_arrow","no","2nd level menu arrow shape","Enabling this option will display arrow shape on 2nd level menu");
        $vertical_area_dropdown_background_container->addChild("vertical_area_menu_items_arrow",$vertical_area_menu_items_arrow);

    $vertical_area_padding = new QodePitchField("text","vertical_area_padding","","Side Menu Area Padding","Set padding for Side Menu Area in pixels (default value is 20px 40px 20px 40px)", array(), array("col_width" => 3));
    $panel7->addChild("vertical_area_padding",$vertical_area_padding);
	
	$vertical_area_navigation_top_margin = new QodePitchField("text","vertical_area_navigation_top_margin","","Navigation Top Margin","Set the space between logo and navigation in pixels (default value is 40px)", array(), array("col_width" => 3));
    $panel7->addChild("vertical_area_navigation_top_margin",$vertical_area_navigation_top_margin);

    $vertical_area_text_color = new QodePitchField("color","vertical_area_text_color","","Side Menu Area Text Color (for Widgets)","Choose a text color for widgets in Side Menu");
    $panel7->addChild("vertical_area_text_color",$vertical_area_text_color);

    $vertical_area_alignment = new QodePitchField("selectblank","vertical_area_alignment","","Side Menu Area Aligment","Specify alignment for logo, menu and widgets.", array(
        "left" => "Left",
        "center" => "Center",
        "right" => "Right"
    ));
    $panel7->addChild("vertical_area_alignment",$vertical_area_alignment);
	
	
	$vertical_area_right_border_color = new QodePitchField("color","vertical_area_right_border_color","","Side Menu Area Right Border Color","Choose a color for right border of side menu area");
    $panel7->addChild("vertical_area_right_border_color",$vertical_area_right_border_color);
	

    $vertical_menu_submenu_sign = new QodePitchField("yesno","vertical_menu_submenu_sign","yes","Enable Plus Sign","Enable dropdown plus sign");
    $panel7->addChild("vertical_menu_submenu_sign",$vertical_menu_submenu_sign);
	
	$vertical_menu_first_level = new QodePitchTitle("vertical_menu_first_level", "First Level Menu");
	$panel7->addChild("vertical_menu_first_level", $vertical_menu_first_level);
	
	$vertical_area_menu_items_padding = new QodePitchField("text","vertical_area_menu_items_padding","","Menu Items Top/Bottom Padding","Enter padding for top and bottom of menu items in menu first level (px)", array(), array("col_width" => 3));
    $panel7->addChild("vertical_area_menu_items_padding",$vertical_area_menu_items_padding);
	

    $full_width_vertical_menu_items = new QodePitchField("yesno","full_width_vertical_menu_items","no","Full Width Menu Items","Enabling this option will set menu item area to full width of vertical menu", array(), array("dependence" => true, "dependence_hide_on_yes" => "#qodef_vertical_menu_separators_width_container", "dependence_show_on_yes" => "#qodef_vertical_menu_top_bottom_separators_container"));
    $panel7->addChild("full_width_vertical_menu_items",$full_width_vertical_menu_items);
	
	$enable_vertical_menu_separators= new QodePitchField("yesno","enable_vertical_menu_separators","no","Enable Menu Item Separators","Enabling this option will display menu item separators", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#qodef_vertical_menu_separators_container"));
    $panel7->addChild("enable_vertical_menu_separators",$enable_vertical_menu_separators);

        $vertical_menu_separators_container = new QodePitchContainer("vertical_menu_separators_container","enable_vertical_menu_separators","no");
        $panel7->addChild("vertical_menu_separators_container",$vertical_menu_separators_container);

            $vertical_menu_separators_width_container = new QodePitchContainer("vertical_menu_separators_width_container","full_width_vertical_menu_items","yes");
            $vertical_menu_separators_container->addChild("vertical_menu_separators_width_container",$vertical_menu_separators_width_container);
			
			
			
            $vertical_menu_separators_width = new QodePitchField("text","vertical_menu_separators_width","","Width (px)","Enter width for the separators", array(), array("col_width" => 1));
            $vertical_menu_separators_width_container->addChild("vertical_menu_separators_width",$vertical_menu_separators_width);
			
			$vertical_menu_separators_color = new QodePitchField("color","vertical_menu_separators_color","","Color","Choose a color for the menu item separators.");
            $vertical_menu_separators_container->addChild("vertical_menu_separators_color",$vertical_menu_separators_color);
			
			
			
			$vertical_menu_top_bottom_separators_container = new QodePitchContainer("vertical_menu_top_bottom_separators_container","full_width_vertical_menu_items","no");
            $vertical_menu_separators_container->addChild("vertical_menu_top_bottom_separators_container",$vertical_menu_top_bottom_separators_container);
			
				$enable_vertical_menutop_bottom_separators= new QodePitchField("yesno","enable_vertical_menutop_bottom_separators","no","Enable Menu Top and Bottom Separators","Enabling this option will display separators at top and bottom of menu also");
				$vertical_menu_top_bottom_separators_container->addChild("enable_vertical_menutop_bottom_separators",$enable_vertical_menutop_bottom_separators);
			
			
	
	$enable_vertical_menu_items_background= new QodePitchField("yesno","enable_vertical_menu_items_background","no","Enable Background for 1st Level Menu Items","Enable this option and choose background color for items in first level menu", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#qodef_vertical_menu_items_background_container"));
    $panel7->addChild("enable_vertical_menu_items_background",$enable_vertical_menu_items_background);

		$vertical_menu_items_background_container = new QodePitchContainer("vertical_menu_items_background_container","enable_vertical_menu_items_background","no");
		$panel7->addChild("vertical_menu_items_background_container",$vertical_menu_items_background_container);

			$vertical_menu_items_background_color = new QodePitchField("color","vertical_menu_items_background_color","","Background Color","Choose a background color for the menu items");
			$vertical_menu_items_background_container->addChild("vertical_menu_items_background_color",$vertical_menu_items_background_color);
			
			$vertical_menu_items_hover_background_color = new QodePitchField("color","vertical_menu_items_hover_background_color","","Hover Background Color","Choose a background color for the hover menu items");
			$vertical_menu_items_background_container->addChild("vertical_menu_items_hover_background_color",$vertical_menu_items_hover_background_color);
			
			$vertical_menu_items_active_background_color = new QodePitchField("color","vertical_menu_items_active_background_color","","Active Background Color","Choose a background color for the active menu items");
			$vertical_menu_items_background_container->addChild("vertical_menu_items_active_background_color",$vertical_menu_items_active_background_color);
		
		
	$enable_vertical_menu_item_left_border_container = new QodePitchContainer("enable_vertical_menu_item_left_border_container","vertical_area_type","hidden_with_icons");
	$panel7->addChild("enable_vertical_menu_item_left_border_container",$enable_vertical_menu_item_left_border_container);
	
		$enable_vertical_menu_item_left_border= new QodePitchField("yesno","enable_vertical_menu_item_left_border","no","Enable Left Border for 1st Level Menu Items","Enabling this option will display left border in first level menu items", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#qodef_vertical_menu_item_left_border_container"));
		$enable_vertical_menu_item_left_border_container->addChild("enable_vertical_menu_item_left_border",$enable_vertical_menu_item_left_border);

			$vertical_menu_item_left_border_container = new QodePitchContainer("vertical_menu_item_left_border_container","enable_vertical_menu_item_left_border","no");
			$panel7->addChild("vertical_menu_item_left_border_container",$vertical_menu_item_left_border_container);


				$vertical_menu_item_left_border_width = new QodePitchField("text","vertical_menu_item_left_border_width","","Border Width (px)","Enter width for the menu item border", array(), array("col_width" => 1));
				$vertical_menu_item_left_border_container->addChild("vertical_menu_item_left_border_width",$vertical_menu_item_left_border_width);
				
				$vertical_menu_item_left_border_color = new QodePitchField("color","vertical_menu_item_left_border_color","","Border Color","Choose a color for the menu item border");
				$vertical_menu_item_left_border_container->addChild("vertical_menu_item_left_border_color",$vertical_menu_item_left_border_color);
				
				$vertical_menu_item_left_border_hover_color = new QodePitchField("color","vertical_menu_item_left_border_hover_color","","Border Hover Color","Choose a hover color for the menu item border");
				$vertical_menu_item_left_border_container->addChild("vertical_menu_item_left_border_hover_color",$vertical_menu_item_left_border_hover_color);
				
				$vertical_menu_item_left_border_active_color = new QodePitchField("color","vertical_menu_item_left_border_active_color","","Border Active Color","Choose a color for the active menu item border");
				$vertical_menu_item_left_border_container->addChild("vertical_menu_item_left_border_active_color",$vertical_menu_item_left_border_active_color);
	
	
	$enable_vertical_menu_item_text_decoration = new QodePitchField("yesno","enable_vertical_menu_item_text_decoration","no","Enable 1st Level Menu Item Text Decoration","Enable this option and choose a text decoration for menu items in first level", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#qodef_vertical_menu_item_text_decoration_container"));
	$panel7->addChild("enable_vertical_menu_item_text_decoration",$enable_vertical_menu_item_text_decoration);
	
		$vertical_menu_item_text_decoration_container = new QodePitchContainer("vertical_menu_item_text_decoration_container","enable_vertical_menu_item_text_decoration","no");
		$panel7->addChild("vertical_menu_item_text_decoration_container",$vertical_menu_item_text_decoration_container);

			$group1 = new QodePitchGroup("Menu Item Text Decoration","");
			$vertical_menu_item_text_decoration_container->addChild("group1",$group1);
				$row1 = new QodePitchRow();
				$group1->addChild("row1",$row1);
				
				$vertical_menu_item_text_decoration_style = new QodePitchField("selectsimple","vertical_menu_item_text_decoration_style","none","Hover Item Text Decoration","Choose text decoration type for hover menu items", array(
				   "none" => "None",
				   "underline" => "Underline",
				   "line-through" => "Line-through",
				   "overline" => "Overline"
				  ));
				$row1->addChild("vertical_menu_item_text_decoration_style",$vertical_menu_item_text_decoration_style);
				
				$vertical_menu_item_active_text_decoration_style = new QodePitchField("selectsimple","vertical_menu_item_active_text_decoration_style","none","Active Item Text Decoration","Choose text decoration type for active menu items", array(
				   "none" => "None",
				   "underline" => "Underline",
				   "line-through" => "Line-through",
				   "overline" => "Overline"
				  ));
				$row1->addChild("vertical_menu_item_active_text_decoration_style",$vertical_menu_item_active_text_decoration_style);
				
				
	$enable_vertical_menu_item_border = new QodePitchField("yesno","enable_vertical_menu_item_border","no","Enable Hover Borders for 1st Level Menu Items","Enabling this option will show borders on hover around item text in first level menu. In order to work, you need to set border width and color.", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#qodef_vertical_menu_item_border_container"));
	$panel7->addChild("enable_vertical_menu_item_border",$enable_vertical_menu_item_border);
	
		$vertical_menu_item_border_container = new QodePitchContainer("vertical_menu_item_border_container","enable_vertical_menu_item_border","no");
		$panel7->addChild("vertical_menu_item_border_container",$vertical_menu_item_border_container);

			$group1 = new QodePitchGroup("Hover Border Style","");
			$vertical_menu_item_border_container->addChild("group1",$group1);
			
				$row1 = new QodePitchRow();
				$group1->addChild("row1",$row1);			
				
					$vertical_menu_item_border_width = new QodePitchField("textsimple","vertical_menu_item_border_width","","Border Width","This is some description");
					$row1->addChild("vertical_menu_item_border_width",$vertical_menu_item_border_width);
					
					
					$vertical_menu_item_border_hover = new QodePitchField("colorsimple","vertical_menu_item_border_hover","","Hover Color","This is some description");
					$row1->addChild("vertical_menu_item_border_hover",$vertical_menu_item_border_hover);
					
					$vertical_menu_item_border_active = new QodePitchField("colorsimple","vertical_menu_item_border_active","","Active Color","This is some description");
					$row1->addChild("vertical_menu_item_border_active",$vertical_menu_item_border_active);
					
	
	$vertical_menu_dropdown = new QodePitchTitle("vertical_menu_dropdown", "Second Level Menu");
	$panel7->addChild("vertical_menu_dropdown", $vertical_menu_dropdown);
	
		$vertical_menu_dropdown_top_padding = new QodePitchField("text","vertical_menu_dropdown_top_padding","","Dropdown Top Padding","Enter top padding for dropdown (in pixels)",array(), array("col_width" => 3));
		$panel7->addChild("vertical_menu_dropdown_top_padding",$vertical_menu_dropdown_top_padding);
		
		$vertical_menu_dropdown_bottom_padding = new QodePitchField("text","vertical_menu_dropdown_bottom_padding","","Dropdown Bottom Padding","Enter bottom padding for dropdown (in pixels)",array(), array("col_width" => 3));
		$panel7->addChild("vertical_menu_dropdown_bottom_padding",$vertical_menu_dropdown_bottom_padding);

		$vertical_menu_dd_item_padding_top_bttm = new QodePitchField("text","vertical_menu_dd_item_padding_top_bttm","","Dropdown Menu Items Top/Bottom Padding","Enter padding for top and bottom of menu items in submenu dropdown (px)",array(),array("col_width" => 3));
		$panel7->addChild("vertical_menu_dd_item_padding_top_bttm",$vertical_menu_dd_item_padding_top_bttm);
		
		$vertical_menu_dropdown_plus_color = new QodePitchField("color","vertical_menu_dropdown_plus_color","","Dropdown 'Plus' Icon Color","Choose a color for dropdown 'plus' icon");
		$panel7->addChild("vertical_menu_dropdown_plus_color",$vertical_menu_dropdown_plus_color);

		$vertical_menu_dd_separator_container = new QodePitchContainer("vertical_menu_dd_separator_container","vertical_area_dropdown_showing","hover",array("hover","side","click"));
		$panel7->addChild("vertical_menu_dd_separator_container",$vertical_menu_dd_separator_container);

			$vertical_dropdown_separators_yesno= new QodePitchField("yesno","vertical_dropdown_separators_yesno","no","Enable Dropdown Menu Item Separators","Enabling this option will display dropdown menu item separators", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#qodef_vertical_dropdown_separators_container"));
	    	$vertical_menu_dd_separator_container->addChild("vertical_dropdown_separators_yesno",$vertical_dropdown_separators_yesno);

	        $vertical_dropdown_separators_container = new QodePitchContainer("vertical_dropdown_separators_container","vertical_dropdown_separators_yesno","no");
	        $vertical_menu_dd_separator_container->addChild("vertical_dropdown_separators_container",$vertical_dropdown_separators_container);

				$vertical_dropdown_separators_color = new QodePitchField("color","vertical_dropdown_separators_color","","Color","Choose a color for the menu item separators.");
	            $vertical_dropdown_separators_container->addChild("vertical_dropdown_separators_color",$vertical_dropdown_separators_color);
				
				$enable_vertical_top_bottom_dropdown_separators= new QodePitchField("yesno","enable_vertical_top_bottom_dropdown_separators","no","Enable Menu Top and Bottom Separators","Enabling this option will display separators at top and bottom of menu also");
				$vertical_dropdown_separators_container->addChild("enable_vertical_top_bottom_dropdown_separators",$enable_vertical_top_bottom_dropdown_separators);

	$vertical_menu_text_icons = new QodePitchTitle("vertical_menu_text_icons", "Menu Text and Icons");
	$panel7->addChild("vertical_menu_text_icons", $vertical_menu_text_icons);
	
    $group1 = new QodePitchGroup("1st Level Menu Style","Define styles for 1st level in Side Menu");
    $panel7->addChild("group1",$group1);

        $row1 = new QodePitchRow();
        $group1->addChild("row1",$row1);

            $vertical_menu_color = new QodePitchField("colorsimple","vertical_menu_color","","Text Color","This is some description");
            $row1->addChild("vertical_menu_color",$vertical_menu_color);
            $vertical_menu_hovercolor = new QodePitchField("colorsimple","vertical_menu_hovercolor","","Hover Color","This is some description");
            $row1->addChild("vertical_menu_hovercolor",$vertical_menu_hovercolor);
			$vertical_menu_activecolor = new QodePitchField("colorsimple","vertical_menu_activecolor","","Active Color","This is some description");
            $row1->addChild("vertical_menu_activecolor",$vertical_menu_activecolor);
			
		$row4 = new QodePitchRow();
        $group1->addChild("row4",$row4);

            $vertical_menu_icon_color = new QodePitchField("colorsimple","vertical_menu_icon_color","","Icon Color","This is some description");
            $row4->addChild("vertical_menu_icon_color",$vertical_menu_icon_color);
            $vertical_menu_icon_hovercolor = new QodePitchField("colorsimple","vertical_menu_icon_hovercolor","","Icon Hover Color","This is some description");
            $row4->addChild("vertical_menu_icon_hovercolor",$vertical_menu_icon_hovercolor);
			$vertical_menu_icon_activecolor = new QodePitchField("colorsimple","vertical_menu_icon_activecolor","","Icon Active Color","This is some description");
            $row4->addChild("vertical_menu_icon_activecolor",$vertical_menu_icon_activecolor);
            $vertical_menu_icon_margin = new QodePitchField("textsimple","vertical_menu_icon_margin","","Space between text and icon (px)","This is some description");
            $row4->addChild("vertical_menu_icon_margin",$vertical_menu_icon_margin);

        $row2 = new QodePitchRow(true);
        $group1->addChild("row2",$row2);

            $vertical_menu_google_fonts = new QodePitchField("fontsimple","vertical_menu_google_fonts","-1","Font family","This is some description");
            $row2->addChild("vertical_menu_google_fonts",$vertical_menu_google_fonts);
            $vertical_menu_fontsize = new QodePitchField("textsimple","vertical_menu_fontsize","","Font size (px)","This is some description");
            $row2->addChild("vertical_menu_fontsize",$vertical_menu_fontsize);
			$vertical_menu_icon_fontsize = new QodePitchField("textsimple","vertical_menu_icon_fontsize","","Icon font size (px)","This is some description");
            $row2->addChild("vertical_menu_icon_fontsize",$vertical_menu_icon_fontsize);
            $vertical_menu_lineheight = new QodePitchField("textsimple","vertical_menu_lineheight","","Line Height (px)","This is some description");
            $row2->addChild("vertical_menu_lineheight",$vertical_menu_lineheight);
        
        $row3 = new QodePitchRow(true);
        $group1->addChild("row3",$row3);

            $vertical_menu_fontstyle = new QodePitchField("selectblanksimple","vertical_menu_fontstyle","","Font Style","This is some description",$qode_pitch_options_fontstyle);
            $row3->addChild("vertical_menu_fontstyle",$vertical_menu_fontstyle);
            $vertical_menu_fontweight = new QodePitchField("selectblanksimple","vertical_menu_fontweight","","Font Weight","This is some description",$qode_pitch_options_fontweight);
            $row3->addChild("vertical_menu_fontweight",$vertical_menu_fontweight);
            $vertical_menu_letterspacing = new QodePitchField("textsimple","vertical_menu_letterspacing","","Letter Spacing (px)","This is some description");
            $row3->addChild("vertical_menu_letterspacing",$vertical_menu_letterspacing);
            $vertical_menu_texttransform = new QodePitchField("selectblanksimple","vertical_menu_texttransform","","Text Transform","This is some description",$qode_pitch_options_texttransform);
            $row3->addChild("vertical_menu_texttransform",$vertical_menu_texttransform);

    $group2 = new QodePitchGroup("2nd Level Menu Style","Define styles for 2nd level in Side Menu");
    $panel7->addChild("group2",$group2);

        $row1 = new QodePitchRow();
        $group2->addChild("row1",$row1);

            $vertical_dropdown_color = new QodePitchField("colorsimple","vertical_dropdown_color","","Text Color","This is some description");
            $row1->addChild("vertical_dropdown_color",$vertical_dropdown_color);
            $vertical_dropdown_hovercolor = new QodePitchField("colorsimple","vertical_dropdown_hovercolor","","Hover Color","This is some description");
            $row1->addChild("vertical_dropdown_hovercolor",$vertical_dropdown_hovercolor);
		
		$row4 = new QodePitchRow();
        $group2->addChild("row4",$row4);
            $vertical_dropdown_icon_color = new QodePitchField("colorsimple","vertical_dropdown_icon_color","","Icon Color","This is some description");
            $row4->addChild("vertical_dropdown_icon_color",$vertical_dropdown_icon_color);
            $vertical_dropdown_icon_hovercolor = new QodePitchField("colorsimple","vertical_dropdown_icon_hovercolor","","Icon Hover Color","This is some description");
            $row4->addChild("vertical_dropdown_icon_hovercolor",$vertical_dropdown_icon_hovercolor);

        $row2 = new QodePitchRow(true);
        $group2->addChild("row2",$row2);

            $vertical_dropdown_google_fonts = new QodePitchField("fontsimple","vertical_dropdown_google_fonts","-1","Font Family","This is some description");
            $row2->addChild("vertical_dropdown_google_fonts",$vertical_dropdown_google_fonts);
            $vertical_dropdown_fontsize = new QodePitchField("textsimple","vertical_dropdown_fontsize","","Font Size (px)","This is some description");
            $row2->addChild("vertical_dropdown_fontsize",$vertical_dropdown_fontsize);
			$vertical_dropdown_icon_fontsize = new QodePitchField("textsimple","vertical_dropdown_icon_fontsize","","Icon font size (px)","This is some description");
            $row2->addChild("vertical_dropdown_icon_fontsize",$vertical_dropdown_icon_fontsize);
            $vertical_dropdown_lineheight = new QodePitchField("textsimple","vertical_dropdown_lineheight","","Line Height (px)","This is some description");
            $row2->addChild("vertical_dropdown_lineheight",$vertical_dropdown_lineheight);
        
        $row3 = new QodePitchRow(true);
        $group2->addChild("row3",$row3);

            $vertical_dropdown_fontstyle = new QodePitchField("selectblanksimple","vertical_dropdown_fontstyle","","Font Style","This is some description",$qode_pitch_options_fontstyle);
            $row3->addChild("vertical_dropdown_fontstyle",$vertical_dropdown_fontstyle);
            $vertical_dropdown_fontweight = new QodePitchField("selectblanksimple","vertical_dropdown_fontweight","","Font Weight","This is some description",$qode_pitch_options_fontweight);
            $row3->addChild("vertical_dropdown_fontweight",$vertical_dropdown_fontweight);
            $vertical_dropdown_letterspacing = new QodePitchField("textsimple","vertical_dropdown_letterspacing","","Letter Spacing (px)","This is some description");
            $row3->addChild("vertical_dropdown_letterspacing",$vertical_dropdown_letterspacing);
            $vertical_dropdown_texttransform = new QodePitchField("selectblanksimple","vertical_dropdown_texttransform","","Text Transform","This is some description",$qode_pitch_options_texttransform);
            $row3->addChild("vertical_dropdown_texttransform",$vertical_dropdown_texttransform);

    $group3 = new QodePitchGroup("3rd Level Menu Style","Define styles for 3rd level in Side Menu");
    $panel7->addChild("group3",$group3);

        $row1 = new QodePitchRow();
        $group3->addChild("row1",$row1);

            $vertical_dropdown_color_thirdlvl = new QodePitchField("colorsimple","vertical_dropdown_color_thirdlvl","","Text Color","This is some description");
            $row1->addChild("vertical_dropdown_color_thirdlvl",$vertical_dropdown_color_thirdlvl);
            $vertical_dropdown_hovercolor_thirdlvl = new QodePitchField("colorsimple","vertical_dropdown_hovercolor_thirdlvl","","Hover Color","This is some description");
            $row1->addChild("vertical_dropdown_hovercolor_thirdlvl",$vertical_dropdown_hovercolor_thirdlvl);
	
		$row4 = new QodePitchRow();
        $group3->addChild("row4",$row4);
            $vertical_dropdown_icon_color_thirdlvl = new QodePitchField("colorsimple","vertical_dropdown_icon_color_thirdlvl","","Icon Color","This is some description");
            $row4->addChild("vertical_dropdown_icon_color_thirdlvl",$vertical_dropdown_icon_color_thirdlvl);
            $vertical_dropdown_icon_hovercolor_thirdlvl = new QodePitchField("colorsimple","vertical_dropdown_icon_hovercolor_thirdlvl","","Icon Hover Color","This is some description");
            $row4->addChild("vertical_dropdown_icon_hovercolor_thirdlvl",$vertical_dropdown_icon_hovercolor_thirdlvl);
		
        $row2 = new QodePitchRow(true);
        $group3->addChild("row2",$row2);

            $vertical_dropdown_google_fonts_thirdlvl = new QodePitchField("fontsimple","vertical_dropdown_google_fonts_thirdlvl","-1","Font Family","This is some description");
            $row2->addChild("vertical_dropdown_google_fonts_thirdlvl",$vertical_dropdown_google_fonts_thirdlvl);
            $vertical_dropdown_fontsize_thirdlvl = new QodePitchField("textsimple","vertical_dropdown_fontsize_thirdlvl","","Font Size (px)","This is some description");
            $row2->addChild("vertical_dropdown_fontsize_thirdlvl",$vertical_dropdown_fontsize_thirdlvl);
			$vertical_dropdown_icon_fontsize_thirdlvl = new QodePitchField("textsimple","vertical_dropdown_icon_fontsize_thirdlvl","","Icon font size (px)","This is some description");
            $row2->addChild("vertical_dropdown_icon_fontsize_thirdlvl",$vertical_dropdown_icon_fontsize_thirdlvl);
            $vertical_dropdown_lineheight_thirdlvl = new QodePitchField("textsimple","vertical_dropdown_lineheight_thirdlvl","","Line Height (px)","This is some description");
            $row2->addChild("vertical_dropdown_lineheight_thirdlvl",$vertical_dropdown_lineheight_thirdlvl);
        
        $row3 = new QodePitchRow(true);
        $group3->addChild("row3",$row3);

            $vertical_dropdown_fontstyle_thirdlvl = new QodePitchField("selectblanksimple","vertical_dropdown_fontstyle_thirdlvl","","Font Style","This is some description",$qode_pitch_options_fontstyle);
            $row3->addChild("vertical_dropdown_fontstyle_thirdlvl",$vertical_dropdown_fontstyle_thirdlvl);
            $vertical_dropdown_fontweight_thirdlvl = new QodePitchField("selectblanksimple","vertical_dropdown_fontweight_thirdlvl","","Font Weight","This is some description",$qode_pitch_options_fontweight);
            $row3->addChild("vertical_dropdown_fontweight_thirdlvl",$vertical_dropdown_fontweight_thirdlvl);
            $vertical_dropdown_letterspacing_thirdlvl = new QodePitchField("textsimple","vertical_dropdown_letterspacing_thirdlvl","","Letter Spacing (px)","This is some description");
            $row3->addChild("vertical_dropdown_letterspacing_thirdlvl",$vertical_dropdown_letterspacing_thirdlvl);
            $vertical_dropdown_texttransform_thirdlvl = new QodePitchField("selectblanksimple","vertical_dropdown_texttransform_thirdlvl","","Text Transform","This is some description",$qode_pitch_options_texttransform);
            $row3->addChild("vertical_dropdown_texttransform_thirdlvl",$vertical_dropdown_texttransform_thirdlvl);   

//Mobile menu	
	
$panel8 = new QodePitchPanel("Mobile Header","mobile_menu_panel");
$headerandfooterPage->addChild("panel8",$panel8);

			$header_height_mobile = new QodePitchField("text","header_height_mobile","","Mobile Header Height","Enter height for mobile header in pixels", array(), array("col_width" => 3));
            $panel8->addChild("header_height_mobile",$header_height_mobile);

            $mobile_separator_color = new QodePitchField("color","mobile_separator_color","","Mobile Menu Item Separator Color","Choose color for mobile menu horizontal separators");
            $panel8->addChild("mobile_separator_color",$mobile_separator_color);
           
		   $mobile_background_color = new QodePitchField("color","mobile_background_color","","Mobile Header & Menu Background Color","Choose color for mobile header&menu background");
            $panel8->addChild("mobile_background_color",$mobile_background_color);	
			
			$logo_mobile_header_height = new QodePitchField("text","logo_mobile_header_height","","Logo Height For Mobile Header (px)","Define logo height for screen size smaller than 1000px",array(), array("col_width" => 3));
			$panel8->addChild("logo_mobile_header_height",$logo_mobile_header_height);

			$logo_mobile_height = new QodePitchField("text","logo_mobile_height","","Logo Height For Mobile Devices (px)","Define logo height for screen size smaller than 480px",array(), array("col_width" => 3));
			$panel8->addChild("logo_mobile_height",$logo_mobile_height);

// Header Button Icons
$panel9 = new QodePitchPanel("Header Button Icons","header_buttons_panel");
$headerandfooterPage->addChild("panel9",$panel9);

	$header_icon_pack = new QodePitchField('select', 'header_icon_pack', 'font_awesome', 'Header Icons Icon Pack', 'Choose
	 Icon Pack', $qode_pitch_IconCollections->getIconCollectionsExclude(array('linea_icons', 'simple_line_icons')));
	$panel9->addChild('header_icon_pack', $header_icon_pack);

	$group1 = new QodePitchGroup("Header Icons Style","Define styles for header icons (Search Icon, Fullscreen Menu Icon and Side Area Icon)");
    $panel9->addChild("group1",$group1);

        $row1 = new QodePitchRow(true);
        $group1->addChild("row1",$row1);

			$header_buttons_color = new QodePitchField("colorsimple","header_buttons_color","","Color","Choose a color for Header icons");
			$row1->addChild("header_buttons_color",$header_buttons_color);

			$header_buttons_hover_color = new QodePitchField("colorsimple","header_buttons_hover_color","","Hover Color","Choose a hover color for Header icons");
			$row1->addChild("header_buttons_hover_color",$header_buttons_hover_color);

        $row2 = new QodePitchRow(true);
        $group1->addChild("row2",$row2);

            $header_light_icons_color = new QodePitchField("colorsimple","header_light_icons_color","","Light Menu Icon Color","Choose a color for Header Light icons");
            $row2->addChild("header_light_icons_color",$header_light_icons_color);

            $header_light_hover_icons_color = new QodePitchField("colorsimple","header_light_hover_icons_color","","Light Menu Icon Hover Color","Choose a hover color for Header Light icons");
            $row2->addChild("header_light_hover_icons_color",$header_light_hover_icons_color);

        $row3 = new QodePitchRow(true);
        $group1->addChild("row3",$row3);

            $header_dark_icons_color = new QodePitchField("colorsimple","header_dark_icons_color","","Dark Menu Icon Color","Choose a color for Header Light icons");
            $row3->addChild("header_dark_icons_color",$header_dark_icons_color);

            $header_dark_hover_icons_color = new QodePitchField("colorsimple","header_dark_hover_icons_color","","Dark Menu Icon Hover Color","Choose a hover color for Header Light icons");
            $row3->addChild("header_dark_hover_icons_color",$header_dark_hover_icons_color);

	$header_buttons_font_size = new QodePitchField("text","header_buttons_font_size","","Side Area Icon/ Search Icon Size","Choose a size for Side Area / Search icons (px)", array(), array("col_width" => 3));
	$panel9->addChild("header_buttons_font_size",$header_buttons_font_size);

	$header_buttons_size = new QodePitchField("select","header_buttons_size","normal","Side Menu Icon / Fullscreen Menu Icon Size","Choose predefined size for Side Area / Fullscreen Menu icons", array( "normal" => "Normal",
		   "medium" => "Medium",
		   "large" => "Large"
		  ));
	$panel9->addChild("header_buttons_size",$header_buttons_size); 
	
	$group3 = new QodePitchGroup("Mobile Header Icons Color","Choose color for mobile header icons (search icon, fullscreen menu icon and side area icon)");
    $panel9->addChild("group3",$group3);

        $row1 = new QodePitchRow(true);
        $group3->addChild("row1",$row1);	

			$mobile_button_color = new QodePitchField("colorsimple","mobile_button_color","","Icon Color","Choose a color for mobile menu icon");
			$row1->addChild("mobile_button_color",$mobile_button_color); 
			
			$mobile_button_color_hover = new QodePitchField("colorsimple","mobile_button_color_hover","","Icon Hover Color","Choose a hover color for mobile menu icon");
			$row1->addChild("mobile_button_color_hover",$mobile_button_color_hover);
	
	$group2 = new QodePitchGroup("Fullscreen Menu Icon Background","Define background for fullscreen menu icon in header");
    $panel9->addChild("group2",$group2);

        $row1 = new QodePitchRow(true);
        $group2->addChild("row1",$row1);	

			$header_buttons_fullscreen_button_background = new QodePitchField("colorsimple","header_buttons_fullscreen_button_background","","Background Color","Choose a background color for Fullscreen Menu icon");
			$row1->addChild("header_buttons_fullscreen_button_background",$header_buttons_fullscreen_button_background); 
			
			$header_buttons_fullscreen_button_background_hover = new QodePitchField("colorsimple","header_buttons_fullscreen_button_background_hover","","Background Hover Color","Choose a background hover color for Fullscreen Menu icon");
			$row1->addChild("header_buttons_fullscreen_button_background_hover",$header_buttons_fullscreen_button_background_hover); 
// WPML Language Selector
if(qode_pitch_is_wpml_installed()){
	
	$panel_lang_selector = new QodePitchPanel("Language Selector","lang_selector_panel");
	$headerandfooterPage->addChild("panel_lang_selector",$panel_lang_selector);	

	$wpml_first_level_background_color = new QodePitchField("color","wpml_first_level_background_color","","Background Color for First Level","Choose a background color for first level element");
	$panel_lang_selector->addChild("wpml_first_level_background_color",$wpml_first_level_background_color);
	
	// First Level Menu 
		
	$group1 = new QodePitchGroup("1st Level Menu Style","Define styles for first menu level ");
    $panel_lang_selector->addChild("group1",$group1);

        $row1 = new QodePitchRow();
        $group1->addChild("row1",$row1);

            $wpml_first_level_menu_color = new QodePitchField("colorsimple","wpml_first_level_menu_color","","Text Color","This is some description");
            $row1->addChild("wpml_first_level_menu_color",$wpml_first_level_menu_color);
			
            $wpml_first_level_menu_color_hover = new QodePitchField("colorsimple","wpml_first_level_menu_color_hover","","Hover Color","This is some description");
            $row1->addChild("wpml_first_level_menu_color_hover",$wpml_first_level_menu_color_hover);
			
			$wpml_first_level_menu_google_fonts = new QodePitchField("fontsimple","wpml_first_level_menu_google_fonts","-1","Font Family","This is some description");
            $row1->addChild("wpml_first_level_menu_google_fonts",$wpml_first_level_menu_google_fonts);
			
            $wpml_first_level_menu_fontsize = new QodePitchField("textsimple","wpml_first_level_menu_fontsize","","Font Size (px)","This is some description");
            $row1->addChild("wpml_first_level_menu_fontsize",$wpml_first_level_menu_fontsize);
			
		$row2 = new QodePitchRow(true);
		$group1->addChild("row2",$row2);
		
			$wpml_first_level_menu_texttransform = new QodePitchField("selectblanksimple","wpml_first_level_menu_texttransform","","Text Transform","This is some description",$qode_pitch_options_texttransform);
            $row2->addChild("wpml_first_level_menu_texttransform",$wpml_first_level_menu_texttransform);
			
			$wpml_first_level_menu_fontstyle = new QodePitchField("selectblanksimple","wpml_first_level_menu_fontstyle","","Font Style","This is some description",$qode_pitch_options_fontstyle);
            $row2->addChild("wpml_first_level_menu_fontstyle",$wpml_first_level_menu_fontstyle);
			
            $wpml_first_level_menu_fontweight = new QodePitchField("selectblanksimple","wpml_first_level_menu_fontweight","","Font Weight","This is some description",$qode_pitch_options_fontweight);
            $row2->addChild("wpml_first_level_menu_fontweight",$wpml_first_level_menu_fontweight);
			
            $wpml_first_level_menu_letterspacing = new QodePitchField("textsimple","wpml_first_level_menu_letterspacing","","Letter Spacing (px)","This is some description");
            $row2->addChild("wpml_first_level_menu_letterspacing",$wpml_first_level_menu_letterspacing);
			
	$group2 = new QodePitchGroup("2nd Level Menu Style","Define styles for second menu level ");
	$panel_lang_selector->addChild("group2",$group2);

        $row1 = new QodePitchRow();
        $group2->addChild("row1",$row1);

            $wpml_second_level_menu_color = new QodePitchField("colorsimple","wpml_second_level_menu_color","","Text Color","This is some description");
            $row1->addChild("wpml_second_level_menu_color",$wpml_second_level_menu_color);
			
            $wpml_second_level_menu_color_hover = new QodePitchField("colorsimple","wpml_second_level_menu_color_hover","","Hover Color","This is some description");
            $row1->addChild("wpml_second_level_menu_color_hover",$wpml_second_level_menu_color_hover);
			
			$wpml_second_level_menu_google_fonts = new QodePitchField("fontsimple","wpml_second_level_menu_google_fonts","-1","Font Family","This is some description");
            $row1->addChild("wpml_second_level_menu_google_fonts",$wpml_second_level_menu_google_fonts);
			
            $wpml_second_level_menu_fontsize = new QodePitchField("textsimple","wpml_second_level_menu_fontsize","","Font Size (px)","This is some description");
            $row1->addChild("wpml_second_level_menu_fontsize",$wpml_second_level_menu_fontsize);
			
		$row2 = new QodePitchRow(true);
		$group2->addChild("row2",$row2);
			$wpml_second_level_menu_texttransform = new QodePitchField("selectblanksimple","wpml_second_level_menu_texttransform","","Text Transform","This is some description",$qode_pitch_options_texttransform);
            $row2->addChild("wpml_second_level_menu_texttransform",$wpml_second_level_menu_texttransform);	
			
			$wpml_second_level_menu_fontstyle = new QodePitchField("selectblanksimple","wpml_second_level_menu_fontstyle","","Font Style","This is some description",$qode_pitch_options_fontstyle);
            $row2->addChild("wpml_second_level_menu_fontstyle",$wpml_second_level_menu_fontstyle);
			
            $wpml_second_level_menu_fontweight = new QodePitchField("selectblanksimple","wpml_second_level_menu_fontweight","","Font Weight","This is some description",$qode_pitch_options_fontweight);
            $row2->addChild("wpml_second_level_menu_fontweight",$wpml_second_level_menu_fontweight);
			
            $wpml_second_level_menu_letterspacing = new QodePitchField("textsimple","wpml_second_level_menu_letterspacing","","Letter Spacing (px)","This is some description");
            $row2->addChild("wpml_second_level_menu_letterspacing",$wpml_second_level_menu_letterspacing);

    $lang_items_padding = new QodePitchField('text', 'header_bottom_lang_items_padding', '', 'Left / Right Spacing Between Languages in List (px)', 'Set spacing between languages when horizontal language switcher is added to main menu', array(), array("col_width" => 3));
    $panel_lang_selector->addChild('header_bottom_lang_items_padding', $lang_items_padding);
			
}	
	
