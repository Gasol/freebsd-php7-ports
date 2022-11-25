--- acinclude.m4.orig	2022-11-25 06:34:20 UTC
+++ acinclude.m4
@@ -3102,3 +3102,6 @@ AC_DEFUN([PHP_CHECK_BUILTIN_CTZLL], [
 
 dnl Load the AX_CHECK_COMPILE_FLAG macro from the autoconf archive.
 m4_include([build/ax_check_compile_flag.m4])
+
+dnl Load pkg-config macros
+m4_include([build/pkg.m4])
