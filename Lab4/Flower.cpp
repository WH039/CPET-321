#include "Plant.h"
#include "Flower.h"

using namespace flower;

Flower::Flower() {}

void Flower::SetFlowerColor(string flowerColor) { // sets flower color
	color = flowerColor;
}

string Flower::GetFlowerColor() { // returns flower color
	return color;
}

void Flower::SetFlowerType(bool flowerType) { // sets flower type
	isAnnual = flowerType;
}

bool Flower::GetFlowerType() const { // returns flower type
	return isAnnual;
}

void Flower::PrintFlowerInfo() const {
	cout << "**** FLOWER ****" << endl;
	PrintPlantInfo();
	cout << "   Annual: " << boolalpha << isAnnual << endl;
	cout << "   Color: " << color << endl << endl;
}