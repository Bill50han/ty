#ifndef LIBC_H
#define LIBC_H

#include <type.h>

//string.h start

typedef unsigned __int64 size_t
#define NULL ((void *)0)

extern void* memset(
    _OUT_   void* _Dst,
    _IN_    int    _Val,
    _IN_    size_t size
);

//string.h end

//errno.h start

typedef errno_t int;
#define errno _errno()

extern int _errno(void);

#define EPERM           1   //Operation not permitted
#define ENOENT          2   //No such file or directory
#define ESRCH           3   //No such process
#define EINTR           4   //Interrupted function call
#define EIO             5   //Input/output error
#define ENXIO           6   //No such device or address
#define E2BIG           7   //Arg list too long
#define ENOEXEC         8   //Exec format error
#define EBADF           9   //Bad file descriptor
#define ECHILD          10  //No child processes
#define EAGAIN          11  //Resource temporarily unavailable
#define ENOMEM          12  //Not enough space
#define EACCES          13  //Permission denied
#define EFAULT          14  //Bad address

#define EBUSY           16  //Resource device
#define EEXIST          17  //File exists
#define EXDEV           18  //Improper link
#define ENODEV          19  //No such device
#define ENOTDIR         20  //Not a directory
#define EISDIR          21  //Is a directory
#define EINVAL          22  //Invalid argument
#define ENFILE          23  //Too many open files in system
#define EMFILE          24  //Too many open files
#define ENOTTY          25  //Inappropriate I/O control operation

#define EFBIG           27  //File too large
#define ENOSPC          28  //No space left on device
#define ESPIPE          29  //Invalid seek
#define EROFS           30  //Read-only file system
#define EMLINK          31  //Too many links
#define EPIPE           32  //Broken pipe
#define EDOM            33  //Domain error
#define ERANGE          34  //Result too large

#define EDEADLK         36  //Resource deadlock avoided

#define ENAMETOOLONG    38  //Filename too long
#define ENOLCK          39  //No locks available
#define ENOSYS          40  //Function not implemented
#define ENOTEMPTY       41  //Directory not empty
#define EILSEQ          42  //Illegal byte sequence

//errno.h end



#endif // !LIBC_H
