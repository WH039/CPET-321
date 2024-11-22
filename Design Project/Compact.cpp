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
    numSeats = 3;
    passengerSeatValue = 5;
}

int Compact::getSeatValue(string seat)
{
    int output = 0;
    if (seat == "passenger") {
        output = passengerSeatValue;
    }

    return output;
}

int Compact::getNumSeats()
{
    int numSeats = 4;

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


