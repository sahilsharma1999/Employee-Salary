

#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;
class employee
{
public:
    int empid;
    char name[50];
    char post[50];
private:
    char lastname[50];
    float salary;
public:
    void accept()
    {
        cout<<endl<<"enter employee id";
        cin>>empid;
        cout<<endl<<"enter name of employee";
        cin>>name;
        cout<<endl<<"enter last name";
        cin>>lastname;
        cout<<endl<<"enter salary";
        cin>>salary;
        cout<<endl<<"enter post";
        cin>>post;
    }
    void display()
    {
     cout<<endl<<"employee id:"<<empid;
     cout<<endl<<"employee name:"<<name;
     cout<<endl<<"employee last name:"<<lastname;
     cout<<endl<<"salary:"<<salary;
     cout<<endl<<"post:"<<post;
    }

    //void display()
    //{
      //  cout<<endl<<"employee id\temployee name\tlast name\tsalary\tpost";
        //cout<<endl<<"******************************************************************";
        //cout<<endl<<empid<<"\t\t ";
        //cout<<name<<"\t\t ";
        //cout<<lastname;
        //cout<<salary<<"\t ";
        //cout<<post<<"\t\t ";
   // }
};
employee obj;

class salary
{
private:
    int empid;
    float salary_given;
public:
    char month[50];
    char year[4];
void accept()
{
cout<<endl<<"enter employee id :";
cin>>empid;

fstream rd;
rd.open("E:\\salaryproject\\employeedata.txt",ios::in);

rd.seekg(0,ios::end);
int n=rd.tellg();
n=n/sizeof(obj);
rd.seekg(0,ios::beg);
for (int i=1;i<=n;i++)
{
    rd.read((char*)&obj,sizeof(obj));
    if(empid==obj.empid)
    {
        obj.display();
    }
}


cout<<endl<<"enter salary to be dispensed :";
cin>>salary_given;
cout<<endl<<"enter month";
cin>>month;
cout<<endl<<"enter year";
cin>>year;
}

int digit(int n)
{
    int count=0;
    while(n!=0)
    {
        n=n/10;
        count++;
    }
    return count;
}
void display()
{
    cout<<endl<<empid<<"\t\t  ";
    cout<<salary_given;
    int p=digit(salary_given);
for(int i=1;i<=(11-p);i++)
{
    cout<<" ";
}

cout<<"\t"<<month<<"\t"<<year;

}

};
salary salobj;


void addemployee()
{
    obj.accept();

    fstream wr;
    wr.open("E:\\salaryproject\\employeedata.txt",ios::app);
    wr.write((char*)&obj,sizeof(obj));
    cout<<endl<<"data written to file";

}

void showallemployee()
{
    fstream rd;
    rd.open("E:\\salaryproject\\employeedata.txt",ios::in);

    rd.seekg(0,ios::end);
    int n=rd.tellg();
    n=n/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int i=1;i<=n;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        obj.display();
        cout<<endl<<"******************************************************************"<<endl;

    }

}
void searchbyempid()
{
    fstream rd;
    rd.open("E:\\salaryproject\\employeedata.txt",ios::in);

    int sr;
    cout<<"enter employee id to be searched";
    cin>>sr;

    rd.seekg(0,ios::end);
    int n=rd.tellg();
    n=n/sizeof(obj);
    rd.seekg(0,ios::beg);
for(int i=1;i<=n;i++)
{
    rd.read((char*)&obj,sizeof(obj));
    if(obj.empid==sr)
    {
        obj.display();
        cout<<endl<<"********************"<<endl;
    }
}
}

void removeemployee()
{
    fstream rd,wr;
    rd.open("E:\\salaryproject\\employeedata.txt",ios::in);
    wr.open("E:\\salaryproject\\temp.txt",ios::out);

    int sr;
    cout<<endl<<"enter employee id to be removed";
    cin>>sr;

    rd.seekg(0,ios::end);
    int n=rd.tellg();
    n=n/sizeof(obj);

    rd.seekg(0,ios::beg);
    for(int i=1;i<=n;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(obj.empid==sr)
        {
            cout<<endl<<"employee removed"<<endl;
        }
        else
        {
            wr.write((char*)&obj,sizeof(obj));
        }
    }
    rd.close();
    wr.close();
    remove("E:\\salaryproject\\employeedata.txt");
    rename("E:\\salaryproject\\temp.txt","E:\\salaryproject\\employeedata.txt");
}

