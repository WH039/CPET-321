/**********************************************************/
/*** Title: main.cpp    					            ***/
/*** Description: CPET-321 Labs #5 - Fall 2023          ***/
/*** Name: Weicheng Huang                               ***/
/**********************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
#include <math.h>
#include <cmath>

#include "lineType.h"

using namespace std;
using namespace LINETYPE;

int main() {

	int func, input1, input2;
	float a, b, c;
	bool check = false;
	lineType line0, line1, line2, line3;

	cout << "1 (Set Coefficients)" << endl;
	cout << "2 (Diplay Line)" << endl;
	cout << "3 (Display All Lines)" << endl;
	cout << "4 (Display Line Slope)" << endl;
	cout << "5 (Check if Lines are Equal)" << endl;
	cout << "6 (Check if Lines are Parallel)" << endl;
	cout << "7 (Check if Lines are Perpendicular)" << endl;
	cout << "8 (Check if Lines are Intersecting)" << endl;
	cout << "0 (End Program)" << endl;
	cout << "Please select your function" << endl;
	cin >> func;

	while (func != 0) {
		system("pause");
		system("CLS");

		switch (func) {
		case 1:
			//Set coefficients

			cout << "Please select your Line (0, 1, 2, 3)" << endl;
			cin >> input1;
			if (input1 == 0) {
				cout << "Please input the coefficients of the line" << endl;
				cout << "a = ";
				cin >> a;
				cout << endl;

				cout << "b = ";
				cin >> b;
				cout << endl;

				cout << "c = ";
				cin >> c;
				cout << endl;

				line0.setCoefficient(a, b, c);
			}
			else if (input1 == 1) {
				cout << "Please input the coefficients of the line" << endl;
				cout << "a = ";
				cin >> a;
				cout << endl;

				cout << "b = ";
				cin >> b;
				cout << endl;

				cout << "c = ";
				cin >> c;
				cout << endl;

				line1.setCoefficient(a, b, c);
			}
			else if (input1 == 2) {
				cout << "Please input the coefficients of the line" << endl;
				cout << "a = ";
				cin >> a;
				cout << endl;

				cout << "b = ";
				cin >> b;
				cout << endl;

				cout << "c = ";
				cin >> c;
				cout << endl;

				line2.setCoefficient(a, b, c);
			}
			else if (input1 == 3) {
				cout << "Please input the coefficients of the line" << endl;
				cout << "a = ";
				cin >> a;
				cout << endl;

				cout << "b = ";
				cin >> b;
				cout << endl;

				cout << "c = ";
				cin >> c;
				cout << endl;

				line3.setCoefficient(a, b, c);
			}
			system("pause");
			system("CLS");

			break;

		case 2:
			//Display Line

			cout << "Please select your Line (0, 1, 2, 3)" << endl;
			cin >> input1;
			if (input1 == 0) {
				cout << "Displaying line0: ";
				line0.displayLine();
				cout << endl;
			}
			else if (input1 == 1) {
				cout << "Displaying line1: ";
				line1.displayLine();
				cout << endl;
			}
			else if (input1 == 2) {
				cout << "Displaying line2: ";
				line2.displayLine();
				cout << endl;
			}
			else if (input1 == 3) {
				cout << "Displaying line3: ";
				line3.displayLine();
				cout << endl;
			}

			system("pause");
			system("CLS");

			break;

		case 3:
			//Displaying all lines

			cout << "Displaying all lines: " << endl;
			line0.displayLine();
			line1.displayLine();
			line2.displayLine();
			line3.displayLine();
			cout << endl;

			system("pause");
			system("CLS");

			break;

		case 4:
			//Slope

			cout << "Please Select your Line (0, 1, 2, 3)" << endl;
			cin >> input1;
			if (input1 == 0) {
				cout << "Line0 ";
				line0.lineSlope();
			}
			else if (input1 == 1) {
				cout << "Line1 ";
				line1.lineSlope();
			}
			else if (input1 == 2) {
				cout << "Line2 ";
				line2.lineSlope();
			}
			else if (input1 == 3) {
				cout << "Line3 ";
				line3.lineSlope();
			}

			system("pause");
			system("CLS");

			break;

		case 5:
			//Equal

			cout << "Please select two lines (0, 1, 2, 3)" << endl;

			cout << "Line";
			cin >> input1;
			cout << endl;

			cout << "Line";
			cin >> input2;
			cout << endl;

			if (input1 == 0) {
				if (input2 == 1) {
					line0==line1;
					
				}
				else if (input2 == 2) {
					line0==line2;
					
				}
				else if (input2 == 3) {
					line0==line3;
					
				}
			}
			else if (input1 == 1) {
				if (input2 == 0) {
					line1==line0;
					
				}
				else if (input2 == 2) {
					line1==line2;
					
				}
				else if (input2 == 3) {
					line1==line3;
					
				}
			}
			else if (input1 == 2) {
				if (input2 == 0) {
					line2==line0;
					
				}
				else if (input2 == 1) {
					line2==line1;
					
				}
				else if (input2 == 3) {
					line2==line3;
					
				}
			}
			else if (input1 == 3) {
				if (input2 == 0) {
					line3==line0;
					
				}
				else if (input2 == 1) {
					line3==line1;
					
				}
				else if (input2 == 2) {
					line3 == line2;
					
				}
			}

			system("pause");
			system("CLS");

			break;

		case 6:
			//Parallel

			cout << "Please select two lines (0, 1, 2, 3)" << endl;

			cout << "Line";
			cin >> input1;
			cout << endl;

			cout << "Line";
			cin >> input2;
			cout << endl;

			if (input1 == 0) {
				if (input2 == 1) {
					line0||line1;
					
				}
				else if (input2 == 2) {
					line0||line2;
					
				}
				else if (input2 == 3) {
					line0||line3;
					
				}
			}
			else if (input1 == 1) {
				if (input2 == 0) {
					line1||line0;
					
				}
				else if (input2 == 2) {
					line1||line2;
					
				}
				else if (input2 == 3) {
					line1||line3;
					
				}
			}
			else if (input1 == 2) {
				if (input2 == 0) {
					line2||line0;
					
				}
				else if (input2 == 1) {
					line2||line1;
					
				}
				else if (input2 == 3) {
					line2||line3;
					
				}
			}
			else if (input1 == 3) {
				if (input2 == 0) {
					line3||line0;
					
				}
				else if (input2 == 1) {
					line3||line1;
					
				}
				else if (input2 == 2) {
					line3||line2;
					
				}
			}

			system("pause");
			system("CLS");

			break;

		case 7:
			//Perpendicular

			cout << "Please select two lines (0, 1, 2, 3)" << endl;

			cout << "Line";
			cin >> input1;
			cout << endl;

			cout << "Line";
			cin >> input2;
			cout << endl;

			if (input1 == 0) {
				if (input2 == 1) {
					line0&&line1;
					
				}
				else if (input2 == 2) {
					line0&&line2;
					
				}
				else if (input2 == 3) {
					line0&&line3;
					
				}
			}
			else if (input1 == 1) {
				if (input2 == 0) {
					line1&&line0;
					
				}
				else if (input2 == 2) {
					line1&&line2;
					
				}
				else if (input2 == 3) {
					line1&&line3;
					
				}
			}
			else if (input1 == 2) {
				if (input2 == 0) {
					line2&&line0;
					
				}
				else if (input2 == 1) {
					line2&&line1;
					
				}
				else if (input2 == 3) {
					line2&&line3;
					
				}
			}
			else if (input1 == 3) {
				if (input2 == 0) {
					line3&&line0;
					
				}
				else if (input2 == 1) {
					line3&& line1;

				}
				else if (input2 == 2) {
					line3&&line2;
					
				}
			}

			system("pause");
			system("CLS");

			break;

		case 8:
			//Intersection

			cout << "Please select two lines (0, 1, 2, 3)" << endl;

			cout << "Line";
			cin >> input1;
			cout << endl;

			cout << "Line";
			cin >> input2;
			cout << endl;

			if (input1 == 0) {
				if (input2 == 1) {
					line0.lineIntersection(line1);
				}
				else if (input2 == 2) {
					line0.lineIntersection(line2);
				}
				else if (input2 == 3) {
					line0.lineIntersection(line3);
				}
			}
			else if (input1 == 1) {
				if (input2 == 0) {
					line1.lineIntersection(line0);
				}
				else if (input2 == 2) {
					line1.lineIntersection(line2);
				}
				else if (input2 == 3) {
					line1.lineIntersection(line3);
				}
			}
			else if (input1 == 2) {
				if (input2 == 0) {
					line2.lineIntersection(line0);
				}
				else if (input2 == 1) {
					line2.lineIntersection(line1);
				}
				else if (input2 == 3) {
					line2.lineIntersection(line3);
				}
			}
			else if (input1 == 3) {
				if (input2 == 0) {
					line3.lineIntersection(line0);
				}
				else if (input2 == 1) {
					line3.lineIntersection(line1);
				}
				else if (input2 == 2) {
					line3.lineIntersection(line2);
				}
			}

			system("pause");
			system("CLS");

			break;

		case 0:
			exit(0);
			break;

		}

		cout << "1 (Set Coefficients)" << endl;
		cout << "2 (Diplay Line)" << endl;
		cout << "3 (Display All Lines)" << endl;
		cout << "4 (Display Line Slope)" << endl;
		cout << "5 (Check if Lines are Equal)" << endl;
		cout << "6 (Check if Lines are Parallel)" << endl;
		cout << "7 (Check if Lines are Perpendicular)" << endl;
		cout << "8 (Check if Lines are Intersecting)" << endl;
		cout << "0 (End Program)" << endl;
		cout << "Please select your function" << endl;
		cin >> func;
	}
}

