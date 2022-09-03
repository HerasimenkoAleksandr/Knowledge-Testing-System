#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdio.h>
#include "Header.h"
#include <vector>
#include <string>
using namespace std;

void Logo()
{
	system("cls");
	cout << "                  ___________________________" << endl;
	cout << "                 ^ Knolwlege Testing Systeam ^                      " << endl;
	cout << "                 ^___________________________^" << endl << endl;
}
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
			{
				system("cls");
			
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
class Admin : public human, public IRegistration
{

public:
	Admin(): human(){}
	Admin(const string& nameP, const string& surnameP, const string& loginP, const string& passwordP, int IDP) : human(nameP, surnameP, loginP, passwordP, IDP) {}

	void Enter()
	{
		Logo();
		ReadFile();
		cout << "Enter -1- if you have an acount" << endl;
		cout << "Enter -2- if you want to create an acount" << endl;
		//system("cls");
		int b;
		cin >> b;
		system("cls");
		switch (b)
		{
		case(1):
		{
			int a = IEnterToApp();
			if (a > 3)
			{
				system("cls");

				Enter();
			}
			break;
		}
		case(2):
		{
			if (GetID() == 1796)
			{
				cout << "Already have an administrator" << endl;
				cout << "In this application, there is only one administrator!" << endl;
				system("pause");
				Enter();
			}
			else
			ICreatAcount();
			break;
		}
		default:
		{
			Enter();
		}
		}
	}
	void Show()
	{
		cout << "Admin's name: " << GetName()<< endl;
		cout << "Surname:        " << GetSurname() << endl;
		cout << "Login:           " << GetLgin() << endl;
		cout << "Passwor:        " << GetPassword() << endl;
		cout << "ID:             " << GetID() << endl;
		cout << " ================================================== " << endl;


	}
	void edit()
	{
		cout << "good";
	}

	void SetAdmin()
	{
		cout << "Hello Admin! " << endl;
		SetName();
		SetSurname();
		SetLgin();
		SetPassword();
		ID = 1000;

	}
	void ICreatAcount()
	{

		SetAdmin();
		cout << endl << endl;
		Show();
		int b;
		cout << endl;
		cout << "If everything is correct, press 5 to create an account!!!" << endl;
		cin >> b;
		if (b == 5)
		{

			WriteFile();
			system("cls");
			cout << "Congratulations! YOU HAVE ACCOUNT!!!" << endl;
		}
		else
		{
			ICreatAcount();
		}
	}
	bool HaveLogin(const string& login)
	{
		
		if (login == GetLgin())
			{
				return true;
			}

		
		return false;
	}
	bool HavePassword(const string& password)
	{
		if (password == GetPassword())
			{
				return true;
			}

			return false;
	}
	int IEnterToApp()
	{
		Logo();
		string a;
		string b;
		cout << "<<<<<<<<<<<<<<<<<<<<<<  HELLO ADMIN  >>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
		cout << "                 Enter your username to login" << endl;
		cout << "_______: ";
		cin >> a;
		cout << "                Enter your username to Password" << endl;
		cout << "_______: ";
		cin >> b;
		int t = 0;
		while (!HaveLogin(a) || !HavePassword(b))
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
	void WriteFile()
	{
		string a("DataAdmin.txt");
		fstream fs;
		fs.open(a, fstream::out);
		if (!fs.is_open())
		{
			cout << "Error open file" << endl; //Error open file
		}

		fs << GetName() << "\n";
		fs << GetSurname() << "\n";
		fs << GetLgin() << "\n";
		fs << GetPassword() << "\n";
		fs << GetID() << "\n";
		fs.close();
	}
	void ReadFile()
	{
		string a("DataAdmin.txt");
		fstream fs;
		fs.open(a, fstream::in);
		if (!fs.is_open())
		{
			cout << "Your account will be the first" << endl; //Error open file
		}
		else
		{
			
			string name;
			string surname;
			string Password;
			string login;
			int ID;
			int b = 0;
				fs >> name;
				fs >> surname;
				fs >> login;
				fs >> Password;
				fs >> ID;
				
				Admin B(name, surname, login, Password, ID);
				*this = B;
			

			fs.close();
		}
	}
};
class Question
{
	string qustion;
	string answer1;
	string answer2;
	string answer3;
	string answer4;
	int correct_answer;

public:

	Question(const string& qustionP, const string& answer1P, const string& answer2P, const string& answer3P, const string& answer4P, int correct_answerP):qustion{ qustionP},
		answer1{ answer1P }, answer2{ answer2P }, answer3{ answer3P }, answer4{ answer4P }, correct_answer{ correct_answerP }{}
	Question() :Question( "", "","", "", "", 0) {}

	string GetQustion()
	{
		return qustion;
	}
	string GetAnswer1()
	{
		return answer1;
	}
	string GetAnswer2()
	{
		return answer2;
	}
	string GetAnswer3()
	{
		return answer3;
	}
	string GetAnswer4()
	{
		return answer4;
	}
	int GetCorrect_answer()
	{
		return correct_answer;
	}
	void ShowQustion()
	{
		cout << qustion << endl;
		cout << "1. - " << answer1 << endl;
		cout << "2. - " << answer2 << endl;
		cout << "3. - " << answer3 << endl;
		cout << "4. - " << answer4 << endl;
	}
	void AddQustion()
	{

		//cin.ignore(1, -1);
		cout << "Write down the question: " << endl;
		cout << "--->:";
		cin.ignore(1, -1);
		getline(cin, qustion);
		cout << "- write down the first answer: " << endl;
		cout << "--->:";
		getline(cin, answer1);
		cout << "- write down the second answer: " << endl;
		cout << "--->:";
		getline(cin, answer2);
		cout << "- write down the third answer: " << endl;
		cout << "--->:";
		getline(cin, answer3);
		cout << "- write down the fourth answer: " << endl;
		cout << "--->:";
		getline(cin, answer4);
		cout << "Indicate the number where the correct answer is located:" << endl;
		cout << "--->:";
		cin >> correct_answer;

	}
	bool AnswerFromStudent()
	{
		ShowQustion();
		cout << endl;
		cout << "Write down the number of the correct answer" << endl;
		cout << "--->: ";
		int a;
		cin >> a;
		if (a == correct_answer)
			return 1;
		else
			return 0;
	}
};


class Test
{
	int IDStudent;
	string subject;
	string TestName;
	vector <Question> test;
	int result;
	int percent;
public:
	Test() : IDStudent{ 0 }, subject{}, TestName{}, test{}, result{ 0 }, percent{}{}
	Test(int IDStudentP) : IDStudent{ IDStudentP }, subject{}, TestName{}, test{}, result{ 0 }, percent{}{}
	string GetSubject()
	{
		return subject;
	}
	string GetTestName()
	{
		return  TestName;
	}
	void AddNewTest()
	{
		cout << "Enter the name of the subject:" << endl;
		cout << "--->: ";
		getline(cin, subject);
		cout << "Enter the name of the knowledge category:" << endl;
		cout << "--->: ";
		getline(cin, TestName);

		for (int i = 0; i < 12; i++)
		{
			system("cls");
			cout << ">->-> "<< subject << ">->-> " <<TestName << endl<<endl;
			cout << "_____________QUSTION " << i + 1 << "_____________" << endl << endl;
			Question temp;
			temp.AddQustion();
			test.push_back(temp);
			cout << endl;
		}
	}
	void WriteFile()
	{
		//string a(TestName);
		fstream fs;
		fs.open(TestName, fstream::out);
		if (!fs.is_open())
		{
			cout << "Error open file" << endl; //Error open file
		}

		fs << subject << "\n";
		fs << TestName << "\n";
		for (int i = 0; i < 12; i++)
		{
			fs << test[i].GetQustion() <<"\n";
			fs << test[i].GetAnswer1() << "\n";
			fs << test[i].GetAnswer2() << "\n";
			fs << test[i].GetAnswer3() << "\n";
			fs << test[i].GetAnswer4() << "\n";
			fs << test[i].GetCorrect_answer() << "\n";
		}
		
	fs.close();
	}
	//void ReadFile()
	//{
	//	string a("DataAdmin.txt");
	//	fstream fs;
	//	fs.open(a, fstream::in);
	//	if (!fs.is_open())
	//	{
	//		cout << "Your account will be the first" << endl; //Error open file
	//	}
	//	else
	//	{

	//		string name;
	//		string surname;
	//		string Password;
	//		string login;
	//		int ID;
	//		int b = 0;
	//		fs >> name;
	//		fs >> surname;
	//		fs >> login;
	//		fs >> Password;
	//		fs >> ID;

	//		Admin B(name, surname, login, Password, ID);
	//		*this = B;


	//		fs.close();
	//	}
	//}

	int PassTest()
	{
		
		for (int i = 0; i < 12; i++)
		{
			system("cls");
			cout << "_____________QUSTION " << i + 1 << "_____________" << endl << endl;
			if(test[i].AnswerFromStudent())
				result++;
		}
		percent = result / 0.12;
		cout << "You answered " << result << " questions correctly!" << endl;
		cout << "Scored " << percent << "%" << endl;
		return result;
	}



};


class KnowledgeTesting
{
	
	vector <Test> tests;
public:
	KnowledgeTesting(): tests{}{}
	void NewTest()
	{

		//tests[0].GetTestName();
		Test temp;
		temp.AddNewTest();
		temp.WriteFile();
		tests.push_back(temp);
		string a("ListTest");
		fstream fs;
		fs.open(a, fstream::out);
		if (!fs.is_open())
		{
			cout << "Error open file" << endl; //Error open file
		}
		vector <Test>  ::iterator iter = tests.begin();
		for (; iter != tests.end(); iter++)
		{
			fs << iter->GetSubject() << "\n";
			fs << iter->GetTestName() << "\n";
		}
	
		
		fs.close();
	}




};

int main()
{
	KnowledgeTesting A;
	A.NewTest();
	Test N;
	N.AddNewTest();
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++==" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++==" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++==" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++==" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++==" << endl;

	N.PassTest();
	Question T;
	//T.AddQustion();
	cout << endl;
	cout << T.GetQustion();
	T.ShowQustion();
	if (T.AnswerFromStudent())
		cout << "Good";
	else
		cout << "not god";


	Admin W;
	//W.ICreatAcount();
	//W.ReadFile();
//	W.Enter();
	//W.Show();
	
	//ListOFPeople T;

	//T.Enter();
	//system("cls");
	//cout << "CONGTETULATE!CONGTETULATECONGTETULATE!CONGTETULATE!CONGTETULATE!CONGTETULATE!CONGTETULATE!CONGTETULATE!CONGTETULATE!ATE!CONGTETULATE!"<<endl;

	

	return 0;
}