<?php

$portfolioPage = new QodePitchAdminPage("9", "Portfolio", "fa fa-camera-retro");
$qode_pitch_Framework->qodeOptions->addAdminPage("portfolioPage",$portfolioPage);

//Portfolio List

$panel1 = new QodePitchPanel("Portfolio List", "porfolio_list");
$portfolioPage->addChild("panel1",$panel1);

    $portfolio_qode_like = new QodePitchField("onoff","portfolio_qode_like","on","Likes",'Enabling this option will turn on "Likes"');
    $panel1->addChild("portfolio_qode_like",$portfolio_qode_like);

	$portfolio_disable_text_box = new QodePitchField("yesno","portfolio_disable_text_box","yes","Disable Boxed Style Project Description","Disabling boxed styled project description", array(), array("dependence" => true, "dependence_hide_on_yes" => "#qodef_enable_portfolio_list_box_container", "dependence_show_on_yes" => ""));
	$panel1->addChild("portfolio_disable_text_box",$portfolio_disable_text_box);

	$enable_portfolio_list_box_container = new QodePitchContainer("enable_portfolio_list_box_container","portfolio_disable_text_box","yes");
	$panel1->addChild("enable_portfolio_list_box_container",$enable_portfolio_list_box_container);

		$portfolio_list_box_background_color = new QodePitchField("color","portfolio_list_box_background_color","","Portfolio Box Background Color","Default color is #ffffff");
		$enable_portfolio_list_box_container->addChild("portfolio_list_box_background_color",$portfolio_list_box_background_color);

    $group1 = new QodePitchGroup("Image Hover Overlay Color","Define icons styles on project hover. Default hover color is #279eff.");
    $panel1->addChild("group1",$group1);

        $row1 = new QodePitchRow();
        $group1->addChild("row1",$row1);

            $portfolio_shader_color = new QodePitchField("colorsimple","portfolio_shader_color","","Color","This is some description");
            $row1->addChild("portfolio_shader_color",$portfolio_shader_color);

            $portfolio_shader_transparency = new QodePitchField("textsimple","portfolio_shader_transparency","","Transparency (0=full - 1=opaque)","This is some description", array(), array("col_width" => 3));
            $row1->addChild("portfolio_shader_transparency",$portfolio_shader_transparency);


// Portfolio List TEXT STYLES

