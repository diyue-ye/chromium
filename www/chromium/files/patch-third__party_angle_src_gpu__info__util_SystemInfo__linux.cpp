--- third_party/angle/src/gpu_info_util/SystemInfo_linux.cpp.orig	2021-09-14 01:58:21 UTC
+++ third_party/angle/src/gpu_info_util/SystemInfo_linux.cpp
@@ -71,6 +71,15 @@ bool GetPCIDevicesWithLibPCI(std::vector<GPUDeviceInfo
 
 bool GetSystemInfo(SystemInfo *info)
 {
+#if defined(__FreeBSD__)
+    if (!CollectMesaCardInfo(&(info->gpus)))
+    {
+        if (!GetPCIDevicesFreeBSD(&(info->gpus)))
+        {
+            return GetSystemInfoVulkan(info);
+        }
+    }
+#else
     if (!GetPCIDevicesWithLibPCI(&(info->gpus)))
     {
         return false;
@@ -80,6 +89,7 @@ bool GetSystemInfo(SystemInfo *info)
     {
         return false;
     }
+#endif
 
     GetDualGPUInfo(info);
 
