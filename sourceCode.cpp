//Source Code
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<stdio.h>
#include<windows.h>

using namespace std;

ofstream fout;   // ofstream writing
ifstream fin;    // ifstream reading
string NewWorkerName;
string NewWorkerPassword;
int ans;
char Wish;

//TRAVEL BY AIRWAYS

class airways
{
int mem;  		           //input the members
char name[30];     		//take input name
char id[30];       		//take email id
char tra;          		//take mode of travel
unsigned int price;     	//price of travelling
char dest[30];          	//travel destination
char purpose[20];
char mode_of_reaching[20];
public:
airways()
{ mem=0;
  tra='a';
  price=0;
}

char* ret_name()     //return name
{ return name; }
char* ret_id()       //return email id
{ return id;   }
char ret_tra()       //return mode of travel
{ return tra;  }

void input();
void travelling(char,int);
void output();
}t; //Airway class object = t

void airways::travelling(char choice,int mem)
{
int xx;
if(choice=='n'||choice=='N')
 { cout<<"\n 1. Flight-> Pune to Jaipur		Per ticket Rs. 5300";
   cout<<"\n 2. Flight-> Pune to Mumbai		Per ticket Rs. 3500";
   cout<<"\n 3. Flight-> Pune to Chennai		Per ticket Rs. 3400";
   cout<<"\n 4. Flight-> Pune to Kolkata		Per ticket Rs. 7200";
   cout<<"\n 5. Flight-> Pune to Delhi		Per ticket Rs. 4700";
   cout<<"\n Enter your choice : ";
   cin>>xx;
   if(xx==1)
   { price=(mem*5300);
     strcpy(dest,"Pune to Jaipur");
   }
   if(xx==2)
   { price=(mem*3500);
     strcpy(dest,"Pune to Mumbai");
   }
   if(xx==3)
   { price=(mem*3400);
     strcpy(dest,"Pune to Chennai");
   }
   if(xx==4)
   { price=(mem*7200);
     strcpy(dest,"Pune to Kolkata");
   }
   if(xx==5)
   { price=(mem*4700);
     strcpy(dest,"Pune to Delhi");
   }
    
   cout<<"\n Booking confirmed!!";
   cout<<"\n Total fare: "<<price;
 }
if(choice=='i'||choice=='I')
 { cout<<"\n 1. Flight-> Delhi to USA		Per ticket Rs. 41000 ";
   cout<<"\n 2. Flight-> Delhi to Australia		Per ticket Rs. 37000";
   cout<<"\n 3. Flight-> Delhi to France		Per ticket Rs. 29000";
   cout<<"\n 4. Flight-> Delhi to Switzerland	Per ticket Rs. 33000";
   cout<<"\n Enter your choice : ";
   cin>>xx;
   
   if(xx==1)
   { price=(mem*41000);
     strcpy(dest,"Delhi to USA");
   }
   if(xx==2)
   { price=(mem*37000);
     strcpy(dest,"Delhi to Australia");
   }
   if(xx==3)
   { price=(mem*29000);
     strcpy(dest,"Delhi to France");
   }
   if(xx==4)
   { price=(mem*33000);
     strcpy(dest,"Delhi to Switzerland");
   }

   cout<<"\n Booking confirmed!!!";
   cout<<"\n Total fare: "<<price;
 }
}
void airways::input()
{ fflush(stdin);
  cout<<"\n Enter your name: ";
  gets(name);
  cout<<"\n Enter e-mail id: ";
  gets(id);
  cout<<"\n Enter the no. of passengers you are travelling with: ";
  cin>>mem;
  if(mem>=1 && mem<=10)
  { cout<<"\n Where you want to travel? (National = N & Internationl = I): ";
    cin>>tra;
  }
  travelling(tra,mem);
  fflush(stdin);
  cout<<"\n \n Enter the purpose of visit (Professional or Personal): ";
  gets(purpose);
  cout<<"\n Mode of transportation for reaching the airport: ";
  gets(mode_of_reaching);
}
void airways::output()
{ cout<<"\n NAME : "<<name;
  cout<<"\n E-MAIL : "<<id;
  cout<<"\n No of companions: "<<mem;
  cout<<"\n Purpose of visit: "<<purpose;
  cout<<"\n Mode of transportation for reaching airpot: "<<mode_of_reaching;
  cout<<"\n TRAVELLING  NATIONAL/INTERNATIONAL : "<<tra;
  cout<<"\n Destination: "<<dest;
  cout<<"\n Total Fare: Rs."<<price;
}
void entry()              //take the entry
{  char ch='y';
   fout.open("fly.txt",ios::app);
   while(ch=='y'||ch=='Y')
   { system("cls");
     t.input();
     fout.write((char*)&t,sizeof(t));
     cout<<"\n More Record (Y/N) : ";
     cin>>ch;
   }
   fout.close();
}
void display()             //display the entry
{  fin.open("fly.txt",ios::in);
   fin.seekg(0);
   fin.read((char*)&t,sizeof(t));
   while(!fin.eof())
   { t.output();
     cout<<endl;
     fin.read((char*)&t,sizeof(t));
   }
   fin.close();
}
void search()            //search the entry
{ fin.open("fly.txt",ios::in|ios::app);
  char n[20];
  fflush(stdin);
  cout<<"\n Search Your Booking by name : ";
  gets(n);
  while(fin.read((char*)&t,sizeof(t)))
  {  if(strcmpi(n,t.ret_name())==0)
     { t.output();
       fin.read((char*)&t,sizeof(t));
     }
  }
  fin.close();
}
void delete_booking(char* id)        //delete the entry
{ fin.open("fly.txt",ios::in);
  fout.open("second.txt",ios::out);
  char found='n';
  while(fin.read((char*)&t,sizeof(t)))
  { if(strcmpi(id,t.ret_id())!=0)
     {  fout.write((char*)&t,sizeof(airways));   }
    else
     {	found='y';   }
  }
  if(found=='n')
  cout<<"\n Record not found";
fin.close();
fout.close();
cout<<"\n Account deleted\n";
remove("fly.txt");
rename("second.txt","fly.txt");
}
void flight_admin()
{ int x; char ans; char id1[30];
  do{   system("cls");
    cout<<"\n....WELCOME TO AIRWAY SERVICES....\n\n";
    cout<<"\n 1. Booking for flight.";
    cout<<"\n 2. Display bookings.";
    cout<<"\n 3. Search booking.";
    cout<<"\n 4. Delete booking.";
    cout<<"\n Enter your choice : ";
    cin>>x;
    switch(x)
      { 
	  case 1:
	   entry();
    break;
    case 2:
    display();
    break;
    case 3: search();
    break;
    case 4:
    display();
    fflush(stdin);
    cout<<"\n Enter the email id to be deleted : ";
    gets(id1);
    delete_booking(id1);
    break;
    default:
    cout<<"\n Try Again\n";
        }
        cout<<"\n GO BACK TO AIRWAY SERVICES (Y/N) : ";
        cin>>ans;
      }while(ans=='y'||ans=='Y');
}
void flight_user()
{
  int x; char ans; char id1[30];
  do{   system("cls");
    cout<<"\n....WELCOME TO AIRWAY SERVICES....\n\n";
    cout<<"\n 1. Booking for flight: ";
    cout<<"\n 2. Display your booking: ";
    cout<<"\n 3. Cancel Booking: ";
    cout<<"\n Enter your choice: ";
    cin>>x;
    switch(x)
      { 
	  case 1:
	  entry();
    break;
    case 2:
    search();
    break;
    case 3: 
    fflush(stdin);
    cout<<"\n Enter the email id to be deleted : ";
    gets(id1);
    delete_booking(id1);
    break;
    default:
    cout<<"\n Try Again\n";
        }
        cout<<"\n GO BACK TO AIRWAY SERVICES (Y/N) : ";
        cin>>ans;
      }while(ans=='y'||ans=='Y');
}
//==============================================
//TRAVEL BY RAILWAYS

