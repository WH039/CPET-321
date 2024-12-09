////////////////////////////////////////////////////////////////////////////////////////////////////
/// File Name   : Pickup.h																		 ///
/// Designers   : Weicheng Huang, James Musonda													 ///
/// Course      : Computational Problem Solving II												 ///
///				  CPET.321.01 / L01                                                              ///
/// Notes       :																				 ///
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Vehicle.h"

using namespace std;

class Pickup : Vehicle {
	private:
		int pin;
		string driver;
		string color;
		vector<char> seats;
		vector<string> passengers;

	public:
		Pickup();
		int findSeat(int, int);
		int passengerListSize();
		void assignVehicle(string);
		void addPassenger(string, string);
		char getSeatValue(int);
		string getColor(string);
		void removePassenger(string, string, int);
		string getPassenger(int);
};