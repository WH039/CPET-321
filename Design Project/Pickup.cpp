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
    passengerSeatValue = 5;
}

int Pickup::getSeatValue(string seat)
{
    int output = 0;
    if (seat == "passenger") {
        output = passengerSeatValue;
    }
    return output;
}

int Pickup::getNumSeats()
{
    int numSeats = 2;

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