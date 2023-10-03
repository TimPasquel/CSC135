#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void intro(double cost);

int readSquareFt();
double readPaintPrice();

double calcPaintCost(double paint, double feet);
double calcLaborCost(double feet);
double calcTotalCost (double paintCost, double laborCost);

void outro(double sqFeet, double perGal, double paint, double labor, double total);

int main()
{
	const double price = 20.00;
	double sqFeet = 0;
	double paintCost = 0;
	
	double Total_paintCost;
	double Total_LaborCost;
	double Total_Cost;
	
	intro(price);
	
	sqFeet = readSquareFt();
	
	while(paintCost < 10.00)
	{
	cout << "-------------------------------------------------------------------" <<endl;
	cout << "Please Enter the Cost of Paint Below (No Less than $10): " << endl;
	cout << "-------------------------------------------------------------------" <<endl;
	paintCost = readPaintPrice();
	}
	
	//calc//
	Total_paintCost = calcPaintCost(paintCost, sqFeet);
	Total_LaborCost = calcLaborCost(sqFeet);
	Total_Cost = calcTotalCost(Total_paintCost, Total_LaborCost);
	//calc//
	
	outro(sqFeet, paintCost, Total_paintCost, Total_LaborCost, Total_Cost);
	
	return 0;
}

void intro(double cost)
{
	double price = cost;
	cout << "-------------------------------------------------------------------" <<endl;
	cout << "Welcome to Resnov's Painting Company" <<endl;
	cout << "Prices: " <<endl;
	cout << "120 sq feet = 1 Gal Paint & 8 Hours of Labor" <<endl;
	cout << "$ " << price << " per Hour of Labor" <<endl;
	cout << "-------------------------------------------------------------------" <<endl;
	cout << "Please Enter the Square Footage of the Area Below: " <<endl;
	cout << "-------------------------------------------------------------------" <<endl;
}

int readSquareFt()
{
	int squareFeet;
	cin >> squareFeet;
	return squareFeet;
}

double readPaintPrice()
{
	double paintPrice;
	cin >> paintPrice;
	return paintPrice;
}

double calcPaintCost(double paint, double feet)
{
	double cost;
	cost = paint * (feet/120.00);
	return cost;
}

double calcLaborCost(double feet)
{
	double cost;
	cost = 20.00 * (8 * (feet/120.00));
	return cost;
}

double calcTotalCost (double paintCost, double laborCost)
{
	double total;
	total = paintCost + laborCost;
	return total;
}

void outro(double sqFeet, double perGal, double paint, double labor, double total)
{
	cout << fixed << showpoint;
	
	cout << "-------------------------------------------------------------------" <<endl;
	cout << left << setprecision(2) << "Final Order: " <<endl;
	cout << "-------------------------------------------------------------------" <<endl;
	cout << setw(40) << "Square Feet: " << setw(6) << sqFeet <<endl;
	cout << setw(40) << "Paint Cost Per Gal: " << "$" << setw(8) << perGal << endl;
	cout << setw(40) << "Paint Cost: " << "$" << setw(8) << paint << endl;
	cout << setw(40) << "Labor Cost: " << "$" << setw(8) << labor << endl;
	cout << setw(40) << "Total Cost: " << "$" << setw(8) << total <<endl;
	cout << "-------------------------------------------------------------------" <<endl;
}
