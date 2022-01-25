#pragma once
#include "lwbus/message.hpp"
#include <memory>

namespace lwbus {
class DataNode {
public:
  DataNode();
  virtual ~DataNode();

  bool InitNode(const std::string &name);

  bool PublishBinaryData(const BinaryMessage msg);

private:
  struct Data;
  std::unique_ptr<Data> m_data;
};
} // namespace lwbus