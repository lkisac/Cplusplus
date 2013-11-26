#include "Student.h"

Student::Student() {
	school[0] = '\0';
	program[0] = '\0';
	studentno[0] = '\0';
}

// This method adds student info to a person.
void Student::addStudentInfo() {	
	char file[15];
	FILE* fileToOpen;


	file[0] = '\0';
	cout << "Select person to add by entering SIN # (0 to quit): ";
	cin >> file;
	fileToOpen = open(file);
	cin.ignore(1000, '\n');

	if (file[0] == '0')
		return;
	if (fileToOpen == NULL) {
		cerr << "Error finding file/person." << endl;
		cin.ignore();
		getchar();
	}
	else {
		add(file);
		return;
	}


	system("cls");

}


// Opens person file to add info to.
FILE* Student::open(char filename[]) {
	FILE* fp;

	if (filename != NULL) {
		strcat(filename, ".txt");
		fp = fopen(filename, "r");
	}
	else
		fp = NULL;
	return fp;
}


void Student::add(char fileAdd[]) {
	int a=0;

	char txt[] = ".txt";
	string str = fileAdd;
	std::fstream fs;

	a = strlen(fileAdd) + 30; // length of characters to create underline below.

	fs.open(fileAdd, ios::app);	

	/*for (int i = 0; i < strlen(txt); ++i) {  Erase .txt from the filename to display.
		str.erase(std::remove(str.begin(), str.end(), txt[i]), fileAdd.end());
	}*/

	// Prompting user to add info.
	cout << endl << "Adding Student Information to " << fileAdd << endl;
	cout << setw(a) << setfill('-') << "" << endl; // underline.
	cout << "School: ";
	cin.getline(school, 29);
	cout << "Program: ";
	cin.getline(program, 4);
	cout << "Student No: ";
	cin.getline(studentno, 10);
	cout << fileAdd << " successfully updated." << endl;
	cin.ignore(1000, '\n');

	// Save/Append student info to person's file.
	fs << school << endl;
	fs << program << endl;
	fs << studentno << endl;
	fs.close();

	system("cls");
}


void Student::viewProfile() {

}


Student::~Student() {

}