$title_text_styles = new QodePitchTitle("title_text_styles","Title Text Styles");
$panel1->addChild("title_text_styles",$title_text_styles);

    $group7 = new QodePitchGroup("Title Style for Standard and Pinterest Lists","Define title styles for standard and pinterest portfolio lists.");
    $panel1->addChild("group7",$group7);

        $row1 = new QodePitchRow();
        $group7->addChild("row1",$row1);
            $portfolio_title_standard_list_color = new QodePitchField("colorsimple","portfolio_title_standard_list_color","","Text Color","This is some description");
            $row1->addChild("portfolio_title_standard_list_color",$portfolio_title_standard_list_color);
            $portfolio_title_standard_list_hover_color = new QodePitchField("colorsimple","portfolio_title_standard_list_hover_color","","Text Hover Color","This is some description");
            $row1->addChild("portfolio_title_standard_list_hover_color",$portfolio_title_standard_list_hover_color);
            $portfolio_title_standard_list_font_size = new QodePitchField("textsimple","portfolio_title_standard_list_font_size","","Font Size (px)","This is some description");
            $row1->addChild("portfolio_title_standard_list_font_size",$portfolio_title_standard_list_font_size);
            $portfolio_title_standard_list_line_height = new QodePitchField("textsimple","portfolio_title_standard_list_line_height","","Line Height (px)","This is some description");
            $row1->addChild("portfolio_title_standard_list_line_height",$portfolio_title_standard_list_line_height);

        $row2 = new QodePitchRow(true);
        $group7->addChild("row2",$row2);
            $portfolio_title_standard_list_text_transform = new QodePitchField("selectblanksimple","portfolio_title_standard_list_text_transform","","Text Transform","This is some description",$qode_pitch_options_texttransform);
            $row2->addChild("portfolio_title_standard_list_text_transform",$portfolio_title_standard_list_text_transform);
            $portfolio_title_standard_list_font_family = new QodePitchField("fontsimple","portfolio_title_standard_list_font_family","-1","Font Family","This is some description");
            $row2->addChild("portfolio_title_standard_list_font_family",$portfolio_title_standard_list_font_family);
            $portfolio_title_standard_list_font_style = new QodePitchField("selectblanksimple","portfolio_title_standard_list_font_style","","Font Style","This is some description",$qode_pitch_options_fontstyle);
            $row2->addChild("portfolio_title_standard_list_font_style",$portfolio_title_standard_list_font_style);
            $portfolio_title_standard_list_font_weight = new QodePitchField("selectblanksimple","portfolio_title_standard_list_font_weight","","Font Weight","This is some description",$qode_pitch_options_fontweight);
            $row2->addChild("portfolio_title_standard_list_font_weight",$portfolio_title_standard_list_font_weight);

        $row3 = new QodePitchRow(true);
        $group7->addChild("row3",$row3);
            $portfolio_title_standard_list_letter_spacing = new QodePitchField("textsimple","portfolio_title_standard_list_letter_spacing","","Letter Spacing (px)","This is some description");
            $row3->addChild("portfolio_title_standard_list_letter_spacing",$portfolio_title_standard_list_letter_spacing);

    $group9 = new QodePitchGroup("Title Style for Text on Hover Image and Text before Hover Lists","Define title styles for text on hover image and text before hover portfolio lists.");
    $panel1->addChild("group9",$group9);

        $row1 = new QodePitchRow();
        $group9->addChild("row1",$row1);
            $portfolio_title_hover_box_list_color = new QodePitchField("colorsimple","portfolio_title_hover_box_list_color","","Text Color","This is some description");
            $row1->addChild("portfolio_title_hover_box_list_color",$portfolio_title_hover_box_list_color);
            $portfolio_title_hover_box_list_hover_color = new QodePitchField("colorsimple","portfolio_title_hover_box_list_hover_color","","Text Hover Color","This is some description");
            $row1->addChild("portfolio_title_hover_box_list_hover_color",$portfolio_title_hover_box_list_hover_color);
            $portfolio_title_hover_box_list_font_size = new QodePitchField("textsimple","portfolio_title_hover_box_list_font_size","","Font Size (px)","This is some description");
            $row1->addChild("portfolio_title_hover_box_list_font_size",$portfolio_title_hover_box_list_font_size);
            $portfolio_title_hover_box_list_line_height = new QodePitchField("textsimple","portfolio_title_hover_box_list_line_height","","Line Height (px)","This is some description");
            $row1->addChild("portfolio_title_hover_box_list_line_height",$portfolio_title_hover_box_list_line_height);

        $row2 = new QodePitchRow(true);
        $group9->addChild("row2",$row2);
            $portfolio_title_hover_box_list_font_family = new QodePitchField("fontsimple","portfolio_title_hover_box_list_font_family","-1","Font Family","This is some description");
            $row2->addChild("portfolio_title_hover_box_list_font_family",$portfolio_title_hover_box_list_font_family);
            $portfolio_title_hover_box_list_text_transform = new QodePitchField("selectblanksimple","portfolio_title_hover_box_list_text_transform","","Text Transform","This is some description",$qode_pitch_options_texttransform);
            $row2->addChild("portfolio_title_hover_box_list_text_transform",$portfolio_title_hover_box_list_text_transform);
            $portfolio_title_hover_box_list_font_style = new QodePitchField("selectblanksimple","portfolio_title_hover_box_list_font_style","","Font Style","This is some description",$qode_pitch_options_fontstyle);
            $row2->addChild("portfolio_title_hover_box_list_font_style",$portfolio_title_hover_box_list_font_style);
            $portfolio_title_hover_box_list_font_weight = new QodePitchField("selectblanksimple","portfolio_title_hover_box_list_font_weight","","Font Weight","This is some description",$qode_pitch_options_fontweight);
            $row2->addChild("portfolio_title_hover_box_list_font_weight",$portfolio_title_hover_box_list_font_weight);

        $row3 = new QodePitchRow(true);
        $group9->addChild("row3",$row3);
            $portfolio_title_hover_box_list_letter_spacing = new QodePitchField("textsimple","portfolio_title_hover_box_list_letter_spacing","","Letter Spacing (px)","This is some description");
            $row3->addChild("portfolio_title_hover_box_list_letter_spacing",$portfolio_title_hover_box_list_letter_spacing);

    $group11 = new QodePitchGroup("Title Style for Portfolio Slider and Masonry Lists","Define title styles for slider and masonry portfolio lists.");
    $panel1->addChild("group11",$group11);

        $row1 = new QodePitchRow();
        $group11->addChild("row1",$row1);
            $portfolio_title_list_color = new QodePitchField("colorsimple","portfolio_title_list_color","","Text Color","This is some description");
            $row1->addChild("portfolio_title_list_color",$portfolio_title_list_color);
            $portfolio_title_list_hover_color = new QodePitchField("colorsimple","portfolio_title_list_hover_color","","Text Hover Color","This is some description");
            $row1->addChild("portfolio_title_list_hover_color",$portfolio_title_list_hover_color);
            $portfolio_title_list_font_size = new QodePitchField("textsimple","portfolio_title_list_font_size","","Font Size (px)","This is some description");
            $row1->addChild("portfolio_title_list_font_size",$portfolio_title_list_font_size);
            $portfolio_title_list_line_height = new QodePitchField("textsimple","portfolio_title_list_line_height","","Line Height (px)","This is some description");
            $row1->addChild("portfolio_title_list_line_height",$portfolio_title_list_line_height);

        $row2 = new QodePitchRow(true);
        $group11->addChild("row2",$row2);
            $portfolio_title_list_text_transform = new QodePitchField("selectblanksimple","portfolio_title_list_text_transform","","Text Transform","This is some description",$qode_pitch_options_texttransform);
            $row2->addChild("portfolio_title_list_text_transform",$portfolio_title_list_text_transform);
            $portfolio_title_list_font_family = new QodePitchField("fontsimple","portfolio_title_list_font_family","-1","Font Family","This is some description");
            $row2->addChild("portfolio_title_list_font_family",$portfolio_title_list_font_family);
            $portfolio_title_list_font_style = new QodePitchField("selectblanksimple","portfolio_title_list_font_style","","Font Style","This is some description",$qode_pitch_options_fontstyle);
            $row2->addChild("portfolio_title_list_font_style",$portfolio_title_list_font_style);
            $portfolio_title_list_font_weight = new QodePitchField("selectblanksimple","portfolio_title_list_font_weight","","Font Weight","This is some description",$qode_pitch_options_fontweight);
            $row2->addChild("portfolio_title_list_font_weight",$portfolio_title_list_font_weight);

            $row3 = new QodePitchRow(true);
            $group11->addChild("row3",$row3);
            $portfolio_title_list_letter_spacing = new QodePitchField("textsimple","portfolio_title_list_letter_spacing","","Letter Spacing (px)","This is some description");
            $row3->addChild("portfolio_title_list_letter_spacing",$portfolio_title_list_letter_spacing);

