<?php

$sidebarPage = new QodePitchAdminPage("7", "Sidebar", "fa fa-bars");
$qode_pitch_Framework->qodeOptions->addAdminPage("sidebar",$sidebarPage);

// Navigation Style

$panel1 = new QodePitchPanel("Widgets","widget_style");
$sidebarPage->addChild("panel1",$panel1);

	$sidebar_background_color = new QodePitchField("color","sidebar_background_color","","Sidebar Background Color","Choose background color for sidebar");
	$panel1->addChild("sidebar_background_color",$sidebar_background_color);

	$group6 = new QodePitchGroup("Padding","Define padding for sidebar");
	$panel1->addChild("group6",$group6);
		$row1 = new QodePitchRow(true);
		$group6->addChild("row1",$row1);
			$sidebar_padding_top = new QodePitchField("textsimple","sidebar_padding_top","","Top Padding (px)","This is some description");
			$row1->addChild("sidebar_padding_top",$sidebar_padding_top);
			$sidebar_padding_right = new QodePitchField("textsimple","sidebar_padding_right","","Right Padding (px)","This is some description");
			$row1->addChild("sidebar_padding_right",$sidebar_padding_right);
			$sidebar_padding_bottom = new QodePitchField("textsimple","sidebar_padding_bottom","","Bottom Padding (px)","This is some description");
			$row1->addChild("sidebar_padding_bottom",$sidebar_padding_bottom);
			$sidebar_padding_left = new QodePitchField("textsimple","sidebar_padding_left","","Left Padding (px)","This is some description");
			$row1->addChild("sidebar_padding_left",$sidebar_padding_left);

$sidebar_shadow_enable = new QodePitchField('yesno', 'sidebar_enable_box_shadow', 'no', 'Enable Shadow For Sidebar', '', array(),
	array(
		'dependence' => true,
		'dependence_hide_on_yes' => '',
		'dependence_show_on_yes' => '#qodef_sidebar_shadow_container'
	));
$panel1->addChild('sidebar_enable_box_shadow', $sidebar_shadow_enable);

$sidebar_shadow_container = new QodePitchContainer('sidebar_shadow_container', 'sidebar_enable_box_shadow', 'no');
$panel1->addChild('sidebar_shadow_container', $sidebar_shadow_container);

$sidebar_shadow_horizontal_offset = new QodePitchField('text', 'sidebar_shadow_horizontal_offset', '', 'Horizontal Offset(px)', 'Use positive numbers for right offset and negative numbers for left offset', array(), array("col_width" => 3));
$sidebar_shadow_container->addChild('sidebar_shadow_horizontal_offset', $sidebar_shadow_horizontal_offset);

$sidebar_shadow_vertical_offset = new QodePitchField('text', 'sidebar_shadow_vertical_offset', '', 'Vertical Offset(px)', 'Use positive numbers for bottom offset and negative numbers for top offset', array(), array("col_width" => 3));
$sidebar_shadow_container->addChild('sidebar_shadow_vertical_offset', $sidebar_shadow_vertical_offset);

$sidebar_shadow_blur = new QodePitchField('text', 'sidebar_shadow_blur', '', 'Blur(px)', 'Define amount of shadow blur in pixels', array(), array("col_width" => 3));
$sidebar_shadow_container->addChild('sidebar_shadow_blur', $sidebar_shadow_blur);

$sidebar_shadow_spread = new QodePitchField('text', 'sidebar_shadow_spread', '', 'Spread(px)', 'Define amount of shadow spread in pixels', array(), array("col_width" => 3));
$sidebar_shadow_container->addChild('sidebar_shadow_spread', $sidebar_shadow_spread);

$sidebar_shadow_color = new QodePitchField('color', 'sidebar_shadow_color', '', 'Color', 'Choose color of shadow');
$sidebar_shadow_container->addChild('sidebar_shadow_color', $sidebar_shadow_color);

$sidebar_alignment = new QodePitchField("select","sidebar_alignment","","Text Alignment","Choose text aligment",array(
    "left" => "Left",
    "center" => "Center",
    "right" => "Right"
));
$panel1->addChild("sidebar_alignment",$sidebar_alignment);

