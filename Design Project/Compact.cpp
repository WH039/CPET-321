////////////////////////////////////////////////////////////////////////////////////////////////////
/// File Name   : Compact.cpp																	 ///
/// Designers   : Weicheng Huang, James Musonda													 ///
/// Course      : Computational Problem Solving II												 ///
///				  CPET.321.01 / L01                                                              ///
/// Notes       :																				 ///
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Compact.h"

using namespace std;

Compact::Compact()
{
}

void Compact::assignVehicle(string driver)
{
    seats = { '-', '5', '3', '3' };
    if (driver == "Ben") {
        color = "Red";
    }
    else if (driver == "Art") {
        color = "Blue";
    }
    else if (driver == "Ann") {
        color = "Yellow";
    }
}

char Compact::getSeatValue(int num)
{
    char seatValue = seats[num];

    return seatValue;
}

string Compact::getColor()
{
    return color;
}

string Compact::findSeat(int credits, int num)
{
    string pin = "000";
    if (num == 1) {
        if (seats[num] != 'X') {
            if (credits >= 5) {
                if (color == "Red") {
                    pin = "401";
                }
                else if (color == "Blue") {
                    pin = "501";
                }
                else if (color == "Yellow") {
                    pin = "601";
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
    if (num == 2) {
        if (seats[num] != 'X') {
            if (credits == 3) {
                if (color == "Purple") {
                    pin = "402";
                }
                else if (color == "Green") {
                    pin = "502";
                }
                else if (color == "Black") {
                    pin = "602";
                }
                seats[num] = 'X';
            }
            else if (credits < 3) {
                cout << "This person does not have enough credits for this seat" << endl;
            }
        }
        else if (seats[num + 1] != 'X') {
            if (credits == 3) {
                if (color == "Purple") {
                    pin = "403";
                }
                else if (color == "Green") {
                    pin = "503";
                }
                else if (color == "Black") {
                    pin = "603";
                }
                seats[num] = 'X';
            }
            else if (credits < 3) {
                cout << "This person does not have enough credits for this seat" << endl;
            }
        }
        else {
            return pin;
        }
    }
    return pin;
}

void Compact::addPassenger(string fname, string lname)
{
    string name = fname;
    name.append(" ");
    name.append(lname);
    passengers.push_back(name);
}

void Compact::removePassenger(string fname, string lname, string pin)
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
    if (pin == "401" || pin == "501" || pin == "601") {
        seats[1] = '5';
    }
    else if (pin == "402" || pin == "502" || pin == "602") {
        seats[2] = '3';
    }
    else if (pin == "403" || pin == "503" || pin == "603") {
        seats[3] = '3';
    }
}

string Compact::getPassenger(int n)
{
    return passengers[n];
}

int Compact::passengerListSize()
{
    int size;

    size = passengers.size();

    return size;
}