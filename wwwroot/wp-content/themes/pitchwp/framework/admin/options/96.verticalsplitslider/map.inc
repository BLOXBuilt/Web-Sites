<?php

$verticalSplitSliderPage = new QodePitchAdminPage("11", "Vertical Split Slider", "fa fa-arrows-v");
$qode_pitch_Framework->qodeOptions->addAdminPage("verticalSplitSlider",$verticalSplitSliderPage);

// General Style

$panel10 = new QodePitchPanel("General Style","general_style");
$verticalSplitSliderPage->addChild("panel10",$panel10);

	$group1 = new QodePitchGroup("Navigation Style","Define style for navigation bullets");
	$panel10->addChild("group1",$group1);

		$row1 = new QodePitchRow();
		$group1->addChild("row1",$row1);

			$vss_navigation_inactive_color = new QodePitchField("colorsimple","vss_navigation_inactive_color","","Navigation Color","Define color for navigation dots");
			$row1->addChild("vss_navigation_inactive_color",$vss_navigation_inactive_color);

			$vss_navigation_inactive_border_color = new QodePitchField("colorsimple","vss_navigation_inactive_border_color","","Navigation Border Color","Define border color for navigation dots");
			$row1->addChild("vss_navigation_inactive_border_color",$vss_navigation_inactive_border_color);

			$vss_navigation_color = new QodePitchField("colorsimple","vss_navigation_color","","Navigation Active Color","Define active color for navigation dots");
			$row1->addChild("vss_navigation_color",$vss_navigation_color);

			$vss_navigation_border_color = new QodePitchField("colorsimple","vss_navigation_border_color","","Navigation Active Border Color","Define active border color for navigation dots");
			$row1->addChild("vss_navigation_border_color",$vss_navigation_border_color);

	$group2 = new QodePitchGroup("Navigation Light Style","Define style for light navigation bullets");
	$panel10->addChild("group2",$group2);

		$row1 = new QodePitchRow();
		$group2->addChild("row1",$row1);

			$vss_navigation_light_inactive_color = new QodePitchField("colorsimple","vss_navigation_light_inactive_color","","Navigation Color","Define color for navigation dots");
			$row1->addChild("vss_navigation_light_inactive_color",$vss_navigation_light_inactive_color);

			$vss_navigation_light_inactive_border_color = new QodePitchField("colorsimple","vss_navigation_light_inactive_border_color","","Navigation Border Color","Define border color for navigation dots");
			$row1->addChild("vss_navigation_light_inactive_border_color",$vss_navigation_light_inactive_border_color);

			$vss_navigation_light_color = new QodePitchField("colorsimple","vss_navigation_light_color","","Navigation Active Color","Define active color for navigation dots");
			$row1->addChild("vss_navigation_light_color",$vss_navigation_light_color);

			$vss_navigation_light_border_color = new QodePitchField("colorsimple","vss_navigation_light_border_color","","Navigation Active Border Color","Define active border color for navigation dots");
			$row1->addChild("vss_navigation_light_border_color",$vss_navigation_light_border_color);

	$group3 = new QodePitchGroup("Navigation Dark Style","Define style for dark navigation bullets");
	$panel10->addChild("group3",$group3);

		$row1 = new QodePitchRow();
		$group3->addChild("row1",$row1);

			$vss_navigation_dark_inactive_color = new QodePitchField("colorsimple","vss_navigation_dark_inactive_color","","Navigation Color","Define color for navigation dots");
			$row1->addChild("vss_navigation_dark_inactive_color",$vss_navigation_dark_inactive_color);

			$vss_navigation_dark_inactive_border_color = new QodePitchField("colorsimple","vss_navigation_dark_inactive_border_color","","Navigation Border Color","Define border color for navigation dots");
			$row1->addChild("vss_navigation_dark_inactive_border_color",$vss_navigation_dark_inactive_border_color);

			$vss_navigation_dark_color = new QodePitchField("colorsimple","vss_navigation_dark_color","","Navigation Active Color","Define active color for navigation dots");
			$row1->addChild("vss_navigation_dark_color",$vss_navigation_dark_color);

			$vss_navigation_dark_border_color = new QodePitchField("colorsimple","vss_navigation_dark_border_color","","Navigation Active Border Color","Define active border color for navigation dots");
			$row1->addChild("vss_navigation_dark_border_color",$vss_navigation_dark_border_color);

	$group4 = new QodePitchGroup("Navigation Size","Define size for navigation dots");
	$panel10->addChild("group4",$group4);

		$row1 = new QodePitchRow();
		$group4->addChild("row1",$row1);

			$vss_navigation_size = new QodePitchField("textsimple","vss_navigation_size","","Size (px)","Define size for navigation dots");
			$row1->addChild("vss_navigation_size",$vss_navigation_size);

			$vss_navigation_active_size = new QodePitchField("textsimple","vss_navigation_active_size","","Active Size (px)","Define active size for navigation dots");
			$row1->addChild("vss_navigation_active_size",$vss_navigation_active_size);

    $vss_navigation_spacing_from_edge = new QodePitchField("text","vss_navigation_spacing_from_edge","","Navigation Position (px)","Define position of navigation from right/left edge of slider", array(), array("col_width" => 1));
    $panel10->addChild("vss_navigation_spacing_from_edge",$vss_navigation_spacing_from_edge);

    $vss_left_panel_size = new QodePitchField("text","vss_left_panel_size","","Left Slide Panel size (%)","Define size for left slide panel. Note that sum of left and right slide panel should be 100.", array(), array("col_width" => 1));
    $panel10->addChild("vss_left_panel_size",$vss_left_panel_size);

    $vss_right_panel_size = new QodePitchField("text","vss_right_panel_size","","Right Slide Panel size (%)","Define size for right slide panel. Note that sum of left and right slide panel should be 100.", array(), array("col_width" => 1));
    $panel10->addChild("vss_right_panel_size",$vss_right_panel_size);

