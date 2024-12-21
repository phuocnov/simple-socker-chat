#pragma once
#include <string>
class Package {
private:
  std::string m_sender;
  std::string m_message;

public:
  Package();
  Package(std::string sender, std::string message);
  std::string get_sender();
  std::string get_message();
  void serialize(char *buffer);
  void deserialize(const char *buffer);
  void display();
};
