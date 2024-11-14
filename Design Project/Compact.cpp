////////////////////////////////////////////////////////////////////////////////////////////////////
/// File Name   : Compact.cpp																	 ///
/// Designers   : Weicheng Huang, James Musonda													 ///
/// Course      : Computational Problem Solving II												 ///
///				  CPET.321.01 / L01                                                              ///
/// Notes       :																				 ///
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Compact.h"

using namespace COMPACT;

Compact::Compact()
{
	numSeats = 4;
}

int Compact::getNumSeats()
{
	return numSeats;
}

string Compact::getVehicleColor(string fname)
{
	if (fname == "Ben") {
		vehicleColor = "Red";
	}
	else if (fname == "Art") {
		vehicleColor = "Blue";
	}
	else if (fname == "Ann") {
		vehicleColor = "Yellow";
	}
	return vehicleColor;
}