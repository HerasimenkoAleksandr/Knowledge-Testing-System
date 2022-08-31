#include <iostream>
#include <windows.h>
#include <io.h>
#include <stdio.h>
using namespace std;

struct IRegistration
{
	virtual void Registration() = 0;
	virtual void ²²dentification() = 0;

};


class human : public IRegistration
{
protected:
	string name;
	string surname;
	string login;
	string password;

public:
	human() :name{}, surname{}, login{}, password{}{}
	human(const string& nameP, const string& surnameP) : name{ nameP }, surname{ surnameP }{}
	virtual void Show() = 0;
	virtual void edit() = 0;
	void Registration()
	{
		cout << "IReg()" << endl;
	}
	void ²²dentification()
	{
		cout << " Identification()" << endl;
	}

};

class student : public human
{
	string address;
	string phone_number;
public:
	student() :human(), address{}, phone_number{}{}
	student(const string& addressP, const string& phone_numberP, const string& nameP, const string& surnameP) : human(nameP, surnameP), address{ addressP }, phone_number{ phone_numberP }{}

	void Show()
	{
		cout << "Student ==============!" << endl;
		cout << name << endl;
		cout << surname << endl;
		cout << login << endl;
		cout << password << endl;
		cout << address << endl;
		cout << phone_number << endl;

	}
	void edit()
	{
		cout << "good";
	}

};
class Admin : public human
{

public:
	Admin(const string& nameP, const string& surnameP) : human(nameP, surnameP) {}


	void Show()
	{
		cout << "Admin ==============!" << endl;
		cout << name << endl;
		cout << surname << endl;
		cout << login << endl;
		cout << password << endl;


	}
	void edit()
	{
		cout << "good";
	}

};





int main()
{

	human* test = new student("qwsd", "qsdsw", "sdqw", "qwsd");
	// test = new teacher("qwsd", "qsdsw");
	test->Show();
	test->Registration();
	test->²²dentification();

	return 0;
}