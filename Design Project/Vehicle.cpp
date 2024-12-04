////////////////////////////////////////////////////////////////////////////////////////////////////
/// File Name   : Vehicle.cpp																	 ///
/// Designers   : Weicheng Huang, James Musonda													 ///
/// Course      : Computational Problem Solving II												 ///
///				  CPET.321.01 / L01                                                              ///
/// Notes       :																				 ///
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Vehicle.h"

using namespace VEHICLE;

void Vehicle::displayVehicle(string vehicleT, string driver)
{
	switch (vehicleT) {
	case "Pickup":
		vehicleType = vehicleT;
		driverName = driver;
		numseats = 1;
		passengerSeatValue = 5;
		windowSeatValue = 0;
		middleSeatValue = 0;
		vehicleColor = setVehicleColor(driverName);
		cout << "Vehicle Type: " << vehicleType << endl;
		cout << "Number of Seats: " << numseats << endl;
		cout << "Passenger Seat Value: " << passengerSeatValue << endl;
		break;

	case "Compact":
		vehicleType = vehicleT;
		numseats = 3;
		passengerSeatValue = 5;
		windowSeatValue = 3;
		middleSeatValue = 0;
		vehicleColor = setVehicleColor(driverName);
		cout << "Vehicle Type: " << vehicleType << endl;
		cout << "Number of Seats: " << numseats << endl;
		cout << "Passenger Seat Value: " << passengerSeatValue << endl;
		cout << "Window Seat Value: " << windowSeatValue << endl;
		break;

	case "Sedan":
		vehicleType = vehicleT;
		numseats = 4;
		passengerSeatValue = 5;
		windowSeatValue = 2;
		middleSeatValue = 1;
		vehicleColor = setVehicleColor(driverName);
		cout << "Vehicle Type: " << vehicleType << endl;
		cout << "Number of Seats: " << numseats << endl;
		cout << "Passenger Seat Value: " << passengerSeatValue << endl;
		cout << "Window Seat Value: " << windowSeatValue << endl;
		cout << "Middle Seat Value: " << middleSeatValue << endl;
		break;

	}
}

string VEHICLE::Vehicle::setVehicleColor(string)
{
	string color;
	if (vehicleType == "Pickup") {
		color = getPickupColor(driverName);
	}
	else if (vehicleType == "Compact") {
		color = getCompactColor(driverName);
	}
	else if (vehicleType == "Sedan") {
		color = getSedanColor(driverName);
	}

	return color;
}