void updateemployee()
{
    fstream rd,wr;
    rd.open("E:\\salaryproject\\employeedata.txt",ios::in);
    wr.open("E:\\salaryproject\\temp.txt",ios::out);

    int sr;
    cout<<endl<<"enter employee id to be updated";
    cin>>sr;

    rd.seekg(0,ios::end);
    int n=rd.tellg();
    n=n/sizeof(obj);

    rd.seekg(0,ios::beg);
    for(int i=1;i<=n;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(obj.empid==sr)
        {
            obj.accept();
            wr.write((char*)&obj,sizeof(obj));
        }
        else
        {
            wr.write((char*)&obj,sizeof(obj));
        }
    }
    rd.close();
    wr.close();
    remove("E:\\salaryproject\\employeedata.txt");
    rename("E:\\salaryproject\\temp.txt","E:\\salaryproject\\employeedata.txt");
}
void dispensesalary()
{
    salobj.accept();
    fstream wr;
    wr.open("E:\\salaryproject\\salary.txt",ios::app);
    wr.write((char*)&salobj,sizeof(salobj));
    cout<<endl<<"salary recorded";
}
void searchsalary()
{
    fstream rd;
    rd.open("E:\\salaryproject\\salary.txt",ios::in);
    char m[50],y[50];
    cout<<endl<<"enter month";
    cin>>m;
    cout<<endl<<"enter year";
    cin>>y;
    cout<<endl<<"employee id\tgiven salary\tmonth\tyear";
    cout<<endl<<"********************************************";
    rd.seekg(0,ios::end);
    int n=rd.tellg()/sizeof(salobj);
    rd.seekg(0,ios::beg);

    for(int i=1;i<=n;i++)
    {
    rd.read((char *)&salobj,sizeof(salobj));
    if(strcmp(salobj.month,m)==0 && strcmp(salobj.year,y)==0)
    {
    salobj.display();
    }
    }
}
void searchbyname()
{
    fstream rd;
    rd.open("E:\\salaryproject\\employeedata.txt",ios::in);
    char sr[10];
    cout<<"enter employee first name to be searched : ";
    cin>>sr;
    rd.seekg(0,ios::end);
    int n=rd.tellg();
    n=n/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int i=1;i<=n;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(strcmp(obj.name,sr)==0)
        {
            obj.display();
            cout<<endl<<"*********************"<<endl;
        }
    }



}
void searchbypost()
{
    fstream rd;
    rd.open("E:\\salaryproject\\employeedata.txt",ios::in);
    char sr[10];
    cout<<endl<<"enter post to be searched"<<endl;
    cin>>sr;
    rd.seekg(0,ios::end);
    int n=rd.tellg();
    n=n/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int i=1;i<=n;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(strcmp(obj.post,sr)==0)
        {
            obj.display();
            cout<<endl<<"***********************"<<endl;
        }
    }
}
void menu()
{
    int n;
cout<<endl<<"\t\t\t\t\t***********************************";
cout<<endl<<"\t\t\t\t\t***********************************";
cout<<endl<<"\t\t\t\t\t*** add employee: \t      1 ***";
cout<<endl<<"\t\t\t\t\t*** list of all employees:    2 ***";
cout<<endl<<"\t\t\t\t\t*** search employee by empid: 3 ***";
cout<<endl<<"\t\t\t\t\t*** remove employee: \t      4 ***";
cout<<endl<<"\t\t\t\t\t*** update employee: \t      5 ***";
cout<<endl<<"\t\t\t\t\t*** dispense salary: \t      6 ***";
cout<<endl<<"\t\t\t\t\t*** search salary: \t      7 ***";
cout<<endl<<"\t\t\t\t\t*** search by name: \t      8 ***";
cout<<endl<<"\t\t\t\t\t*** search by post: \t      9 ***";
cout<<endl<<"\t\t\t\t\t*** To exit: \t\t      0 ***";
cout<<endl<<"\t\t\t\t\t***********************************";
cout<<endl<<"\t\t\t\t\t***********************************"<<endl;
cin>>n;
if (n>0)
   {
       switch(n)
       {
       case 1:
        {
            addemployee();
            menu();
            break;
        }
       case 2:
        {
            showallemployee();
            menu();
            break;
        }
       case 3:
        {
            searchbyempid();
            menu();
            break;
        }
       case 4:
        {
            removeemployee();
            menu();
            break;
        }
       case 5:
        {
            updateemployee();
            menu();
            break;
        }
       case 6:
        {
            dispensesalary();
            menu();
            break;
        }
       case 7:
        {
            searchsalary();
            menu();
            break;
        }
       case 8:
        {
            searchbyname();
            menu();
            break;

        }
       case 9:
        {
            searchbypost();
            menu();
            break;

        }

       }
   }
   else if(n>0)
   {

   }
   else if(n==0)
   {
       cout<<endl<<"enter to exit";

   }
}

main()
{
 menu();
}

