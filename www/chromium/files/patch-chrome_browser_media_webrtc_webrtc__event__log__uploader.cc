--- chrome/browser/media/webrtc/webrtc_event_log_uploader.cc.orig	2020-10-07 16:38:38 UTC
+++ chrome/browser/media/webrtc/webrtc_event_log_uploader.cc
@@ -36,7 +36,7 @@ constexpr size_t kExpectedMimeOverheadBytes = 1000;  /
 const char kProduct[] = "Chrome";
 #elif defined(OS_MAC)
 const char kProduct[] = "Chrome_Mac";
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 const char kProduct[] = "Chrome_Linux";
 #elif defined(OS_ANDROID)
 const char kProduct[] = "Chrome_Android";