class rail
{
int mem;			//take the input of members
char name[20];		//take input name
char id[30];			//take email id			
unsigned int price;		//take the travelling price
char dest[30];		//take the input of destination
char purpose[20];
char mode_of_reaching[20];
public:
rail()
{ mem=0;
  price=0;
}
char* ret_name()
{ return name; }
char* ret_id()
{ return id;   }
void input();
void travelling(int);
void output();
}r;
//Railway class object = r
void rail::travelling(int mem)
{
int xx;
   cout<<"\n 1. Train -> Pune to Mumbai   Per ticket Rs. 720";
   cout<<"\n 2. Train -> Pune to Patna    Per ticket Rs. 1800";
   cout<<"\n 3. Train -> Pune to Delhi    Per ticket Rs. 2800";
   cout<<"\n 4. Train -> Pune to Punjab   Per ticket Rs. 750";
   cout<<"\n 5. Train -> Pune to Lucknow  Per ticket Rs. 1600";
   cout<<"\n Enter your choice : ";
   cin>>xx;
   if(xx==1)
   { price=(mem*720);
     strcpy(dest,"Pune to Mumbai");
   }
   if(xx==2)
   { price=(mem*1800);
     strcpy(dest,"Pune to Patna");
   }
   if(xx==3)
   { price=(mem*2800);
     strcpy(dest,"Pune to Delhi");
   }
   if(xx==4)
   { price=(mem*750);
     strcpy(dest,"Pune to Punjab");
   }
   if(xx==5)
   { price=(mem*1600);
     strcpy(dest,"Pune to Lucknow");
   }
   
   cout<<"\n Total fare: Rs. "<<price;
   cout<<"\n Booking confirmed";
}
void rail::input()
{
  fflush(stdin);
  cout<<"\n Enter your name: ";
  gets(name);
  cout<<"\n Enter e-mail id: ";
  gets(id);
  cout<<"\n Enter the no. of passengers you are travelling with: ";
  cin>>mem;
  if(mem>=1 && mem<=8)
  { travelling(mem);
  }
}
void rail::output()
{ cout<<"\n Name: "<<name;
  cout<<"\n E-mail: "<<id;
  cout<<"\n No of companions: "<<mem;
  cout<<"\n Destination:  "<<dest;
  cout<<"\n Total Fare: Rs. "<<price;
}
void entry1()              //take the entry
{
   fout.open("rail.txt",ios::app);
   while(1)
   { system("cls");
     r.input();
     fout.write((char*)&r,sizeof(r));
     break;
   }
   fout.close();
}
void display1()             //display the entry
{  fin.open("rail.txt",ios::in);
   fin.seekg(0);
   fin.read((char*)&r,sizeof(r));
   while(!fin.eof())
   { r.output();
     cout<<endl;
     fin.read((char*)&r,sizeof(r));
   }
   fin.close();
}
void search1()            //search the entry
{ fin.open("rail.txt",ios::in|ios::app);
  char n[20];
  fflush(stdin);
  cout<<"\n Search Your Booking by name : ";
  gets(n);
  while(fin.read((char*)&r,sizeof(r)))
  {  if(strcmpi(n,r.ret_name())==0)
     { r.output();
       fin.read((char*)&r,sizeof(r));
     }
  }
  fin.close();
}
void delete_booking_id1(char* id)        //delete the entry
{ fin.open("rail.txt",ios::in);
  fout.open("new.txt",ios::out);
  char found='n';
  while(fin.read((char*)&r,sizeof(r)))
  { if(strcmpi(id,r.ret_id())!=0)
     {  fout.write((char*)&r,sizeof(rail));   }
    else
     {	found='y';   }
  }
  if(found=='n')
  cout<<"\n Record not found";
fin.close();
fout.close();
cout<<"\n Account deleted\n";
remove("rail.txt");
rename("new.txt","rail.txt");
}
void train_admin()
{ int x; char ans; char id1[30];
  do{  system("cls");
    cout<<"\n....WELCOME TO RAILWAY SERVICES....\n\n";
    cout<<"\n 1. Booking for train.";
    cout<<"\n 2. Display bookings.";
    cout<<"\n 3. Search booking.";
    cout<<"\n 4. Delete booking.";
    cout<<"\n Enter your choice : ";
    cin>>x;
    switch(x)
      { case 1: entry1();
	break;
	case 2: display1();
	break;
	case 3: search1();
	break;
	case 4:
  display1();
	cout<<"\n Enter the email id to be deleted : ";
	fflush(stdin);
	gets(id1);
	delete_booking_id1(id1);
	break;
      }
      cout<<"\n GO BACK TO RAILWAY SERVICES (Y/N) : ";
      cin>>ans;
    }while(ans=='y'||ans=='Y');
}
void train_user()
{
  int x; char ans; char id1[30];
  do{  system("cls");
    cout<<"\n....WELCOME TO RAILWAY SERVICES....\n\n";
    cout<<"\n 1. Booking for train";
    cout<<"\n 2. Display Your booking";
    cout<<"\n 3. Cancel booking";
    cout<<"\n Enter your choice : ";
    cin>>x;
    switch(x)
      { 
        case 1: entry1();
        break;
        case 2: search1();
        break;
        case 3:
        cout<<"\n Enter your Email id: ";
        fflush(stdin);
        gets(id1);
        delete_booking_id1(id1);
        break;
      }
      cout<<"\n GO BACK TO RAILWAY SERVICES (Y/N) : ";
      cin>>ans;
    }while(ans=='y'||ans=='Y');
}
//=========================================================
//TAVEL BY cab

