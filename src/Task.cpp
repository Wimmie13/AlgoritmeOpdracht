/*
 * Task.cpp
 *
 *  Created on: 10 mrt. 2017
 *      Author: Willem
 */

#include "Task.h"
#include <iostream>

Task::Task(type_task anId, type_machine aMachineId, type_task aTijdsduur) :
		id(anId), machineId(aMachineId), tijdsduur(aTijdsduur)
{
	// TODO Auto-generated constructor stub
}

Task::~Task()
{
	// TODO Auto-generated destructor stub
}

void Task::printData()
{
	std::cout << "Task ID: " << id << " Machine: " << machineId << " duur: "
			<< tijdsduur << std::endl;
}

Task::type_machine Task::getTijdsduur()
{
	return tijdsduur;
}

int Task::getMachineId() const
{
	return machineId;
}
