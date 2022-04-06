#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class PayRaise 
{
public:
	PayRaise(const char* = " ", float = 0.0, float = 0.0);//constructor
	~PayRaise();//prints the employee name for the object being destructed.
	void printData();//printData which prints out the five private data members for the employee.
	void calcBonus(int bonus);//recalculate the necessary private data members when an employee receives a bonus.
	//  The user should be prompted for the bonus amount in the main.
private:
	char name[20];
	float currentPay;
	float raisePercentage;
	float raiseAmount;
	float newPay;
};

PayRaise::PayRaise(const char* name, float currentPay, float raisePercentage)
{
	strcpy(this->name, name);
	this->currentPay = currentPay;
	this->raisePercentage = raisePercentage;
	this->raiseAmount = currentPay * raisePercentage / 100;
	newPay = raiseAmount + currentPay;
}

PayRaise::~PayRaise()//prints the employee name for the object being destructed.
{
	cout << name << " has been destructed." << endl;
}

void PayRaise::printData()//prints out the five private data members for the employee
{

	cout <<setw(20)<< left << "name: " << name << endl;
	cout<<setw(20)<<"current pay: "<< currentPay << endl;
	cout << setw(20) << "raise percentage: " << raisePercentage << endl;
	cout << setw(20) << "raise amount: " << raiseAmount << endl;
	cout << setw(20) << "new pay: " << newPay << endl<<endl;
}

void PayRaise::calcBonus(int bonus)
{
	currentPay+=bonus;
	raiseAmount = currentPay * raisePercentage / 100;
	newPay = raiseAmount + currentPay;
}

int main()
{
	PayRaise p("Corby Bryan", 50000, 10);
	cout << setprecision(2) << fixed << showpoint;
	p.printData();
	cout << "how much is the bonus?:>";
	int bonus;
	cin >> bonus;
	cout << endl;
	p.calcBonus(bonus);
	p.printData();
	return 0;
}
