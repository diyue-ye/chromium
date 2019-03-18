--- content/browser/storage_partition_impl_map.cc.orig	2019-03-17 17:40:34 UTC
+++ content/browser/storage_partition_impl_map.cc
@@ -425,7 +425,7 @@ StoragePartitionImpl* StoragePartitionImplMap::Get(
   bool create_request_context = true;
   if (base::FeatureList::IsEnabled(network::features::kNetworkService)) {
     // These ifdefs should match StoragePartitionImpl::GetURLRequestContext.
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     create_request_context = false;
 #elif defined(OS_ANDROID)
     create_request_context =
