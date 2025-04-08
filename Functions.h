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
// Class Definition
//-------------------------------------------------------------------------------------------------

class Functions
{

public:

	//-------------------------------------------------------------------------------------------------
	// Other Public Methods
	//-------------------------------------------------------------------------------------------------

	void getInput(string& startingWord, string& endingWord);

	void radixSort(vector<string>& arr);

	bool isAllCaps(string wordToCheck);

};

#endif