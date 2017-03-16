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
	std::vector<Task>& getTaskList();
	type_job getEndtime() const;
	void setEndTime(int endtime);
	void updateEndTime(int time);
	type_job getStarttime() const;
	void setStarttime(type_job starttime);
	type_job getId();
private:
	type_job id, starttime, endtime;
	std::vector<Task> taskList;
};

#endif /* JOB_H_ */