$widget_style = new QodePitchTitle("widget_style", "Widget Style");
$panel1->addChild("widget_style", $widget_style);

    $widget_background_color = new QodePitchField("color","widget_background_color","","Background Color","Choose color for widget background");
    $panel1->addChild("widget_background_color",$widget_background_color);

	$widget_border_color = new QodePitchField("color","widget_border_color","","Border Color","Choose a border color around widget");
	$panel1->addChild("widget_border_color",$widget_border_color);

	$group1 = new QodePitchGroup("Padding","Define padding for widget");
	$panel1->addChild("group1",$group1);
		$row1 = new QodePitchRow(true);
		$group1->addChild("row1",$row1);
			$widget_padding_top = new QodePitchField("textsimple","widget_padding_top","","Top Padding (px)","This is some description");
			$row1->addChild("widget_padding_top",$widget_padding_top);
			$widget_padding_right = new QodePitchField("textsimple","widget_padding_right","","Right Padding (px)","This is some description");
			$row1->addChild("widget_padding_right",$widget_padding_right);
			$widget_padding_bottom = new QodePitchField("textsimple","widget_padding_bottom","","Bottom Padding (px)","This is some description");
			$row1->addChild("widget_padding_bottom",$widget_padding_bottom);
			$widget_padding_left = new QodePitchField("textsimple","widget_padding_left","","Left Padding (px)","This is some description");
			$row1->addChild("widget_padding_left",$widget_padding_left);

	$sidebar_widget_enable_box_shadow = new QodePitchField('yesno', 'sidebar_widget_enable_box_shadow', 'no', 'Enable Shadow For Widgets', '', array(),
		array(
			'dependence' => true,
			'dependence_hide_on_yes' => '',
			'dependence_show_on_yes' => '#qodef_sidebar_widget_shadow_container'
		));
	$panel1->addChild('sidebar_widget_enable_box_shadow', $sidebar_widget_enable_box_shadow);

	$sidebar_widget_shadow_container = new QodePitchContainer('sidebar_widget_shadow_container', 'sidebar_widget_enable_box_shadow', 'no');
	$panel1->addChild('sidebar_widget_shadow_container', $sidebar_widget_shadow_container);

		$sidebar_widget_shadow_horizontal_offset = new QodePitchField('text', 'sidebar_widget_shadow_horizontal_offset', '', 'Horizontal Offset(px)', 'Use positive numbers for right offset and negative numbers for left offset', array(), array("col_width" => 3));
		$sidebar_widget_shadow_container->addChild('sidebar_widget_shadow_horizontal_offset', $sidebar_widget_shadow_horizontal_offset);

		$sidebar_widget_shadow_vertical_offset = new QodePitchField('text', 'sidebar_widget_shadow_vertical_offset', '', 'Vertical Offset(px)', 'Use positive numbers for bottom offset and negative numbers for top offset', array(), array("col_width" => 3));
		$sidebar_widget_shadow_container->addChild('sidebar_widget_shadow_vertical_offset', $sidebar_widget_shadow_vertical_offset);

		$sidebar_widget_shadow_blur = new QodePitchField('text', 'sidebar_widget_shadow_blur', '', 'Blur(px)', 'Define amount of shadow blur in pixels', array(), array("col_width" => 3));
		$sidebar_widget_shadow_container->addChild('sidebar_widget_shadow_blur', $sidebar_widget_shadow_blur);

		$sidebar_widget_shadow_spread = new QodePitchField('text', 'sidebar_widget_shadow_spread', '', 'Spread(px)', 'Define amount of shadow spread in pixels', array(), array("col_width" => 3));
		$sidebar_widget_shadow_container->addChild('sidebar_widget_shadow_spread', $sidebar_widget_shadow_spread);

		$sidebar_widget_shadow_color = new QodePitchField('color', 'sidebar_widget_shadow_color', '', 'Color', 'Choose color of shadow');
		$sidebar_widget_shadow_container->addChild('sidebar_widget_shadow_color', $sidebar_widget_shadow_color); 

