/**********************************************************/
/*** Title: Landscaping.cpp    					        ***/
/*** Description: CPET-321 Labs #4 - Fall 2023          ***/
/*** Name: Weicheng Huang                               ***/
/**********************************************************/
#include "Plant.h"
#include "Flower.h"
#include "Tree.h"
#include <vector>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <cstdlib>		

using namespace std;
using namespace plant;
using namespace flower;
using namespace tree;

ifstream OpenInputFile()
{   
    //**** Step #1 ****/
    // Opens the input file yard_plants.txt reate a vector
    // of object Flower that contains all the flowers
    // that are (i) Annuals and (ii) Cost Less-Than $10.00
    // 
    // Once created, print-out all the flowers in the vector
    string inFileName = "yard_plants.txt";
    ifstream temp;

    temp.open(inFileName.c_str());

    if (!temp.is_open()) {
        cout << "\nUnsuccessfully... Program Terminated\n" << endl;
        exit(1);
    }
    return (temp);
}

int main() 
{

    //**** Step #1 ****/
    // Opens the input file yard_plants.txt, read the plant information
    // and builds the two vectors myFlowers and myTrees.
    // 
    // After the two vectors are build, the information all the flowers,
    // and then all the trees, will be printed
    //   
    // If the files does not exist, the program terminates.

    ifstream inFile;
    inFile = OpenInputFile();

    vector<Flower> myFlowers;
    string flowerName;
    float flowerCost;
    string flowerColor;
    bool isAnnual; 
 
    vector<Tree> myTrees;
    string treeName;
    float treeCost;
    bool isDeciduous;  

    char flower_or_tree;

    Flower tempFlower;
    Tree tempTree;

    while (inFile.good()) {
        inFile >> flower_or_tree;
        if (tolower(flower_or_tree) == 'f')
        {
            inFile >> flowerName >> flowerCost >> flowerColor >> isAnnual;
            tempFlower.SetPlantName(flowerName);
            tempFlower.SetPlantCost(flowerCost);
            tempFlower.SetFlowerColor(flowerColor);
            tempFlower.SetFlowerType(isAnnual);
            myFlowers.push_back(tempFlower);
        }
        else if (tolower(flower_or_tree) == 't')
        {
            inFile >> treeName >> treeCost >> isDeciduous;
            tempTree.SetPlantName(treeName);
            tempTree.SetPlantCost(treeCost);
            tempTree.SetTreeType(isDeciduous);
            myTrees.push_back(tempTree);
        }
    }

    /** Prints the information on all the flowers **/
    cout << "**** ALL THE FLOWERS ****" << endl;
    for (int i = 0; i < myFlowers.size(); ++i) {
        myFlowers.at(i).PrintFlowerInfo();
    }

    /** Prints the information on all the tree **/
    cout << "**** ALL THE TREES ****" << endl;
    for (int i = 0; i < myTrees.size(); ++i) {
        myTrees.at(i).PrintTreeInfo();
    }


    //**** Step #2 ****/
    // Create a vector of object Flower that contains all the flowers
    // that are (i) Annuals and (ii) Cost Less-Than $10.00
    // 
    // Once created, print-out all the flowers in the vector

    // YOUR CODE GOES HERE

    vector<Flower> cheapAnnualFlowers;

    for (int i = 0; i < myFlowers.size(); i++) {
        if (myFlowers[i].GetFlowerType() == true && myFlowers[i].GetPlantCost() < 10) {
            cheapAnnualFlowers.push_back(myFlowers[i]);
        }
    }

    cout << "**** ALL CHEAP, ANNUAL FLOWERS ****" << endl;
    for (int i = 0; i < cheapAnnualFlowers.size(); ++i) {
        cheapAnnualFlowers.at(i).PrintFlowerInfo();
    }

    //**** Step #3 ****/
    // Create a vector of object Flower that contains all the flowers
    // that are (i) Perennials and (ii) Cost More-Than $20.00
    // 
    // Once created, print-out all the flowers in the vector

    // YOUR CODE GOES HERE

    vector<Flower> expensivePerennialsFlowers;

    for (int i = 0; i < myFlowers.size(); i++) {
        if (myFlowers[i].GetFlowerType() == false && myFlowers[i].GetPlantCost() > 20) {
            expensivePerennialsFlowers.push_back(myFlowers[i]);
        }
    }

    cout << "**** ALL EXPENSIVE, PERENNIAL FLOWERS ****" << endl;
    for (int i = 0; i < expensivePerennialsFlowers.size(); ++i) {
        expensivePerennialsFlowers.at(i).PrintFlowerInfo();
    }

    //**** Step #4 ****/
    // Create a vector of object Flower that contains all the flowers
    // that are (i) RED or (ii) PINK
    // 
    // Once created, print-out all the flowers in the vector

    // YOUR CODE GOES HERE

    vector<Flower> redAndPinkFlowers;

    for (int i = 0; i < myFlowers.size(); i++) {
        if (myFlowers[i].GetFlowerColor() == "red" || myFlowers[i].GetFlowerColor() == "pink") {
            redAndPinkFlowers.push_back(myFlowers[i]);
        }
    }

    cout << "**** ALL RED & PINK FLOWERS ****" << endl;
    for (int i = 0; i < redAndPinkFlowers.size(); ++i) {
        redAndPinkFlowers.at(i).PrintFlowerInfo();
    }

    //**** Step #5 ****/
    // Create a vector of object Trees that contains all the 
    // Deciduous trees that cost between $100 and $200 
    // 
    // Once created, print-out all the Trees in the vector

    // YOUR CODE GOES HERE

    vector<Tree> deciduousMidrangeTrees;

    for (int i = 0; i < myTrees.size(); i++) {
        if (myTrees[i].GetTreeType() == true) {
            if (myTrees[i].GetPlantCost() > 100 && myTrees[i].GetPlantCost() < 200) {
                deciduousMidrangeTrees.push_back(myTrees[i]);
            }
        }
    }

    cout << "**** ALL MIDRANGE DECIDUOUS TREES ****" << endl;
    for (int i = 0; i < deciduousMidrangeTrees.size(); ++i) {
        deciduousMidrangeTrees.at(i).PrintTreeInfo();
    }

    return 0;
}