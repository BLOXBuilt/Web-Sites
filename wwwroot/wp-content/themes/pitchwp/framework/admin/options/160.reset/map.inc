<?php

$resetPage = new QodePitchAdminPage("21", "Reset", "fa fa-retweet");
$qode_pitch_Framework->qodeOptions->addAdminPage("Reset",$resetPage);

//Reset

$panel1 = new QodePitchPanel("Reset to Defaults","reset_panel");
$resetPage->addChild("panel1",$panel1);

	$reset_to_defaults = new QodePitchField("yesno","reset_to_defaults","no","Reset to Defaults","This option will reset all Select Options values to defaults");
	$panel1->addChild("reset_to_defaults",$reset_to_defaults);