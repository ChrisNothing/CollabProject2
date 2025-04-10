//-------------------------------------------------------------------------------------------------
//DOCUMENTATION BLOCK
// 
//Course:      CST 202
//Exercise:    
//Programmers: David Bremer & Chris Ellenberger
// 
//Source File Contains:
//	Standard function definitions for coursework.
//-------------------------------------------------------------------------------------------------

#include "Standards.h"

//-------------------------------------------------------------------------------------------------
// Constant Definitions
//-------------------------------------------------------------------------------------------------

//Our names, used in course header output.
const string PROGRAMMER_A = "David Bremer";
const string PROGRAMMER_B = "Chris Ellenberger";

//-------------------------------------------------------------------------------------------------
// Function Definitions
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Function - PrintDivider
// 
// Output to the destination the specified symbol the number of times specified by numberOfSymbols.
//-------------------------------------------------------------------------------------------------
void PrintDivider(ostream& outFile, int numberOfSymbols, char symbol)
{

	//Outputs a single divider line to the destination. The type-casts ensure no warnings.
	outFile << setfill(symbol) << setw(int(double(numberOfSymbols) + 1)) << ' ' << setfill(' ');
	outFile << endl;

}

//-------------------------------------------------------------------------------------------------
// Function - PrintCenteredMessage
// 
// Output to the destination the specified message centered on the specified number of characters.
//-------------------------------------------------------------------------------------------------
void PrintCenteredMessage(ostream& outFile, int width, string message)
{

	int centerWidth;

	//Output the message to the destination, centered.
	centerWidth = static_cast<int>((width + message.length()) / 2);
	outFile << setw(centerWidth) << message << endl;

}

//-------------------------------------------------------------------------------------------------
// Function - PrintHeading
// 
// Output to the specified destination the standard course heading.
//-------------------------------------------------------------------------------------------------
void PrintHeading(ostream& outFile, int width, string courseAndExercise)
{

	const string COLLEGE = "SUNY Broome Community College";
	const string NAME = PROGRAMMER_A + " & " + PROGRAMMER_B;

	//Output single divider line to the destination.
	PrintDivider(outFile, width, '-');

	//Output college name to the destination, centered.
	PrintCenteredMessage(outFile, width, COLLEGE);

	//Output name to the destination, centered.
	PrintCenteredMessage(outFile, width, NAME);

	//Output course and exercise number to the destination, centered.
	PrintCenteredMessage(outFile, width, courseAndExercise);

	//Output single divider line to the destination.
	PrintDivider(outFile, width, '-');

	//Output a line break to the destination.
	outFile << endl;

}