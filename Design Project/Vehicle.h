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

class Vehicle {
	protected:
		string vehicleType;
		string vehicleColor;

	public:
		void displayVehicle();
	};