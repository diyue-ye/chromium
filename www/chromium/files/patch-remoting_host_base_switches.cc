Index: remoting/host/base/switches.cc
--- remoting/host/base/switches.cc.orig
+++ remoting/host/base/switches.cc
@@ -23,7 +23,7 @@ const char kProcessTypeEvaluateCapability[] = "evaluat
 const char kProcessTypeFileChooser[] = "file_chooser";
 const char kProcessTypeUrlForwarderConfigurator[] =
     "url_forwarder_configurator";
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 const char kProcessTypeXSessionChooser[] = "xsession_chooser";
 #endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
 
