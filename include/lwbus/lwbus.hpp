#pragma once
#include <functional>
#include <memory>
#include <string>

#include "message.hpp"

namespace lwbus {

using ReceiveHandler = std::function<void(const Message &)>;

class Bus {
  public:
    Bus();
    virtual ~Bus();

    bool open_connection(const std::string service_name);
    void set_receive_handler(ReceiveHandler handler);

    int WriteData(const DataMessage &msg);
    void SendRequestWaitReply(RequestMessage, ReceiveHandler handler);
    void setReceiveHandler(ReceiveHandler handler);

  protected:
    int WriteMessage(const Message &msg);
    ReceiveHandler m_handler;

  private:
    struct Data;
    std::unique_ptr<Data> m_data;
};

} // namespace lwbus