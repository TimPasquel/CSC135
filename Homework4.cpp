#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void intro();
int numberPeople();
double subtotal(int people);
double salestax(double subtotal);
double tip(int people, double subtotal);
double total(double subtotal, double salestax, double tip);
void outro(double subtotal, double salestax, double tip, double total);
void farewell(double grandsub, double grandtax, double grandtip, double grandtotal);

int main()
{
	double sub_total = 0;
	double sales_tax = 0;
	double tip_tip = 0;
	double end_total = 0;
	int people = 0;
	double grand_total = 0;
	double grand_salestax = 0;
	double grand_tip = 0;
	double grand_subtotal = 0;
	
	intro();
	
	do
	{
	cout << "----------------------------------------------------------" <<endl;
	cout << "Please Enter the Amount of People in Your Party Below: " <<endl;
	cout << "----------------------------------------------------------" <<endl;
	
	people = numberPeople();
	
	if(people == 0)
		continue;
	
	sub_total = subtotal(people); // Current Room Variables//
	sales_tax = salestax(sub_total);
	tip_tip = tip(people, sub_total);
	end_total = total(sub_total, sales_tax, tip_tip); //Current Room Variables//
	
	outro(sub_total, sales_tax, tip_tip, end_total);
	
	grand_total = grand_total + end_total;      //Room Total Variables//
	grand_salestax = grand_salestax + sales_tax;
	grand_tip = grand_tip + tip_tip;
	grand_subtotal = grand_subtotal + sub_total;  ///Room Total Variables//
	cout << endl;

	}
	while (people != 0);
	
	farewell(grand_subtotal, grand_salestax, grand_tip, grand_total);
	
	return 0;
}

//Functions-------------------------------------------------------------------//
void farewell(double grandsub, double grandtax, double grandtip, double grandtotal)
{
	cout << fixed << showpoint;
	
	cout << "----------------------------------------------------------" <<endl;
	cout << left << setprecision(2) << "Complete Room Order: " <<endl;
	cout << "----------------------------------------------------------" <<endl;
	cout << setw(40) << "Room Sub Total: " << "$" << setw(6) << grandsub <<endl;
	cout << setw(40) << "Room Sales Tax Total: " << "$" << setw(6) << grandtax <<endl;
	cout << setw(40) << "Room Tip Total: " << "$" << setw(6) << grandtip <<endl;
	cout << setw(40) << "Room Total: " << "$" << setw(6) << grandtotal <<endl;
	cout << "----------------------------------------------------------" <<endl;
	cout << "Thank You For Coming to Tiny Tims Tavern" <<endl;
	cout << "Please Come Again :)" <<endl;
	cout << "----------------------------------------------------------" <<endl;
}

void outro(double subtotal, double salestax, double tip, double total)
{
	cout << fixed << showpoint;
	
	cout << "----------------------------------------------------------" <<endl;
	cout << left << setprecision(2) << "Final Order: " <<endl;
	cout << "----------------------------------------------------------" <<endl;
	cout << setw(40) << "Sub Total: " << "$" << setw(6) << subtotal <<endl;
	cout << setw(40) << "Sales Tax (5%): " << "$" << setw(8) << salestax << endl;
	cout << setw(40) << "Tip: " << "$" << setw(8) << tip << endl;
	cout << setw(40) << "Total: " << "$" << setw(8) << total << endl;
	cout << "----------------------------------------------------------" <<endl;
}

double total(double subtotal, double salestax, double tip)
{
	double total = 0;
	total = subtotal + salestax + tip;
	return total;
}

double tip(int people, double subtotal)
{
	double tip = 0;
	
	if(people < 5)
	{
		tip = subtotal * 0.16;
		return tip;
	}
	else
	{
		tip = subtotal * 0.20;
		return tip;
	}
}

double salestax(double subtotal)
{
	double salestax = 0;
	salestax = subtotal * 0.05;
	return salestax;
}

double subtotal(int people)
{
	double sub = 0;
	double subtotal = 0;
	int order = 1;
	
	for(int k = people; k > 0; k--)
	{
		cout << "----------------------------------------------------------" <<endl;
		cout << "Order " << order << ": ";
		cin >> sub;
		
		subtotal = subtotal + sub;
		
		order++;
	}
	return subtotal;
}

void intro()
{
	cout << "----------------------------------------------------------" <<endl;
	cout << "Welcome to Tiny Tims Tiny Tavern" <<endl;
}

int numberPeople()
{
	int people = 0;
	cin >> people;
	return people;
}

//Functions-------------------------------------------------------------------//