class cab
{
int mem;			//take the input of members
char name[20];		//take input name
char id[30];			//take phone no.			
unsigned int price;		//take the travelling price
char dest[30];		//take the input of destination
char purpose[20];
int pkm;			//price per kilometer = 8
public:
cab()
{ 
	mem=0;
	price=0;
  pkm=8;
}
char* ret_name()
{ return name; }
char* ret_id()
{ return id;   }
void input();
void travelling(int);
void output();
}ti; //Roadway class object = ti

void cab::travelling(int mem)
{ 
 
 int xx;
 
   cout<<"\n 1. 1km < Distance <=5km";
   cout<<"\n 2. 5km < Distance <= 10km";
   cout<<"\n 3. 10km < Distance <= 15km";
   cout<<"\n 4. 15km < Distance <= 20km";
   cout<<"\n 5. Rental for a day.";
   cout<<"\n Enter your choice : ";
   cin>>xx;
   if(xx==1)
   { price=(mem*20 + 5*pkm);
     strcpy(dest,"1km to 5km");
   }
   if(xx==2)
   { price=(mem*20 + 9*pkm);
     strcpy(dest,"5km to 10km");
   }
   if(xx==3)
   { price=(mem*20 + 13*pkm);
     strcpy(dest,"10km to 15km");
   }
   if(xx==4)
   { price=(mem*20 + 18*pkm);
     strcpy(dest,"15km to 20km");
   }
   if(xx==5)
   { price=(mem*20 + 3000);
     strcpy(dest,"Rental for a day");
   }
    cout<<"\n Total fare: Rs. "<<price;
    cout<<"\n Booking confirmed";




}
void cab::input()
{
  fflush(stdin);
  cout<<"\n Enter your name: ";
  gets(name);
  cout<<"\n Phone no. : ";
  gets(id);
  cout<<"\n Enter the no. of passengers you are travelling with (max = 4): ";
  cin>>mem;
  if(mem>=1 && mem<=4)
  { 
    travelling(mem);
    fflush(stdin);
    cout<<"\n\n Whats the purpose of your visit: ";
    gets(purpose);
  }
  else exit(1);
}
void cab::output()

