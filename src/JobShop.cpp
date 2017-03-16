/*
 * JobShop.cpp
 *
 *  Created on: 10 mrt. 2017
 *      Author: Willem
 */

#include "JobShop.h"

JobShop::JobShop(type_jobshop anAmountOfMachines) :
		amountOfMachines(anAmountOfMachines)
{
	for (auto i = 0; i<anAmountOfMachines; ++i){
		MachineList.push_back(Machine(i));
	}
}

JobShop::~JobShop()
{
	// TODO Auto-generated destructor stub
}

void JobShop::addJob(type_jobshop id, std::vector<Task> taskList)
{
	JobList.push_back(Job(id, taskList));
}

const std::vector<Job>& JobShop::getJobList() const
{
	return JobList;
}

const std::vector<Machine>& JobShop::getMachineList() const
{
	return MachineList;
}

JobShop::type_jobshop JobShop::getAmountOfMachines() const
{
	return amountOfMachines;
}
