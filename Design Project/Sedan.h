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
		int numSeats_Sedan;
		string vehicleColor_Sedan;
		int passengerSeatValue_Sedan;
		int windowSeatValue_Sedan;
		int middleSeatValue_Sedan;

	public:
		Sedan();
		int getSedanSeatValue(string);
		int getSedanNumSeats();
		string getSedanColor(string);

	};
}