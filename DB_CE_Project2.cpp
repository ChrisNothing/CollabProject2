//-------------------------------------------------------------------------------------------------
//DOCUMENTATION BLOCK
// 
//Course:      CST 202
//Exercise:    Project 2
//Programmers: David Bremer & Chris Ellenberger
// 
//Source File Contains:
//  Main driver function for the current exercise.
// 
//Inputs:
//  [TBD]
// 
//Outputs:
//  [TBD]
// 
//-------------------------------------------------------------------------------------------------

#include "Standards.h"
#include "Functions.h"

#include "bremerdw_testclass.h"

//-------------------------------------------------------------------------------------------------
// Main Function
//-------------------------------------------------------------------------------------------------

int main(void)
{

    //---------------------------------------------------------------------------------------------
    // Variable Declaration
    //---------------------------------------------------------------------------------------------

    string startingWord;
    string endingWord;

    vector<string> wordLadderPath;

    Functions funcObject;

    //---------------------------------------------------------------------------------------------
    // Test Execution
    //---------------------------------------------------------------------------------------------

    //Instantiate objects of the test classes.
    bremerdw_testclass bremerdw_tests;

    //Execute tests of all functions, and exit execution in the event of a failed test.
    if (bremerdw_tests.bremerdw_RunAllTests() == false)
    {

        return -1;

    }

    //---------------------------------------------------------------------------------------------
    // Opening Statements
    //---------------------------------------------------------------------------------------------

    //Print the standard course heading to the screen.
    PrintHeading(cout, 100, "CST 202 - Project 2");

    //---------------------------------------------------------------------------------------------
    // Project Exercise Body
    //---------------------------------------------------------------------------------------------

    //Get two words as input from the user.
    funcObject.getInput(startingWord, endingWord);

    //Find a valid word ladder for the two words.
    wordLadderPath = funcObject.solveWordLadder(startingWord, endingWord);

    //Print the path that was found.
    funcObject.printWordLadder(wordLadderPath);

    //---------------------------------------------------------------------------------------------
    // Closing Statements
    //---------------------------------------------------------------------------------------------

    return 0;

}