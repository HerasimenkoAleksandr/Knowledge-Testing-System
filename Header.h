#pragma once
#include <fstream>
#include <string>
#include<vector>
using namespace std;

struct IRegistration
{
	virtual void ICreatAcount() = 0;
	virtual int IEnterToApp() = 0;

};
class human 
{
protected:
	string name;
	string surname;
	string login;
	string password;
	int ID;

public:
	human() :name{}, surname{}, login{}, password{}, ID{ 0 }{}
	human(const string& nameP, const string& surnameP, const string& loginP, const string& passwordP, int IDP ) : name{ nameP }, surname{ surnameP }, login{ loginP },
		password{ passwordP },  ID{IDP}{}
	human(const string& nameP, const string& surnameP, int IDP) : name{ nameP }, surname{ surnameP }, login{ },
		password{  }, ID{ IDP }{}
	virtual void Show() = 0;
	virtual void edit() = 0;
	string GetName()
	{
		return name;
	}
	string GetSurname()
	{
		return surname;
	}
	string GetLgin()
	{
		return login;
	}
	string GetPassword()
	{
		return 	password;
	}
	int GetID()
	{
		return 	ID;
	}
	void SetName()
	{
		cout << "Enter your name ";
		cin>> name;
	}
	void SetSurname()
	{
		cout << "Enter your surname ";
		cin>> surname;
	}
	void SetLgin()
	{
		cout << "Enter login ";
		cin>> login;
	}
	void SetPassword()
	{
		cout << "Enter password ";
		cin	>> password;
	}
	void SetID()
	{
		srand(time(NULL));
		ID = rand() % 1000 + 1001;
	}
	/*void ��dentification()
	{
		cout << " Identification()" << endl;
	}*/

};

class student : public human, public IRegistration
{
	string address;
	string phone_number;
public:
	student() :human(), address{}, phone_number{}{}
	student(const string& nameP, const string& surnameP, const string& loginP, const string& passwordP, int IDP , const string& addressP, const string& phone_numberP) :
		human(nameP, surnameP, loginP, passwordP, IDP), address{ addressP }, phone_number{ phone_numberP }{}
	student(const string& nameP, const string& surnameP,  int IDP)  :human(nameP, surnameP,  IDP),  address{  }, phone_number{  }{}
	void Show()
	{
		cout << "Student's name: " << name << endl;
		cout << "surname:        " << surname << endl;
		cout << "Login:          " << login << endl;
		cout << "Passwor:        " << password << endl;
		cout << "Address:        " << address << endl;
		cout << "Phone number:   " << phone_number << endl;
		cout << "ID:             " << ID << endl;
		cout << " ================================================== " << endl;
	}

	void SetStudent()
	{
		
		
		
		SetName();
		SetSurname();
	    SetLgin();
		SetPassword();
		SetID();
		SetPhone();
		SetAddress();
	}
	void SetAddress()
	{
		cout << "Enter address: ";
		cin.ignore(256, '\n');
		getline(cin, address);
	}
	student& operator=(student& obj)
	{
		name= obj.GetName();
		surname = obj.GetSurname();
		login = obj.GetLgin();
		password = obj.GetPassword();
		ID = obj.GetID();
		address = obj.GetAddress();
		phone_number = obj.GetPhone_number();
		return *this;

	}
	void SetPhone()
	{
		cout << "Enter phone number: ";
		cin >> phone_number;
	}
	string GetAddress()
	{
		return address;
	}
	string GetPhone_number()
	{
		return phone_number;
	}
	void edit()
	{
		cout << "good";
	}
	void edit2()
	{
		cout << "666666666666666666666666666666666666666666666";
	}
	
	void ICreatAcount()
	{
		cout << "student IReg()" << endl;
	}
	int IEnterToApp()
	{
		cout << "student Identification()" << endl;
		return 1;
	}