$widget_title = new QodePitchTitle("widget_title", "Widget Title");
$panel1->addChild("widget_title", $widget_title);

	$group2 = new QodePitchGroup("Text Style","Define styles for widgets title");
	$panel1->addChild("group2",$group2);
		$row1 = new QodePitchRow();
		$group2->addChild("row1",$row1);
        $sidebar_title_color = new QodePitchField("colorsimple","sidebar_title_color","","Text Color","This is some description");
			$row1->addChild("sidebar_title_color",$sidebar_title_color);

			$sidebar_title_font_size = new QodePitchField("textsimple","sidebar_title_font_size","","Font Size (px)","This is some description");
			$row1->addChild("sidebar_title_font_size",$sidebar_title_font_size);

			$sidebar_title_line_height = new QodePitchField("textsimple","sidebar_title_line_height","","Line Height (px)","This is some description");
			$row1->addChild("sidebar_title_line_height",$sidebar_title_line_height);

			$sidebar_title_text_transform = new QodePitchField("selectblanksimple","sidebar_title_text_transform","","Text Transform","This is some description",$qode_pitch_options_texttransform);
			$row1->addChild("sidebar_title_text_transform",$sidebar_title_text_transform);

		$row2 = new QodePitchRow(true);
		$group2->addChild("row2",$row2);
			$sidebar_title_font_family = new QodePitchField("fontsimple","sidebar_title_font_family","-1","Font Family","This is some description");
			$row2->addChild("sidebar_title_font_family",$sidebar_title_font_family);

			$sidebar_title_font_style = new QodePitchField("selectblanksimple","sidebar_title_font_style","","Font Style","This is some description",$qode_pitch_options_fontstyle);
			$row2->addChild("sidebar_title_font_style",$sidebar_title_font_style);

			$sidebar_title_font_weight = new QodePitchField("selectblanksimple","sidebar_title_font_weight","","Font Weight","This is some description",$qode_pitch_options_fontweight);
			$row2->addChild("sidebar_title_font_weight",$sidebar_title_font_weight);

			$sidebar_title_letter_spacing = new QodePitchField("textsimple","sidebar_title_letter_spacing","","Letter Spacing (px)","This is some description");
			$row2->addChild("sidebar_title_letter_spacing",$sidebar_title_letter_spacing);
			
$sidebar_title_aligment = new QodePitchField("select","sidebar_title_aligment","","Title Text Alignment","Choose text alignment for widget title",array(
    "left" => "Left",
    "center" => "Center",
    "right" => "Right"
));
$panel1->addChild("sidebar_title_aligment",$sidebar_title_aligment);

$sidebar_title_background = new QodePitchField("color","sidebar_title_background","","Background Color","Choose color for background");
$panel1->addChild("sidebar_title_background",$sidebar_title_background);

$sidebar_title_border_color = new QodePitchField("color","sidebar_title_border_color","","Border Color","Choose color for border");
$panel1->addChild("sidebar_title_border_color",$sidebar_title_border_color);

	$group8 = new QodePitchGroup("Padding for Title","Define padding for title");
	$panel1->addChild("group8",$group8);

		$row1 = new QodePitchRow();
		$group8->addChild("row1",$row1);

			$sidebar_title_padding_top = new QodePitchField("textsimple","sidebar_title_padding_top","","Top Padding (px)","This is some description");
			$row1->addChild("sidebar_title_padding_top",$sidebar_title_padding_top);

			$sidebar_title_padding_right = new QodePitchField("textsimple","sidebar_title_padding_right","","Right Padding (px)","This is some description");
			$row1->addChild("sidebar_title_padding_right",$sidebar_title_padding_right);

			$sidebar_title_padding_bottom = new QodePitchField("textsimple","sidebar_title_padding_bottom","","Bottom Padding (px)","This is some description");
			$row1->addChild("sidebar_title_padding_bottom",$sidebar_title_padding_bottom);

			$sidebar_title_padding_left = new QodePitchField("textsimple","sidebar_title_padding_left","","Left Padding (px)","This is some description");
			$row1->addChild("sidebar_title_padding_left",$sidebar_title_padding_left);			

	$group4 = new QodePitchGroup("Separator","Define styles for title separator");
	$panel1->addChild("group4",$group4);
		$row1 = new QodePitchRow();
		$group4->addChild("row1",$row1);
			$sidebar_title_border_bottom_color = new QodePitchField("colorsimple","sidebar_title_border_bottom_color","","Color","This is some description");
			$row1->addChild("sidebar_title_border_bottom_color",$sidebar_title_border_bottom_color);

			$sidebar_title_border_bottom_width = new QodePitchField("textsimple","sidebar_title_border_bottom_width","","Thickness (px)","This is some description");
			$row1->addChild("sidebar_title_border_bottom_width",$sidebar_title_border_bottom_width);

			$sidebar_title_border_bottom_padding_bottom = new QodePitchField("textsimple","sidebar_title_border_bottom_padding_bottom","","Top Margin (px)","This is some description");
			$row1->addChild("sidebar_title_border_bottom_padding_bottom",$sidebar_title_border_bottom_padding_bottom);

			$sidebar_title_border_bottom_margin_bottom = new QodePitchField("textsimple","sidebar_title_border_bottom_margin_bottom","","Bottom Margin (px)","This is some description");
			$row1->addChild("sidebar_title_border_bottom_margin_bottom",$sidebar_title_border_bottom_margin_bottom);

		$row2 = new QodePitchRow();
		$group4->addChild("row2",$row2);

			$sidebar_title_border_bottom_length = new QodePitchField("textsimple","sidebar_title_border_bottom_length","","Width (px)","This is some description");
			$row2->addChild("sidebar_title_border_bottom_length",$sidebar_title_border_bottom_length);

