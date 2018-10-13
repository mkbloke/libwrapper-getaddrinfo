#define _GNU_SOURCE

#include <dlfcn.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

static int (*real_getaddrinfo)(const char *node, const char *service,
  const struct addrinfo *hints, struct addrinfo **res);

int getaddrinfo(const char *node, const char *service,
  const struct addrinfo *hints, struct addrinfo **res)
{
  struct addrinfo replacement_hints;

  memset(&replacement_hints, 0, sizeof(struct addrinfo));
  memcpy(&replacement_hints, hints, sizeof(struct addrinfo));
  replacement_hints.ai_family = AF_INET;

  real_getaddrinfo = dlsym(RTLD_NEXT, "getaddrinfo");
  return real_getaddrinfo(node, service, &replacement_hints, res);
}
