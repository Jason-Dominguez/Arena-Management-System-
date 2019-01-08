#ifndef SCHEDULE_H_INCLUDED
#define SCHEDULE_H_INCLUDED
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "tickets.h"
#include "bankacc.h"

using namespace std;

class bank;
class ticket;

class schedule {
    string event;
    int month;
    int day;
    int year;
    int hour;
    int minute;

public:
    schedule ()
    {
        event="";
        month=0;
        day=0;
        year=0;
        hour=0;
        minute=0;
    }
    string getEvent();
    int getMonth();
    int getDay();
    int getYear();
    int getHour();
    int getMinute();

    void setEvent(string inEvent);
    void setMonth(int inMonth);
    void setDay(int inDay);
    void setYear(int inYear);
    void setHour(int inHour);
    void setMinute(int inMinute);
    void print(ostream& out);
};

void readSchedule(vector<schedule> &scheduleData);
void printSchedule(vector<schedule> scheduleData);
int inputMonth();
int inputDay();
int inputYear();
string inputName();
int inputHour();
int inputMin();
bool inputYN();
string scheduleCheck(vector<schedule> scheduleData);
void cancel(string event, vector<schedule> &scheduleData, vector<ticket> &ticketData, bank &bankData);
char editMenu(string nm);
void edit(string event, vector<schedule> &scheduleData, vector<ticket> &ticketData);
char scheduleMenu();
void manageSchedule(vector<schedule> &scheduleData, vector<ticket> &ticketData, bank &bankData);
void eventCreator(vector<schedule> &scheduleData, vector<ticket> &ticketData);
void scheduleFile(vector<schedule> scheduleData);


#endif // SCHEDULE_H_INCLUDED