$widget_text = new QodePitchTitle("widget_text", "Widget Text");
$panel1->addChild("widget_text", $widget_text);

	$group7 = new QodePitchGroup("Text Style","Define styles for widgets text");
	$panel1->addChild("group7",$group7);
		$row1 = new QodePitchRow();
		$group7->addChild("row1",$row1);
			$sidebar_text_color = new QodePitchField("colorsimple","sidebar_text_color","","Text Color","This is some description");
			$row1->addChild("sidebar_text_color",$sidebar_text_color);

			$sidebar_text_font_size = new QodePitchField("textsimple","sidebar_text_font_size","","Font Size (px)","This is some description");
			$row1->addChild("sidebar_text_font_size",$sidebar_text_font_size);

			$sidebar_text_line_height = new QodePitchField("textsimple","sidebar_text_line_height","","Line Height (px)","This is some description");
			$row1->addChild("sidebar_text_line_height",$sidebar_text_line_height);

			$sidebar_text_text_transform = new QodePitchField("selectblanksimple","sidebar_text_text_transform","","Text Transform","This is some description",$qode_pitch_options_texttransform);
			$row1->addChild("sidebar_text_text_transform",$sidebar_text_text_transform);

		$row2 = new QodePitchRow(true);
		$group7->addChild("row2",$row2);
			$sidebar_text_font_family = new QodePitchField("fontsimple","sidebar_text_font_family","-1","Font Family","This is some description");
			$row2->addChild("sidebar_text_font_family",$sidebar_text_font_family);

			$sidebar_text_font_style = new QodePitchField("selectblanksimple","sidebar_text_font_style","","Font Style","This is some description",$qode_pitch_options_fontstyle);
			$row2->addChild("sidebar_text_font_style",$sidebar_text_font_style);

			$sidebar_text_font_weight = new QodePitchField("selectblanksimple","sidebar_text_font_weight","","Font Weight","This is some description",$qode_pitch_options_fontweight);
			$row2->addChild("sidebar_text_font_weight",$sidebar_text_font_weight);

			$sidebar_text_letter_spacing = new QodePitchField("textsimple","sidebar_text_letter_spacing","","Letter Spacing (px)","This is some description");
			$row2->addChild("sidebar_text_letter_spacing",$sidebar_text_letter_spacing);

