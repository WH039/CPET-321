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
	cout << "[0] Exit" << endl;
}

void displayPickups(int seatNum, string color,string carType, Pickup carColor) {
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

	/*
	for (int i = 0; i < Person.size(); i++) {
		cout << Person[i].getFirstname() << " " << Person[i].getLastname() << " " << Person[i].getCredits() << endl;
	}
	*/

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

	/*
	Compact redCompact, blueCompact, yellowCompact;
	Sedan blueSedan, blackSedan, greenSedan;
	Pickup purplePickup, greenPickup, blackPickup;

	vector<Compact> compactCars = { redCompact, blueCompact, yellowCompact };
	vector<Sedan> sedanCars = { blueSedan, blackSedan, greenSedan };
	vector<Pickup> pickupCars = { purplePickup, greenPickup, blackPickup };
	
	for (int t = 0; t < 9; t++) {
		if (t < 3) {
			pickupCars[t].assignVehicle(Person[t].getFirstname());
		}
		if (t >= 3 && t < 6) {
			compactCars[t-3].assignVehicle(Person[t-3].getFirstname());
		}
		if (t >= 6) {
			sedanCars[t-6].assignVehicle(Person[t-6].getFirstname());
		}
	}
	*/

	

	int choice = -1;

	while (choice != 0) {
		displayMenu();

		cin >> choice;

		while (choice != 0) {
			if (choice == 1) {
				system("cls");
				string name;
				bool found = false;
				int index;
				string seatSelection;
				string carSelect;
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
					cout << "\nCredits: " << Person[index].getCredits() << endl;
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
					}
					cout << endl << endl;
					
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
									cout << "No front seat available please choose a different vehicle" << endl;
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
									cout << "No front seat available please choose a different vehicle" << endl;
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
									cout << "No front seat available please choose a different vehicle" << endl;
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
									cout << "No front seat available please choose a different vehicle" << endl;
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
									cout << "No front seat available please choose a different vehicle" << endl;
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
									cout << "No front seat available please choose a different vehicle" << endl;
									system("pause");
									break;
								}
							}
						}
					}

				}
				cout << "Reservation Created." << endl;
				cout << "Reservation PIN number: " << Person[index].getPIN() << endl;
				system("pause");
				break;
			}

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
			}
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
			} //if
		} //while 2
		system("cls");
	} //while 1
	File.close();
}