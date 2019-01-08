#include "concession.h"
#include "bankacc.h"

string concession::getItem(){
    return item;
}
void concession::setItem(string inItem){
    item=inItem;
}

int concession::getInventory(){
    return inventory;
}
void concession::setInventory(int inInventory){
    inventory = inInventory;
}

double concession::getPrice(){
    return price;
}
void concession::setPrice(double inPrice){
    price = inPrice;
}

void concession::print(ostream& out){
    out <<left<<setw(15)<<getItem()<<setw(10)<< getInventory()<<fixed<<setprecision(2)<< getPrice()<<endl;
}

void readConcession(vector<concession> &concessionData, bank &bankData)/// reads data from concession.txt and stores it in concessionData
{
    string item ="";
    int inventory = 0;
    double price = 0.0;
    concession temp;
    ifstream inFile;
    inFile.open("concession.txt");
    if(!inFile)
        cout<<endl<<"Cannot open the file";
    if(isdigit(inFile.peek()))///checks if file is original input file or saved file with formating
    {
        for(int i = 0; i < 6; i++)
        {
           inFile >> inventory >> price;
           temp.setInventory(inventory);
           temp.setPrice(price);
           concessionData.push_back(temp);
        }
        concessionData[0].setItem("Hot dogs:");
        concessionData[1].setItem("Peanuts:");
        concessionData[2].setItem("Burgers:");
        concessionData[3].setItem("Soft drinks:");
        concessionData[4].setItem("Beer:");
        concessionData[5].setItem("Jersey:");
        inFile >> inventory;
        bankData.setCon(inventory);///stores concession sales in bank data
    }
    else/// reads saved file format
    {
        getline(inFile, item, ':');/// saved file format is set it up so its easy to read and put into vectors
        inFile >> inventory >> price;/// also makes it easier to add a function to add and remove items from concessions
        while(!inFile.eof())
            {
                temp.setItem(item += ':');
                temp.setInventory(inventory);
                temp.setPrice(price);
                concessionData.push_back(temp);
                inFile.ignore();/// ignores new line character at end of line, would be picked up by getline bc getline is using char delim
                getline(inFile, item, ':');  /// gets the next item at the end of loop so if its the end of file !.eof() will be false
                inFile >> inventory >>  price;
            }
    }
    inFile.close();
    return;
}

void conFile(vector<concession> concessionData)
{
    ofstream outFile;  /// prints concessionData vector to concession.txt
    outFile.open("concession.txt");
    for (size_t i=0; i<concessionData.size(); i++)
    {
        concessionData[i].print(outFile);
    }
    return;
}

void bankConFile(bank bankData)///concession data is stored in bank data
{
    ofstream outFile;  /// prints bankData vector to bank.txt
    outFile.open("bank.txt");
    outFile << bankData.getSales()<<" "<< bankData.getCash()<<" "<<bankData.getDebt()<<" "<<bankData.getCon();
    return;
}

