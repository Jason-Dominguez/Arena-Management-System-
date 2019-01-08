#include "schedule.h"

string schedule::getEvent(){
    return event;
}
void schedule::setEvent(string inEvent){
    event=inEvent;
}

int schedule::getMonth(){
    return month;
}
void schedule::setMonth(int inMonth){
    month = inMonth;
}

int schedule::getDay(){
    return day;
}
void schedule::setDay(int inDay){
    day = inDay;
}

int schedule::getYear(){
    return year;
}
void schedule::setYear(int inYear){
    year=inYear;
}

int schedule::getHour(){
    return hour;
}
void schedule::setHour(int inHour){
    hour=inHour;
}

int schedule::getMinute(){
    return minute;
}
void schedule::setMinute(int inMinute){
    minute=inMinute;
}

void schedule::print(ostream& out){
    out <<left<<setw(12)<< getEvent()<<" "<<right<<setw(2)<<getMonth()<<"/"<<setw(2)<<getDay()<<"/"<<getYear();
    out <<setw(7)<< getHour() <<":"<<setw(2)<<setfill ('0')<<getMinute()<<setfill(' ')<<endl;
}

void printSchedule(vector<schedule> scheduleData)
{
    system ("CLS");
    cout<<" Event          Date         Time"<<endl<<endl;
    for (size_t i=0; i<scheduleData.size(); i++)
    {
        scheduleData[i].print(cout);
    }
    cout<<endl<<endl;
}

void readSchedule(vector<schedule> &scheduleData)/// reads data from schedule.txt and stores it in scheduleData
{
    string event="";
    int month=0, day=0, year=0, hour=0, minute=0;
    char x=' ';
    schedule temp;
    ifstream inFile;
    inFile.open("schedule.txt");
    if(!inFile)
        cout<<endl<<"Cannot open the file";
    inFile >> event >> month >> x >> day >> x >> year >> hour >> x >> minute;
    while(!inFile.eof())/// while loop to read file stops at end
    {
        temp.setEvent(event);
        temp.setMonth(month);
        temp.setDay(day);
        temp.setYear(year);
        temp.setHour(hour);
        temp.setMinute(minute);
        scheduleData.push_back(temp);
        inFile >> event >> month >> x >> day >> x >> year >> hour >> x >> minute;
    }
}

void scheduleFile(vector<schedule> scheduleData)///save function
{
    ofstream outFile;  /// prints scheduleData vector to schedule.txt
    outFile.open("schedule.txt");
    for (size_t i=0; i<scheduleData.size(); i++)
    {
        scheduleData[i].print(outFile);
    }
    return;
}

int inputMonth()
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
int inputDay()
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
int inputYear()
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
string inputName()
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

