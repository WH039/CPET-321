#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

namespace plant {
	class Plant {
	private:
		string plantName;
		float plantCost;

	public:
		Plant(); // default constructor

		void SetPlantName(string);
		string GetPlantName();
		void SetPlantCost(float);
		float GetPlantCost() const;
		void PrintPlantInfo() const;

	};
}