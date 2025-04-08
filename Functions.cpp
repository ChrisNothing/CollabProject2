//-------------------------------------------------------------------------------------------------
//DOCUMENTATION BLOCK
// 
//Course:      CST 202
//Exercise:    Project 2
//Programmers: David Bremer & Chris Ellenberger
// 
//Source File Contains:
//	Multi-line member functions for Class "Functions".
//-------------------------------------------------------------------------------------------------

#include "Functions.h"

//-------------------------------------------------------------------------------------------------
// Member Functions
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Function - getInput
// 
// Get a starting word and an ending word from the user, checking for matching lengths.
//-------------------------------------------------------------------------------------------------
void Functions::getInput(string& startingWord, string& endingWord)
{

    //Do loop to execute until the two words are the same length.
    do
    {

        //Do loop to execute until the first word is of valid format.
        do
        {

            //Query the user for the starting word.
            cout << "Please enter the starting word in ALL CAPS with no special characters: ";
            getline(cin, startingWord, '\n');
            cout << endl;

            //If statement to check if the word is invalid.
            if (isAllCaps(startingWord) == false)
            {

                //Output a warning and prompt to retry.
                cout << "The word must be in ALL CAPS with no special characters. Try again.";
                cout << endl;

            }

        } while (isAllCaps(startingWord) == false);

        //Do loop to execute until the second word is of valid format.
        do
        {

            //Query the user for the ending word.
            cout << "Please enter the ending word in ALL CAPS with no special characters:   ";
            getline(cin, endingWord, '\n');
            cout << endl;

            //If statement to check if the word is invalid.
            if (isAllCaps(endingWord) == false)
            {

                //Output a warning and prompt to retry.
                cout << "The word must be in ALL CAPS with no special characters. Try again.";
                cout << endl;

            }

        } while (isAllCaps(endingWord) == false);

        //If statement to check if both words are the same length.
        if (startingWord.length() != endingWord.length())
        {

            //Output a warning and prompt to retry.
            cout << "The two words must be of the exact same length. Try again.";
            cout << endl;

        }

    } while (startingWord.length() != endingWord.length());

}

//-------------------------------------------------------------------------------------------------
// Function - radixSort
// 
// Sort the passed-in array using a radix sorting algorithm (modified from provided code sample).
//-------------------------------------------------------------------------------------------------
void Functions::radixSort(vector<string>& arr)
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
            char char_val = (unsigned(digit) < str.length()) ? str[digit] : '\n';

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

//-------------------------------------------------------------------------------------------------
// Function - isAllCaps
// 
// Check if the passed-in word consists entirely of capital letters and returns true if it does.
//-------------------------------------------------------------------------------------------------
bool Functions::isAllCaps(string wordToCheck)
{

    for (int i = 0; unsigned(i) < wordToCheck.length(); i++)
    {

        if ((wordToCheck[i] < 65) || (wordToCheck[i] > 90))
        {

            return false;

        }

    }

    return true;

}