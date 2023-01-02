#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;

typedef struct student
{
    int roll;
    char a,name[20],add[30];
}stud;
void create();
void display();
void insert();
void search(int key);
void delete1(int key);
void modify(int key);

int main()
{int ch,x;
    do
    {
        cout<<"\n\t***MENU***\n1.Accept\n2.Display\n3.Insert\n4.Search\n5.Delete\n6.Modify\n7.Exit\nEnter your choice=";
        cin>>ch;
        switch(ch)
        {
            case 1:create();
                break;
            case 2:display();
                break;
            case 3:insert();
                break;
            case 4: cout<<"Enter roll no to search=";
                cin>>x;
                search(x);
                break;
            case 5:cout<<"Enter roll no to delete=";
                cin>>x;
                delete1(x);
                break;
            case 6:cout<<"Enter roll no to modify=";
                cin>>x;
                modify(x);
                break;
        }

    }while(ch!=7);

    return 0;
}


ifstream fin;
ofstream fout;
fstream fm;
int n;
char fname[20];


void create()
{int i;
    stud s;
    cout<<"Enter name of the file=";
    cin>>fname;
    fm.open(fname,ios::out);

    cout<<"\nEnter no. of records:=";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"Enter roll no=";
        cin>>s.roll;
        cout<<"Enter name=";
        cin>>s.name;
        cout<<"Enter division=";
        cin>>s.a;
        cout<<"Enter address=";
        cin>>s.add;
        fm.write((char*)&s,sizeof(s));

    }

    fm.close();
}//create

void display()
{int i;
    stud s;
    fin.open(fname);
    cout<<"\nROLL NO\tNAME\tDIV\tADDRESS";
    //	while(!fin.eof())
    for(i=0;i<n;i++)
    {
        fin.read((char*)&s,sizeof(s));
        cout<<"\n"<<s.roll<<"\t"<<s.name<<"\t"<<s.a<<"\t"<<s.add;
    }
    fin.close();
}//display

void insert()
{stud s;
    fout.open(fname,ios::app);
    cout<<"Enter roll no=";
    cin>>s.roll;
    cout<<"Enter name=";
    cin>>s.name;
    cout<<"Enter division=";
    cin>>s.a;
    cout<<"Enter address=";
    cin>>s.add;
    fout.write((char*)&s,sizeof(s));
    n++;
    fout.close();
}

void search(int key)
{  stud s;
    int flag=0,i;

    fin.open(fname);

    for(i=0;i<n;i++)
    {
        fin.read((char *)&s,sizeof(s));
        if(s.roll==key)
        {
            cout<<"\nRecord is present their corresponding details are:\nRoll no=";
            cout<<s.roll<<"\nName="<<s.name<<"\nDivision="<<s.a<<"\nAddress="<<s.add;
            flag=1;
        }
    }
    if(flag==0)
        cout<<"\nRoll no.= "<<key<<" is not present in the record";

    fin.close();
}


void delete1(int key)
{  stud s;
    int flag=0,i;

    fin.open(fname);
    fout.open("temp.txt",ios::out);

    for(i=0;i<n;i++)
    {
        fin.read((char *)&s,sizeof(s));
        if(s.roll==key)
        {   cout<<"\nRecord deleted successfully";
            flag=1;
        }
        else
        {
            fout.write((char *)&s,sizeof(s));
        }
    }
    if(flag==0)
        cout<<"\nRoll no.= "<<key<<" is not present in the record";
    else
        n--;

    fin.close();
    fout.close();

    remove(fname);
    rename("temp.txt",fname);
}

void modify(int key)
{  stud s;
    int flag=0,i;

    fin.open(fname);
    fout.open("temp.txt",ios::out);

    for(i=0;i<n;i++)
    {
        fin.read((char *)&s,sizeof(s));
        if(s.roll==key)
        {
            cout<<"Enter roll no=";
            cin>>s.roll;
            cout<<"Enter name=";
            cin>>s.name;
            cout<<"Enter division=";
            cin>>s.a;
            cout<<"Enter address=";
            cin>>s.add;
            fout.write((char*)&s,sizeof(s));

            flag=1;
        }
        else
        {
            fout.write((char *)&s,sizeof(s));

        }
    }
    if(flag==0)
        cout<<"\nRoll no.= "<<key<<" is not present in the record";

    fin.close();
    fout.close();

    remove(fname);
    rename("temp.txt",fname);
}

/*    ************* OUTPUT  *****************
"C:\Users\hp\CLionProjects\DSA SIB32\cmake-build-debug\DSA_SIB32.exe"

        ***MENU***
1.Accept
2.Display
3.Insert
4.Search
5.Delete
6.Modify
7.Exit
Enter your choice=1
Enter name of the file=Records

Enter no. of records:=3
Enter roll no=32
Enter name=Krishna
Enter division=B
Enter address=Latur
Enter roll no=34
Enter name=Shyam
Enter division=B
Ente
r address=Mumbai
Enter roll no=39
Enter name=Ram
Enter division=B
Enter address=Dubai

        ***MENU***
1.Accept
2.Display
3.Insert
4.Search
5.Delete
6.Modify
7.Exit
Enter your choice=2

ROLL NO NAME    DIV     ADDRESS
32      Krishna B       Latur
34      Shyam   B       Mumbai
39      Ram     B       Dubai
        ***MENU***
1.Accept
2.Display
3.Insert
4.Search
5.Delete
6.Modify
7.Exit
Enter your choice=4
Enter roll no to search=32

Record is present their corresponding details are:
Roll no=32
Name=Krishna
Division=B
Address=Latur
        ***MENU***
1.Accept
2.Display
3.Insert
4.Search
5.Delete
6.Modify
7.Exit
Enter your choice=5
Enter roll no to delete=39

Record deleted successfully
        ***MENU***
1.Accept
2.Display
3.Insert
4.Search
5.Delete
6.Modify
7.Exit
Enter your choice=2

ROLL NO NAME    DIV     ADDRESS
32      Krishna B       Latur
34      Shyam   B       Mumbai
        ***MENU***
1.Accept
2.Display
3.Insert
4.Search
5.Delete
6.Modify
7.Exit
Enter your choice=7

Process finished with exit code 0
*/