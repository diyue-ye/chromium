--- extensions/browser/extension_prefs.cc.orig	2022-04-21 18:48:31 UTC
+++ extensions/browser/extension_prefs.cc
@@ -2270,7 +2270,7 @@ void ExtensionPrefs::RegisterProfilePrefs(
   registry->RegisterDictionaryPref(kInstallSignature);
   registry->RegisterListPref(kExternalUninstalls);
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(pref_names::kChromeAppsEnabled, false);
 #endif
   registry->RegisterBooleanPref(pref_names::kU2fSecurityKeyApiEnabled, false);
