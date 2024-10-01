#include "Plant.h"
#include "Tree.h"

using namespace tree;

Tree::Tree(){}

void Tree::SetTreeType(bool type) { // sets tree type
	isDeciduous = type;
}

bool Tree::GetTreeType() const { // returns tree type
	return isDeciduous;
}

void Tree::PrintTreeInfo() const {
	cout << "**** TREE ****" << endl;
	PrintPlantInfo();
	cout << "   Deciducous: " << boolalpha << isDeciduous << endl << endl;
}