$category_text_styles = new QodePitchTitle("category_text_styles","Category Text Styles");
$panel1->addChild("category_text_styles",$category_text_styles);

    $group8 = new QodePitchGroup("Category Style for Standard and Pinterest Lists","Define category styles for standard and pinterest portfolio lists.");
    $panel1->addChild("group8",$group8);

         $row1 = new QodePitchRow();
         $group8->addChild("row1",$row1);
            $portfolio_category_standard_list_color = new QodePitchField("colorsimple","portfolio_category_standard_list_color","","Text Color","This is some description");
            $row1->addChild("portfolio_category_standard_list_color",$portfolio_category_standard_list_color);
            $portfolio_category_standard_list_font_size = new QodePitchField("textsimple","portfolio_category_standard_list_font_size","","Font Size (px)","This is some description");
            $row1->addChild("portfolio_category_standard_list_font_size",$portfolio_category_standard_list_font_size);
            $portfolio_category_standard_list_line_height = new QodePitchField("textsimple","portfolio_category_standard_list_line_height","","Line Height (px)","This is some description");
            $row1->addChild("portfolio_category_standard_list_line_height",$portfolio_category_standard_list_line_height);
            $portfolio_category_standard_list_text_transform = new QodePitchField("selectblanksimple","portfolio_category_standard_list_text_transform","","Text Transform","This is some description",$qode_pitch_options_texttransform);
            $row1->addChild("portfolio_category_standard_list_text_transform",$portfolio_category_standard_list_text_transform);

        $row2 = new QodePitchRow(true);
        $group8->addChild("row2",$row2);
            $portfolio_category_standard_list_font_family = new QodePitchField("fontsimple","portfolio_category_standard_list_font_family","-1","Font Family","This is some description");
            $row2->addChild("portfolio_category_standard_list_font_family",$portfolio_category_standard_list_font_family);
            $portfolio_category_standard_list_font_style = new QodePitchField("selectblanksimple","portfolio_category_standard_list_font_style","","Font Style","This is some description",$qode_pitch_options_fontstyle);
            $row2->addChild("portfolio_category_standard_list_font_style",$portfolio_category_standard_list_font_style);
            $portfolio_category_standard_list_font_weight = new QodePitchField("selectblanksimple","portfolio_category_standard_list_font_weight","","Font Weight","This is some description",$qode_pitch_options_fontweight);
            $row2->addChild("portfolio_category_standard_list_font_weight",$portfolio_category_standard_list_font_weight);
            $portfolio_category_standard_list_letter_spacing = new QodePitchField("textsimple","portfolio_category_standard_list_letter_spacing","","Letter Spacing (px)","This is some description");
            $row2->addChild("portfolio_category_standard_list_letter_spacing",$portfolio_category_standard_list_letter_spacing);

    $group10 = new QodePitchGroup("Category Style for Text on Hover Image and Text before Hover Lists","Define category styles for standard and pinterest portfolio lists.");
    $panel1->addChild("group10",$group10);

        $row1 = new QodePitchRow();
        $group10->addChild("row1",$row1);
            $portfolio_category_hover_box_list_color = new QodePitchField("colorsimple","portfolio_category_hover_box_list_color","","Text Color","This is some description");
            $row1->addChild("portfolio_category_hover_box_list_color",$portfolio_category_hover_box_list_color);
            $portfolio_category_hover_box_list_font_size = new QodePitchField("textsimple","portfolio_category_hover_box_list_font_size","","Font Size (px)","This is some description");
            $row1->addChild("portfolio_category_hover_box_list_font_size",$portfolio_category_hover_box_list_font_size);
            $portfolio_category_hover_box_list_line_height = new QodePitchField("textsimple","portfolio_category_hover_box_list_line_height","","Line Height (px)","This is some description");
            $row1->addChild("portfolio_category_hover_box_list_line_height",$portfolio_category_hover_box_list_line_height);
            $portfolio_category_hover_box_list_text_transform = new QodePitchField("selectblanksimple","portfolio_category_hover_box_list_text_transform","","Text Transform","This is some description",$qode_pitch_options_texttransform);
            $row1->addChild("portfolio_category_hover_box_list_text_transform",$portfolio_category_hover_box_list_text_transform);

        $row2 = new QodePitchRow(true);
        $group10->addChild("row2",$row2);
            $portfolio_category_hover_box_list_font_family = new QodePitchField("fontsimple","portfolio_category_hover_box_list_font_family","-1","Font Family","This is some description");
            $row2->addChild("portfolio_category_hover_box_list_font_family",$portfolio_category_hover_box_list_font_family);
            $portfolio_category_hover_box_list_font_style = new QodePitchField("selectblanksimple","portfolio_category_hover_box_list_font_style","","Font Style","This is some description",$qode_pitch_options_fontstyle);
            $row2->addChild("portfolio_category_hover_box_list_font_style",$portfolio_category_hover_box_list_font_style);
            $portfolio_category_hover_box_list_font_weight = new QodePitchField("selectblanksimple","portfolio_category_hover_box_list_font_weight","","Font Weight","This is some description",$qode_pitch_options_fontweight);
            $row2->addChild("portfolio_category_hover_box_list_font_weight",$portfolio_category_hover_box_list_font_weight);
            $portfolio_category_hover_box_list_letter_spacing = new QodePitchField("textsimple","portfolio_category_hover_box_list_letter_spacing","","Letter Spacing (px)","This is some description");
            $row2->addChild("portfolio_category_hover_box_list_letter_spacing",$portfolio_category_hover_box_list_letter_spacing);



    $group12 = new QodePitchGroup("Category Style for Portfolio Slider and Masonry Lists","Define category styles for slider and masonry portfolio lists.");
    $panel1->addChild("group12",$group12);

        $row1 = new QodePitchRow();
        $group12->addChild("row1",$row1);
            $portfolio_category_list_color = new QodePitchField("colorsimple","portfolio_category_list_color","","Text Color","This is some description");
            $row1->addChild("portfolio_category_list_color",$portfolio_category_list_color);
            $portfolio_category_list_font_size = new QodePitchField("textsimple","portfolio_category_list_font_size","","Font Size (px)","This is some description");
            $row1->addChild("portfolio_category_list_font_size",$portfolio_category_list_font_size);
            $portfolio_category_list_line_height = new QodePitchField("textsimple","portfolio_category_list_line_height","","Line Height (px)","This is some description");
            $row1->addChild("portfolio_category_list_line_height",$portfolio_category_list_line_height);
            $portfolio_category_list_text_transform = new QodePitchField("selectblanksimple","portfolio_category_list_text_transform","","Text Transform","This is some description",$qode_pitch_options_texttransform);
            $row1->addChild("portfolio_category_list_text_transform",$portfolio_category_list_text_transform);

        $row2 = new QodePitchRow(true);
        $group12->addChild("row2",$row2);
            $portfolio_category_list_font_family = new QodePitchField("fontsimple","portfolio_category_list_font_family","-1","Font Family","This is some description");
            $row2->addChild("portfolio_category_list_font_family",$portfolio_category_list_font_family);
            $portfolio_category_list_font_style = new QodePitchField("selectblanksimple","portfolio_category_list_font_style","","Font Style","This is some description",$qode_pitch_options_fontstyle);
            $row2->addChild("portfolio_category_list_font_style",$portfolio_category_list_font_style);
            $portfolio_category_list_font_weight = new QodePitchField("selectblanksimple","portfolio_category_list_font_weight","","Font Weight","This is some description",$qode_pitch_options_fontweight);
            $row2->addChild("portfolio_category_list_font_weight",$portfolio_category_list_font_weight);
            $portfolio_category_list_letter_spacing = new QodePitchField("textsimple","portfolio_category_list_letter_spacing","","Letter Spacing (px)","This is some description");
            $row2->addChild("portfolio_category_list_letter_spacing",$portfolio_category_list_letter_spacing);


