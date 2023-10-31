/*
*************************************************************************
 Title: Recursion
                                                                        
 Author: Kyle Drewes
                    
 Date: 11/18/2022
 
 Description: This program is designed to produce a series of algorithms
 which all iteration and recursion.  The four algorithms include:
 
 1) Counting Inversion
 2) Larger on the Left Algorithm
 3) Larger_Left_Right Algorithm
 4) Increasing Sequences
 
 Overall, I think I did quite well on this project.  My only challenge was
 setting up the test cases.  Please view my Files folder if you would
 like to look over the test cases.  I also will make sure to include the
 instructions for each of these algorithms in case anyone has any questions.
 
 Thank you
 *********************************************************************
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include "Algorithms.hpp"

using namespace std;

/* Function prototypes */
bool read_inputs(vector<int>& numbers, string filename);
void run_tests(string filename);

// Unit Test used to count inversions
void test1();

// Unit Test used for largest left
void test2();

// Unit Test used for larger left right
void test3();

// Unit Test used for Increased Sequences
void test4();

std::vector<int>CreateVector(std::string fileName);

void Print(std::vector<int>& Results, std::ofstream &write);

int main()
{
    test1();
    test2();
    test3();
    test4();
    
    return 0;
}
/*
 * read_inputs(vector<int>&, char*)
 *
 * Pass it the filename as a C-string and a vector to populate with
 * the numbers in that file (which should be separated by whitespace)
 *
 * This vector should be empty prior to calling this function
 *
 * Returns true if it was able to read at least one number into the
 * vector, else false
 */
bool read_inputs(vector<int>& numbers, string filename) {
    assert(numbers.empty()); // vector should be empty before call
    ifstream inFile(filename);
    int currentNumber;
    inFile >> currentNumber;
    while (inFile.good() && !(inFile.eof())) {
        numbers.push_back(currentNumber);
        inFile >> currentNumber;
    }
    // Return true if at least 1 number was read from input file,
    // else false
    return (numbers.size() > 0);
}
/*
 * Run_tests
 * Given a filename, call your functions and run unit tests
 *
 * You'll probably want to change this function to pass it
 * the desired outputs for each input file
 */
