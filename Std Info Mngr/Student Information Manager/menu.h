#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include<bits/stdc++.h>
#include<windows.h>
#include<ctime>
#include"files.h"

using namespace std;

/**Globals**/
string semester,year,section,roll;


/**functions**/
void menu(bool o);
void view_results(bool o);
void edit_results(bool o);
void print();
void exit_module();
void error_msg();
void cse_module(bool m);
void bba_module(bool m);
void hsc_module(bool m);
void selection();
void individual_result();
void individual_result(char c);
void group_result();
void group_result(char c);
void select_semester(bool m);
void select_year(bool m);
void select_section(bool m);
void select_roll(bool m);

void group_result()
{
    select_semester(true);
    select_section(true);
}

void group_result(char c)
{
    select_year(true);
    select_section(true);
}

void select_section(bool m)
{
    vector <string> sec_names;
    sec_names.push_back("secA");
    sec_names.push_back("secB");
    sec_names.push_back("secC");

    system("cls");
    print();
    if(m)
        error_msg();
    else
        selection();

    cout<<"1. Section A\n";
    cout<<"2. Section B\n";
    cout<<"3. Section C\n";
    cout<<"0. Back\n";

    string x;
    getline(cin,x);

    if(x=="1"||x=="2"||x=="3")
    {
        int o=x[0]-'0';
        section=sec_names[o-1];
    }
    else if(x=="0")
    {
        select_semester(false);
    }
    else
    {
        select_section(true);
    }
}

void select_roll(bool m)
{
    system("cls");
    print();
    if(m)
        error_msg();
    else
        selection();

    cout<<"Please enter roll or enter 0 to go back\n";
    string x;
    getline(cin,x);

    if(x=="0")
    {
        select_section(false);
    }
    else
    {
        roll=x;
    }

}

void select_semester(bool m)
{
    vector <string> sem_names;
    sem_names.push_back("sem1");
    sem_names.push_back("sem2");
    sem_names.push_back("sem3");
    sem_names.push_back("sem4");
    sem_names.push_back("sem5");
    sem_names.push_back("sem6");
    sem_names.push_back("sem7");
    sem_names.push_back("sem8");

    system("cls");
    print();
    if(m)
        error_msg();
    else
    selection();

    cout<<"1. 1st semester.\n";
    cout<<"2. 2nd semester.\n";
    cout<<"3. 3rd semester.\n";
    cout<<"4. 4th semester.\n";
    cout<<"5. 5th semester.\n";
    cout<<"6. 6th semester.\n";
    cout<<"7. 7th semester.\n";
    cout<<"8. 8th semester.\n";
    cout<<"0. Back.\n";
    string x;
    getline(cin,x);
    if(x=="1" || x=="2" || x=="3" || x=="4" || x=="5" || x=="6" || x=="7" || x=="8")
    {
        int o=x[0]-'0';
        semester=sem_names[o-1];
    }
    else if(x=="0")
    {
        cse_module(false);
    }
    else
    {
        select_semester(true);
    }

}

void select_year(bool m)
{
    vector<string> year_names;
    year_names.push_back("year1");
    year_names.push_back("year2");

    system("cls");
    print();
    if(m)
        error_msg();
    else
    selection();

    cout<<"1. First Year.\n";
    cout<<"2. Second Year.\n";
    cout<<"0.Back\n";

    string x;

    getline(cin,x);

    if(x=="1" || x=="2")
    {
        int o=x[0]-'0';
        year=year_names[o-1];
    }
    else if(x=="0")
    {
        hsc_module(false);

    }
    else
    {
        select_year(true);
    }
}

void individual_result()
{
    select_semester(false);
    select_section(false);
    select_roll(false);
}

void individual_result(char h)
{
    select_year(false);
    select_section(false);
    select_roll(false);
}

void selection()
{
    cout<<"Please select from the following menu.\n"<<endl;
}

void cse_module(bool m)
{
    system("cls");
    print();

    if(m)
        error_msg();
    else
        selection();

    cout<<"1.Individual Result\n";
    cout<<"2.Group result\n";
    cout<<"3.Back\n";

    string x;

    getline(cin,x);

    if(x=="1")
    {
        individual_result();
    }
    else if(x=="2")
    {
        group_result();
    }
    else if(x=="3")
    {
        view_results(false);
    }
    else
    {
        cse_module(true);
    }

}

