#include "pch.h"
#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<fstream>

using namespace std;
class IT2
{
private:
	char name[10];
	int vtu;
	int noofc;
	char login[10];
	char pass[10];
	float marks=0.00;
public:
	void get()
	{
		char ch;
		cout<< "enter name" << endl;
		cin >> name;

		cout << "enter vtu number" << endl;
		cin >> vtu;
	label:
		cout << "enter number of credits" << endl;
		cin >> noofc;
		if (noofc < 18 || noofc>28)
		{
			cout << "Incorrect number of credits" << endl;
			goto label;
		}
		cout << "Add marks?" << endl;
		cout << "Answer in Y or N" << endl;
		cin >> ch;
		if (ch == 'y' || ch == 'Y')
		{
			mark();
		}
		else if (ch == 'N' || ch == 'n')
		{
			return;
		}

	}
	void disp()
	{

		cout << "name:" << name << endl;
		cout << "vtu number:" << vtu << endl;
		cout << "number of credits:" << noofc << endl;
		if (marks>0 && marks<1000)
			cout << "marks:" << marks << endl;
		else
		cout << "No Marks Stored"<<endl ;
		

	}
	int getvtu()
	{
		return vtu;
	}
	int getnoofc()
	{
		return noofc;
	}
	void duplicate(int arr[], int size)
	{
		int i, j;

		for (i = 0; i < size; i++)
			for (j = i + 1; j < size; j++)
				if (arr[i] == arr[j])
				{
					cout << "Repeat vtu numbers " << arr[i] << endl;

				}
				else if (arr[i] != arr[j])
				{
					goto label1;


				}
	label1:
		cout << "No duplicates found" << endl;
		system("PAUSE");
		system("CLS");

	}
	void mark()
	{

		system("CLS");
		int grade[100], credit[100], sub[100], i, nos, sum = 0.0, totcred = 0.0;
		cout << "|________________________________________________|" << endl;
		cout << "|                  1.ENTER MARKS                 |" << endl;
		cout << "|                  2.CALCULATE MARKS             |" << endl;
		cout << "|________________________________________________|" << endl;
		cin >> i;
		switch (i)
		{
		case 1:cout << "enter marks";
			cin >> marks;
			break;
		case 2:
			float gpa = 0.0;
			char ch;
			cout << "Enter number of subjects" << endl;
			cin >> nos;
			cout << "Enter grades and Credits in caps respectively" << endl;
			for (i = 0.0;i < nos;i++)
			{
			label:
				cin >> ch;
				if (ch == 'S')
					grade[i] = 10.0;
				else if (ch == 'A')
					grade[i] = 9.0;
				else if (ch == 'B')
					grade[i] = 8.0;
				else if (ch == 'C')
					grade[i] = 7.0;
				else if (ch == 'D')
					grade[i] = 6.0;
				else if (ch != 'S' || ch != 'A' || ch != 'B' || ch != 'C' || ch != 'D')
				{
					cout << "Wrong Grade Entered" << endl;
					cout << "Enter again" << endl;
					goto label;
				}
				cin >> credit[i];

			}
			for (i = 0;i < nos;i++)
			{
				sub[i] = grade[i] * credit[i];
			}
			for (i = 0;i < nos;i++)
			{
				sum += sub[i];
				totcred += credit[i];

			}
			cout << sum << endl;
			cout << totcred << endl;
			gpa=float(sum) / totcred;
			cout << "Grade point Average is" << gpa << endl;
			break;

		}
	}
	void dispmark()
	{
		cout << marks;
	}
};
int main()
{    
		IT2 obj[10], l;
	int j;
	IT2 temp;
	system("CLS");
	char ans;
	char login[] = { "admin" };
	char password[] = { "veltech" };
	char getl[10], passw[10];
label:
	cout << "enter login id" << endl;
	gets_s(getl);
	if (strcmp(getl, login) == 0)
	{
		cout<< "valid" << endl;
		cout << "Enter password" << endl;
		gets_s(passw);
		if (strcmp(passw, password) == 0)
		{
			cout << "valid" << endl;
		}
		else {
			cout << "invalid" << endl;
			system("CLS");
			goto label;

		}
	}
	else
	{
		cout << "invalid" << endl;
		goto label;
	}
	system("CLS");
	system("PAUSE");
	int ch, getv, i, nos;
	cout << "-------------------RECORD OF STUDENTS----------------" << endl;
	cout << "enter number of students" << endl;
	cin >> nos;
	for (i = 0;i < nos;i++)
	{
		cout << "Enter details of student:" << endl;
		obj[i].get();
	}
	system("CLS");
	int arr[100];
	for (i = 0;i < nos;i++)                      //for storing values in array for finding duplicate
	{
		arr[i] = obj[i].getvtu();
	}
	l.duplicate(arr, nos);                      //calling duplicate function
	system("PAUSE");

	do {
		system("CLS");
		cout << "|---------------------------------------------------------------|" << endl;
		cout << "|                 MAIN MENU                                     |" << endl;
		cout << "|                 1.Specific student                            |" << endl;
		cout << "|                 2.All students                                |" << endl;
		cout << "|                 3.Order of vtu                                |" << endl;
		cout << "|                 4.Order of credits                            |" << endl;
		cout << "|                 5.Marks                                       |" << endl;
		cout << "|---------------------------------------------------------------|" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:cout << "Enter vtu number" << endl;
			cin >> getv;
			for (i = 0;i < nos;i++)
			{
				if (obj[i].getvtu() == getv)
				{
					obj[i].disp();
					break;
				}
			}if (i == nos)
				cout << "invalid vtu number" << endl;
			break;
		case 2:for (i = 0;i < nos;i++)
		{
			obj[i].disp();

		}
			   break;

		case 3:
			for (i = 0;i < nos;i++)
			{
				for (j = 0;j < (nos - i);j++)
					if (obj[j].getvtu() > obj[j + 1].getvtu())
					{
						temp = obj[j];
						obj[j] = obj[j + 1];
						obj[j + 1] = temp;
					}
			}
			for (i = 1;i <= nos;i++)
				obj[i].disp();

			break;
		case 4:for (i = 0;i < nos;i++)
		{
			for (j = 0;j < (nos - i);j++)
				if (obj[j].getnoofc() > obj[j + 1].getnoofc())
				{
					temp = obj[j];
					obj[j] = obj[j + 1];
					obj[j + 1] = temp;
				}
		}
			   for (i = 1;i <= nos;i++)
				   obj[i].disp();
			   break;
		case 5:system("CLS");
			cout << "enter vtu number" << endl;
			cin >> getv;
			for (i = 0;i < nos;i++)
			{
				if (obj[i].getvtu() == getv)
				{
					obj[i].dispmark();
				}
			}
			break;
		}
		cout << "Want to run once again?" << endl;
		cout << "Answer in Y or N" << endl;
		cin >> ans;
	} while (ans == 'y' || ans == 'Y');
}
