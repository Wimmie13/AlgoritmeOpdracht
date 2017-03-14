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
		lines.push_back(newLine);
	}
}

Input::~Input()
{
	// TODO Auto-generated destructor stub
}

void Input::generateJobs(JobShop& jobShop)
{

}

const Input::type_input Input::getAmountOfMachines()
{
	return lines.at(0).at(1);
}

const Input::type_input Input::getAmountOfJobs()
{
	return lines.at(0).at(1);
}
