#include "lwbus/lwbus.hpp"
#include "ext/mdns.h"

#include <netinet/in.h>

namespace lwbus {
struct lwbus::Data {};
lwbus::lwbus() {
}

lwbus::~lwbus() {
}

bool lwbus::open_connection(const std::string service_name) {
    struct sockaddr if_addr;
    if_addr.sa_family = AF_INET;

    int sock = mdns_socket_open_ipv4(const struct sockaddr_in *saddr) mdns_discovery_send(int sock) return false;
}

void lwbus::set_receive_handler(receive_handler handler) {
    m_handler = handler;
}

int lwbus::write_message(const message &msg) {
}
} // namespace lwbus