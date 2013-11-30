/* 
    Len Isac
    FStream Student Info single file
    November 29th, 2013
    This program saves student information to a file for a student.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string studentname; 
    string coursecode;
    string studentnumber;
    string filename;

    do
    {
        cout << "Student Info" << endl;
        cout << "============" << endl;

        // Get student info.
        cout << "Name (0 to quit): ";
        getline(cin, studentname, '\n'); if (studentname[0] == '0') exit(0);
        cout << "Course Code: ";
        getline(cin, coursecode, '\n');
        cout << "Student Number: ";
        getline(cin, studentnumber, '\n');
        fflush(stdin);

        // Save student info to file.
        filename = studentnumber + ".txt";
        ofstream fout(filename);
        fout << studentname << endl << coursecode << endl << studentnumber << endl;

        cout << endl << studentname << "'s file saved as " << "'" << filename << "'" << endl;
        cout << endl << "Press any key to continue..."; getchar();
        system("CLS");
    
    } while (studentname != "0");

    return 0;
}