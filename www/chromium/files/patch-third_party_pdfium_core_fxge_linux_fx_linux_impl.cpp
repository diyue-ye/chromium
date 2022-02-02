Index: third_party/pdfium/core/fxge/linux/fx_linux_impl.cpp
--- third_party/pdfium/core/fxge/linux/fx_linux_impl.cpp.orig
+++ third_party/pdfium/core/fxge/linux/fx_linux_impl.cpp
@@ -17,7 +17,7 @@
 #include "third_party/base/check.h"
 #include "third_party/base/cxx17_backports.h"
 
-#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_ASMJS)
+#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_ASMJS) && !defined(OS_BSD)
 #error "Included on the wrong platform"
 #endif
 
@@ -165,9 +165,9 @@ class CLinuxPlatform : public CFX_GEModule::PlatformIf
   std::unique_ptr<SystemFontInfoIface> CreateDefaultSystemFontInfo() override {
     auto pInfo = std::make_unique<CFX_LinuxFontInfo>();
     if (!pInfo->ParseFontCfg(CFX_GEModule::Get()->GetUserFontPaths())) {
-      pInfo->AddPath("/usr/share/fonts");
-      pInfo->AddPath("/usr/share/X11/fonts/Type1");
-      pInfo->AddPath("/usr/share/X11/fonts/TTF");
+	    /* XXXROBERT */
+      pInfo->AddPath("/usr/X11R6/lib/X11/fonts/Type1");
+      pInfo->AddPath("/usr/X11R6/lib/X11/fonts/TTF");
       pInfo->AddPath("/usr/local/share/fonts");
     }
     return pInfo;
