#pragma once
#include <istream>
#include <ostream> 
#include<fstream>
#include<String>

using namespace std;

// Author: Sean Mathews
// FileName: chart.h
// Date Modified: 11/2/2017
// Description: This is the base header for the two other sub headers, barchart and pieChart 
struct Category {
	string name;
	double value;
};

 class Chart 
{
	 


protected:
	/*DataMembers*/
	

	char categoryType;
	Category listOfCategories[10]; // maximum number of categories
	int numberOfCategories;


public:
	/*Default Ctr*/
	Chart();

	Chart(char categoryType, int numberOfCategories);
	/*Destructor, this deletes all objects made from the ctr*/
	~Chart();

	/*accessors*/

	int getNumberOfCategories() const;
	void setNumberOfCategories(int numberOfCategories);

	char getCategoryType() const;
	void setCategoryType(char categoryType) const;


	/*overloaded operator >>*/

	friend istream& operator >> (istream& inStream, Chart& input);

	/*prototype for addCategory*/

	bool addCategory(string name, double value);

	/*pure virtual function display chart, makes the class virtual*/
	virtual void displayChart(ostream& output) = 0;

	/*adds all the values of each thing*/
	double addAllValues();

	/*This prints the legend*/
	void printLegend(ostream& output);
};