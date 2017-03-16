/*
 * Algoritme.cpp
 *
 *  Created on: 10 mrt. 2017
 *      Author: Willem
 */

#include "Algoritme.h"

Algoritme::Algoritme()
{
	// TODO Auto-generated constructor stub

}

Algoritme::~Algoritme()
{
	// TODO Auto-generated destructor stub
}

int Algoritme::calculateCriticalPath(std::vector<Job> JobList) {
	int criticalPath;

	for (int i = 0; i<JobList.size(); i++){
		int criticalPathJob;
		for (int j = 0; j<JobList.at(i).getTaskList().size(); j++){
			criticalPathJob += JobList.at(i).getTaskList().at(j).getTijdsduur();
		}
		if (criticalPathJob>=criticalPath){
			criticalPath=criticalPathJob;
		}
		criticalPathJob = 0;
	}
	return criticalPath;
}

Task& Algoritme::calculateLeastSlack(std::vector<Job> JobList, int criticalPath) {
	int leastSlack = criticalPath;
	int jobId;
	for (int i=JobList.size(); i>= 0 ; i--){
		int leastSlackJob = criticalPath;
		for (int  j=JobList.at(i).getTaskList().size(); j>=0; j--){
			leastSlackJob -= JobList.at(i).getTaskList().at(j).getTijdsduur();
		}
		if (leastSlackJob<=leastSlack){
			leastSlack=leastSlackJob;
			jobId = i;
		}
		leastSlackJob = criticalPath;
	}
	return JobList.at(jobId).getTaskList().at(0);
}
