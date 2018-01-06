#pragma once
#include<iostream>
#include<fstream>
#include<String>
#include "chart.h"
#include "barChart.h"
using namespace std;

// Author: Sean Mathews
// FileName: pie.cpp
// Date Modified: 11/2/2017
// Description: this header file is the sub header for the sub class pie chart 

class PieChart: public Chart
{

	

public:

	PieChart();

	PieChart(string categoryType, int numberOfCategories);

	~PieChart();

	void displayChart(ostream& output);


	void calculateAngle(double angle[]);
};