int inputHour()
{
    bool badInput = true;
    int hour = 0;
    while(badInput)
    {
    cout<<"Hour: "<<endl;
    cin>>hour;
     if(!cin || hour < 0 || hour > 24)
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
    return hour;
}
int inputMin()
{
    bool badInput = true;
    int minute = 0;
    while(badInput)
    {
    cout<<"Minute: "<<endl;
    cin>>minute;
     if(!cin || minute < 0 || minute > 60)
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
    return minute;
}
bool inputYN()
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

void eventCreator(vector<schedule> &scheduleData, vector<ticket> &ticketData)///NEED TO ADD ABILITY TO SET TICKET PRICE
{
    cout<<"\nNew Event"<<endl;
    cout<<"\nEnter the date of the new event"<<endl;
    string event = inputName();
    int month = inputMonth();
    int day = inputDay();
    int year = inputYear();
    int hour = inputHour();
    int minute = inputMin();
    size_t i = 0;
    while(i<scheduleData.size())
    {
        if(event == scheduleData[i].getEvent())
        {
            cout<<"\nAn event "<<event<<" already exists"<<endl;
            cout<<"Please choose a different name"<<endl<<endl;
            event = inputName();
            i=0;
            continue;
        }
        if(month == scheduleData[i].getMonth() && day == scheduleData[i].getDay() && year == scheduleData[i].getYear() && hour == scheduleData[i].getHour())
        {
            cout<<"\nAn event is already scheduled that day around that time"<<endl;
            cout<<"Please choose a different date"<<endl<<endl;
            month = inputMonth();
            day = inputDay();
            year = inputYear();
            i=0;
            continue;
        }
        i++;
    }
    ticket tempT;
    for(int section=0; section<50; section++)
    {
        for(int seat=0; seat<10; seat++)
        {
          tempT.setSection(section);
          tempT.setSeat(seat);
          tempT.setPrice(45);
          tempT.setSold(1);
          tempT.setName(event);
          ticketData.push_back(tempT);
        }
    }
    schedule tempS;
    tempS.setEvent(event);
    tempS.setMonth(month);
    tempS.setDay(day);
    tempS.setYear(year);
    tempS.setHour(hour);
    tempS.setMinute(minute);
    scheduleData.push_back(tempS);
    cout<<event<<" has been created on "<<month<<"/"<<day<<"/"<<year<<endl;
}
string scheduleCheck(vector<schedule> scheduleData)/// use schedule to check what events are happening on user given date
{
    string event = "";
    int outputCheck=0;
    cout<<"  Event          Date         Time"<<endl<<endl;/// shows schedule of events for user
    for (size_t i=0; i<scheduleData.size(); i++)
    {
        scheduleData[i].print(cout);
    }
    cout<<"\nEnter the date of the event:"<<endl;
    int month=inputMonth();
    int day=inputDay();
    int year=inputYear();
    size_t i = 0;
    while(i<scheduleData.size())
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
                bool tryAgain=inputYN();
                if(!tryAgain)
                    return "";
                if(tryAgain)
                {
                    month=inputMonth();
                    day=inputDay();
                    year=inputYear();
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
                event = inputName();
                i=0;
                while(i<scheduleData.size())
                    {
                        if(scheduleData[i].getMonth() == month && scheduleData[i].getDay() == day && scheduleData[i].getYear() == year && scheduleData[i].getEvent() == event)
                            return event;
                        if(i == scheduleData.size()-1)
                        {
                            cout<<"\nEvent not recognized"<<endl;
                            cout<<"Please enter event name exactly as it appears above"<<endl;
                            event = inputName();
                            i=0;
                            continue;
                        }
                        i++;
                    }
            }
            return event;
}

void cancel(string event, vector<schedule> &scheduleData, vector<ticket> &ticketData, bank &bankData)
{
    for (size_t i=0; i<scheduleData.size(); i++)
    {
        if (scheduleData[i].getEvent() == event)
        {
            scheduleData.erase(scheduleData.begin()+ i); /// erases event from schedule
            break;
        }
    }
    for (size_t i=0; i<ticketData.size(); i++)/// refunds tickets that have been bought for canceled event
    {
        if (ticketData[i].getName() == event && ticketData[i].getSold() == 0)
        {
            if(bankData.getCash() >= 45)/// uses cash on hand first
              bankData.setCash(bankData.getCash()-45);
            else                                      ///adds to debt if there is not enough cash to refund tickets
              bankData.setDebt(bankData.getDebt()+45);
        }
    }
    for (size_t i=0; i<ticketData.size(); i++)
    {                                         ///looks for event in tickets vector
        if(ticketData[i].getName() == event)
        {
          ticketData.erase(ticketData.begin()+i,ticketData.begin()+i+500); /// erases tickets for event
          break;
        }
    }
    cout<<endl;
    cout<<event<<" has been canceled and purchased tickets have been refunded"<<endl;
}

char editMenu(string nm)
{
    char menu = ' ';
    while(true)
    {
        cout<<endl;
        cout<<nm<<endl;
        cout<<"1. Change Name"<<endl;
        cout<<"2. Change Date"<<endl;
        cout<<"3. Change Time"<<endl;
        cout<<"4. Schedule Menu"<<endl;
        cout<<"\nEnter Selection: ";
        cin>>menu;
        cin.clear();
        cin.ignore(256, '\n');
        if(menu>'0' && menu<'5')
            return menu;
        cout<<"PLEASE ENTER A VALID SELECTION\n\n"<<endl;
    }
}
void edit(string event, vector<schedule> &scheduleData, vector<ticket> &ticketData)
{
    system ("CLS");
    size_t place = 0;
    for(size_t i=0; i<scheduleData.size(); i++)///gets place of event in vector scheduleData to check for conflicts later
            {
                if(event == scheduleData[i].getEvent())
                {
                    place = i;
                }
            }
    while(true){
        char menu = editMenu(event);
        switch(menu){
        case '1':
        {
           cout<<"\n\nEditing "<<event<<endl<<endl;
           cout<<"Enter New Name:"<<endl;
           string newName=inputName();
           size_t i = 0;
           while(i<scheduleData.size())///loop checks new name is not already in use
               {                                         ///gets user to change new name and rechecks if it is
                 if(scheduleData[i].getEvent() == newName)
                 {
                     cout<<"\nThe name "<<newName<<" is already in use"<<endl;
                     cout<<"Please choose a different name"<<endl;
                     newName=inputName();
                     i=0;
                     continue;
                 }
               }
            scheduleData[place].setEvent(newName);///changes name in schedule
            for(i=0; i<ticketData.size(); i++)///changes name in tickets
               {
                   if(ticketData[i].getName() == event)
                        ticketData[i].setName(newName);
               }
           cout<<event<<" has been changed to "<<newName<<endl;
           return;
        }
        case '2':
        {
            cout<<"\n\nEditing "<<event<<endl;
            cout<<"Enter New Date:"<<endl;
            int newMonth=inputMonth();
            int newDay=inputDay();
            int newYear=inputYear();
            size_t i = 0;
            while(i<scheduleData.size())///loop checks if there are conflicts with new date
                {
                    if(newMonth == scheduleData[i].getMonth() && newDay == scheduleData[i].getDay() && newYear == scheduleData[i].getYear() && scheduleData[place].getHour() == scheduleData[i].getHour())
                    {
                        cout<<"\nAn event is already scheduled that day around that time"<<endl;
                        cout<<"Would you like to try another date?"<<endl;
                        bool tryAgain=inputYN();
                        if(!tryAgain)
                            return;
                        if(tryAgain)
                            {
                                newMonth=inputMonth();
                                newDay=inputDay();
                                newYear=inputYear();
                                i=0;
                                continue;
                            }
                    }
                    i++;
                }
            scheduleData[place].setMonth(newMonth);
            scheduleData[place].setDay(newDay);
            scheduleData[place].setYear(newYear);
            cout<<"\nDate for "<<event<<" has been changed to "<<newMonth<<"/"<<newDay<<"/"<<newYear<<endl;
            return;
        }
        case '3':
        {
          cout<<"\n\nEditing "<<event<<endl;
          cout<<"Enter New Time:"<<endl;
          int newHour = inputHour();
          int newMinute = inputMin();
          size_t i = 0;
          while(i<scheduleData.size())///loop checks if there are conflicts with new time
            {
                if(scheduleData[place].getMonth() == scheduleData[i].getMonth() &&  scheduleData[place].getDay() == scheduleData[i].getDay() && scheduleData[place].getYear() == scheduleData[i].getYear() && newHour == scheduleData[i].getHour())
                {
                    cout<<"\nAn event is already scheduled that day around that time"<<endl;
                    cout<<"Would you like to try another time?"<<endl;
                    bool tryAgain=inputYN();
                    if(!tryAgain)
                        return;
                    if(tryAgain)
                        {
                            newHour=inputHour();
                            newMinute=inputMin();
                            i=0;
                            continue;
                        }
                }
                i++;
            }
          scheduleData[place].setHour(newHour);
          scheduleData[place].setMinute(newMinute);
          return;
        }
        }
    }
}

char scheduleMenu()
{
    char selection=' ';
    while(true)
    {
        cout<<endl;
        cout<<" Schedule Menu"<<endl;
        cout<<"1. Create new event"<<endl;
        cout<<"2. Show all upcoming events"<<endl;
        cout<<"3. Edit existing events"<<endl;
        cout<<"4. Cancel an event"<<endl;
        cout<<"5. Search for events by date"<<endl;
        cout<<"6. Main Menu"<<endl;
        cout<<"\nEnter Selection: ";
        cin>>selection;
        cin.clear();
        cin.ignore(256, '\n');
        if(selection>'0' && selection<'7')
            return selection;
        cout<<"PLEASE ENTER A VALID SELECTION\n\n"<<endl;
    }
}
void manageSchedule(vector<schedule> &scheduleData, vector<ticket> &ticketData, bank &bankData)
{
    system ("CLS");
    while(true){
        char select= scheduleMenu();
        switch(select)
        {
        case '6':
            return;
        case '1':
            eventCreator(scheduleData, ticketData);
            break;
        case '2':
            printSchedule(scheduleData);
            break;
        case '3':
            {
            cout<<"\nWhen is the event?"<<endl;
            string event=scheduleCheck(scheduleData);
            if(event != "")
                edit(event, scheduleData, ticketData);
            break;
            }
        case '4':
            {
            cout<<"\nWhen is the event you want to cancel?"<<endl;
            string event=scheduleCheck(scheduleData);
            if(event != "")
                cancel(event, scheduleData, ticketData, bankData);
            break;
            }
        case '5':
            {
            string event=scheduleCheck(scheduleData);
            if(event != "")
            {
                int counter = 0;
                for (size_t i = 0; i<ticketData.size(); i++)
                {
                    if(event == ticketData[i].getName() && 0 == ticketData[i].getSold())
                        ++counter;
                }
                for (size_t i=0; i<scheduleData.size(); i++)
                    {
                        if(event == scheduleData[i].getEvent())
                        {
                            cout<<"\nEvent  Date  Time"<<endl;
                            scheduleData[i].print(cout);
                            cout<<"Tickets Sold: "<<counter<<endl;
                            break;
                        }

                    }
            }
            break;
            }
        }
    }
}
