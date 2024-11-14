////////////////////////////////////////////////////////////////////////////////////////////////////
/// File Name   : Sedan.cpp																		 ///
/// Designers   : Weicheng Huang, James Musonda													 ///
/// Course      : Computational Problem Solving II												 ///
///				  CPET.321.01 / L01                                                              ///
/// Notes       :																				 ///
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Sedan.h"

using namespace SEDAN;

Sedan::Sedan()
{
	numSeats = 5;
}

int Sedan::getNumSeats()
{
	return numSeats;
}

string Sedan::getVehicleColor(string fname)
{
	if (fname == "Grace") {
		vehicleColor = "Blue";
	}
	else if (fname == "Lary") {
		vehicleColor = "Black";
	}
	else if (fname == "Jessie") {
		vehicleColor = "Green";
	}
	return vehicleColor;
}