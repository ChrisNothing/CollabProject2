# CollabProject2

/**************************************************************************************************

---------------------------------------------------------------------------------------------------
Task 1 - Started 2025-04-01, Functionally Completed 2025-04-01, Improved As Needed
---------------------------------------------------------------------------------------------------
Chris: Created the GitHub repository and shared access to David and Prof. Zwolinsky. This README
       file will be used to track the work done by each group member and when it was completed.

David: Created the C++ project via "using existing code" option to link to the repository, and
       pushed this initial project to GitHub after adding some standard functions and includes.
       It seems the better process is to create the repo in Visual Studio and push from there.

---------------------------------------------------------------------------------------------------
Task 2 - Started 2025-04-03, Functionally Completed 2025-04-03, Improved As Needed
---------------------------------------------------------------------------------------------------
Chris: Followed and copied down the example radix sort function for integers while David spent the
       lecture setting up the project files within the repository.

David: Implemented a radix sort of strings by copying over the class example, modifying it using
       Microsoft Copilot, and further editing it to account for the fact that only the 26 capital
       letters are expected for this project. Formatted and commented the code as needed as well.

---------------------------------------------------------------------------------------------------
Task 3 - Started 2025-04-08, Functionally Completed 2025-04-10, Improved As Needed
---------------------------------------------------------------------------------------------------

Chris: Developed the initial function code and test for removing duplicate words from a list of
       words and returning the truncated vector.

David: Retrofitted Chris's function and test to fit within the established project framework,
       making sure to preserve Chris's variable names and choice of coding operations. This
       function needed pretty significant changes in order to partition out the test.

---------------------------------------------------------------------------------------------------
Task 4 - Started 2025-04-09, Functionally Completed 2025-04-11, Improved As Needed
---------------------------------------------------------------------------------------------------

Chris: Developed the initial function code and test for obtaining a vector of valid single-letter
       transformations of a word given an initial word and a list of possible words.

David: Retrofitted Chris's function and test to fit within the established project framework,
       making sure to preserve Chris's variable names and choice of coding operations. This
       function needed only minor changes, mainly to work with capitals and unordered sets.

---------------------------------------------------------------------------------------------------
Task 5 - Started 2025-04-11, Functionally Completed 2025-04-14, Improved As Needed
---------------------------------------------------------------------------------------------------

Chris: Wrote the intermediate function for finding descendant words, which is critical for the
       operation of the word ladder solver function. Additionally provided debugging support
       during the coding process.

David: Developed the initial word ladder solver code using Chris's descendant words function, in
       addition to help from Copilot to determine how to manipulate the stack without causing an
       overflow error. Preliminary testing shows the solutions found are not optimal.

---------------------------------------------------------------------------------------------------
Extras - Started 2025-04-15, Functionally Completed 2025-04-15, Improved As Needed
---------------------------------------------------------------------------------------------------

Chris: Wrote the necessary methods to implement both required functions to complete the Extra
       Credit tasks, including implementation into the main project branch. The program now works
       from beginning to end, giving what we believe to be the optimal solution.

David: Slightly modified the output appearance to be more concise. Commented and formatted where
       needed. Cleaned up program flow to only use the optimal solution case (David's initial
       sub-optimal solution function therefore goes unused). Marked all unused functions.

---------------------------------------------------------------------------------------------------
Other Miscellaneous Tasks Not Included In The Above Sections
---------------------------------------------------------------------------------------------------

Chris: Developed the main operative function that executes the user-facing operations.
       Implemented a loop system to allow the user to play again within the same program instance.

David: General management of files and directory structure.
       Completed the function for reading input from the user.
       Implemented functions for checking the validity of user input.
       Took and uploaded the requested screenshot of program execution.
       Removed test/temporary files from the main branch, as per the project directions.

---------------------------------------------------------------------------------------------------
Missing Features Or Potential Bugs
---------------------------------------------------------------------------------------------------
> There is no catch for if the user enters the same word twice. The program does execute, printing
  a path of length 1 consisting only of the entered word, but an input validation would be useful.

> There is no catch for if a path is never found. We have not been able to find an example where
  this happens, and given the completeness of the given dictionary, such examples seem unlikely.

> We had some trouble determining what the "proper" way to implement tests was for the project.
  Both of us made test branches in GitHub, and the tests are not present in the main branch. We
  hope this is acceptable for now, and hope to learn more about the "proper" way in the future.

**************************************************************************************************/
