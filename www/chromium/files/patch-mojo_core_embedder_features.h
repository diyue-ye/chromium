Index: mojo/core/embedder/features.h
--- mojo/core/embedder/features.h.orig
+++ mojo/core/embedder/features.h
@@ -14,7 +14,7 @@ namespace mojo {
 namespace core {
 
 #if defined(OS_POSIX) && !defined(OS_NACL) && !defined(OS_MAC)
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 COMPONENT_EXPORT(MOJO_CORE_EMBEDDER_FEATURES)
 extern const base::Feature kMojoLinuxChannelSharedMem;
 
