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
		int numseats;
		string driverName;
		int numPassengers;
		string frontPassenger;
		string leftWindowPassenger;
		string rightWindowPassenger;
		string middlePassanger;
		string vehicleType;
		string vehicleColor;
		int passengerSeatValue;
		int windowSeatValue;
		int middleSeatValue;

	public:
		void displayVehicle(string, string);
		string setVehicleColor(string);
	};
}