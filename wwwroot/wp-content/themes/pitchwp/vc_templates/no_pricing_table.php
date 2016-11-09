<?php

$args = array(
    "type"                         => "price_on_top",
    "title"         			   => "",
    "title_color"                  => "",
    "small_title"                  => "",
    "title_font_family"			   => "",
    "title_background_color"       => "",
    "title_background_image"       => "",
    "title_alignment"              => "left",
    "price"         			   => "100",
    "price_color"         		   => "",
    "price_font_weight"       	   => "",
    "price_bckg_image"			   => "",
    "price_background"  	       => "",
	"price_border_bottom"		   => "yes",
	"price_border_bottom_color"    => "",
    "currency"      			   => "$",
    "price_period"  			   => "Monthly",
	"price_period_position"  	   => "",	
    "link"          			   => "",
    "target"        		       => "_self",
    "button_text"   			   => "button",
    "button_font_size"   		   => "",
    "button_size"   			   => "",
	"button_font_family"		   => "",
    "button_color"                 => "",
    "button_hover_color"           => "",
    "button_background_color"      => "",
    "button_background_image"      => "",
	"content_style"				   => "pricing_content_grid",
	"different_odd_even_sections"  => "no",
	"even_back_color"			   => "",
	"odd_back_color"			   => "",
	"content_background_color"	   => "",
	"content_background_image"	   => "",
    "active"        			   => "",
	"active_style"        		   => "",
    "active_text"   			   => "Best choice",
    "active_text_color"            => "",
    "active_text_background_color" => "",
	"content_text_color"		   => "",
	"title_separator"			   => "",
	"title_separator_color"		   => "",
    "title_border_bottom"          => "yes",
	"title_border_bottom_style"	   => "pricing_title_grid",
    "title_border_bottom_color"    => "",
    "table_border_top"             => "yes", 
    "pricing_table_border_top_color" => "",
    "button_arrow"                   => "no",
	"disable_button_border_top"		 => "",
    "border_arround"                 => "no",
    "border_arround_color"           => "",
	"show_button"					 => "yes",
	"pricing_button_type"			 => "",
	"button_icon_size"				 => ""	
	
);

extract(shortcode_atts($args, $atts));

$html						= "";
$pricing_table_clasess		= '';
$pricing_content_clasess	= '';
$pricing_table_background 	= '';
$pricing_table_background_image	='';
$price_style_array			= array();
$price_style				= array();
$price_currency_style       = '';
$title_style                = "";
$title_top_type_title_style          = array();
$pricing_table_border_top_style      = array();
$active_holder_style_array  = array();
$active_holder_style        = "";
$active_text_style_array    = array();
$active_text_style          = "";
$title_holder_style         = "";
$button_style               = "";
$button_on_bottom_style     = array();
$button_class               = "";
$button_holder_style        = "";
$content_text_style			= "";
$title_separator_style		= "";
$title_clasess				= "";
$active_text_position       = "";
$border_arround_style       = array();
$price_background_style     = '';
$price_border_style			= '';
$data_attr					= '';
$data_attr_button			= '';

$title = esc_html($title);
$title_color = esc_attr($title_color);
$small_title = esc_html($small_title);
$title_font_family = esc_attr($title_font_family);
$title_background_color = esc_attr($title_background_color);
$price = esc_attr($price);
$price_background = esc_attr($price_background);
$price_border_bottom = esc_attr($price_border_bottom);
$price_border_bottom_color = esc_attr($price_border_bottom_color);
$currency = esc_attr($currency);
$price_period = esc_attr($price_period);
$price_period_position = esc_attr($price_period_position);
$link = esc_url($link);
$button_text = esc_html($button_text);
$button_color = esc_attr($button_color);
$button_font_family = esc_attr($button_font_family);
$disable_button_border_top = esc_attr($disable_button_border_top);
$button_background_color = esc_attr($button_background_color);
$content_style = esc_attr($content_style);
$content_background_color = esc_attr($content_background_color);
$different_odd_even_sections = esc_attr($different_odd_even_sections);
$even_back_color = esc_attr($even_back_color);
$odd_back_color = esc_attr($odd_back_color);
$active_style = esc_html($active_style);
$active_text = esc_html($active_text);
$active_text_color = esc_attr($active_text_color);
$active_text_background_color = esc_attr($active_text_background_color);
$content_text_color = esc_attr($content_text_color);
$title_separator_color = esc_attr($title_separator_color);
$title_border_bottom_style = esc_attr($title_border_bottom_style);
$title_border_bottom_color = esc_attr($title_border_bottom_color);
$pricing_table_border_top_color = esc_attr($pricing_table_border_top_color);
$border_arround_color = esc_attr($border_arround_color);
$show_button = esc_attr($show_button);
$pricing_button_type = esc_attr($pricing_button_type);
$button_icon_size	= esc_attr($button_icon_size);


