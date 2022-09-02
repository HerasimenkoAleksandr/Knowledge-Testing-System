#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdio.h>
#include "Header.h"
#include <vector>
using namespace std;

class ListOFPeople : public IRegistration
{
	vector <student> Init;
public:
	void Add(student& obj)
	{
		Init.push_back(obj);
	
	}
	void ShowStudent()
	{
		vector <student>  ::iterator iter = Init.begin();
		for (; iter != Init.end(); iter++)
		{
			iter->Show();
			}
	}
	bool HaveLogin(const string& login)
	{
		vector <student>  ::iterator iter = Init.begin();
		for (; iter != Init.end(); iter++)
		{
			if (login == iter->GetLgin())
			{
				return true;
			}

		}
		return false;
	}
	bool HavePassword(const string& password)
	{
		vector <student>  ::iterator iter = Init.begin();
		for (; iter != Init.end(); iter++)
		{
			if (password == iter->GetPassword())
			{
				return true;
			}

		}
		return false;
	}
	void Logo()
	{
		system("cls");
		cout << "                  ___________________________" << endl;
		cout << "                 ^ Knolwlege Testing Systeam ^                      " << endl;
		cout << "                 ^___________________________^" << endl << endl;
	}
	void Enter()
	{
		Logo();
		ReadFile();
		cout << "Enter -1- if you have an acount" << endl;
		cout <<"Enter -2- if you want to create an acount" << endl;
		//system("cls");
		int b;
		cin >> b;
		system("cls");
		switch (b)
		{
		case(1):
		{
			int a=IEnterToApp();
			if (a > 3)
				system("cls");
			{
				Enter();
			}
			break;
		}
		case(2):
		{
			ICreatAcount();
			break;
		}
		default:
		{
			Enter();
		}
		}

			

	}
	int IEnterToApp()
	{
		Logo();
		string a;
		string b;
		cout << "<<<<<<<<<<<<<<<<<<<<<<  HELLO STUDENT  >>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl; 
		cout << "                 Enter your username to login" << endl;
		cout << "_______: " ;
		cin >>a;
		cout << "                Enter your username to Password" << endl;
		cout << "_______: " ;
		cin >> b;
		int t = 0;
		while (!HaveLogin(a)||!HavePassword(b))
		{
			if (t > 3)
				break;
			system("cls");
			//cout << "LOGIN --> " << a << endl;
			cout << "Login or password entered incorrectly. REPEAT!!! " << endl;
			cout << "   Enter your username to login" << endl;
			cin >> a;
			cout << "   Enter your username to Password" << endl;
			cin >> b;
			t++;
		}
		return t;

	}
	void ICreatAcount()
	{
				student temp;
			temp.SetStudent();
			cout << endl << endl;
		 while (HaveLogin(temp.GetLgin()))
		 {
			 system("cls");
		     cout << "LOGIN --> " << temp.GetLgin() << endl;
			 cout << "THIS LOGIN IS BEING USED. You need to enter another login! " << endl;
			 temp.SetLgin();
			
		 }
		 cout << endl;
		temp.Show();
		int b;
		cout << endl;
		cout << "If everything is correct, press 5 to create an account!!!" << endl;
		cin >> b;
		if (b == 5)
		{
			Init.push_back(temp);
			WriteFile();
			system("cls");
			cout << "Congratulations! YOU HAVE ACCOUNT!!!" << endl;
		}
		else
		{
			ICreatAcount();
		}
	}
	
	void WriteFile()
	{
		string a("DataPeople.txt");
		fstream fs;
		fs.open(a,  fstream::out);
		if (!fs.is_open())
		{
			cout << "Error open file" << endl; //Error open file
		}
		vector <student>  ::iterator iter = Init.begin();
		for (; iter != Init.end(); iter++)
		{
			//fstream fs;
			fs << iter->GetName() << "\n";
			fs << iter->GetSurname() << "\n";
			fs << iter->GetLgin() << "\n";
			fs << iter->GetPassword() << "\n";
			fs << iter->GetAddress() << "\n";
			fs << iter->GetPhone_number() << "\n";
			fs << iter->GetID() << "\n";

		}
		fs.close();
	}
	void ReadFile()
	{
		string a("DataPeople.txt");
		fstream fs;
		fs.open(a, fstream::in );
		if (!fs.is_open())
		{
			cout << "Your account will be the first" << endl; //Error open file
		}
		else
		{
			//student temp;
			string name;
			string surname;
			string Password;
			string login;
			string address;
			string phone_nomber;
			int ID;
			int b = 0;
			while (!fs.eof())
			{
			
				fs >> name;
				fs >> surname;
				fs >> login;
				fs >> Password;
				fs >> address;
				fs >> phone_nomber;
				fs >> ID;
				ID = 100;
				student temp(name, surname, login, Password, ID, address, phone_nomber);
				Init.push_back(temp);
				//b++;
			}

			Init.pop_back();
			fs.close();
		}
	}

};
 


int main()
{
	//student temp(name, surname, Password, login, ID, address, phone_nomber);
	//Init.push_back( student r("Ivan", "Bobrov", "email", "33333", 1111, "0937018395", "Stroiteley"));
	
	ListOFPeople T;

	T.Enter();
	system("cls");
	cout << "CONGTETULATE!CONGTETULATECONGTETULATE!CONGTETULATE!CONGTETULATE!CONGTETULATE!CONGTETULATE!CONGTETULATE!CONGTETULATE!ATE!CONGTETULATE!"<<endl;

	

	return 0;
}