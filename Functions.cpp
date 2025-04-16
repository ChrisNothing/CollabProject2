//-------------------------------------------------------------------------------------------------
//DOCUMENTATION BLOCK
// 
//Course:      CST 202
//Exercise:    Project 2
//Programmers: David Bremer & Chris Elleneberger
// 
//Source File Contains:
//	Multi-line member functions for Class "Functions".
//-------------------------------------------------------------------------------------------------

#include "Functions.h"

//-------------------------------------------------------------------------------------------------
// Member Functions
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Function - BY DAVID - getInput
// 
// Get a starting word and an ending word from the user, checking for matching lengths.
//-------------------------------------------------------------------------------------------------
void Functions::getInput(string& startingWord, string& endingWord)
{

    //Print the standard course heading to the screen.
    PrintHeading(cout, SCREEN_WIDTH, "CST 202 - Project 2");

    //Output instructions to the user.
    cout << "This program simulates the game Word Ladder. Given a starting word and an" << endl;
    cout << "ending word, a sequence of single-letter transformations from the starting" << endl;
    cout << "word to the ending word will be produced, where the intermediate steps will" << endl;
    cout << "also be real words. For this program, two words of the same length, between" << endl;
    cout << "three and five letters in length, are accepted. Have fun!" << endl << endl;

    //Do loop to execute until the two words are the same length.
    do
    {

        //Do loop to execute until the first word is of valid format and a real word.
        do
        {

            //Query the user for the starting word.
            cout << "Please enter the starting word in ALL CAPS with no special characters: ";
            getline(cin, startingWord, '\n');
            cout << endl;

            //If statement to check if the word format is invalid.
            if (isAllCaps(startingWord) == false)
            {

                //Output a warning and prompt to retry.
                cout << "The word must be in ALL CAPS with no special characters. Try again.";
                cout << endl << endl;

            }
            //If the first check is passed, now check if the word is a real word.
            else if (isValidWord(startingWord) == false)
            {

                //Output a warning and prompt to retry.
                cout << "That word is not a real word, or is otherwise unsupported. Try again.";
                cout << endl << endl;

            }

        } while (isAllCaps(startingWord) == false || isValidWord(startingWord) == false);

        //Do loop to execute until the second word is of valid format and a real word.
        do
        {

            //Query the user for the ending word.
            cout << "Please enter the ending word in ALL CAPS with no special characters:   ";
            getline(cin, endingWord, '\n');
            cout << endl;

            //If statement to check if the word format is invalid.
            if (isAllCaps(endingWord) == false)
            {

                //Output a warning and prompt to retry.
                cout << "The word must be in ALL CAPS with no special characters. Try again.";
                cout << endl << endl;

            }
            //If the first check is passed, now check if the word is a real word.
            else if (isValidWord(endingWord) == false)
            {

                //Output a warning and prompt to retry.
                cout << "That word is not a real word, or is otherwise unsupported. Try again.";
                cout << endl << endl;

            }

        } while (isAllCaps(endingWord) == false || isValidWord(endingWord) == false);

        //If statement to check if both words are the same length.
        if (startingWord.length() != endingWord.length())
        {

            //Output a warning and prompt to retry.
            cout << "The two words must be of the exact same length. Try again.";
            cout << endl << endl;

        }

    } while (startingWord.length() != endingWord.length());

}

//-------------------------------------------------------------------------------------------------
// Function - BY DAVID - radixSort
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

} // UNUSED IN FINAL DELIVERABLE

//-------------------------------------------------------------------------------------------------
// Function - BY DAVID - isAllCaps
// 
// Check if the passed-in word consists entirely of capital letters and return true if it does.
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