if($target == ""){
    $target = "_self";
}

if($type == "price_on_top") {
    $pricing_table_clasess .= ' price_on_top';
}

if($type == "title_on_top") {
    $pricing_table_clasess .= ' title_on_top';

    if($title_border_bottom == "no"){
        $pricing_table_clasess .= ' title_top_padding_and_border';
    }
}

if($type == "price_on_top"){
	if($price_period_position == "next_to_title"){
	$pricing_table_clasess .= '  price_period_next_to_title';
	}
	elseif($price_period_position == "bellow_title"){
		$pricing_table_clasess .= '  price_period_bellow_title';
	}
}

if($active == "yes") {
    $pricing_table_clasess .= ' active';
	
	if($active_style == "circle" && $active == "yes"){
		$pricing_table_clasess .= ' active_circle';
	}
	elseif($active_style == "rectangle" && $active == "yes"){
		$pricing_table_clasess .= ' active_rectangle';
	}
}

if($title_separator == "yes") {
    $title_clasess .= ' active_small_separator';
}
if($title_border_bottom_style != "") {
    $title_clasess .= ' '.$title_border_bottom_style;
}
if($small_title != "") {
    $title_clasess .= ' has_small_title';
}
if($title_alignment != '') {
    $title_clasess .= ' ' . $title_alignment;
}

if($active_text_color !== '') {
    $active_text_style_array[] = 'color: '.$active_text_color;
}

if(is_array($active_text_style_array) && count($active_text_style_array)) {
    $active_text_style = 'style="'.implode(';', $active_text_style_array).'"';
} else {
    $active_text_style = '';
}

if($active_text_background_color !== '') {
    $active_holder_style_array[] = 'background-color: '.$active_text_background_color;
}

if(is_array($active_holder_style_array) && count($active_holder_style_array)) {
    $active_holder_style = 'style="'.implode(';', $active_holder_style_array).'"';
} else {
    $active_holder_style = '';
}

if($price_bckg_image !== "") {
	if (is_numeric($price_bckg_image)){
		$price_background_image = wp_get_attachment_url($price_bckg_image);
	}
	else {
		$price_background_image = esc_url($price_bckg_image);
	}
	$price_background_style .=  'background-image: url('.$price_background_image.');';
	$price_background_style .=  'background-position: center; background-repeat: no-repeat;';
}

if($price_background !== "") {
    $price_background_style .=  'background-color: '.$price_background.';';
}
if($price_border_bottom == "yes"){
	if($price_border_bottom_color != ""){
		$price_border_style .= "border-bottom-color: ".$price_border_bottom_color.";";
	}
}else{
	$price_border_style .= "border-bottom: 0;";
}

if($price_font_weight !== '') {
	$price_style_array[] = 'font-weight: '.$price_font_weight;
}

if($price_color !== '') {
    $price_style_array[] = 'color: '.$price_color;
    $price_currency_style = 'color: '.$price_color;
}

if ($show_button== "yes" && $button_size == "normal") {
    $button_class .= "normal";
}

if ($show_button== "yes" && $pricing_button_type == "button_on_bottom") {
    $button_class .= " button_on_bottom";
}
if($content_style != "" && $type == "title_on_top"){
	$pricing_content_clasess .= $content_style;
}

if($content_background_color != ""){
	$pricing_table_background .= "background-color: ".$content_background_color.";";
}

if($content_background_image != ""){
	if(is_numeric($content_background_image)) {
		$background_image_src = wp_get_attachment_url( $content_background_image );
	} else {
		$background_image_src = esc_url($content_background_image);
	}
	$pricing_table_background_image .= "background-image: url(".$background_image_src.");";
}
if($different_odd_even_sections == "yes"){
	if($even_back_color != ""){
		$data_attr .= " data-even-background-color='" . $even_back_color . "'";
	}
	if($odd_back_color != ""){
		$data_attr .= " data-odd-background-color='" . $odd_back_color . "'";
	}
}

if($title_color != '') {
    $title_style .= "color: '.$title_color.';";
    $title_top_type_title_style[] = "color:" .$title_color. ";";
}

if($title_font_family != '') {
    $title_style .= 'font-family: '.$title_font_family.';';
    $title_top_type_title_style[] = 'font-family: '.$title_font_family.';';
}


