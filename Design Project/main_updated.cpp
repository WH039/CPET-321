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

    cout << "Enter the player's first name: ";
    cin >> Name;

    for (int i = 0; i < passList.size(); i++) {
        if (Name == passList[i]) {
            foundPlayer = true;
            continue;
        }
    }

    if(!foundPlayer){
        cout << "Player not found.\n";
        exit(1);
    }

    for (int i = 0; i < passList.size(); i++) {
        if (Name == passList[i]) {
            cout << "Credits: " << creditList[i] << endl;
            continue;
        }
    }

    char CB = '1', LWB = '2';
    char RWB = '2', RF = '5';
    char RB = '3', LB = '3';
    vector<char> sedanSeats = { '-', RF, LWB, CB, RWB };
    vector<char> compactSeats = { '-', RF, LB, RB };
    vector<char> truckSeats = { '-', RF };

    vector<string> sedanSpot = { "-", "RF", "LB", "CB", "RB"};
    vector<string> compactSpot = { "-", "RF", "LB", "RB" };
    vector<string> truckSpot = { "-", "RF" };

    bool proceed = false;
    string seatType;
    char location = ' ';

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

            cout << "\n\nSelect your seat. Case sensitive. ";
            cout << "Seat: ";
            cin >> seatType;
            for (int t = 0; t < compactSpot.size(); t++){
                if (seatType == compactSpot[t]) {
                    location = compactSeats[t];
                    continue;
                }
            } //for
            for (int t = 0; t < creditList.size(); t++) {
                if (creditList[t] >= location - '0') {
                    cout << "Reserved spot for seat " << location << ".\n";
                    continue;
                }
                else {
                    cout << "Not enough credits.\n";
                }
            } //for
            
            for (int t = 0; t < compactSeats.size(); t++) {
                if (location == compactSeats[t]) {
                    compactSpot[t] = 'X';
                    continue;
                }
            } //for

            cout << "\nCompact assignments:\n";
            for (int t = 0; t < compactSeats.size(); t++) {
                cout << "(" << compactSeats[t] << ")";
                if (t == 1) { cout << endl; }
            }
            break;
        case 2:
            cout << "\nSedan assignments:\n";
            for (int t = 0; t < sedanSeats.size(); t++) {
                cout << "(" << sedanSeats[t] << ")";
                if (t == 0) { cout << "   "; }
                if (t == 1) { cout << endl; }
            }

            cout << "\n\nSelect your seat. Case sensitive. ";
            cout << "Seat: ";
            cin >> seatType;
            for (int t = 0; t < sedanSpot.size(); t++) {
                if (seatType == sedanSpot[t]) {
                    location = sedanSeats[t];
                    continue;
                }
            } //for
            for (int t = 0; t < creditList.size(); t++) {
                if (creditList[t] >= location - '0') {
                    cout << "Reserved spot for seat " << location << ".\n";
                    continue;
                }
                else {
                    cout << "Not enough credits.\n";
                }
            } //for

            for (int t = 0; t < sedanSeats.size(); t++) {
                if (location == sedanSeats[t]) {
                    sedanSpot[t] = 'X';
                    continue;
                }
            } //for

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

            cout << "\n\nSelect your seat. Case sensitive. ";
            cout << "Seat: ";
            cin >> seatType;
            for (int t = 0; t < truckSpot.size(); t++) {
                if (seatType == truckSpot[t]) {
                    location = truckSeats[t];
                    continue;
                }
            } //for
            for (int t = 0; t < creditList.size(); t++) {
                if (creditList[t] >= location - '0') {
                    cout << "Reserved spot for seat " << location << ".\n";
                    
                    continue;
                }
                else {
                    cout << "Not enough credits.\n";
                }
            } //for

            for (int t = 0; t < truckSeats.size(); t++) {
                if (location == truckSeats[t]) {
                    truckSpot[t] = 'X';
                    continue;
                }
            } //for

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

    return 0;
}