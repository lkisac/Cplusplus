/* 
    Len Isac
    FStream Student Info List - Binary Files
    Status: Incomplete.  Currently working debug assertion error.  Only occuring if user displays list first and does anything afterwards, then error occurs on exit.
            If the user enters a new student, then displays info or leaves, program works fine.
    Date: December 6th, 2013
    Description: This program saves all student information into "binarystudents.bin" file and displays the list for the user.
*/

// #define _CRT_SECURE_NO_WARNINGS 1  // same as changing debug >> file properties >> preprocessor definitions
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student
{
    string _studentname; 
    char _coursecode[4];
    char _studentnumber[10];
public:
    Student(string studentname = "", const char* coursecode = "", const char* studentnumber = "")
    {
        set(studentname, coursecode, studentnumber);
    }
    void set(string studentname = "", const char* coursecode = "", const char* studentnumber = "")
    {
        _studentname = studentname;
                
        strcpy(_coursecode, coursecode);

        strcpy(_studentnumber, studentnumber);
    }
    ostream& print(ostream& os)const
    {
        return os << "Name: " << _studentname << endl << "Course Code: " << _coursecode << endl << "Student #: " << _studentnumber << endl;
    }
    void Student::enterNewStudent(Student& S, const char* filename);
    void displayStudentList(Student& S, const char* filename);
    ~Student()
    {
        // Destructor.
    }
};
ostream& operator<<(ostream& os, const Student& S)
{
    return S.print(os);
}

void Student::enterNewStudent(Student& S, const char* filename)
{
    fstream file(filename, ios::out|ios::binary|ios::app); // Open filename to append to

    // Get student info
    cout << "Name: ";
    getline(cin, S._studentname);
    /*cin.clear(); cin.ignore(INT_MAX, '\n');*/
    fflush(stdin);
    
    cout << "Course Code: ";
    cin.getline(S._coursecode, 4, '\n');
    fflush(stdin);

    cout << "Student Number: ";
    cin.getline(S._studentnumber, 10, '\n');
    fflush(stdin);

    file.write((const char*)&S, sizeof(Student));

    cout << S._studentname << "'s" << " file saved in " << filename << endl;

    file.clear();
    file.close();
    cout << endl << "Press any key to continue...";
    getchar();
}

void Student::displayStudentList(Student& S, const char* filename)
{
    fstream file(filename, ios::in|ios::binary|ios::app); // Open filename to display

    for (int i = 0; !file.fail(); i++)
    {
        file.read((char*)&S, sizeof(Student));
        if (!file.fail())
        {
            cout << S;
        }
    }
    
    file.clear();
    file.close();    
    cout << endl << "Press any key to continue...";
    getchar();
}

int main()
{
    Student S;
    const char* filename;

    unsigned int choice;

    filename = "students.bin";

    // Main Menu
    do
    {
        cout << "Student Info" << endl;
        cout << "============" << endl << endl;

        cout << "1. Enter new student" << endl;
        cout << "2. Display all students" << endl;
        cout << "3. Exit" << endl;

        cin >> choice;
        cin.clear(); cin.ignore(INT_MAX, '\n');

        switch(choice)
        {
            case 1:
                S.enterNewStudent(S, filename);
                system("CLS");
                break;
            case 2:
                S.displayStudentList(S, filename);
                system("CLS");
                break;
            case 3:
                break;
        }
    }while(choice != 3);

    return 0;
}