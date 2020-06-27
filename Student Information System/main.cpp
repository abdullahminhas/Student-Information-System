#include <iostream>
#include <fstream>
#include <math.h>
#include <windows.h>
#include <ctime>
#include <iomanip>
#include <limits>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

void modify_record();

using namespace std;

class bahria
{
protected:

    int rno;
    char fname[20], lname[20], mo[20], course[20], dob[25];
    int sub1;
    int sub2;
    int sub3;
    int sub4;
    int total;
    float per;

public:
    void input_details()
    {
        cout << "\n\n Enter Roll No : ";
        cin >> rno;
        cout << "\n";
        cout << "\n\n Enter First Name : ";
        cin >> fname;
        cout << "\n";
        cout << "\n\n Enter Last Name : ";
        cin >> lname;
        cout << "\n";
        cout << "\n\n Enter Course : ";
        cin >> course;
        cout << "\n";
        cout << "\n\n Enter Date Of Birth :";
        cin >> dob;
        cout << "\n";
        cout << "\n\n Enter Mobile No :";
        cin >> mo;
        cout << "\n";
        cout << "\n\n Enter Marks Of 1st subject :";
        cin >> sub1;
        cout << "\n";
        cout << "\n\n Enter Marks Of 2nd subject :";
        cin >> sub2;
        cout << "\n";
        cout << "\n\n Enter Marks Of 3rd subject :";
        cin >> sub3;
        cout << "\n";
        cout << "\n\n Enter Marks Of 4th subject :";
        cin >> sub4;
        cout << "\n";
        total = sub1 + sub2 + sub3 + sub4;
        per = total * 100 / 400;

    }
    void write_file()
    {
        ofstream fout;
        fout.open("db.txt", ios::binary | ios::app);
        bahria bs;
        bs.input_details();
        fout.write((char*)& bs, sizeof(bs));
        fout.close();


    }

    void output_details()
    {
        cout << "\n\t---------------------------------\n";
        cout << "\t Roll No | First Name | Last Name\n";
        cout << "\t" << rno << "\t   " << fname << "\t" << lname;
        cout << "\n\t---------------------------------\n";
        cout << "\n\tcourse | Date Of Birth | Mobile No.\n";
        cout << "\t" << course << "\t" << dob << "\t" << mo;
        cout << "\n\t---------------------------------\n";
    }



    void output_marksheet()
    {
        cout << "\n\t\t Marks OF 1st subject  : " << sub1;
        cout << "\n\t\t Marks OF 2nd subject   : " << sub2;
        cout << "\n\t\t Marks OF 3rd subject   : " << sub3;
        cout << "\n\t\t Marks OF 4th subject  : " << sub4;
        cout << "\n\t\t Total Marks   : " << total;
        cout << "\n\t\t Percentage    : " << per;
        if (per >= 90 && per <= 100)
        {
            cout << "\n\n\t\t Your Grade is : A+";
            cout << "\n";
        }
        else if (per >= 80 && per <= 90)
        {
            cout << "\n\n\t\t Your Grade is : A";
            cout << "\n";
        }
        else if (per >= 70 && per <= 80)
        {
            cout << "\n\t\t Your Grade is : B+";

        }
        else if (per >= 60 && per <= 70)
        {
            cout << "\n\t\t Your Grade is : B";

        }
        else if (per >= 50 && per <= 60)
        {
            cout << "\n\t\t Your Grade is : C";

        }
        else if (per >= 40 && per <= 50)
        {
            cout << "\n\t\t Your Grade is : D";

        }
        else
        {
            cout << "\n\t\t You Are Fail......";

        }
    }

    void create()
    {
        cout << "\n\n\t======================> Insert Student Information <=====================\n\n";
        input_details();
        cout << "\n\n\t======================> End Of Student Information <=====================\n\n";
    }
    void display()
    {
        cout << "\n\n\t=========================> Summary Report <============================\n\n";
        output_details();
        cout << "\n\n\t=========================> Marksheet Report <==========================\n\n";
        output_marksheet();



    }


    int retrno()
    {

        return rno;
    }

};



void wride_file()
{
    ofstream fout;
    fout.open("db.txt", ios::binary | ios::app);
    bahria bs;
    bs.input_details();
    fout.write((char*)& bs, sizeof(bs));
    fout.close();


}
void show_data()
{
    ifstream fin;
    fin.open("db.txt", ios::binary);
    bahria bs;
    while (fin.read((char*)& bs, sizeof(bs)))
    {
        bs.display();
        cout << "\n\n\t==================> End of student Report <======================\n\n";
    }
    fin.close();
}


void  search()
{
    ifstream fin;
    fin.open("db.txt");
    int rno;
    bahria bs;
    int flag = 0;

    system("cls");
    cout << "\n Enter roll number you want to search : ";
    cin >> rno;

    while (fin.read((char*)& bs, sizeof(bs)))
    {
        if (bs.retrno() == rno)
        {
            system("cls");
            cout << "\n Student Information ";
            cout << "\n--------------------------------------------------------" << endl;
            bs.output_details();
            flag = 1;
        }


    }
    fin.close();

    if (flag == 0)
        cout << "\n\n Roll No : " << rno << " does not exist please try again";

    return;

}

