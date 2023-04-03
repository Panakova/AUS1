#pragma once
#include <libds/amt/implicit_sequence.h>
#include <string>
#include "Area.h"

class Alg
{
public:
	Alg();
	~Alg();

	static ds::amt::ImplicitSequence<Area*>* findContainsSting(std::string text, ds::amt::ImplicitSequence<Area> *area ) {

		ds::amt::ImplicitSequence<Area*>* find = new ds::amt::ImplicitSequence<Area*>();

		area->processAllBlocksForward([&](ds::amt::MemoryBlock<Area>* block)->void {

			std::string name = block->data_.getOfficialName();

			std::transform(text.begin(), text.end(), text.begin(), ::tolower);
			std::transform(name.begin(), name.end(), name.begin(), ::tolower);

			if (name.find(text) != std::string::npos)
			{
				find->insertLast().data_ = &block->data_;
			}
			});
		return find;
	};

	static ds::amt::ImplicitSequence<Area*>* findStartWithSting(std::string text, ds::amt::ImplicitSequence<Area>* area) {

		ds::amt::ImplicitSequence<Area*>* find = new ds::amt::ImplicitSequence<Area*>();

		area->processAllBlocksForward([&](ds::amt::MemoryBlock<Area>* block)->void {

			std::string name = block->data_.getOfficialName();

			std::transform(text.begin(), text.end(), text.begin(), ::tolower);
			std::transform(name.begin(), name.end(), name.begin(), ::tolower);

			if (name.rfind(text, 0) != std::string::npos)
			{
				find->insertLast().data_ = &block->data_;
			}
			});
		return find;
	};

private:

};

Alg::Alg()
{
}

Alg::~Alg()
{
}