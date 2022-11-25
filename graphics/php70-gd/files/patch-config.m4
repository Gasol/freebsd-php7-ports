--- config.m4.orig	2022-11-25 07:23:40 UTC
+++ config.m4
@@ -32,8 +32,8 @@ fi
 PHP_ARG_WITH(xpm-dir, for the location of libXpm,
 [  --with-xpm-dir[=DIR]      GD: Set the path to libXpm install prefix], no, no)
 
-PHP_ARG_WITH(freetype-dir, for FreeType 2,
-[  --with-freetype-dir[=DIR] GD: Set the path to FreeType 2 install prefix], no, no)
+PHP_ARG_ENABLE(freetype, for FreeType 2,
+[  --enable-freetype       GD: Enable FreeType 2 support], no, no)
 
 PHP_ARG_ENABLE(gd-native-ttf, whether to enable truetype string function in GD,
 [  --enable-gd-native-ttf  GD: Enable TrueType string function], no, no)
@@ -187,30 +187,14 @@ AC_DEFUN([PHP_GD_XPM],[
 ])
 
 AC_DEFUN([PHP_GD_FREETYPE2],[
-  if test "$PHP_FREETYPE_DIR" != "no"; then
+  if test "$PHP_FREETYPE" != "no"; then
+    PKG_CHECK_MODULES([FREETYPE2], [freetype2], [FREETYPE2_FOUND=true])
 
-    for i in $PHP_FREETYPE_DIR /usr/local /usr; do
-      if test -f "$i/bin/freetype-config"; then
-        FREETYPE2_DIR=$i
-        FREETYPE2_CONFIG="$i/bin/freetype-config"
-        break
-      fi
-    done
-
-    if test -z "$FREETYPE2_DIR"; then
-      AC_MSG_ERROR([freetype-config not found.])
-    fi
-
-    FREETYPE2_CFLAGS=`$FREETYPE2_CONFIG --cflags`
-    FREETYPE2_LIBS=`$FREETYPE2_CONFIG --libs`
-
     PHP_EVAL_INCLINE($FREETYPE2_CFLAGS)
     PHP_EVAL_LIBLINE($FREETYPE2_LIBS, GD_SHARED_LIBADD)
     AC_DEFINE(USE_GD_IMGSTRTTF, 1, [ ])
     AC_DEFINE(HAVE_LIBFREETYPE,1,[ ])
     AC_DEFINE(ENABLE_GD_TTF,1,[ ])
-  else
-    AC_MSG_RESULT([If configure fails try --with-freetype-dir=<DIR>])
   fi
 ])
 
