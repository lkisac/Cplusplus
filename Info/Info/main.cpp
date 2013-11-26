#include <cstdio>
#include <iostream>
#include <iomanip>
#include "Student.h"

using namespace std;


/* 
This program will prompt the user to enter information. 
A user can input personal, student, or employee information about him/herself.

*/

char mainmenu(istream& is);
char entermenu(istream& is);
void viewmenu();

int main () {
	
	int userChoice;

	do {
		// call main menu.
		userChoice = mainmenu(cin);

		switch(userChoice) {
		case 1:
			int c1;
			c1 = entermenu(cin);			

			break;
		case 2:
			//call viewmenu();
			break;
		case 3:
			//call extra();
			break;
		}

	} while (userChoice != 4);

	getchar();
}


// Main Menu.
char mainmenu(istream& is) {

	system("cls");
	
	int uc;

	cout << endl;
	cout << setw(25) << left << "      Main Menu" << endl;
	cout << setw(25) << setfill('-') << "" << endl;

	cout << setw(25) << setfill(' ') << "1. Enter information" << endl;
	cout << setw(25) << "2. View information" << endl;
	cout << setw(25) << "3. Extra..." << endl;
	cout << setw(25) << "4. Exit" << endl << endl;

	cout << setw(25) << "Please select an option: ";
    
	cin >> uc;

	return uc;
}


// Enter Information Menu.
char entermenu(istream& is) {

	system("cls");
	Person person;
	Student student;

	int ec;

	do {
		cout << endl;
		cout << setw(25) << left << "   Enter Information" << endl;
		cout << setw(25) << setfill('-') << "" << endl;

		cout << setw(25) << setfill(' ') << "1. Create Personal Profile" << endl;
		cout << setw(25) << "2. Add Student Information" << endl;
		cout << setw(25) << "3. Add Work Information" << endl;
		cout << setw(25) << "4. Back to Main menu" << endl << endl;

		cout << setw(25) << "Please select an option: ";
        
		cin >> ec;
		cin.ignore();

		switch(ec) {
		case 1:
			person.menu();
			break;
		case 2:
			// Add Student Information.
			student.addStudentInfo();
			break;
		case 3:
			// Add Work Information.
			break;
		case 4:
			break;
		}

	} while (ec != 4);


	return ec;

}




void viewmenu() {
	system("cls");
	Person person;
	Student student;

	int ec;

	do {
		cout << endl;
		cout << setw(25) << left << "    View Information" << endl;
		cout << setw(25) << setfill('-') << "" << endl;

		cout << setw(25) << setfill(' ') << "1. View Personal Profile" << endl;
		cout << setw(25) << "2. View Student Information" << endl;
		cout << setw(25) << "3. View Work Information" << endl;
		cout << setw(25) << "4. Back to Main menu" << endl << endl;

		cout << setw(25) << "Please select an option: ";
        
		cin >> ec;
		cin.ignore();

		switch(ec) {
		case 1:
			person.viewProfile();
			break;
		case 2:
			// Add Student Information.
			student.addStudentInfo();
			break;
		case 3:
			// Add Work Information.
			break;
		case 4:
			break;
		}

	} while (ec != 4);

}