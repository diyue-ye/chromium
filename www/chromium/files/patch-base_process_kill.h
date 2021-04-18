--- base/process/kill.h.orig	2020-10-07 16:38:34 UTC
+++ base/process/kill.h
@@ -113,11 +113,11 @@ BASE_EXPORT TerminationStatus GetTerminationStatus(Pro
 BASE_EXPORT TerminationStatus GetKnownDeadTerminationStatus(
     ProcessHandle handle, int* exit_code);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Spawns a thread to wait asynchronously for the child |process| to exit
 // and then reaps it.
 BASE_EXPORT void EnsureProcessGetsReaped(Process process);
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 #endif  // defined(OS_POSIX)
 
 // Registers |process| to be asynchronously monitored for termination, forcibly