size_t selection(size_t most)
{
    bool badInput = true;
    size_t selection = 0;
    while(badInput)
    {
    cin >> selection;
    if(!cin || selection > most)
    {
       cin.clear();
       cin.ignore(256, '\n');
       cout<<"\n\nINVALID SELECTION enter a number (0-"<<most<<")\n\n";
       continue;
    }
    cin.clear();
    cin.ignore(256, '\n');
    badInput = false;
    }
    return selection;
}
bool inputYNc()
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
void order(vector<concession> &concessionData, bank &bankData)
{
    cout<<"\n\n\n     Order menu"<<endl<<endl;
    for(size_t i = 0; i<concessionData.size(); i++)
    {
        cout<<i<<". "<<left<<setw(15)<<concessionData[i].getItem()<<" "<<concessionData[i].getInventory()<<endl;
    }
    cout<<"\n\nWhat would you like to order more of? Enter a number 0-"<<concessionData.size()-1<<endl;
    size_t pos = selection(concessionData.size()-1);
    cout<<"How many "<<concessionData[pos].getItem()<<" would you like to order?"<<endl;
    int amount = selection(SIZE_MAX);
    double cost = .5 * concessionData[pos].getPrice() * amount;
    if(cost > bankData.getCash())
    {
        cout<<"\n\nCost of "<<amount<<" "<<concessionData[pos].getItem()<<": $"<<cost<<endl;
        cout<<"Cash on hand: $"<< bankData.getCash()<<endl;
        cout<<"The arena does not have enough cash on hand to complete that transaction"<<endl;
        cout<<"Would you like to take on more debt to pay for the order?"<<endl<<endl;
        bool yn = inputYNc();
        if(yn)
        {
            bankData.setDebt(bankData.getDebt()+(cost - bankData.getCash()));
            concessionData[pos].setInventory(concessionData[pos].getInventory() + amount);
            cout<<"\n\n\nTransaction complete"<<endl;
        }
        if(!yn)
        {
            cout<<"\n\n\nTransaction canceled"<<endl;
            return;
        }
    }
    else if(cost <= bankData.getCash())
    {
        bankData.setCash(bankData.getCash()-cost);
        concessionData[pos].setInventory(concessionData[pos].getInventory() + amount);
        cout<<"\n\n\nTransaction complete"<<endl;
    }
   return;
}

void sell(vector<concession> &concessionData, bank &bankData)
{
    bool yn = true;
    while(yn)///loop so multiple sales can be made
    {
    cout<<"\n\n\n      Sales Menu"<<endl<<endl;
    cout<<"     Item      Inventory"<<endl;
    for(size_t i = 0; i<concessionData.size(); i++)
    {
        cout<<i<<". "<<left<<setw(15)<<concessionData[i].getItem()<<concessionData[i].getInventory()<<endl;
    }
    cout<<"What would you like to sell? Enter a number 0-"<<concessionData.size()-1<<endl;
    size_t pos = selection(concessionData.size()-1);
    cout<<"How many: ";
    int amount = selection(concessionData[pos].getInventory());
    concessionData[pos].setInventory(concessionData[pos].getInventory()-amount);/// sets bank account and inventory
    bankData.setCash(bankData.getCash()+(amount * concessionData[pos].getPrice()));
    bankData.setCon(bankData.getCon()+(amount * concessionData[pos].getPrice()));
    cout<<"\n\nSale complete"<<endl;
    cout<<"Would you like to make another sale?"<<endl;
    yn = inputYNc();
    }
    return;
}

char concessionMenu()
{
    char selection=' ';
    while(true)
    {
        cout<<endl;
        cout<<" Concession Menu"<<endl;
        cout<<"1. Print Sales and Inventory"<<endl;
        cout<<"2. Order Inventory"<<endl;
        cout<<"3. Sell Concessions"<<endl;
        cout<<"4. Out of stock"<<endl;
        cout<<"5. Main Menu"<<endl;
        cout<<"\nEnter Selection: ";
        cin>>selection;
        cin.clear();
        cin.ignore(256, '\n');
        if(selection>'0' && selection<'6')
            return selection;
        cout<<"PLEASE ENTER A VALID SELECTION\n\n"<<endl;
    }
}

void manageConcession(vector<concession> &concessionData, bank &bankData)
{
    system ("CLS");
    while(true){
        char select= concessionMenu();
        switch(select)
        {
        case '5':
            return;
        case '1':
            {
                cout<<"\n\n\n\n\n\n\n\nItem        Inventory    Price"<<endl<<endl;
                for (size_t i=0; i<concessionData.size(); i++)
                    {
                        concessionData[i].print(cout);
                    }
                cout<<"\nSales:  "<<bankData.getCon()<<endl;
            }
            break;
        case '2':
            order(concessionData, bankData);
            break;
        case '3':
            sell(concessionData, bankData);
            break;
        case '4':
            cout<<"\n\n\nOut of stock"<<endl<<endl;
            for(size_t i = 0; i<concessionData.size(); i++)
                {
                    if(concessionData[i].getInventory() == 0)
                        cout<<concessionData[i].getItem()<<endl;
                }
            break;
        }
        }
}

