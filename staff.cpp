#include "staff.h"
using namespace std;

int staff::getID(){
    return id;
}
void staff::setID(int inID){
    id=inID;
}

string staff::getFname(){
    return fname;
}
void staff::setFname(string inFname){
    fname = inFname;
}

string staff::getLname(){
    return lname;
}
void staff::setLname(string inLname){
    lname = inLname;
}

string staff::getJob(){
    return job;
}
void staff::setJob(string inJob){
    job = inJob;
}

int staff::getSalary(){
    return salary;
}
void staff::setSalary(int inSalary){
    salary=inSalary;
}

void staff::print(ostream& out){
    out <<right<<setw(5)<< getID()<<setw(4)<<" "<<left<<setw(10)<<getFname()<<setw(10)<<getLname()<<setw(15)<<getJob()<<setw(15)<<getSalary()<<endl;
}
void printStaff(vector<staff> staffData)
{
    cout<<"  ID          Name             Job         Salary"<<endl;
    for(size_t i=0; i<staffData.size(); i++)
    {
       staffData[i].print(cout);
    }
}
string inputFname()
{
    bool badInput = true;
    string fname = "";
    while(badInput)
    {
    cout<<"First Name: "<<endl;
    cin>>fname;
     if(!cin)
     {
       cin.clear();
       cin.ignore(256, '\n');
       cout<<"\rInvalid Input::: ";
       continue;
     }
     cin.clear();
     cin.ignore(256, '\n');
     badInput = false;
    }
    return fname;
}

string inputLname()
{
    bool badInput = true;
    string lname = "";
    while(badInput)
    {
    cout<<"Last Name: "<<endl;
    cin>>lname;
     if(!cin)
     {
       cin.clear();
       cin.ignore(256, '\n');
       cout<<"\rInvalid Input::: ";
       continue;
     }
     cin.clear();
     cin.ignore(256, '\n');
     badInput = false;
    }
    return lname;
}

string inputJob()
{
    bool badInput = true;
    string job = "";
    while(badInput)
    {
    cout<<"Job: "<<endl;
    cin>>job;
     if(!cin)
     {
       cin.clear();
       cin.ignore(256, '\n');
       cout<<"\rInvalid Input::: ";
       continue;
     }
     cin.clear();
     cin.ignore(256, '\n');
     badInput = false;
    }
    return job;
}

int inputSalary()
{
    bool badInput = true;
    int salary = 0;
    while(badInput)
    {
    cout<<"Salary: "<<endl;
    cin>>salary;
     if(!cin)
     {
       cin.clear();
       cin.ignore(256, '\n');
       cout<<"\rInvalid Input::: ";
       continue;
     }
     cin.clear();
     cin.ignore(256, '\n');
     badInput = false;
    }
    return salary;
}

int inputID()
{
    bool badInput = true;
    int id = 0;
    while(badInput)
    {
    cout<<"ID: "<<endl;
    cin>>id;
     if(!cin || id < 1000 || id > 9999)
     {
       cin.clear();
       cin.ignore(256, '\n');
       cout<<"Invalid Input ID numbers are 4 digits"<<endl;
       continue;
     }
     cin.clear();
     cin.ignore(256, '\n');
     badInput = false;
    }
    return id;
}

bool staffYN()
{
    char YN = ' ';
    while(true)
    {
    cout<<"Enter Y for YES or N for NO"<<endl;
    cin>>YN;
     if(!cin)
     {
       cin.clear();
       cin.ignore(256, '\n');
       cout<<"\rInvalid Input::: ";
       continue;
     }
     cin.clear();
     cin.ignore(256, '\n');
     if(YN == 'y' || YN == 'Y')
        return true;
     if(YN == 'n' || YN == 'N')
        return false;
     else
       cout<<"\rInvalid Input::: ";
    }
}

void readStaff(vector<staff> &staffData)/// reads data from staff.txt and stores it in staffData
{
    ifstream inFile;
    int id=0, salary=0;
    string fname="", lname="", job="";
    staff temp;
    inFile.open("staff.txt");
    if(!inFile)
        cout<<endl<<"Cannot open the file";
    inFile >> id >> fname >> lname >> job >> salary;///reads once before entering loop so !inFile.eof is false at end and not one iteration after
    while(!inFile.eof())/// while loop to read file stops at end
    {
        temp.setID(id);  ///stores all values in temp staff class
        temp.setFname(fname);
        temp.setLname(lname);
        temp.setJob(job);
        temp.setSalary(salary);
        staffData.push_back(temp);///pushes back temp class to staffData
        inFile >> id >> fname >> lname >> job >> salary;
    }
}

