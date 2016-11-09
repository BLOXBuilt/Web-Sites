<?php

$qode_pages = array();
$pages = get_posts(array(
    'post_type' => 'page',
    'meta_key' => '_wp_page_template',
    'meta_value' => 'login.php'
));
foreach($pages as $page) {
    $qode_pages[$page->ID] = $page->post_title;
}

$loginPage = new QodePitchAdminPage("20", "Login Page", "fa fa-user");
$qode_pitch_Framework->qodeOptions->addAdminPage("Login Page",$loginPage);

//Maintenance

$panel1 = new QodePitchPanel("Settings","login_panel");
$loginPage->addChild("panel1",$panel1);

	$qode_enable_login_page = new QodePitchField("yesno","qode_enable_login_page","no","Login Page","Turn on this option if you want to enable login page on your site", array(),
        array("dependence" => true,
            "dependence_hide_on_yes" => "",
            "dependence_show_on_yes" => "#qodef_login_container"
        ));
	$panel1->addChild("qode_enable_login_page",$qode_enable_login_page);

    $login_container = new QodePitchContainer("login_container","qode_enable_login_page","no");
    $panel1->addChild("login_container",$login_container);

    $qode_login_page = new QodePitchField("selectblank","qode_login_page","",'Login Page','Choose login page to display on your site',$qode_pages);
    $login_container->addChild("qode_login_page",$qode_login_page);

    $login_page_title = new QodePitchField("text","login_page_title","","Login Page Title","Enter title you want to have displayed on login page.", array(), array("col_width" => 12));
    $login_container->addChild("login_page_title",$login_page_title);

    $login_page_subtitle = new QodePitchField("text","login_page_subtitle","","Login Page Subtitle","Enter subtitle you want to have displayed on login page.", array(), array("col_width" => 12));
    $login_container->addChild("login_page_subtitle",$login_page_subtitle);

    $login_page_image = new QodePitchField("image","login_page_image","","Backround Image",'Upload custom image to be displayed as your login page background.');
    $login_container->addChild("login_page_image",$login_page_image);