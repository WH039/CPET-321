////////////////////////////////////////////////////////////////////////////////////////////////////
/// File Name   : main.cpp																		 ///
/// Designers   : Weicheng Huang, James Musonda													 ///
/// Course      : Computational Problem Solving II												 ///
///				  CPET.321.01 / L01                                                              ///
/// Notes       :																				 ///
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Vehicle.h"
#include "Compact.h"
#include "Sedan.h"
#include "Pickup.h"
#include "Reservation.h"

using namespace std;

static void displayMenu() {
	cout << "Welcome to the Carpool Reservation System" << endl;
	cout << "Please Select an Option:" << endl;
	cout << "________________________" << endl;
	cout << "[1] Create a Reservation" << endl;
	cout << "[2] Modify a Reservation" << endl;
	cout << "[3] Delete a Reservation" << endl;
	cout << "[4] Display all Vehicles" << endl;
	cout << "[5] Print All Reservations" << endl;
	cout << "[6] Print Vehicle Assignments" << endl;
	cout << "[0] Exit" << endl << endl;;
	cout << "Selection: ";
}

void displayPickups(int seatNum, string color, string carType, Pickup carColor) {
	for (int t = 0; t < seatNum; ++t) {
		if (t == 0) {
			cout << color << endl;
		}
		cout << "(" << carColor.getSeatValue(t) << ")";
	} //for
	cout << endl << endl;
}
void displayCompacts(int seatNum, string color, string carType, Compact carColor) {
	for (int t = 0; t < seatNum; ++t) {
		if (t == 0) {
			cout << color << endl;
		}
		if (t == 2) { cout << endl; }
		cout << "(" << carColor.getSeatValue(t) << ")";
	} //for
	cout << endl << endl;
}
void displaySedans(int seatNum, string color, string carType, Sedan carColor) {
	for (int t = 0; t < seatNum; ++t) {
		if (t == 0) {
			cout << color << endl;
		}
		if (t == 1) { cout << "   "; }
		if (t == 2) { cout << endl; }
		cout << "(" << carColor.getSeatValue(t) << ")";
	} //for
	cout << endl << endl;
}

