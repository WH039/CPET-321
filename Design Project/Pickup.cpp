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

string Pickup::getColor(string driver) {
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
    return color;
}

int Pickup::findSeat(int credits, int num) {
    if (num < 0 || num >= seats.size()) {
        cout << "Invalid seat number." << endl;
        return 0;
    }

    if (seats[num] == 'X') {
        cout << "Seat already taken." << endl;
        return 0;
    }

    if (credits >= 5) {
        // Assign a PIN based on color
        if (color == "Purple") {
            pin = 101;
        }
        else if (color == "Green") {
            pin = 201;
        }
        else if (color == "Black") {
            pin = 301;
        }
        else {
            pin = 0; // Default for unknown color
        }

        seats[num] = 'X';
        return pin;
    }
    else {
        cout << "Not enough credits." << endl;
        return 0;
    }
}

void Pickup::addPassenger(string firstName, string lastName) {
    passengers.emplace_back(firstName + " " + lastName);
}

void Pickup::removePassenger(string firstName, string lastName, int pin) {
    auto it = find(passengers.begin(), passengers.end(), firstName);
    if (it != passengers.end()) {
        passengers.erase(it);
    }
    else {
        cout << "Passenger not found." << endl;
        return;
    }

    // Reset the seat if the PIN is valid
    if (pin == 101 || pin == 201 || pin == 301) {
        if (seats.size() > 1) {
            seats[1] = '5';
        }
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
