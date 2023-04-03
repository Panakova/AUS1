#pragma once
#include <libds/amt/implicit_sequence.h>
#include <libds/adt/list.h>
#include <fstream>
#include <vector>
#include <string>
#include "Area.h"
#include "Alg.h"
#include <Windows.h>


enum type_objects {
	OBEC, KRAJ, OKRES
};

class Manager
{
private:

	ds::amt::ImplicitSequence<Area> kraje;
	ds::amt::ImplicitSequence<Area> okresy;
	ds::amt::ImplicitSequence<Area> obce;



public:
	Manager() {
		SetConsoleCP(1250);
		SetConsoleOutputCP(1250);
		setlocale(LC_ALL, "SK");
	};
	~Manager() {
		
		kraje.processAllBlocksForward([&](ds::amt::MemoryBlock<Area>* block) {
			if (kraje.accessNext(*block) != nullptr)
				kraje.removeNext(*block);
			});
		okresy.processAllBlocksForward([&](ds::amt::MemoryBlock<Area>* block) {
			if (okresy.accessNext(*block) != nullptr)
				okresy.removeNext(*block);
			});
		obce.processAllBlocksForward([&](ds::amt::MemoryBlock<Area>* block) {
			if (obce.accessNext(*block) != nullptr)
				obce.removeNext(*block);
			});
			
		

	};

	void writeMembers(ds::amt::ImplicitSequence<Area*> &area) {
		for (auto a : area)
		{
			std::cout << a->getOfficialName() << std::endl;
		}
	};

	void findInSeq_Contains(std::string text, int area) {
		ds::amt::ImplicitSequence<Area*>* find;
		switch (area)
		{
		case 1:
			find = Alg::findContainsSting(text, &kraje);
			break;
		case 2:
			find = Alg::findContainsSting(text, &okresy);
			break;
		default:
			find = Alg::findContainsSting(text, &obce);
			break;
		}
		writeMembers(*find);
		for (auto a : *find)
			a = nullptr;

		delete find;
	}

	void findInSeq_Starts(std::string text, int area) {
		ds::amt::ImplicitSequence<Area*>* find;
		switch (area)
		{
		case 1:
			find = Alg::findStartWithSting(text, &kraje);
			break;
		case 2:
			find = Alg::findStartWithSting(text, &okresy);
			break;
		default:
			find = Alg::findStartWithSting(text, &obce);
			break;
		}
		writeMembers(*find);

		for (auto a : *find)
			a = nullptr;

		delete find;
	}



	void readFromCSV(std::string filename, type_objects druh) {

		std::string hodnota;
		std::string line;

		std::fstream file(filename, std::ios::in);
		if (file.is_open())
		{
			getline(file, line);

			while (getline(file, line))
			{
				std::vector<std::string> riadok;

				std::stringstream str(line);
				while (getline(str, hodnota, ';'))
				{
					riadok.push_back(hodnota);
				}
				 Area a(riadok.at(1), riadok.at(2), riadok.at(3), riadok.at(4), riadok.at(5));
				 switch (druh)
				 {
				 case OBEC:
					 obce.insertLast().data_ = a;
					 break;
				 case KRAJ:
					 kraje.insertLast().data_ = a;
					 break;
				 case OKRES:
					 okresy.insertLast().data_ = a;
					 break;
				 default:
					 break;
				 } 
			}
		}

		
	};


};


