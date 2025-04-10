//-------------------------------------------------------------------------------------------------
//DOCUMENTATION BLOCK
// 
//Course:      CST 202
//Exercise:    Project 2
//Programmers: David Bremer & Chris Ellenberger
// 
//Header File Contains:
//  Class Definition for Class "Functions".
//-------------------------------------------------------------------------------------------------

#pragma once

#ifndef Functions_h
#define Functions_h

#include "Standards.h"

//-------------------------------------------------------------------------------------------------
// Constant Declaration
//-------------------------------------------------------------------------------------------------

const string DICTIONARY_FILE_NAME = "dictionary345.txt";

//-------------------------------------------------------------------------------------------------
// Class Definition
//-------------------------------------------------------------------------------------------------

class Functions
{

public:

	//---------------------------------------------------------------------------------------------
	// Other Public Methods
	//---------------------------------------------------------------------------------------------

	void getInput(string& startingWord, string& endingWord);

	void radixSort(vector<string>& arr);

	bool isAllCaps(string wordToCheck);

	bool isValidWord(string wordToCheck);

	unordered_set<string> getWordList(int numberOfDigits);

	vector<string> removeDuplicateWords(vector<string> inputList);

};

#endif