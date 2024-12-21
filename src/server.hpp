#pragma once

#include "package.hpp"
#include <vector>
#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CONNECTIONS 5
#define MAX_CHAT_BUFFER 5

class Server {
private:
  std::vector<Package> packages;
  void send_message(int client_socket);

public:
  void m_main();
};
