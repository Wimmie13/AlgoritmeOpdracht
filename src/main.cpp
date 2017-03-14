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



//	for (unsigned int i = 0; i < test.size(); i++)
//	{
//		for (unsigned int j = 0; j < test.at(i).size(); j++)
//		{
//			std::cout << test.at(i).at(j) << " ";
//		}
//		std::cout << std::endl;
//	}
	return 0;
}
