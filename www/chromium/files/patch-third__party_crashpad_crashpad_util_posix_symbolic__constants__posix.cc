--- third_party/crashpad/crashpad/util/posix/symbolic_constants_posix.cc.orig	2022-02-07 13:39:41 UTC
+++ third_party/crashpad/crashpad/util/posix/symbolic_constants_posix.cc
@@ -64,7 +64,7 @@ constexpr const char* kSignalNames[] = {
     "INFO",
     "USR1",
     "USR2",
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 #if defined(ARCH_CPU_MIPS_FAMILY)
     "HUP",
     "INT",
@@ -135,7 +135,7 @@ constexpr const char* kSignalNames[] = {
 #endif  // defined(ARCH_CPU_MIPS_FAMILY)
 #endif
 };
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 // NSIG is 64 to account for real-time signals.
 static_assert(base::size(kSignalNames) == 32, "kSignalNames length");
 #else
