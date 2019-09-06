#pragma once

#include <iostream>
#include <Semaphore.h>
#include <vector>


class Task {

	//friend
	friend std::ostream& operator<<(std::ostream& out, const Task& task) { return task.print(out); }

private:
	unsigned int mPeriod;
	unsigned int mDeadline;
	unsigned int mExecutionTime;
	unsigned int mResponseTime;

protected:
	std::ostream& print(std::ostream& out)const;

public:
	//constructors
	explicit Task();
	explicit Task(const unsigned int period, const unsigned int deadline,const unsigned int executionTime);
	explicit Task(const Task& task);
	//getters & setters
	inline const unsigned int getPeriod()const { return mPeriod; }
	inline const unsigned int getExecutionTime()const { return mExecutionTime; }
	inline const unsigned int getResponseTime() const { return mResponseTime; }
	inline const unsigned int getDeadline()const { return mDeadline; }
	inline void setResponseTime(const unsigned int responseTime) { mResponseTime = responseTime; }
	//operators
	Task& operator = (const Task& task);
	inline bool operator < (const Task& task)const { return mDeadline < task.getDeadline(); }
	//utilities

	
};
