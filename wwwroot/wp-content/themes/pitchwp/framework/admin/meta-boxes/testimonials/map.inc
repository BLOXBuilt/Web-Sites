<?php

//Testimonials

$qodeTestimonials = new QodePitchMetaBox("testimonials", "Testimonials");
$qode_pitch_Framework->qodeMetaBoxes->addMetaBox("testimonials",$qodeTestimonials);

	$qode_show_testimonial_title_text = new QodePitchMetaField("yesno","qode_show_testimonial_title_text","no","Hide Testimonial Title Text","Enable this option to hide the title text", array(), array("dependence" => true, "dependence_hide_on_yes" => "#qodef_qode_testimonial_title_container", "dependence_show_on_yes" => ""));
	$qodeTestimonials->addChild("qode_show_testimonial_title_text",$qode_show_testimonial_title_text);

		$qode_testimonial_title_container = new QodePitchContainer("qode_testimonial_title_container","qode_show_testimonial_title_text","yes");
		$qodeTestimonials->addChild("qode_testimonial_title_container",$qode_testimonial_title_container);
	
			$qode_testimonial_title= new QodePitchMetaField("text","qode_testimonial_title","","Title","Enter testimonial title");
			$qode_testimonial_title_container->addChild("qode_testimonial_title",$qode_testimonial_title);
	
	$qode_testimonial_author = new QodePitchMetaField("text","qode_testimonial-author","","Author","Enter author name");
	$qodeTestimonials->addChild("qode_testimonial-author",$qode_testimonial_author);

	$qode_testimonial_author_position = new QodePitchMetaField("text","qode_testimonial_author_position","","Job Position","Enter job position name");
	$qodeTestimonials->addChild("qode_testimonial_author_position",$qode_testimonial_author_position);

	$qode_testimonial_text = new QodePitchMetaField("textarea","qode_testimonial-text","","Text","Enter testimonial text");
	$qodeTestimonials->addChild("qode_testimonial-text",$qode_testimonial_text);