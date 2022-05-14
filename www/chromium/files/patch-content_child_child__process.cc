--- content/child/child_process.cc.orig	2022-04-21 18:48:31 UTC
+++ content/child/child_process.cc
@@ -72,7 +72,7 @@ ChildProcess::ChildProcess(base::ThreadPriority io_thr
   DCHECK(!g_lazy_child_process_tls.Pointer()->Get());
   g_lazy_child_process_tls.Pointer()->Set(this);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   const base::CommandLine& command_line =
       *base::CommandLine::ForCurrentProcess();
   const bool is_embedded_in_browser_process =
