//-------------------------------------------------------------------------------------------------
//DOCUMENTATION BLOCK
// 
//Course:      CST 202
//Exercise:    Project 2
//Programmers: David Bremer
// 
//Source File Contains:
//	Multi-line member functions for Class "bremerdw_testclass"
//-------------------------------------------------------------------------------------------------

#include "Standards.h"

#include "bremerdw_testclass.h"

//-------------------------------------------------------------------------------------------------
// Member Functions
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Function - bremerdw_Test_isAllCaps
// 
// Method for testing function "bremerdw_Test_isAllCaps".
//-------------------------------------------------------------------------------------------------
bool bremerdw_Test_isAllCaps(void)
{

	string testString1 = "Test";
	string testString2 = "TEST";
	string testString3 = "TEST ";

	if ((isAllCaps(testString1) == false) &&
		(isAllCaps(testString2) == true) &&
		(isAllCaps(testString3) == false))
	{

		return true;

	}

	return false;

}

//-------------------------------------------------------------------------------------------------
// Function - bremerdw_Test_isAllCaps
// 
// Method for testing function "bremerdw_Test_isAllCaps".
//-------------------------------------------------------------------------------------------------
void bremerdw_RunAllTests(void)
{

	if (bremerdw_Test_isAllCaps() == false)
	{

		cout << "The function 'isAllCaps' failed its test." << endl;

	}

}