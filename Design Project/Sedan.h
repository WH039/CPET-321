////////////////////////////////////////////////////////////////////////////////////////////////////
/// File Name   : Sedan.h																		 ///
/// Designers   : Weicheng Huang, James Musonda													 ///
/// Course      : Computational Problem Solving II												 ///
///				  CPET.321.01 / L01                                                              ///
/// Notes       :																				 ///
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Vehicle.h"

using namespace std;

class Sedan : Vehicle {
	private:
		string driver;
		string color;
		vector<char> seats;
		vector<string> passengers;

	public:
		Sedan();
		string findSeat(int, int);
		int passengerListSize();
		void assignVehicle(string);
		void addPassenger(string, string);
		void removePassenger(string, string, string);
		char getSeatValue(int);
		string getColor();
		string getPassenger(int);
};