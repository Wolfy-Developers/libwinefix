# libwinefix
libwinefix - LD_PRELOAD library that fixes Wine's "&lt;dir> is not owned by you" error, written on C. The library is primarily intended for Termux, in which Wine will work. Disclaimer: this library designed only for the root user! If you work from a regular user, then you need to change the user ID value of the constant FAKE_UID in the libwinefix.c file. You can find out the current regular user ID value with the command "id -u"

The LD_PRELOAD trick is a useful technique to influence the linkage of shared libraries and the resolution of symbols (functions) at runtime. To explain LD_PRELOAD, let’s first discuss a bit about libraries in the Linux system. In brief, a library is a collection of compiled functions. We can make use of these functions in our programs without rewriting the same functionality. This can be achieved by either including the library code in our program (static library) or by linking dynamically at runtime (shared library).

## Usage
Before you start using the library, you must first clone this git repository, and compile it:
```
git clone https://github.com/Wolfy-Developers/libwinefix
cd libwinefix/
make
```
Now you must export the newly compiled file to a variable LD_PRELOAD, and start Wine:
```
LD_PRELOAD=`pwd`/libwinefix.so wine
```
