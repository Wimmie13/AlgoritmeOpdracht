/*
 * Job.h
 *
 *  Created on: 10 mrt. 2017
 *      Author: Willem
 */

#ifndef JOB_H_
#define JOB_H_

#include <vector>
#include "Task.h"

class Job
{
public:
	Job(unsigned short anId);
	virtual ~Job();
private:
	std::vector<Task> TaskList;
	unsigned short id;
};

#endif /* JOB_H_ */
