#pragma once
#include<iostream>


class Area
{
public:
	Area() {};
	Area(std::string code, std::string officialTitle, std::string mediumTitle, std::string shortTitle, std::string note)
		:code(code), officialTitle(officialTitle), mediumTitle(mediumTitle), shortTitle(shortTitle), note(note) {
		
	};
	~Area();
	std::string getOfficialName() {

		return officialTitle;
	};

	bool containsString(std::string wanted) {
		return officialTitle.find(wanted) != std::string::npos;
	};
	bool startWithString(std::string wanted) {
		return officialTitle.rfind(wanted, 0) != std::string::npos;
	};



private:
	std::string code;
	std::string officialTitle;
	std::string mediumTitle;
	std::string shortTitle;
	std::string note;
	
};


Area::~Area()
{
}
