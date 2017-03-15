/*
 * Input.cpp
 *
 *  Created on: 10 mrt. 2017
 *      Author: Willem
 */

#include "Input.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <string>
#include <regex>

Input::Input(const std::string& filename)
{
	std::ifstream input(filename);
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
			for (int i = 0; i < newLine.size(); i+=2) {
				newTaskList.push_back(Task(newTaskList.size(), newLine.at(i), newLine.at(i + 1)));
			}
			jobs.push_back(newTaskList);
		}
	}

//	for (int i = 0; i < getAmountOfJobs(); i++)
//	{
//		for (int j = 0; j < jobs.at(i).size(); j++)
//		{
//			std::cout << jobs.at(i).at(j) << " ";
//		}
//		std::cout << std::endl;
//	}
}

Input::~Input()
{
}

void Input::generateJobs(JobShop& jobShop)
{
	for (int i = 0; i < getAmountOfJobs(); i++)
	{
		jobShop.addJob(i, jobs.at(i));
	}
}

const int Input::getAmountOfMachines()
{
	return info.at(1);
}

const int Input::getAmountOfJobs()
{
	return info.at(0);
}