// Portfolio Filter
    $portfolio_filter = new QodePitchTitle("portfolio_filter","Category Filter");
    $panel1->addChild("portfolio_filter",$portfolio_filter);

    $portfolio_list_filter_background_color = new QodePitchField("color","portfolio_list_filter_background_color","","Background Color","Choose color for background of filter area",array(), array("col_width" => 3));
    $panel1->addChild("portfolio_list_filter_background_color",$portfolio_list_filter_background_color);

    $portfolio_list_filter_height = new QodePitchField("text","portfolio_list_filter_height","","Height (px)","Enter height for filter area",array(), array("col_width" => 3));
    $panel1->addChild("portfolio_list_filter_height",$portfolio_list_filter_height);

    $portfolio_filter_margin_bottom = new QodePitchField("text","portfolio_filter_margin_bottom","","Bottom Margin (px)","Enter bottom margin for filter area. Default value is 36",array(), array("col_width" => 3));
    $panel1->addChild("portfolio_filter_margin_bottom",$portfolio_filter_margin_bottom);

        $group2 = new QodePitchGroup("Title","Define text styles for filter title");
        $panel1->addChild("group2",$group2);

            $row1 = new QodePitchRow();
            $group2->addChild("row1",$row1);
                $portfolio_filter_title_color = new QodePitchField("colorsimple","portfolio_filter_title_color","","Text Color","This is some description");
                $row1->addChild("portfolio_filter_title_color",$portfolio_filter_title_color);
                $portfolio_filter_title_font_size = new QodePitchField("textsimple","portfolio_filter_title_font_size","","Font Size (px)","This is some description");
                $row1->addChild("portfolio_filter_title_font_size",$portfolio_filter_title_font_size);
                $portfolio_filter_title_line_height = new QodePitchField("textsimple","portfolio_filter_title_line_height","","Line Height (px)","This is some description");
                $row1->addChild("portfolio_filter_title_line_height",$portfolio_filter_title_line_height);
                $portfolio_filter_title_text_transform = new QodePitchField("selectblanksimple","portfolio_filter_title_text_transform","","Text Transform","This is some description",$qode_pitch_options_texttransform);
                $row1->addChild("portfolio_filter_title_text_transform",$portfolio_filter_title_text_transform);

                $row2 = new QodePitchRow(true);
                $group2->addChild("row2",$row2);
                $portfolio_filter_title_font_family = new QodePitchField("fontsimple","portfolio_filter_title_font_family","-1","Font Family","This is some description");
                $row2->addChild("portfolio_filter_title_font_family",$portfolio_filter_title_font_family);
                $portfolio_filter_title_font_style = new QodePitchField("selectblanksimple","portfolio_filter_title_font_style","","Font Style","This is some description",$qode_pitch_options_fontstyle);
                $row2->addChild("portfolio_filter_title_font_style",$portfolio_filter_title_font_style);
                $portfolio_filter_title_font_weight = new QodePitchField("selectblanksimple","portfolio_filter_title_font_weight","","Font Weight","This is some description",$qode_pitch_options_fontweight);
                $row2->addChild("portfolio_filter_title_font_weight",$portfolio_filter_title_font_weight);
                $portfolio_filter_title_letter_spacing = new QodePitchField("textsimple","portfolio_filter_title_letter_spacing","","Letter Spacing (px)","This is some description");
                $row2->addChild("portfolio_filter_title_letter_spacing",$portfolio_filter_title_letter_spacing);

        $group3 = new QodePitchGroup("Categories","Define text styles for filter categories");
        $panel1->addChild("group3",$group3);

            $row1 = new QodePitchRow();
            $group3->addChild("row1",$row1);
            $portfolio_filter_color = new QodePitchField("colorsimple","portfolio_filter_color","","Text Color","This is some description");
            $row1->addChild("portfolio_filter_color",$portfolio_filter_color);
            $portfolio_filter_hovercolor = new QodePitchField("colorsimple","portfolio_filter_hovercolor","","Hover/Active Color","This is some description");
            $row1->addChild("portfolio_filter_hovercolor",$portfolio_filter_hovercolor);
            $portfolio_filter_font_size = new QodePitchField("textsimple","portfolio_filter_font_size","","Font Size (px)","This is some description");
            $row1->addChild("portfolio_filter_font_size",$portfolio_filter_font_size);
            $portfolio_filter_line_height = new QodePitchField("textsimple","portfolio_filter_line_height","","Line Height (px)","This is some description");
            $row1->addChild("portfolio_filter_line_height",$portfolio_filter_line_height);

            $row2 = new QodePitchRow(true);
            $group3->addChild("row2",$row2);
            $portfolio_filter_font_family = new QodePitchField("fontsimple","portfolio_filter_font_family","-1","Font Family","This is some description");
            $row2->addChild("portfolio_filter_font_family",$portfolio_filter_font_family);
            $portfolio_filter_font_style = new QodePitchField("selectblanksimple","portfolio_filter_font_style","","Font Style","This is some description",$qode_pitch_options_fontstyle);
            $row2->addChild("portfolio_filter_font_style",$portfolio_filter_font_style);
            $portfolio_filter_font_weight = new QodePitchField("selectblanksimple","portfolio_filter_font_weight","","Font Weight","This is some description",$qode_pitch_options_fontweight);
            $row2->addChild("portfolio_filter_font_weight",$portfolio_filter_font_weight);
            $portfolio_filter_text_transform = new QodePitchField("selectblanksimple","portfolio_filter_text_transform","","Text Transform","This is some description",$qode_pitch_options_texttransform);
            $row2->addChild("portfolio_filter_text_transform",$portfolio_filter_text_transform);

            $row3 = new QodePitchRow(true);
            $group3->addChild("row3",$row3);
            $portfolio_filter_letter_spacing = new QodePitchField("textsimple","portfolio_filter_letter_spacing","","Letter Spacing (px)","This is some description");
            $row3->addChild("portfolio_filter_letter_spacing",$portfolio_filter_letter_spacing);

    $portfolio_filter_disable_separator = new QodePitchField("yesno","portfolio_filter_disable_separator","yes","Disable Separator Between Categories","Disabling this option will remove separator between filter categories.",array(),array(
        "dependence" => true,
        "dependence_hide_on_yes" => "#qodef_portfolio_filter_separator_container",
        "dependence_show_on_yes" => "",
        ));
    $panel1->addChild("portfolio_filter_disable_separator",$portfolio_filter_disable_separator);

    $portfolio_filter_separator_container = new QodePitchContainer("portfolio_filter_separator_container","portfolio_filter_disable_separator","yes");
    $panel1->addChild("portfolio_filter_separator_container",$portfolio_filter_separator_container);

        $portfolio_filter_separator_color = new QodePitchField("color","portfolio_filter_separator_color","","Separator Between Categories Color","Choose a color for separator between categories in filter");
        $portfolio_filter_separator_container->addChild("portfolio_filter_separator_color",$portfolio_filter_separator_color);