$widget_link = new QodePitchTitle("widget_link", "Widget Link");
$panel1->addChild("widget_link", $widget_link);

	$group3 = new QodePitchGroup("Text Style","Define styles for widget links");
	$panel1->addChild("group3",$group3);
		$row1 = new QodePitchRow();
		$group3->addChild("row1",$row1);
            $sidebar_link_color = new QodePitchField("colorsimple","sidebar_link_color","","Text Color","This is some description");
			$row1->addChild("sidebar_link_color",$sidebar_link_color);

            $sidebar_link_hover_color = new QodePitchField("colorsimple","sidebar_link_hover_color","","Text Hover Color","This is some description");
            $row1->addChild("sidebar_link_hover_color",$sidebar_link_hover_color);

			$sidebar_link_font_size = new QodePitchField("textsimple","sidebar_link_font_size","","Font Size (px)","This is some description");
			$row1->addChild("sidebar_link_font_size",$sidebar_link_font_size);

			$sidebar_link_line_height = new QodePitchField("textsimple","sidebar_link_line_height","","Line Height (px)","This is some description");
			$row1->addChild("sidebar_link_line_height",$sidebar_link_line_height);

		$row2 = new QodePitchRow(true);
		$group3->addChild("row2",$row2);

            $sidebar_link_text_transform = new QodePitchField("selectblanksimple","sidebar_link_text_transform","","Text Transform","This is some description",$qode_pitch_options_texttransform);
            $row2->addChild("sidebar_link_text_transform",$sidebar_link_text_transform);

			$sidebar_link_font_family = new QodePitchField("fontsimple","sidebar_link_font_family","-1","Font Family","This is some description");
			$row2->addChild("sidebar_link_font_family",$sidebar_link_font_family);

			$sidebar_link_font_style = new QodePitchField("selectblanksimple","sidebar_link_font_style","","Font Style","This is some description",$qode_pitch_options_fontstyle);
			$row2->addChild("sidebar_link_font_style",$sidebar_link_font_style);

			$sidebar_link_font_weight = new QodePitchField("selectblanksimple","sidebar_link_font_weight","","Font Weight","This is some description",$qode_pitch_options_fontweight);
			$row2->addChild("sidebar_link_font_weight",$sidebar_link_font_weight);

		$row3 = new QodePitchRow(true);
		$group3->addChild("row3",$row3);
            $sidebar_link_letter_spacing = new QodePitchField("textsimple","sidebar_link_letter_spacing","","Letter Spacing (px)","This is some description");
            $row3->addChild("sidebar_link_letter_spacing",$sidebar_link_letter_spacing);

$group9 = new QodePitchGroup("Separator Style","Choose style for separator between links");
$panel1->addChild("group9",$group9);

	$row1 = new QodePitchRow();
	$group9->addChild("row1",$row1);

		$sidebar_link_separator_color = new QodePitchField("colorsimple","sidebar_link_separator_color","","Separator between links color","Choose color for separator between color");
		$row1->addChild("sidebar_link_separator_color",$sidebar_link_separator_color);

		$sidebar_link_separator_type = new QodePitchField("selectblanksimple","sidebar_link_separator_type","","Separator between links style","Choose style for separator",array(
			"solid" => "Solid",
			"dotted" => "Dotted",
			"dashed" => "Dashed"
			));
		$row1->addChild("sidebar_link_separator_type",$sidebar_link_separator_type);

