#include<bits/stdc++.h>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<direct.h>
#include<process.h>
#include<stdlib.h>
#include<math.h>
#include "windows.h"
using namespace std;
void addrecord();
void delrecord();
void modrecord();
void disprecord();
void dispall();
void head();
void head();
void loading();
float w,z;
void gotoxy(int x, int y) 
{ 
    COORD coord;
    coord.X = x; 
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void loading()
{
  for (int i=0;i<101;i++)
    {
      cout<<"loading…";
      gotoxy(40,10);
      cout<<i<<"%";
      Sleep(30);
    }
  char password[25];
  cout<<"\n\n\n\n\n\n\n\n\t\t\t ENTER THE PASSWORD:";
  gets(password);
  char t[13]="WELCOME";
  if(strcmp(password,t)!=0)
  {
    cout<<"\t\t\t WRONG PASSWORD!!!";
    cout<<"\n\t\t\t press any key to exit…";  
  }
  cout<<" \n\n\t\t PASSWORD ACCEPTED\a\a";
}
class account
  {
    int admino;
    char name[30];
    char cls[10];
    public:

  //member function to return admission no
    int giveadmino()
    {
      return admino;
    }
    //function to get data from user
    void getdata()
    {
      cout<<"\n Admission no:";
      cin>>admino;
      cout<<"\n Enter students name:";
      gets(name);
      cout<<" ";
      cout<<"\n Enter class:";
      gets(cls);
      cout<<" ";
    }
    //member function to display details
    void disdata()
    {
      int scrnt=0;
      if(scrnt==1)
      {
        cout<<"\n Display all menu";

      scrnt=0;
      }
        cout<<"\n\n Admission number:";
        cout<<admino;
        cout<<"\n Name of student:";
        cout<<name;
        cout<<"\n Class:";
        cout<<cls;
        scrnt++;
   } 
};
int main()
{
  int mch;
  loading();
  //main menu
  do
  {
    head();
    cout<<"\n";
    cout<<"\t\t MAIN MENU \n";
    cout<<"\n\t\t 1.New admission";
    cout<<"\n\t\t 2.Close a student record";
    cout<<"\n\t\t 3.Modefy a student record";
    cout<<"\n\t\t 4.Display a student record";
    cout<<"\n\t\t 5.Display all records";
    cout<<"\n\t\t 6.exit";
    cout<<"\n\n\n\n Enter your choice:";
    cin>>mch;
    switch(mch)
    {
      case 1:addrecord();
      break;
      case 2:delrecord();
      break;
      case 3:modrecord();
      break;
      case 4:disprecord();
      break;
      case 5:dispall();
      break;
    }
  }
  while(mch!=6);
}
//heading
void head()
{
  for(int i=0;i<80;i++)
  cout<<"-";
  cout<<"\n\t\t\t\t BHARATIYA VIDYA BHAVAN \n\n";
  for(int i=0;i<80;i++)
  cout<<"-";
}
//addrecords
void addrecord()
{
  account ob1,ob2;
  fstream fout;
  fout.open("schooling.dat",ios::in|ios::binary);
  if(!fout)
  {
    cout<<"File open error";
    getch();
    return;
  }
  int recsize=sizeof(account);
  fout.seekg(0,ios::end);
  fout.seekg(-1*recsize,ios::cur);
  fout.read((char*)&ob1,recsize);
  fout.close();
  head();
  cout<<"Create new record-menu\n";
  ob2.getdata();
  fout.open("schooling.dat",ios::app|ios::binary);
  if(!fout)
  {
    cout<<"File open error";
    getch();
    return;
  }
  fout.write((char*)&ob2,recsize);
  cout<<"\t\n Record added to data base";
  cout<<"\t\n Press any key to continue…";
  getch();
  fout.close();
}
//display all records
void dispall()
{
  account ob3;
  fstream fout;
  int recsize=sizeof(account);
  int countrec=0;
  head();
  cout<<"\n Display all menu \n";
  fout.open("schooling.dat",ios::in|ios::binary);
  if(!fout)
  {
    cout<<"file open error";
    getch();
    return;
  }
  while(fout.read((char*)&ob3,recsize))
  {
    ob3.disdata();
    countrec++;
    cout<<"\n\n\n Press any key for next….";
    getch();
  }
  cout<<"\n\n End of file \n total no of records..";
  cout<<countrec;
  cout<<"\n press any key….";
  getch();
  fout.close();
}
//display selected record
void disprecord()
{
  account ob4;
  fstream fout;
  int mrno,flag=0;
  int recsize=sizeof(account);
  head();
  cout<<"\n Display an account menu \n";
  fout.open("schooling.dat",ios::in|ios::binary);
  if(!fout)
  {
    cout<<"\n File open error";
    getch();
    return;
  }
  cout<<"enter the admission no";
  cin>>mrno;
  while(fout.read((char*)&ob4,recsize))
  {
    if(ob4.giveadmino()==mrno)
    {
      ob4.disdata();
      cout<<"Press any key…";
      flag=1;
      break;
    } 
    }
  if(flag==0)
  {
    cout<<"no such account exist";
    cout<<"\n Press any key..";
  }
  getch();
  fout.close();
}
//delete record
void delrecord()
{
  account ob5;
  fstream fout,temp;
  int mrno;
  int flag=0;
  int recsize=sizeof(account);
  head();
  cout<<"\n Close account menu\n";
  fout.open("schooling.dat",ios::in|ios::binary);
  if(!fout)
  {
    cout<<"\t\n File open Error..";
    getch();
    return;
  }
  temp.open("temp1.dat",ios::app|ios::binary);
  if(!temp)
  {
    cout<<"\t\n File open error";
    getch();
    return;
  }
  cout<<"\t\n Enter the admission no";
  cin>>mrno;
  while(fout.read((char*)&ob5,recsize))
  {
    if(ob5.giveadmino()==mrno)
    {
      ob5.disdata();
      char confirm;
      cout<<"\t\n Are you sure to delete (y/n)";
      cin>>confirm;
      if(confirm=='y'||confirm=='Y')
      {
        fout.read((char*)&ob5,recsize);
        cout<<"\t\n Record deleted from data base";
        cout<<"\t\n Press any key…..";
        flag=1;
        if(!fout)
        break;
      }
      flag=1;
    }
    temp.write((char*)&ob5,recsize);
  }
  fout.close();
  temp.close();
  remove("schooling.dat");
  rename("temp1.dat","schooling.dat");
  if(flag==0)
  {
    cout<<"\n no such account exist….\n";
    cout<<"\n Press any key…";
  }
  getch();
}
//modifying a record
void modrecord()
{
  account ob6,ob7;
  fstream fout;
  int mrno,flag=0;
  int recsize=sizeof(account);
  head();
  cout<<"Modefy account menu\n";
  fout.open("schooling.dat",ios::in|ios::out|ios::binary);
  if(!fout)
  {
    cout<<"File open error";
    getch();
    return;
  }
  fout.seekg(ios::beg);
  cout<<"\n Enter record no";
  cin>>mrno;
  while(fout.read((char*)&ob6,recsize))
  {
    if(ob6.giveadmino()==mrno)
    {
      head();
      cout<<"\n\t Modefy Menu\n";
      ob6.disdata();
      cout<<"\n\n\t Enter new data\n";
      ob7.getdata();
      char confirm;
      cout<<"Are you sure (y/n)";
      cin>>confirm;
      if((confirm=='y')||(confirm = 'Y'))
      {
        fout.seekg(-1*recsize,ios::cur);
        fout.write((char*)&ob7,recsize);
        cout<<"\n Record modified\n";
        cout<<"Press any key….";
        flag=1; 
      }
    }
  }
  if (flag==0)
  {cout<<"\n No such account exist..\n";
  cout<<"press any key..";}
  fout.close();
  getch();
}
