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
	typedef int type_job;
	Job(type_job anId, std::vector<Task> anTaskList);
	virtual ~Job();
	std::vector<Task> getTaskList();
private:
	type_job id;
	std::vector<Task> taskList;
};

#endif /* JOB_H_ */