$widget_elements = new QodePitchTitle("widget_elements", "Widget Elements");
$panel1->addChild("widget_elements", $widget_elements);

	$group5 = new QodePitchGroup("Search","Define styles for search in widget");
	$panel1->addChild("group5",$group5);
		$row1 = new QodePitchRow();
		$group5->addChild("row1",$row1);
		
			$sidebar_search_height = new QodePitchField("textsimple","sidebar_search_height","","Height (px)","This is some description");
            $row1->addChild("sidebar_search_height",$sidebar_search_height);
			
			$sidebar_search_border_color = new QodePitchField("colorsimple","sidebar_search_border_color","","Border Color","This is some description");
			$row1->addChild("sidebar_search_border_color",$sidebar_search_border_color);

			$sidebar_search_loupe_color = new QodePitchField("colorsimple","sidebar_search_loupe_color","","Magnifier Color","This is some description");
			$row1->addChild("sidebar_search_loupe_color",$sidebar_search_loupe_color);
			
			$sidebar_search_loupe_background_color = new QodePitchField("colorsimple","sidebar_search_loupe_background_color","","Magnifier Area Background Color","This is some description");
			$row1->addChild("sidebar_search_loupe_background_color",$sidebar_search_loupe_background_color);

        $row2 = new QodePitchRow();
        $group5->addChild("row2",$row2);
            $sidebar_search_text_color = new QodePitchField("colorsimple","sidebar_search_text_color","","Text Color","This is some description");
            $row2->addChild("sidebar_search_text_color",$sidebar_search_text_color);

            $sidebar_search_focus_text_color = new QodePitchField("colorsimple","sidebar_search_focus_text_color","","Focus Text Color","This is some description");
            $row2->addChild("sidebar_search_focus_text_color",$sidebar_search_focus_text_color);

            $sidebar_search_text_font_size = new QodePitchField("textsimple","sidebar_search_text_font_size","","Font Size (px)","This is some description");
            $row2->addChild("sidebar_search_text_font_size",$sidebar_search_text_font_size);

            $sidebar_search_text_line_height = new QodePitchField("textsimple","sidebar_search_text_line_height","","Line Height (px)","This is some description");
            $row2->addChild("sidebar_search_text_line_height",$sidebar_search_text_line_height);



        $row3 = new QodePitchRow(true);
        $group5->addChild("row3",$row3);

            $sidebar_search_text_text_transform = new QodePitchField("selectblanksimple","sidebar_search_text_text_transform","","Text Transform","This is some description",$qode_pitch_options_texttransform);
            $row3->addChild("sidebar_search_text_text_transform",$sidebar_search_text_text_transform);

            $sidebar_search_text_font_family = new QodePitchField("fontsimple","sidebar_search_text_font_family","-1","Font Family","This is some description");
            $row3->addChild("sidebar_search_text_font_family",$sidebar_search_text_font_family);

            $sidebar_search_text_font_style = new QodePitchField("selectblanksimple","sidebar_search_text_font_style","","Font Style","This is some description",$qode_pitch_options_fontstyle);
            $row3->addChild("sidebar_search_text_font_style",$sidebar_search_text_font_style);

            $sidebar_search_text_font_weight = new QodePitchField("selectblanksimple","sidebar_search_text_font_weight","","Font Weight","This is some description",$qode_pitch_options_fontweight);
            $row3->addChild("sidebar_search_text_font_weight",$sidebar_search_text_font_weight);

        $row4 = new QodePitchRow(true);
        $group5->addChild("row4",$row4);

            $sidebar_search_text_letter_spacing = new QodePitchField("textsimple","sidebar_search_text_letter_spacing","","Letter Spacing (px)","This is some description");
            $row4->addChild("sidebar_search_text_letter_spacing",$sidebar_search_text_letter_spacing);            

            $sidebar_search_border_around = new QodePitchField("selectsimple","sidebar_search_border_around","","Border Around","This is some description",array(
                "around_everything" => "Around Everything",
                "around_search_text" => "Around Search Text"
                ));
            $row4->addChild("sidebar_search_border_around",$sidebar_search_border_around);


$widget_blog_list = new QodePitchTitle("widget_blog_list", "Widget - Select Blog");
$panel1->addChild("widget_blog_list", $widget_blog_list);

