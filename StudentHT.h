#include <string>

// declare StudentHT class
class StudentHT
{
	public:

	//**************************************************************************
	// Function: RecType(Structure)
	// Purpose:  Structure for RecType
	//**************************************************************************
	struct RecType
	{
		int id;
		std::string recFirstName;
		std::string recLastName;
	};


	//**************************************************************************
	// Function: RecType(Structure)
	// Purpose:  Structure for NodeType
	//**************************************************************************
	struct NodeType{
		int id;
		std::string nodeFirstName;
		std::string nodeLastName;
		NodeType *next;
	};


	struct NodeType **hashPtr;	// instance variable pointing to hash table array of pointers
	

	//**************************************************************************
	//	Statistics Variables
	//**************************************************************************
  int tableSize;									// size of the hash table
  int numNodeSearched;						// total number of id’s searched
  int numIDSearched;							// total number of nodes searched
  double avgNodeSearched;							// average number of nodes search per id searched


	//**************************************************************************
	//	Functions
	//**************************************************************************

  StudentHT(int size);						// default constructor
	int hashFunction(int studentID);// hash function
	void insert(RecType record);		// insert function
  RecType search(RecType record);	// search function
  void startStatistics();					// start statistics
  void endStatistics();						// end statistics
  void displayStatistics();				// display statistics
};