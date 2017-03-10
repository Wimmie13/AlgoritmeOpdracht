/*
 * Task.h
 *
 *  Created on: 10 mrt. 2017
 *      Author: Willem
 */

#ifndef TASK_H_
#define TASK_H_

#include "Machine.h"

class Task
{
public:
	Task(Machine& aMachine, unsigned short aTijdsduur);
	virtual ~Task();
private:
	Machine& machine;
	unsigned short tijdsduur;
};

#endif /* TASK_H_ */
