#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void getData(string filename);
bool checkFile(string filename);
string getFileName();
void Calc(double sub_total, int people, double& tip, double& tax, double& total);
void terminal_output(int table_number, int people, double sub_total, double sales_tax, double tip, double total);

int main()
{
	string filename;
	
	filename = getFileName();
	
	if(checkFile(filename))
	{
		cout << "----------------------------------------------------------" <<endl;
		cout << "Unable to Open Files" <<endl;
		cout << "Program Termintated :(" <<endl;
		cout << "----------------------------------------------------------" <<endl;
		return 404;
	}
	
	getData(filename);
	
	return 0;
}

//-------------------------------------------------------------------Functions-------------------------------------------------------------------//
void getData(string filename)
{
	ifstream Room;
	
	Room.open(filename);
	
	int table_number = 1;
	
	while (Room) 
	{
		int people = 0;
		double current_cost = 0;
		double table_total = 0;
		
		double tax = 0;
		double tip = 0;
		double sub_total = 0;	//Variables
		double total = 0;
		
		Room >> people; 
			
		for(int k = 0; k < people; k++)
		{
			Room >> current_cost;
			table_total = table_total + current_cost; 
		}
		
		Calc(table_total, people, tip, tax, total); 
		
		terminal_output(table_number, people, table_total, tax, tip, total);
		
		table_number++;
		
		if(Room.eof())
			break;
		 
	}
	Room.close(); 
	
}

bool checkFile(string filename)
{
	ifstream file;
	file.open(filename);
	if(!file)
	{
		file.close();
		return true;
	}
	else 
	{
		file.close();
		return false;
	}
}

string getFileName()
{
	string filename;
	cout << "Please Enter the Name of the File Here: ";
	cin >> filename;
	return filename;
	
}

void Calc(double sub_total, int people, double& tip, double& tax, double& total)
{
	if(people < 5)		            //Tip Calc
		tip = sub_total * 0.16;
	else
		tip = sub_total * 0.20;  //Tip Calc
	
	tax = sub_total * 0.05; 		//Tax Calc
	
	total = sub_total + tip + tax;  //Total Calc
	
}

void terminal_output(int table_number, int people, double sub_total, double sales_tax, double tip, double total) 
{		
	cout << fixed << showpoint;
	
	cout << "----------------------------------------------------------" <<endl;
	cout << left << setprecision(2) << "Table Number: " << table_number <<endl;
	cout << "----------------------------------------------------------" <<endl;
	cout << setw(40) << "Customers: " << people << " Customers" << endl;
	cout << setw(40) << "Sub Total: " << setw(2) << "$" << setw(6) << sub_total <<endl;
	cout << setw(40) << "Sales Tax (5%): " << setw(2) << "$" << setw(8) << sales_tax << endl;
	cout << setw(40) << "Tip: " << setw(2) << "$" << setw(8) << tip << endl;
	cout << setw(40) << "Total: " << setw(2) << "$" << setw(8) << total << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "**********************************************************" << endl;
	
}
//-------------------------------------------------------------------Functions-------------------------------------------------------------------//
