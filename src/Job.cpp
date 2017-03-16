/*
 * Job.cpp
 *
 *  Created on: 10 mrt. 2017
 *      Author: Willem
 */

#include "Job.h"
#include <iostream>

Job::Job(type_job anId, std::vector<Task> anTaskList) :
		id(anId), taskList(anTaskList)
{
	// TODO Auto-generated constructor stub
	std::cout << "Job met ID: " << id << std::endl;
	for(int i = 0; i != taskList.size(); i++)
	{
		taskList.at(i).printData();
	}

}

Job::~Job()
{
	// TODO Auto-generated destructor stub
}

std::vector<Task> Job::getTaskList() {
	return taskList;
}
