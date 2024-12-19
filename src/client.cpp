#include "client.hpp"

#include "iostream"
#include "sys/socket.h"
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CONNECTIONS 5

void send_message(int client_socket) {}

void Client::init_state() {
  // Implement init logic
  m_app_state = ASSIGN_USERNAME;
}

void Client::assign_username() {
  // Implement assign username logic
  std::cout << "Enter your username: ";
  std::string username;
  std::cin >> username;

  m_username = username;
  std::cout << "Welcome " << m_username << " join the chat!" << std::endl;
  m_app_state = CHATTING;
}

void Client::chatting() {
  // Implement assign username logic
  while (m_app_state == CHATTING) {
  }
  m_app_state = EXIT;
}

void Client::exit() {
  // Implement assign username logic
}

void Client::main() {
  bool is_running = true;
  EAppState app_state = INIT;

  while (is_running) {
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    auto connect_result =
        connect(client_socket, (struct sockaddr *)&server_address,
                sizeof(server_address));

    std::string message;
    // Wait for user input
    std::cout << "Enter a message: ";
    std::getline(std::cin, message);
    // Send the message to the server
    send(client_socket, message.c_str(), message.size(), 0);
    close(client_socket);
  }
}
