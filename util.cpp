#include <fstream>
#include <iostream>

#include "util.h"

std::string util::rd(std::string fName) {
	std::ifstream in;
	in.open(fName);

	std::string buff;
	for (std::string l; std::getline(in, l);) {
		buff += l + "\n";
	}

	in.close();

	return buff;
}

const std::string util::path::curr = ".";

const std::string util::path::sep = "/";

std::string util::path::build(std::vector<std::string> entry) {
	std::string serial;
	for (int i = 0; i < entry.size(); i++) {
		std::string val = entry[i];

		if (i < entry.size() - 1) {
			val += sep;
		}

		serial += val;
	}

	return serial;
}
