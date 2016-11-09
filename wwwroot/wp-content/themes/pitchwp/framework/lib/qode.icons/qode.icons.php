<?php


include get_template_directory().'/framework/lib/qode.icons/qode.iconcollection.interface.php';
include get_template_directory().'/framework/lib/qode.icons/qode.fontawesome.php';
include get_template_directory().'/framework/lib/qode.icons/qode.fontelegant.php';
include get_template_directory().'/framework/lib/qode.icons/qode.ionicons.php';
include get_template_directory().'/framework/lib/qode.icons/qode.lineaicons.php';
include get_template_directory().'/framework/lib/qode.icons/qode.simplelineicons.php';
include get_template_directory().'/framework/lib/qode.icons/qode.dripicons.php';

/*
  Class: qode_pitch_IconCollections
  A class that initializes Qode Icon Collections
 */

class qode_pitch_IconCollections {

    private static $instance;
    public $iconCollections;
    public $VCParamsArray;
    public $iconPackParamName;

    private function __construct() {
        $this->iconPackParamName = 'icon_pack';
        $this->initIconCollections();
    }

    public static function get_instance() {

        if (null == self::$instance) {
            self::$instance = new self;
        }

        return self::$instance;
    }

    /**
     * Method that adds individual collections to set of collections
     */
    private function initIconCollections() {
        $this->addIconCollection('font_awesome', new QodePitchIconsFontAwesome("Font Awesome", "fa_icon"));
        $this->addIconCollection('font_elegant', new QodePitchIconsFontElegant("Font Elegant", "fe_icon"));
        $this->addIconCollection('ion_icons', new QodePitchIconsIonIcons("Ion Icons", "ion_icon"));
        $this->addIconCollection('linea_icons', new QodePitchIconsLineaIcons('Linea Icons', 'linea_icon'));
        $this->addIconCollection('simple_line_icons', new QodePitchSimpleLineIcons('Simple Line Icons',
            'simple_line_icons'));
        $this->addIconCollection('dripicons', new QodePitchDripicons('Dripicons', 'dripicon'));
    }

    public function getVCParamsArray($iconPackDependency = array(), $iconCollectionPrefix = "", $emptyIconPack = false) {
        if ($emptyIconPack) {
            $iconCollectionsVC = $this->getIconCollectionsVCEmpty();
        } else {
            $iconCollectionsVC = $this->getIconCollectionsVC();
        }

        $iconPackParams = array(
            "type" => "dropdown",
            "class" => "",
            "heading" => "Icon pack",
            "param_name" => $this->iconPackParamName,
            "value" => $iconCollectionsVC,
			"save_always" => true,
            "description" => ""
        );

        if ($iconPackDependency !== "") {
            $iconPackParams["dependency"] = $iconPackDependency;
        }

        $iconPackParams = array($iconPackParams);

        $iconSetParams = array();
        if (is_array($this->iconCollections) && count($this->iconCollections)) {
            foreach ($this->iconCollections as $key => $collection) {
                $iconSetParams[] = array(
                    "type" => "dropdown",
                    "class" => "",
                    "heading" => "Icon",
                    "param_name" => $iconCollectionPrefix . $collection->param,
                    "value" => $collection->getIconsArray(),
                    "description" => "",
                    "dependency" => array('element' => $this->iconPackParamName, 'value' => array($key))
                );
            }
        }

        return array_merge($iconPackParams, $iconSetParams);
    }

    public function getSocialVCParamsArray($iconPackDependency = array(), $iconCollectionPrefix = "", $emptyIconPack = false, $exclude = '') {
        if ($emptyIconPack) {
            $iconCollectionsVC = $this->getIconCollectionsVCEmptyExclude($exclude);
        } else {
            $iconCollectionsVC = $this->getIconCollectionsVCExclude($exclude);
        }


        $iconPackParams = array(
            "type" => "dropdown",
            "class" => "",
            "heading" => "Icon pack",
            "param_name" => $this->iconPackParamName,
            "value" => $iconCollectionsVC,
            "description" => ""
        );

        if ($iconPackDependency !== "") {
            $iconPackParams["dependency"] = $iconPackDependency;
        }

        $iconPackParams = array($iconPackParams);

        $iconCollections = $this->iconCollections;
        if(is_array($exclude) && count($exclude)) {
            foreach ($exclude as $exclude_key) {
                if  (array_key_exists($exclude_key, $this->iconCollections)) {

                    unset($iconCollections[$exclude_key]);
                }
            }

        } else {
            if  (array_key_exists($exclude, $this->iconCollections)) {
                unset($iconCollections[$exclude]);
            }
        }

        $iconSetParams = array();
        if (is_array($iconCollections) && count($iconCollections)) {
            foreach ($iconCollections as $key => $collection) {
                $iconSetParams[] = array(
                    "type" => "dropdown",
                    "class" => "",
                    "heading" => "Icon",
                    "param_name" => $iconCollectionPrefix . $collection->param,
                    "value" => $collection->getSocialIconsArrayVC(),
                    "description" => "",
                    "dependency" => array('element' => $this->iconPackParamName, 'value' => array($key))
                );
            }
        }

        return array_merge($iconPackParams, $iconSetParams);
    }

