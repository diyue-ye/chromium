--- content/gpu/gpu_main.cc.orig	2022-03-25 21:59:56 UTC
+++ content/gpu/gpu_main.cc
@@ -86,7 +86,7 @@
 #include "sandbox/win/src/sandbox.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/gpu/gpu_sandbox_hook_linux.h"
 #include "sandbox/policy/linux/sandbox_linux.h"
 #include "sandbox/policy/sandbox_type.h"
@@ -108,7 +108,7 @@ namespace content {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool StartSandboxLinux(gpu::GpuWatchdogThread*,
                        const gpu::GPUInfo*,
                        const gpu::GpuPreferences&);
@@ -170,7 +170,7 @@ class ContentSandboxHelper : public gpu::GpuSandboxHel
   bool EnsureSandboxInitialized(gpu::GpuWatchdogThread* watchdog_thread,
                                 const gpu::GPUInfo* gpu_info,
                                 const gpu::GpuPreferences& gpu_prefs) override {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     return StartSandboxLinux(watchdog_thread, gpu_info, gpu_prefs);
 #elif BUILDFLAG(IS_WIN)
     return StartSandboxWindows(sandbox_info_);
@@ -266,7 +266,7 @@ int GpuMain(MainFunctionParams parameters) {
           std::make_unique<base::SingleThreadTaskExecutor>(
               gpu_preferences.message_pump_type);
     }
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #error "Unsupported Linux platform."
 #elif BUILDFLAG(IS_MAC)
     // Cross-process CoreAnimation requires a CFRunLoop to function at all, and
@@ -409,17 +409,19 @@ int GpuMain(MainFunctionParams parameters) {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool StartSandboxLinux(gpu::GpuWatchdogThread* watchdog_thread,
                        const gpu::GPUInfo* gpu_info,
                        const gpu::GpuPreferences& gpu_prefs) {
   TRACE_EVENT0("gpu,startup", "Initialize sandbox");
 
+#if !BUILDFLAG(IS_BSD)
   if (watchdog_thread) {
     // SandboxLinux needs to be able to ensure that the thread
     // has really been stopped.
     sandbox::policy::SandboxLinux::GetInstance()->StopThread(watchdog_thread);
   }
+#endif
 
   // SandboxLinux::InitializeSandbox() must always be called
   // with only one thread.
@@ -454,11 +456,13 @@ bool StartSandboxLinux(gpu::GpuWatchdogThread* watchdo
           *base::CommandLine::ForCurrentProcess()),
       base::BindOnce(GpuProcessPreSandboxHook), sandbox_options);
 
+#if !BUILDFLAG(IS_BSD)
   if (watchdog_thread) {
     base::Thread::Options thread_options;
     thread_options.timer_slack = base::TIMER_SLACK_MAXIMUM;
     watchdog_thread->StartWithOptions(std::move(thread_options));
   }
+#endif
 
   return res;
 }