int main() {

	ifstream File("dodgeball_team.txt");
	if (!File.is_open()) {
		cout << "File not found.\n";
		exit(4);
	}
	vector<Reservation> Person;
	vector<string> driverList;
	vector<string> assignedPeople;
	Reservation tempPerson;
	string firstName;
	string lastName;
	int credits = 0;
	int t = 0;

	while (File.good()) {
		if (t < 9) {
			File >> firstName >> lastName;
			driverList.push_back(firstName);
		}
		else {
			File >> firstName >> lastName >> credits;
		}
		tempPerson.setFirstName(firstName);
		tempPerson.setLastName(lastName);
		tempPerson.setCredits(credits);
		Person.push_back(tempPerson);
		t++;
	}

	Pickup purplePickup;
	purplePickup.assignVehicle(Person[0].getFirstname());
	//cout << purplePickup.getColor();
	Pickup greenPickup;
	greenPickup.assignVehicle(Person[1].getFirstname());
	//cout << greenPickup.getColor();
	Pickup blackPickup;
	blackPickup.assignVehicle(Person[2].getFirstname());
	//cout << blackPickup.getColor();

	Compact redCompact;
	redCompact.assignVehicle(Person[3].getFirstname());
	//cout << redCompact.getColor();
	Compact blueCompact;
	blueCompact.assignVehicle(Person[4].getFirstname());
	//cout << blueCompact.getColor();
	Compact yellowCompact;
	yellowCompact.assignVehicle(Person[5].getFirstname());
	//cout << yellowCompact.getColor();

	Sedan blueSedan;
	blueSedan.assignVehicle(Person[6].getFirstname());
	//cout << blueSedan.getColor();
	Sedan blackSedan;
	blackSedan.assignVehicle(Person[7].getFirstname());
	//cout << blackSedan.getColor();
	Sedan greenSedan;
	greenSedan.assignVehicle(Person[8].getFirstname());
	//cout << greenSedan.getColor();

	int choice = -1;

	while (choice != 0) {
		displayMenu();

		cin >> choice;

		while (choice != 0) {
			if (choice == 1) {
				system("cls");
				string name;
				bool found;
				bool proceed;
				int index;
				string seatSelection;
				string carSelect;

			do {
				found = false;
				proceed = true;

				cout << "Please enter the passenger's name: ";
				cin >> name;

				for (int t = 0; t < assignedPeople.size(); t++) {
					if (name == assignedPeople[t]) {
						found = true;
						proceed = false;
						cout << name << " has a seat already.\n";
					}
				}
				for (int i = 0; i < Person.size(); i++) {
					if (name == Person[i].getFirstname() && proceed) {
						found = true;
						index = i;
						if (Person[index].getCredits() == 0) {
							cout << name << " has no credits." << endl;
							proceed = false;
							break;
						}
						else {
							cout << "\nCredits: " << Person[index].getCredits() << endl;
						}
					} //if
				} //for
				if (!found) {
					cout << "Player not found." << endl;
					proceed = false;
				}
			} while (!found || !proceed);

			do {
				proceed = true;
				cout << "Select your display (Pickup/Compact/Sedan): ";
				cin >> carSelect;

				system("cls");

				if (carSelect == "Pickup") {
					cout << "Pickups\n--------\n\n";
					displayPickups(2, "Purple", "Pickup", purplePickup);
					displayPickups(2, "Green", "Pickup", greenPickup);
					displayPickups(2, "Black", "Pickup", blackPickup);
				}
				else if (carSelect == "Compact") {
					cout << "Compact\n--------\n\n";
					displayCompacts(4, "Red", "Compact", redCompact);
					displayCompacts(4, "Blue", "Compact", blueCompact);
					displayCompacts(4, "Yellow", "Compact", yellowCompact);
				}
				else if (carSelect == "Sedan") {
					cout << "Sedan\n--------\n\n";
					displaySedans(5, "Blue", "Sedan", blueSedan);
					displaySedans(5, "Black", "Sedan", blackSedan);
					displaySedans(5, "Green", "Sedan", greenSedan);
				}
				else {
					cout << "Invalid input.\n";
					proceed = false;
				}
				cout << endl << endl;
			} while (!proceed);

			do {
				proceed = true;
				cout << "Options: [front] [window] [middle]";
				cout << "\nSelect your seat: ";
				cin >> seatSelection;

				//Front seat
				if (seatSelection == "front" && carSelect == "Pickup") {
					Person[index].setPIN(purplePickup.findSeat(Person[index].getCredits(), 1));
					purplePickup.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
					if (Person[index].getPIN() == "000") {
						Person[index].setPIN(greenPickup.findSeat(Person[index].getCredits(), 1));
						greenPickup.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
						if (Person[index].getPIN() == "000") {
							Person[index].setPIN(blackPickup.findSeat(Person[index].getCredits(), 1));
							blackPickup.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
							if (Person[index].getPIN() == "000") {
								cout << "No front seats available." << endl;
								system("pause");
								break;
							}
						}
					}
				}

				if (seatSelection == "front" && carSelect == "Compact") {
					Person[index].setPIN(redCompact.findSeat(Person[index].getCredits(), 1));
					redCompact.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
					if (Person[index].getPIN() == "000") {
						Person[index].setPIN(blueCompact.findSeat(Person[index].getCredits(), 1));
						blueCompact.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
						if (Person[index].getPIN() == "000") {
							Person[index].setPIN(yellowCompact.findSeat(Person[index].getCredits(), 1));
							yellowCompact.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
							if (Person[index].getPIN() == "000") {
								cout << "No front seats available." << endl;
								system("pause");
								break;
							}
						}
					}
				}

				if (seatSelection == "front" && carSelect == "Sedan") {
					Person[index].setPIN(blueSedan.findSeat(Person[index].getCredits(), 1));
					blueSedan.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
					if (Person[index].getPIN() == "000") {
						Person[index].setPIN(blackSedan.findSeat(Person[index].getCredits(), 1));
						blackSedan.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
						if (Person[index].getPIN() == "000") {
							Person[index].setPIN(greenSedan.findSeat(Person[index].getCredits(), 1));
							greenSedan.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
							if (Person[index].getPIN() == "000") {
								cout << "No front seats available." << endl;
								system("pause");
								break;
							}
						}
					}
				}

				//Window seat
				if (seatSelection == "window" && carSelect == "Compact") {
					Person[index].setPIN(redCompact.findSeat(Person[index].getCredits(), 1));
					redCompact.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
					if (Person[index].getPIN() == "000") {
						Person[index].setPIN(blueCompact.findSeat(Person[index].getCredits(), 1));
						blueCompact.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
						if (Person[index].getPIN() == "000") {
							Person[index].setPIN(yellowCompact.findSeat(Person[index].getCredits(), 1));
							yellowCompact.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
							if (Person[index].getPIN() == "000") {
								cout << "No window seats available." << endl;
								system("pause");
								break;
							}
						}
					}
				}

				if (seatSelection == "window" && carSelect == "Sedan") {
					Person[index].setPIN(blueSedan.findSeat(Person[index].getCredits(), 2));
					blueSedan.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
					if (Person[index].getPIN() == "000") {
						Person[index].setPIN(blackSedan.findSeat(Person[index].getCredits(), 2));
						blackSedan.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
						if (Person[index].getPIN() == "000") {
							Person[index].setPIN(greenSedan.findSeat(Person[index].getCredits(), 2));
							greenSedan.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
							if (Person[index].getPIN() == "000") {
								cout << "No window seats available." << endl;
								system("pause");
								break;
							}
						}
					}
				}

				//Middle seat
				if (seatSelection == "middle" && carSelect == "Sedan") {
					Person[index].setPIN(blueSedan.findSeat(Person[index].getCredits(), 3));
					blueSedan.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
					if (Person[index].getPIN() == "000") {
						Person[index].setPIN(blackSedan.findSeat(Person[index].getCredits(), 3));
						blackSedan.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
						if (Person[index].getPIN() == "000") {
							Person[index].setPIN(greenSedan.findSeat(Person[index].getCredits(), 3));
							greenSedan.addPassenger(Person[index].getFirstname(), Person[index].getLastname());
							if (Person[index].getPIN() == "000") {
								cout << "No window seats available." << endl;
								system("pause");
								break;
							}
						}
					}
				}
			} while (!proceed);
				cout << "Reservation Created." << endl;
				cout << "Reservation PIN number: " << Person[index].getPIN() << endl;
				assignedPeople.push_back(name);
				system("pause");
				break;
			} //if(1)
			else if (choice == 2) {
				system("cls");
				string name;
				string pinNum;
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
				if (found == false) { cout << "Player not found." << endl; }
				cout << endl;

				cout << "Please Enter Reservation PIN: ";
				cin >> pinNum;
				if (pinNum == Person[index].getPIN()) {
					foundReserve = true;
					choice = 1;
					cout << "Please create a new reservation." << endl;
				}
				if (!foundReserve) { cout << "There is no reservation under that PIN number." << endl; }
				system("pause");
			} //if (2)
			else if (choice == 3) {
				system("cls");
				string name;
				string pinNum;
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
					cout << "Player not found." << endl;
					system("pause");
					break;
				}
				cout << endl;
				cout << "Please Enter Reservation PIN: ";
				cin >> pinNum;
				if (pinNum == Person[index].getPIN()) {
					foundReserve = true;
					Person[index].setPIN("000");
					if (pinNum == "101") {
						purplePickup.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == "201") {
						greenPickup.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == "301") {
						blackPickup.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == "401") {
						redCompact.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == "501") {
						blueCompact.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == "601") {
						yellowCompact.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == "701") {
						blueSedan.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == "801") {
						blackSedan.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == "901") {
						greenSedan.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}

					else if (pinNum == "402") {
						redCompact.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == "502") {
						blueCompact.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == "602") {
						yellowCompact.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == "702") {
						blueSedan.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == "802") {
						blackSedan.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == "902") {
						greenSedan.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}

					else if (pinNum == "403") {
						redCompact.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == "503") {
						blueCompact.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == "603") {
						yellowCompact.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == "703") {
						blueSedan.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == "803") {
						blackSedan.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == "903") {
						greenSedan.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}

					else if (pinNum == "704") {
						blueSedan.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == "804") {
						blackSedan.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
					else if (pinNum == "904") {
						greenSedan.removePassenger(Person[index].getFirstname(), Person[index].getLastname(), pinNum);
					}
				}
				if (foundReserve == false) {
					cout << "No reservation under that PIN number." << endl;
					system("pause");
					break;
				}
				break;
			} //if(3)
			else if (choice == 4) {
				system("cls");
				cout << "Pickup\n--------\n\n";
				displayPickups(2, "Purple", "Pickup", purplePickup);
				displayPickups(2, "Green", "Pickup", greenPickup);
				displayPickups(2, "Black", "Pickup", blackPickup);
				cout << "Compact\n--------\n\n";
				displayCompacts(4, "Red", "Compact", redCompact);
				displayCompacts(4, "Blue", "Compact", blueCompact);
				displayCompacts(4, "Yellow", "Compact", yellowCompact);
				cout << "Sedan\n--------\n\n";
				displaySedans(5, "Blue", "Sedan", blueSedan);
				displaySedans(5, "Black", "Sedan", blackSedan);
				displaySedans(5, "Green", "Sedan", greenSedan);
				cout << endl << endl;
				system("pause");
				break;
			} //if(4)
			else if (choice == 5) {
				system("cls");

				string filename;

				filename = "all_reservations.txt";

				ofstream outFile(filename);

				if (outFile.is_open()) {
					for (int i = 0; i < purplePickup.passengerListSize(); i++) {
						cout << purplePickup.getPassenger(i) << " \n";
						outFile << purplePickup.getPassenger(i) << endl;
					}
					for (int i = 0; i < greenPickup.passengerListSize(); i++) {
						cout << greenPickup.getPassenger(i) << " \n";
						outFile << greenPickup.getPassenger(i) << endl;
					}
					for (int i = 0; i < blackPickup.passengerListSize(); i++) {
						cout << blackPickup.getPassenger(i) << " \n";
						outFile << blackPickup.getPassenger(i) << endl;
					}
					for (int i = 0; i < redCompact.passengerListSize(); i++) {
						cout << redCompact.getPassenger(i) << " \n";
						outFile << redCompact.getPassenger(i) << endl;
					}
					for (int i = 0; i < blueCompact.passengerListSize(); i++) {
						cout << blueCompact.getPassenger(i) << " \n";
						outFile << blueCompact.getPassenger(i) << endl;
					}
					for (int i = 0; i < yellowCompact.passengerListSize(); i++) {
						cout << yellowCompact.getPassenger(i) << " \n";
						outFile << yellowCompact.getPassenger(i) << endl;
					}
					for (int i = 0; i < blueSedan.passengerListSize(); i++) {
						cout << blueSedan.getPassenger(i) << " \n";
						outFile << blueSedan.getPassenger(i) << endl;
					}
					for (int i = 0; i < blackSedan.passengerListSize(); i++) {
						cout << blackSedan.getPassenger(i) << " \n";
						outFile << blackSedan.getPassenger(i) << endl;
					}
					for (int i = 0; i < greenSedan.passengerListSize(); i++) {
						cout << greenSedan.getPassenger(i) << " \n";
						outFile << greenSedan.getPassenger(i) << endl;
					}
				}
				system("pause");
				break;
			} //if(5)
			else if (choice == 6) {
				system("cls");

				string vehicle;
				string filename;

				cout << "Use the following format to display reservation [purple_pickup].";
				cout << endl << "Selection: ";
				cin >> vehicle;

				filename = vehicle + ".txt";

				ofstream outFile(filename);

				if (outFile.is_open()) {
					if (vehicle == "purple_pickup") {
						for (int i = 0; i < purplePickup.passengerListSize(); i++) {
							cout << purplePickup.getPassenger(i) << " \n";
							outFile << purplePickup.getPassenger(i) << endl;
						}
					}
					if (vehicle == "green_pickup") {
						for (int i = 0; i < greenPickup.passengerListSize(); i++) {
							cout << greenPickup.getPassenger(i) << " \n";
							outFile << greenPickup.getPassenger(i) << endl;
						}
					}
					if (vehicle == "black_pickup") {
						for (int i = 0; i < blackPickup.passengerListSize(); i++) {
							cout << blackPickup.getPassenger(i) << " \n";
							outFile << blackPickup.getPassenger(i) << endl;
						}
					}
					if (vehicle == "red_compact") {
						for (int i = 0; i < redCompact.passengerListSize(); i++) {
							cout << redCompact.getPassenger(i) << " \n";
							outFile << redCompact.getPassenger(i) << endl;
						}
					}
					if (vehicle == "blue_compact") {
						for (int i = 0; i < blueCompact.passengerListSize(); i++) {
							cout << blueCompact.getPassenger(i) << " \n";
							outFile << blueCompact.getPassenger(i) << endl;
						}
					}
					if (vehicle == "yellow_compact") {
						for (int i = 0; i < yellowCompact.passengerListSize(); i++) {
							cout << yellowCompact.getPassenger(i) << " \n";
							outFile << yellowCompact.getPassenger(i) << endl;
						}
					}
					if (vehicle == "blue_sedan") {
						for (int i = 0; i < blueSedan.passengerListSize(); i++) {
							cout << blueSedan.getPassenger(i) << " \n";
							outFile << blueSedan.getPassenger(i) << endl;
						}
					}
					if (vehicle == "black_sedan") {
						for (int i = 0; i < blackSedan.passengerListSize(); i++) {
							cout << blackSedan.getPassenger(i) << " \n";
							outFile << blackSedan.getPassenger(i) << endl;
						}
					}
					if (vehicle == "green_sedan") {
						for (int i = 0; i < greenSedan.passengerListSize(); i++) {
							cout << greenSedan.getPassenger(i) << " \n";
							outFile << greenSedan.getPassenger(i) << endl;
						}
					}
				}
				outFile.close();
				system("pause");
			} //if //if(6)
		} //while 2
		system("cls");
	} //while 1
	File.close();
}