//-------------------------------------------------------------------------------------------------
// Function - BY DAVID - isValidWord
// 
// Check if the passed-in word exists within the dictionary file and return true if it does.
//-------------------------------------------------------------------------------------------------
bool Functions::isValidWord(string wordToCheck)
{

    string currentWord;

    fstream inFile;

    //Open the dictionary file.
    inFile.open(DICTIONARY_FILE_NAME);

    //Do loop to pass through the entire file.
    do
    {

        //Get the next word from the input file.
        getline(inFile, currentWord, '\n');

        //If statement to check if the grabbed word equals the word being checked.
        if (currentWord == wordToCheck)
        {

            //Close the dictionary file.
            inFile.close();

            //If a match is found, return true.
            return true;

        }

    } while (inFile);

    //Close the dictionary file.
    inFile.close();

    //If a match was never found, return false.
    return false;

}

//-------------------------------------------------------------------------------------------------
// Function - BY DAVID - getWordList
// 
// Extract each word in the dictionary of the specified length and return a set of such words.
//-------------------------------------------------------------------------------------------------
unordered_set<string> Functions::getWordList(int numberOfDigits)
{

    string currentWord;

    fstream inFile;

    unordered_set<string> wordList;

    //Open the dictionary file.
    inFile.open(DICTIONARY_FILE_NAME);

    //If statement to check if the file was opened successfully.
    if (inFile.is_open() == false)
    {

        //Throw a runtime error (Copilot suggested this over returning an empty list).
        throw runtime_error("The dictionary file could not be opened.");

    }

    //Do loop to pass through the entire file.
    while (getline(inFile, currentWord, '\n'))
    {

        //If statement to check if the grabbed word exists and is of the desired length.
        if (currentWord.empty() == false && currentWord.length() == numberOfDigits)
        {

            //If the word is of the desired length, add it to the word list.
            wordList.insert(currentWord);

        }

    }
    
    //Close the dictionary file.
    inFile.close();

    //Return the word list.
    return wordList;

}

//-------------------------------------------------------------------------------------------------
// Function - BY CHRIS - removeDuplicateWords
// 
// Remove any duplicate words from a vector of strings and return the truncated vector.
//-------------------------------------------------------------------------------------------------
vector<string> Functions::removeDuplicateWords(vector<string> inputList)
{

    int startIndex = 0;

    string nameOne;
    string nameTwo;

    vector<string> outputList = inputList;

    //If statement to check if the vector is not empty or single-element.
    if (outputList.size() != 0 && outputList.size() != 1)
    {

        //For loop to pass through each word in the list.
        for (string word : outputList)
        {

            //Extract the current word to be checked against.
            nameOne = word;

            //Increment the start index for checking subsequent words.
            startIndex++;

            //For loop to pass through every word in the vector after the word being checked against.
            for (size_t counterForLoop = startIndex; counterForLoop < outputList.size(); counterForLoop++)
            {

                //Extract the current word being compared.
                nameTwo = outputList[counterForLoop];

                //If statement to check if a match was found.
                if (nameOne == nameTwo)
                {

                    //Remove the found match from the list.
                    outputList.erase(outputList.begin() + counterForLoop);

                    //Decrement the inner loop counter to compensate for this removal.
                    counterForLoop--;

                }

            }

        }

    }

    return outputList;

} // UNUSED IN FINAL DELIVERABLE

//-------------------------------------------------------------------------------------------------
// Function - BY CHRIS - getDescendantWords
// 
// Find any words that differ from the passed-in word within the passed in set, and return them.
//-------------------------------------------------------------------------------------------------
vector<string> Functions::getDescendantWords(const string& word, const unordered_set<string>& wordList)
{

    vector<string> validWords;

    // Iterate through each position of the word
    for (size_t counterForLoop = 0; counterForLoop < word.length(); counterForLoop++)
    {

        // Try replacing the character at position counterForLoop with all letters from 'A' to 'Z'
        for (char charMajor = 'A'; charMajor <= 'Z'; charMajor++)
        {

            if (charMajor == word[counterForLoop])
            {

                continue; // Skip the character if it's the same as the current one

            }

            // Create a new word by replacing the character at position counterForLoop
            string transformed = word;
            transformed[counterForLoop] = charMajor;

            // Check if the transformed word exists in the wordList
            if (wordList.find(transformed) != wordList.end())
            {

                //Chatgpt gave me (Chris) this nice little function. Need to ask if this is okay.
                validWords.push_back(transformed);

            }

        }

    }

    return validWords;

}

