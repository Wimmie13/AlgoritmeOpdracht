/*
 * Input.h
 *
 *  Created on: 10 mrt. 2017
 *      Author: Willem
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <fstream>
#include <vector>
#include "JobShop.h"

class Input
{
public:
	typedef int type_input;
	Input(const std::string& filename)
	{
		std::string testfile = "testFile.test";
		std::string test =
				"6 6\n2 1 0 3 1 6 3 7 5 3 4 6\n1 8 2 5 4 10 5 10 0 10 3 4\n2 5 3 4 5 8 0 9 1 1 4 7\n1 5 0 5 2 5 3 3 4 8 5 9\n2 9 1 3 4 5 5 4 0 3 3 1\n1 3 3 3 5 9 0 10 4 4 2 1";
		std::ofstream(testfile, std::ios::binary) << test;
		std::ifstream input(testfile);
		std::string line;
		std::regex line_regex("[0-9]+");
		while (getline(input, line))
		{
			std::smatch match;
			std::vector<type_input> newLine;
			while (std::regex_search(line, match, line_regex))
			{
				newLine.push_back(std::stoi(match.str()));
				line = match.suffix();
			}
			if (info.empty())
			{
				info = newLine;
			}
			else
			{
				std::vector<Task> newTaskList;
				for (int i = 0; i < newLine.size(); i += 2)
				{
					newTaskList.push_back(
							Task(newTaskList.size(), newLine.at(i),
									newLine.at(i + 1)));
				}
				jobs.push_back(newTaskList);
			}
		}
	}
	virtual ~Input();
	void generateJobs(JobShop& jobShop);
	const int getAmountOfMachines();
	const int getAmountOfJobs();
private:
	std::vector<type_input> info;
	std::vector<std::vector<Task>> jobs;
};

#endif /* INPUT_H_ */
