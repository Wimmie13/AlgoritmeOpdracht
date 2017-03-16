/*
 * Machine.h
 *
 *  Created on: 16 mrt. 2017
 *      Author: Willem
 */

#ifndef MACHINE_H_
#define MACHINE_H_

class Machine
{
public:
	typedef int type_machine;
	Machine();
	virtual ~Machine();
	type_machine getTime() const;
	void setTime(type_machine time);
private:
	type_machine time;
};

#endif /* MACHINE_H_ */
