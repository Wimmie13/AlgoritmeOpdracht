//============================================================================
// Name        : main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "input.h"
#include "JobShop.h"

int main(int argc, char **argv)
{
	Input input(argv[1]);
	JobShop jobShop(input.getAmountOfMachines());
	input.generateJobs(jobShop);

	return 0;
}