	/*void GoTest(KnowledgeTesting& obj)
	{
		obj.

	}*/
};
//class Admin : public human, public IRegistration
//{
//
//public:
//	Admin(const string& nameP, const string& surnameP, const string& loginP, const string& passwordP, int IDP) : human(nameP, surnameP, loginP, passwordP, IDP) {}
//
//	void SetAdmin()
//	{
//
//		cout << "Hello Admin! " << endl;
//
//		SetName();
//		SetSurname();
//		SetLgin();
//		SetPassword();
//		SetID();
//		
//	}
//	void Show()
//	{
//		cout << "Admin ==============!" << endl;
//		cout << name << endl;
//		cout << surname << endl;
//		cout << login << endl;
//		cout << password << endl;
//
//
//	}
//	void edit()
//	{
//		cout << "good";
//	}
//	void edit1()
//	{
//		cout << "55555555555555555555555555555555555555555555555555";
//	}
//	void ICreatAcount()
//	{
//		cout << "aD IReg()" << endl;
//	}
//	int IEnterToApp()
//	{
//		cout << "ad Identification()" << endl;
//		return 1;
//	}
//	
//};



class ListOFPeople : public IRegistration
{
	vector <student> Init;
public:
	ListOFPeople():Init {}{}
	void Add(const student& obj);
	void ShowStudent();
	bool HaveLogin(const string& login);
	bool HaveID(int IDp);
	bool HavePassword(const string& login, const string& password);

	student Enter();
	void DeleteStudent();
	int IEnterToApp();
	void ICreatAcount();

	void Edit();
	void WriteFile();
	void ReadFile();

};


class Admin : public human, public IRegistration
{

public:
	Admin();
	Admin(const string& nameP, const string& surnameP, const string& loginP, const string& passwordP, int IDP);

	int Enter();
	void Show();
	void edit();

	void SetAdmin();
	void ICreatAcount();
	bool HaveLogin(const string& login);
	bool HavePassword(const string& password);
	int IEnterToApp();
	void WriteFile();
	void ReadFile();
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

	Question(const string& qustionP, const string& answer1P, const string& answer2P, const string& answer3P, const string& answer4P, int correct_answerP);
	Question();

	string GetQustion();
	string GetAnswer1();
	string GetAnswer2();
	string GetAnswer3();
	string GetAnswer4();
	int GetCorrect_answer();
	void ShowQustion();
	void AddQustion();
	bool AnswerFromStudent();
	Question& operator=(Question& obj);
};

class Test
{
	string subject;
	string TestName;
	vector <Question> test;
	int result;
	float percent;

public:
	Test();
	Test(string& subjectP, string& TestNameP, int resultP, float percentP);
	Test(string& subjectP, string& TestNameP);
	Test(string& subjectP, string& TestNameP, int resultP, float percentP, vector <Question>& testP);
	string GetSubject();
	string GetTestName();
	int GetResulte();
	vector <Question> GetTest();
	int GetPercent();
	void AddNewTest();
	void WriteFile();
	void ReadTest();
	int PassTest();
	Test& operator=(Test& obj);


};

class KnowledgeTesting
{

	vector <Test> tests;
public:
	KnowledgeTesting();
	void Show();
	void NewTest();
	void ReadListTest();
	void ReadOllTest();
	string CategorySelection();
	string TestSelection(const string& categ);
	void KnowledgeTest1(student& obj);


};

class RESULT :public KnowledgeTesting, public ListOFPeople
{
	student A;
	Test B;
public:
	RESULT();
	RESULT(student& AP, Test& BP);
	RESULT(const student& obj);
	int GetAID();
	void StudentMOVE(student& obj);
	void WriteResultForAll();
	void WriteResult();
	void ShowResult();
	void ShowResult(int IDP);
};

class ListRESULT
{
	vector<RESULT> A;
public:
	ListRESULT();
	void ReadResult();
	void Show();
	void Show(int IDP);
	void ShowAll();
};

