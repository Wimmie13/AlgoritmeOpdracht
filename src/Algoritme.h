/*
 * Algoritme.h
 *
 *  Created on: 10 mrt. 2017
 *      Author: Willem
 */

#ifndef ALGORITME_H_
#define ALGORITME_H_

#include <vector>
#include "JobShop.h"

class Algoritme
{
public:
	Algoritme(JobShop& aJobShop);
	virtual ~Algoritme();
	int calculateCriticalPath(std::vector<Job>&JobList);
	int calculateLeastSlack(std::vector<Job> JobList);
	void generateResults();
private:
	JobShop jobShop;
};

#endif /* ALGORITME_H_ */
