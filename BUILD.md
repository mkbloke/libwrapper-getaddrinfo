To build the wrapper library requires make, gcc and the libc development package.

Building should be as simple as cloning or downloading the repository contents, then:

cd libwrapper-getaddrinfo
make

The resulting libwrapper-getaddrinfo.so can then be used in the LD_PRELOAD environment avaiable.
