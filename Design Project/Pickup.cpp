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
    numSeats_Pickup = 1;
    passengerSeatValue_Pickup = 5;
}

int Pickup::getPickupSeatValue(string seat)
{
    int output = 0;
    if (seat == "passenger") {
        output = passengerSeatValue_Pickup;
    }
    return output;
}

int Pickup::getPickupNumSeats()
{
    return numSeats_Pickup;
}

string Pickup::getPickupColor(string fname)
{
    if (fname == "Pat") {
        vehicleColor_Pickup = "Purple";
    }
    else if (fname == "Jane") {
        vehicleColor_Pickup = "Green";
    }
    else if (fname == "Tim") {
        vehicleColor_Pickup = "Black";
    }

    return vehicleColor_Pickup;
}