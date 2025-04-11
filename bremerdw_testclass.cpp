//-------------------------------------------------------------------------------------------------
//DOCUMENTATION BLOCK
// 
//Course:      CST 202
//Exercise:    Project 2
//Programmers: David Bremer
// 
//Source File Contains:
//	Multi-line member functions for Class "bremerdw_testclass".
//-------------------------------------------------------------------------------------------------

#include "bremerdw_testclass.h"

//-------------------------------------------------------------------------------------------------
// Member Functions
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Function - bremerdw_Test_radixSort
// 
// Method for testing function "radixSort".
//-------------------------------------------------------------------------------------------------
bool bremerdw_testclass::bremerdw_Test_radixSort(void)
{

	vector<string> arrOld{ "FUNNY", "BRIDE", "BRUTE", "KIND", "SHIRT", "AID", "FOUR", "TAIL" };
	vector<string> arrNew{ "AID", "BRIDE", "BRUTE", "FOUR", "FUNNY", "KIND", "SHIRT", "TAIL" };

	Functions testObject;

	testObject.radixSort(arrOld);

	if (arrOld == arrNew)
	{

		return true;

	}

	return false;

}

//-------------------------------------------------------------------------------------------------
// Function - bremerdw_Test_isAllCaps
// 
// Method for testing function "isAllCaps".
//-------------------------------------------------------------------------------------------------
bool bremerdw_testclass::bremerdw_Test_isAllCaps(void)
{

	string testString1 = "Test";
	string testString2 = "TEST";
	string testString3 = "TEST ";

	Functions testObject;

	if ((testObject.isAllCaps(testString1) == false) &&
		(testObject.isAllCaps(testString2) == true) &&
		(testObject.isAllCaps(testString3) == false))
	{

		return true;

	}

	return false;

}

//-------------------------------------------------------------------------------------------------
// Function - bremerdw_Test_isValidWord
// 
// Method for testing function "isValidWord".
//-------------------------------------------------------------------------------------------------
bool bremerdw_testclass::bremerdw_Test_isValidWord(void)
{

	string testString1 = "QUIRK";
	string testString2 = "FLARP";

	Functions testObject;

	if ((testObject.isValidWord(testString1) == true) &&
		(testObject.isValidWord(testString2) == false))
	{

		return true;

	}

	return false;

}

//-------------------------------------------------------------------------------------------------
// Function - bremerdw_Test_removeDuplicateWords
// 
// Method for testing function "removeDuplicateWords".
//-------------------------------------------------------------------------------------------------
bool bremerdw_testclass::bremerdw_Test_removeDuplicateWords(void)
{

	vector<string> nameOne = { "ForRt", "ForTh", "ForTo", "ForFi", "ForFo", "ForSe", "For", "ForEi", "ForNi", "For" };
	vector<string> nameTwo = { "ForRt", "ForTh", "ForTo", "ForFi", "ForFo", "ForSe", "For", "ForEi", "ForNi" };
	vector<string> nameFin;

	Functions testObject;

	nameFin = testObject.removeDuplicateWords(nameOne);

	if (nameFin == nameTwo)
	{

		return true;

	}

	return false;

}

//-------------------------------------------------------------------------------------------------
// Function - bremerdw_Test_getDescendantWords
// 
// Method for testing function "getDescendantWords".
//-------------------------------------------------------------------------------------------------
bool bremerdw_testclass::bremerdw_Test_getDescendantWords(void)
{

	string initialWord = "HARE";

	unordered_set<string> wordList = { "FEND", "BEND", "REND", "BARE", "FIRE", "TEAR", "CARE",
		                               "MARE", "LAND", "LENS", "PEND", "SEND", "TEND", "BORE",
		                               "MORE", "SHORE", "FOUR", "POUR", "SORE", "CORE", "ROPE",
		                               "HOPE", "KOPE", "VOTE", "NOTE", "WORE", "LAKE", "FAKE",
		                               "CAKE", "MINT", "HINT", "LINK", "TANK", "MASK", "BARK",
		                               "PARK", "WARP", "CART", "DART", "STAR", "CHAR" };

	vector<string> expectedResult = {"BARE", "CARE", "MARE"};
	vector<string> actualResult;

	Functions testObject;

	actualResult = testObject.getDescendantWords(initialWord, wordList);

	if (expectedResult == actualResult)
	{

		return true;

	}

	return false;

}

//-------------------------------------------------------------------------------------------------
// Function - bremerdw_Test_RunAllTests
// 
// Method for running all tests.
//-------------------------------------------------------------------------------------------------
bool bremerdw_testclass::bremerdw_RunAllTests(void)
{

	if (bremerdw_Test_radixSort() == false)
	{

		cout << "The function 'radixSort' failed its test." << endl;

	}

	if (bremerdw_Test_isAllCaps() == false)
	{

		cout << "The function 'isAllCaps' failed its test." << endl;

	}

	if (bremerdw_Test_isValidWord() == false)
	{

		cout << "The function 'isValidWord' failed its test." << endl;

	}

	if (bremerdw_Test_removeDuplicateWords() == false)
	{

		cout << "The function 'removeDuplicateWords' failed its test." << endl;

	}

	if (bremerdw_Test_getDescendantWords() == false)
	{

		cout << "The function 'getDescendantWords' failed its test." << endl;

	}

	if ((bremerdw_Test_radixSort() == false) ||
		(bremerdw_Test_isAllCaps() == false) ||
		(bremerdw_Test_isValidWord() == false) ||
		(bremerdw_Test_removeDuplicateWords() == false) ||
		(bremerdw_Test_getDescendantWords() == false))
	{

		return false;

	}

	return true;

}