void staffFile(vector<staff> staffData)///save function
{
    ofstream outFile;  /// prints staffData vector to staff.txt
    outFile.open("staff.txt");
    for (size_t i=0; i<staffData.size(); i++)
    {
        staffData[i].print(outFile);
    }
    return;
}

size_t searchID(vector<staff> staffData)
{
  cout<<"Enter the staff ID to get employee info"<<endl;
    int id=inputID();
    size_t i = 0;
    while(i<staffData.size())
    {
        if(id == staffData[i].getID())
        {
            return i;/// returns place in vector staffData of that id
        }
        else if(i == staffData.size()-1)
        {
            cout<<"\n\n\nID not recognized"<<endl;
            cout<<"Would you like to try another ID?"<<endl;
            bool yn = staffYN();
            if(yn)
            {
                id=inputID();
                i = 0;
                continue;
            }
            if(!yn)/// checks if user wants to quit searching
                return SIZE_MAX;///returns max value to be checked with if statement
        }
        i++;
    }
    return SIZE_MAX;///should never be able to get here
}

size_t searchJob(vector<staff> staffData)
{
  cout<<"Enter the employee's job to get employee info"<<endl;
    string job = inputJob();
    int counter = 0;
    size_t place = 0;
    size_t i = 0;
    while(i<staffData.size())
    {
        if(job == staffData[i].getJob())
        {
            place = i;
            ++counter;/// counts how many staff have that job
        }
        else if(i == staffData.size()-1 && counter == 0)
        {
            cout<<"\n\n\nJob not recognized"<<endl;
            cout<<"Would you like to search for another job?"<<endl;
            bool yn = staffYN();
            if(yn)
            {
                job=inputJob();
                i = 0;
                continue;
            }
            if(!yn)/// checks if user wants to quit searching
                return SIZE_MAX;///returns max value to be checked with if statement
        }
        i++;
    }
    if(counter == 1)
        return place;
    if(counter > 1)
    {
        cout<<"\n\n\nMultiple employees have that job"<<endl;
        cout<<"Would you like to search by ID?"<<endl;
        bool yn = staffYN();
        if(yn)
        {
           place = searchID(staffData);
           return place;
        }
        if(!yn)
            return SIZE_MAX;
    }
    return SIZE_MAX;/// should never be able to get here
}

char editStaffMenu()
{
    char menu = ' ';
    while(true)
    {
        cout<<endl;
        cout<<"1. Change Employee Name"<<endl;
        cout<<"2. Change Employee Job"<<endl;
        cout<<"3. Change Employee Salary"<<endl;
        cout<<"4. Change Employee ID"<<endl;
        cout<<"5. Staff Menu"<<endl;
        cout<<"\nEnter Selection: ";
        cin>>menu;
        cin.clear();
        cin.ignore(256, '\n');
        if(menu>'0' && menu<'6')
            return menu;
        cout<<"PLEASE ENTER A VALID SELECTION\n\n"<<endl;
    }
}