$group10 = new QodePitchGroup("Blog List Title","Define Blog List title style");
$panel1->addChild("group10",$group10);
    $row1 = new QodePitchRow();
    $group10->addChild("row1",$row1);

        $widget_blog_list_title_color = new QodePitchField("colorsimple","widget_blog_list_title_color","","Text Color","This is some description");
        $row1->addChild("widget_blog_list_title_color",$widget_blog_list_title_color);

        $widget_blog_list_title_hover_color = new QodePitchField("colorsimple","widget_blog_list_title_hover_color","","Text Hover Color","This is some description");
        $row1->addChild("widget_blog_list_title_hover_color",$widget_blog_list_title_hover_color);

        $widget_blog_list_title_font_size = new QodePitchField("textsimple","widget_blog_list_title_font_size","","Font Size (px)","This is some description");
        $row1->addChild("widget_blog_list_title_font_size",$widget_blog_list_title_font_size);

        $widget_blog_list_title_line_height = new QodePitchField("textsimple","widget_blog_list_title_line_height","","Line Height (px)","This is some description");
        $row1->addChild("widget_blog_list_title_line_height",$widget_blog_list_title_line_height);

    $row2 = new QodePitchRow(true);
    $group10->addChild("row2",$row2);

        $widget_blog_list_title_text_transform = new QodePitchField("selectblanksimple","widget_blog_list_title_text_transform","","Text Transform","This is some description",$qode_pitch_options_texttransform);
        $row2->addChild("widget_blog_list_title_text_transform",$widget_blog_list_title_text_transform);

        $widget_blog_list_title_font_family = new QodePitchField("fontsimple","widget_blog_list_title_font_family","-1","Font Family","This is some description");
        $row2->addChild("widget_blog_list_title_font_family",$widget_blog_list_title_font_family);

        $widget_blog_list_title_font_style = new QodePitchField("selectblanksimple","widget_blog_list_title_font_style","","Font Style","This is some description",$qode_pitch_options_fontstyle);
        $row2->addChild("widget_blog_list_title_font_style",$widget_blog_list_title_font_style);

        $widget_blog_list_title_font_weight = new QodePitchField("selectblanksimple","widget_blog_list_title_font_weight","","Font Weight","This is some description",$qode_pitch_options_fontweight);
        $row2->addChild("widget_blog_list_title_font_weight",$widget_blog_list_title_font_weight);

        
    $row3 = new QodePitchRow(true);
    $group10->addChild("row3",$row3);

        $widget_blog_list_title_letter_spacing = new QodePitchField("textsimple","widget_blog_list_title_letter_spacing","","Letter Spacing (px)","This is some description");
        $row3->addChild("widget_blog_list_title_letter_spacing",$widget_blog_list_title_letter_spacing);


$group11 = new QodePitchGroup("Blog List Post Info","Define blog list post info style");
$panel1->addChild("group11",$group11);
    $row1 = new QodePitchRow();
    $group11->addChild("row1",$row1);

        $widget_blog_list_post_info_color = new QodePitchField("colorsimple","widget_blog_list_post_info_color","","Text Color","This is some description");
        $row1->addChild("widget_blog_list_post_info_color",$widget_blog_list_post_info_color);

        $widget_blog_list_post_info_link_color = new QodePitchField("colorsimple","widget_blog_list_post_info_link_color","","Link Color","This is some description");
        $row1->addChild("widget_blog_list_post_info_link_color",$widget_blog_list_post_info_link_color);

        $widget_blog_list_post_info_link_hover_color = new QodePitchField("colorsimple","widget_blog_list_post_info_link_hover_color","","Link Hover Color","This is some description");
        $row1->addChild("widget_blog_list_post_info_link_hover_color",$widget_blog_list_post_info_link_hover_color);

        $widget_blog_list_post_info_font_size = new QodePitchField("textsimple","widget_blog_list_post_info_font_size","","Font Size (px)","This is some description");
        $row1->addChild("widget_blog_list_post_info_font_size",$widget_blog_list_post_info_font_size);


    $row2 = new QodePitchRow(true);
    $group11->addChild("row2",$row2);

        $widget_blog_list_post_info_line_height = new QodePitchField("textsimple","widget_blog_list_post_info_line_height","","Line Height (px)","This is some description");
        $row2->addChild("widget_blog_list_post_info_line_height",$widget_blog_list_post_info_line_height);

        $widget_blog_list_post_info_text_transform = new QodePitchField("selectblanksimple","widget_blog_list_post_info_text_transform","","Text Transform","This is some description",$qode_pitch_options_texttransform);
        $row2->addChild("widget_blog_list_post_info_text_transform",$widget_blog_list_post_info_text_transform);

        $widget_blog_list_post_info_font_family = new QodePitchField("fontsimple","widget_blog_list_post_info_font_family","-1","Font Family","This is some description");
        $row2->addChild("widget_blog_list_post_info_font_family",$widget_blog_list_post_info_font_family);

        $widget_blog_list_post_info_font_style = new QodePitchField("selectblanksimple","widget_blog_list_post_info_font_style","","Font Style","This is some description",$qode_pitch_options_fontstyle);
        $row2->addChild("widget_blog_list_post_info_font_style",$widget_blog_list_post_info_font_style);

    $row3 = new QodePitchRow(true);
    $group11->addChild("row3",$row3);

        $widget_blog_list_post_info_font_weight = new QodePitchField("selectblanksimple","widget_blog_list_post_info_font_weight","","Font Weight","This is some description",$qode_pitch_options_fontweight);
        $row3->addChild("widget_blog_list_post_info_font_weight",$widget_blog_list_post_info_font_weight);

        $widget_blog_list_post_info_letter_spacing = new QodePitchField("textsimple","widget_blog_list_post_info_letter_spacing","","Letter Spacing (px)","This is some description");
        $row3->addChild("widget_blog_list_post_info_letter_spacing",$widget_blog_list_post_info_letter_spacing);

