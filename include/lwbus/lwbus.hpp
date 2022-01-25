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

    bool OpenConnection(const std::string service_name);
    void SetReceiveHandler(ReceiveHandler handler);

    //void SendRequestWaitReply(RequestMessage, ReceiveHandler handler);

  protected:
    //int WriteMessage(const Message &msg);
    ReceiveHandler m_handler;

  private:
    struct Data;
    std::unique_ptr<Data> m_data;
};

} // namespace lwbus