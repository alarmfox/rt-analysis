#pragma once

#include <ostream>
#include "../task/task.h"
#include "../semaphore/semaphore.h"

class ResourceTask : public Task {

	friend std::ostream& operator<<(std::ostream& out, const ResourceTask& task) { return task.print(out); }

private:
	std::vector<Semaphore> mResourceSemaphores;
	unsigned int mBlockingTime;

protected:
	std::ostream& print(std::ostream& out)const;

public:
	//constructors
	explicit ResourceTask();
	ResourceTask(const unsigned int period, const unsigned int deadline, const unsigned int executionTime, std::vector<Semaphore>& semaphores);
	ResourceTask(const ResourceTask& task);
	//getters setters
	inline const std::vector<Semaphore> getResourceSemaphores()const { return mResourceSemaphores; }
	inline const unsigned int getBlockingTime()const { return mBlockingTime; }
	inline void setResourceSemaphores(const std::vector<Semaphore>& semaphores) { mResourceSemaphores = semaphores; }
	//operators
	ResourceTask& operator = (const ResourceTask& task);
};
