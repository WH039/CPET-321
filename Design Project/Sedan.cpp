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
    numSeats_Sedan = 4;
    passengerSeatValue_Sedan = 5;
    windowSeatValue_Sedan = 2;
    middleSeatValue_Sedan = 1;
}

int Sedan::getSedanSeatValue(string seat)
{
    int output = 0;
    if (seat == "passenger") {
        output = passengerSeatValue_Sedan;
    }
    else if (seat == "window") {
        output = windowSeatValue_Sedan;
    }
    else if (seat == "middle") {
        output = middleSeatValue_Sedan;
    }

    return output;
}

int Sedan::getSedanNumSeats()
{
    return numSeats;
}

string Sedan::getSedanColor(string fname)
{
    if (fname == "Grace") {
        vehicleColor_Sedan = "Blue";
    }
    else if (fname == "Lary") {
        vehicleColor_Sedan = "Black";
    }
    else if (fname == "Jessie") {
        vehicleColor_Sedan = "Green";
    }

    return vehicleColor_Sedan;
}