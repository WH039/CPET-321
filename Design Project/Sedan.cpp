////////////////////////////////////////////////////////////////////////////////////////////////////
/// File Name   : Sedan.cpp														    			 ///
/// Designers   : Weicheng Huang, James Musonda													 ///
/// Course      : Computational Problem Solving II												 ///
///				  CPET.321.01 / L01                                                              ///
/// Notes       :																				 ///
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Sedan.h"

using namespace std;

Sedan::Sedan()
{
}

void Sedan::assignVehicle(string driver)
{
    if (driver == "Grace") {
        color = "Blue";
    }
    else if (driver == "Larry") {
        color = "Black";
    }
    else if (driver == "Jess") {
        color = "Green";
    }
    seats = { '-', '5', '2', '1', '2' };
}

char Sedan::getSeatValue(int num)
{
    char seatValue = seats[num];

    return seatValue;
}

string Sedan::getColor()
{
    return color;
}

string Sedan::findSeat(int credits, int num)
{
    string pin = "000";
    if (num == 1) {
        if (seats[num] != 'X') {
            if (credits >= 5) {
                if (color == "Blue") {
                    pin = "701";
                }
                else if (color == "Black") {
                    pin = "801";
                }
                else if (color == "Green") {
                    pin = "901";
                }
                seats[num] = 'X';
            }
            else if (credits < 5) {
                cout << "This person does not have enough credits for this seat" << endl;
            }
        }
    }
    if (num == 2) {
        if (seats[num] != 'X') {
            if (credits >= 2) {
                if (color == "Purple") {
                    pin = "702";
                }
                else if (color == "Green") {
                    pin = "802";
                }
                else if (color == "Black") {
                    pin = "902";
                }
                seats[num] = 'X';
            }
            else if (credits < 2) {
                cout << "This person does not have enough credits for this seat" << endl;
            }
        }
        if (seats[num + 2] != 'X') {
            if (credits >= 2) {
                if (color == "Purple") {
                    pin = "704";
                }
                else if (color == "Green") {
                    pin = "804";
                }
                else if (color == "Black") {
                    pin = "904";
                }
                seats[num] = 'X';
            }
            else if (credits < 2) {
                cout << "This person does not have enough credits for this seat" << endl;
            }
        }
    }
    if (num == 3) {
        if (seats[num] != 'X') {
            if (credits >= 1) {
                if (color == "Purple") {
                    pin = "703";
                }
                else if (color == "Green") {
                    pin = "803";
                }
                else if (color == "Black") {
                    pin = "903";
                }
                seats[num] = 'X';
            }
            else if (credits < 1) {
                cout << "This person does not have enough credits for this seat" << endl;
            }
        }
    }

    return pin;
}

void Sedan::addPassenger(string fname, string lname)
{
    string name = fname;
    name.append(" ");
    name.append(lname);
    passengers.push_back(name);
}

void Sedan::removePassenger(string fname, string lname, string pin)
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
    if (pin == "701" || pin == "801" || pin == "901") {
        seats[1] = '5';
    }
    else if (pin == "702" || pin == "802" || pin == "902") {
        seats[2] = '2';
    }
    else if (pin == "703" || pin == "803" || pin == "903") {
        seats[3] = '1';
    }
    else if (pin == "704" || pin == "804" || pin == "904") {
        seats[4] = '3';
    }
}

string Sedan::getPassenger(int n)
{
    return passengers[n];
}

int Sedan::passengerListSize()
{
    int size;

    size = passengers.size();

    return size;
}