////////////////////////////////////////////////////////////////////////////////////////////////////
/// File Name   : Reservation.h																	 ///
/// Designers   : Weicheng Huang, James Musonda													 ///
/// Course      : Computational Problem Solving II												 ///
///				  CPET.321.01 / L01                                                              ///
/// Notes       :																				 ///
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Reservation {
	private:
		string firstName;
		string lastName;
		int credits = 0;
		int PIN = 0;

	public:
		Reservation();
		void setFirstName(string);
		void setLastName(string);
		void setCredits(int);
		void setPIN(int);
		string getFirstname();
		string getLastname();
		int getCredits();
		int getPIN();
	};