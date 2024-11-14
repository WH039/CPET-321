////////////////////////////////////////////////////////////////////////////////////////////////////
/// File Name   : Vehicle.h																		 ///
/// Designers   : Weicheng Huang, James Musonda													 ///
/// Course      : Computational Problem Solving II												 ///
///				  CPET.321.01 / L01                                                              ///
/// Notes       :																				 ///
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

namespace VEHICLE {
	class Vehicle {
	protected:
		int numSeats;
		string vehicleType;
		vector<string> seating;

	public:
		void displayVehicles();
		void printVehicleAssignments();
	};
}