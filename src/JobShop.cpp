/*
 * JobShop.cpp
 *
 *  Created on: 10 mrt. 2017
 *      Author: Willem
 */

#include "JobShop.h"
#include <unordered_map>

JobShop::JobShop(type_jobshop anAmountOfMachines) :
		amountOfMachines(anAmountOfMachines)
{

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

int JobShop::getAmountOfMachines() const
{
	return amountOfMachines;
}
