/**********************************************************/
/*** Title: linetype.cpp    					        ***/
/*** Description: CPET-321 Labs #5 - Fall 2023          ***/
/*** Name: Weicheng Huang                               ***/
/**********************************************************/

#include "lineType.h"

using namespace LINETYPE;

lineType::lineType() 
{ //default constructor
	a = 1.0;
	b = 1.0;
	c = 1.0;
}

void lineType::setCoefficient(float aValue, float bValue, float cValue) 
{ //sets the values of the coefficient
	a = aValue;
	b = bValue;
	c = cValue;
}

void lineType::displayLine() 
{ //displays the line 
	cout << a << setprecision(2) << " x  + " << b << setprecision(2) << " y =  " << c << setprecision(2) << endl;
}

void lineType::lineSlope() 
{ //displays the slope of the line
	float slope;
	if (a == 0) 
	{
		cout << "Slope = 0" << endl;
	}
	else if (b == 0) 
	{
		cout << "Slope = inf" << endl;
	}
	else if (b != 0) 
	{
		slope = -(a / b);
		cout << "Slope = " << slope << setprecision(2) << endl;
	}
}

bool lineType::operator==(lineType& line)
{ //compares if the lines are equal
	if ((a == line.a) && (b == line.b) && (c == line.c)) 
	{
		cout << "The lines are equal." << endl;
		return true;
	}
	
	else if (a != 0 && line.a != 0) 
	{
		double k1 = a / line.a;
		double k2 = b / line.b;
		double k3 = c / line.c;

		if (k1 == k2 && k2 == k3) {
			return true;
		}
	}

	else 
	{
		cout << "The lines are not equal" << endl;
		return false;
	}
}

bool lineType::operator||(lineType& line)
{ //Determines if the lines are parallel
	float slope1 = -(a / b);
	float slope2 = -(line.a / line.b);
	if (a == 0 && line.a == 0)
	{
		cout << "Both lines are Parallel, horizontally" << endl;
		return true;
	}
	else if (b == 0 && line.b == 0)
	{
		cout << "Both lines are Parallel, vetically" << endl;;
		return true;
	}
	else if (slope1 == slope2)
	{
		cout << "Both lines are Parallel, same slope" << endl;
		return true;
	}
	else 
	{
		cout << "The lines are not Parallel." << endl;
		return false;
	}
}

bool lineType::operator&&(lineType& line)
{ //Determines if the lines are perpendicular
	float slope1 = -(a / b);
	float slope2 = -(line.a / line.b);
	if ((a == 0 && line.b == 0) || (b == 0 && line.a == 0))
	{
		cout << "The lines are Perpendicular" << endl;
		return true;
	}
	
	else if ((slope1 * slope2) == -1)
	{
		cout << "The lines are Perpendicular" << endl;
		return true;
	}
	else
	{
		cout << "The lines are not Perpendicular" << endl;
		return false;
	}
}

void lineType::lineIntersection(lineType& line) 
{ //displays the intersections of two lines
	float slope1 = -(a / b);
	float slope2 = -(line.a / line.b);
	if ((a == 0 && line.a == 0) || (b == 0 && line.b == 0) || (slope1 == slope2))
	{
		cout << "The lines are parallel so they do not intersect" << endl;
	}
	else
	{
		float x, y;

		x = ((c * line.b) - (line.c * b)) / ((a * line.b) - (line.a * b));

		y = (c / b) - ((a / b) * x);

		cout << "The lines intersect at (" << x << ", " << y << ")." << endl;
	}
	
}