//-------------------------------------------------------------------------------------------------
//DOCUMENTATION BLOCK
// 
//Course:      CST 202
//Exercise:    
//Programmers: David Bremer & Chris Ellenberger
// 
//Header File Contains:
//  Standard includes, namespace, and function prototypes for coursework.
//-------------------------------------------------------------------------------------------------

#pragma once

#ifndef Standards_h
#define Standards_h

#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <string>

using namespace std;

//-------------------------------------------------------------------------------------------------
// Function Prototypes
//-------------------------------------------------------------------------------------------------

void PrintDivider(ostream& outFile, int numberOfSymbols, char symbol);

void PrintCenteredMessage(ostream& outFile, int width, string message);

void PrintHeading(ostream& outFile, int width, string courseAndExercise);

#endif
