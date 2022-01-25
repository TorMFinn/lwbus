#include "lwbus/lwbus.hpp"
#include "ext/mdns.h"

#include <netinet/in.h>
#include <nng/nng.h>
#include <nng/protocol/bus0/bus.h>

namespace lwbus {

struct Bus::Data {
    nng_socket sock;
};

Bus::Bus() {
}

Bus::~Bus() {
}

bool Bus::OpenConnection(const std::string service_name) {
    /*
    struct sockaddr if_addr;
    if_addr.sa_family = AF_INET;

    int sock = mdns_socket_open_ipv4(const struct sockaddr_in *saddr) mdns_discovery_send(int sock) return false;
    */
}

void Bus::SetReceiveHandler(ReceiveHandler handler) {
    m_handler = handler;
}

/*
void Bus::SendRequestWaitReply(RequestMessage, ReceiveHandler handler) {
}
*/
} // namespace lwbus