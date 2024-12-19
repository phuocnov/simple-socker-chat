#pragma once
#include <string>
class Package {
private:
  std::string sender;
  std::string message;

public:
  Package(std::string sender, std::string message);
  std::string get_sender();
  std::string get_message();
};
