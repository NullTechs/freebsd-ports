--- lxsys.c.orig	Tue Apr 10 14:08:58 2007
+++ lxsys.c	Sat Apr 21 23:31:47 2007
@@ -1,12 +1,14 @@
-
-#include <sys/io.h>
+#include <sys/cdefs.h>
+#include <sys/types.h>
+#include <machine/cpufunc.h>
+#include <machine/sysarch.h>
 #include <unistd.h>
 #include <sys/mman.h>
+#include <sys/time.h>
 #include <sys/resource.h>
 #include <semaphore.h>
 #include <pthread.h>
 #include <sched.h>
-#include <sys/time.h>
 #include <fcntl.h>
 #include <termios.h>
 #include "thrdef.h"
@@ -18,8 +20,9 @@
 #include "hwaredef.h"
 
 struct termios old_options;
-char serport_name[]="/dev/ttyS?";
+char serport_name[]="/dev/ttyd?";
 
+extern int saved_euid;
 
 
 void lirerr(int errcod)
@@ -152,15 +155,13 @@
 
 int lir_parport_permission(void)
 {
-int i;
+int i=0;
 // Get permission to write to the parallel port
 if(ui.parport < 0x400-4)
   {
-  i=ioperm(ui.parport,4,1);
-  }
-else
-  {
-  i=iopl(3);
+  seteuid(saved_euid);
+  i=i386_set_ioperm(ui.parport,4,1);
+  seteuid(getuid());
   }
 if(i != 0)
   {
@@ -305,11 +306,9 @@
 int i;
 if(ui.parport < 0x400-4)
   {
-  i=ioperm(ui.parport,4,1);
-  }
-else
-  {
-  i=iopl(3);
+  seteuid(saved_euid);
+  i=i386_set_ioperm(ui.parport,4,1);
+  seteuid(getuid());
   }
 if(i!=0)lirerr(764921);
 i=1000;
@@ -322,11 +321,9 @@
 int i;
 if(ui.parport < 0x400-4)
   {
-  i=ioperm(ui.parport,4,1);
-  }
-else
-  {
-  i=iopl(3);
+  seteuid(saved_euid);
+  i=i386_set_ioperm(ui.parport,4,1);
+  seteuid(getuid());
   }
 if(i!=0)lirerr(764921);
 return inb(port);
