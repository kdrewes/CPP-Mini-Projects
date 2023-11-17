/*
 *************************************************************************
 
 Title: String Problem
 
 Author: Kyle Drewes
 
 Date: 11/15/2023
 
 Description: In this problem you are given 3 strings x, y and z.
 Your objective is to determine if string x and y
 would equate to having the same exact characters as
 string z.
 
 ------------------------------------------------------
 Example 1:
 
 Input:
 x = "abac" y = "bcaa" z = caaacbba
 
 Output:
 True
 
 Explanation:
 If you combine string x and string y, there are 4 a's,
 2 b's and 2 c's.  In string z, it contains the
 same exact characters.  Therefore, the outcome is
 true.
 
 ------------------------------------------------------
 
 Example 2:
 
 Input:
 x = "zjs" y = "zjs" z = zjjss
 
 Output:
 False
 
 Explanation:
 If you combine string x and string y, there are 2 z's,
 2 j's and 2's.  However, string z only contains 1 z,
 2 j's and 2's.  Therefore, it is not a match so the
 outcome is false.
 ------------------------------------------------------
 
 **********************************************************************/

#include <iostream>
#include <map>

// -------------------------------------------------------------------
// Customized library

// Create library for my own customizable commands
namespace command
{
void space(int n)
{
    for(int i = 0; i < n; i++)
        std::cout << std::endl;
}
};

// ---------------------------- Prototype ----------------------------

// Used to determine if string z is identical to string x and y combined
bool isIdentical(std::string x, std::string y, std::string z);

// -------------------------------------------------------------------

int main(int argc, const char * argv[]) {
    
    // Declare string values
    std::string x = "abac",
    y = "bcaa",
    z = "caaacbba";
    
    isIdentical(x,y,z)
    ? std::cout << x << " and " << y << " are identical to " << z << std::endl
    : std::cout << x << " and " << y << " are not identical to " << z << std::endl;
    command::space(2);
    
    return 0;
}
// -------------------------------------------------------------------
// Used to determine if string z is identical to string x and y combined
bool isIdentical(std::string x, std::string y, std::string z)
{
    // Change names of datatypes for organizational purposes
    typedef int index;
    typedef char characters;
    typedef bool boolean;
    
    // Used to reference the indexes of string z
    std::map<index,characters> Indexed_Character;
    
    // Used to determine if there is a match between x/y and z
    boolean isMatch = true;
    
    // Initialize keys and values of Index_Reference_Of_Z
    for(int i = 0; i < z.size(); i++)
        Indexed_Character[i] = ' ';
    
    // Determine if characters of x match charaacters of z
    for(int i = 0; (i < x.size() && isMatch); i++)
    {
        isMatch = false;
        
        for(int j = 0; j < z.size(); j++)
        {
            if(x[i] == z[j])
            {
                if(Indexed_Character[j] != x[i])
                {
                    Indexed_Character[j] = x[i];
                    isMatch = true;
                    break;
                }
            }
        }
    }
    
    if(!isMatch)
        return false;
    
    // Determine if characters of y match charaacters of z
    for(int i = 0; (i < y.size() && isMatch); i++)
    {
        isMatch = false;
        
        for(int j = 0; j < z.size(); j++)
        {
            if(y[i] == z[j])
            {
                if(Indexed_Character[j] != y[i])
                {
                    Indexed_Character[j] = y[i];
                    isMatch = true;
                    break;
                }
            }
        }
    }
    
    if(!isMatch)
        return false;
    
    return true;
}
// -------------------------------------------------------------------
