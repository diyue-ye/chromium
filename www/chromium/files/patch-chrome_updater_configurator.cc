--- chrome/updater/configurator.cc.orig	2022-03-25 21:59:56 UTC
+++ chrome/updater/configurator.cc
@@ -39,7 +39,7 @@
 #include "chrome/updater/win/net/network.h"
 #elif BUILDFLAG(IS_MAC)
 #include "chrome/updater/mac/net/network.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/updater/linux/net/network.h"
 #endif
 
