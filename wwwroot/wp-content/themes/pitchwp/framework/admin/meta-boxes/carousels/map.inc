<?php

//Carousels

$qodeCarousels = new QodePitchMetaBox("carousels", "Carousels");
$qode_pitch_Framework->qodeMetaBoxes->addMetaBox("carousels",$qodeCarousels);

	$qode_carousel_image = new QodePitchMetaField("image","qode_carousel-image","","Carousel Image","Choose carousel image (min width needs to be 215px)");
	$qodeCarousels->addChild("qode_carousel-image",$qode_carousel_image);

	$qode_carousel_hover_image = new QodePitchMetaField("image","qode_carousel-hover-image","","Carousel Hover Image","Choose carousel hover image (min width needs to be 215px)");
	$qodeCarousels->addChild("qode_carousel-hover-image",$qode_carousel_hover_image);

	$qode_carousel_item_text = new QodePitchMetaField("textarea","qode_carousel-item-text","","Text","Enter carousel text");
	$qodeCarousels->addChild("qode_carousel-item-text",$qode_carousel_item_text);

	$qode_carousel_item_link = new QodePitchMetaField("text","qode_carousel-item-link","","Link","Enter the URL to which you want the image to link to (e.g. http://www.example.com)");
	$qodeCarousels->addChild("qode_carousel-item-link",$qode_carousel_item_link);

	$qode_carousel_item_target = new QodePitchMetaField("selectblank","qode_carousel-item-target","","Target","Specify where to open the linked document", array(
        "_self" => "Self",
        "_blank" => "Blank"
    ));
	$qodeCarousels->addChild("qode_carousel-item-target",$qode_carousel_item_target);