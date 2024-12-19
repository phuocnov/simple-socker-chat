#include <netinet/in.h>
#include <unistd.h>

#include "client.hpp"
#include "server.hpp"

int main(int argc, char *argv[]) {
  Client *client;
  Server *server;
  if (argc > 1) {
    if (strcmp(argv[1], "--server") == 0) {
      server->main();
    } else {
      client->main();
    }
  } else {
    client->main();
  }
  return 0;
}
