#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdio.h>
#include "Header.h"
#include <vector>
#include <string>
using namespace std;

void Logo();
void MenuStudent(student& obj);
void MenuAdmin(Admin& obj);
void Menu();

int main()
{
	Menu();

	return 0;
}











void ListOFPeople::Add(const student& obj)
{
	Init.push_back(obj);

}
void ListOFPeople::ShowStudent()
{
	//ReadFile();
	vector <student>  ::iterator iter = Init.begin();
	for (; iter != Init.end(); iter++)
	{
		iter->Show();
	}
	system("pause");
}
bool ListOFPeople::HaveLogin(const string& login)
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
bool ListOFPeople::HaveID(int IDp)
{
	vector <student>  ::iterator iter = Init.begin();
	for (; iter != Init.end(); iter++)
	{
		if (IDp == iter->GetID())
		{
			return true;
		}

	}
	return false;
}
bool ListOFPeople::HavePassword(const string& login, const string& password)
{
	vector <student>  ::iterator iter = Init.begin();
	for (; iter != Init.end(); iter++)
	{
		if (login == iter->GetLgin() && password == iter->GetPassword())
		{
			return true;
		}

	}
	return false;
}

student ListOFPeople::Enter()
{
	Logo();
	Init.clear();
	ReadFile();
	cout << "Enter -1- if you have an acount" << endl << endl;
	cout << "                  Enter -2- if you want to create an acount" << endl << endl;
	cout << "                                               press -3- to exit" << endl << endl;
	//system("cls");
	int b;
	cin >> b;
	system("cls");
	switch (b)
	{
	case(1):
	{
		int a = IEnterToApp();
		vector <student>  ::iterator iter = Init.begin();
		for (; iter != Init.end(); iter++)
		{
			if (a == iter->GetID())
			{
				return *iter;
			}

		}
		if (a < 1000)
		{
			system("cls");

			Enter();
		}
		break;
	}
	case(2):
	{
		ICreatAcount();
		return Init.back();

	}
	case(3):
	{
		student s;
		return s;


	}
	default:
	{
		Enter();
	}
	}

}


void ListOFPeople::DeleteStudent()
{
	string a("DataPeople.txt");
	fstream fs;
	fs.open(a, fstream::out);
	if (!fs.is_open())
	{
		cout << "Error open file" << endl; //Error open file
	}
	Logo();
	//ReadFile();
	cout << "Enter the ID of the student whose information you want to delete " << endl;
	int id;
	//tem.SetStudent();

	cin >> id;
	system("cls");
	vector <student>  ::iterator iter = Init.begin();
	for (; iter != Init.end(); iter++)
	{
		if (id == iter->GetID())
		{
			continue;

		}
		else
		{
			fs << iter->GetName() << "\n";
			fs << iter->GetSurname() << "\n";
			fs << iter->GetLgin() << "\n";
			fs << iter->GetPassword() << "\n";
			fs << iter->GetAddress() << "\n";
			fs << iter->GetPhone_number() << "\n";
			fs << iter->GetID() << "\n";
		}
	}
	Init.pop_back();


	system("cls");
	cout << " --------- >>> deletion completed <<<-----------" << endl;
	system("pause");


}
int ListOFPeople::IEnterToApp()
{
	Logo();
	string a;
	string b;
	cout << "<<<<<<<<<<<<<<<<<<<<<<  HELLO STUDENT  >>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	cout << "                 Enter your username to login" << endl;
	cout << "_______: ";
	cin >> a;
	cout << "                Enter your username to Password" << endl;
	cout << "_______: ";
	cin >> b;
	int t = 0;
	while (!HavePassword(a, b))
	{
		if (t > 3)
			return t;
		system("cls");
		//cout << "LOGIN --> " << a << endl;
		cout << "Login or password entered incorrectly. REPEAT!!! " << endl;
		cout << "              you have 3 tries                    " << endl;
		cout << "   Enter your username to login" << endl;
		cin >> a;
		cout << "   Enter your username to Password" << endl;
		cin >> b;
		t++;
	}

	vector <student>  ::iterator iter = Init.begin();
	for (; iter != Init.end(); iter++)
	{
		if (a == iter->GetLgin())
		{
			return iter->GetID();
		}

	}



}
void ListOFPeople::ICreatAcount()
{
	student tem;
	cout << "Dear student! We are glad to see you here!!!" << endl;
	tem.SetStudent();
	cout << endl << endl;
	while (HaveLogin(tem.GetLgin()))
	{
		system("cls");
		cout << "LOGIN --> " << tem.GetLgin() << endl;
		cout << "THIS LOGIN IS BEING USED. You need to enter another login! " << endl;
		tem.SetLgin();

	}
	cout << endl;
	tem.Show();
	int b;
	cout << endl;
	cout << "If everything is correct, press 5 to create an account!!!" << endl;
	cin >> b;
	if (b == 5)
	{
		Init.push_back(tem);
		WriteFile();
		system("cls");
		cout << "Congratulations! YOU HAVE ACCOUNT!!!" << endl;
		system("pause");
	}
	else
	{
		ICreatAcount();
	}
}

