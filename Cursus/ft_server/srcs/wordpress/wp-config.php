<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://codex.wordpress.org/Editing_wp-config.php
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'root' );

/** MySQL database password */
define( 'DB_PASSWORD', '' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8mb4' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         'lz)(~=8;sEA{4j2n2$;zW]UNL#g4IJSMK)!<]WE-KU~Qiqi/.K)(^9YUtx<z,ea=' );
define( 'SECURE_AUTH_KEY',  'Z*4aLiNphAhQveFB`!@cqCHuC_z^>dj0pmgV1 g)T&oXAF{C3N.n/=Xm1Sp]0CVm' );
define( 'LOGGED_IN_KEY',    'R?|}+^fk,4Q8.gYzxA}9wW545,A}w,29%]3AYmlP4yV;^G}MQo<szunZ+ Fm#=d6' );
define( 'NONCE_KEY',        '?L?c%8CA8^cS /f<7}|lsGnf/Gqkx.h>/):BVswq}PPY$piceKWl_=KZJ5@g)f4t' );
define( 'AUTH_SALT',        '8J*9Kk^@K+JX~5L,8J!%0[!1CBcbU`fH/8|VVL83drw:xWnQaQ7YYQ%$zDl.?!Vs' );
define( 'SECURE_AUTH_SALT', 'HF@gh,i.&$k I0ulN<3rw|lRqBQ[x~a.(2{az|08b.iNv59>%@M2<$|#y:R7t+wW' );
define( 'LOGGED_IN_SALT',   'lQ fv6cxK0/S#[h1E:|BaA*3eUUa:aOGh5^NuBHQ/+.)`Wr..r*_mFJ i%pb|,XH' );
define( 'NONCE_SALT',       'g{$=697&M FX/jcw_-x:<lU7N<p]%|@C5=pafcC<n#G-TJ 37hW{>+!;IfG8TNLv' );

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}

/** Sets up WordPress vars and included files. */
require_once( ABSPATH . 'wp-settings.php' );
