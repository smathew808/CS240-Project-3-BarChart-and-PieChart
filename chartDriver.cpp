#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "chart.h"
#include "pieChart.h"
#include "barChart.h"

using namespace std;

// Author: Sean Mathews
// FileName: chartDriver.cpp
// Date Modified: 11/2/2017
// Description: This file is what interacts with the user to display charts and add categories to them 


const int MAX_CHARTS = 10; //max amount of charts
typedef Chart* chartPtr;	//the pointer for the Chart Array
void fillArray(chartPtr list[], int &size);
void modChart(chartPtr list[], int size);
int getIndex(int size);
char getChoice(int size);

void main()
{
	chartPtr chartList[MAX_CHARTS];
	int size, chartPicked;
	char choice;
	cout << "\n\t\tWelcome to the charting program!\n\n";
	fillArray(chartList, size);
	do
	{
		choice = getChoice(size);
		switch (choice)
		{
		case '1':
			chartPicked = getIndex(size);//uses the 
			chartList[chartPicked]->displayChart(cout);
			chartList[chartPicked]->printLegend(cout);
			break;
		case '2':
			modChart(chartList, size);
			chartList[chartPicked]->displayChart(cout);
			chartList[chartPicked]->printLegend(cout);
			break;
		case 'Q':
			cout << "\n\n\t\t\tGoodbye\n\n";
			for (int i = 0; i<size; i++)
				delete chartList[i];
			break;
		}
	} while (choice != 'Q');
	cout << "Press 'Enter' to quit.";
	cin.get(choice);
	return;
}
//call getChoice and getIndex
void modChart(chartPtr list[], int size)
{
	double modValue;
	string modName;
	
	int index = getIndex(size);
	cout << "What is the title of the chart's new category?";
	cin >> modName;
	cout << "What is the value of the chart's new category?";
	cin >> modValue;

	list[index]->addCategory(modName, modValue);

	
}

int getIndex(int size)
{
	int index;
	cout << "Which chart would you like? (1.." << size << "): ";
	cin >> index;
	while ((index < 1) || (index > size))
	{
		cout << "That is not a valid chart number. Try again.\n";
		cout << "Which chart would you like? (1.." << size << "): ";
		cin >> index;
	}
	index--; // to make the index (0..size-1) instead of (1..size).
	return index;
}
char getChoice(int size)
{
	char choice;
	cout << "There are " << size << " charts.\n"
		<< "What would you like to do? " << endl
		<< "1) View a chart\n"
		<< "2) Add a category to a chart\n"
		<< "Q) Quit\n"
		<< "?: ";
	cin >> choice;
	choice = toupper(choice);
	while ((choice != 'Q') && (choice != '1') && (choice != '2'))
	{
		cout << "\n\n ***  '" << choice << "' is not a listed choice.  Try again. ***\n\n";
		cout << "There are " << size << " charts.\n"
			<< "What would you like to do? (Choose 1.." << size << endl
			<< "1) View a chart\n"
			<< "2) Add a category to a chart\n"
			<< "Q) Quit\n"
			<< "?: ";
		cin >> choice;
		choice = toupper(choice);
	}
	return choice;
}
//what is the &size, is it the size of the file
void fillArray(chartPtr list[], int &size)
{	//this is the reference for the end of line character
	string trashString;

	//this is the reference for the B or P to read in
	char singleString;


	ifstream chartFile;
	chartFile.open("chartData.txt");
	//this is where overloaded operator would be used
	//so get the file size from text file
	//then set variable that is made = to size

	 size = 0;

	if (chartFile.fail()) {
		cout << "Sorry! I can't find the file, make sure it's pathed correctly.";
	}

	//make a variable to get the P character
	 //getline(chartFile, singleString);
	

	while (chartFile.good()) {
		chartFile >> singleString;
	//good means as long as you arent at the end of the file
	if (singleString == 'B') {
		//makes a new pointer to the object barChart

		//makes the new barchart object
		BarChart *barChart = new BarChart;

		//this points at list index whatever to the barchart object, but it DOESNT dereference it
		list[size] = barChart;

		chartFile >> *list[size];
		std::getline(chartFile, trashString);

		size++;
	}
	if(singleString == 'P'){
		//makes a new pointer to the object pieChart
		PieChart *pieChart = new PieChart;
		//puts that object into the index 0-whatever where what pointer is pointing at
		list[size] = pieChart;

		chartFile >> *list[size];
		std::getline(chartFile, trashString);

		size++;
	}
	
}
	chartFile.close();

}