void ListOFPeople::Edit()
{
	Logo();
	//ReadFile();
	//student tem;
	cout << "Admin you can change student details!!! " << endl;
	cout << "Enter student ID to change student information! : ";
	int id;
	//tem.SetStudent();

	cin >> id;
	system("cls");
	cout << "Please enter new data!" << endl << endl;
	vector <student>  ::iterator iter = Init.begin();
	for (; iter != Init.end(); iter++)
	{
		if ((iter->GetID()) == id)
		{
			iter->SetName();
			iter->SetSurname();
			iter->SetAddress();
			iter->SetPhone();
			iter->SetLgin();
			iter->SetPassword();
			break;
		}
	}
	if (iter == Init.end())
	{
		cout << "ID is not correct" << endl;
		system("pause");
		return;
	}
	cout << endl;
	system("cls");
	cout << "Your corrections" << endl << endl;
	//iter = Init.begin();
	iter->Show();
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
		system("cls");
		cout << " --------- >>> Ñhanges not saved <<<-----------" << endl;
		system("pause");
	}
}
void ListOFPeople::WriteFile()
{
	string a("DataPeople.txt");
	fstream fs;
	fs.open(a, fstream::out);
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
void ListOFPeople::ReadFile()
{
	string a("DataPeople.txt");
	fstream fs;
	fs.open(a, fstream::in);
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
			fs.ignore(256, '\n');
			getline(fs, address);
			fs >> phone_nomber;
			fs >> ID;
			fs.ignore(256, '\n');
			student temp(name, surname, login, Password, ID, address, phone_nomber);
			Init.push_back(temp);
			//b++;
		}

		Init.pop_back();
		fs.close();
	}
}

Admin::Admin() : human() {}
Admin::Admin(const string& nameP, const string& surnameP, const string& loginP, const string& passwordP, int IDP) : human(nameP, surnameP, loginP, passwordP, IDP) {}

int Admin::Enter()
{
	Logo();
	ReadFile();
	cout << "Enter -1- if you have an acount" << endl << endl;
	cout << "                Enter -2- if you want to create an acount" << endl << endl;
	cout << "                                              press -3- to exit" << endl << endl;
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
		return 1;

	}
	case(2):
	{
		if (GetID() == 1000)
		{
			cout << "Already have an administrator" << endl;
			cout << "In this application, there is only one administrator!" << endl;
			system("pause");
			Enter();
		}
		else
			ICreatAcount();
		return 1;
		break;
	}
	case(3):
	{
		return 0;
		break;
	}
	default:
	{
		Enter();
	}
	}
}
void Admin::Show()
{
	cout << "Admin's name: " << GetName() << endl;
	cout << "Surname:        " << GetSurname() << endl;
	cout << "Login:           " << GetLgin() << endl;
	cout << "Passwor:        " << GetPassword() << endl;
	cout << "ID:             " << GetID() << endl;
	cout << " ================================================== " << endl;


}
void Admin::edit()
{
	cout << "good";
}