{ cout<<"\n Name: "<<name;
  cout<<"\n Phone No.: "<<id;
  cout<<"\n No. of companions: "<<mem;
  cout<<"\n Package: "<<dest;
  cout<<"\n Purpose of your visit: "<<purpose;
  cout<<"\n Total Fare: Rs. "<<price;
}
void entry2()              //take the entry
{
   fout.open("cab.txt",ios::app);
   while(1)
   { system("cls");
     ti.input();
     fout.write((char*)&ti,sizeof(ti));
     break;
   }
   fout.close();
}
void display2()             //display the entry
{  fin.open("cab.txt",ios::in);
   fin.seekg(0);
   fin.read((char*)&ti,sizeof(ti));
   while(!fin.eof())
   { ti.output();
     cout<<endl;
     fin.read((char*)&ti,sizeof(ti));
   }
   fin.close();
}
void search2()            //search the entry
{ fin.open("cab.txt",ios::in|ios::app);
  char n[20];
  fflush(stdin);
  cout<<"\n Search Your Booking by name : ";
  gets(n);
  while(fin.read((char*)&ti,sizeof(ti)))
  {  if(strcmpi(n,ti.ret_name())==0)
     { ti.output();
       fin.read((char*)&ti,sizeof(ti));
     }
  }
  fin.close();
}
void delete_booking_id2(char* name)        //delete the entry
{ fin.open("cab.txt",ios::in);
  fout.open("txta.txt",ios::out);
  char found='n';
  while(fin.read((char*)&ti,sizeof(ti)))
  { if(strcmpi(name,ti.ret_name())!=0)
     {  fout.write((char*)&ti,sizeof(cab));    }
    else
     {	found='y';    }
  }
  if(found=='n')
  cout<<"\n Record not found";
fin.close();
fout.close();
cout<<"\n Account deleted\n";
remove("cab.txt");
rename("txta.txt","cab.txt");
}
void taxi_admin()
{ int x; char ans; char id1[30];
  do{   system("cls");
    cout<<"\n....WELCOME TO CAB services.... \n\n";
    cout<<"\n 1.Booking for cab";
    cout<<"\n 2.Display bookings";
    cout<<"\n 3.Search  bookings";
    cout<<"\n 4.Delete booking";
    cout<<"\n Enter your choice : ";
    cin>>x;
    switch(x)
      { 
	case 1: entry2();
	break;
	case 2: display2();
	break;
	case 3: search2();
	break;
	case 4:
  display2();
	fflush(stdin);
	cout<<"\n Enter the name to be deleted: ";
	gets(id1);
	delete_booking_id2(id1);
	break;
      }
      cout<<"\n GO BACK TO cab SERVICES (Y/N) : ";
      cin>>ans;
    }while(ans=='y'||ans=='Y');
}
void taxi_user()
{
int x; char ans; char id1[30];
  do{   system("cls");
    cout<<"\n....WELCOME TO CAB service.... \n\n";
    cout<<"\n 1. Booking for cab. ";
    cout<<"\n 2. Display your booking. ";
    cout<<"\n 3. Cancel booking. ";
    cout<<"\n Enter your choice : ";
    cin>>x;
    switch(x)
      { 
	case 1: entry2();
	break;
	case 2: 
  search2();
	break;
	case 3:
  fflush(stdin);
	cout<<"\n Enter your name to cancel booking: ";
	gets(id1);
	delete_booking_id2(id1);
	break;
	break;
      }
      cout<<"\n GO BACK TO CAB services (Y/N) : ";
      cin>>ans;
    }while(ans=='y'||ans=='Y');
}

