////////////////////////////////////////////////////////////////////////////////////////////////////
/// File Name   : Pickup.h																		 ///
/// Designers   : Weicheng Huang, James Musonda													 ///
/// Course      : Computational Problem Solving II												 ///
///				  CPET.321.01 / L01                                                              ///
/// Notes       :																				 ///
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Vehicle.h"

using namespace VEHICLE;

namespace PICKUP {
	class Pickup : Vehicle {
	private:
		string driver;
		string color;
		vector<char> seats;
		vector<string> passengers;

	public:
		Pickup();
		
		void assignVehicle(string);
		char getSeatValue(int);
		string getColor(string);
		int findSeat(int, int);
		void addPassenger(string, string);
		void removePassenger(const string, const string, int);
		string getPassenger(int);
		int passengerListSize();
	};
}