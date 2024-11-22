////////////////////////////////////////////////////////////////////////////////////////////////////
/// File Name   : Sedan.cpp														    			 ///
/// Designers   : Weicheng Huang, James Musonda													 ///
/// Course      : Computational Problem Solving II												 ///
///				  CPET.321.01 / L01                                                              ///
/// Notes       :																				 ///
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Sedan.h"

using namespace SEDAN;

Sedan::Sedan()
{
    numSeats = 4;
    passengerSeatValue = 5;
    windowSeatValue = 2;
    middleSeatValue = 1;
}

int Sedan::getSeatValue(string seat)
{
    int output = 0;
    if (seat == "passenger") {
        output = passengerSeatValue;
    }
    else if (seat == "window") {
        output = windowSeatValue;
    }
    else if (seat == "middle") {
        output = middleSeatValue;
    }

    return output;
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