void Admin::SetAdmin()
{
	cout << "Hello Admin! " << endl;
	SetName();
	SetSurname();
	SetLgin();
	SetPassword();
	ID = 1000;

}
void Admin::ICreatAcount()
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
bool Admin::HaveLogin(const string& login)
{

	if (login == GetLgin())
	{
		return true;
	}


	return false;
}
bool Admin::HavePassword(const string& password)
{
	if (password == GetPassword())
	{
		return true;
	}

	return false;
}
int Admin::IEnterToApp()
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
		cout << "              you have 3 tries                    " << endl;
		cout << "   Enter your username to login" << endl;
		cin >> a;
		cout << "   Enter your username to Password" << endl;
		cin >> b;
		t++;
	}
	return t;

}
void Admin::WriteFile()
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
void Admin::ReadFile()
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

Question::Question(const string& qustionP, const string& answer1P, const string& answer2P, const string& answer3P, const string& answer4P, int correct_answerP) :qustion{ qustionP },
answer1{ answer1P }, answer2{ answer2P }, answer3{ answer3P }, answer4{ answer4P }, correct_answer{ correct_answerP }{}
Question::Question() : Question("", "", "", "", "", 0) {}

string Question::GetQustion()
{
	return qustion;
}
string  Question::GetAnswer1()
{
	return answer1;
}
string  Question::GetAnswer2()
{
	return answer2;
}
string Question::GetAnswer3()
{
	return answer3;
}
string Question::GetAnswer4()
{
	return answer4;
}
int Question::GetCorrect_answer()
{
	return correct_answer;
}
void Question::ShowQustion()
{
	cout << qustion << endl;
	cout << "1. - " << answer1 << endl;
	cout << "2. - " << answer2 << endl;
	cout << "3. - " << answer3 << endl;
	cout << "4. - " << answer4 << endl;
}
void Question::AddQustion()
{

	//cin.ignore(1, -1);
	cout << "Write down the question: " << endl;
	cout << "--->:";
	//cin.ignore(1, '\n');
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
	cin.ignore(256, '\n');

}
bool Question::AnswerFromStudent()
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
Question& Question :: operator=(Question& obj)
{
	qustion = obj.GetQustion();
	answer1 = obj.GetAnswer1();
	answer2 = obj.GetAnswer2();
	answer3 = obj.GetAnswer3();
	answer4 = obj.GetAnswer4();
	correct_answer = obj.GetCorrect_answer();
	return *this;
}