    public function getCollectionsWithSocialIcons() {
        $collectionsWithSocial = array();

        foreach ($this->iconCollections as $key => $collection) {
            if($collection->hasSocialIcons()) {
                $collectionsWithSocial[$key] = $collection;
            }
        }

        return $collectionsWithSocial;

    }

    public function getIconSizesArray() {
        return array(
            "Tiny" => "fa-lg",
            "Small" => "fa-2x",
            "Medium" => "fa-3x",
            "Large" => "fa-4x",
            "Very Large" => "fa-5x"
        );
    }

    public function getIconSizeClass($iconSize) {
        switch ($iconSize) {
            case "fa-lg":
                $iconSize = "qode_tiny_icon";
                break;
            case "fa-2x":
                $iconSize = "qode_small_icon";
                break;
            case "fa-3x":
                $iconSize = "qode_medium_icon";
                break;
            case "fa-4x":
                $iconSize = "qode_large_icon";
                break;
            case "fa-5x":
                $iconSize = "qode_huge_icon";
                break;
            default:
                $iconSize = "qode_small_icon";
        }

        return $iconSize;
    }

	public function getIconCollectionParamNameByKey($key) {
		$collection = $this->getIconCollection($key);

		if($collection) {
			return $collection->param;
		}

		return false;
	}

    public function getShortcodeParams($iconCollectionPrefix = "") {
        $iconCollectionsParam = array();
        foreach ($this->iconCollections as $key => $collection) {
            $iconCollectionsParam[$iconCollectionPrefix . $collection->param] = '';
        }

        return array_merge(array($this->iconPackParamName => '',), $iconCollectionsParam);
    }

    public function addIconCollection($key, $value) {
        $this->iconCollections[$key] = $value;
    }

    public function getIconCollection($key) {
        if (array_key_exists($key, $this->iconCollections)) {
            return $this->iconCollections[$key];   
        }
        return false;
            
    }

    public function getIconCollectionIcons(iIconPitchCollection $collection) {
        return $collection->getIconsArray();
    }

    public function getIconCollectionsVC() {
        $vc_array = array();
        foreach ($this->iconCollections as $key => $collection) {
            $vc_array[$collection->title] = $key;
        }
        return $vc_array;
    }

    public function getIconCollectionsVCExclude($exclude) {
        $array = $this->getIconCollectionsVC();

        if(is_array($exclude) && count($exclude)) {
            foreach ($exclude as $key) {
                if(($x = array_search($key, $array)) !== false) {
                    unset($array[$x]);
                }
            }

        } else {
            if(($x = array_search($exclude, $array)) !== false) {
                unset($array[$x]);
            }
        }


        return $array;
    }

    public function getIconCollectionsKeys() {
        return array_keys($this->iconCollections);
    }

    /**
     * Method that returns an array of 'param' attribute of each icon collection
     * @return array array of param attributes
     */
    public function getIconCollectionsParams() {
        $paramArray = array();
        if(is_array($this->iconCollections) && count($this->iconCollections)) {
            foreach ($this->iconCollections as $key => $obj) {
                $paramArray[] = $obj->param;
            }
        }

        return $paramArray;
    }

    public function getIconCollections() {
        $array = array();
        foreach ($this->iconCollections as $key => $collection) {
            $array[$key] = $collection->title;
        }
        return $array;
    }

    public function getIconCollectionsEmpty($no_empty_key = "") {
        $array = array();
        $array[$no_empty_key] = "No Icon";
        foreach ($this->iconCollections as $key => $collection) {
            $array[$key] = $collection->title;
        }

        return $array;
    }

