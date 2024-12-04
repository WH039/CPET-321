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
		int numSeats_Pickup;
		string vehicleColor_Pickup;
		int passengerSeatValue_Pickup;
		

	public:
		Pickup();
		int getPickupSeatValue(string);
		int getPickupNumSeats();
		string getPickupColor(string);

	};
}