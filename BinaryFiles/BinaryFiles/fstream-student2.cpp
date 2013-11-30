/* 
    Len Isac
    FStream Student Info List
    November 29th, 2013
    This program saves all student information into one file and displays the list for the user.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void enterNewStudent(string filename)
{
    string studentname; 
    string coursecode;
    string studentnumber;

    ofstream fout; 
    fout.open(filename, ios::app); // Open filename to append to


    // Get student info
    cout << "Name: ";
    getline(cin, studentname, '\n');
    cout << "Course Code: ";
    getline(cin, coursecode, '\n');
    cout << "Student Number: ";
    getline(cin, studentnumber, '\n');
    fflush(stdin);

    fout << studentname << "," << coursecode << "," << studentnumber << endl;

    cout << studentname << "'s file saved in " << filename << endl;

    cout << endl << "Press any key to continue...";
    getchar();
}

void displayStudentList(string filename)
{
    ifstream studentfile(filename);
    char studentname[21];
    char coursecode[4];
    char studentnumber[10];
    int colcount = 0;
    bool isempty = false;

    if (!studentfile) //if (studentfile.is_open()) was trying different functions
    {
        cout << "Cannot open " << filename << endl;
    }
    else
    {
        // Table
        cout.width(30); cout << "Students File" << endl;
        cout << string(47, '_'); cout << endl << endl;
        cout.width(21); cout << left << "Student Name"; cout.width(14); cout << left << "Course Code"; cout.width(12); cout << left << "Student #"; cout << endl;
        cout << string(47, '='); cout << endl;

        // Table Rows
        while(studentfile)
        {
            colcount++;
            if (colcount == 1) // Gets Student Name from file
            {
                studentfile.getline(studentname, 21, ',');
                char ch = studentname[0];
                cout.width(21); cout << left << studentname; colcount++;
                if (ch == 0)
                {
                    isempty = true;
                }
            }
            if (colcount == 2 && !isempty) // Gets Course Code from file
            {
                studentfile.getline(coursecode, 4, ','); cout.width(14); cout << left << coursecode; colcount++;
            }
            if (colcount == 3 && !isempty) // Gets Student Number from file
            {
                studentfile.getline(studentnumber, 10, '\n'); cout.width(12); cout << left << studentnumber << endl; colcount++;
            }
            if (colcount == 4 && !isempty) // Prints next row line
            {
                cout << string(47, '-') << endl; colcount = 0;
            }
        }
        studentfile.close(); // Close student file
    }
    cout << endl << "Press any key to continue...";
    getchar();
    
}

int main()
{
    string filename;

    unsigned int choice;

    filename = "students.txt";

    // Main Menu
    do
    {
        cout << "Student Info" << endl;
        cout << "============" << endl << endl;

        cout << "1. Enter new student" << endl;
        cout << "2. Display all students" << endl;
        cout << "3. Exit" << endl;

        cin >> choice;
        fflush(stdin);

        switch(choice)
        {
            case 1:
                enterNewStudent(filename);
                system("CLS");
                break;
            case 2:
                displayStudentList(filename);
                system("CLS");
                break;
            case 3:
                break;
        }
    }while(choice != 3);

    return 0;
}