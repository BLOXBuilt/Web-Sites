<?php

$sliderPage = new QodePitchAdminPage("10", "Select Slider", "fa fa-arrows-h");
$qode_pitch_Framework->qodeOptions->addAdminPage("slider",$sliderPage);

// General Style

$panel3 = new QodePitchPanel("General Style","navigation_control_style");
$sliderPage->addChild("panel3",$panel3);

    $qs_slider_height_mobile = new QodePitchField("text","qs_slider_height_mobile","","Slider Height For Mobile Devices (px)","Define slider height for mobile devices");
    $panel3->addChild("qs_slider_height_mobile",$qs_slider_height_mobile);

	$qs_slider_preloader_background = new QodePitchField("color","qs_slider_preloader_background","","Slider Preloader Background Color","Define background color for slider preloader");
	$panel3->addChild("qs_slider_preloader_background",$qs_slider_preloader_background);
	
	$qs_slider_custom_word_color = new QodePitchField("color","qs_slider_custom_word_color","","Title Highlited Word Color","Define color for highlited word in title. Note: highlite the word in title like this: <span class = 'custom'> example </span>");
	$panel3->addChild("qs_slider_custom_word_color",$qs_slider_custom_word_color);
	
	$qs_slider_underline_word_color = new QodePitchField("color","qs_slider_underline_word_color","","Title Underlined Word Color","Define color for underlined word in title. Note: underline the word in title like this: <span class = 'underline'> example </span>");
	$panel3->addChild("qs_slider_underline_word_color",$qs_slider_underline_word_color);

// Navigation Control Style

$panel2 = new QodePitchPanel("Navigation Bullets Style","navigation_control_style");
$sliderPage->addChild("panel2",$panel2);

	$group1 = new QodePitchGroup("Colors","Choose color styles for navigation bullets");
	$panel2->addChild("group1",$group1);

		$row1 = new QodePitchRow();
		$group1->addChild("row1",$row1);

			$qs_navigation_control_color = new QodePitchField("colorsimple","qs_navigation_control_color","","Color","This is some description");
			$row1->addChild("qs_navigation_control_color",$qs_navigation_control_color);

			$qs_navigation_control_transparency = new QodePitchField("textsimple","qs_navigation_control_transparency","","Transparency (0-1)","This is some description");
			$row1->addChild("qs_navigation_control_transparency",$qs_navigation_control_transparency);

			$qs_navigation_control_active_color = new QodePitchField("colorsimple","qs_navigation_control_active_color","","Active Color","This is some description");
			$row1->addChild("qs_navigation_control_active_color",$qs_navigation_control_active_color);

			$qs_navigation_control_active_transparency = new QodePitchField("textsimple","qs_navigation_control_active_transparency","","Active Transparency(0-1)","This is some description");
			$row1->addChild("qs_navigation_control_active_transparency",$qs_navigation_control_active_transparency);

	$group2 = new QodePitchGroup("Size","Define size for navigation bullets controls (w=h in px)");
	$panel2->addChild("group2",$group2);

		$row1 = new QodePitchRow();
		$group2->addChild("row1",$row1);

			$qs_navigation_control_size = new QodePitchField("textsimple","qs_navigation_control_size","","Size (px)","This is some description");
			$row1->addChild("qs_navigation_control_size",$qs_navigation_control_size);

			$qs_navigation_control_active_size = new QodePitchField("textsimple","qs_navigation_control_active_size","","Active Size (px)","This is some description");
			$row1->addChild("qs_navigation_control_active_size",$qs_navigation_control_active_size);

	$group3 = new QodePitchGroup("Border Style","Define border style for navigation bullets");
	$panel2->addChild("group3",$group3);

		$row1 = new QodePitchRow();
		$group3->addChild("row1",$row1);

			$qs_navigation_control_border_color = new QodePitchField("colorsimple","qs_navigation_control_border_color","","Border Color","This is some description");
			$row1->addChild("qs_navigation_control_border_color",$qs_navigation_control_border_color);

			$qs_navigation_control_active_border_color = new QodePitchField("colorsimple","qs_navigation_control_active_border_color","","Active Border Color","This is some description");
			$row1->addChild("qs_navigation_control_active_border_color",$qs_navigation_control_active_border_color);			

			$qs_navigation_control_border_radius = new QodePitchField("textsimple","qs_navigation_control_border_radius","","Border Radius (px)","This is some description");
			$row1->addChild("qs_navigation_control_border_radius",$qs_navigation_control_border_radius);


// Custom cursor navigation style

