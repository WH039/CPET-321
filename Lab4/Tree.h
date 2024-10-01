#pragma once

#include "Plant.h"

using namespace plant;

namespace tree {
	class Tree : public Plant {
	private:
		bool isDeciduous;

	public:
		Tree(); // default constructor

		void SetTreeType(bool);
		bool GetTreeType() const;
		void PrintTreeInfo() const;

	};
}