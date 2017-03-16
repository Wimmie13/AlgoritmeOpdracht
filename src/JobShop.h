/*
 * JobShop.h
 *
 *  Created on: 10 mrt. 2017
 *      Author: Willem
 */

#ifndef JOBSHOP_H_
#define JOBSHOP_H_

#include <vector>
#include "Job.h"
#include "Machine.h"

class JobShop
{
public:
	typedef int type_jobshop;
	JobShop(type_jobshop anAmountOfMachines);
	void addJob(type_jobshop id, std::vector<Task> taskList);
	virtual ~JobShop();
	const std::vector<Job>& getJobList() const;
	const std::vector<Machine>& getMachineList() const;
	type_jobshop getAmountOfMachines() const;
private:
	std::vector<Job> JobList;
	std::vector<Machine> MachineList;
	type_jobshop amountOfMachines;
};

#endif /* JOBSHOP_H_ */
