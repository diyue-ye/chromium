--- base/base.gypi.orig	2011-07-27 11:01:28.000000000 +0300
+++ base/base.gypi	2011-08-12 21:31:05.632294656 +0300
@@ -94,6 +94,7 @@
           'files/file_path_watcher_linux.cc',
           'files/file_path_watcher_mac.cc',
           'files/file_path_watcher_win.cc',
+          'files/file_path_watcher_freebsd.cc',
           'fix_wp64.h',
           'float_util.h',
           'global_descriptors_posix.cc',
@@ -189,6 +190,7 @@
           'process_posix.cc',
           'process_util.cc',
           'process_util.h',
+          'process_util_freebsd.cc',
           'process_util_linux.cc',
           'process_util_mac.mm',
           'process_util_posix.cc',
@@ -371,11 +373,9 @@
                 'message_pump_glib_x.cc',
               ],
           }],
-          [ 'OS != "linux"', {
+          [ 'OS != "linux" and OS != "freebsd"', {
               'sources!': [
                 # Not automatically excluded by the *linux.cc rules.
-                'gtk_util.cc',
-                'gtk_util.h',
                 'linux_util.cc',
               ],
             },
@@ -391,6 +391,15 @@
               'sources/': [ ['exclude', '_freebsd\\.cc$'] ],
             },
           ],
+          # Older releases do not define EV_RECEIPT, fallback to stub.
+          [ 'OS == "freebsd" and <!(sysctl -n kern.osreldate) < 801000', {
+              'sources!': [
+                'files/file_path_watcher_freebsd.cc',
+              ],
+              'sources': [
+                'files/file_path_watcher_stub.cc',
+              ],
+          }],
           [ 'OS != "openbsd"', {
               'sources/': [ ['exclude', '_openbsd\\.cc$'] ],
             },
@@ -413,7 +422,7 @@
               'string16.cc',
             ],
           },],
-          ['os_posix==1 and OS!="linux" and OS!="mac"', {
+          ['os_posix==1 and OS!="linux" and OS!="mac" and OS!="freebsd"', {
             'sources!': [
               'files/file_path_watcher_linux.cc',
             ],
@@ -491,6 +500,13 @@
             ],
         }],
         [ 'OS == "freebsd" or OS == "openbsd"', {
+          # XXX rene: maybe this chunk should go one day
+          'sources!': [
+             'file_util_linux.cc',
+             'process_linux.cc',
+             'process_util_linux.cc',
+             'files/file_path_watcher_linux.cc',
+          ],
           'link_settings': {
             'libraries': [
               '-L/usr/local/lib -lexecinfo',
