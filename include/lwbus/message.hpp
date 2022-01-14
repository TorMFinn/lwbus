#pragma once
#include <memory>
#include <string>
#include <vector>

namespace lwbus {

const std::string m = R"(
  {
    "type": "data",
    "name: "mavlink",
    "payload": "_bytes_"
  }

  {
    "type": "request",
    "name": "get_fc_state",
    "payload": ""
  }

  {
    "type": "reply",
    "name": "get_fc_state",
    "payload": "armed"
  }
)";

enum class MessageType
{
    json,
    binary,
    request,
    reply
};

class Message {
  public:
    virtual MessageType get_type() = 0;
    virtual std::string get_name() = 0;
    virtual std::string get_payload() = 0;

  protected:
    std::string m_data;
};

using MessagePtr = std::shared_ptr<Message>();

class BinaryMessage : public Message {
  public:
    MessageType get_type() override {
        return MessageType::binary;
    }

    void SetBinaryData(std::vector<uint8_t> bytes);
};

class JsonMessage : public Message {
  public:
    MessageType get_type() override {
        return MessageType::json;
    }
};

class RequestMessage : public Message {
  public:
    MessageType get_type() override {
        return MessageType::request;
    }
};

class ReplyMessage : public Message {
  public:
    MessageType get_type() override {
        return MessageType::reply;
    }
};
} // namespace lwbus