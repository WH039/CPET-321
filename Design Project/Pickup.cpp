////////////////////////////////////////////////////////////////////////////////////////////////////
/// File Name   : Pickup.cpp																	 ///
/// Designers   : Weicheng Huang, James Musonda													 ///
/// Course      : Computational Problem Solving II												 ///
///				  CPET.321.01 / L01                                                              ///
/// Notes       :																				 ///
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Pickup.h"

using namespace std;

Pickup::Pickup() {}

// Assign vehicle color and initialize seats
void Pickup::assignVehicle(string driver) {
    seats = { '-', '5' };
    if (driver == "Pat") {
        color = "Purple";
    }
    else if (driver == "Jane") {
        color = "Green";
    }
    else if (driver == "Tim") {
        color = "Black";
    }
    else {
        color = "Unknown";
    }
}

char Pickup::getSeatValue(int num) {
    if (num < seats.size()) {
        return seats[num];
    }
    else {
        return ' '; // Default for invalid indices
    }
}

string Pickup::getColor() {
    return color;
}

string Pickup::findSeat(int credits, int num) {
    string pin = "000";
    if (num == 1) {
        if (seats[num] != 'X') {
            if (credits >= 5) {
                if (color == "Purple") {
                    pin = "101";
                }
                else if (color == "Green") {
                    pin = "201";
                }
                else if (color == "Black") {
                    pin = "301";
                }
                seats[num] = 'X';
            }
            else if (credits < 5) {
                cout << "This person does not have enough credits for this seat" << endl;
            }
        }
        else {
            return pin;
        }
    }
}

void Pickup::addPassenger(string firstName, string lastName) {
    passengers.emplace_back(firstName + " " + lastName);
}

void Pickup::removePassenger(string fname, string lname, string pin)
{
    string name = fname;
    name.append(" ");
    name.append(lname);
    for (int i = 0; i < passengers.size(); i++) {
        if (passengers[i] == name) {
            passengers.erase(passengers.begin() + (i - 1));
            break;
        }
    }
    if (pin == "101" || pin == "201" || pin == "301") {
        seats[1] = '5';
    }
}

// Get the name of a specific passenger
string Pickup::getPassenger(int n) {
    if (n < passengers.size()) {
        return passengers[n];
    }
    return "Invalid index";
}

// Get the size of the passenger list
int Pickup::passengerListSize() {
    return passengers.size();
}
