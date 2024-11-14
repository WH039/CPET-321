////////////////////////////////////////////////////////////////////////////////////////////////////
/// File Name   : Pickup.cpp																	 ///
/// Designers   : Weicheng Huang, James Musonda													 ///
/// Course      : Computational Problem Solving II												 ///
///				  CPET.321.01 / L01                                                              ///
/// Notes       :																				 ///
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Pickup.h"

using namespace PICKUP;

Pickup::Pickup()
{
	numSeats = 2;
}

int Pickup::getNumSeats()
{
	return numSeats;
}

string Pickup::getVehicleColor(string fname)
{
	if (fname == "Pat") {
		vehicleColor = "Purple";
	}
	else if (fname == "Jane") {
		vehicleColor = "Green";
	}
	else if (fname == "Tim") {
		vehicleColor = "Black";
	}
	return vehicleColor;
}
