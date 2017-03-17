/*
 * Algoritme.cpp
 *
 *  Created on: 10 mrt. 2017
 *      Author: Willem
 */

#include "Algoritme.h"
#include <iostream>

Algoritme::Algoritme(JobShop& aJobShop) :
		jobShop(aJobShop)
{
	// TODO Auto-generated constructor stub

}

Algoritme::~Algoritme()
{
	// TODO Auto-generated destructor stub
}

int Algoritme::calculateCriticalPath(std::vector<Job>& JobList)
{
	int criticalPath;

	for (int i = 0; i < JobList.size(); i++)
	{
		int criticalPathJob = 0;

		for (int j = 0; j < JobList.at(i).getTaskList().size(); j++)
		{
			criticalPathJob += JobList.at(i).getTaskList().at(j).getTijdsduur();
		}

		if (criticalPathJob >= criticalPath)
		{
			criticalPath = criticalPathJob;
		}
	}
	return criticalPath;
}

int Algoritme::calculateLeastSlack(std::vector<Job> JobList)
{
	int jobId;
	int criticalPath = calculateCriticalPath(JobList);
	int leastSlack = criticalPath;

	for (int i = JobList.size()-1 ; i >= 0; --i)
	{
	auto taskList = JobList.at(i).getTaskList();
	int leastSlackJob = criticalPath;
	for (int j = taskList.size()-1 ; j >= 0; --j)
	{
		leastSlackJob -= taskList.at(j).getTijdsduur();
	}

	if (leastSlackJob <= leastSlack)
	{
		leastSlack = leastSlackJob;
		jobId = i;
		}
	}
	return jobId;
}

void Algoritme::generateResults()
{
	std::vector<Job> JobList = jobShop.getJobList();
	std::vector<Machine> MachineList = jobShop.getMachineList();
	int jobsRemaining = JobList.size();

	//while there are still tasks remaining to be scheduled
	while (jobsRemaining != 0)
	{
		auto& job = JobList.at(calculateLeastSlack(JobList));
		auto& taskList = job.getTaskList();

		//if this is the first task to be scheduled for this job
		if (job.getStarttime() == -1)
		{
			//set startTime for the job
			job.setStarttime(MachineList.at(taskList.at(0).getMachineId()).getEndTime());
			job.updateEndTime(MachineList.at(taskList.at(0).getMachineId()).getEndTime());
			//set endTime for the machine
			MachineList.at(taskList.at(0).getMachineId()).setEndTime(taskList.at(0).getTijdsduur());
			//set endTime for the job
			job.updateEndTime(MachineList.at(taskList.at(0).getMachineId()).getEndTime());
			//std::cout << "j.setEndTime: " << MachineList.at(taskList.at(0).getMachineId()).getEndTime() << std::endl;
		}
		//if this is not the first task to be scheduled for this job
		else {
//			//update the endTime for the machine
//			MachineList.at(taskList.at(0).getMachineId()).updateEndTime(taskList.at(0).getTijdsduur());
//			std::cout << "m.updateEndTime: " << taskList.at(0).getTijdsduur() << std::endl;
//			std::cout << taskList.at(0).getMachineId() << MachineList.at(taskList.at(0).getMachineId()).getEndTime() << std::endl;
//			//update the endTime for the job
//			job.updateEndTime(MachineList.at(taskList.at(0).getMachineId()).getEndTime());
//			//std::cout << "j.updateEndTime: " << MachineList.at(taskList.at(0).getMachineId()).getEndTime() << std::endl;
		auto machine = MachineList.at(taskList.at(0).getMachineId());
		machine.updateEndTime(taskList.at(0).getTijdsduur());
		job.updateEndTime(machine.getEndTime());


		}

		//remove the Task to prevent double scheduling
		taskList.erase(taskList.begin());

		//if the Job has no tasks remaining
		if (taskList.empty())
		{
			//remove the Job
			//JobList.erase(JobList.begin()+job.getId());
			//update jobsRemaining
			jobsRemaining--;
		}
	}

	if (jobsRemaining == 0)
	{
		// Should be inserted into file!
		for (unsigned int i = 0; i < JobList.size(); i++)
		{
			std::cout << i << " " << JobList.at(i).getStarttime() << " " << JobList.at(i).getEndtime() << std::endl;
		}
	}
}
