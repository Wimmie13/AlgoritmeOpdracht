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

	for (int i = JobList.size() - 1; i >= 0; i--)
	{
		auto taskList = JobList.at(i).getTaskList();
		int leastSlackJob = criticalPath;

		for (int j = taskList.size() - 1; j >= 0; j--)
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
	int currentTime = 0, jobsRemaining = JobList.size();

	while (jobsRemaining != 0)
	{
		auto& job = JobList.at(calculateLeastSlack(JobList));

		if (job.getStarttime() == -1)
		{
			job.setStarttime(currentTime);
		}

		// Set the tasklist of the job with the least slack, add the time and erase.
		auto& taskList = job.getTaskList();
		currentTime += taskList.at(0).getTijdsduur();

		if (taskList.size() == 1)
		{
			job.setEndtime(currentTime);
			jobsRemaining--;
		}

		taskList.erase(taskList.begin());
	}

	// Should be inserted into file!
	for (unsigned int i = 0; i < JobList.size(); i++)
	{
		std::cout << i << " " << JobList.at(i).getStarttime() << " "
				<< JobList.at(i).getEndtime() << std::endl;
	}
}
