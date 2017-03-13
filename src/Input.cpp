/*
 * Input.cpp
 *
 *  Created on: 10 mrt. 2017
 *      Author: Willem
 */

#include "Input.h"

Input::Input(const std::string& aFilename) :
		filename(aFilename)
{
	// TODO Auto-generated constructor stub

}

Input::~Input()
{
	// TODO Auto-generated destructor stub
}

const std::string& Input::getFilename() const
{
	return filename;
}
