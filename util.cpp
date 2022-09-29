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
