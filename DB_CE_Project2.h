//-------------------------------------------------------------------------------------------------
//DOCUMENTATION BLOCK
// 
//Course:      CST 202
//Exercise:    Project 2
//Programmers: David Bremer & Chris Ellenberger
// 
//Header File Contains:
//  Necessary for calling functions in the main .cpp file from within test classes.
//-------------------------------------------------------------------------------------------------

#pragma once

#ifndef DB_CE_Project2_h
#define DB_CE_Project2_h

#include "Standards.h"

//-------------------------------------------------------------------------------------------------
// User-Defined Function Prototypes
//-------------------------------------------------------------------------------------------------

void getInput(string& startingWord, string& endingWord);

void radixSort(vector<string>& arr);

bool isAllCaps(string wordToCheck);

#endif