--- third_party/blink/renderer/modules/webgl/webgl_rendering_context_base.cc.orig	2022-04-21 18:48:31 UTC
+++ third_party/blink/renderer/modules/webgl/webgl_rendering_context_base.cc
@@ -6109,7 +6109,7 @@ void WebGLRenderingContextBase::TexImageHelperMediaVid
   constexpr bool kAllowZeroCopyImages = true;
 #endif
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(crbug.com/1175907): Only TexImage2D seems to work with the GPU path on
   // Android M -- appears to work fine on R, but to avoid regressions in <video>
   // limit to TexImage2D only for now. Fails conformance test on Nexus 5X:
