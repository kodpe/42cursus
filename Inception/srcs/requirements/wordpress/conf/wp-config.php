<?php
/** The name of the db for WordPress */
define("DB_NAME", getenv("DB_NAME"));

/** MySQL db username */
define("DB_USER", getenv("DB_USER"));

/** MySQL db password */
define("DB_PASSWORD", getenv("DB_PASSWORD"));

/** MySQL hostname */
define("DB_HOST", getenv("DB_HOST") . ":3306");

/** Database Charset to use in creating db tables. */
define('DB_CHARSET', 'utf8');

/** The Database Collate type. Don't change this if in doubt. */
define('DB_COLLATE', '');

$table_prefix  = 'wp_';
define("WP_DEBUG", true);
define('WP_DEBUG_DISPLAY', false);

if (!defined("ABSPATH"))
	define("ABSPATH", __DIR__ . "/");

define( 'UPLOADS', 'wp-content/uploads' );
require_once ABSPATH . "wp-settings.php";

/* That's all, stop editing! Happy blogging. */
?>