void bba_module(bool m)
{
    system("cls");
    print();

    if(m)
        error_msg();
    else
        selection();

    cout<<"1.Individual Result\n";
    cout<<"2.Group result\n";
    cout<<"3.Back\n";

    string x;

    getline(cin,x);

    if(x=="1")
    {
        individual_result();
    }
    else if(x=="2")
    {
        group_result();
    }
    else if(x=="3")
    {
        view_results(false);
    }
    else
    {
        bba_module(true);
    }

}

void hsc_module(bool m)
{
    system("cls");
    print();

    if(m)
        error_msg();
    else
        selection();

    cout<<"1.Individual Result\n";
    cout<<"2.Group result\n";
    cout<<"3.Back\n";

    string x;

    getline(cin,x);

    if(x=="1")
    {
        individual_result('h');
    }
    else if(x=="2")
    {
        group_result('h');
    }
    else if(x=="3")
    {
        view_results(false);
    }
    else
    {
        hsc_module(true);
    }

}


void error_msg()
{
    cout<<"Invalid Choice! Please Select Again.\n\n";
}

void exit_module()
{
    string  s;
    cout<<"Are you sure you want to proceed? (y/n)\n";
    getline(cin,s);
    //getchar();
    if(s=="y")
    {
        system("cls");
        cout<<"Good Bye....\n";
        Sleep(1000);
    }
    else if(s=="n")
    {
        menu(false);
    }
    else
    {
        exit_module();
    }
}


void view_results(bool o)
{
    system("cls");
    print();
    if(o)
        error_msg();
    else
        selection();
    cout<<"1.View CSE result\n";
    cout<<"2.View BBA result\n";
    cout<<"3.View HSC result\n";
    cout<<"4.Back\n";
    string x;

    getline(cin,x);

    if(x=="1")
    {
        cse_module(false);
        string file_name;
        file_name="data\\CSE\\"+semester+"\\"+section+"\\"+roll+".txt";
        //cout<<file_name<<endl;
        view_individual_result(file_name);
    }
    else if(x=="2")
    {
        bba_module(false);
        cout<<semester<<endl<<section<<endl<<roll<<endl;
    }
    else if(x=="3")
    {
        hsc_module(true);
        cout<<year<<endl<<section<<endl<<roll<<endl;
    }
    else if(x=="4")
    {
        menu(false);
    }
    else
    {
        cout<<"Invalid Choice\n";
        view_results(true);
    }

}

void edit_results(bool o)
{
    system("cls");
    print();
    if(o)
        error_msg();
    else
        selection();
    cout<<"1.Edit CSE result\n";
    cout<<"2.Edit BBA result\n";
    cout<<"3.Edit HSC result\n";
    cout<<"4.Back\n";
    string x;

    getline(cin,x);

    if(x=="1")
    {
        cse_module(false);
        cout<<semester<<endl<<section<<endl<<roll<<endl;
    }
    else if(x=="2")
    {
        bba_module(false);
        cout<<semester<<endl<<section<<endl<<roll<<endl;
    }
    else if(x=="3")
    {
        hsc_module(false);
        cout<<year<<endl<<section<<endl<<roll<<endl;
    }
    else if(x=="4")
    {
        menu(false);
    }
    else
    {
        cout<<"Invalid Choice\n";
        edit_results(true);
    }

}

void print()
{
    time_t now = time(0);
    char* dt = ctime(&now);
    system("cls");
    cout<<"========================================================================================================================\n";
    cout<<"******************************************** STUDENT INFORMATION MANAGEMENT ********************************************\n";
    cout<<"========================================================================================================================\n";
    cout<<dt;
    cout<<"========================================================================================================================\n";
}

void menu(bool o)
{
    print();
    if(0)
        error_msg();
    else
        selection();
    cout<<"1.View Results(1).\n2.Enter results.(2).\n3.Exit.(3)"<<endl;
    string x;
    getline(cin,x);

    if(x=="1")
        view_results(false);
    else if(x=="2")
    {
        edit_results(false);
    }
    else if(x=="3")
    {
        system("cls");
        exit_module();
    }
    else
    {
        menu(true);
    }

}


#endif // FUNCTIONS_H_INCLUDED