//-------------------------------------------------------------------------------------------------
// Function - BY DAVID - solveWordLadder
// 
// Generate a path from the starting word to the ending word using single-letter transformations.
//-------------------------------------------------------------------------------------------------
vector<string> Functions::solveWordLadder(string startingWord, string endingWord)
{

    //Output a message to the screen that this process could take several seconds.
    cout << "This process may take several seconds. Please wait..." << endl << endl;

    //Initialize an unordered set to hold the list of words.
    unordered_set<string> wordList;

    //Use the getWordList function to obtain a list of valid words using the length of the
    //starting word (by the time this function is called, both words are equal length).
    wordList = getWordList(startingWord.length());

    //Initialize a stack to store the assorted paths that will be generated.
    stack<vector<string>> wordLadderPaths;

    //Initialize a vector to store the current path being worked on.
    vector<string> currentPath;

    //Push the starting word into the currently empty path vector.
    currentPath.push_back(startingWord);

    //Push the unfinished path into the stack of possible paths.
    wordLadderPaths.push(currentPath);

    //While loop to execute while the stack of paths is not empty.
    while (wordLadderPaths.empty() == false)
    {

        //Variable to store the final word in the current path.
        string finalWord;

        //Get the top path from the stack to be manipulated in this step.
        currentPath = wordLadderPaths.top();

        //Pop the top path from the stack as it has now been copied to a variable.
        wordLadderPaths.pop();

        //Get the last word from the current path for comparison.
        finalWord = currentPath.back();

        //If statement to check if the last word in the current path is the desired ending word.
        if (finalWord == endingWord)
        {

            //If so, the current path is successful and can be returned immediately.
            return currentPath;

        }

        //Initialize a vector to store all descendant words of the final word.
        vector<string> descendantWords;

        //Use the getDescendantWords function to obtain all valid single-letter transformations.
        descendantWords = getDescendantWords(finalWord, wordList);

        //For loop to pass through all the found descendant words (if no descendants are found,
        //currentPath "dies" since this loop is skipped and no descendant paths are pushed back onto the stack).
        for (string nextWord : descendantWords)
        {

            //Initialize a vector to store the path with the next word added.
            vector<string> newPath;

            //Copy the current path into the vector to store the continued path.
            newPath = currentPath;

            //Add the new descendant word to the new path.
            newPath.push_back(nextWord);

            //Push this new path onto the stack of possible paths.
            wordLadderPaths.push(newPath);

            //Remove the word that was just added from the local words list to prevent possible backwards traversal.
            wordList.erase(nextWord);

        }

    }

    //If no valid path ends up being found, return a null vector.
    return { };

} // UNUSED IN FINAL DELIVERABLE

//-------------------------------------------------------------------------------------------------
// Function - BY CHRIS - solveWordLadderOptimal
// 
// Generate a path from the starting word to the ending word using single-letter transformations.
//-------------------------------------------------------------------------------------------------
vector<string> Functions::solveWordLadderOptimal(string startingWord, string endingWord)
{

    //Output a message to the screen that this process could take several seconds.
    cout << "This process may take several seconds. Please wait..." << endl << endl;

    // If start and end are the same, return immediately
    if (startingWord == endingWord)
    {
        return { startingWord };
    }

    // Get the dictionary of words of the correct length
    unordered_set<string> wordList = getWordList(startingWord.length());

    // Quick check to make sure both words are in the dictionary
    if (wordList.find(startingWord) == wordList.end() || wordList.find(endingWord) == wordList.end())
    {
        return {};
    }

    // Queue for BFS; stores the current path
    queue<vector<string>> paths;
    paths.push({ startingWord });

    // Track visited words to avoid cycles
    unordered_set<string> visited;
    visited.insert(startingWord);

    while (!paths.empty())
    {
        int levelSize = paths.size(); // For layer-wise BFS
        unordered_set<string> levelVisited; // Track only for this layer to allow multiple paths to same word in layer

        for (int counterForLoop = 0; counterForLoop < levelSize; ++counterForLoop)
        {
            vector<string> path = paths.front();
            paths.pop();

            string currentWord = path.back();
            vector<string> neighbors = getDescendantWords(currentWord, wordList);

            for (string& neighbor : neighbors)
            {
                if (visited.find(neighbor) != visited.end())
                {
                    continue;
                }

                vector<string> newPath = path;
                newPath.push_back(neighbor);

                if (neighbor == endingWord)
                {
                    return newPath;
                }

                paths.push(newPath);
                levelVisited.insert(neighbor);
            }
        }

        // Add all words visited at this BFS layer to global visited set
        visited.insert(levelVisited.begin(), levelVisited.end());
    }

    // If we get here, no path was found
    return {};
}

