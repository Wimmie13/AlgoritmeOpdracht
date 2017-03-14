/*
 * Input.h
 *
 *  Created on: 10 mrt. 2017
 *      Author: Willem
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <fstream>
#include "JobShop.h"

class Input
{
public:
	typedef int type_input;
	Input(const std::string& filename);
	virtual ~Input();
	void generateJobs(JobShop& jobShop);
	const type_input getAmountOfMachines();
	const type_input getAmountOfJobs();
private:
	std::vector<std::vector<type_input>> lines;
};

#endif /* INPUT_H_ */
