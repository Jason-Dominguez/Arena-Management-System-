#include <iostream>
#include <vector>
#include "bankacc.h"
#include "concession.h"
#include "parking.h"
#include "schedule.h"
#include "staff.h"
#include "tickets.h"

using namespace std;

char menu()
{
    system ("CLS");
    char selection=' ';/// main menu to choose
    while(true)
    {
        cout<<"\n  Main Menu"<<endl;
        cout<<"1. Manage Tickets"<<endl;
        cout<<"2. Manage Schedule"<<endl;
        cout<<"3. Manage Parking"<<endl;
        cout<<"4. Manage Staff"<<endl;
        cout<<"5. Manage Bank Account"<<endl;
        cout<<"6. Manage Concession Stand"<<endl;
        cout<<"7. Reset"<<endl;
        cout<<"8. Save & Exit"<<endl;
        cout<<"\nEnter Selection: ";
        cin>>selection;
        cin.clear();
        cin.ignore(256, '\n');
        if(selection>'0' && selection<'9')
            return selection;
        cout<<"PLEASE ENTER A VALID SELECTION\n\n"<<std::endl;
    }
}

void reset()///resets to original input files for assignment
{
    string source[6] = {"Obank.txt", "Oconcession.txt", "Oparking.txt", "Oschedule.txt", "Ostaff.txt", "Oticket.txt"};
    string destination[6] = {"bank.txt", "concession.txt", "parking.txt", "schedule.txt", "staff.txt", "ticket.txt"};
	ifstream inFile;
	ofstream outFile;
	for(int i = 0; i<6; i++)
        {
            inFile.open(source[i]);
            if(!inFile)
                {
                    cout<<"Error in opening "<<source<<endl;
                    return;
                }
            outFile.open(destination[i]);
            if(!outFile)
                {
                    cout<<"Error in opening "<<destination<<endl;
                    return;
                }
            outFile << inFile.rdbuf();
            inFile.close();
            outFile.close();
        }
	cout<<"Files reset"<<endl;
	cout<<"Please restart the program"<<endl;
}

void manager()
{
    vector<ticket> ticketData;
    vector<parking> parkingData;  /// creates vectors and calls functions to read data from txt files into them
    vector<schedule> scheduleData;
    vector<staff> staffData;
    vector<concession> concessionData;
    bank bankData;
    readSchedule(scheduleData); /// reads in all data to to their respected classes and vectors
    readTickets(ticketData);
    readParking(parkingData);
    readBank(bankData);
    readStaff(staffData);
    readConcession(concessionData, bankData);

    while(true){
        char select=menu();
        switch(select)
        {
         case '1':
            ticketManager(ticketData, scheduleData, bankData);
            break;
         case '2':
            manageSchedule(scheduleData, ticketData, bankData);
            break;
        case '3':
            parkingManager(parkingData, bankData);
            break;
        case '4':
            manageStaff(staffData);
            break;
        case '5':
            bankManager(bankData);
            break;
        case '6':
            manageConcession(concessionData, bankData);
            break;
        case '7':
            {
            cout<<"This will reset the input files to the originals given for the assignment"<<endl;
            cout<<"Do you want to do that?"<<endl;
            bool yn = inputYN();
            if(yn)
            {
               reset();
               return;/// send back to main, program needs to be restarted
            }
            if(!yn)
                break;
            }
        case '8':
            {
                cout<<"Would you like to save changes?"<<endl;
                bool yn = inputYN();
                if(yn)
                {
                    bankFile(bankData);
                    conFile(concessionData);
                    parkingFile(parkingData);
                    scheduleFile(scheduleData);
                    staffFile(staffData);
                    ticketFile(ticketData);
                    cout<<"\n\n\n********Save Complete***********"<<endl;
                }
                return;
            }

        }
   }
}





int main()
{
    manager();
    return 0;
}