if($title_separator_color != '') {
    $title_separator_style = 'style="background-color: '.$title_separator_color.';"';
}

if($title_background_color != '') {
    $title_holder_style .= 'background-color: '.$title_background_color.';';
}

if($title_background_image != '') {
    if (is_numeric($title_background_image)) {
        $background_image_src = wp_get_attachment_url($title_background_image);
    } else {
        $background_image_src = $title_background_image;
    }
    $title_holder_style .= "background-image: url('".$background_image_src."');";
}

if($title_border_bottom_color != '') {
    $title_top_type_title_style[] = "border-bottom-color:".$title_border_bottom_color.";";
}


if(is_array($title_top_type_title_style) && count($title_top_type_title_style)) {
    $title_top_type_title_style = 'style="'.implode(';', $title_top_type_title_style).'"';
} else {
    $title_top_type_title_style = '';
}

if($show_button == "yes"){
	
	if($button_font_family != '') {
		$button_style .= 'font-family: '.$button_font_family.';';
		$button_on_bottom_style[] = 'font-family: '.$button_font_family;
	}
	
    if($button_font_size != '') {
    	$button_font_size = (strstr($button_font_size, 'px', true)) ? $button_font_size : $button_font_size . "px";
        $button_style .= 'font-size: '.$button_font_size.';';
        $button_on_bottom_style[] = 'font-size: '.$button_font_size;
    }
	
	if($button_color != '') {
		$button_style .= 'color: '.$button_color.';';
		$button_on_bottom_style[] = 'color: '.$button_color;
	}

    if($button_hover_color != '') {
        $data_attr_button .= "data-hover-color= '".$button_hover_color."'";
    }


	if($button_background_color != '') {
		$button_holder_style = 'background-color: '.$button_background_color.';';
		$button_on_bottom_style[] = 'background-color: '.$button_background_color; 
	}

    if($button_background_image != '' && $pricing_button_type == "standard_button") {
        if (is_numeric($button_background_image)) {
            $background_image_src = wp_get_attachment_url($button_background_image);
        } else {
            $background_image_src = $button_background_image;
        }
        $button_class .= " background_on_button";
        $button_holder_style .= "background-image: url('".$background_image_src."');";
    }
	
	if($button_icon_size != ""){
		$button_on_bottom_style[] = 'font-size: '.$button_icon_size.'px'; 
	}
	
	if(is_array($button_on_bottom_style) && count($button_on_bottom_style)) {
		$button_on_bottom_styles = implode(';', $button_on_bottom_style);
	} else {
			$button_on_bottom_styles = '';
	}
}


if($content_text_color != '') {
    $content_text_style = "color: ".$content_text_color.";";
}

if($table_border_top == "no"){ 
    $pricing_table_border_top_style[] = "border-top:0;";
    $active_text_position = "style = top:-38px;";
}

if($table_border_top == "no" && $border_arround=="yes"){ 
    $pricing_table_border_top_style[] = "border-top:0;";
    $active_text_position = "style = top:-39px;";
}

if($pricing_table_border_top_color != ''){
    $pricing_table_border_top_style[] = "border-top-color: ".$pricing_table_border_top_color.";";
}

if(is_array($pricing_table_border_top_style) && count($pricing_table_border_top_style)) {
    $pricing_table_border_top_style = 'style="'.implode(';', $pricing_table_border_top_style).'"';
} else {
    $pricing_table_border_top_style = '';
}

if($border_arround == "yes"){
    $border_arround_style[] = "border: 1px solid #fff;";
}

if(($border_arround == "yes") && ($border_arround_color != "")){
    $border_arround_style[] = "border-color: ".$border_arround_color." ;";
}

if(($border_arround == "yes") && ($table_border_top == "yes")){
    $border_arround_style[] = "border-top: 0;";
}

if(is_array($border_arround_style) && count($border_arround_style)) {
    $border_arround_style = 'style="'.implode(';', $border_arround_style).'"';
} else {
    $border_arround_style = '';
}

$disable_button_border_top_class = '';
if($type == "title_on_top" && $disable_button_border_top == "yes"){
    $disable_button_border_top_class .= " disable_button_border_top";
}


if($type=="title_on_top"){
    $html .= "<div class='q_price_table ".$pricing_table_clasess."' ".$pricing_table_border_top_style.">";
}

if($type=="price_on_top"){
    $html .= "<div class='q_price_table ".$pricing_table_clasess."'>";
}

$html .= "<div class='price_table_inner' ".$border_arround_style.">";

