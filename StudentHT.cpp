#include "StudentHT.h"
#include <iostream>
using namespace std;


//**************************************************************************
// Function: StudentHT(Default constructor)
// Purpose:  Construct a StudentHT object
//**************************************************************************
StudentHT::StudentHT(int size)
{
	tableSize = size;
	// pointer pointing to dynamically allocated an array of pointers
	hashPtr = new NodeType*[tableSize];

	// initialize pointer with nullptr values
	for (int i = 0; i < tableSize; i++)
	{
		hashPtr[i] = nullptr;
	}
}

//**************************************************************************
// Function:	hashFunction(int studentID)
// Purpose:		Calculate the hash index from student id as 
//        		hash index = (student id) % (total entries in hash table)
// Returns:		hash index value
//**************************************************************************
int StudentHT::hashFunction(int studentID)
{
	return studentID % tableSize;
}


//**************************************************************************
// Function:	insert(RecType record)
// Purpose:		Insert node to hash table
// Returns:		Nothing
//**************************************************************************
void StudentHT::insert(RecType record)
{
	// generate hash index
	int hashKey = hashFunction(record.id);
	// allocate new memory for new
	NodeType* newRecord = new NodeType;
	// Copy record to NodeType record
	newRecord->id = record.id;
	newRecord->nodeFirstName = record.recFirstName;
	newRecord->nodeLastName = record.recLastName;
	newRecord->next = nullptr;


	// assign new record to hashPtr if it is new
	if (hashPtr[hashKey] == nullptr)
	{
			hashPtr[hashKey] = newRecord;
	}
	else {
		// insert node in the linked list
		NodeType *current = hashPtr[hashKey];
		while (current->next!=nullptr)
		{
			current = current->next;
		}
		current->next = newRecord;
	}
}


//**************************************************************************
// Function:	search(RecType record)
// Purpose:		traverse through the linkedlist and return a pointer to student ID
// Returns:		searchedRecord
//**************************************************************************
StudentHT::RecType StudentHT::search(RecType record)
{
	numIDSearched++;
	int hashKey = hashFunction(record.id);
	RecType *searchedRecord = new RecType;

	// return a pointer to student ID if exists, -1 if not
	if (hashPtr[hashKey]!=nullptr)
	{
		NodeType *current = hashPtr[hashKey];
		// copy current record to searched record
		while (current!=nullptr)
		{
			numNodeSearched++;
			if (current->id == record.id)	
			{
				searchedRecord->id = current->id;
				searchedRecord->recFirstName = current->nodeFirstName;
				searchedRecord->recLastName = current->nodeLastName;
				return *searchedRecord;
			}
			current = current->next;
		}
	}
	// return -1 if not found
	searchedRecord->id = -1;
	return *searchedRecord;
}

//**************************************************************************
// Function:	startStatistics()
// Purpose:		Initialize stats variables
// Returns:		Nothing
//**************************************************************************
	void StudentHT::startStatistics()
	{
		numIDSearched = 0;
		numNodeSearched = 0;
		avgNodeSearched = 0;
	}

//**************************************************************************
// Function:	endStatistics()
// Purpose:		Calculate average searches
// Returns:		Nothing
//**************************************************************************
	void StudentHT::endStatistics()
	{
		avgNodeSearched = (double)numNodeSearched / numIDSearched;
	}

	//display statistics
	void StudentHT::displayStatistics()
	{
			cout << "================================================================================" << "\n";
			cout << "Total number of ID's searched : " << numIDSearched << "\n";
			cout << "Total number of nodes searched : " << numNodeSearched << "\n";
			cout << "Average number of nodes search per id searched : " << avgNodeSearched << "\n";
			cout << "================================================================================" << "\n";
	}