Test::Test() : subject{}, TestName{}, test{}, result{ 0 }, percent{}{}
Test::Test(string& subjectP, string& TestNameP, int resultP, float percentP) : subject{ subjectP }, TestName{ TestNameP }, result{ resultP }, percent{ percentP }, test{}{}
Test::Test(string& subjectP, string& TestNameP) : Test(subjectP, TestNameP, 0, 0) {}
Test::Test(string& subjectP, string& TestNameP, int resultP, float percentP, vector <Question>& testP) : subject{ subjectP }, TestName{ TestNameP }, result{ resultP }, percent{ percentP }, test{ testP }{}
string Test::GetSubject()
{
	return subject;
}
string Test::GetTestName()
{
	return  TestName;
}
int Test::GetResulte()
{
	return  result;
}
vector <Question> Test::GetTest()
{
	return test;
}
int Test::GetPercent()
{
	return  percent;
}
void Test::AddNewTest()
{
	cout << "Enter the name of the subject:" << endl;
	cout << "--->: ";
	cin.ignore(256, '\n');
	getline(cin, subject);
	cout << "Enter the name of the knowledge category:" << endl;
	cout << "--->: ";
	getline(cin, TestName);

	for (int i = 0; i < 12; i++)
	{
		system("cls");
		cout << ">->-> " << subject << ">->-> " << TestName << endl << endl;
		cout << "_____________QUSTION " << i + 1 << "_____________" << endl << endl;
		Question temp;
		temp.AddQustion();
		test.push_back(temp);
		cout << endl;
	}
}
void Test::WriteFile()
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
		fs << test[i].GetQustion() << "\n";
		fs << test[i].GetAnswer1() << "\n";
		fs << test[i].GetAnswer2() << "\n";
		fs << test[i].GetAnswer3() << "\n";
		fs << test[i].GetAnswer4() << "\n";
		fs << test[i].GetCorrect_answer() << "\n";
	}

	fs.close();
}
void Test::ReadTest()
{
	//	string a("ListTest");
	fstream fs;
	fs.open(TestName, fstream::in);
	if (!fs.is_open())
	{
		cout << "Error open file" << endl; //Error open file
	}
	else
	{
		string Subject;
		string TestName;
		getline(fs, Subject);
		getline(fs, TestName);
		while (!fs.eof())
		{

			string qustion;
			string answer1;
			string answer2;
			string answer3;
			string answer4;
			int correct_answer;
			getline(fs, qustion);
			getline(fs, answer1);
			getline(fs, answer2);
			getline(fs, answer3);
			getline(fs, answer4);

			fs >> correct_answer;
			//fs.ignore(256, '\n');
			Question T(qustion, answer1, answer2, answer3, answer4, correct_answer);
			test.push_back(T);
			fs.ignore(256, '\n');
		}


		test.pop_back();
		fs.close();
	}
}
int Test::PassTest()
{

	for (int i = 0; i < 12; i++)
	{
		system("cls");
		cout << "_____________QUSTION " << i + 1 << "_____________" << endl << endl;
		if (test[i].AnswerFromStudent())
			result++;
	}
	cout << endl;
	percent = result / 0.12;
	cout << "You answered " << result << " questions correctly!" << endl;
	cout << "Scored " << percent << "%" << endl;
	system("pause");
	return result;
}
Test& Test :: operator=(Test& obj)
{
	delete& subject;
	delete& TestName;
	//	delete test
//*this = obj;
	subject = obj.GetSubject();
	TestName = obj.GetTestName();
	result = obj.GetResulte();
	percent = obj.GetPercent();
	//Test OR;
	//OR = obj.GetTest();
	//test = obj.GetTest().begin();
	vector <Question>  ::iterator iter = obj.test.begin();
	vector <Question>  ::iterator iter2 = test.begin();
	string qustion;
	string answer1;
	string answer2;
	string answer3;
	string answer4;
	int correct_answer;
	for (; iter != obj.test.end(); iter++)
	{
		qustion = iter->GetQustion();
		answer1 = iter->GetAnswer1();
		answer2 = iter->GetAnswer2();
		answer3 = iter->GetAnswer3();
		answer4 = iter->GetAnswer4();
		correct_answer = iter->GetCorrect_answer();
		Question T(qustion, answer1, answer2, answer3, answer4, correct_answer);
		test.push_back(T);
	}
	//delete &obj;

	return *this;
}

