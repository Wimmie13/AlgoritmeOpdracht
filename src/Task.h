/*
 * Task.h
 *
 *  Created on: 10 mrt. 2017
 *      Author: Willem
 */

#ifndef TASK_H_
#define TASK_H_

class Task
{
public:
	Task(unsigned short aTijdsduur);
	virtual ~Task();
private:
	unsigned short tijdsduur;
};

#endif /* TASK_H_ */