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

 *********************************************************************
 */

#include<vector>
#include<fstream>
#include<iostream>
#include<climits>
#include "Algorithms.hpp"

// ----------------------------------  Count Inversions ----------------------------------

//Count Inverations iterated helper function
int count_inversions_iterative_helper( const std::vector<int>& Numbers, int n);

//Count Inverations recursive helper function
int count_inversions_recursive_helper( const std::vector<int>& Numbers, int count, int n);

// --------------------------------- larger to the Left ----------------------------------

//Larger to the left recursive helper function
void largest_left_recursive_helper(const std::vector<int>&Numbers, std::vector<int>&Result, int i, int size);

// ---------------------------------- Larger_Left_Right ----------------------------------

//Larger to the left_right iterated helper function, used for the double for loop that decrements to the left
int larger_left_right_iterative_leftHelper(const std::vector<int>& numbers, int i);

//Larger to the left_right iterated helper function, used for the double for loop that increments to the right
int larger_left_right_iterative_rightHelper(const std::vector<int>& numbers, int i);

//Larger to the left_right recursive helper function
int larger_left_right_recursive_helper(const std::vector<int> Numbers, int number, int index, bool isLeft);

// --------------------------------- Increasing Sequences ---------------------------------

//Increasing Sequencesrecursive helper function
int increasing_sequences_recursive_helper(const std::vector<int>& numbers, int startIdx, int count, int maxNumber);

// -----------------------------------------------------------------------------------------

//Count Inverations iterative function
int count_inversions_iterative( const std::vector<int>& Numbers )
{
   return count_inversions_iterative_helper(Numbers,Numbers.size());
}

//------------------------------------------------------------------------------------------

//Count Inverations iterative helper function
int count_inversions_iterative_helper(const std::vector<int>& Numbers, int n)
{
    int count = 0;
    
    for(std::vector<int> :: size_type i = 0; i < n-1; i++)
        if(Numbers[i] > Numbers[i + 1])
            ++count;
    
    return count;
}

//------------------------------------------------------------------------------------------

//Count Inverations recursive function
int count_inversions_recursive( const std::vector<int>& Numbers )
{
    int count = 0;
    return count_inversions_recursive_helper(Numbers,count,Numbers.size());
}

//------------------------------------------------------------------------------------------

//Count Inverations iterative helper function
int count_inversions_recursive_helper(const std::vector<int>& Numbers, int count, int n)
{
    if(n <= 1)
        return count;
    
    if(Numbers[n - 2] > Numbers[n - 1])
        ++count;

    return count_inversions_recursive_helper(Numbers,count,--n);
}

//------------------------------------------------------------------------------------------

// Iterative Largest Left function
void largest_left_iterative(const std::vector<int>& Numbers, std::vector<int>& Results)
{
    int previous_subscript = Numbers[0];
    Results.push_back(0);
    
    for(std::vector<int> :: size_type i = 1; i < Numbers.size(); i++)
    {
        if((previous_subscript > Numbers[i]) && (Numbers[i-1] < Numbers[i]))
        {
            Results.push_back(previous_subscript);
            previous_subscript = Results[i];
        }
        else if((previous_subscript > Numbers[i]) && (Numbers[i-1] > Numbers[i]))
        {
            Results.push_back(Numbers[i-1]);
            previous_subscript = Results[i];
        }
        else
        {
            previous_subscript = Numbers[i];
            Results.push_back(0);

        }
    }
}

//------------------------------------------------------------------------------------------

// Recursive Largest Left function
void largest_left_recursive(const std::vector<int>& Numbers, std::vector<int>& Results)
{
    largest_left_recursive_helper(Numbers,Results,0,Numbers.size());
}

//------------------------------------------------------------------------------------------

// Recursive Largest Left helper function
void largest_left_recursive_helper(const std::vector<int>& Numbers, std::vector<int>& Results, int i, int size)
{
    static int previous_subscript = 0;
    
    if(i >= size)
        return;
    
    if(i == 0)
    {
        Results.push_back(0);
        previous_subscript = Numbers[i];
    }
    else
    {
        if((previous_subscript > Numbers[i]) && (Numbers[i-1] < Numbers[i]))
        {
            Results.push_back(previous_subscript);
            previous_subscript = Results[i];
        }
        else if((previous_subscript > Numbers[i]) && (Numbers[i-1] > Numbers[i]))
        {
            Results.push_back(Numbers[i-1]);
            previous_subscript = Results[i];
        }
        else
        {
            previous_subscript = Numbers[i];
            Results.push_back(0);

        }
    }
    
    largest_left_recursive_helper(Numbers,Results,++i,size);
}

