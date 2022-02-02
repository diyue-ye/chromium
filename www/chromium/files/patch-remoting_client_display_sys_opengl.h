Index: remoting/client/display/sys_opengl.h
--- remoting/client/display/sys_opengl.h.orig
+++ remoting/client/display/sys_opengl.h
@@ -9,7 +9,7 @@
 
 #if defined(OS_IOS)
 #include <OpenGLES/ES3/gl.h>
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #define GL_GLEXT_PROTOTYPES
 #include <GL/gl.h>
 #include <GL/glext.h>
