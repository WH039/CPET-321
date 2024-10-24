/**********************************************************/
/*** Title: linetype.h        					        ***/
/*** Description: CPET-321 Labs #5 - Fall 2023          ***/
/*** Name: Weicheng Huang                               ***/
/**********************************************************/

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
#include <math.h>
#include <cmath>

using namespace std;

namespace LINETYPE {
	class lineType {
	private:
		float a;
		float b;
		float c;

	public:
		lineType();
		void setCoefficient(float, float, float);
		void displayLine();
		void lineSlope();
		bool operator==(lineType&);
		bool operator||(lineType&);
		bool operator&&(lineType&);
		void lineIntersection(lineType&);

	};
}