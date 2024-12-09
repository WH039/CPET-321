////////////////////////////////////////////////////////////////////////////////////////////////////
/// File Name   : Compact.h																		 ///
/// Designers   : Weicheng Huang, James Musonda													 ///
/// Course      : Computational Problem Solving II												 ///
///				  CPET.321.01 / L01                                                              ///
/// Notes       :																				 ///
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Vehicle.h"

using namespace std;

class Compact : Vehicle {
private:
	string driver;
	string color;
	vector<char> seats;
	vector<string> passengers;

public:
	Compact();
	int findSeat(int, int);
	int passengerListSize();
	void assignVehicle(string);
	void addPassenger(string, string);
	void removePassenger(const string, const string, int);
	char getSeatValue(int);
	string getColor(string);
	string getPassenger(int);
};


/*
class Compact : Vehicle {
	private:
		int compactSeatCount;
		string compactColor;
		int compactFront;
		int compactWindowL;
		int compactWindowR;
		int scompactMiddle;

	public:
		Compact();
		int getCompactSeatValue(string);
		int getCompactNumSeats();
		string getCompactColor(string);
	};
	*/
