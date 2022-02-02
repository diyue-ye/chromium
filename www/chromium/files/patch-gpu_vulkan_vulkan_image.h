Index: gpu/vulkan/vulkan_image.h
--- gpu/vulkan/vulkan_image.h.orig
+++ gpu/vulkan/vulkan_image.h
@@ -86,7 +86,7 @@ class COMPONENT_EXPORT(VULKAN) VulkanImage {
       VkImageUsageFlags usage,
       VkImageCreateFlags flags);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   static std::unique_ptr<VulkanImage> CreateWithExternalMemoryAndModifiers(
       VulkanDeviceQueue* device_queue,
       const gfx::Size& size,
@@ -169,7 +169,7 @@ class COMPONENT_EXPORT(VULKAN) VulkanImage {
       VkImageTiling image_tiling,
       uint32_t queue_family_index);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   bool InitializeWithExternalMemoryAndModifiers(VulkanDeviceQueue* device_queue,
                                                 const gfx::Size& size,
                                                 VkFormat format,