KnowledgeTesting::KnowledgeTesting() : tests{} {}
void KnowledgeTesting::Show()
{
	vector <Test>  ::iterator iter = tests.begin();
	for (; iter != tests.end(); iter++)
	{
		cout << endl;

		cout << "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" << endl;
		cout << "      Subject:    " << iter->GetSubject() << endl;
		cout << "      Test name:  " << iter->GetTestName() << endl;
		cout << "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" << endl;
	}
}
void  KnowledgeTesting::NewTest()
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
void KnowledgeTesting::ReadListTest()
{
	string a("ListTest");
	fstream fs;
	fs.open(a, fstream::in);
	if (!fs.is_open())
	{
		cout << "Error open file" << endl; //Error open file
	}
	else
	{
		while (!fs.eof())
		{
			//fs.ignore(256, '\n');
			string Subject;
			string TestName;
			getline(fs, Subject);
			getline(fs, TestName);
			Test T(Subject, TestName);
			tests.push_back(T);
		}


		tests.pop_back();
		fs.close();
	}
}
void KnowledgeTesting::ReadOllTest()
{
	//string a("ListTest");
	vector <Test>  ::iterator iter = tests.begin();
	for (; iter != tests.end(); iter++)
	{
		iter->ReadTest();

	}
}
string KnowledgeTesting::CategorySelection()
{
	int a = 0;
	int q = 0;
	vector <string> Temp;

	cout << "Select a category to pass from the proposed one and write down its number" << endl;
	vector <Test>  ::iterator iter = tests.begin();

	int n = 0;
	for (; iter != tests.end(); iter++)
	{
		int r = 0;
		vector <Test>  ::iterator iter2 = tests.begin();
		for (; iter2 != iter; iter2++)
		{
			n++;
			if (iter2->GetSubject() == iter->GetSubject())
			{
				r++;
			}
		}
		if (r == 0 || n == 1)
		{
			Temp.push_back(iter->GetSubject());
			cout << "number - " << ++a << endl;
			cout << "Category: " << iter->GetSubject() << endl;;
		}
	}
	cout << "Your choice -->: ";
	cin >> q;

	return Temp[q - 1].data();

}
string KnowledgeTesting::TestSelection(const string& categ)
{
	system("cls");
	int a = 0;
	int q = 0;
	vector <string> Temp;
	cout << "-->>: " << categ << endl;
	cout << "Select a test to pass from the proposed one and write down its number" << endl;
	vector <Test>  ::iterator iter = tests.begin();

	for (; iter != tests.end(); iter++)
	{

		if (categ == iter->GetSubject())
		{
			Temp.push_back(iter->GetTestName());
			cout << "number - " << ++a << endl;
			cout << "Test: " << iter->GetTestName() << endl;;
		}
	}
	cout << "Your choice -->: ";
	cin >> q;

	return Temp[q - 1].data();

}

void KnowledgeTesting::KnowledgeTest1(student& obj)
{
	string t = CategorySelection();
	string tes;
	int r;
	float b;
	tes = TestSelection(t);
	fstream fs;
	fs.open("Result.txt", fstream::out | fstream::app);
	if (!fs.is_open())
	{
		cout << "Error open file" << endl; //Error open file
	}
	else
	{
		vector <Test>  ::iterator iter = tests.begin();
		for (; iter != tests.end(); iter++)
		{
			if (tes == iter->GetTestName())
			{
				r = iter->PassTest();
				b = r / 0.12;
				// fs.ignore(256, '\n');
				fs << iter->GetSubject() << "\n";
				fs << iter->GetTestName() << "\n";
				fs << obj.GetName() << "\n";
				fs << obj.GetSurname() << "\n";
				fs << r << "\n";
				fs << b << "\n";
				fs << obj.GetID() << "\n";
			}
		}
	}

	fs.close();



}

RESULT::RESULT() :A{}, B{}{}
RESULT::RESULT(student& AP, Test& BP) : A{ AP }, B{ BP }{}
RESULT::RESULT(const student& obj) : A{ obj }, B{  }
{
	ReadListTest();
	ReadOllTest();
	//B = KTest(CategorySelection());
	B.PassTest();
	WriteResult();
}
int RESULT::GetAID()
{
	return A.GetID();
}
void  RESULT::StudentMOVE(student& obj)
{
	ReadListTest();
	ReadOllTest();
	KnowledgeTest1(obj);
}
void RESULT::WriteResultForAll()
{
	fstream fs;
	fs.open("RESULTofSTUDENT", fstream::out | fstream::app);
	if (!fs.is_open())
	{
		cout << "Error open file" << endl; //Error open file
	}
	else
	{

		fs << "Subject: " << B.GetSubject() << endl;
		fs << "Test name: " << B.GetTestName() << endl;
		fs << "Student: " << A.GetName() << " " << A.GetSurname() << endl;
		fs << "Exam result: " << B.GetResulte() << endl;
		fs << "percentage of correct answers: " << B.GetPercent() << endl;
		fs << "==========================================================================================" << endl;
	}

	fs.close();
}
void RESULT::WriteResult()
{
	fstream fs;
	fs.open("Result", fstream::out | fstream::app);
	if (!fs.is_open())
	{
		cout << "Error open file" << endl; //Error open file
	}
	else
	{

		fs << B.GetSubject() << endl;
		fs << B.GetTestName() << endl;
		fs << A.GetName() << endl;
		fs << A.GetSurname() << endl;
		fs << B.GetResulte() << endl;
		fs << B.GetPercent() / 0.12 << endl;
		fs << A.GetID() << endl;
	}

	fs.close();
}
void RESULT::ShowResult()
{
	//cout << " ---- Results of all students -----" << endl << endl;
	cout << "Subject: " << B.GetSubject() << endl;
	cout << "Test name: " << B.GetTestName() << endl;
	cout << "Student: " << A.GetName() << " " << A.GetSurname() << endl;
	cout << "Exam result: " << B.GetResulte() << endl;
	cout << "percentage of correct answers: " << B.GetPercent() << endl;
	cout << "==========================================================================================" << endl;
}
void RESULT::ShowResult(int IDP)
{

	cout << " -------------------------------------------------------------------------------------- - " << endl << endl;
	cout << "Subject: " << B.GetSubject() << endl;
	cout << "Test name: " << B.GetTestName() << endl;
	cout << "Student: " << A.GetName() << " " << A.GetSurname() << endl;
	cout << "Exam result: " << B.GetResulte() << endl;
	cout << "percentage of correct answers: " << B.GetPercent() << "%" << endl;
	cout << "==========================================================================================" << endl;
}