$panel4 = new QodePitchPanel("Custom Cursor Navigation Style","navigation_custom_cursor_style");
$sliderPage->addChild("panel4",$panel4);

	$qs_enable_navigation_custom_cursor = new QodePitchField("yesno","qs_enable_navigation_custom_cursor","no","Enable Custom Cursor for Navigation","Enabling this option will display custom cursors for slider navigation", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#qodef_qs_enable_navigation_custom_cursor_container"));
	$panel4->addChild("qs_enable_navigation_custom_cursor",$qs_enable_navigation_custom_cursor);
	
	
		$qs_enable_navigation_custom_cursor_container = new QodePitchContainer("qs_enable_navigation_custom_cursor_container","qs_enable_navigation_custom_cursor","no");
		$panel4->addChild("qs_enable_navigation_custom_cursor_container",$qs_enable_navigation_custom_cursor_container);
		
			$cursor_image_left_right_area_size = new QodePitchField("text","cursor_image_left_right_area_size","","Clickable Left/Right Area Size (%)","Define size of clickable left/right slider area in relation to slider width (default value is 8%)", array(), array("col_width" => 3));
			$qs_enable_navigation_custom_cursor_container->addChild("cursor_image_left_right_area_size",$cursor_image_left_right_area_size);
		
			$cursor_image_left_normal = new QodePitchField("image","cursor_image_left_normal","","Cursor Image 'Left' - Normal","Choose a default cursor 'Left' image to display ");
			$qs_enable_navigation_custom_cursor_container->addChild("cursor_image_left_normal",$cursor_image_left_normal);
			
			$cursor_image_right_normal = new QodePitchField("image","cursor_image_right_normal","","Cursor Image 'Right' - Normal","Choose a default cursor 'Right' image to display ");
			$qs_enable_navigation_custom_cursor_container->addChild("cursor_image_right_normal",$cursor_image_right_normal);
			
			
			$cursor_image_left_light = new QodePitchField("image","cursor_image_left_light","","Cursor Image 'Left' - Light","Choose a cursor 'Left' light image to display ");
			$qs_enable_navigation_custom_cursor_container->addChild("cursor_image_left_light",$cursor_image_left_light);
			
			$cursor_image_right_light = new QodePitchField("image","cursor_image_right_light","","Cursor Image 'Right' - Light","Choose a cursor 'Right' light image to display ");
			$qs_enable_navigation_custom_cursor_container->addChild("cursor_image_right_light",$cursor_image_right_light);
			
			$cursor_image_left_dark = new QodePitchField("image","cursor_image_left_dark","","Cursor Image 'Left' - Dark","Choose a cursor 'Left' dark image to display ");
			$qs_enable_navigation_custom_cursor_container->addChild("cursor_image_left_dark",$cursor_image_left_dark);
			
			$cursor_image_right_dark = new QodePitchField("image","cursor_image_right_dark","","Cursor Image 'Right' - Dark","Choose a cursor 'Right' dark image to display ");
			$qs_enable_navigation_custom_cursor_container->addChild("cursor_image_right_dark",$cursor_image_right_dark);
			

		$qs_enable_navigation_custom_cursor_grab = new QodePitchField("yesno","qs_enable_navigation_custom_cursor_grab","no","Enable Custom Cursor for 'Grab' Arrow","Enabling this option will display custom cursor for slider 'Grab' arrow", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#qodef_qs_enable_navigation_custom_cursor_grab_container"));
		$qs_enable_navigation_custom_cursor_container->addChild("qs_enable_navigation_custom_cursor_grab",$qs_enable_navigation_custom_cursor_grab);
			
			$qs_enable_navigation_custom_cursor_grab_container = new QodePitchContainer("qs_enable_navigation_custom_cursor_grab_container","qs_enable_navigation_custom_cursor_grab","no");
			$qs_enable_navigation_custom_cursor_container->addChild("qs_enable_navigation_custom_cursor_grab_container",$qs_enable_navigation_custom_cursor_grab_container);
			
				$cursor_image_grab_normal = new QodePitchField("image","cursor_image_grab_normal","","Cursor Image 'Grab' - Normal","Choose a default cursor 'Grab' image to display");
				$qs_enable_navigation_custom_cursor_grab_container->addChild("cursor_image_grab_normal",$cursor_image_grab_normal);
				
				$cursor_image_grab_light = new QodePitchField("image","cursor_image_grab_light","","Cursor Image 'Grab' - Light","Choose a cursor 'Grab' light image to display");
				$qs_enable_navigation_custom_cursor_grab_container->addChild("cursor_image_grab_light",$cursor_image_grab_light);
				
				$cursor_image_grab_dark = new QodePitchField("image","cursor_image_grab_dark","","Cursor Image 'Grab' - Dark","Choose a cursor 'Grab' dark image to display");
				$qs_enable_navigation_custom_cursor_grab_container->addChild("cursor_image_grab_dark",$cursor_image_grab_dark);
				
				
				
				
				
	