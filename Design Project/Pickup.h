////////////////////////////////////////////////////////////////////////////////////////////////////
/// File Name   : Pickup.h																		 ///
/// Designers   : Weicheng Huang, James Musonda													 ///
/// Course      : Computational Problem Solving II												 ///
///				  CPET.321.01 / L01                                                              ///
/// Notes       :																				 ///
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Vehicle.h"

using namespace VEHICLE;

namespace PICKUP {
	class Pickup : Vehicle {
	private:
		int numSeats;
		string vehicleColor;

	public:
		Pickup();
		int getNumSeats();
		string getVehicleColor(string);
	};
}