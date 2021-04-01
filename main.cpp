
#include <iostream>
#include <fstream>
#include <string>
#include "StudentHT.h"
using namespace std;

int main(){

	int studentID;
	StudentHT table1(100);					// hash table object
	table1.startStatistics();				// start statistics
	ifstream infile; 								// open a file in read mode.


	//**************************************************************************
	// Reading file
	//**************************************************************************

	// open insert.txt file
	infile.open("insert.txt");			

	while (!infile.eof())
	{
		// read student IDs from file
		infile >> studentID;

		// create a record object type RecType
		StudentHT::RecType record;

		// assign student ID to record ID
		record.id = studentID;

		// insert the record into the hash table 
		table1.insert(record);
	}

	// close the file
	infile.close();


	//**************************************************************************
	// Searching in file
	//**************************************************************************

	cout << "=================================== Searching ===================================" << endl;

	// open insert.txt file
	infile.open("search.txt");
	// searched record object type RecType
	StudentHT::RecType searchedRec;		
	
	while (!infile.eof())
	{
		infile >> studentID;
		StudentHT:: RecType record;
		record.id = studentID;
		// search record in hash table
		searchedRec = table1.search(record);

		// Displays ID if found, an error log if not
		if (searchedRec.id == -1)	// id not found
		{
			cout << "Record not found for Student ID: " << studentID << endl;
		}
		else	// id found
		{
			cout << "The Student Record found is: \n" << "Student ID: " << searchedRec.id << endl;
		}
	}
		//close search.txt
		infile.close();

		//**************************************************************************
		// Statistics
		//**************************************************************************

		// end statistics
		table1.endStatistics();

		//display statustics
		table1.displayStatistics();

		return 0;
	}	// end of main