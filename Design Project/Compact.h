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
		int numSeats_Compact;
		string vehicleColor_Compact;
		int passengerSeatValue_Compact;
		int windowSeatValue_Compact;

	public:
		Compact();
		int getCompactSeatValue(string);
		int getCompactNumSeats();
		string getCompactColor(string);
	};
}