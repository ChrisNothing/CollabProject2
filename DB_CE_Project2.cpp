//-------------------------------------------------------------------------------------------------
//DOCUMENTATION BLOCK
// 
//Course:      CST 202
//Exercise:    Project 2
//Programmers: David Bremer & Chris Ellenberger
// 
//Source File Contains:
//  Main driver function for the current exercise.
//  Additional functions for the current exercise.
// 
//Inputs:
//  [TBD]
// 
//Outputs:
//  [TBD]
// 
//-------------------------------------------------------------------------------------------------

#include "Standards.h"

//-------------------------------------------------------------------------------------------------
// Global Constant Definitions
//-------------------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------------
// Global Variable Definitions
//-------------------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------------
// User-Defined Function Prototypes
//-------------------------------------------------------------------------------------------------

void getInput(string startingWord, string endingWord);

void radixSort(vector<string>& arr);

//-------------------------------------------------------------------------------------------------
// Main Function
//-------------------------------------------------------------------------------------------------

int main(void)
{

    //---------------------------------------------------------------------------------------------
    // Variable Definitions
    //---------------------------------------------------------------------------------------------

    //TEST: Vector of arrays to text the radix sort.
    vector<string> arr{ "FUNNY", "BRIDE", "BRUTE", "KIND", "SHIRT", "AID", "FOUR", "TAIL" };

    //---------------------------------------------------------------------------------------------
    // Opening Statements
    //---------------------------------------------------------------------------------------------

    //Print the standard course heading to the screen.
    PrintHeading(cout, 100, "CST 202 - Project 2");

    //TEST: Print the original vector.
    for (const auto& element : arr) { cout << element << " "; }
    cout << endl;

    //TEST: Radix sort the test vector.
    radixSort(arr);

    //TEST: Print the sorted vector.
    for (const auto& element : arr) { cout << element << " "; }
    cout << endl;

	return 0;

}

//-------------------------------------------------------------------------------------------------
// User-Defined Function Definitions
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Function - getInput
// 
// Get a starting word and an ending word from the user, checking for matching lengths.
//-------------------------------------------------------------------------------------------------
void getInput(string startingWord, string endingWord)
{

    //Do loop to execute until the two words are the same length.
    do
    {



    } while (startingWord.length() != endingWord.length());

}

//-------------------------------------------------------------------------------------------------
// Function - radixSort
// 
// Sort the passed-in array using a radix sorting algorithm (modified from provided code sample).
//-------------------------------------------------------------------------------------------------
void radixSort(vector<string>& arr)
{

    //If statement to determine if the vector of words is empty.
    if (arr.empty())
    {

        //Return control immediately in the event there is nothing to sort.
        return;

    }

    //Declare and initialize a variable to store the length of the longest word.
    size_t max_length = 0;

    //For loop to pass through the entire vector of words.
    for (const string& str : arr)
    {

        //If the current word is longer than the recorded max length, update the max length.
        //NOTE: Although the compiler regocnizes the max function (presumably from #include
        //      <vector>), Microsoft Copilot recommends using #include <algorithm> as well,
        //      to protect against future updates that may change which headers bring in max.
        //      Therefore, we have, even though it is not currently necessary to do this.
        max_length = max(max_length, str.length());

    }

    //For loop to pass through each character from right to left of the words in the vector.
    for (int digit = static_cast<int>(max_length) - 1; digit >= 0; digit--)
    {

        //Buckets in this case must store the 26 capital letters instead of the 10 numeric digits.
        //NOTE: We technically only need 27 buckets (one for the null character and 26 for each
        //      of the capital letters. However, the null character is not contiguous with the
        //      capital letters in ASCII order. To eliminate the need for additional logic for
        //      conversion, buckets are created for all characters between null and capital Z.
        vector<queue<string>> queues(133);

        //For loop to pass through the entire vector of words.
        for (string& str : arr)
        {

            //Decision structure to determine if the character position is valid. If it is, the
            //character at that position is saved. If not, the null character is assigned. This
            //ensures that order is preserved even when dealing with strings of different length.
            //NOTE: This line throws warning C4018 during building, but vanishes on completion.
            char char_val = (digit < str.length()) ? str[digit] : '\n';

            //Pushes the current string into the bucket corresponding to the current character.
            queues[static_cast<unsigned char>(char_val)].push(str);

        }

        //Declare and initialize a variable to store the index of the vector position.
        int index = 0;

        //For loop to pass through each bucket in ASCII order.
        for (auto& queue : queues)
        {

            //While loop to execute while the current queue is not empty.
            while (!queue.empty())
            {

                //Copy the top word in the current bucket to the next vector position.
                //Also update the index for the next word to be copied to.
                arr[index++] = queue.front();

                //Pop the top word out of the current bucket.
                queue.pop();

            }

        }

    }

}