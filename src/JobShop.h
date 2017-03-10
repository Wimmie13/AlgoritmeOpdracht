/*
 * JobShop.h
 *
 *  Created on: 10 mrt. 2017
 *      Author: Willem
 */

#ifndef JOBSHOP_H_
#define JOBSHOP_H_

#include <vector>
#include "Job.h"

class JobShop
{
public:
	JobShop();
	virtual ~JobShop();
private:
	std::vector<Job> JobList;
};

#endif /* JOBSHOP_H_ */
