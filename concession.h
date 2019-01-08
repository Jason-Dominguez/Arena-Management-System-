#ifndef CONCESSION_H_INCLUDED
#define CONCESSION_H_INCLUDED
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cctype>
#include "bankacc.h"

using namespace std;

class bank;

class concession{
    string item;
    int inventory;
    double price;

public:
    concession ()
    {
        setItem("");
        setInventory(0);
        setPrice(0.0);
    }
    string getItem();
    int getInventory();
    double getPrice();

    void setItem(string inItem);
    void setInventory(int inInventory);
    void setPrice(double inPrice);
    void print(ostream& out);
};

void readConcession(vector<concession> &concessionData, bank &bankData);
size_t selection(size_t most);
bool inputYNc();
void order(vector<concession> &concessionData, bank &bankData);
void sell(vector<concession> &concessionData, bank &bankData);
char concessionMenu();
void manageConcession(vector<concession> &concessionData, bank &bankData);
void conFile(vector<concession> concessionData);
void bankConFile(bank bankData);



#endif // CONCESSION_H_INCLUDED
