#include<iostream>
#include<cassert>
#include<fstream>
#include<String>
#include "chart.h"
#include "pieChart.h"
#include "barChart.h"
using namespace std;

// Author: Sean Mathews
// FileName: barChartClass.cpp
// Date Modified: 11/2/2017
// Description: this is the barchart sub class, it's mainly used for displaying the bar chart itself


BarChart::BarChart() {
	
}

void BarChart::displayChart(ostream& output) {
	//declare aray of ints
	int numChars[10]; //this holds the array of number of characters for each category
	calculateNumberOfCharacters(numChars);
	
	//output << "				  " << endl;//gets top decoration of chart
	//this is where we start printing and do comparisions, nest for

	for (int i = 0; i < numberOfCategories; i++)
	{
		cout << "--";
	}

	for (int down = 20; down >= 0; down--)
	{
		cout << endl;
			//this goes from 0 til the num of categories is reached and then second goes down 1 row
			
			//if the row tracker is == to number of categories, then exit to go down 1 row
			//if down is <= to numChar[0] print
			//this is going to make a choice whether 
			if (down <= numChars[0]) {
				cout << "! ";
			}
			else {
				cout << "  ";

			}

			if (down <= numChars[1]) {
				cout << "@ ";
			}
			else {
				cout << "  ";

			}
			if (down <= numChars[2]) {
				cout << "# ";
			}
			else {
				cout << "  ";

			}
			if (down <= numChars[3]) {
				cout << "$ ";
			}
			else {
				cout << "  ";

			}
			if (down <= numChars[4]) {
				cout << "% ";
			}
			else {
				cout << "  ";

			}
			if (down <= numChars[5]) {
				cout << "^ ";
			}
			else {
				cout << "  ";

			}
			if (down <= numChars[6]) {
				cout << "& ";
			}
			else {
				cout << "  ";

			}
			if (down <= numChars[7]) {
				cout << "* ";
			}
			else {
				cout << "  ";

			}
			if (down <= numChars[8]) {
				cout << "/ ";
			}
			else {
				cout << "  ";

			}
			if (down <= numChars[9]) {
				cout << "? ";
			}
			else {
				cout << "  ";

			}

		
	}
	cout << endl;

	for (int i = 0; i < numberOfCategories; i++)
	{
		cout << "--";
	}
	cout << endl;
}

//this function will calculate number of characters for each index[i] value by finding a factor and then multiplying it by each index[i]
void BarChart::calculateNumberOfCharacters(int numCharacters[]) {
	//first find the greatest element in the array by accessing each element and reassign it to a greatestElement reference til done
	
	double greatestElement = 0;//the greatest element is needed to be found in the listofcategories array
	double factor;//this is the factor that all the other catagories will be multiplied by to get scaled output by the largest category value

	int numCharsSize = 0;
	for (int i = 0; i < numberOfCategories; i++)//needs to be the value for listOfCategories at each [i]
	{
		if (listOfCategories[i].value > greatestElement) {
			greatestElement = listOfCategories[i].value;
		}
	}

	for(int i = 0; i < numberOfCategories; i++)
	{
		factor = (20 / greatestElement);

		numCharacters[i] = factor * listOfCategories[i].value ; //want listofcategoriesValue
	}
	
}




//for (int i = 0; i < numberOfCategories; i++)
//{
//	//this is terrible code, but what im trying to say is that I want to dereference(*listOfCategories) each index( [i] ) add(+=) each number of charracters at each of the arrays index value(calculateNumberOfCharacters(listOfCategories[i])
//	*listOfCategories[i] += calculateNumberOfCharacters(listOfCategories[i]);
//}


////specify the number that is stored 
//
////less than or equal to
//
//// if for example, goes to round 20, compares each *listOfCategories[i] to # 20, and if *listOfCategories[i] is = 20, then print ' ' else print char. *listOfCategories[i] from last night represented the num of chars, i know the code is not right but i got the idea i think 
////i have it as down because i need an decrementing value to get shit to print properly 
//if (*listOfCategories[i] == down) {
//	//keep going til reach number of catagories
//	//if first column print this then second column print this if third column print this etc 
//	output << ''
//
//}


