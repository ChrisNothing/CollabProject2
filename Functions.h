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

	void mistakesWereMade();

	unordered_set<string> getWordList(int numberOfDigits);

	vector<string> removeDuplicateWords(vector<string> inputList);

	vector<string> getDescendantWords(const string& word, const unordered_set<string>& wordList);

	vector<string> solveWordLadderOptimal(string startingWord, string endingWord);
	vector<string> solveWordLadder(string startingWord, string endingWord);

	void printWordLadder(vector<string> wordLadderPath);

};

#endif