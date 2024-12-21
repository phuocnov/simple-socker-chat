#include "client.hpp"

#include "iostream"
#include "package.hpp"
#include "sys/socket.h"
#include <netinet/in.h>
#include <string>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CONNECTIONS 5

void send_message(Package package) {
  int client_socket = socket(AF_INET, SOCK_STREAM, 0);

  sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(PORT);
  server_address.sin_addr.s_addr = INADDR_ANY;

  auto connect_result =
      connect(client_socket, (struct sockaddr *)&server_address,
              sizeof(server_address));
  char buffer[1024];
  package.serialize(buffer);

  send(client_socket, buffer, sizeof(Package), 0);
  close(client_socket);
}

void Client::init_state() {
  // Implement init logic
  m_app_state = ASSIGN_USERNAME;
  std::cout << "Welcome to the chat!" << std::endl;
  return;
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
    std::cout << "Enter a message: ";

    std::string message;
    std::getline(std::cin, message);

    if (message == "/exit") {
      m_app_state = EXIT;
      continue;
    }
    Package package(m_username, message);
    send_message(package);
    std::cout << "Message sent!" << std::endl;
  }
  m_app_state = EXIT;
}

void Client::exit() {
  // Implement assign username logic
  m_exit = true;
}

void Client::m_main() {
  while (!m_exit) {
    switch (m_app_state) {
    case INIT:
      init_state();
      break;
    case ASSIGN_USERNAME:
      assign_username();
      break;
    case CHATTING:
      chatting();
      break;
    case EXIT:
      exit();
      break;
    }
  }
}