void modify_record()
{

    ifstream fin;
    ofstream fout;
    bahria bs;
    int rno;
    int flag = 0;
    system("cls");
    cout << "\n Enter roll number you want  :";
    cin >> rno;

    fin.open("db.txt", ios::binary);
    fout.open("temp.txt");

    while (fin.read((char*)& bs, sizeof(bs)))
    {
        if (bs.retrno() != rno)
            fout.write((char*)& bs, sizeof(bs));
        else
            flag = 1;

    }
    fin.close();
    fout.close();

    remove("db.txt");
    rename("temp.txt", "db.txt");

    if (flag == 1)
        cout << "\n\n  Sucess " << endl;
    else
        cout << "\n Roll :" << rno << " does not exist please try again";
    wride_file();


}

void  del_record()
{

    ifstream fin;
    ofstream fout;
    bahria bs;
    int rno;
    int flag = 0;
    system("cls");
    cout << "\n Enter roll number you want to delete :";
    cin >> rno;

    fin.open("db.txt", ios::binary);
    fout.open("temp.txt");

    while (fin.read((char*)& bs, sizeof(bs)))
    {
        if (bs.retrno() != rno)
            fout.write((char*)& bs, sizeof(bs));
        else
            flag = 1;

    }
    fin.close();
    fout.close();

    remove("db.txt");
    rename("temp.txt", "db.txt");

    if (flag == 1)
        cout << "\n\n Record Sucessfully removed " << endl;
    else
        cout << "\n Roll No :" << rno << " does not exist please try again";
    _getch();
    return;
}

void timer()
{

    system("color 2A");
    system("color 2F");
    char a = 177, b = 219;
    cout << "\n\t\t\t\t\t\t  Abdullah Minhas ";
    cout << "\n\n\n\t\t\t\t Loading Program....";
    cout << "\n\n\n";
    cout << "\t\t\t\t\t";

    for (int i = 0; i <= 25; i++)
        cout << a;
    Sleep(100);
    cout << "\r";
    cout << "\t\t\t\t\t ";
    for (int i = 0; i <= 25; i++)
    {
        cout << b;
        Sleep(25);


    }

    //system("pause>0");
    //    return 0;

}





class faculty:public bahria
{
protected:
    string name;
    int id;
public:
    virtual float salary() = 0;
    virtual void input()
    {
        cout << "-------" << endl;
    }
};
class permanentfaculty : public faculty
{
private:
    int yearservice;
    int basicpay;
public:
    void setyearservice(int y)
    {
        yearservice = y;
    }
    void setbasicpay(int b)
    {
        basicpay = b;
    }
    void input()
    {
        setyearservice(4);
        setbasicpay(20000);
    }
    float salary()
    {
        float mediclallwnce;
        mediclallwnce = 0.10 * basicpay;
        float houserent;
        houserent = 0.25*basicpay;
        float sal = mediclallwnce + houserent + basicpay;
        cout << "Permanent Faculty Salary" << endl;
        return sal;
    }
};
class vistingfaculty : public faculty
{
private:
    int prhrrate;
    int nofhrtaught;
public:
    void setprhrrate(int p)
    {
        prhrrate = p;
    }
    void setnofhrtaught(int n)
    {
        nofhrtaught = n;
    }
    void input()
    {
        setnofhrtaught(25);
        setprhrrate(1200);
    }
    float salary()
    {
        cout << "Visiting_Faculty Salary" << endl;
        float sal = prhrrate*nofhrtaught;
        return sal;
    }

};
    

    int main()
    {
        faculty *f1[10];
        


        timer();
        system("color f2");
        int i;
        bahria bs;
        while (1)
        {
            system("cls");
            cout << "\n\n\t ******** Student      Information      System **********\n\n";
            cout << "\n\n\t ******** Choose Operation You Want To Perform **********\n\n";
            cout << "\n\n\t          1)          Create  Record";
            cout << "\n\n\t          2)          Display Record";
            cout << "\n\n\t          3)          Search  Record";
            cout << "\n\n\t          4)          Modify  Record ";
            cout << "\n\n\t          5)          Delete  Record";
            cout << "\n\n\t          6)          faculty  Record";
            cout << "\n\n\t          7)          Exit    Program";
            cout << endl;
            cout << "\n\n   Enter your choice : ";

            int ch;

            cin >> ch;
            switch (ch)
            {
            case 1:
                system("cls");
                wride_file();
                break;

            case 2:
                system("cls");
                show_data();
                cout << endl;
                system("pause");
                break;

            case 3:
                system("cls");
                search();
                cout << endl;
                system("pause");
                break;

            case 4:
                system("cls");
                modify_record();
                cout << endl;
                system("pause");
                break;

            case 5:
                system("cls");
                del_record();
                cout << endl;
                system("pause");
                break;

            case 6:
                {
                for (int a = 0; a < 10; a++)
            {
                cout << ":::::";
                f1[a] = new permanentfaculty;
                f1[a]->input();
                cout << f1[a]->salary() << endl;
                f1[a] = new vistingfaculty;
                f1[a]->input();
                cout << f1[a]->salary() << endl;
                system("pause");
            }
                }
                break;
            case 7:
                goto out;
                break;
            default:
                cout << "\n\n\t========> Invalid choice <========";
                cout << endl;
                system("pause");
                break;
            }
        }
    out:
        system("cls");
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "\n\n\t\t\t ******** Student      Information      System **********\n\n";
        cout << "\n\n\t\t\t                             by                            \n\n";
        cout << "\n\t\t\t==============> Abdullah Sajjad Saeed minhas <=================\n";
        cout << endl;
        cout << endl;
        system("pause");
        return 0;
    }
