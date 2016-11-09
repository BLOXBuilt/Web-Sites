<?php

$contentbottomPage = new QodePitchAdminPage("16", "Content Bottom", "fa fa-level-down");
$qode_pitch_Framework->qodeOptions->addAdminPage("Content Bottom",$contentbottomPage);

//Content Bottom Area

$panel1 = new QodePitchPanel("Content Bottom Area","content_bottom_area_panel");
$contentbottomPage->addChild("panel1",$panel1);

	$enable_content_bottom_area = new QodePitchField("yesno","enable_content_bottom_area","no","Enable Content Bottom Area","This option will enable Content Bottom area on pages", array(), array("dependence" => true, "dependence_hide_on_yes" => "", "dependence_show_on_yes" => "#qodef_enable_content_bottom_area_container"));
	$panel1->addChild("enable_content_bottom_area",$enable_content_bottom_area);

		$enable_content_bottom_area_container = new QodePitchContainer("enable_content_bottom_area_container","enable_content_bottom_area","no");
		$panel1->addChild("enable_content_bottom_area_container",$enable_content_bottom_area_container);

		    $custom_sidebars = qode_pitch_get_custom_sidebars();

			$content_bottom_sidebar_custom_display = new QodePitchField("selectblank","content_bottom_sidebar_custom_display","","Sidebar to Display","Choose a Content Bottom sidebar to display", $custom_sidebars);
			$enable_content_bottom_area_container->addChild("content_bottom_sidebar_custom_display",$content_bottom_sidebar_custom_display);

			$content_bottom_in_grid = new QodePitchField("yesno","content_bottom_in_grid","yes","Display in Grid","Enabling this option will place Content Bottom in grid");
			$enable_content_bottom_area_container->addChild("content_bottom_in_grid",$content_bottom_in_grid);

			$content_bottom_background_color = new QodePitchField("color","content_bottom_background_color","","Background Color","Choose a background color for Content Bottom area");
			$enable_content_bottom_area_container->addChild("content_bottom_background_color",$content_bottom_background_color);