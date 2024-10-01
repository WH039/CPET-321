#include "Plant.h"

using namespace plant;

Plant::Plant(){} // default constructor

void Plant::SetPlantName(string name) { // sets plant name
	plantName = name;
}

string Plant::GetPlantName() { // returns plant name
	
	return plantName;
}

void Plant::SetPlantCost(float cost) { // sets plant cost
	plantCost = cost;
}

float Plant::GetPlantCost() const { // returns plant cost

	return plantCost;
}

void Plant::PrintPlantInfo() const {
	cout << "   Name: " << plantName << endl;
	cout << "   Cost: " << setw(6) << setprecision(4) << plantCost << endl;
}