void editStaff(vector<staff> &staffData)
{
    cout<<"\n Staff Info Editor"<<endl;
    size_t place = searchID(staffData);
    if(place < SIZE_MAX)
    {
        while(true){
        char select = editStaffMenu();
        switch(select)
        {
        case '5':
            return;
        case '1':
            {
                cout<<"\n\nEditing: "<<staffData[place].getFname()<<" "<<staffData[place].getLname()<<endl;
                cout<<"Enter new name"<<endl;
                string newFname = inputFname();
                string newLname = inputLname();
                staffData[place].setFname(newFname);
                staffData[place].setLname(newLname);
                cout<<"Employee's name is now "<<staffData[place].getFname()<<" "<<staffData[place].getLname()<<endl;
                break;
            }
        case '2':
            {
                cout<<"\n\nEditing: "<<staffData[place].getFname()<<" "<<staffData[place].getLname()<<endl;
                cout<<"Enter new job"<<endl;
                string job = inputJob();
                staffData[place].setJob(job);
                cout<<"Employee's job is now "<<job<<endl;
                break;
            }
        case '3':
            {
                cout<<"\n\nEditing: "<<staffData[place].getFname()<<" "<<staffData[place].getLname()<<endl;
                cout<<"Enter new salary"<<endl;
                int salary = inputSalary();
                staffData[place].setSalary(salary);
                cout<<"Employee's salary is now "<<salary<<endl;
                break;
            }
        case '4':
            {
                cout<<"\n\nEditing: "<<staffData[place].getFname()<<" "<<staffData[place].getLname()<<endl;
                cout<<"Enter new ID"<<endl;
                int id = inputID();
                size_t i = 0;
                while(i < staffData.size())
                {
                    if(id == staffData[i].getID() && i != place)/// checks to make sure new id in not already assigned
                    {
                        cout<<"That ID is already in use"<<endl;
                        cout<<"Would you like to try a different ID"<<endl;
                        bool yn = staffYN();
                        if(yn)
                        {
                            id = inputID();
                            i = 0;
                            continue;
                        }
                        if(!yn)
                            return;
                    }
                    i++;
                }
                staffData[place].setID(id);
                cout<<"Employee's ID is now "<<id<<endl;
                break;
            }
        }
        }
    }
}

void hireStaff(vector<staff> &staffData)
{
    cout << "\n\nNew Hire Information"<<endl;
    string fname = inputFname();
    string lname = inputLname();
    string job = inputJob();
    int salary = inputSalary();
    int id = (double)rand()/(RAND_MAX + 1) * (9999-1000) + 1000;/// generates random 4 digit ID
    size_t i = 0;
    while (i<staffData.size())/// checks to see if ID has been used before if it has that ID is regenerated and everything is checked again
        {
            if(staffData[i].getID() == id)
            {
                id = (double)rand()/(RAND_MAX + 1) * (9999-1000) + 1000;
                i=0;
                continue;
            }
            i++;
        }
    staff temp;
    temp.setFname(fname);
    temp.setLname(lname);
    temp.setJob(job);
    temp.setSalary(salary);
    temp.setID(id);
    staffData.push_back(temp);
    cout<<fname<<" "<<lname<<" has been added to staff"<<endl;
}

void fireStaff(vector<staff> &staffData)
{
    cout<<"\n\nEmployee Termination Menu"<<endl;
    size_t place = searchID(staffData);
    if(place < SIZE_MAX)
    {
        cout<<"Are you sure you want to fire "<<staffData[place].getFname()<<" "<<staffData[place].getLname()<<"?"<<endl;
        bool yn = staffYN();
        if(yn)
        {
            cout<<staffData[place].getFname()<<" "<<staffData[place].getLname()<<" has been removed from staff."<<endl;
            staffData.erase(staffData.begin()+place);
            return;
        }
    }
    return;
}

char staffMenu()
{
    char selection=' ';
    while(true)
    {
        cout<<endl;
        cout<<" Staff Menu"<<endl;
        cout<<"1. Adjust staff info"<<endl;
        cout<<"2. Print all staff"<<endl;
        cout<<"3. Search by staff ID number"<<endl;
        cout<<"4. Search by job"<<endl;
        cout<<"5. Hire new staff"<<endl;
        cout<<"6. Fire existing staff"<<endl;
        cout<<"7. Main Menu"<<endl;
        cout<<"\nEnter Selection: ";
        cin>>selection;
        cin.clear();
        cin.ignore(256, '\n');
        if(selection>'0' && selection<'8')
            return selection;
        cout<<"PLEASE ENTER A VALID SELECTION\n\n"<<endl;
    }
}

void manageStaff(vector<staff> &staffData)
{
    system ("CLS");
    while(true){
        char select= staffMenu();
        switch(select)
        {
        case '7':
            return;
        case '1':
            editStaff(staffData);
            break;
        case '2':
            printStaff(staffData);
            break;
        case '3':
            {
            size_t place = searchID(staffData);
            if(place < SIZE_MAX)
                staffData[place].print(cout);
            break;
            }
        case '4':
            {
            size_t place = searchJob(staffData);
            if(place < SIZE_MAX)
                staffData[place].print(cout);
            break;
            }
        case '5':
            hireStaff(staffData);
            break;
        case '6':
            fireStaff(staffData);
            break;
            }
        }
}


