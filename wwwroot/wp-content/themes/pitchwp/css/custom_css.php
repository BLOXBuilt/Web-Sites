<?php
$absolute_path = explode('wp-content', $_SERVER['SCRIPT_FILENAME']);

if(count($absolute_path) == 1) {
    $absolute_path = explode('wp-admin', $_SERVER['SCRIPT_FILENAME']);
}

$wp_load = $absolute_path[0] . 'wp-load.php';
require_once($wp_load);

header("Content-type: text/css; charset=utf-8");

?>


<?php print $qode_pitch_options['custom_css'];  ?>
<?php print $qode_pitch_options['custom_svg_css']; ?>