$group12 = new QodePitchGroup("Blog List Date Style","Define blog list date style");
$panel1->addChild("group12",$group12);
    $row1 = new QodePitchRow();
    $group12->addChild("row1",$row1);

        $widget_blog_list_date_color = new QodePitchField("colorsimple","widget_blog_list_date_color","","Text Color","This is some description");
        $row1->addChild("widget_blog_list_date_color",$widget_blog_list_date_color);

        $widget_blog_list_date_font_size = new QodePitchField("textsimple","widget_blog_list_date_font_size","","Font Size (px)","This is some description");
        $row1->addChild("widget_blog_list_date_font_size",$widget_blog_list_date_font_size);

        $widget_blog_list_date_line_height = new QodePitchField("textsimple","widget_blog_list_date_line_height","","Line Height (px)","This is some description");
        $row1->addChild("widget_blog_list_date_line_height",$widget_blog_list_date_line_height);

        $widget_blog_list_date_text_transform = new QodePitchField("selectblanksimple","widget_blog_list_date_text_transform","","Text Transform","This is some description",$qode_pitch_options_texttransform);
        $row1->addChild("widget_blog_list_date_text_transform",$widget_blog_list_date_text_transform);

    $row2 = new QodePitchRow(true);
    $group12->addChild("row2",$row2);

        $widget_blog_list_date_font_family = new QodePitchField("fontsimple","widget_blog_list_date_font_family","-1","Font Family","This is some description");
        $row2->addChild("widget_blog_list_date_font_family",$widget_blog_list_date_font_family);

        $widget_blog_list_date_font_style = new QodePitchField("selectblanksimple","widget_blog_list_date_font_style","","Font Style","This is some description",$qode_pitch_options_fontstyle);
        $row2->addChild("widget_blog_list_date_font_style",$widget_blog_list_date_font_style);

        $widget_blog_list_date_font_weight = new QodePitchField("selectblanksimple","widget_blog_list_date_font_weight","","Font Weight","This is some description",$qode_pitch_options_fontweight);
        $row2->addChild("widget_blog_list_date_font_weight",$widget_blog_list_date_font_weight);

        $widget_blog_list_date_letter_spacing = new QodePitchField("textsimple","widget_blog_list_date_letter_spacing","","Letter Spacing (px)","This is some description");
        $row2->addChild("widget_blog_list_date_letter_spacing",$widget_blog_list_date_letter_spacing);

$group31 = new QodePitchGroup("Blog List Spacing","Define blog list spacing");
$panel1->addChild("group31",$group31);

    $row1 = new QodePitchRow(true);
    $group31->addChild("row1",$row1);
    
        $widget_blog_list_title_margin_bttm = new QodePitchField("textsimple","widget_blog_list_title_margin_bttm","","Margin Under Title (px)","This is some description");
        $row1->addChild("widget_blog_list_title_margin_bttm",$widget_blog_list_title_margin_bttm);
        
        $widget_blog_list_post_info_margin_bttm = new QodePitchField("textsimple","widget_blog_list_post_info_margin_bttm","","Margin Under Post Info (px)","This is some description");
        $row1->addChild("widget_blog_list_post_info_margin_bttm",$widget_blog_list_post_info_margin_bttm);
        
        $widget_blog_list_read_more_margin_top = new QodePitchField("textsimple","widget_blog_list_read_more_margin_top","","Margin Above Read More Button (px)","This is some description");
        $row1->addChild("widget_blog_list_read_more_margin_top",$widget_blog_list_read_more_margin_top);  