//-------------------------------------------------------------------------------------------------
//DOCUMENTATION BLOCK
// 
//Course:      CST 202
//Exercise:    Project 2
//Programmers: David Bremer
// 
//Header File Contains:
//  Class Definition for Class "bremerdw_testclass".
//-------------------------------------------------------------------------------------------------

#pragma once

#ifndef bremerdw_testclass_h
#define bremerdw_testclass_h

#include "Standards.h"
#include "Functions.h"

//-------------------------------------------------------------------------------------------------
// Class Definition
//-------------------------------------------------------------------------------------------------

class bremerdw_testclass
{

public:

    //---------------------------------------------------------------------------------------------
    // Class Test Methods
    //---------------------------------------------------------------------------------------------

    bool bremerdw_Test_radixSort(void);
    bool bremerdw_Test_isAllCaps(void);
    bool bremerdw_Test_isValidWord(void);
    bool bremerdw_Test_removeDuplicateWords(void);

    bool bremerdw_RunAllTests(void);

};

#endif