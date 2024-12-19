#pragma once

#include "package.hpp"
#include <stack>
#include <string>

#define MAX_CHAT_BUFFER 5

enum EAppState { INIT, ASSIGN_USERNAME, CHATTING, EXIT };

class Client {
private:
  EAppState m_app_state = INIT;
  std::string m_username;
  std::stack<Package> m_packets;

  void init_state();
  void assign_username();
  void chatting();
  void exit();

public:
  void main();
};
