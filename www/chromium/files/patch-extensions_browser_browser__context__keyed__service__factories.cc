--- extensions/browser/browser_context_keyed_service_factories.cc.orig	2022-03-25 21:59:56 UTC
+++ extensions/browser/browser_context_keyed_service_factories.cc
@@ -89,7 +89,7 @@ void EnsureBrowserContextKeyedServiceFactoriesBuilt() 
   IdleManagerFactory::GetInstance();
   ManagementAPI::GetFactoryInstance();
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   NetworkingPrivateEventRouterFactory::GetInstance();
 #endif
   PowerAPI::GetFactoryInstance();
