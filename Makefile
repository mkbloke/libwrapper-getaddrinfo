CC=gcc
CFLAGS=-fPIC -shared
LFLAGS=-ldl
FMODE=0644

libwrapper-getaddrinfo.so: libwrapper-getaddrinfo.c
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)
	chmod $(FMODE) $@

clean:
	rm -f *~ *.so

.PHONY: clean
