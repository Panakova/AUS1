#include <libds/heap_monitor.h>
//#include <libds/amt/implicit_sequence.h>

//#include "readingManager.h"
#include "Manager.h"
#include "Alg.h"

#include <Windows.h>

int main() {

	initHeapMonitor();

	SetConsoleCP(1250);
	SetConsoleOutputCP(1250);
	setlocale(LC_ALL, "SK");

	Manager* manager = new Manager();

	manager->readFromCSV("C:/Users/RPanakova/Documents/kraje.csv", KRAJ);
	manager->readFromCSV("C:/Users/RPanakova/Documents/okresy.csv", OKRES);
	manager->readFromCSV("C:/Users/RPanakova/Documents/obce.csv", OBEC);

	bool exit = false;

	while (!exit)
	{
		std::cout << "- - - - - Slovak register - - - - -" << std::endl;
		std::cout << "Press nuber to select: " << std::endl;
		std::cout << "1 .. Area name contains substring" << std::endl;
		std::cout << "2 .. Area name starts with substring" << std::endl;
		std::cout << "3 .. End" << std::endl;
		std::string option;
		std::string wanted;
		std::cin >> option;
		ds::amt::ImplicitSequence<Area*>* find = nullptr;

		if (option == "1")
		{
			std::cout << "Name should contains: " << std::endl;
			std::cin.ignore();
			std::getline(std::cin, wanted);
			std::cout << "Searching for area with string " << wanted << "\n " << std::endl;
			manager->findInSeq_Contains(wanted, 1);
			manager->findInSeq_Contains(wanted, 2);
			manager->findInSeq_Contains(wanted, 3);
		}
		else if (option == "2")
		{
			std::cout << "Name should starts with: " << std::endl;
			std::cin.ignore();
			std::getline(std::cin, wanted);
			std::cout << "Searching for area with string " << wanted << "\n " << std::endl;
			manager->findInSeq_Starts(wanted, 1);
			manager->findInSeq_Starts(wanted, 2);
			manager->findInSeq_Starts(wanted, 3);
		}
		else if (option == "3")
		{
			std::cout << "Program exit " << std::endl;
			exit = true;
		}
		else
			std::cout << "Sorry couldn't understand :(";
	}

	delete manager;
}



