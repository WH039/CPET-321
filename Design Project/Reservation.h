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

using namespace std;

namespace RESERVATION {
	class Reservation {
	private:
		string firstName;
		string lastName;
		int credits;

	public:
		void createReservation();
		void modifyReservation();
		void deleteReservation();
		void displayVehicles();
		void printReservation();
		void printVehicleAssignments();

	};
}