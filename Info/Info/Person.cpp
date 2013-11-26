#include "Person.h"


Person::Person() {
	fname[0] = '\0';
	lname[0] = '\0';
	phoneno[0] = '\0';
	address[0] = '\0';
	sinno[0] = '\0';
}


Person::~Person() {

}

// Add person main menu.
void Person::menu() {
	system("cls");

	int choice;
	
	do {
		cout << endl;
		cout << setw(25) << "   New Profile" << endl;
		cout << setw(25) << setfill('-') << "" << endl;
		cout << setw(25) << setfill(' ') << "1. Create new profile" << endl;
		cout << setw(25) << "2. Change existing profile" << endl;
		cout << setw(25) << "3. Return to main menu" << endl << endl;
		cout << setw(25) << "Please select an option: ";

		cin >> choice;		
		cin.ignore();

		switch(choice) {
		case 1:
			createProfile();
			break;
		case 2:
			// change existing. ********************
			break;
		case 3:
			system("cls");
			return;
		}
	} while (choice != 3);
}

// Create new profile.
void Person::createProfile() {	
	system("cls");

	ofstream newProfile;
	char filename[MSIN + 4];

	filename[0] = '\0';

	cout << endl;
	cout << "First Name: ";
	cin.getline(fname, MNAME);

	cout << "Last Name: ";
	cin.getline(lname, MNAME);

	cout << "Phone Number: ";
	cin.getline(phoneno, MPHONE);

	cout << "Address: ";
	cin.getline(address, MADDRESS);

	cout << "SIN #: ";
	cin.getline(sinno, MSIN);   /* * * * *  ADD error checking.  * * * * */
	
	/* * * * * * add code HERE to check for valid(non repeated) SIN # * * * * * */

	strcat(filename, sinno);
	strcat(filename, ".txt");
	newProfile.open(filename);

	newProfile << fname << endl;
	newProfile << lname << endl;
	newProfile << phoneno << endl;
	newProfile << address << endl;
	newProfile << sinno << endl;
	newProfile.close();

	cout << endl << "New Profile Created (" << sinno << ")." << endl << endl;
	getchar();
	system("cls");
}




void Person::viewProfile() {
	ofstream openFile;

	char filename[MSIN];
	bool checked = false;

	filename[0] = '\0';

	do {
		cout << "Please enter SIN# of profile you would like to view. (0 to quit)" << endl;
		cout << "SIN #: ";
			
		cin >> filename;

		if (filename[0] == '0') {
			checked = true;
			break;
		}
		else if (strlen(filename) != MSIN) {
			cout << "SIN# must be 9 numbers.";
			checked = false;
		}

		else if (strlen(filename) == MSIN)
			checked = true;
	} while (!checked);	



}