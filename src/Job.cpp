/*
 * Job.cpp
 *
 *  Created on: 10 mrt. 2017
 *      Author: Willem
 */

#include "Job.h"
#include <iostream>

Job::Job(type_job anId, std::vector<Task> anTaskList) :
		id(anId), starttime(-1), endtime(0), taskList(anTaskList)
{
	// TODO Auto-generated constructor stub
	std::cout << "Job met ID: " << id << std::endl;
	for (int i = 0; i != taskList.size(); i++)
	{
		taskList.at(i).printData();
	}

}

Job::~Job()
{
	// TODO Auto-generated destructor stub
}

std::vector<Task>& Job::getTaskList()
{
	return taskList;
}

Job::type_job Job::getEndtime() const
{
	return endtime;
}

void Job::setEndTime(int endtime)
{
	this->endtime = endtime;
}

Job::type_job Job::getStarttime() const
{
	return starttime;
}

void Job::setStarttime(type_job starttime)
{
	this->starttime = starttime;
}

void Job::updateEndTime(int time) {
	if (id == 0)
	std::cout << "Starttime: " << starttime << " Endtime: " << endtime << " Endtime + " << time << std::endl;
	this->endtime += time;
	if (id == 0)
	std::cout << endtime << std::endl;
}

Job::type_job Job::getId() {
	return id;
}
