////////////////////////////////////////////////////////////////////////////////////////////////////
/// File Name   : Reservation.h																	 ///
/// Designers   : Weicheng Huang, James Musonda													 ///
/// Course      : Computational Problem Solving II												 ///
///				  CPET.321.01 / L01                                                              ///
/// Notes       :																				 ///
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Reservation.h"

using namespace RESERVATION;

void Reservation::setFirstName(string fn) 
{
	firstName = fn;
}

void Reservation::setLastName(string ln) 
{
	lastName = ln;
}

void Reservation::setCredits(int cred)
{
	credits = cred;
	if (credits == -1) {
		isDriver = true;
	}
}

void Reservation::setPIN(int p)
{
	PIN = p;
}

string Reservation::getFirstname()
{
	return firstName;
}

string Reservation::getLastname()
{
	return lastName;
}

int Reservation::getCredits()
{
	return credits;
}

int Reservation::getPIN() {
	return PIN;
}
