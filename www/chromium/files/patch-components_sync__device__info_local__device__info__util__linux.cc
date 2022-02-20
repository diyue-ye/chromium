--- components/sync_device_info/local_device_info_util_linux.cc.orig	2022-02-07 13:39:41 UTC
+++ components/sync_device_info/local_device_info_util_linux.cc
@@ -14,6 +14,11 @@
 #include "ash/constants/devicetype.h"
 #endif
 
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#define HOST_NAME_MAX MAXHOSTNAMELEN
+#endif
+
 namespace syncer {
 
 #if BUILDFLAG(IS_CHROMEOS_ASH)
