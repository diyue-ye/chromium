--- components/network_session_configurator/browser/network_session_configurator_unittest.cc.orig	2022-04-21 18:48:31 UTC
+++ components/network_session_configurator/browser/network_session_configurator_unittest.cc
@@ -820,7 +820,7 @@ TEST_F(NetworkSessionConfiguratorTest, HostRules) {
 }
 
 TEST_F(NetworkSessionConfiguratorTest, DefaultCacheBackend) {
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   EXPECT_EQ(net::URLRequestContextBuilder::HttpCacheParams::DISK_SIMPLE,
             ChooseCacheType());
 #elif BUILDFLAG(IS_MAC)
