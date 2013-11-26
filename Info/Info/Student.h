// Student Class

#include "Person.h"

using namespace std;

class Student : public Person {
	char school[30];
	char program[5];
	char studentno[10];
public:
	Student();
	void addStudentInfo();
	void add(char fileAdd[]);
	void viewProfile();
	FILE* open(char filename[]);
	~Student();
};