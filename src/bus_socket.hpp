#pragma once
#include <memory>

namespace lwbus {
class BusSocket {
	public:
	BusSocket();
	~BusSocket();

	void Listen();

	private:
	struct Data;
	std::unique_ptr<Data> m_data;
};
} // namespace lwbus