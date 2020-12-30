#include "src/task_set/task_set.h"

int main(void) {

	int choice;
	std::string filename;

	std::cout << "1 Response Time Analysis schedulability test" << std::endl;
	std::cout << "2 Interference schedulability test" << std::endl;
	std::cout << "3 Liu and Layland schedulability test" << std::endl;
	std::cout << "4 Apply rate monotonic" << std::endl;
	std::cout << "5 Apply deadline monotonic" << std::endl;
	std::cout << "6 Save set on file" << std::endl;
	std::cout << "7 Print set values" << std::endl;
	std::cout << "8 Read from file" << std::endl;
	std::cout << "9 Show this menu" << std::endl;
	std::cout << "0 Exit the program" << std::endl;


	
	std::cout << "Insert a filename: ";
	std::cin >> filename;

	static TaskSet *set = new TaskSet;

	bool init = set->loadTasks(filename);

	do
	{
		if (!init) {
			std::cout << "Unable to load tasks: invalid filename" << std::endl;
			break;
		}
		else {
			std::cout << "Choose what to do: ";
			std::cin >> choice;
		}

		switch (choice)
		{
		case 0:
			std::cout << "Program terminated" << std::endl;
			choice = 0;
			break;

		case 1: 
			if (set->doResponseTimeAnalysis())
				std::cout << "Schedulable set" << std::endl;
			else
			{
				std::cout << "Unschedulable set" << std::endl;
			}
			break;
		
		case 2: 

			if (set->doInterferenceTest())
				std::cout << "Schedulable set" << std::endl;
			else
			{
				std::cout << "Unschedulable set" << std::endl;
			}

			break;
		
		case 3: 
			if (set->doLiuLaylandTest())
				std::cout << "Schedulable set" << std::endl;
			else
			{
				std::cout << "Unschedulable set" << std::endl;
			}

			break;
		
		case 6: 
			std::cout << "Enter filename [results]: ";
			std::cin >> filename;

			if (!set->save(filename) ){
				std::cout << "Could not save on file!" << std::endl;
			}
			break;
		

		case 7: 
			std::cout << "\t******TASK PRINTING******" << std::endl;
			std::cout << "Utilization factor: " << set->getUtilizationFactor() << std::endl;
			std::cout << "Task\tPer\tDeadln\tWCET\tRT\tInt" << std::endl;
			std::cout << *set << std::endl;
			std::cout << "\t******DONE PRINTING******" << std::endl;
			break;
		
		case 8: 
			std::cout << "Enter filename: ";
			std::cin >> filename;
			init = set->loadTasks(filename);
			break;
		
		case 4: 
			set->applyRateMonotonic();
			break;
		
		case 5: 
			set->applyDeadlineMonotonic();
			break;
		
		case 9: 
			std::cout << "1 Response Time Analysis schedulability test" << std::endl;
			std::cout << "2 Interference schedulability test" << std::endl;
			std::cout << "3 Liu and Layland schedulability test" << std::endl;
			std::cout << "4 Apply rate monotonic" << std::endl;
			std::cout << "5 Apply deadline monotonic" << std::endl;
			std::cout << "6 Save set on file" << std::endl;
			std::cout << "7 Print set values" << std::endl;
			std::cout << "8 Read from file" << std::endl;
			std::cout << "9 Show this menu" << std::endl;
			std::cout << "0 Exit the program" << std::endl;
			break;
		
		default:
			std::cout << "Program terminated" << std::endl;
			choice = 0;
			break;
		
		}
	} while (choice);
	
	
	
	delete set;
	return 0;
}