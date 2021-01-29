#define _GNU_SOURCE

//#include <stdio.h>
#include <dlfcn.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FAKE_UID 0;

static int (*old_xstat)(int ver, const char *path, struct stat *buf) = NULL;
static int (*old_xstat64)(int ver, const char *path, struct stat64 *buf) = NULL;

int __xstat(int ver, const char *path, struct stat *buf)
{
  if ( old_xstat == NULL ) {
    old_xstat = dlsym(RTLD_NEXT, "__xstat");
  }

  int retval = old_xstat(ver, path, buf);
  if (retval == 0) {
    buf->st_uid = FAKE_UID;
  }

  //printf("xstat %s\n",path);
  return retval;
}

int __xstat64(int ver, const char *path, struct stat64 *buf)
{
  if ( old_xstat64 == NULL ) {
    old_xstat64 = dlsym(RTLD_NEXT, "__xstat64");
  }

  int retval = old_xstat64(ver, path, buf);
  if (retval == 0) {
    buf->st_uid = FAKE_UID;
  }

  //printf("xstat64 %s\n",path);
  return retval;
}

int geteuid() {
   return FAKE_UID;
}

int getuid() {
   return FAKE_UID;
}
