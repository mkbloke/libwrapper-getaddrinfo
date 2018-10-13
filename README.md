# libwrapper-getaddrinfo
A wrapper library to replace the libc getaddrinfo() function with a version that doesn't return IPv6 addresses.

To use this wrapper with an application, start the application, such as streamlink by specifiying the path to
the wrapper shared object file in the LD_PRELOAD environment variable.  For example:

LD_PRELOAD="/home/user/libwrapper-getaddrinfo/libwrapper-getaddrinfo.so" streamlink tvplayer.com/watch/tvpone best
