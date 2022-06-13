#include <iostream>
#include <vector>
#include <algorithm>
const int SIZE = 24;

struct Highscore
{
    //Used to record the score of the user
    int score;
    
    //Used to store the name of each user
    char name[SIZE];
};
//----------------------------------------------------
//Prototypes
void readData(std::vector<Highscore>& scores);
void sortData(std::vector<Highscore>& scores);
void displayData(const std::vector<Highscore>& scores);
std::vector<Highscore>::iterator findLocationOfLargest(
const std::vector<Highscore>::iterator startingLocation,
const std::vector<Highscore>::iterator endingLocation);
int Size();
//----------------------------------------------------
namespace command
{
    void space(std::size_t size)
    {
        for(size_t i = 0; i < size; i++)
            std::cout << std::endl;
    }
}
//----------------------------------------------------
int main()
{
    int size = Size();
    
    std::vector<Highscore>Score(size);
    
    readData(Score);
    sortData(Score);
    
    std::vector<Highscore>::iterator startingLocation = Score.begin();
    std::vector<Highscore>::iterator endingLocation = Score.end();
    std::vector<Highscore>:: iterator Highest =
    findLocationOfLargest(startingLocation,endingLocation);
    displayData(Score);
    
    std::cout << "Highest score " << Highest->score;
    command::space(2);
    return 0;
}
//----------------------------------------------------
//Prompts user for data
void readData(std::vector<Highscore>& scores)
{
    
    std::vector<Highscore>::iterator it = scores.begin();
    
    int count = 0;
    
    for(it = scores.begin(); it != scores.end(); it++)
    {
       
        std::cout << "\nEnter the name for score #" << count + 1<< ": ";
        std::cin.ignore();
        std::cin >> it->name;
       
        std::cout << "Enter the score for score #" << count + 1<< ": ";
        std::cin >> it->score;
        
        count += 1;
    }
}
//----------------------------------------------------
//Uses Selection Sort algorithm to sort the data with iterators.
void sortData(std::vector <Highscore> &scores)
{
    std::vector<Highscore> :: iterator i = scores.begin();
    std::vector<Highscore> :: iterator it = scores.begin();
    std::vector<Highscore> :: iterator it2 = scores.begin();
    
    for(i = scores.begin(); i != scores.end()-1; i++)
    {
        it = i;
        
        for (it2 = scores.begin() + 1; it2 != scores.end(); it2++)
        if(it2->score < it->score)
        it = it2;
        std::swap(i->score,it->score);
        std::swap(i->name,it->name);
    }
    
}
//----------------------------------------------------
//Displays results
void displayData(const std::vector<Highscore>& scores)
{
    command:command::space(1);
    std::cout << "Top Scorers:\n";
    for(auto it = scores.crbegin(); it != scores.crend(); it++)
        std::cout << it->name << ": " << it->score << std::endl;
        command::space(1);
}
//----------------------------------------------------
//Determines how many users will be included
int Size()
{
    int size;
    std::cout << "Enter Number of scores: ";
    std::cin >> size;
    return size;
}
//----------------------------------------------------
//Determines the highest score of the user.  This is done through the use of iterators.
std::vector<Highscore>::iterator findLocationOfLargest(
                                const std::vector<Highscore>::iterator startingLocation,
                                const std::vector<Highscore>::iterator endingLocation)
{
     
    std::vector<Highscore> :: iterator HighestIterator;
    std::vector<Highscore> :: iterator it = startingLocation;
       int High = INT_MIN;
       while (it != endingLocation)
       {
            if (it->score > High)
            {
                High = it->score;
                HighestIterator = it;
            }
           it++;
       }
           return HighestIterator;
}
