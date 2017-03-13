/*
 * Input.h
 *
 *  Created on: 10 mrt. 2017
 *      Author: Willem
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <fstream>

class Input
{
public:
	Input(const std::string& aFilename);
	virtual ~Input();
	const std::string& getFilename() const;
private:
	std::string filename;
};

#endif /* INPUT_H_ */
