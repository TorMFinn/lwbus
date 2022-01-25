#include "lwbus/ServiceAdvertiser.hpp"
#include "ext/mdns.h"

#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdexcept>
#include <sys/socket.h>

#include <cstring>
#include <iostream>
#include <string>

namespace lwbus {
struct ServiceAdvertiser::Data {
  Data() {}

  bool OpenSocket() {
    struct sockaddr_in addr;
    addr.sin_port = MDNS_PORT;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;

    socket_fd = mdns_socket_open_ipv4(&addr);
    if (socket_fd < 0) {
      std::cerr << "failed to open socket: " << std::strerror(errno)
                << std::endl;
      return false;
    }
    return true;
  }

  int socket_fd;
};

ServiceAdvertiser::ServiceAdvertiser() : m_data(new Data()) {}

ServiceAdvertiser::~ServiceAdvertiser() = default;

bool ServiceAdvertiser::AdvertiseService(const std::string &name) {
    if (!m_data->OpenSocket()) {
        return false;
    }
}

} // namespace lwbus
