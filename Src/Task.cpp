#include "Task.h"

Task::Task():mPeriod(0), mExecutionTime(0), mPriority(0), mResponseTime(0)
{

}

Task::Task(const unsigned int period, const unsigned int executionTime):mPeriod(period), mExecutionTime(executionTime), mPriority(0), mResponseTime(0)
{
}

Task& Task::operator=(const Task& task)
{
	if(this != &task){
		mExecutionTime = task.getExecutionTime();
		mPeriod = task.getPeriod();
		mPriority = task.getPriority();
		mResponseTime = task.getResponseTime();
	}
	return *this;
}


