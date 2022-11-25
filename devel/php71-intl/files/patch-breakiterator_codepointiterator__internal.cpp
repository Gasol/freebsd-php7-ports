--- breakiterator/codepointiterator_internal.cpp.orig	2022-11-24 13:09:05 UTC
+++ breakiterator/codepointiterator_internal.cpp
@@ -74,7 +74,11 @@ CodePointBreakIterator::~CodePointBreakIterator()
 	clearCurrentCharIter();
 }
 
+#if U_ICU_VERSION_MAJOR_NUM >= 70
+bool CodePointBreakIterator::operator==(const BreakIterator& that) const
+#else
 UBool CodePointBreakIterator::operator==(const BreakIterator& that) const
+#endif
 {
 	if (typeid(*this) != typeid(that)) {
 		return FALSE;
