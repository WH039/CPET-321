////////////////////////////////////////////////////////////////////////////////////////////////////
/// File Name   : Reservation.h																	 ///
/// Designers   : Weicheng Huang, James Musonda													 ///
/// Course      : Computational Problem Solving II												 ///
///				  CPET.321.01 / L01                                                              ///
/// Notes       :																				 ///
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Reservation.h"

using namespace std;

Reservation::Reservation() {}

void Reservation::setFirstName(string first) { firstName = first; }

void Reservation::setLastName(string last){	lastName = last;}

void Reservation::setCredits(int coins) { credits = coins; }

void Reservation::setPIN(int pinNum) { PIN = pinNum; }

string Reservation::getFirstname() { return firstName; }

string Reservation::getLastname() {	return lastName;}

int Reservation::getCredits(){ return credits; }

int Reservation::getPIN(){ return PIN; }
