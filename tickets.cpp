#include "tickets.h"

int ticket::getSection(){
    return section;
}
void ticket::setSection(int inSection){
    section = inSection;
}

int ticket::getSeat(){
    return seat;
}
void ticket::setSeat(int inSeat){
seat = inSeat;
}

int ticket::getPrice(){
    return price;
}
void ticket::setPrice(int inPrice){
price = inPrice;
}

bool ticket::getSold(){/// 1 = true = ticket is still available
    return sold;
}
void ticket::setSold(bool inSold){
sold=inSold;
}

string ticket::getName(){
    return name;
}
void ticket::setName(string inName){
name=inName;
}

void ticket::print(ostream& out){
    out <<setw(5)<< getSection() <<setw(8) << getSeat()<<setw(8)<< getPrice()<<setw(10) << getSold() << setw(15) << getName()<< endl;
}
int inputZone()
{
    bool badInput = true;
    int zone = 0;
    while(badInput)
    {
    cout<<"Section: "<<endl;
    cin>>zone;
     if(!cin || zone>49 || zone<0)
     {
       cin.clear();
       cin.ignore(256, '\n');
       cout<<"\rInvalid Input. Please enter a section 0-49::: ";
       continue;
     }
     cin.clear();
     cin.ignore(256, '\n');
     badInput = false;
    }
    return zone;
}
int inputSeat()
{
    bool badInput = true;
    int seat = 0;
    while(badInput)
    {
    cout<<"Seat Number: "<<endl;
    cin>>seat;
     if(!cin || seat>9 || seat<0)
     {
       cin.clear();
       cin.ignore(256, '\n');
       cout<<"\rInvalid Input. Please enter a seat number 0-9::: ";
       continue;
     }
     cin.clear();
     cin.ignore(256, '\n');
     badInput = false;
    }
    return seat;
}
int inputMonthT()
{
    bool badInput = true;
    int month = 0;
    while(badInput)
    {
    cout<<"Month: "<<endl;
    cin>>month;
     if(!cin || month>12 || month<1)
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
    return month;
}
int inputDayT()
{
    bool badInput = true;
    int day = 0;
    while(badInput)
    {
    cout<<"Day: "<<endl;
    cin>>day;
     if(!cin || day>31 || day<1)
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
    return day;
}
int inputYearT()
{
    bool badInput = true;
    int year = 0;
    while(badInput)
    {
    cout<<"Year: "<<endl;
    cin>>year;
     if(!cin || year<2018)
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
    return year;
}
string inputNameT()
{
    bool badInput = true;
    string name = "";
    while(badInput)
    {
    cout<<"Event Name: "<<endl;
    cin>>name;
     if(!cin || name == "")
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
    return name;
}

bool inputYNt()
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

void printTickets(vector<ticket> ticketData)
{
    for (size_t i=0; i<ticketData.size(); i++)
    {

        if(i % 10 == 0)
            cout<<"Section   Seat   Price   Availability   Event"<<endl;/// label for tickets prints every section
        ticketData[i].print(cout);

    }
}
void printAva(vector<ticket> ticketData)
{
    int counter = 0;
    for (size_t i=0; i<ticketData.size(); i++)
    {

        if(ticketData[i].getSold()==1)
        {

            if(counter % 10 == 0)
                cout<<"Section   Seat   Price   Availability   Event"<<endl;
            ticketData[i].print(cout);
            counter++;///if there is even one available ticket labels will print
        }
    }
}
void printUnAva(vector<ticket> ticketData)
{
    int counter = 0;
    for (size_t i=0; i<ticketData.size(); i++)
    {
        if(ticketData[i].getSold()==0)
        {
            if(counter % 10 == 0)
                cout<<"Section   Seat   Price   Availability   Event"<<endl;
            ticketData[i].print(cout);
            counter++;///if there is even one available ticket labels will print
            cout<<counter<<endl;
        }
    }
}

void readTickets(vector<ticket> &ticketData)/// reads data from ticket.txt and stores it in ticketData
{
    int section=0, seat=0, price=0;
    bool available =0;
    string name ="";
    ticket temp;
    ifstream inFile;
    inFile.open("ticket.txt");
    if(!inFile)
        cout<<endl<<"Cannot open the file";
    inFile >> section >> seat >> price >> available >> name;
    while(!inFile.eof())
    {
        temp.setSection(section);
        temp.setSeat(seat);
        temp.setPrice(price);
        temp.setSold(available);
        temp.setName(name);
        ticketData.push_back(temp);
        inFile >> section >> seat >> price >> available >> name;
    }
}

void ticketFile(vector<ticket> ticketData)///save function
{
    ofstream outFile;  /// prints ticketData vector to ticket.txt
    outFile.open("ticket.txt");
    for (size_t i=0; i<ticketData.size(); i++)
    {
        ticketData[i].print(outFile);
    }
    return;
}

bool sellRe()
{
    char SR=' ';
    while(true)
    {
      cout<<"Enter S to sell or R to refund:"<<endl;
      cin>>SR;
      cin.clear();
      cin.ignore(256, '\n');
    if(SR == 's'||SR=='S')
    {
        return true;
    }
    if(SR=='r'||SR=='R')
    {
        return false;
    }
    cout<<"\nInvalid entry."<<endl;
    }
}

char ticketMenu()
{
    char selection=' ';
    while(true)
    {
        cout<<endl;
        cout<<" Ticket Menu"<<endl;
        cout<<"1. Show all ticket info"<<endl;
        cout<<"2. Show all available tickets"<<endl;
        cout<<"3. Show all unavailable tickets"<<endl;
        cout<<"4. Sell/Refund ticket"<<endl;
        cout<<"5. Search for ticket by date"<<endl;
        cout<<"6. Main Menu"<<endl;
        cout<<"\nEnter Selection: "<<endl;
        cin>>selection;
        cin.clear();
        cin.ignore(256, '\n');
        if(selection>'0' && selection<'7')
            return selection;
        cout<<"PLEASE ENTER A VALID SELECTION\n\n"<<endl;
    }
}

/*string scheduleCheckT(vector<schedule> scheduleData)/// use schedule to check what events are happening on user given date
{
    string event = "";
    int outputCheck=0;
    cout<<"\n\n\n\n\n\n\n\n\n\n\n Event          Date         Time"<<endl<<endl;/// shows schedule of events for user
    for (size_t i=0; i<scheduleData.size(); i++)
    {
        scheduleData[i].print(cout);
    }
    cout<<"\nEnter the date of the event:"<<endl;
    int month=inputMonthT();
    int day=inputDayT();
    int year=inputYearT();
    size_t i=0;
    while(i < scheduleData.size())
        {
            if(scheduleData[i].getMonth()==month && scheduleData[i].getDay()==day &&scheduleData[i].getYear()==year)
            {
                cout<<"  \nEvents on "<<month<<"/"<<day<<"/"<<year<<endl;
                cout<<scheduleData[i].getEvent()<<"   "<<scheduleData[i].getHour()<<":"<<scheduleData[i].getMinute()<<endl;
                event = scheduleData[i].getEvent();
                ++outputCheck;
            }
            if(i == scheduleData.size()-1 && outputCheck == 0)
            {
                cout<<"There are no events on "<<month<<"/"<<day<<"/"<<year<<endl;
                cout<<"Would you like to try another date?"<<endl;
                bool tryAgain=inputYNt();
                if(!tryAgain)
                    return "";
                if(tryAgain)
                {
                    month=inputMonthT();
                    day=inputDayT();
                    year=inputYearT();
                    i=0;
                    continue;
                }
            }
            i++;
        }
        if(outputCheck == 1)
            {
                return event;
            }
        if(outputCheck > 1)/// user is prompted to pick their event(if there is more than one that day)
            {
                cout<<"Which event?"<<endl;
                event = inputNameT();
                i = 0;
                while(i < scheduleData.size())
                    {
                        if(scheduleData[i].getMonth() == month && scheduleData[i].getDay() == day && scheduleData[i].getYear() == year && scheduleData[i].getEvent() == event)
                            return event;
                        if(i == scheduleData.size()-1)
                        {
                            cout<<"\nEvent not recognized"<<endl;
                            cout<<"Please enter event name exactly as it appears above"<<endl;
                            event = inputNameT();
                            i=0;
                            continue;
                        }
                        i++;
                    }
            }
            return event;
}*/

size_t findTicket(vector<ticket> &ticketData, string event)/// user enters section and seat
{
    cout<<"\nWhat section is the ticket in?"<<endl;
    int section = inputZone();
    cout<<"\nWhat seat number"<<endl;
    int spot = inputSeat();
    for(size_t i=0; i<ticketData.size(); i++)
    {
        if(ticketData[i].getName()==event && ticketData[i].getSection()==section && ticketData[i].getSeat()==spot)
            return i;/// ticket place is returned as size_t
    }
    cout<<"error something went wrong"<<endl;
        return 0;
}

void ticketManager(vector<ticket> &ticketData, vector<schedule> &scheduleData, bank &bankData)
{
    system ("CLS");
    while(true){
        bool choice=true;
        char select=ticketMenu();
        switch(select)
        {
        case '1':
            printTickets(ticketData);
            break;
        case '2':
            printAva(ticketData);
            break;
        case '3':
            printUnAva(ticketData);
            break;
        case '4':
            {
            cout<<"Do you want to sell or refund a ticket?"<<endl;
            choice = sellRe();
            system ("CLS");
            if(choice)
                cout<<"\n"<<setw(25)<<"Selling Ticket"<<endl<<endl;
            else
                cout<<"\n"<<setw(25)<<"Refunding Ticket"<<endl<<endl;
            string event = scheduleCheck(scheduleData);
            if(event != "")///scheduleCheck will return "" if the user declines to try again after an invalid input
            {
                size_t place = findTicket(ticketData, event);
                if(choice)/// sell ticket
                    {
                      if(ticketData[place].getSold())
                      {
                          ticketData[place].setSold(0);
                          bankData.setSales(bankData.getSales()+45);
                          bankData.setCash(bankData.getCash()+45);
                          cout<<ticketData[place].getName()<<" ticket for seat "<<ticketData[place].getSeat()<<" in section "<<ticketData[place].getSection()<<" is sold."<<endl;
                          break;
                      }
                      if(!ticketData[place].getSold())
                        cout<<ticketData[place].getName()<<" ticket for seat "<<ticketData[place].getSeat()<<" in section "<<ticketData[place].getSection()<<" is already sold."<<endl;
                if(!choice)///refund ticket
                    {
                     if(!ticketData[place].getSold())
                      {
                          ticketData[place].setSold(1);
                          bankData.setSales(bankData.getSales()-45);
                          bankData.setCash(bankData.getCash()-45);
                          cout<<ticketData[place].getName()<<" ticket for seat "<<ticketData[place].getSeat()<<" in section "<<ticketData[place].getSection()<<" is refunded."<<endl;
                          break;
                      }
                      if(ticketData[place].getSold())
                        cout<<ticketData[place].getName()<<" ticket for seat "<<ticketData[place].getSeat()<<" in section "<<ticketData[place].getSection()<<" has not been sold."<<endl;
                    }
                   }
            }
            break;
        }
        case '5':
            {
            string event = scheduleCheck(scheduleData);///function to find ticket by date
            int place = findTicket(ticketData, event);
            cout<<"Section   Seat   Price   Availability   Event"<<endl;
            ticketData[place].print(cout);
            break;
            }
        case '6':
            return;
        }
    }
}









