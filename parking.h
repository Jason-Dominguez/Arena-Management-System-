#ifndef PARKING_H_INCLUDED
#define PARKING_H_INCLUDED
#include <iostream>
#include <vector>
#include <fstream>
#include "bankacc.h"
using namespace std;

class parking {
    int section;
    int space;
    int price;
    bool available;

public:
    parking ()
    {
        section=0;
        space=0;
        price=0;
        available=0;
    }
    int getSection();
    int getSpace();
    int getPrice();
    bool getAvailable();

    void setSection(int inSection);
    void setSpace(int inSpace);
    void setPrice(int inPrice);
    void setAvailable(bool inAvailable);
    void print(ostream& out);
};

void readParking(vector<parking> &parkingData);
void printParking(vector<parking> parkingData, int zone);
void printAvailible(vector<parking> parkingData, int num);
void parkingManager(vector<parking> &parkingData, bank &bankData);
char parkingMenu();
int getzone();///extra functions to make life easier
int getspot();
bool getysno();
void parkingFile(vector<parking> parkingData);


#endif // PARKING_H_INCLUDED
