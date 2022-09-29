#pragma once

#include <string>
#include <vector>

namespace util {
	std::string rd(std::string name);

	namespace path {
		extern const std::string curr;

		extern const std::string sep;

		std::string build(std::vector<std::string> entry);
	}
}
