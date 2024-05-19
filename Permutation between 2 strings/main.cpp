#include <iostream>
#include <map>
#include <set>

class PermutationClass
{
private:
    
    // Declare sum variable
    int sum;
    
    // Declare vector used to collect index sum of each character
    std::vector<int>collectValues;
    
    // Declare map used to correspond each character to map
    std::map<char,std::pair<int,int>>permutation_map;
    
    // Declare pair used to collect both incdeces
    std::pair<int,int> indexPair;
    
    
public:
    // Constructor
    PermutationClass();
    
    // Methods
    void Method1(std::string, std::string);
    void Method2(std::string, std::string);
    
    // Return sums
    int ReturnSum();
    
};

// ------------------------------------------------------------------------------------------------
// Constructor
PermutationClass :: PermutationClass()
{
    
    collectValues.clear();
    permutation_map.clear();
    this -> sum = 0;
    
}
// ------------------------------------------------------------------------------------------------
void PermutationClass :: Method1(std::string str, std::string str2)
{
    
    // Traverse through strings to determine permutation
    for(int i = 0; i < str.size(); i++)
    {
        for(int j = 0; j < str2.size(); j++)
        {
            if(j != i && str[i] == str2[j])
            {
                // Perform mathematical calucation
                this -> collectValues.push_back(abs(i - j));
                break;
            }
        }
    }
    
    // Traverse through collectValues vector
    for(std::vector<int> :: size_type i = 0; i < collectValues.size(); i++)
        this -> sum += this -> collectValues[i];
    
    // Reset values
    this -> collectValues.clear();
    
}
// ------------------------------------------------------------------------------------------------
// Implement Method 2
void PermutationClass :: Method2(std::string str, std::string str2)
{
    // Collect characters from str
    for(int i = 0; i < str.size(); i++)
        this -> permutation_map[str[i]] = {i,-1};
    
    // Collect characters from str2
    for(int i = 0; i < str2.size(); i++)
        if(permutation_map.find(str2[i]) != permutation_map.end())
            permutation_map[str2[i]].second = i;
    
    // Perform mathematical calucation
    for(const auto & pm : permutation_map)
        this -> collectValues.push_back(abs(pm.second.second - pm.second.first));
    
        // Traverse through collectValues vector
        for(std::vector<int> :: size_type i = 0; i < collectValues.size(); i++)
            this -> sum += this -> collectValues[i];
    
    // Reset values
    this -> collectValues.clear();
}
// ------------------------------------------------------------------------------------------------
// Return Sum
int PermutationClass :: ReturnSum()
{
    int s = this -> sum;
    this -> sum = 0;
    return s;
}
// ------------------------------------------------------------------------------------------------
int main(int argc, const char * argv[]) {
    
    // Instantial object
    PermutationClass perm;
    
    // Execute method
    perm.Method1("abc","bac");
    int sum = perm.ReturnSum();
    
    // Display Sum
    std::cout << "Sum for method1: " << sum << std::endl;
    
    perm.Method2("abcde","edbac");
    sum = perm.ReturnSum();
    
    // Display Sum
    std::cout << "Sum for method2: " << sum << std::endl;
    
    return 0;
}
