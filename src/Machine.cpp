/*
 * Machine.cpp
 *
 *  Created on: 16 mrt. 2017
 *      Author: Willem
 */

#include "Machine.h"

Machine::Machine() :
		time(0)
{
	// TODO Auto-generated constructor stub

}

Machine::~Machine()
{
	// TODO Auto-generated destructor stub
}

Machine::type_machine Machine::getTime() const
{
	return time;
}

void Machine::setTime(type_machine time)
{
	this->time = time;
}

