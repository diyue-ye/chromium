--- chrome/common/chrome_features.h.orig	2022-04-21 18:48:31 UTC
+++ chrome/common/chrome_features.h
@@ -95,7 +95,7 @@ extern const base::Feature kArcPiGhostWindow;
 COMPONENT_EXPORT(CHROME_FEATURES) extern const base::Feature kAsyncDns;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kAutofillAddressSurvey;
 COMPONENT_EXPORT(CHROME_FEATURES)
@@ -104,7 +104,7 @@ COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kAutofillPasswordSurvey;
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kBackgroundModeAllowRestart;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -219,7 +219,7 @@ COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kDesktopPWAsWebBundles;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kDesktopPWAsWebAppSettingsPage;
 COMPONENT_EXPORT(CHROME_FEATURES)
@@ -440,7 +440,7 @@ COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kKernelnextVMs;
 #endif
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMEOS)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kLinuxLowMemoryMonitor;
 COMPONENT_EXPORT(CHROME_FEATURES)
@@ -449,7 +449,7 @@ COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::FeatureParam<int> kLinuxLowMemoryMonitorCriticalLevel;
 #endif  // BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kListWebAppsSwitch;
 #endif