ListRESULT::ListRESULT() : A{} {}
void ListRESULT::ReadResult()
{
	string a("Result.txt");
	fstream fs;
	fs.open(a, fstream::in | fstream::app);
	if (!fs.is_open())
	{
		cout << "Error open file" << endl; //Error open file
	}
	else
	{

		//cout << " ---- Results of all students -----" << endl << endl;
		while (!fs.eof())
		{

			string Subject;
			string TestName;
			string Name;
			string Surname;
			int result;
			float Percent;
			int ID;
			getline(fs, Subject);
			getline(fs, TestName);
			getline(fs, Name);
			getline(fs, Surname);
			fs >> result;
			fs >> Percent;
			fs >> ID;
			fs.ignore(256, '\n');
			Test T(Subject, TestName, result, Percent);
			student S(Name, Surname, ID);
			RESULT W(S, T);
			A.push_back(W);
			if (fs.eof()) break;
			//cin.ignore(256, '\n');

		}

		A.pop_back();



	}
	fs.close();

}
void ListRESULT::Show()
{
	vector <RESULT>  ::iterator iter = A.begin();
	for (; iter != A.end(); iter++)
	{
		cout << " ---- Results of all students -----" << endl << endl;
		iter->ShowResult();
	}
}
void ListRESULT::Show(int IDP)
{
	int a = 0;
	vector <RESULT>  ::iterator iter = A.begin();
	for (; iter != A.end(); iter++)
	{
		//	cout << " ---- Results -----" << endl << endl;
		if (iter->GetAID() == IDP)
		{
			//	cout << " ---- Results of all students -----" << endl << endl;
			iter->ShowResult();
			a++;
		}
	}
	if (a == 0)
	{
		cout << "The student did not pass any test !" << endl;
	}
}
void ListRESULT::ShowAll()
{
	cout << "view the test results of all students press -1-" << endl << endl;
	cout << "                    view all results of one student press -2-" << endl << endl;
	cout << "                                               press -3- to exit" << endl << endl;
	cout << "------->: ";
	int a;
	cin >> a;
	switch (a)
	{
	case(1):
	{
		system("cls");
		Show();
		system("pause");
		ShowAll();
		break;
	}
	case(2):
	{
		system("cls");
		cout << "Enter ID student to view information about it -> ";
		int a;
		cin >> a;
		Show(a);
		system("pause");
		ShowAll();
		break;
	}
	case(3):
	{

		break;
	}
	default:
		ShowAll();
	}

}

