<?php

$parallaxPage = new QodePitchAdminPage("15", "Parallax", "fa fa-unsorted");
$qode_pitch_Framework->qodeOptions->addAdminPage("Parallax",$parallaxPage);

//Parallax Settings

$panel1 = new QodePitchPanel("Parallax Settings","parallax_settings_panel");
$parallaxPage->addChild("panel1",$panel1);

	$parallax_onoff = new QodePitchField("onoff","parallax_onoff","off","Parallax on touch devices","Enabling this option will allow parallax on touch devices");
	$panel1->addChild("parallax_onoff",$parallax_onoff);

	$parallax_minheight = new QodePitchField("text","parallax_minheight","400","Parallax Min Height (px)","Set a minimum height for parallax images on small displays (phones, tablets, etc.)",array(), array("col_width" => 3));
	$panel1->addChild("parallax_minheight",$parallax_minheight);