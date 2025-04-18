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

#include <algorithm>
#include <cmath>
#include <conio.h>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

//-------------------------------------------------------------------------------------------------
// Function Prototypes
//-------------------------------------------------------------------------------------------------

void PrintDivider(ostream& outFile, int numberOfSymbols, char symbol);

void PrintCenteredMessage(ostream& outFile, int width, string message);

void PrintHeading(ostream& outFile, int width, string courseAndExercise);

#endif
