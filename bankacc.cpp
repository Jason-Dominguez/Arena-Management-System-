#include "bankacc.h"

double bank::getSales(){
    return sales;
}
void bank::setSales(double inSales){
    sales=inSales;
}

double bank::getCash(){
    return cash;
}
void bank::setCash(double inCash){
    cash = inCash;
}

double bank::getDebt(){
    return debt;
}
void bank::setDebt(double inDebt){
    debt = inDebt;
}

double bank::getCon(){
    return conSales;
}
void bank::setCon(double inConSales){
    conSales = inConSales;
}


void readBank(bank &bankData)/// reads data from bank.txt and stores it in bankData
{
    double sales=0, cash=0, debt=0, conSales=0;
    ifstream inFile;
    inFile.open("bank.txt");
    if(!inFile){
        cout<<endl<<"Cannot open the file";
    }
    inFile >> sales >> cash >> debt >> conSales;/// conSales is not read from given file but will be on saved file after first use
        bankData.setSales(sales);
        bankData.setCash(cash);
        bankData.setDebt(debt);
        bankData.setCon(conSales);
}

void bankFile(bank bankData)
{
    ofstream outFile;  /// prints bankData vector to bank.txt
    outFile.open("bank.txt");
    outFile << bankData.getSales()<<" "<< bankData.getCash()<<" "<<bankData.getDebt()<<" "<<bankData.getCon();
    return;
}

bool inputYNb()
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

void printBank(bank bankData)
{
    cout<<"\n   Bank Account Information"<<endl;
    cout<<"Sales:            $"<<bankData.getSales()<<endl;
    cout<<"Concession Sales: $"<<bankData.getCon()<<endl;
    cout<<"Cash:             $"<<bankData.getCash()<<endl;
    cout<<"Debt:             $"<<bankData.getDebt()<<endl<<endl;

}
char adjMenu()
{
   char edit=' ';
   while(true)
    {
      cout<<"\nWhat would you like to edit?"<<endl;
      cout<<"1. Sales\n2. Cash\n3. Debt\n4. Exit"<<endl;
      cin>>edit;
      cin.clear();
      cin.ignore(256, '\n');
      if(edit=='1'||edit=='2'||edit=='3'||edit=='4')
        return edit;
      cout<<"Invalid entry. Enter a number 1-4"<<endl;
    }
}
double change()
{
    while(true){
    double temp=0;
    cout<<"What would you like to change it to?"<<endl;
    cin>>temp;
    if(!cin || temp < 0)
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout<<"Invalid entry"<<endl;
        }
    else
        return temp;
    }
}

void adjustBank(bank &bankData)
{
    double temp=0;
    char edit=adjMenu();
        switch(edit)
        {
            case '1':
                cout<<"\nSales account is currently "<<bankData.getSales()<<endl;
                temp=change();
                bankData.setSales(temp);
                cout<<"Sales account is now "<<bankData.getSales()<<endl<<endl;
                break;
            case '2':
                cout<<"\nCash account is currently $"<<bankData.getCash()<<endl;
                temp=change();
                bankData.setCash(temp);
                cout<<"Cash account is now $"<<bankData.getCash()<<endl<<endl;
                break;
            case '3':
                cout<<"\nDebt account is currently $"<<bankData.getDebt()<<endl;
                temp=change();
                bankData.setDebt(temp);
                cout<<"Debt account is now $"<<bankData.getDebt()<<endl<<endl;
                break;
        }
}
void payOff(bank &bankData)
{
    while(true){
    double pay=0;
    cout<<"\nThe arena currently has $"<<bankData.getCash()<<" cash on hand"<<endl;
    cout<<"and carries a debt of $"<<bankData.getDebt()<<endl;
    cout<<"How much would you like to pay off?\n$";
    cin>>pay;
    if(!cin || pay<0)
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout<<"Invalid entry"<<endl<<endl;
        }
    else if(pay > bankData.getCash())
        cout<<"The arena does not have that much cash on hand"<<endl;
    else if(pay > bankData.getDebt())
        cout<<"The arena does not need to pay more than it owes"<<endl;
    else
    {
        bankData.setCash(bankData.getCash()-pay);
        bankData.setDebt(bankData.getDebt()-pay);
        cout<<"Payment complete"<<endl;
        break;
    }
    }
}

char bankMenu()
{
  char menu=' ';
   while(true)
    {
      cout<<"\n    Bank Account"<<endl<<endl;
      cout<<"1. View all accounts"<<endl;
      cout<<"2. Adjust accounts"<<endl;
      cout<<"3. Pay off debt"<<endl;
      cout<<"4. Main Menu"<<endl;
      cin>>menu;
      cin.clear();
      cin.ignore(256, '\n');
      if(menu=='1'||menu=='2'||menu=='3'||menu=='4')
        return menu;
      cout<<"Invalid entry. Enter a number 1-4"<<endl;
    }
}

void bankManager(bank &bankData)
{
    system ("CLS");
    while(true){
            char menu=bankMenu();
            switch(menu)
            {
            case '1':
                printBank(bankData);
                break;
            case '2':
                adjustBank(bankData);
                break;
            case '3':
                payOff(bankData);
                break;
            case '4':
                return;
            }
    }
}



