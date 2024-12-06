////////////////////////////////////////////////////////////////////////////////////////////////////
/// File Name   : main.cpp																		 ///
/// Designers   : Weicheng Huang, James Musonda													 ///
/// Course      : Computational Problem Solving II												 ///
///				  CPET.321.01 / L01                                                              ///
/// Notes       :																				 ///
////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void intFailSafe() {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid input.\n";
}

void displayVehicle(const vector<char>& Seats, string carType) {
    cout << "\n" << carType << " assignments:\n"; //Display Assignments
    for (int t = 0; t < Seats.size(); t++) {
        cout << "(" << Seats[t] << ")";
        if (carType != "Compact" && t == 0) { cout << "   "; }
        if (t == 1) { cout << endl; }
    }
    cout << endl;
}

bool reserveSeat(vector<string>& availableSeats, string& seatType, int playerCredits, vector<char>& compactSeats) {
    for (int t = 0; t < availableSeats.size(); t++) {
        if (seatType == availableSeats[t]) {
            int seatCredit = compactSeats[t] - '0'; // Convert char to int
            if (compactSeats[t] == 'X') {
                cout << "The seat is taken.\n";
                return false;
            }
            if (playerCredits < seatCredit) {
                cout << "Not enough credits.\n";
                return false;
            }
            else {
                compactSeats[t] = 'X'; // Mark as reserved
                cout << "Reserved spot for seat " << seatType << ".\n";
                return true;
            }
        }
    }
    cout << "Invalid seat selection.\n";
    return false;
}

int main() {
    string firstName, lastName, Name;

    vector<string> driverList, passList, assignedPeople;
    vector<string> sedanSpot = { "-", "RF", "LB", "CB", "RB" }; //What we look for when we want to modify sedanSeats
    vector<string> compactSpot = { "-", "RF", "LB", "RB" };
    vector<string> pickupSpot = { "-", "RF" };

    char CB = '1', LWB = '2', RWB = '2', RF = '5', RB = '3', LB = '3';

    vector<char> sedanSeats = { '-', RF, LWB, CB, RWB };  //The things we actually modify for display
    vector<char> compactSeats = { '-', RF, LB, RB };
    vector<char> pickupSeats = { '-', RF };

    ifstream File("dodgeball_team.txt");
    if (!File.is_open()) { cout << "File not found.\n"; }

    string seatType;
    char location = ' ';

    bool foundPlayer = false;
    bool proceed = true;

    int t = 0;
    int choice = 0;
    int credits = 0;
    int playerCredits = 0;
    
    vector<int> creditList;
    
    while (getline(File, Name) && t < 9) {
        driverList.push_back(Name);
        t++;
    }
    while (File >> firstName >> lastName >> credits) {
        string fullname = firstName + " " + lastName;
        passList.push_back(firstName);
        creditList.push_back(credits);
    }

    while (1) {
        do {
            cout << "Enter the player's first name: ";
            cin >> Name;

            proceed = true;

            for (int t = 0; t < assignedPeople.size(); t++) {
                if (Name == assignedPeople[t]) {
                    proceed = false;
                    cout << Name << " has a seat already.\n";
                    break;
                }
            }
        } while (!proceed);

        for (int i = 0; i < passList.size(); i++) {
            if (Name == passList[i]) {
                foundPlayer = true;
                playerCredits = creditList[i];
                cout << "Credits: " << playerCredits << endl;
                break;
            }
        }

        if (!foundPlayer) {
            cout << "Player not found.\n";
            exit(1);
        }


        cout << "\n1. Compact\n";
        cout << "2. Sedan\n";
        cout << "3. Pickup\n";
        cout << "Select your car of choice: ";
        cin >> choice;

    switch (choice) {
        case 1:
            displayVehicle(compactSeats, "Compact");

            cout << "\n\nSelect your seat. Case sensitive.\nSeat: ";
            cin >> seatType;
            
            if (reserveSeat(compactSpot, seatType, playerCredits, compactSeats)) {
                assignedPeople.push_back(Name);
                displayVehicle(compactSeats, "Compact");
            }
            break;
        case 2:
            displayVehicle(sedanSeats, "Sedan");

            cout << "\n\nSelect your seat. Case sensitive.\nSeat: ";
            cin >> seatType;

            if (reserveSeat(sedanSpot, seatType, playerCredits, sedanSeats)) {
                assignedPeople.push_back(Name);
                displayVehicle(sedanSeats, "Sedan");
            }
            break;
        case 3:
            displayVehicle(pickupSeats, "Pickup");

            cout << "\n\nSelect your seat. Case sensitive.\nSeat: ";
            cin >> seatType;

            if (reserveSeat(pickupSpot, seatType, playerCredits, pickupSeats)) {
                assignedPeople.push_back(Name);
                displayVehicle(pickupSeats, "Pickup");
            }
            break;
        default:
            proceed = false;
            intFailSafe();
        } //switch
    } // while

    return 0;
}