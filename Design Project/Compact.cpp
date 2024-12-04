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
    numSeats_Compact = 3;
    passengerSeatValue_Compact = 5;
    windowSeatValue_Compact = 3;
}

int Compact::getCompactSeatValue(string seat)
{
    int output = 0;
    if (seat == "passenger") {
        output = passengerSeatValue_Compact;
    }
    else if (seat == "window") {
        output = windowSeatValue_Compact;
    }

    return output;
}

int Compact::getCompactNumSeats()
{
    return numSeats_Compact;
}

string Compact::getCompactColor(string fname)
{
    if (fname == "Ben") {
        vehicleColor_Compact = "Red";
    }
    else if (fname == "Art") {
        vehicleColor_Compact = "Blue";
    }
    else if (fname == "Ann") {
        vehicleColor_Compact = "Yellow";
    }
    
    return vehicleColor_Compact;
}


