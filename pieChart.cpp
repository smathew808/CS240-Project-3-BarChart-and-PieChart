#include<iostream>
#include<cassert>
#include<fstream>
#include<String>
#include "chart.h"
#include "pieChart.h"
#include "barChart.h"
using namespace std;

// Author: Sean Mathews
// FileName: pieChart.cpp
// Date Modified: 11/2/2017
// Description: This is the pieChart, it's mainly used to display the pie chart itself


PieChart::PieChart() {


}

void PieChart::displayChart(ostream& output) {
	int x, y; // this is the value for the current value that the "char printer" is at on the "x, y" axis plane thing

	const int MAXRADIUS = 6; //the maximum radius

	double distanceFromCenter; //is how far the character is current being printed from the "center" of the pie chart//
							   //this value is used to determine if the characcter should be blank or not; if it's too far from the center be in the pie. 

	double angle[10]; //this array stores the angles for each index value of the listOfCategories array, and it's mirrored to eachother

	double currentAngle; //the current angle is the angle calculated by three points: the x, y, and center of chart

	calculateAngle(angle);

	//this populates the angle array with all the values from the listOfcategories array

	cout << endl;
	for (y = MAXRADIUS; y >= -MAXRADIUS; y--) // this increments the printer to go down 1, meaning go down 1 on y axis
	{
		cout << '\t'; //makes space  for each increment down
		for (x = int(-1.5*MAXRADIUS); x <= int(1.5*MAXRADIUS); x++)// this increments from left to right, from the "negative" direction to the "positive" direction
		{
			distanceFromCenter = sqrt((2.0*x / 3.0) * (2.0*x / 3.0) + y * y); // this is actually the distance formula lol  
			if (distanceFromCenter > MAXRADIUS)
				cout << ' ';					// this makes the blank spaces that are past the max radius
			else
			{
				currentAngle = atan2(2.0*x / 3.0, y);  // this gets the current angle in radians, this accounts what angle it's printing at, and gives the value that decides what char to print
				if (currentAngle < 0)
					currentAngle += ((2) * (3.14));      //this is LITERALLY just adding "2PI" or "360 degrees" to account for any weird output that the computer cant print or some shit, it just accounts for any WEIRD SHIT that we cant really do about printing wise

														 //this accounts for if they angle is less than 0
														 // angle array has to be used to get the pie sectioned correctly, and the percentages gotta be calculated within scope of the angle array. should we do the calculation in display even if its not modularized?

														 //Look at example in red skinny notebook on last page, calculate the radians array with this and try to itterate with an example, will understand faster if you do

				if (currentAngle <= angle[0])
					cout << "!";
				else if (currentAngle <= angle[0] + angle[1])
					cout << "@";
				else if (currentAngle <= angle[0] + angle[1] + angle[2])
					cout << "#";
				else if (currentAngle <= angle[0] + angle[1] + angle[2] + angle[3])
					cout << "$";
				else if (currentAngle <= angle[0] + angle[1] + angle[2] + angle[3] + angle[4])
					cout << "%";
				else if (currentAngle <= angle[0] + angle[1] + angle[2] + angle[3] + angle[4] + angle[5])
					cout << "^";
				else if (currentAngle <= angle[0] + angle[1] + angle[2] + angle[3] + angle[4] + angle[5] + angle[6])
					cout << "&";
				else if (currentAngle <= angle[0] + angle[1] + angle[2] + angle[3] + angle[4] + angle[5] + angle[6] + angle[7])
					cout << "*";
				else if (currentAngle <= angle[0] + angle[1] + angle[2] + angle[3] + angle[4] + angle[5] + angle[6] + angle[7] + angle[8])
					cout << "/";
				else if (currentAngle <= angle[0] + angle[1] + angle[2] + angle[3] + angle[4] + angle[5] + angle[6] + angle[7] + angle[8] + angle[9])
					cout << "?";
				//  while compare if its one guy, then print else add to angle and compare again til 360
			}
		}
		cout << endl;
	}
	return;
}

void PieChart::calculateAngle(double angle[]) {

	const double PI = 3.141592653589793;

	for (int i = 0; i < numberOfCategories; i++) {

		angle[i] = (2 * PI) * (listOfCategories[i].value / addAllValues());

	}


}