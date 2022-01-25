#pragma once
#include <memory>
#include <string>
#include <vector>
#include <optional>

namespace lwbus {

    struct LookupResult {
        std::string name;
        std::string host;
        std::string port;
    };

    using LookupResultVect = std::vector<LookupResult>;

    class ServiceLookup {
        public:
        ServiceLookup();
        virtual ~ServiceLookup();

        std::optional<LookupResult> FindService(const std::string &name);
        LookupResultVect ListServices();

        private:
        struct Data;
        std::unique_ptr<Data> m_data;
    };
}