void MenuStudent(student& obj)
{
	system("cls");
	int q;
	Logo();
	cout << endl;
	cout << " HELLO " << obj.GetName() << "! I wish you to benefit from my development" << endl << endl;
	cout << "choose and pass the test press -1- " << endl << endl;
	cout << "                   see your results press -2-" << endl << endl;
	cout << "                                    press -3- to exit" << endl << endl;
	cout << "------->: ";
	cin >> q;
	switch (q)
	{
	case(1):
	{
		system("cls");
		RESULT D;
		D.StudentMOVE(obj);

		MenuStudent(obj);
		break;
	}
	case(2):
	{
		ListRESULT B;
		system("cls");
		B.ReadResult();
		Logo();
		cout << " ____________ Here are all your results _____________ " << endl << endl;
		B.Show(obj.GetID());
		system("pause");
		//RESULT D;
		//D.StudentMOVE(obj);
		MenuStudent(obj);
		break;
	}
	case(3):
	{

		break;
	}
	default:
		MenuStudent(obj);

	}

}

void MenuAdmin(Admin& obj)
{
	system("cls");
	int q;
	Logo();
	cout << endl;
	cout << " HELLO " << obj.GetName() << "! I wish you to benefit from my development" << endl << endl;
	cout << "View information about students press -1- " << endl << endl;
	cout << "                          Test section press -2-" << endl << endl;
	cout << "                                        press -3- to exit" << endl << endl;
	cout << "------->: ";
	cin >> q;
	switch (q)
	{
	case(1):
	{
		system("cls");
		cout << "Information about students press -1- " << endl << endl;
		cout << "                   Edit student information press -2-" << endl << endl;
		cout << "                                    view test results press -3- " << endl << endl;
		cout << "                                               delete student account -4- " << endl << endl;
		cout << "                                                                     press -5- to exit" << endl << endl;
		cout << "------->: ";


		int a;
		cin >> a;
		switch (a)
		{
		case(1):
		{
			ListOFPeople stud;
			stud.ReadFile();
			stud.ShowStudent();
			MenuAdmin(obj);
			break;
		}
		case(2):
		{
			ListOFPeople stud;
			stud.ReadFile();
			stud.Edit();
			MenuAdmin(obj);
			break;
		}
		case(3):
		{
			ListRESULT B;
			B.ReadResult();
			B.ShowAll();
			MenuAdmin(obj);
			break;
		}
		case(4):
		{
			ListOFPeople stud;
			stud.ReadFile();
			stud.DeleteStudent();
			break;
		}
		case(5):
		{

			break;
		}
		default:
		{
			MenuAdmin(obj);
			break;
		}
		}
	}
	case(2):
	{
		system("cls");
		cout << "Ñreate a test press -1- " << endl << endl;
		cout << "                   see all tests -2-" << endl << endl;
		cout << "                                                 press -3- to exit" << endl << endl;
		cout << "------->: ";


		int a;
		cin >> a;
		switch (a)
		{
		case(1):
		{
			KnowledgeTesting B;
			B.ReadListTest();
			B.ReadOllTest();
			B.NewTest();
			MenuAdmin(obj);
			break;
		}
		case(2):
		{
			system("cls");
			KnowledgeTesting B;
			B.ReadListTest();
			B.ReadOllTest();
			cout << "All possible tests !!!" << endl << endl;
			B.Show();
			system("pause");
			MenuAdmin(obj);
			break;
		}
		case(3):
		{


			break;
		}
		default:
		{
			MenuAdmin(obj);
			break;
		}
		}

	}


	}
}

void Menu()
{

	int q;
	Logo();
	//system("cls");
	cout << "if you are a student press -1- " << endl << endl;
	cout << "             if you are an administrator press -2-" << endl << endl;
	cout << "------->: ";
	cin >> q;

	//stud.ReadFile();
	switch (q)
	{
	case(1):
	{
		Logo();
		ListOFPeople stud;
		student stud_1 = stud.Enter();
		if (stud_1.GetID() == 0)
			Menu();

		MenuStudent(stud_1);
		Menu();
		break;

	}
	case(2):
	{
		Logo();
		Admin admin;
		int a = admin.Enter();
		if (a == 0)
			Menu();
		MenuAdmin(admin);
		Menu();
		break;

	}
	default:
		Menu();
	}

}

void Logo()
{
	system("cls");
	cout << "               __________________________________" << endl;
	cout << "              ^     Knolwlege Testing Systeam    ^                      " << endl;
	cout << "              ^__________________________________^" << endl << endl;
}