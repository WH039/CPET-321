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

namespace RESERVATION {
	class Reservation {
	private:
		string firstName;
		string lastName;
		int credits;
		bool isdriver;

	public:
		void createReservation();
		void modifyReservation();
		void deleteReservation();
		void printReservation();

	};
}