//------------------------------------------------------------------------------------------

// Iterative Larger_Left_Right Function
void larger_left_right_iterative(const std::vector<int>& Numbers, std::vector<int>& Result)
{
    int left = 0,
        right = 0;
    
    for(std::vector<int> :: size_type i = 0; i < Numbers.size(); i++)
    {
        
        if(i != 0)
            left = larger_left_right_iterative_leftHelper(Numbers,i);
        
        
        if(i != Numbers.size() - 1)
            right = larger_left_right_iterative_rightHelper(Numbers,i);
        
        Result.push_back(std::max(left,right));
        
        left = 0;
        right = 0;
        
    }
}

//------------------------------------------------------------------------------------------

//Larger to the left_right iterated helper function, used for the double for loop that decrements to the left
int larger_left_right_iterative_leftHelper(const std::vector<int>& Numbers, int i)
{
    int maxNumber = 0;
    
    for(int x = i - 1; x > -1; x--)
    {
        if(Numbers[i] < Numbers[x])
        {
            maxNumber = Numbers[x];
            break;
        }
    }

    return maxNumber;
}

//------------------------------------------------------------------------------------------

//Larger to the left_right iterated helper function, used for the double for loop that increments to the right
int larger_left_right_iterative_rightHelper(const std::vector<int>& Numbers, int i)
{
    int maxNumber = 0;
    
    for(int j = i + 1; j < Numbers.size(); j++)
    {
        if(Numbers[i] < Numbers[j])
        {
            maxNumber = Numbers[j];
            break;
        }
    }
    
    return maxNumber;
}

//------------------------------------------------------------------------------------------

//Larger to the left_right recursive function
void larger_left_right_recursive(const std::vector<int>& Numbers, std::vector<int>& Result, int i)
{
    
    if(i == Numbers.size() || Numbers.size() == 0)
    {
        return;
    }

    int left = larger_left_right_recursive_helper(Numbers, Numbers[i], i, true);
    int right = larger_left_right_recursive_helper(Numbers, Numbers[i], i, false);

    int maxNumber = std::max(left,right);

    if(Numbers[i] > maxNumber)
        Result.push_back(0);
    
    else
        Result.push_back(maxNumber);

    ++i;
    larger_left_right_recursive(Numbers, Result, i);
}

//------------------------------------------------------------------------------------------

//Larger to the left_right recursive helper function
int larger_left_right_recursive_helper(const std::vector<int> Numbers, int number, int index, bool isLeft)
{
    if(isLeft)
    {
        if((index-1) < 0)
            return 0;
        else
        {
            if( Numbers[index-1] > number)
                return Numbers[index-1];

            else
                return larger_left_right_recursive_helper(Numbers, number, --index, isLeft);
        }
    }
    else
    {
        if((index+1) > Numbers.size())
            return 0;
        else
        {
            if( Numbers[index+1] > number)
                return Numbers[index+1];
            else
                return larger_left_right_recursive_helper(Numbers, number, ++index, isLeft);
            
        }
    }
}

//------------------------------------------------------------------------------------------

//Iterative Increasing Sequences Function
int increasing_sequences_iterative(std::vector<int> &Numbers)
{
    int maxNumber = INT_MIN,
        count = 0;
    
    for(std::vector<int> :: size_type i = 0; i < Numbers.size(); i++)
    {
        if(Numbers[i] <= Numbers[i + 1])
            ++count;
        else
            count = 1;
        
        maxNumber = std::max(count,maxNumber);
    }
    
    return maxNumber;
}

//------------------------------------------------------------------------------------------

//Recursive Increasing Sequences function
int increasing_sequences_recursive(std::vector<int> &Numbers)
{
    return increasing_sequences_recursive_helper(Numbers,0,0,0);
}

//------------------------------------------------------------------------------------------

//Recursive Increasing Sequences helper function
int increasing_sequences_recursive_helper(const std::vector<int>& Numbers, int startIdx, int count, int maxNumber)
{
    
    if(startIdx >= Numbers.size())
        return maxNumber;
    
    if(Numbers[startIdx] <= Numbers[startIdx + 1])
        ++count;
    else
        count = 1;
    
    maxNumber = std::max(count,maxNumber);
    
    return increasing_sequences_recursive_helper(Numbers,++startIdx,count,maxNumber);
}

//------------------------------------------------------------------------------------------
