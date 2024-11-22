////////////////////////////////////////////////////////////////////////////////////////////////////
/// File Name   : Compact.h																		 ///
/// Designers   : Weicheng Huang, James Musonda													 ///
/// Course      : Computational Problem Solving II												 ///
///				  CPET.321.01 / L01                                                              ///
/// Notes       :																				 ///
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Vehicle.h"

using namespace VEHICLE;

namespace COMPACT {
	class Compact : Vehicle {
	private:
		int numSeats;
		string vehicleColor;
		int passengerSeatValue;

	public:
		Compact();
		int getSeatValue(string);
		int getNumSeats();
		string getVehicleColor(string);
	};
}