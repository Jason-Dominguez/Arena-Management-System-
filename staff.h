#ifndef STAFF_H_INCLUDED
#define STAFF_H_INCLUDED
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

class staff {
    int id;
    string fname;
    string lname;
    string job;
    int salary;

public:
    staff ()
    {
        id=0;
        fname="";
        lname="";
        job="";
        salary=0;
    }
    int getID();
    string getFname();
    string getLname();
    string getJob();
    int getSalary();

    void setID(int inID);
    void setFname(string inFname);
    void setLname(string inLname);
    void setJob(string inJob);
    void setSalary(int inSalary);
    void print(ostream& out);
};

void printStaff();
void readStaff(vector<staff> &staffData);
string inputFname();
string inputLname();
string inputJob();
int inputSalary();
int inputID();
char staffMenu();
bool staffYN();
size_t searchID(vector<staff> staffData);
size_t searchJob(vector<staff> staffData);
char editStaffMenu();
void editStaff(vector<staff> &staffData);
void hireStaff(vector<staff> &staffData);
void fireStaff(vector<staff> &staffData);
char staffMenu();
void manageStaff(vector<staff> &staffData);
void staffFile(vector<staff> staffData);









#endif // STAFF_H_INCLUDED
