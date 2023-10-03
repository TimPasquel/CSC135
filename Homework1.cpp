#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;
int main()
{
	double amount = 0;
	double principle = 0;
	double rate = 0;
	int time = 0;
	
	cout << fixed << showpoint;

	//Input//
	cout << "----------------------------------------------------------------------------------------------" << endl;
	cout << left <<  setprecision(2) << "Please Enter the Principle Amount Below (XXXX.XX): " << endl;
	cout << "----------------------------------------------------------------------------------------------" << endl;
	cin >> principle;

	cout << "" << endl;

	cout << "----------------------------------------------------------------------------------------------" << endl;
	cout << "Please Enter the Interest Rate Below (XX.XX): " << endl;
	cout << "----------------------------------------------------------------------------------------------" << endl;
	cin >> rate;

	rate = rate / 100;

	cout << "" << endl;

	cout << "----------------------------------------------------------------------------------------------" << endl;
	cout << "Please Enter the Times Compounded Below (X): " << endl;
	cout << "----------------------------------------------------------------------------------------------" << endl;
	cin >> time;

	cout << "" << endl;
	//Input//

	//Calc//
	amount = principle * pow((1 + rate / time), time);
	rate = rate *100; //return it to visable state
	//Calc//

	//Output//
	cout << "----------------------------------------------------------------------------------------------" << endl;
	cout << setw(25) << left << "Principle: " << right << setw(15) << "$" << principle << endl;
	cout << setw(25) << left << "Interest Rate: " << right << setw(15) << rate << "%" <<endl;
	cout << setw(25) << left << "Times Compounded: " << right << setw(15) << time << " Times" <<endl;
	cout << "----------------------------------------------------------------------------------------------" << endl;
	cout << setw(25) << left << "Total Amount: " << right << setw(15) << "$" << amount << endl;
	cout << "----------------------------------------------------------------------------------------------" << endl;
	//Output//




	return 0;

}
