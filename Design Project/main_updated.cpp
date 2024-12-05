////////////////////////////////////////////////////////////////////////////////////////////////////
/// File Name   : main.cpp																		 ///
/// Designers   : Weicheng Huang, James Musonda													 ///
/// Course      : Computational Problem Solving II												 ///
///				  CPET.321.01 / L01                                                              ///
/// Notes       :																				 ///
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Vehicle.h"
#include "Reservation.h"

using namespace std;

void intFailSafe() {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid input.\n";
}

int main() {
    string firstName, lastName, Name;
    vector<string> driverList;
    vector<string> passList;

    ifstream File("dodgeball_team.txt");
    if (!File.is_open()) {
        cout << "File not found.\n";
    }

    int choice = 0;
    int t = 0;
    int credits = 0;
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

    bool foundPlayer = false;

    string Name;
    cout << "Enter the player's first name: ";
    cin >> Name;

    for (int i = 0; i < passList.size(); i++) {
        if (Name == passList[i]) {
            foundPlayer = true;
            if (creditList[i] == 0) {
                cout << "No credits available.\n";
            }
            else {
                cout << "Credits: " << creditList[i] << endl;
            }
        } //if
        if (!foundPlayer) {
            cout << "Player not found.\n";
        }
    } //for

    char CB = '1', LWB = '2';
    char RWB = '2', RF = '5';
    char RB = '3', LB = '3';
    vector<char> sedanSeats = { '-', RF, LWB, CB, RWB };
    vector<char> compactSeats = { '-', RF, LB, RB };
    vector<char> truckSeats = { '-', RF };

    bool proceed = false;
    string seatType;

    while (!proceed) {
        cout << "1. Compact\n";
        cout << "2. Sedan\n";
        cout << "3. Pickup\n";
        cout << "Select your car of choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nCompact assignments:\n";
            for (int t = 0; t < compactSeats.size(); t++) {
                cout << "(" << compactSeats[t] << ")";
                if (t == 1) { cout << endl; }
            }

            cout << "Select your seat: ";
            cin >> seatType;
            break;
        case 2:
            cout << "\nSedan assignments:\n";
            for (int t = 0; t < sedanSeats.size(); t++) {
                cout << "(" << sedanSeats[t] << ")";
                if (t == 0) { cout << "   "; }
                if (t == 1) { cout << endl; }
            }
            break;
        case 3:
            cout << "\nTruck assignments:\n";
            for (int t = 0; t < truckSeats.size(); t++) {
                cout << "(" << truckSeats[t] << ")";
                if (t == 1) { cout << endl; }
            }

            break;
        default:
            proceed = false;
            intFailSafe();
        } //switch
    } // while

    // char c = '4';
    // int value = 4;
    // c - '0' == value    

    return 0;
}