//ICONS STYLE
    $icons_style = new QodePitchTitle("icons_style", "Icons");
    $panel1->addChild("icons_style", $icons_style);

    $portfolio_list_icons_pack = new QodePitchField("select","portfolio_list_icons_pack","font-awesome","Font Family",'Choose font family for hover icons on portfolio', array(
        "font-awesome" => "Font Awesome",
        "font-elegant" => "Font Elegant"
    ));
    $panel1->addChild("portfolio_list_icons_pack",$portfolio_list_icons_pack);

    $group25 = new QodePitchGroup("Size","Enter size for icons in portfolio list ");
    $panel1->addChild("group25",$group25);

        $row1 = new QodePitchRow(true);
        $group25->addChild("row1",$row1);

            $portfolio_list_icons_size = new QodePitchField("textsimple","portfolio_list_icons_size","","Icon Size (px)","");
            $row1->addChild("portfolio_list_icons_size",$portfolio_list_icons_size);

            $portfolio_list_icons_shape_size = new QodePitchField("textsimple","portfolio_list_icons_shape_size","","Shape Size (px)","");
            $row1->addChild("portfolio_list_icons_shape_size",$portfolio_list_icons_shape_size);

	$group4 = new QodePitchGroup("Color","Choose color of the icons on project hover");
	$panel1->addChild("group4",$group4);

		$row1 = new QodePitchRow();
		$group4->addChild("row1",$row1);
			$portfolio_list_icons_color = new QodePitchField("colorsimple","portfolio_list_icons_color","","Color","This is some description");
			$row1->addChild("portfolio_list_icons_color",$portfolio_list_icons_color);
			$portfolio_list_icons_hover_color = new QodePitchField("colorsimple","portfolio_list_icons_hover_color","","Hover Color","This is some description");
			$row1->addChild("portfolio_list_icons_hover_color",$portfolio_list_icons_hover_color);

    $group5 = new QodePitchGroup("Background Color","Define icons background color styles on project hover");
    $panel1->addChild("group5",$group5);

        $row1 = new QodePitchRow();
        $group5->addChild("row1",$row1);
			$portfolio_list_icons_background_color = new QodePitchField("colorsimple","portfolio_list_icons_background_color","","Background Color","This is some description");
			$row1->addChild("portfolio_list_icons_background_color",$portfolio_list_icons_background_color);
			$portfolio_list_icons_background_hover_color = new QodePitchField("colorsimple","portfolio_list_icons_background_hover_color","","Background Hover Color","This is some description");
			$row1->addChild("portfolio_list_icons_background_hover_color",$portfolio_list_icons_background_hover_color);

    $group6 = new QodePitchGroup("Border","Define icons border styles on project hover");
    $panel1->addChild("group6",$group6);

		$row1 = new QodePitchRow(true);
		$group6->addChild("row1",$row1);

			$portfolio_list_icons_border_color = new QodePitchField("colorsimple","portfolio_list_icons_border_color","","Border Color","This is some description");
			$row1->addChild("portfolio_list_icons_border_color",$portfolio_list_icons_border_color);
			$portfolio_list_icons_border_hover_color = new QodePitchField("colorsimple","portfolio_list_icons_border_hover_color","","Border Hover Color","This is some description");
			$row1->addChild("portfolio_list_icons_border_hover_color",$portfolio_list_icons_border_hover_color);
			$portfolio_list_icons_border_width = new QodePitchField("textsimple","portfolio_list_icons_border_width","","Border Width (px)","This is some description");
			$row1->addChild("portfolio_list_icons_border_width",$portfolio_list_icons_border_width);
            $portfolio_list_icons_border_radius = new QodePitchField("textsimple","portfolio_list_icons_border_radius","","Border Radius (px)","This is some description");
            $row1->addChild("portfolio_list_icons_border_radius",$portfolio_list_icons_border_radius);

    $portfolio_pinterest_style = new QodePitchTitle("portfolio_pinterest_style", "Pinterest");
    $panel1->addChild("portfolio_pinterest_style", $portfolio_pinterest_style);

    $group24 = new QodePitchGroup("Pinterest Padding","Define pinterest padding");
    $panel1->addChild("group24",$group24);

        $row1 = new QodePitchRow(true);
        $group24->addChild("row1",$row1);

        $pinterest_padding_left = new QodePitchField("textsimple","pinterest_padding_left","","Padding Left (px)","This is some description");
        $row1->addChild("pinterest_padding_left",$pinterest_padding_left);

        $pinterest_padding_right = new QodePitchField("textsimple","pinterest_padding_right","","Padding Right (px)","This is some description");
        $row1->addChild("pinterest_padding_right",$pinterest_padding_right);

        $pinterest_padding_top = new QodePitchField("textsimple","pinterest_padding_top","","Padding Top (px)","This is some description");
        $row1->addChild("pinterest_padding_top",$pinterest_padding_top);

        $pinterest_padding_bottom = new QodePitchField("textsimple","pinterest_padding_bottom","","Padding Bottom (px)","This is some description");
        $row1->addChild("pinterest_padding_bottom",$pinterest_padding_bottom);

    $portfolio_masonry_style = new QodePitchTitle("portfolio_masonry_style", "Masonry");
    $panel1->addChild("portfolio_masonry_style", $portfolio_masonry_style);

    $portfolio_masonry_with_padding_width = new QodePitchField("text","portfolio_masonry_with_padding_width","","Space Width (px)","Enter space width for Masonry if space is enabled. Default value is 10",array(), array("col_width" => 3));
    $panel1->addChild("portfolio_masonry_with_padding_width",$portfolio_masonry_with_padding_width);

    $thin_plus_only_style = new QodePitchTitle("thin_plus_only_style", "Thin Plus Only");
    $panel1->addChild("thin_plus_only_style", $thin_plus_only_style);

    $group13 = new QodePitchGroup("Cursor","Define styles for Cursor on Thin Plus Only hover type");
    $panel1->addChild("group13",$group13);

        $row1 = new QodePitchRow();
        $group13->addChild("row1",$row1);
            $thin_plus_only_style_color = new QodePitchField("colorsimple","thin_plus_only_style_color","","Color","This is some description");
            $row1->addChild("thin_plus_only_style_color",$thin_plus_only_style_color);
            $thin_plus_only_style_size = new QodePitchField("textsimple","thin_plus_only_style_size","","Font Size (px)","This is some description");
            $row1->addChild("thin_plus_only_style_size",$thin_plus_only_style_size);
            $thin_plus_only_style_weight = new QodePitchField("selectblanksimple","thin_plus_only_style_weight","","Font Weight","This is some description",$qode_pitch_options_fontweight);
            $row1->addChild("thin_plus_only_style_weight",$thin_plus_only_style_weight);

    $animated_border_hover_style = new QodePitchTitle("animated_border_hover_style", "Animated Border");
    $panel1->addChild("animated_border_hover_style", $animated_border_hover_style);

    $group23 = new QodePitchGroup("Border Hover","Define styles for border on Animated Border hover type");
    $panel1->addChild("group23",$group23);

        $row1 = new QodePitchRow();
        $group23->addChild("row1",$row1);
            $animated_border_hover_color = new QodePitchField("colorsimple","animated_border_hover_color","","Color","This is some description");
            $row1->addChild("animated_border_hover_color",$animated_border_hover_color);
            $animated_border_hover_width = new QodePitchField("textsimple","animated_border_hover_width","","Width (px)","This is some description");
            $row1->addChild("animated_border_hover_width",$animated_border_hover_width);

    $animated_border_disable_animation = new QodePitchField("yesno","animated_border_disable_animation","no","Disable Animation","Enabling this option will turn off border animation on hover");
    $panel1->addChild("animated_border_disable_animation",$animated_border_disable_animation);