    public function getIconCollectionsVCEmpty() {
        $vc_array = array();
        $vc_array["No Icon"] = "";
        foreach ($this->iconCollections as $key => $collection) {
            $vc_array[$collection->title] = $key;
        }
        return $vc_array;
    }

    public function getIconCollectionsVCEmptyExclude($key) {
        $array = $this->getIconCollectionsVCEmpty();
        if  (($x = array_search($key, $array)) !== false) {
            unset($array[$x]);
        }
        return $array;
    }

    public function getIconCollectionsExclude($exclude) {
        $array = $this->getIconCollections();

        if(is_array($exclude) && count($exclude)) {
            foreach ($exclude as $exclude_key) {
                if(array_key_exists($exclude_key, $array)) {
                    unset($array[$exclude_key]);
                }
            }

        } else {
            if  (array_key_exists($exclude, $array)) {
                unset($array[$exclude]);
            }
        }

        return $array;
    }

    public function hasIconCollection($key) {

        return array_key_exists($key, $this->iconCollections);

    }


    # HEADER AND SIDE MENU ICONS
    public function getSearchIcon($iconPack) {

        if ($this->hasIconCollection($iconPack)) {

            $iconsObject = $this->getIconCollection($iconPack);
            print $iconsObject->getSearchIcon();

        }

    }

    public function getSearchClose($iconPack) {

        if ($this->hasIconCollection($iconPack)) {

            $iconsObject = $this->getIconCollection($iconPack);
            print $iconsObject->getSearchClose();

        }

    }

    public function getSearchIconValue($iconPack) {

        if ($this->hasIconCollection($iconPack)) {

            $iconsObject = $this->getIconCollection($iconPack);
            print $iconsObject->getSearchIconValue();

        }

    }

    public function getMenuSideIcon($iconPack) {

        if ($this->hasIconCollection($iconPack)) {

            $iconsObject = $this->getIconCollection($iconPack);
            print $iconsObject->getMenuSideIcon();

        }

    }

    public function getBackToTopIcon($iconPack) {

        if ($this->hasIconCollection($iconPack)){

            $iconsObject = $this->getIconCollection($iconPack);
            print $iconsObject->getBackToTopIcon();

        }


    }

    public function getMobileMenuIcon($iconPack) {

        if($this->hasIconCollection($iconPack)) {

            $iconsObject = $this->getIconCollection($iconPack);
            print $iconsObject->getMobileMenuIcon();

        }

    }

    public function getQuoteIcon($iconPack, $return = false) {

        if($this->hasIconCollection($iconPack)) {

            $iconsObject = $this->getIconCollection($iconPack);
            if($return == true){
                return $iconsObject->getQuoteIcon();
            }
            else{
                print $iconsObject->getQuoteIcon();
            }

        }

    }


    # SOCIAL SIDEBAR ICONS
    public function getFacebookIcon($iconPack) {

        if ($this->hasIconCollection($iconPack)) {

            $iconsObject = $this->getIconCollection($iconPack);
            return $iconsObject->getFacebookIcon();

        }

    }

    public function getTwitterIcon($iconPack) {

        if ($this->hasIconCollection($iconPack)) {

            $iconsObject = $this->getIconCollection($iconPack);
            return $iconsObject->getTwitterIcon();

        }

    }

    public function getGooglePlusIcon($iconPack) {

        if ($this->hasIconCollection($iconPack)) {

            $iconsObject = $this->getIconCollection($iconPack);
            return $iconsObject->getGooglePlusIcon();

        }

    }

    public function getLinkedInIcon($iconPack) {

        if ($this->hasIconCollection($iconPack)) {

            $iconsObject = $this->getIconCollection($iconPack);
            return $iconsObject->getLinkedInIcon();

        }

    }

    public function getTumblrIcon($iconPack) {

        if ($this->hasIconCollection($iconPack)) {

            $iconsObject = $this->getIconCollection($iconPack);
            return $iconsObject->getTumblrIcon();

        }

    }

    public function getPinterestIcon($iconPack) {

        if ($this->hasIconCollection($iconPack)) {

            $iconsObject = $this->getIconCollection($iconPack);
            return $iconsObject->getPinterestIcon();

        }

    }

    public function getVKIcon($iconPack) {

        if ($this->hasIconCollection($iconPack)) {

            $iconsObject = $this->getIconCollection($iconPack);
            return $iconsObject->getVKIcon();

        }

    }


}

global $qode_pitch_IconCollections;
$qode_pitch_IconCollections = qode_pitch_IconCollections::get_instance();