if($active == 'yes') {
	if(($type == "price_on_top") || ($type == "title_on_top" && $active_style == "circle")){
		 $html .= "<div class='active_text' ".$active_holder_style."><span class='active_text_inner'><span ".$active_text_style.">".$active_text."</span></span></div>";
	}
	if($type == "title_on_top" && $active_style == "rectangle"){
		$html .= "<div class='active_text' ".$active_text_position."><span class='active_text_inner' ".$active_holder_style."><span ".$active_text_style.">".$active_text."</span></span></div>";
	}   
}

$html .= "<ul style='".$pricing_table_background_image."'>";

if($type=="price_on_top" ){
    $html .= "<li class='prices' " .qode_pitch_get_inline_style($price_background_style) . ">";
    $html .= "<div class='price_in_table'" .  qode_pitch_get_inline_style($price_border_style).">";
    $html .= "<sup class='value' ".qode_pitch_get_inline_style($price_currency_style).">".$currency."</sup>";
    $html .= "<span class='price' ".qode_pitch_get_inline_style($price_style_array).">".$price."</span>";
    $html .= "<span class='mark'>/ ".$price_period."</span>";

    $html .= "</div>"; // close div.price_in_table
    $html .= "</li>"; //close li.prices
    $html .= "<li class='cell table_title ".$title_clasess."' ".qode_pitch_get_inline_style($title_holder_style).">";
    if($small_title != '') {
        $html .= "<span class='small_title_content' ".$title_style." > ".$small_title."</span>";
    }
    $html .= "<span class='title_content' ".$title_style.">".$title."</span>";
    
    if($title_separator == "yes"){
        $html .="<div class='title_separator'  ".$title_separator_style."></div>";
    }
    $html .= "</li>";
}

if($type=="title_on_top"){	
    $html .= "<li class='cell table_title ".$title_clasess."' ".qode_pitch_get_inline_style($title_holder_style).">";
    if($small_title != '') {
        $html .= "<span class='small_title_content' ".$title_style.">".$small_title."</span>";
    }
    $html .= "<span class='title_content' ".$title_top_type_title_style.">".$title."</span>";
    $html .= "</li>";    

    $html .= "<li class='prices $pricing_content_clasess' " .qode_pitch_get_inline_style($price_background_style) . ">";
    $html .= "<div class='price_in_table'" .  qode_pitch_get_inline_style($price_border_style).">";
    $html .= "<sup class='value' ".qode_pitch_get_inline_style($price_currency_style).">".$currency."</sup>";
    $html .= "<span class='price' ".qode_pitch_get_inline_style($price_style_array).">".$price."</span>";
    $html .= "<span class='mark'>/ ".$price_period."</span>";
    $html .= "</div>"; // close div.price_in_table
    $html .= "</li>"; //close li.prices	
}

$html .= "<li class='pricing_table_content $pricing_content_clasess ' style='".$content_text_style." ".$pricing_table_background."' $data_attr>";
$html .= do_shortcode($content); //append pricing table content
$html .= "</li>";
if($show_button == "yes"){
	if($pricing_button_type == "standard_button"){
		if(isset($button_text) && $button_text !== '') {
			$html .="<li class='price_button $button_class' ".qode_pitch_get_inline_style($button_holder_style)." >";
			if($type=="title_on_top"){
				$html .= "<div class='title_on_top_button_wrapper $disable_button_border_top_class'>";
				$html .= "<a ".qode_pitch_get_inline_style($button_style)." href='$link' target='$target'>".$button_text."";
				if($button_arrow == "yes"){
					$html .= "<span class='pricing_table_icon arrow_right'></span>";
				}        
				$html .= "</a>";
				$html .= "</div>";
			}

			if($type=="price_on_top"){
				$html .= "<a ".qode_pitch_get_inline_style($button_style)." href='$link' target='$target'>".$button_text."";
				if($button_arrow == "yes"){
					$html .= "<span class='pricing_table_icon arrow_right'></span>";
				}
				$html .= "</a>";
			}

			$html .= "</li>"; //close li.price_button
		}
	}elseif($pricing_button_type == "button_on_bottom"){
		$html .="<li class='button_on_bottom_wrapper'>";
		$html .="<a class='button_on_bottom' ".qode_pitch_get_inline_style($button_on_bottom_styles)." href='$link' target='$target'></a>";
		$html .="</li>";//close li.price_button
	}
}

$html .= "</ul>";
$html .= "</div>"; //close div.price_table_inner
$html .="</div>"; //close div.q_price_table

print $html;