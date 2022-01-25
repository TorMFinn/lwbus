#pragma once
#include "message.hpp"

namespace lwbus {
std::string msg_to_json(MessagePtr msg);
MessagePtr json_to_msg(const std::string &json);
} // namespace lwbus