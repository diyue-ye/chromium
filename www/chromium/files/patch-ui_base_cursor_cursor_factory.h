Index: ui/base/cursor/cursor_factory.h
--- ui/base/cursor/cursor_factory.h.orig
+++ ui/base/cursor/cursor_factory.h
@@ -81,7 +81,7 @@ class COMPONENT_EXPORT(UI_BASE_CURSOR) CursorFactory {
   base::ObserverList<CursorFactoryObserver>::Unchecked observers_;
 };
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 COMPONENT_EXPORT(UI_BASE_CURSOR)
 std::vector<std::string> CursorNamesFromType(mojom::CursorType type);
 #endif
