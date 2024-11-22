////////////////////////////////////////////////////////////////////////////////////////////////////
/// File Name   : Sedan.h																		 ///
/// Designers   : Weicheng Huang, James Musonda													 ///
/// Course      : Computational Problem Solving II												 ///
///				  CPET.321.01 / L01                                                              ///
/// Notes       :																				 ///
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Vehicle.h"

using namespace VEHICLE;

namespace SEDAN {
	class Sedan : Vehicle {
	private:
		int numSeats;
		string vehicleColor;
		int passengerSeatValue;
		int windowSeatValue;
		int middleSeatValue;

	public:
		Sedan();
		int getSeatValue(string);
		int getNumSeats();
		string getVehicleColor(string);

	};
}