//Portfolio Single Project

$panel2 = new QodePitchPanel("Portfolio Single", "porfolio_single_project");
$portfolioPage->addChild("panel2",$panel2);

	$portfolio_style = new QodePitchField("select","portfolio_style","floating-right","Portfolio Type",'Choose a default type for Single Project pages', array(
		"floating-right" => "Portfolio text floating right",
		"floating-left" => "Portfolio text floating left",
		"fixed-right" => "Portfolio text fixed right",
		"fixed-left" => "Portfolio text fixed left",
		"big-slider" => "Portfolio big slider",
		"custom" => "Portfolio custom",
		"central" => "Portfolio central",
		"gallery" => "Portfolio gallery",
		"gallery-right" => "Portfolio gallery right",
		"masonry-gallery-top" => "Portfolio masonry gallery top",
		"masonry-gallery-bottom" => "Portfolio masonry gallery bottom",
		"masonry-gallery-right" => "Portfolio masonry gallery right"
      ));
	$panel2->addChild("portfolio_style",$portfolio_style);
	
	$portfolio_enable_animation= new QodePitchField("selectblank","portfolio_enable_animation","","Enable Loading Animation for Images","", array(
		"yes" => "Yes",
		"no" => "No"
	));
    $panel2->addChild("portfolio_enable_animation",$portfolio_enable_animation);

    $group3 = new QodePitchGroup("Portfolio Overlay Color","Define color and opacity for overlay color");
    $panel2->addChild("group3",$group3);

        $row1 = new QodePitchRow();
        $group3->addChild("row1",$row1);

            $portfolio_gallery_overlay_color = new QodePitchField("colorsimple","portfolio_gallery_overlay_color","","Color","This is some description");
            $row1->addChild("portfolio_gallery_overlay_color",$portfolio_gallery_overlay_color);

            $portfolio_gallery_overlay_transparency = new QodePitchField("textsimple","portfolio_gallery_overlay_transparency","","Transparency (px)","This is some description");
            $row1->addChild("portfolio_gallery_overlay_transparency",$portfolio_gallery_overlay_transparency);


    $portfolio_gallery_image_hover_style = new QodePitchField("select","portfolio_gallery_image_hover_style","magnifier","Portfolio Image Hover",'Choose a default hover type for Single Project pages', array(
        "disable" => "None",
        "magnifier" => "Magnifier",
        "icon" => "Icon",
        "text" => "Image Title"
    ),
        array("dependence" => true,
            "hide" => array(
                "disable"=>"#qodef_portfolio_gallery_image_hover_separator_container,#qodef_portfolio_gallery_image_hover_icon_container",
                "magnifier"=>"#qodef_portfolio_gallery_image_hover_separator_container,#qodef_portfolio_gallery_image_hover_icon_container",
                "icon"=>"#qodef_portfolio_gallery_image_hover_separator_container",
                "text"=>"#qodef_portfolio_gallery_image_hover_icon_container"),
            "show" => array(
                "disable"=>"",
                "magnifier"=>"",
                "icon"=>"#qodef_portfolio_gallery_image_hover_icon_container",
                "text"=>"#qodef_portfolio_gallery_image_hover_separator_container")
        ));
    $panel2->addChild("portfolio_gallery_image_hover_style",$portfolio_gallery_image_hover_style);

        $portfolio_gallery_image_hover_separator_container = new QodePitchContainer("portfolio_gallery_image_hover_separator_container","portfolio_gallery_image_hover_style","magnifier",array("disable","magnifier","icon"));
        $panel2->addChild("portfolio_gallery_image_hover_separator_container",$portfolio_gallery_image_hover_separator_container);

            $portfolio_gallery_image_hover_separator = new QodePitchField("select","portfolio_gallery_image_hover_separator","","Separator below image title","This option will place separator below text", array(
                "yes" => "Yes",
                "no" => "No"
            ), array("col_width" => 3));
            $portfolio_gallery_image_hover_separator_container->addChild("portfolio_gallery_image_hover_separator",$portfolio_gallery_image_hover_separator);

            $portfolio_gallery_overlay_text_color = new QodePitchField("color","portfolio_gallery_overlay_text_color","","Text Color","Choose a color for overlay text in Single Project pages");
            $portfolio_gallery_image_hover_separator_container->addChild("portfolio_gallery_overlay_text_color",$portfolio_gallery_overlay_text_color);

        $portfolio_gallery_image_hover_icon_container = new QodePitchContainer("portfolio_gallery_image_hover_icon_container","portfolio_gallery_image_hover_style","magnifier",array("disable","magnifier","text"));
        $panel2->addChild("portfolio_gallery_image_hover_icon_container",$portfolio_gallery_image_hover_icon_container);

            $group4 = new QodePitchGroup("Portfolio Image Hover Icon","Define style for Portfolio Image Hover Icon");
            $portfolio_gallery_image_hover_icon_container->addChild("group4",$group4);

            $row1 = new QodePitchRow();
            $group4->addChild("row1",$row1);

                $portfolio_gallery_icon_pack = new QodePitchField("selectsimple","portfolio_gallery_icon_pack","font-awesome","Font Family",'This is some description', array(
                    "font-awesome" => "Font Awesome",
                    "font-elegant" => "Font Elegant"
                ));
                $group4->addChild("portfolio_gallery_icon_pack",$portfolio_gallery_icon_pack);

                    $portfolio_gallery_icon_size = new QodePitchField("textsimple","portfolio_gallery_icon_size","","Size","This is some description");
                $group4->addChild("portfolio_gallery_icon_size",$portfolio_gallery_icon_size);

                $portfolio_gallery_icon_color = new QodePitchField("colorsimple","portfolio_gallery_icon_color","","Color","This is some description");
                $group4->addChild("portfolio_gallery_icon_color",$portfolio_gallery_icon_color);

    $group1 = new QodePitchGroup("Title Style","Define title styles on project.");
    $panel2->addChild("group1",$group1);

        $row1 = new QodePitchRow();
        $group1->addChild("row1",$row1);

            $portfolio_title_tag = new QodePitchField("selectsimple","portfolio_title_tag","h3","Tag element",'This is some description', array(
                "h2" => "h2",
                "h3" => "h3",
                "h4" => "h4",
                "h5" => "h5"
            ));
            $row1->addChild("portfolio_title_tag",$portfolio_title_tag);

            $portfolio_title_margin_bottom = new QodePitchField("textsimple","portfolio_title_margin_bottom","","Margin Bottom (px)","This is some description");
            $row1->addChild("portfolio_title_margin_bottom",$portfolio_title_margin_bottom);

            $portfolio_title_color = new QodePitchField("colorsimple","portfolio_title_color","","Text Color","This is some description");
            $row1->addChild("portfolio_title_color",$portfolio_title_color);

    $portfolio_title_hidden_in_info = new QodePitchField("yesno","portfolio_title_hidden_in_info","yes","Hide Title in Info","Enabling this option will hide title in portfolio info section.");
    $panel2->addChild("portfolio_title_hidden_in_info",$portfolio_title_hidden_in_info);

    $group2 = new QodePitchGroup("Additional Portfolio Titles","Define additional portfolio titles styles on project.");
    $panel2->addChild("group2",$group2);

        $row1 = new QodePitchRow();
        $group2->addChild("row1",$row1);

            $portfolio_info_tag = new QodePitchField("selectsimple","portfolio_info_tag","h6","Tag element",'This is some description', array(
                "h4" => "h4",
                "h5" => "h5",
                "h6" => "h6"
            ));
            $row1->addChild("portfolio_info_tag",$portfolio_info_tag);

            $portfolio_info_margin_bottom = new QodePitchField("textsimple","portfolio_info_margin_bottom","","Margin Bottom (px)","This is some description");
            $row1->addChild("portfolio_info_margin_bottom",$portfolio_info_margin_bottom);

            $portfolio_info_color = new QodePitchField("colorsimple","portfolio_info_color","","Text Color","This is some description");
            $row1->addChild("portfolio_info_color",$portfolio_info_color);

	$lightbox_single_project = new QodePitchField("yesno","lightbox_single_project","yes","Lightbox for Images","Enabling this option will turn on lightbox functionality for projects with images.");
	$panel2->addChild("lightbox_single_project",$lightbox_single_project);

	$lightbox_video_single_project = new QodePitchField("yesno","lightbox_video_single_project","no","Lightbox for Videos","Enabling this option will turn on lightbox functionality for YouTube/Vimeo projects.");
	$panel2->addChild("lightbox_video_single_project",$lightbox_video_single_project);

	$portfolio_hide_categories = new QodePitchField("yesno","portfolio_hide_categories","no","Hide Categories","Enabling this option will disable category meta description on Single Projects.");
	$panel2->addChild("portfolio_hide_categories",$portfolio_hide_categories);

	$portfolio_hide_date = new QodePitchField("yesno","portfolio_hide_date","no","Hide Date","Enabling this option will disable date meta on Single Projects.");
	$panel2->addChild("portfolio_hide_date",$portfolio_hide_date);

	$portfolio_hide_comments = new QodePitchField("yesno","portfolio_hide_comments","yes","Hide Comments","Enabling this option will turn off comments functionality.");
	$panel2->addChild("portfolio_hide_comments",$portfolio_hide_comments);

	$portfolio_text_follow = new QodePitchField("portfoliofollow","portfolio_text_follow","portfolio_single_follow","Sticky Side Text ","Enabling this option will make side text sticky on Single Project pages");
	$panel2->addChild("portfolio_text_follow",$portfolio_text_follow);

    $portfolio_related_projects = new QodePitchField("yesno","portfolio_related_projects","yes","Portfolio Related Projects ","Enabling this option will display related projects on Single Project pages");
    $panel2->addChild("portfolio_related_projects",$portfolio_related_projects);

	$portfolio_hide_pagination = new QodePitchField("yesno","portfolio_hide_pagination","no","Hide Pagination","Enabling this option will turn off portfolio pagination functionality.", array(), array("dependence" => true, "dependence_hide_on_yes" => "#qodef_portfolio_hide_pagination_container", "dependence_show_on_yes" => ""));
	$panel2->addChild("portfolio_hide_pagination",$portfolio_hide_pagination);

	$portfolio_hide_pagination_container = new QodePitchContainer("portfolio_hide_pagination_container","portfolio_hide_pagination","yes");
	$panel2->addChild("portfolio_hide_pagination_container",$portfolio_hide_pagination_container);

		$portfolio_navigation_through_same_category = new QodePitchField("yesno","portfolio_navigation_through_same_category","no","Enable Pagination Through Same Category","Enabling this option will make portfolio pagination sort through current category.");
		$portfolio_hide_pagination_container->addChild("portfolio_navigation_through_same_category",$portfolio_navigation_through_same_category);


    $portfolio_box = new QodePitchField("yesno","portfolio_box","yes","Enable Box Holder","Enabling this option will place box holder on project. This option works only if Portfolio style is Big Images, Big Slider or Gallery", array(), array("dependence" => true, "dependence_hide_on_yes" => "#qodef_portfolio_without_box_container", "dependence_show_on_yes" => "#qodef_portfolio_box_container"));
    $panel2->addChild("portfolio_box",$portfolio_box);

    $portfolio_box_container = new QodePitchContainer("portfolio_box_container","portfolio_box","no");
    $panel2->addChild("portfolio_box_container",$portfolio_box_container);

        $portfolio_box_background_color = new QodePitchField("color","portfolio_box_background_color","","Background Color","Default color is #ffffff");
        $portfolio_box_container->addChild("portfolio_box_background_color",$portfolio_box_background_color);

        $portfolio_box_lr_padding = new QodePitchField("text","portfolio_box_lr_padding","","Padding(px)","Format: 10px 5px 10px 8px (Default value is 46px 26px 45px 26px)", array(), array("col_width" => 3));
        $portfolio_box_container->addChild("portfolio_box_lr_padding",$portfolio_box_lr_padding);

    $portfolio_without_box_container = new QodePitchContainer("portfolio_without_box_container","portfolio_box","yes");
    $panel2->addChild("portfolio_without_box_container",$portfolio_without_box_container);

        $portfolio_box_top_padding = new QodePitchField("text","portfolio_box_top_padding","","Top Padding(px)","Default value is 46", array(), array("col_width" => 3));
        $portfolio_without_box_container->addChild("portfolio_box_top_padding",$portfolio_box_top_padding);

	$portfolio_columns_number = new QodePitchField("select","portfolio_columns_number","4","Number of Columns",'Enter the number of columns for Portfolio Gallery type', array( "2" => "2 columns",
       "3" => "3 columns",
       "4" => "4 columns"
      ));
	$panel2->addChild("portfolio_columns_number",$portfolio_columns_number);

	$portfolio_single_slug = new QodePitchField("text","portfolio_single_slug","","Portfolio Single Slug",'Enter if you wish to use a different Single Project slug (Note: After entering slug, navigate to Settings -> Permalinks and click "Save" in order for changes to take effect) ', array(), array("col_width" => 3));
	$panel2->addChild("portfolio_single_slug",$portfolio_single_slug);

  