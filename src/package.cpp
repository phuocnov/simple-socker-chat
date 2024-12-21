#include "package.hpp"
#include <cstring>
#include <iostream>

Package::Package() {
  m_sender = "";
  m_message = "";
}

Package::Package(std::string sender, std::string message) {
  m_sender = sender;
  m_message = message;
}
void Package::serialize(char *buffer) {
  size_t offset = 0;

  size_t senderLength = m_sender.size();
  std::memcpy(buffer + offset, &senderLength, sizeof(size_t));
  offset += sizeof(size_t);

  std::memcpy(buffer + offset, m_sender.c_str(), senderLength);
  offset += senderLength;

  size_t messageLength = m_message.size();
  std::memcpy(buffer + offset, &messageLength, sizeof(size_t));
  offset += sizeof(size_t);

  std::memcpy(buffer + offset, m_message.c_str(), messageLength);
}
void Package::deserialize(const char *buffer) {
  size_t offset = 0;

  // Deserialize sender string
  size_t senderLength;
  std::memcpy(&senderLength, buffer + offset,
              sizeof(size_t)); // Read the length of sender
  offset += sizeof(size_t);    // Move the offset forward

  m_sender.resize(senderLength); // Resize the sender string to fit the length
  std::memcpy(&m_sender[0], buffer + offset,
              senderLength); // Copy the sender string data
  offset += senderLength;    // Move the offset forward

  // Deserialize message string
  size_t messageLength;
  std::memcpy(&messageLength, buffer + offset,
              sizeof(size_t)); // Read the length of message
  offset += sizeof(size_t);    // Move the offset forward

  m_message.resize(
      messageLength); // Resize the message string to fit the length
  std::memcpy(&m_message[0], buffer + offset,
              messageLength); // Copy the message string data
}

void Package::display() {
  std::cout << m_sender << ": " << m_message << std::endl;
}
