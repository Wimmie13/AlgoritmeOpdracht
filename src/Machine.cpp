/*
 * Machine.cpp
 *
 *  Created on: 16 mrt. 2017
 *      Author: Willem
 */

#include "Machine.h"

Machine::Machine(int anId) :
		endTime(0), id(anId)
{
	// TODO Auto-generated constructor stub

}

Machine::~Machine()
{
	// TODO Auto-generated destructor stub
}

int Machine::getEndTime() const
{
	return endTime;
}

void Machine::setEndTime(int time)
{
	this->endTime = time;
}

void Machine::updateEndTime(int time) {
	this->endTime += time;
}
