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

    funcObject.mistakesWereMade();

    //---------------------------------------------------------------------------------------------
    // Closing Statements
    //---------------------------------------------------------------------------------------------

    return 0;

}