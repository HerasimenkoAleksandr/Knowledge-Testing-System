#pragma once
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
	/*void ²²dentification()
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

	void Show()
	{
		cout << "Student's name: " << name << endl;
		cout << "surname:        " << surname << endl;
		cout << "Login:           " << login << endl;
		cout << "Passwor:        " << password << endl;
		cout << "Address:        " << address << endl;
		cout << "Phone number:   " << phone_number << endl;
		cout << "ID:             " << ID << endl;
		cout << " ================================================== " << endl;
	}

	void SetStudent()
	{
		
		cout << "Dear student! We are glad to see you here!!!" << endl;
		
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
		cout << "Enter address ";
		cin >> address;
	}
	void SetPhone()
	{
		cout << "Enter phone number ";
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
};
class Admin : public human, public IRegistration
{

public:
	Admin(const string& nameP, const string& surnameP, const string& loginP, const string& passwordP, int IDP) : human(nameP, surnameP, loginP, passwordP, IDP) {}


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
	void edit1()
	{
		cout << "55555555555555555555555555555555555555555555555555";
	}
	void ICreatAcount()
	{
		cout << "aD IReg()" << endl;
	}
	int IEnterToApp()
	{
		cout << "ad Identification()" << endl;
		return 1;
	}
	
};
