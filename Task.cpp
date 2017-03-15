/*
 * Task.cpp
 *
 *  Created on: 10 mrt. 2017
 *      Author: Willem
 */

#include "Task.h"
#include <iostream>

Task::Task(type_task anId, type_machine aMachine, type_task aTijdsduur) :
		id(anId), machine(aMachine), tijdsduur(aTijdsduur), finished(false)
{
	// TODO Auto-generated constructor stub
}

Task::~Task()
{
	// TODO Auto-generated destructor stub
}

void Task::printData()
{
	std::cout << "Task ID: " << id << " Machine: " << machine << " duur: "
			<< tijdsduur << std::endl;
}

int Task::getTijdsduur() {
	return tijdsduur;
}
