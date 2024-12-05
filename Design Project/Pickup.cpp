////////////////////////////////////////////////////////////////////////////////////////////////////
/// File Name   : Pickup.cpp																	 ///
/// Designers   : Weicheng Huang, James Musonda													 ///
/// Course      : Computational Problem Solving II												 ///
///				  CPET.321.01 / L01                                                              ///
/// Notes       :																				 ///
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Pickup.h"

using namespace PICKUP;

Pickup::Pickup()
{
}

void Pickup::assignVehicle(string driver)
{
    if (driver == "Pat") {
        color = "Purple";
    }
    else if (driver == "Jane") {
        color = "Green";
    }
    else if (driver == "Tim") {
        color = "Black";
    }
    seats = { '-', '5' };
}

char Pickup::getSeatValue(int num)
{
    char seatValue = seats[num];

    return seatValue;
}

string Pickup::getColor(string fname)
{
    return color;
}

int Pickup::findSeat(int credits, int num)
{
    int pin = 000;
    if (num == 1) {
        if (seats[num] != 'X') {
            if (credits == 5) {
                if (color == "Purple") {
                    pin = 101;
                }
                else if (color == "Green") {
                    pin = 201;
                }
                else if (color == "Black") {
                    pin = 301;
                }
                seats[num] = 'X';
            }
            else if (credits < 5) {
                cout << "This person does not have enough credits for this seat" << endl;
            }
        }
    }

    return pin;
}

void Pickup::addPassenger(string fname, string lname)
{
    string name = fname;
    name.append(" ");
    name.append(lname);
    passengers.push_back(name);
}

void Pickup::removePassenger(const string fname, const string lname, int pin)
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
    if (pin == 101 || pin == 201 || pin == 301) {
        seats[1] = '5';
    }

}

string Pickup::getPassenger(int n)
{
    return passengers[n];
}

int Pickup::passengerListSize()
{
    int size;

    size = passengers.size();
    
    return size;
}
