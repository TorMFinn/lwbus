#pragma once

#include "../message.hpp"

namespace lwbus::std_msgs {
	class VPNStatus : lwbus::BinaryMessage {
		public:
		VPNStatus();
		virtual ~VPNStatus();

		private:
	};
};