void run_tests(string inputfile) {
    vector<int> inputs, result;
    bool failureFlag = false;
    if (!read_inputs(inputs, inputfile)) {
        cerr << "I couldn't read from " << inputfile << endl;
        return;
    }
    cout << "Testing your functions on " << inputfile << endl;
    // Call your test functions here
    
    if (!failureFlag) {
        cout << "All tests passed\n";
    }
}
//-------------------------------------------------------------------------------------------------
std::vector<int>CreateVector(std::string fileName)
{
    std::ifstream read(fileName, std::ios::in);
    
    std::vector <int> Numbers;
    
    // Represents each number in file
    std::string stringNumber = "";
    
    // Determines if there is an error in file
    if(!read)
    {
        std::cerr << "\nFile is unable to open\n";
        exit(1);
    }
    else
        while(getline(read,stringNumber))
            Numbers.push_back(std::stoi(stringNumber));
    
    read.close();
    
    return Numbers;
}
//-------------------------------------------------------------------------------------------------
// Unit Test used to count inversions
void test1()
{
    //Creating file which will contain test results
    std::ofstream write("test-results.txt");
    
    const std::string FileNames[] = {
                                        "test1-1.txt",
                                        "test1-2.txt",
                                        "test1-3.txt",
                                        "test1-4.txt",
                                        "test1-5.txt",
                                    };
    
    //Contains answers for each of the file in FileName
    const int correctAnswers[5] = {3, 12, 4, 0, 7};
    
    //Contains Size of correctAnswers[] array
    std::size_t FileSize = sizeof(correctAnswers)/sizeof(correctAnswers[0]);
    
    for(int i = 0; i < FileSize; i++)
    {
        std::cout << "----------------- " << FileNames[i] << " -----------------\n";
        write << "----------------- " << FileNames[i] << " -----------------\n";
        
        //Read Input Data in Numbers Vector
        std::vector<int>Numbers = CreateVector(FileNames[i]);
        
        //Return amount of inversions through iteration function
        int iterative_inversions = count_inversions_iterative(Numbers);
        
        //Return amount of inversions through Recursion function
        int recursive_inversions = count_inversions_recursive(Numbers);
        
        //Display Results
        std::cout << "\n\ncount_inversions_iterative(Numbers) = " << iterative_inversions;
        std::cout << "\n\ncount_inversions_recursive(Numbers) = " << recursive_inversions;
        std::cout << "\n\nCorrect Answer: " << correctAnswers[i] << std::endl;
        
        //Display Results in file
        write << "\n\ncount_inversions_iterative(Numbers) = " << iterative_inversions;
        write << "\n\ncount_inversions_recursive(Numbers) = " << recursive_inversions;
        write << "\n\nCorrect Answer: " << correctAnswers[i] << std::endl;
        
        //Input Validation
        assert((iterative_inversions == recursive_inversions) && iterative_inversions == correctAnswers[i]);
        
        //Output
        std::cout << "\nTest for " << FileNames[i] << " has successfully passed.\n\n\n";
        write << "\nTest for " << FileNames[i] << " has successfully passed.\n\n\n";

    }
    
    write.close();
    
    
}
// Unit Test used for largest left
void test2()
{

    //Contains Collections of all test files for problem 2
    const std::string Test_Files[] = {"test2-1.txt",
                                      "test2-2.txt",
                                      "test2-3.txt",
                                      "test2-4.txt",
                                      "test2-5.txt",
                                      "test2-6.txt",
                                      "test2-7.txt"};
    
    const std::string Result_Files[] = {"test2-1_results.txt",
                                        "test2-2_results.txt",
                                        "test2-3_results.txt",
                                        "test2-4_results.txt",
                                        "test2-5_results.txt",
                                        "test2-6_results.txt",
                                        "test2-7_results.txt"};
    
    std::size_t FileSize = sizeof(Test_Files) / sizeof(Test_Files[0]);
    
    //Creating file which will contain test results for test 1 - 3
    std::ofstream write("test-results.txt", std::ios::app);
    
    for(int i = 0; i < FileSize; i++)
    {
        
        std::cout << "----------------- " << Test_Files[i] << " -----------------\n";
        write << "----------------- " << Test_Files[i] << " -----------------\n";
        
        std::vector<int>Numbers = CreateVector(Test_Files[i]);   // Reads input data from file to Numbers Vector
        
        std::vector<int>Results = CreateVector(Result_Files[i]); // Reads output (actual results) data from file to Results Vector
        
        std::vector<int> Iterative_Results,                       // Collects the output from largest_left_iterative to Iterative_Result
        
                         Recursive_Results;                       // Collects the output from largest_left_iterative to Recursive_Result
        
        largest_left_iterative(Numbers,Iterative_Results);        // Calls iterative function which implements algorithms and collects output
        
        largest_left_recursive(Numbers,Recursive_Results);        // Calls recursive function which implements algorithms and collects output
        
        
        //Print Input
        std::cout << "\nPrint Input from " << Test_Files[i] << ": ";
        write << "\nPrint Input from " << Test_Files[i] << ": ";
        Print(Numbers,write);
        
        //Print Input generated by Iterative_Results
        std::cout << "\n\nPrint output from iterative function: ";
        write << "\nPrint output from iterative function: ";
        Print(Iterative_Results,write);
        
        //Print Input generated by Recursive_Results
        std::cout << "\n\nPrint output from recursive function: ";
        write << "\nPrint output from iterative function: ";
        Print(Recursive_Results,write);
        
        //Input Validation
        assert((Iterative_Results == Results) && (Recursive_Results == Results));
        
        //Output Message
        std::cout << "\nTest for " << Test_Files[i] << " has successfully passed.\n\n\n";
        write << "\nTest for " << Test_Files[i] << " has successfully passed.\n\n\n";
        
    }
    
    write.close();
    
    
}
//-------------------------------------------------------------------------------------------------
// Unit Test used for larger left right
void test3()
{

    //Contains Collections of all test files for problem 3
    const std::string Test_Files[] = {"test3-1.txt",
                                      "test3-2.txt",
                                      "test3-3.txt",
                                      "test3-4.txt",
                                      "test3-5.txt",
                                      "test3-6.txt",
                                      "test3-7.txt"
                                      "test3-8.txt"};
                                      
    
    const std::string Result_Files[] = {"test3-1_results.txt",
                                        "test3-2_results.txt",
                                        "test3-3_results.txt",
                                        "test3-4_results.txt",
                                        "test3-5_results.txt",
                                        "test3-6_results.txt",
                                        "test3-7_results.txt"
                                        "test3-8_results.txt"};
    
    std::size_t FileSize = sizeof(Test_Files) / sizeof(Test_Files[0]);
    
    //Creating file which will contain test results for test 1 - 3
    std::ofstream write("test-results.txt", std::ios::app);
    
    for(int i = 0; i < FileSize; i++)
    {
        
        std::cout << "----------------- " << Test_Files[i] << " -----------------\n";
        write << "----------------- " << Test_Files[i] << " -----------------\n";
        
        std::vector<int>Numbers = CreateVector(Test_Files[i]);   // Reads input data from file to Numbers Vector
        
        std::vector<int>Results = CreateVector(Result_Files[i]); // Reads output (actual results) data from file to Results Vector
        
        std::vector<int> Iterative_Results,                       // Collects the output from largest_left_iterative to Iterative_Result
        
                         Recursive_Results;                       // Collects the output from largest_left_iterative to Recursive_Result
        
        larger_left_right_iterative(Numbers,Iterative_Results);   // Calls iterative function which implements algorithm and collects input
        
        larger_left_right_recursive(Numbers,Recursive_Results,0);   // Calls recursive function which implements algorithms and collects output
        
        //Print Input
        std::cout << "\nPrint Input from " << Test_Files[i] << ": ";
        write << "\nPrint Input from " << Test_Files[i] << ": ";
        Print(Numbers,write);
        
        //Print Input generated by Iterative_Results
        std::cout << "\n\nPrint output from iterative function: ";
        write << "\nPrint output from iterative function: ";
        Print(Iterative_Results,write);
        
        //Print Input generated by Recursive_Results
        std::cout << "\n\nPrint output from recursive function: ";
        write << "\nPrint output from iterative function: ";
        Print(Recursive_Results,write);
        
        //Input Validation
        assert((Iterative_Results == Results) && (Recursive_Results == Results));
        
        std::cout << "\nTest for " << Test_Files[i] << " has successfully passed.\n\n\n";
        write << "\nTest for " << Test_Files[i] << " has successfully passed.\n\n\n";
    }
    
    write.close();
    
}
//-------------------------------------------------------------------------------------------------
//Unit Test Used for Increased Sequences
void test4()
{
    
    //Creating file which will contain test results
    std::ofstream write("test-results.txt");
    
    //List of file we
    const std::string FileNames[] = {
                                        "Problem4_Test.txt",
                                        "Problem4_Test2.txt",
                                        "Problem4_Test3.txt",
                                        "Problem4_Test4.txt",
                                    };
    
    //Contains correct answer for each file in FileName[]
    const int correctAnswers[4] = {4, 4, 2,3};
    
    //Size of correctAnswers Array
    std::size_t FileSize = sizeof(correctAnswers)/sizeof(correctAnswers[0]);
    
    for(int i = 0; i < FileSize; i++)
    {
        std::cout << "----------------- " << FileNames[i] << " -----------------\n";
        write << "----------------- " << FileNames[i] << " -----------------\n";
        
        //Read Input Data in Numbers Vector
        std::vector<int>Numbers = CreateVector(FileNames[i]);
        
        //Return amount of increased sequences through iteration function
        int iterative_increased_sequences = increasing_sequences_iterative(Numbers);
        
        //Return amount of increased sequences through Recursion function
        int recursive_increased_sequences = increasing_sequences_recursive(Numbers);
        
        //Display Results
        std::cout << "\n\ncount_inversions_iterative(Numbers) = " << iterative_increased_sequences;
        std::cout << "\n\ncount_inversions_recursive(Numbers) = " << recursive_increased_sequences;
        std::cout << "\n\nCorrect Answer: " << correctAnswers[i] << std::endl;
        
        //Display Results in file
        write << "\n\ncount_inversions_iterative(Numbers) = " << iterative_increased_sequences;
        write << "\n\ncount_inversions_recursive(Numbers) = " << recursive_increased_sequences;
        write << "\n\nCorrect Answer: " << correctAnswers[i] << std::endl;
        
        //Input Validation
        assert((iterative_increased_sequences == recursive_increased_sequences) && iterative_increased_sequences == correctAnswers[i]);
        
        //Output
        std::cout << "\nTest for " << FileNames[i] << " has successfully passed.\n\n\n";
        write << "\nTest for " << FileNames[i] << " has successfully passed.\n\n\n";

    }
    
    write.close();
    
    
}
//-------------------------------------------------------------------------------------------------
void Print(std::vector<int>& Results, std::ofstream &write)
{
    for(std::vector<int> :: size_type i = 0; i < Results.size(); i++)
        std::cout << Results[i] << ' ';
    
    std::cout << std::endl;
}
//-------------------------------------------------------------------------------------------------