//-------------------------------------------------------------------------------------------------
// Function - BY D & C - printWordLadder
// 
// Output the passed-in word ladder to the screen, in order with one word per line.
//-------------------------------------------------------------------------------------------------
void Functions::printWordLadder(vector<string> wordLadderPath)
{

    //For loop to pass through every word in the path.
    for (size_t counterForLoop = 0; counterForLoop < wordLadderPath.size(); ++counterForLoop)
    {

        //If statement to check if the current word is the second one in the path or later.
        if (counterForLoop > 0)
        {

            string prev = wordLadderPath[counterForLoop - 1];
            string curr = wordLadderPath[counterForLoop];

            //For loop to pass through every letter in the previous and current words.
            for (size_t forCounterLoop = 0; forCounterLoop < curr.length(); ++forCounterLoop)
            {

                //If statement to check if the two current letters are not the same.
                if (prev[forCounterLoop] != curr[forCounterLoop])
                {

                    //Output a marker denoting the changed letter.
                    cout << setw(forCounterLoop) << "" << "|" << setw(5 - forCounterLoop) << "";
                    cout << "{ " << prev[forCounterLoop] << " -> " << curr[forCounterLoop] << " }" << endl;

                    //Output the current word.
                    cout << wordLadderPath[counterForLoop] << endl;
                    
                    // Only one letter changes per step, so we can break early.
                    break; 

                }
            }

        }
        //Otherwise, the first word is being printed.
        else
        {

            //Output the first word and nothing else.
            cout << wordLadderPath[counterForLoop] << endl;

        }
    }
}

//-------------------------------------------------------------------------------------------------
// Function - BY D & C - executeProgram
// 
// The main operative function for all inputs and outputs of program execution.
//-------------------------------------------------------------------------------------------------
void Functions::executeProgram()
{

    string startingWord;
    string endingWord;
    string endChoice;

    vector<string> wordLadderPath;

    // Main loop to continue prompting the user for new word ladders
    do 
    {

        //Get two words as input from the user.
        getInput(startingWord, endingWord);

        //Find a valid word ladder for the two words.
        wordLadderPath = solveWordLadderOptimal(startingWord, endingWord);

        //Print the path that was found and its length.
        cout << "One possible optimal path between these two words is as follows:" << endl;
        PrintDivider(cout, SCREEN_WIDTH, '-');
        printWordLadder(wordLadderPath);
        PrintDivider(cout, SCREEN_WIDTH, '-');
        cout << "Any possible optimal path is completed in exactly " << wordLadderPath.size() << " steps." << endl;

        //Prompt the user with the option to try another word ladder or end the program.
        cout << endl;
        cout << "Please type Y and press Enter to play again, or anything else to end: ";
        cin >> endChoice;

        //If statement to check the user input to see if the program should end.
        if (endChoice != "Y" && endChoice != "y")
        {

            //If the user wishes to end, break the loop.
            break;

        }
        else
        {

            //Clear the screen for the next game to reduce clutter.
            system("cls");

            //Clear the input buffer.
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        }

    } while (true);

}