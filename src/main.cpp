//============================================================================
// Name        : main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "input.h"
#include <fstream>

int main(int argc, char **argv) {
	std::ifstream input(argv[1]);

	std::cout << input.get() << std::endl;
	return 0;
}
