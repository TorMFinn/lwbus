#pragma once
#include <memory>

namespace lwbus {
    class ServiceAdvertiser {
        public:
        ServiceAdvertiser();
        virtual ~ServiceAdvertiser();

        bool AdvertiseService(const std::string& name);

        private:
        struct Data;
        std::unique_ptr<Data> m_data;
    };
}