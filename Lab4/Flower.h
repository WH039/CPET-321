#pragma once

#include "Plant.h"

using namespace plant;

namespace flower {
	class Flower : public Plant {
	private:
		string color;
		bool isAnnual;

	public:
		Flower(); // default constructor
		
		void SetFlowerColor(string);
		string GetFlowerColor();
		void SetFlowerType(bool);
		bool GetFlowerType() const;
		void PrintFlowerInfo() const;

	};
}