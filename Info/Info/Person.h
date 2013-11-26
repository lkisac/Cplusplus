// Person Class

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>

#define MNAME 30
#define MPHONE 20
#define MADDRESS 40
#define MSIN 10

using namespace std;

class Person {
	char fname[MNAME];
	char lname[MNAME];
	char phoneno[MPHONE];
	char address[MADDRESS];
	char sinno[MSIN];
public:
	Person();
	void menu();
	void createProfile();
	virtual void viewProfile();
	virtual ~Person();
};