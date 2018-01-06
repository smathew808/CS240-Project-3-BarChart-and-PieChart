#include <istream>
#include <ostream> 
#include<fstream>
#include"chart.h"
#include<String>

using namespace std;

// Author: Sean Mathews
// FileName: ChartClass.cpp
// Date Modified: 11/2/2017
// Description: this is the chartclass, which contains the implementations of all the functions that could be used for the subclasses and the driver




Chart::Chart() {

}

Chart::~Chart() {


}

/*Getters and Setters*/
int Chart::getNumberOfCategories() const {
	return numberOfCategories;

}
void Chart::setNumberOfCategories(int newNumberOfCatagories) {
	numberOfCategories = newNumberOfCatagories;

}

char Chart::getCategoryType() const{
	return categoryType;

}




/*used to read in the txt file using file io */
/*description of what operator is doing in executable
* ! means checked*/
/*things that could be wrong: friend!, not protected!, spelled correctly! what if the code isnt dervied from the chart.h*/
istream& operator >> (istream& inStream, Chart &n) {
	
	string trashString;//need this to store and take care of the <--| space after the int and double
	//this reads in the number of categories
	inStream >> n.numberOfCategories;
	std::getline(inStream, trashString);//this takes care of the <--| character after the numberOfCategories is read in
	for (int i = 0; i < n.getNumberOfCategories(); i++)
	{
		std::getline(inStream, n.listOfCategories[i].name);//this takes care of name to be put into the listOfCategories array[i] including the trash string
		inStream >> n.listOfCategories[i].value;//this takes care of the value be put into the listOfCategories array[i] 
		std::getline(inStream, trashString);//this takes care for the trashString -->| after the double value
	}
		return inStream;
}



bool Chart::addCategory(string name, double value) {
	//create the pointer for userCreatedCategory and make it as a new category, so far it has nothing in it
	
		//getnumberofcategories has current size
	const int MAXSIZE = 10;
	Category *userCreatedCategory = new Category;

	//takes the arguments from the function call to be used for the data structure
	userCreatedCategory->name = name;
	userCreatedCategory->value = value;

	//push on to categoryList 
	if (numberOfCategories == MAXSIZE)
		return false;
	else
		//does usercreatedcategory need to be a dereferenced or object 
		listOfCategories[numberOfCategories] = *userCreatedCategory;
	numberOfCategories++;
	return true;
}

 void displayChart(ostream& output);




/*1) Find # of categories, 2) access each categories value, 3) add all values*/
double Chart::addAllValues() {
	double totalValues = 0;
		//is it getting the dereference'ed part of listOfCategories?
	for(int i = 0; i < numberOfCategories; i++){
		totalValues += listOfCategories[i].value;
	}

	return totalValues;
}

void Chart::printLegend(ostream& output) {
	char charArray[10] = { '!', '@', '#', '$', '%', '^', '&', '*', '/', '?' };

	for (int i = 0; i < numberOfCategories; i++)
	{
		
		output << charArray[i] << " -			" << listOfCategories[i].name << "  " << (100 * ( (listOfCategories[i].value) / ( addAllValues() ) )) << "%			" << listOfCategories[i].value << endl;
	}


}







