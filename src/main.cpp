#include <netinet/in.h>
#include <unistd.h>

#include "client.hpp"
#include "server.hpp"

int main(int argc, char *argv[]) {
  Client client;
  Server server;
  if (argc > 1) {
    if (strcmp(argv[1], "--server") == 0) {
      server.m_main();
    } else {
      client.m_main();
    }
  } else {
    client.m_main();
  }
  return 0;
}