void loading_screen(){
                              
    int count=0;
    system("color 3");
  	cout<<endl;
  	cout<<"\t******************************\n"; 
   	cout<<"\t*         Welcome            *\n";
	cout<<"\t*           To               *\n"; 
    cout<<"\t*  Travel Agency Management  *\n";
    cout<<"\t*         System             *\n";   
    cout<<"\t******************************\n";
   cout<<endl;
   cout<<endl;
   cout<<endl;
   cout<<"\tLoading ";
   Sleep(300);//For Pause 
   cout<<"<"; 
   Sleep(100);//For Pause
   cout<<">"; 
   Sleep(300);//For Pause  
   cout<<"<"; 
      Sleep(100);//For Pause 
   cout<<">"; 
   Sleep(100);//For Pause
   cout<<"<"; 
   Sleep(300);//For Pause
   cout<<">"; 
   Sleep(100);//For Pause  
   cout<<"<"; 
      Sleep(100);//For Pause 
   cout<<">"; 
   Sleep(100);//For Pause
   cout<<"<"; 
      Sleep(100);//For Pause 
   cout<<">"; 
   Sleep(100);//For Pause
   cout<<"<"; 
      Sleep(100);//For Pause 
   cout<<">"; 
   Sleep(100);//For Pause
   cout<<"<"; 
      Sleep(100);//For Pause 
   cout<<">"; 
   Sleep(100);//For Pause
   cout<<"\n\n\tSuccessful\n";

   Sleep(1000);//For Pause
   system("CLS");//To Clear The Screen

}

void admin_login()
{
  start:
  string AdminName="admin";
  string AdminPassword="admin";
  int choice;
  int hide;
  string UserName;//declaration
  string Password;//declaration

        
              
        //************************************************************************************
				//*                           Admin Login                                            *
				//************************************************************************************     
				        system("CLS");
                cout<<"\t ********************"<<endl;
                cout<<"\t *  Admin Login     *"<<endl;
                cout<<"\t ********************"<<endl;
                cout<<endl;
                Sleep(500);//For Pause
                
                cout<<" Hint:- admin\n";
                cout<<"\n UserName: ";
                cin>>UserName;
                cout<<" Password: ";
                hide = getch();

                while (hide !=13)
                  {
                    Password.push_back(hide);
                    cout << '*';
                    hide = getch();
                  }
                

                if (UserName== AdminName && Password == AdminPassword)
                {
                    cout<<"\n Login Successful \n";
                    Sleep(1000);
                    system("CLS");
          

                    do
                    {
                        system("CLS");
                        cout<<"\t ********************"<<endl;
                        cout<<"\t *    Admin Login   *"<<endl;
                        cout<<"\t ********************"<<endl;
                        cout<<endl;
                        cout<<"1. Airline record"<<endl;
                        cout<<endl;
                        cout<<"2. Train record"<<endl;
                        cout<<endl;
                        cout<<"3. Cab record"<<endl;
                        cout<<endl;
                        cout<<"4. Log Out"<<endl;
                        cout<<endl;
                        cout<<"    Select : ";
                        cin>>choice;
                        switch (choice)
                        {
                        case 1:
                        system("cls");
                        flight_admin();   
                        break;
                        case 2:
                        system("cls");
                        train_admin();
                        break;
                        case 3:
                        system("cls");
                        taxi_admin();
                        break;
                        case 4:
                        system("CLS");
                        cout<<"\t\n\n Click any key to logout\n";
                        break;
                        default:
                        cout<<" You Entered Wrong Choice"<<endl;
                        break;
                        }
                         if(choice==4)
                                 {
                                 break;
                                 }

                    cout<<" Press any key to continue...... ";
                     Wish=getch();
                                 }while(Wish);
                    
                }
                else
                  {
                      cout<<"\n Incorrect User Name And Password\n";
                      cout<<" Please Try Again";
                      Sleep(1000);
                      goto start;
                  }
          

}

