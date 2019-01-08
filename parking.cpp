#include "parking.h"

int parking::getSection(){
    return section;
}
void parking::setSection(int inSection){
    section=inSection;
}

int parking::getSpace(){
    return space;
}
void parking::setSpace(int inSpace){
    space = inSpace;
}

int parking::getPrice(){
    return price;
}
void parking::setPrice(int inPrice){
    price = inPrice;
}

bool parking::getAvailable(){
    return available;
}
void parking::setAvailable(bool inAvailable){
    available=inAvailable;
}

void parking::print(ostream& out){
    out << setw(5) << getSection() <<setw(10) << getSpace() << setw(10) <<getPrice() << setw(10) <<getAvailable()<<endl;
}

void readParking(vector<parking> &parkingData)/// reads data from parking.txt and stores it in parkingData
{
    int section=0, space=0, price=0;
    bool available =0;
    parking temp;
    ifstream inFile;
    inFile.open("parking.txt");
    if(!inFile)
        cout<<endl<<"Cannot open the file";
    inFile >> section >> space >> price >> available;
    while(!inFile.eof())
    {
        temp.setSection(section);
        temp.setSpace(space);
        temp.setPrice(price);
        temp.setAvailable(available);
        parkingData.push_back(temp);
        inFile >> section >> space >> price >> available;
    }
}

void parkingFile(vector<parking> parkingData)///save function
{
    ofstream outFile;  /// prints parkingData vector to parking.txt
    outFile.open("parking.txt");
    for (size_t i=0; i<parkingData.size(); i++)
    {
        parkingData[i].print(outFile);
    }
    return;
}

void printParking(vector<parking> parkingData, int zone){
    size_t start =0;
    size_t i =0;
    size_t j =parkingData.size();
    if(zone != -1){
        start = zone * 30;
        j = start + 30;
        }
    for (i=start; i<j; i++)
    {
        if(i % 10 == 0)
            cout<<"Section    Space      Price  Availability"<<endl;
        parkingData[i].print(cout);
    }
}

void printAvailible(vector<parking> parkingData,int num)
{
    int availibility[30] ={ };
   for(size_t i=0; i<parkingData.size(); i++)
   {
       if (parkingData[i].getAvailable() == 1)
        {
            ++availibility[parkingData[i].getSection()];
        }
   }
   for(int j=0; j<30; j++)
   {
       if(availibility[j] >= num)
        cout<<"Section "<< j <<" has "<< availibility[j] <<" spaces available"<<endl;
   }
}

int getzone()
    {
      while(true)
      {
          int zone=0;
          cout<<"Section: "<<endl;
          cin>>zone;
          cin.clear();
          cin.ignore(256, '\n');
        if(zone>=0 && zone<20)
            return zone;
        cout<<"Invalid entry. Please enter a section 0-19\n\n"<<endl;

      }
    }

int getspot()
{
  while(true)
      {
          int spot=0;
          cout<<"Space number: "<<endl;
          cin>>spot;
          cin.clear();
          cin.ignore(256, '\n');
        if(spot>=0 && spot<30)
            return spot;
        cout<<"Invalid entry. Please enter a space 0-29\n\n"<<endl;
      }
}
bool getysno()
{
    char ysno=' ';
    while(true){
    cout<<"Enter y for yes\nEnter n for no"<<endl;
    cin>>ysno;
    cin.clear();
    cin.ignore(256, '\n');
    if(ysno == 'y'||ysno=='Y')
    {
        return true;
    }
    if(ysno=='n'||ysno=='N')
    {
        return false;
    }
    cout<<"Invalid entry."<<endl;
    }
}

char parkingMenu()
{
    char selection=' ';
    while(true)
    {
        cout<<endl;
        cout<<" Parking Menu"<<endl;
        cout<<"1. View all parking info"<<endl;
        cout<<"2. View parking info by section"<<endl;
        cout<<"3. View parking by availability"<<endl;
        cout<<"4. Change parking availability"<<endl;
        cout<<"5. Sell parking pass"<<endl;
        cout<<"6. Refund parking pass"<<endl;
        cout<<"7. Main Menu"<<endl;
        cout<<"\nEnter Selection: ";
        cin>>selection;
        cin.clear();
        cin.ignore(256, '\n');
        if(selection>'0' && selection<'8')
            return selection;
        cout<<"PLEASE ENTER A VALID SELECTION\n\n"<<endl;
    }
}
void parkingManager(vector<parking> &parkingData, bank &bankData)
{
    system ("CLS");
    int zone=-1;
    int num=0;
    int spot=0;
    while(true){
        char select=parkingMenu();
        switch(select)
        {
        case '7':
            return;
        case '1':
            printParking(parkingData, zone);
            break;
        case '2':
            cout<<"Which parking section would you like to view (enter a number 0-19)\n";
            zone=getzone();
            printParking(parkingData, zone);
            break;
        case '3':
            while(true){
            cout<<"How many parking spaces do you need?\n (enter a number 1-30): ";
            cin>>num;
            cin.clear();
            cin.ignore(256, '\n');
            if(num>0 && num<30){
                printAvailible(parkingData, num);
                break;
                }
            cout<<"PLEASE ENTER A VALID SELECTION\n\n"<<endl;
            }
            break;
        case '4':
            cout<<"\n********** Please note, changes made here will not refund customers **********"<<endl;
            cout<<"****************** or make changes to the bank account ***********************"<<endl<<endl;
            cout<<"What section is the parking space in?"<<endl;
            zone=getzone();
            cout<<"What space number do you want to change?"<<endl;
            spot=getspot();
            for(size_t i =0; i<parkingData.size(); i++)
                    {
                        if(parkingData[i].getSection()==zone && parkingData[i].getSpace()==spot)
                        {
                            if(parkingData[i].getAvailable()==1)
                            {
                                cout<<"Parking space "<<spot<<" in section "<<zone<<" is available, would you like to change it to unavailable?"<<endl;
                                if(getysno())
                                    {
                                        parkingData[i].setAvailable(0);
                                    }
                                break;
                            }
                            if(parkingData[i].getAvailable()==0)
                            {
                                cout<<"Parking space "<<spot<<" in section "<<zone<<" is unavailable, would you like to change it to available?"<<endl;
                                if(getysno())
                                    {
                                        parkingData[i].setAvailable(1);
                                    }
                               break;
                            }
                        }
                    }
                break;
        case '5':
            for (size_t i =0; i<parkingData.size(); i++)
                    {
                        if (parkingData[i].getAvailable() == 1)
                        {
                          parkingData[i].setAvailable(0);
                          bankData.setSales(bankData.getSales()+10);
                          bankData.setCash(bankData.getCash()+10);
                          cout<<"Sold parking space "<<parkingData[i].getSpace()<<" in section "<<parkingData[i].getSection()<<endl;
                          break;
                        }
                        else if (i == parkingData.size()-1){
                            cout<<"Parking lot is full"<<endl;
                            break;
                            }
                     }
                    break;
        case '6':
            cout<<"Which section and parking space would you like to refund?"<<endl;
                    zone=getzone();
                    spot=getspot();
                    for(size_t i =0; i<parkingData.size(); i++)
                    {
                        if(parkingData[i].getSection()==zone && parkingData[i].getSpace()==spot)
                        {
                            if(parkingData[i].getAvailable()==0)
                            {
                               parkingData[i].setAvailable(1);
                               bankData.setSales(bankData.getSales()-10);
                               bankData.setCash(bankData.getCash()-10);
                               break;
                            }
                            cout<<"This space is not sold"<<endl;
                            break;
                        }
                    }
                    break;
        }

    }
}


