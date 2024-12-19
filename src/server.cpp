#include "server.hpp"
#include "iostream"
#include "sys/socket.h"
#include <netinet/in.h>
#include <unistd.h>

void Server::main() {
  // Create a socket
  int socker_server = socket(AF_INET, SOCK_STREAM, 0);

  // Specify socker address
  sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(PORT);
  server_address.sin_addr.s_addr = INADDR_ANY;

  // Bind the socket to the specified address
  int bind_result = bind(socker_server, (struct sockaddr *)&server_address,
                         sizeof(server_address));

  // Listen for incoming connections
  listen(socker_server, MAX_CONNECTIONS);
  std::cout << "Server listening on port " << PORT << std::endl;

  while (true) {
    // Accept incoming connections
    int client_socket = accept(socker_server, NULL, NULL);

    // Receive data from the client
    char buffer[BUFFER_SIZE] = {0};
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    std::cout << "Message: " << buffer << std::endl;
  }

  close(socker_server);
}
