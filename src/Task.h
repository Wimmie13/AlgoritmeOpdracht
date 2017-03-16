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
	typedef int type_task;
	typedef unsigned short type_machine;
	Task(type_task anId, type_machine aMachineId, type_task aTijdsduur);
	virtual ~Task();
	void printData();
	type_machine getTijdsduur();
	type_machine getMachineId() const;
private:
	type_task id;
	type_machine machineId;
	type_task tijdsduur;
	bool finished;
};

#endif /* TASK_H_ */
