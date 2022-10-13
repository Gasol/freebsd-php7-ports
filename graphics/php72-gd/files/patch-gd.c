--- gd.c.orig	2018-07-17 05:35:52 UTC
+++ gd.c
@@ -53,7 +53,7 @@
 # include <Wingdi.h>
 #endif
 
-#ifdef HAVE_GD_XPM
+#if defined(HAVE_XPM) && defined(HAVE_GD_XPM)
 # include <X11/xpm.h>
 #endif
 
@@ -77,7 +77,7 @@ static int le_gd, le_gd_font;
 # endif
 #endif
 
-#if defined(HAVE_GD_XPM) && defined(HAVE_GD_BUNDLED)
+#if defined(HAVE_XPM) && defined(HAVE_GD_XPM) && defined(HAVE_GD_BUNDLED)
 # include "X11/xpm.h"
 #endif
 
@@ -325,7 +325,7 @@ ZEND_BEGIN_ARG_INFO(arginfo_imagecreatefromxbm, 0)
 	ZEND_ARG_INFO(0, filename)
 ZEND_END_ARG_INFO()
 
-#if defined(HAVE_GD_XPM)
+#if defined(HAVE_XPM) && defined(HAVE_GD_XPM)
 ZEND_BEGIN_ARG_INFO(arginfo_imagecreatefromxpm, 0)
 	ZEND_ARG_INFO(0, filename)
 ZEND_END_ARG_INFO()
@@ -934,7 +934,7 @@ const zend_function_entry gd_functions[] = {
 #endif
 	PHP_FE(imagecreatefromwbmp,						arginfo_imagecreatefromwbmp)
 	PHP_FE(imagecreatefromxbm,						arginfo_imagecreatefromxbm)
-#if defined(HAVE_GD_XPM)
+#if defined(HAVE_XPM) && defined(HAVE_GD_XPM)
 	PHP_FE(imagecreatefromxpm,						arginfo_imagecreatefromxpm)
 #endif
 	PHP_FE(imagecreatefromgd,						arginfo_imagecreatefromgd)
@@ -1299,7 +1299,7 @@ PHP_MINFO_FUNCTION(gd)
 	php_info_print_table_row(2, "libPNG Version", gdPngGetVersionString());
 #endif
 	php_info_print_table_row(2, "WBMP Support", "enabled");
-#if defined(HAVE_GD_XPM)
+#if defined(HAVE_XPM) && defined(HAVE_GD_XPM)
 	php_info_print_table_row(2, "XPM Support", "enabled");
 	{
 		char tmp[12];
@@ -1354,7 +1354,7 @@ PHP_FUNCTION(gd_info)
 	add_assoc_bool(return_value, "PNG Support", 0);
 #endif
 	add_assoc_bool(return_value, "WBMP Support", 1);
-#if defined(HAVE_GD_XPM)
+#if defined(HAVE_XPM) && defined(HAVE_GD_XPM)
 	add_assoc_bool(return_value, "XPM Support", 1);
 #else
 	add_assoc_bool(return_value, "XPM Support", 0);
@@ -2184,7 +2184,7 @@ PHP_FUNCTION(imagetypes)
 	ret |= 4;
 #endif
 	ret |= 8;
-#if defined(HAVE_GD_XPM)
+#if defined(HAVE_XPM) && defined(HAVE_GD_XPM)
 	ret |= 16;
 #endif
 #ifdef HAVE_GD_WEBP
@@ -2443,7 +2443,7 @@ static void _php_image_create_from(INTERNAL_FUNCTION_P
 			case PHP_GDIMG_TYPE_GD2PART:
 				im = (*func_p)(fp, srcx, srcy, width, height);
 				break;
-#if defined(HAVE_GD_XPM)
+#if defined(HAVE_XPM) && defined(HAVE_GD_XPM)
 			case PHP_GDIMG_TYPE_XPM:
 				im = gdImageCreateFromXpm(file);
 				break;
@@ -2525,7 +2525,7 @@ PHP_FUNCTION(imagecreatefromxbm)
 }
 /* }}} */
 
-#if defined(HAVE_GD_XPM)
+#if defined(HAVE_XPM) && defined(HAVE_GD_XPM)
 /* {{{ proto resource imagecreatefromxpm(string filename)
    Create a new image from XPM file or URL */
 PHP_FUNCTION(imagecreatefromxpm)
