#ifndef TICKETS_H_INCLUDED
#define TICKETS_H_INCLUDED
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include "schedule.h"
#include "bankacc.h"

using namespace std;

class schedule;

class ticket {
    int section;
    int seat;
    int price;
    bool sold;
    string name;

public:
    ticket ()
    {
        setSection(0);
        setSeat(0);
        setPrice(0);
        setSold(0);
        setName("");
    }
    int getSection();
    int getSeat();
    int getPrice();
    bool getSold();
    string getName();

    void setSection(int inSection);
    void setSeat(int inSeat);
    void setPrice(int inPrice);
    void setSold(bool inSold);
    void setName(string inName);
    void print(ostream& out);
};

void readTickets(vector<ticket> &ticketData);
int getTzone();
int getTspot();
void printTickets(vector<ticket> ticketData);
void printAva(vector<ticket> ticketData);
void printUnAva(vector<ticket> ticketData);
bool sellRe();
char ticketMenu();
string scheduleCheckT(vector<schedule> scheduleData);
size_t findTicket(vector<ticket> &ticketData, string event);
void ticketManager(vector<ticket> &ticketData, vector<schedule> &scheduleData, bank &bankData);
void ticketFile(vector<ticket> ticketData);

#endif // TICKETS_H_INCLUDED
