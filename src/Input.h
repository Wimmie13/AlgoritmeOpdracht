/*
 * Input.h
 *
 *  Created on: 10 mrt. 2017
 *      Author: Willem
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <fstream>
#include <vector>
#include "JobShop.h"

class Input
{
public:
	typedef int type_input;
	Input(const std::string& filename);
	virtual ~Input();
	void generateJobs(JobShop& jobShop);
	const int getAmountOfMachines();
	const int getAmountOfJobs();
private:
	std::vector<type_input> info;
	std::vector<std::vector<Task>> jobs;
};

#endif /* INPUT_H_ */
