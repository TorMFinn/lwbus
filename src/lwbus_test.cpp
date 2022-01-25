#include "lwbus/ServiceAdvertiser.hpp"
#include "lwbus/ServiceLookup.hpp"
#include <cstdlib>
#include <iostream>

int main_service() {
    return 0;
}

int main_lookup() {
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        return EXIT_FAILURE;
    }

    switch (std::stoi(argv[1])) {
        case 1:
        return main_service();
        case 2:
        return main_lookup();
    }

    std::cerr << "Unknown program name" << std::endl;

    return EXIT_FAILURE;
}