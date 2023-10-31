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
#ifndef Algorithms_hpp
#define Algorithms_hpp

#include <stdio.h>
#include<iostream>
#include <climits>
#include<vector>

// ------------------------------  Count Inversions -----------------------------

// Iterative Count Inversion Function
int count_inversions_iterative( const std::vector<int>& Numbers);

// Recursive Count Inversion Function
int count_inversions_recursive( const std::vector<int>& Numbers);

// ----------------------------- larger to the Left ----------------------------

// Iterative Largest Left Function
void largest_left_iterative(const std::vector<int>& Numberes, std::vector<int>& Result);

// Recursive Largest Left Function
void largest_left_recursive(const std::vector<int>& Numbers, std::vector<int>& Result);

// ----------------------------- Larger_Left_Right -----------------------------

// Iterative Larger_Left_Right Function
void larger_left_right_iterative(const std::vector<int>& Numbers, std::vector<int>& Results);

// Recursive Larger_Left_Right Function
void larger_left_right_recursive(const std::vector<int>& Numbers, std::vector<int>& Result, int i);

// ----------------------------- Increasing Sequences --------------------------

//Iterative Increasing Sequences Function
int increasing_sequences_iterative(std::vector<int> &Numbers);

//Recursive Increasing Sequences Function
int increasing_sequences_recursive(std::vector<int> &Numbers);

#endif
