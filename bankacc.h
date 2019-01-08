#ifndef BANKACC_H_INCLUDED
#define BANKACC_H_INCLUDED
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class bank {
    double sales;
    double cash;
    double debt;
    double conSales;

public:
    bank ()
    {
        setSales(0);
        setCash(0);
        setDebt(0);
        setCon(0);
    }
    double getSales();
    double getCash();
    double getDebt();
    double getCon();

    void setSales(double inSales);
    void setCash(double inCash);
    void setDebt(double inDebt);
    void setCon(double inCon);
};

void readBank(bank &bankData);
void printBank(bank bankData);
void adjustBank(bank &bankData);
void bankManager(bank &bankData);
void payOff(bank &bankData);
void bankFile(bank bankData);
char bankMenu();
char adjMenu();
double change();
bool inputYNb();

#endif // BANKACC_H_INCLUDED
