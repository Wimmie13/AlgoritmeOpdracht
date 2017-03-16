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
	Machine(int id);
	virtual ~Machine();
	int getEndTime() const;
	void setEndTime(int time);
	void updateEndTime(int time);
private:
	int endTime;
	type_machine id;
};

#endif /* MACHINE_H_ */
