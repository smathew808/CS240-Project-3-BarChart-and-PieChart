#pragma once
#include<iostream>
#include<fstream>
#include<String>
#include "chart.h"
#include "pieChart.h"

using namespace std;

// Author: Sean Mathews
// FileName: bar.h
// Date Modified: 11/2/2017
// Description: this is the sub header bar.h, it contains the prototypes for the barchart class

class BarChart: public Chart
{

public:

	BarChart();

	BarChart(string categoryType, int numberOfCategories);

	~BarChart();

	void calculateNumberOfCharacters(int numCharacters[]);

	void displayChart(ostream& output);
};