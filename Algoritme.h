/*
 * Algoritme.h
 *
 *  Created on: 10 mrt. 2017
 *      Author: Willem
 */

#ifndef ALGORITME_H_
#define ALGORITME_H_

#include <vector>
#include "job.h"

class Algoritme
{
public:
	Algoritme();
	virtual ~Algoritme();
	int calculateCriticalPath(std::vector<Job> JobList);
	Task& calculateLeastSlack(std::vector<Job> JobList, int criticalPath);
	int criticalPath;
};

#endif /* ALGORITME_H_ */
