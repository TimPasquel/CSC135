#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void intro(); //Intro Prompt
void Spaces();
double SubTotal(int books, double price);
double Discount(double sub, double disc);
double TotalCost(double sub, double dis);

int readNumberBooks();
void printResults (int books, double subCost, double discount, double totalCost);

int main()
{
	int NumBooks = 0;
	
	const double Bookprice = 8.99; //constant bookprice
	const double percent = 0.15; //constant discount, can be changed to book stores desire
	
	
	double Sub_Total = 0.0; //End Results
	double Dis_count = 0.0;
	double Total_Cost = 0.0;
	
	intro();
	NumBooks = readNumberBooks();
	
	Spaces();
	
	//Calc and Functions//
	Sub_Total = SubTotal(NumBooks, Bookprice);
	Dis_count = Discount(Sub_Total, percent);
	Total_Cost = TotalCost(Sub_Total, Dis_count);
	//Calc and Functions//
	
	printResults(NumBooks, Sub_Total, Dis_count, Total_Cost);
	
	return 0;
}

void intro()
{
	cout << "----------------------------------------------------------------------------------------" << endl;
	cout << "Welcome to BandN Books Books Store!" <<endl;
	cout << "----------------------------------------------------------------------------------------" << endl;
	cout << "Prices: " <<endl;
	cout << "Standard Ebook - $8.99" <<endl;
	cout << "Todays Deal: 15% off Total Order of Ebooks!" <<endl;
	cout << "----------------------------------------------------------------------------------------" << endl;
	cout << "Please Enter the Amount of Ebooks in The Order Below: " <<endl;
	cout << "----------------------------------------------------------------------------------------" << endl;
}

int readNumberBooks()
{
	int books;
	cin >> books;
	return books;
}

void Spaces()
{
	cout << " " << endl; //Space between intro and recpit
	cout << " " << endl;
}

double SubTotal(int books, double price)
{
	double subtotal = books * price;
	return subtotal;
}

double Discount(double sub, double disc)
{
	double discount = sub * disc;
	return discount;
}

double TotalCost(double sub, double dis)
{
	double total = sub - dis;
	return total;
}

void printResults (int books, double subCost, double discount, double totalCost)
{
	int Books = books;
	double sub_Cost = subCost;
	double Discount = discount;
	double total_Cost = totalCost;
	
	cout << fixed << showpoint; //sets decimals to 2 places
	
	cout << "----------------------------------------------------------------------------------------" << endl;
	cout << left << setprecision(2) << "Your Final Order: " <<endl;
	cout << "----------------------------------------------------------------------------------------" << endl;
	cout << setw(25) << "Number of Ebooks: " << setw(1) << Books << " EBooks" <<endl;
	cout << setw(25) << "Sub Total: " << "$" << setw (7) << sub_Cost <<endl;
	cout << setw(25) << "Discount: " << "$" << setw (7) << Discount << endl;
	cout << "----------------------------------------------------------------------------------------" << endl;
	cout << setw(25) << "Total Cost: " << "$" <<setw(7) << total_Cost << endl;
	cout << "----------------------------------------------------------------------------------------" << endl;
}