void user_login()
{
  {
    start:
    int hide;
    int choice;
    string UserName;
    string Password;

            
                        system("CLS");
                        cout<<"\t ********************"<<endl;
                        cout<<"\t *  User Login     *"<<endl;
                        cout<<"\t ********************"<<endl;
                        cout<<"\n Hint:- user\n";
                        cout<<" UserName: ";
                        cin>>UserName;
                        cout<<" Password: ";
                        hide = getch();

                        while (hide !=13)
                        {
                          Password.push_back(hide);
                          cout << '*';
                          hide =getch();
                        }
         
                       if(UserName== "user" && Password == "user" || UserName== NewWorkerName && Password == NewWorkerPassword )
                       {
                            cout<<"\n Login Successful \n";
      
                            Sleep(1000);
                            
                            system("CLS");

                            //*                             DiSpLaYiNg MeNu On The ScReEn    
                  
                            do
                            {
                                    system("CLS");
                                    cout<<"\t ********************"<<endl;
                                    cout<<"\t * User Login      *"<<endl;
                                    cout<<"\t ********************"<<endl;
                                    cout<<endl;
                                    cout<<" <1> Flight Booking"<<endl;
                                    cout<<endl;
                                    cout<<" <2> Train Booking"<<endl;
                                    cout<<endl;
                                    cout<<" <3> Cab Booking"<<endl;
                                    cout<<endl;
                                    cout<<" <4> Log Out"<<endl;
                                    cout<<endl;
                                    cout<<"     Select : ";
                                    cin>>choice;

                                    switch (choice)
                                      {
                                      case 1:
                                      system("cls");
                                      flight_user();   
                                      break;
                                      case 2:
                                      system("cls");
                                      train_user();
                                      break;
                                      case 3:
                                      system("cls");
                                      taxi_user();
                                      break;
                                      case 4:
                                      system("CLS");
                                      cout<<"\t\t\n For Logout\n";
                                      break;
                                      default:
                                      break;
                                      }
                            if(choice==4)
     {
      break;
     }
 cout<<" Press any key to continue...... ";
 Wish=getch();
    }while(Wish); 
                            
                       }

                        else
                  {
                      cout<<" \n\nIncorrect User Name And Password";
                      cout<<" \nPlease Try Again";
                      Sleep(1000);
                      goto start;
                  }
            
        }
}

int main()
{
	loading_screen();
	int choice;
    do
    {
        system("cls");
        fflush(stdin);
	cout<<"\t **********************"<<endl;
	cout<<"\t *Travel Agency System*"<<endl;
	cout<<"\t **********************"<<endl;
	cout<<endl;
	  
	cout<<" *************************"<<endl;
	cout<<" * <1>  For Admin Login  *"<<endl;
	cout<<" *************************"<<endl;
	cout<<endl;   
	cout<<" **************************"<<endl;
	cout<<" * <2> For User Login     *"<<endl;
	cout<<" **************************"<<endl;
	cout<<endl;
	cout<<" ******************"<<endl;
	cout<<" * <3> For Exit   *"<<endl;
	cout<<" ******************"<<endl;
	cout<<endl;
	cout<<" Select: ";
	cin>>choice;

    switch (choice)
    {
    case 1:{
     admin_login(); 
    }
     
    break;

    case 2:
      user_login();    
    break;
    
    case 3:
    {
      system("CLS");
      cout<<" \n\t Thank You so much for using our travelling agency..... \n\n\n\n";
      exit(0);
      break;
    }

    default:
    cout<<"\n You Entered Wrong Choice";
    break;
    }

    cout<<"\t\n Press any key to continue...... ";
    Wish=getch();
    }while(Wish);
 
 
 return 0;
}
