////////////////////////////////////////////////////////////////////////////////////////////////////
/// File Name   : main.cpp																		 ///
/// Designers   : Weicheng Huang, James Musonda													 ///
/// Course      : Computational Problem Solving II												 ///
///				  CPET.321.01 / L01                                                              ///
/// Notes       :																				 ///
////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>

#include "Vehicle.h"
#include "Pickup.h"
#include "Compact.h"
#include "Sedan.h"
#include "Reservation.h"

using namespace std;
using namespace VEHICLE;
using namespace PICKUP;
using namespace COMPACT;
using namespace SEDAN;
using namespace RESERVATION;

ifstream OpenInputFile()
{
	string inFileName = "dodgeball_team.txt";
	ifstream temp;

	temp.open(inFileName.c_str());

	if (!temp.is_open()) {
		cout << "\nUnsuccessfully... Program Terminated\n" << endl;
		exit(1);
	}
	return (temp);
}

int main() {
	
	ifstream inFile;
	inFile = OpenInputFile();

	vector<Reservation> Person;
	Reservation tempPerson;
	string fname;
	string lname;
	int credits;

	while (inFile.good()) {
		inFile >> fname >> lname >> credits;
		tempPerson.setFirstName(fname);
		tempPerson.setLastName(lname);
		tempPerson.setCredits(credits);
		Person.push_back(tempPerson);
	}

	for (int i = 0; i < Person.size(); i++) {
		cout << Person[i].getFirstname() << " " << Person[i].getLastname() << " " << Person[i].getCredits() << endl;
	}

	Pickup purplePickup;
	purplePickup.assignVehicle(Person[0].getFirstname());
	Pickup greenPickup;
	greenPickup.assignVehicle(Person[1].getFirstname());
	Pickup blackPickup;
	blackPickup.assignVehicle(Person[2].getFirstname());

	Pickup redCompact;
	redCompact.assignVehicle(Person[3].getFirstname());
	Pickup blueCompact;
	blueCompact.assignVehicle(Person[4].getFirstname());
	Pickup yellowCompact;
	yellowCompact.assignVehicle(Person[5].getFirstname());

	Pickup blueSedan;
	blueSedan.assignVehicle(Person[6].getFirstname());
	Pickup blackSedan;
	blackSedan.assignVehicle(Person[7].getFirstname());
	Pickup greenSedan;
	greenSedan.assignVehicle(Person[8].getFirstname());



	int choice = -1;

	while (choice != 0) {
		system("cls");
		cout << "Welcome to the Carpool Reservation System" << endl;
		cout << "Please Select an Option:" << endl;
		cout << "________________________" << endl;
		cout << "[1] Create a Reservation" << endl;
		cout << "[2] Modify a Reservation" << endl;
		cout << "[3] Delete a Reservation" << endl;
		cout << "[4] Display all Vehicles" << endl;
		cout << "[5] Print All Reservations" << endl;
		cout << "[6] Print Vehicle Assignments" << endl;
		cout << "[0] Exit" << endl;
		cin >> choice;

		while (choice != 0) {
			if (choice == 1) {
				system("cls");
				string name;
				bool found = false;
				int index;
				string seatSelection;
				cout << "Please Enter the Passenger's Name: ";
				cin >> name;
				for (int i = 0; i < Person.size(); i++) {
					if (name == Person[i].getFirstname()) {
						found = true;
						index = i;
					}
				}
				if (found == false) {
					cout << "Error: This person does not exist on the dodgeball team" << endl;
					system("pause");
					break;
				}
				if (Person[index].getCredits() == 0) {
					cout << "This passenger does not have enough credits to make a reservation" << endl;
					system("pause");
					break;
				}
				else {
					cout << "\nThis passenger has " << Person[index].getCredits() << endl;
					system("pause");
					system("cls");
					cout << "-Pickup-  -Front-" << endl;
					cout << "Purple :  (" << purplePickup.getSeatValue(0) << ") (" << purplePickup.getSeatValue(1) << ")" << endl;
					cout << "Green  :  (" << greenPickup.getSeatValue(0) << ") (" << greenPickup.getSeatValue(1) << ")" << endl;
					cout << "Black  :  (" << blackPickup.getSeatValue(0) << ") (" << blackPickup.getSeatValue(1) << ")" << endl;
					cout << endl;
					cout << "-Compact- -Front- -Rear--" << endl;
					cout << "Red    :  (" << redCompact.getSeatValue(0) << ") (" << redCompact.getSeatValue(1) << ") (" << redCompact.getSeatValue(2) << ") (" << redCompact.getSeatValue(3) << ")" << endl;
					cout << "Blue   :  (" << blueCompact.getSeatValue(0) << ") (" << blueCompact.getSeatValue(1) << ") (" << blueCompact.getSeatValue(2) << ") (" << blueCompact.getSeatValue(3) << ")" << endl;
					cout << "Yellow :  (" << yellowCompact.getSeatValue(0) << ") (" << yellowCompact.getSeatValue(1) << ") (" << yellowCompact.getSeatValue(2) << ") (" << yellowCompact.getSeatValue(3) << ")" << endl;
					cout << endl;
					cout << "-Sedan-   -Front- ----Rear---" << endl;
					cout << "Blue   :  (" << blueSedan.getSeatValue(0) << ") (" << blueSedan.getSeatValue(1) << ") (" << blueSedan.getSeatValue(2) << ") (" << blueSedan.getSeatValue(3) << ") (" << blueSedan.getSeatValue(3) << ")" << endl;
					cout << "Black  :  (" << blackSedan.getSeatValue(0) << ") (" << blackSedan.getSeatValue(1) << ") (" << blackSedan.getSeatValue(2) << ") (" << blackSedan.getSeatValue(3) << ") (" << blackSedan.getSeatValue(3) << ")" << endl;
					cout << "Green  :  (" << greenSedan.getSeatValue(0) << ") (" << greenSedan.getSeatValue(1) << ") (" << greenSedan.getSeatValue(2) << ") (" << greenSedan.getSeatValue(3) << ") (" << greenSedan.getSeatValue(3) << ")" << endl;
					
					cout << "\nPlease select a seat: ";
					cin >> seatSelection;
					bool found = false;
					if (seatSelection == "front-seat") {
						Person[index].setPIN(purplePickup.findSeat(Person[index].getCredits(), 1));
						purplePickup.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
						if (Person[index].getPIN() != 000) {
							break;
						}
						Person[index].setPIN(greenPickup.findSeat(Person[index].getCredits(), 1));
						greenPickup.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
						if (Person[index].getPIN() != 000) {
							break;
						}
						Person[index].setPIN(blackPickup.findSeat(Person[index].getCredits(), 1));
						blackPickup.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
						if (Person[index].getPIN() != 000) {
							break;
						}
						Person[index].setPIN(redCompact.findSeat(Person[index].getCredits(), 1));
						redCompact.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
						if (Person[index].getPIN() != 000) {
							break;
						}
						Person[index].setPIN(blueCompact.findSeat(Person[index].getCredits(), 1));
						blueCompact.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
						if (Person[index].getPIN() != 000) {
							break;
						}
						Person[index].setPIN(yellowCompact.findSeat(Person[index].getCredits(), 1));
						yellowCompact.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
						if (Person[index].getPIN() != 000) {
							break;
						}
						Person[index].setPIN(blueSedan.findSeat(Person[index].getCredits(), 1));
						blueSedan.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
						if (Person[index].getPIN() != 000) {
							break;
						}
						Person[index].setPIN(blackSedan.findSeat(Person[index].getCredits(), 1));
						blackSedan.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
						if (Person[index].getPIN() != 000) {
							break;
						}
						Person[index].setPIN(greenSedan.findSeat(Person[index].getCredits(), 1));
						greenSedan.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
						if (Person[index].getPIN() != 000) {
							break;
						}
					}
					if (seatSelection == "Back-Window") {
						Person[index].setPIN(redCompact.findSeat(Person[index].getCredits(), 2));
						redCompact.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
						if (Person[index].getPIN() != 000) {
							break;
						}
						Person[index].setPIN(blueCompact.findSeat(Person[index].getCredits(), 2));
						blueCompact.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
						if (Person[index].getPIN() != 000) {
							break;
						}
						Person[index].setPIN(yellowCompact.findSeat(Person[index].getCredits(), 2));
						yellowCompact.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
						if (Person[index].getPIN() != 000) {
							break;
						}
						Person[index].setPIN(blueSedan.findSeat(Person[index].getCredits(), 2));
						blueSedan.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
						if (Person[index].getPIN() != 000) {
							break;
						}
						Person[index].setPIN(blackSedan.findSeat(Person[index].getCredits(), 2));
						blackSedan.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
						if (Person[index].getPIN() != 000) {
							break;
						}
						Person[index].setPIN(greenSedan.findSeat(Person[index].getCredits(), 2));
						greenSedan.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
						if (Person[index].getPIN() != 000) {
							break;
						}
					}
					if (seatSelection == "Middle-Seat") {
						Person[index].setPIN(blueSedan.findSeat(Person[index].getCredits(), 3));
						blueSedan.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
						if (Person[index].getPIN() != 000) {
							break;
						}
						Person[index].setPIN(blackSedan.findSeat(Person[index].getCredits(), 3));
						blackSedan.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
						if (Person[index].getPIN() != 000) {
							break;
						}
						Person[index].setPIN(greenSedan.findSeat(Person[index].getCredits(), 3));
						greenSedan.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
						if (Person[index].getPIN() != 000) {
							break;
						}
					}

				}
				cout << "Reservation Created" << endl;
				system("pause");
				break;
			}
			else if (choice == 2) {
				system("cls");
				string name;
				int pinNum;
				bool found = false;
				bool foundReserve = false;
				int index;

				cout << "Please Enter Passenger's Name: ";
				cin >> name;
				for (int i = 0; i < Person.size(); i++) {
					if (name == Person[i].getFirstname()) {
						found = true;
						index = i;
					}
				}
				if (found == false) {
					cout << "Error: This person does not exist on the dodgeball team" << endl;
					system("pause");
					break;
				}
				cout << endl;
				cout << "Please Enter Reservation PIN: ";
				cin >> pinNum;
				if (pinNum == Person[index].getPIN()) {
					foundReserve = true;
					choice = 1;
					cout << "Please Create new Reservation for that passenger" << endl;
				}
				if (foundReserve == false) {
					cout << "Error: There is no reservation under that PIN number" << endl;
					system("pause");
					break;
				}
				system("pause");
				break;
			}
			else if (choice == 3) {
				system("cls");
				string name;
				int pinNum;
				bool found = false;
				bool foundReserve = false;
				int index;

				cout << "Please Enter Passenger's Name: ";
				cin >> name;
				for (int i = 0; i < Person.size(); i++) {
					if (name == Person[i].getFirstname()) {
						found = true;
						index = i;
					}
				}
				if (found == false) {
					cout << "Error: This person does not exist on the dodgeball team" << endl;
					system("pause");
					break;
				}
				cout << endl;
				cout << "Please Enter Reservation PIN: ";
				cin >> pinNum;
				if (pinNum == Person[index].getPIN()) {
					foundReserve = true;
					Person[index].setPIN(000);
					if (pinNum == 101) {
						purplePickup.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == 201) {
						greenPickup.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == 301) {
						blackPickup.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == 401) {
						redCompact.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == 501) {
						blueCompact.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == 601) {
						yellowCompact.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == 701) {
						blueSedan.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == 801) {
						blackSedan.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == 901) {
						greenSedan.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}

					else if (pinNum == 402) {
						redCompact.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == 502) {
						blueCompact.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == 602) {
						yellowCompact.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == 702) {
						blueSedan.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == 802) {
						blackSedan.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == 902) {
						greenSedan.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}

					else if (pinNum == 403) {
						redCompact.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == 503) {
						blueCompact.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == 603) {
						yellowCompact.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == 703) {
						blueSedan.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == 803) {
						blackSedan.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == 903) {
						greenSedan.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}

					else if (pinNum == 704) {
						blueSedan.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == 804) {
						blackSedan.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == 904) {
						greenSedan.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
				}
				if (foundReserve == false) {
					cout << "Error: There is no reservation under that PIN number" << endl;
					system("pause");
					break;
				}
				break;
			}
			else if (choice == 4) {
				system("cls");
				cout << "-Pickup-  -Front-" << endl;
				cout << "Purple :  (" << purplePickup.getSeatValue(0) << ") (" << purplePickup.getSeatValue(1) << ")" << endl;
				cout << "Green  :  (" << greenPickup.getSeatValue(0) << ") (" << greenPickup.getSeatValue(1) << ")" << endl;
				cout << "Black  :  (" << blackPickup.getSeatValue(0) << ") (" << blackPickup.getSeatValue(1) << ")" << endl;
				cout << endl;
				cout << "-Compact- -Front- -Rear--" << endl;
				cout << "Red    :  (" << redCompact.getSeatValue(0) << ") (" << redCompact.getSeatValue(1) << ") (" << redCompact.getSeatValue(2) << ") (" << redCompact.getSeatValue(3) << ")" << endl;
				cout << "Blue   :  (" << blueCompact.getSeatValue(0) << ") (" << blueCompact.getSeatValue(1) << ") (" << blueCompact.getSeatValue(2) << ") (" << blueCompact.getSeatValue(3) << ")" << endl;
				cout << "Yellow :  (" << yellowCompact.getSeatValue(0) << ") (" << yellowCompact.getSeatValue(1) << ") (" << yellowCompact.getSeatValue(2) << ") (" << yellowCompact.getSeatValue(3) << ")" << endl;
				cout << endl;
				cout << "-Sedan-   -Front- ----Rear---" << endl;
				cout << "Blue   :  (" << blueSedan.getSeatValue(0) << ") (" << blueSedan.getSeatValue(1) << ") (" << blueSedan.getSeatValue(2) << ") (" << blueSedan.getSeatValue(3) << ") (" << blueSedan.getSeatValue(3) << ")" << endl;
				cout << "Black  :  (" << blackSedan.getSeatValue(0) << ") (" << blackSedan.getSeatValue(1) << ") (" << blackSedan.getSeatValue(2) << ") (" << blackSedan.getSeatValue(3) << ") (" << blackSedan.getSeatValue(3) << ")" << endl;
				cout << "Green  :  (" << greenSedan.getSeatValue(0) << ") (" << greenSedan.getSeatValue(1) << ") (" << greenSedan.getSeatValue(2) << ") (" << greenSedan.getSeatValue(3) << ") (" << greenSedan.getSeatValue(3) << ")" << endl;
				system("pause");
				break;
			}
			else if (choice == 5) {
				system("cls");

				string filename;

				filename = "all_reservations.txt";

				ofstream outFile(filename);

				if (outFile.is_open()) {
					for (int i = 0; i < purplePickup.passengerListSize(); i++) {
						cout << purplePickup.getPassenger(i) << " ";
						outFile << purplePickup.getPassenger(i) << endl;
					}
					for (int i = 0; i < greenPickup.passengerListSize(); i++) {
						cout << greenPickup.getPassenger(i) << " ";
						outFile << greenPickup.getPassenger(i) << endl;
					}
					for (int i = 0; i < blackPickup.passengerListSize(); i++) {
						cout << blackPickup.getPassenger(i) << " ";
						outFile << blackPickup.getPassenger(i) << endl;
					}
					for (int i = 0; i < redCompact.passengerListSize(); i++) {
						cout << redCompact.getPassenger(i) << " ";
						outFile << redCompact.getPassenger(i) << endl;
					}
					for (int i = 0; i < blueCompact.passengerListSize(); i++) {
						cout << blueCompact.getPassenger(i) << " ";
						outFile << blueCompact.getPassenger(i) << endl;
					}
					for (int i = 0; i < yellowCompact.passengerListSize(); i++) {
						cout << yellowCompact.getPassenger(i) << " ";
						outFile << yellowCompact.getPassenger(i) << endl;
					}
					for (int i = 0; i < blueSedan.passengerListSize(); i++) {
						cout << blueSedan.getPassenger(i) << " ";
						outFile << blueSedan.getPassenger(i) << endl;
					}
					for (int i = 0; i < blackSedan.passengerListSize(); i++) {
						cout << blackSedan.getPassenger(i) << " ";
						outFile << blackSedan.getPassenger(i) << endl;
					}
					for (int i = 0; i < greenSedan.passengerListSize(); i++) {
						cout << greenSedan.getPassenger(i) << " ";
						outFile << greenSedan.getPassenger(i) << endl;
					}
				}
				system("pause");
				break;
			}
			else if (choice == 6) {
				system("cls");
				
				string vehicle;
				string filename;

				cout << "Please Select a vehicle to display: ";
				cin >> vehicle;

				filename = vehicle + ".txt";
				cout << filename;

				ofstream outFile(filename);

				if (outFile.is_open()) {
					if (vehicle == "purple_pickup") {
						for (int i = 0; i < purplePickup.passengerListSize(); i++) {
							cout << purplePickup.getPassenger(i) << " ";
							outFile << purplePickup.getPassenger(i) << endl;
						}
					}
					if (vehicle == "green_pickup") {
						for (int i = 0; i < greenPickup.passengerListSize(); i++) {
							cout << greenPickup.getPassenger(i) << " ";
							outFile << greenPickup.getPassenger(i) << endl;
						}
					}
					if (vehicle == "black_pickup") {
						for (int i = 0; i < blackPickup.passengerListSize(); i++) {
							cout << blackPickup.getPassenger(i) << " ";
							outFile << blackPickup.getPassenger(i) << endl;
						}
					}
					if (vehicle == "red_compact") {
						for (int i = 0; i < redCompact.passengerListSize(); i++) {
							cout << redCompact.getPassenger(i) << " ";
							outFile << redCompact.getPassenger(i) << endl;
						}
					}
					if (vehicle == "blue_compact") {
						for (int i = 0; i < blueCompact.passengerListSize(); i++) {
							cout << blueCompact.getPassenger(i) << " ";
							outFile << blueCompact.getPassenger(i) << endl;
						}
					}
					if (vehicle == "yellow_compact") {
						for (int i = 0; i < yellowCompact.passengerListSize(); i++) {
							cout << yellowCompact.getPassenger(i) << " ";
							outFile << yellowCompact.getPassenger(i) << endl;
						}
					}
					if (vehicle == "blue_sedan") {
						for (int i = 0; i < blueSedan.passengerListSize(); i++) {
							cout << blueSedan.getPassenger(i) << " ";
							outFile << blueSedan.getPassenger(i) << endl;
						}
					}
					if (vehicle == "black_sedan") {
						for (int i = 0; i < blackSedan.passengerListSize(); i++) {
							cout << blackSedan.getPassenger(i) << " ";
							outFile << blackSedan.getPassenger(i) << endl;
						}
					}
					if (vehicle == "green_sedan") {
						for (int i = 0; i < greenSedan.passengerListSize(); i++) {
							cout << greenSedan.getPassenger(i) << " ";
							outFile << greenSedan.getPassenger(i) << endl;
						}
					}
				}
				outFile.close();
				system("pause");
				break;
			}
		}
	}
	inFile.close();
}

/*
	cout << "-Pickup-  -Front-" << endl;
	cout << "Purple :  (" << purplePickupSeats[0] << ") (" << purplePickupSeats[1] << ")" << endl;
	cout << "Green  :  (" << greenPickupSeats[0] << ") (" << greenPickupSeats[1] << ")" << endl;
	cout << "Black  :  (" << blackPickupSeats[0] << ") (" << blackPickupSeats[1] << ")" << endl;
	cout << endl;
	cout << "-Compact- -Front- -Rear--" << endl;
	cout << "Red    :  (" << redCompact[0] << ") (" << redCompact[1] << ") (" << redCompact[2] << ") (" << redCompact[3] << ")" << endl;
	cout << "Blue   :  (" << blueCompact[0] << ") (" << blueCompact[1] << ") (" << blueCompact[2] << ") (" << blueCompact[3] << ")" << endl;
	cout << "Yellow :  (" << yellowCompact[0] << ") (" << yellowCompact[1] << ") (" << yellowCompact[2] << ") (" << yellowCompact[3] << ")" << endl;
	cout << endl;
	cout << "-Sedan-   -Front- ----Rear---" << endl;
	cout << "Blue   :  (" << blueSedan[0] << ") (" << blueSedan[1] << ") (" << blueSedan[2] << ") (" << blueSedan[3] << ") (" << blueSedan[4] << ")" << endl;
	cout << "Black  :  (" << blackSedan[0] << ") (" << blackSedan[1] << ") (" << blackSedan[2] << ") (" << blackSedan[3] << ") (" << blackSedan[4] << ")" << endl;
	cout << "Green  :  (" << greenSedan[0] << ") (" << greenSedan[1] << ") (" << greenSedan[2] << ") (" << greenSedan[3] << ") (" << greenSedan[4] << ")" << endl;
*/