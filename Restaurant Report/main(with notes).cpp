/**
 Write a program to help a restaurant owner keep track of how many pounds of food each category of diners eats each day during a typical week. There are 3 categories of diners: Kids, Adults and Seniors.

In main create a two-dimensional 3 x 7 array to hold the diners’ data. Each row represents a different diner category and each column represents a different day of the week.
From main call a function to prompt and capture the user input data for each diner category. Validate the input, negative numbers for pounds of food eaten is invalid.
From main call a function to calculate and display the average amount of food eaten per day by all the diners.
From main call a function to display the least amount of food eaten during the week by any one diner category (Display the Diner Category, the least amount of food eaten, and on what day).
From main call a function to display the greatest amount of food eaten during the week by any one diner category. (Display the Diner Category #, the greatest amount of food eaten, and on what day).
Run:
Input Data
Amounts of food (in pounds) eaten each day of the week by each category of diners
 
Kids: 200, 100, 100, 60, 75, 300, 300
 
Adults: 500, 300, 200, 200, 400, 600, 900
 
Seniors: 400, 500, 600, 600, 700, 200, 100
 */

#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

#define DAYS 7
#define CATEGORY 3

//--------------------------------------------------------------------------------------------------
//Enum
enum Category {KIDS,ADULTS,SENIORS} category;
//--------------------------------------------------------------------------------------------------
//Function Prototypes:

//Input Function which allows user to input all necessary data
void Input(long double [CATEGORY][DAYS], const std::string [], const std::string [], std::string []);

//Displays Result
void Print(const std::string []);

//Used for Input Validation
void Verify(long double [CATEGORY][DAYS], const std::string [], int, int);

//Determines if numbers are greater or lesser
bool Compare(long double,long double,bool);

//Determines lowest number in each category
long double GetLowest(long double [1][DAYS], int);

//Determines highest number in each category
long double GetHighest(long double [1][DAYS], int);

//Counts the amount of duplicate numbers if the lowest or highest number contains duplicates.
int GetCount(long double [1][DAYS], long double, int);

//Determines the subscript of each duplicate number
std::vector <int> GetIndex(long double [1][DAYS], long double, int);

//Displays output for each category.  Results are transferred to string document[] (argument for Print)
std::string Output(long double [CATEGORY][DAYS], const std::string [], int, long double);

//--------------------------------------------------------------------------------------------------

//Library
namespace command
{

void space(int size)

{
    std::string temp;
    for(int i = 0; i < size; i++)
        temp += '\n';
   
    std::cout << temp;
}
}
//--------------------------------------------------------------------------------------------------
int main()
{
    //Multidemensional array which contains pounds for 3 different categories and 7 days each
    long double pounds[CATEGORY][DAYS];
    
    //String Array which consists of categories
    const std::string categories [CATEGORY] =
    {"---------- Kids ----------","---------- Adults ----------","---------- Seniors ----------"};
    
    //String Array which consists of days
    const std::string days [DAYS] =
    {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    
    //String array used to store results
    std::string document[CATEGORY];
    
    //Input Function
    Input(pounds,categories,days,document);
    
    //Displays result
    Print(document);
    
    return 0;
}
//--------------------------------------------------------------------------------------------------
//Input Function which allows user to input all necessary data
void Input(long double pounds[CATEGORY][DAYS], const std::string categories[], const std::string days[], std::string document[])
{
    int sum = 0;                                        //Determines sum of pounds per category
    
    std::ostringstream output;                          //Collects all information per category and is then tranferred to document[]
    
    std::divides <long double> average;                 //Determines average [ average = sum/DAYS ]
    
    bool flag;                                          //Used for input validation if an exception occurrs.
    
    for(int i = 0; i < CATEGORY; i++)                   //For loop used for each category
    {
        
        std::cout << categories[i];                     //Display Category for each iteration
        
        output << categories[i] << std::endl;           //Collect data into output
        
        command::space(1);
      
        for(int j = 0; j < DAYS; j++)                   //For loop used for each day
        {
            flag = false;                               //Resets flag
            
            do
            {
                
            try
            {
                Verify(pounds,days,i,j);                 //Used for input validation
                
                flag = true;                             //Determines if information is valid
            }
            catch(long double exception)                 //Catches negative values
            {
               command::space(1);
                
               std::cerr << exception << " is not a valid entry, please re-enter:\n\n";
            }
            catch(std::invalid_argument &exception)      //Catches non numerical data
            {
                std::cerr << exception.what();
                
                std::cin.clear();
                
                std::cin.ignore(1000,'\n');
            }
                
            }while(!flag);                                //Loops if data is negative or non numerical
            
            output << days[j] << ": " << pounds[i][j]     //Collects data through output
            << " Pounds " << std::endl << std::endl;
            
            sum += pounds[i][j]; command::space(1);       //Calculates sum
        }
        
        output << Output(pounds,days,i,average(static_cast<long double>(sum),DAYS));  //Collects output
        
        document[i] = output.str() + '\n';                //Stores output in string document []
        
        output.str("");                                   //Empties data within output.
            
        output.clear();                                   //Clears error flags.
        
        sum = 0;                                          //Resets sum
    }
}
//--------------------------------------------------------------------------------------------------
//Displays Result
void Print(const std::string document [])
{
    for(int i = 0; i < CATEGORY; i++)
        std::cout << document[i];
}
//--------------------------------------------------------------------------------------------------
//Used for Input Validation
void Verify(long double pounds [1][DAYS], const std::string days [], int i, int j)
{
    std::cout << days[j] << ": ";
    std::cin >> pounds[i][j];
    
    if(Compare(pounds[i][j],0,true))
        throw pounds[i][j];

    if(!std::cin)
        throw std::invalid_argument ("\nInvalid entry, please re-enter:\n\n");
}
//--------------------------------------------------------------------------------------------------
//Determines if numbers are greater or lesser
bool Compare(long double number,long double number2,bool flag)
{
        if(flag)
        {
            if(number < number2)
            return true; return false;
        }
    
        else
        {
            if(number > number2)
            return true; return false;
        }
}
//--------------------------------------------------------------------------------------------------
//Determines lowest number in each category
long double GetLowest(long double pounds[1][DAYS],int i)
{
    long double lowest;
    
    lowest = pounds[i][0];
    
    for(int x = 0; x < DAYS; x++)
        if(Compare(lowest,pounds[i][x],false))
            lowest = pounds[i][x];
    
    return lowest;
}
//--------------------------------------------------------------------------------------------------
//Determines highest number in each category
long double GetHighest(long double pounds[1][DAYS],int i)
{
    long double highest;
    
    highest = pounds[i][0];
    
    for(int x = 0; x < DAYS; x++)
        if(Compare(highest,pounds[i][x],true))
            highest = pounds[i][x];
    
    return highest;
}
//--------------------------------------------------------------------------------------------------
//Counts the amount of duplicate numbers if the lowest or highest number contains duplicates.
int GetCount(long double pounds[1][DAYS], long double number, int i)
{
    int count = 0;
    
    for(int x = 0; x < DAYS; x++)
        if(number == pounds[i][x])
            count++;
    
            return count;
}
//--------------------------------------------------------------------------------------------------
//Determines the subscript of each duplicate number.
std::vector <int> GetIndex (long double pounds[1][DAYS], long double number, int i)
{
    std::vector <int> Index;
    
    for(int x = 0; x < DAYS; x++)
        if(number == pounds[i][x])
            Index.push_back(x);
    
            return Index;
}
//--------------------------------------------------------------------------------------------------
//Displays output for each category.  Results are transferred to string document[] (argument for Print)
std::string Output(long double pounds[CATEGORY][DAYS], const std::string days[], int i, long double average)
{
    std::ostringstream output;
    
    std::vector <int> HighIndex = GetIndex(pounds,GetHighest(pounds,i),i),
                      LowIndex = GetIndex(pounds,GetLowest(pounds,i),i);
    
    if(GetCount(pounds,GetLowest(pounds,i),i) == 1)
    output << "\nLowest: " <<  GetLowest(pounds,i)<< " pounds on " << days[LowIndex[0]] << std::endl;
    
    else if(GetCount(pounds,GetLowest(pounds,i),i) == 2)
    output << "\nLowest: " <<  GetLowest(pounds,i)<< " pounds on " << days[LowIndex[0]] << " and " <<  days[LowIndex[1]] << std::endl;
    
    else if(GetCount(pounds,GetLowest(pounds,i),i) == 3)
    output << "\nLowest: " <<  GetLowest(pounds,i)<< " pounds on " << days[LowIndex[0]] << ", " <<  days[LowIndex[1]] << " and " << days[LowIndex[2]] << std::endl;
    
    else if(GetCount(pounds,GetLowest(pounds,i),i) == 4)
    output << "\nLowest: " <<  GetLowest(pounds,i)<< " pounds on " << days[LowIndex[0]] << ", " <<  days[LowIndex[1]] << ", " << days[LowIndex[2]] << " and " << days[LowIndex[3]] << std::endl;
    
    else if(GetCount(pounds,GetLowest(pounds,i),i) == 5)
    output << "\nLowest: " <<  GetLowest(pounds,i)<< " pounds on " << days[LowIndex[0]] << ", " <<  days[LowIndex[1]] << ", " << days[LowIndex[2]] << ", " << days[LowIndex[3]] << " and " <<days[LowIndex[4]] << std::endl;
    
    else if(GetCount(pounds,GetLowest(pounds,i),i) == 6)
    output << "\nLowest: " <<  GetLowest(pounds,i)<< " pounds on " << days[LowIndex[0]] << ", " <<  days[LowIndex[1]] << ", " << days[LowIndex[2]] << ", " << days[LowIndex[3]] << ", " << days[LowIndex[4]] << " and " << days[LowIndex[5]] << std::endl;
    
    
    if(GetCount(pounds,GetHighest(pounds,i),i) == 1)
    output << "\nHighest: " <<  GetHighest(pounds,i)<< " pounds on " << days[HighIndex[0]] << std::endl;
    
    else if(GetCount(pounds,GetHighest(pounds,i),i) == 2)
    output << "\nHighest: " <<  GetHighest(pounds,i)<< " pounds on " << days[HighIndex[0]] << " and " <<  days[HighIndex[1]] << std::endl;
    
    else if(GetCount(pounds,GetHighest(pounds,i),i) == 3)
    output << "\nHighest: " <<  GetHighest(pounds,i)<< " pounds on " << days[HighIndex[0]] << ", " <<  days[HighIndex[1]] << " and " << days[HighIndex[2]] << std::endl;
    
    else if(GetCount(pounds,GetHighest(pounds,i),i) == 4)
    output << "\nHighest: " <<  GetHighest(pounds,i)<< " pounds on " << days[HighIndex[0]] << ", " <<  days[HighIndex[1]] << ", " << days[HighIndex[2]] << " and " << days[HighIndex[3]] << std::endl;
    
    else if(GetCount(pounds,GetHighest(pounds,i),i) == 5)
    output << "\nHighest: " <<  GetHighest(pounds,i)<< " pounds on " << days[HighIndex[0]] << ", " <<  days[HighIndex[1]] << ", " << days[HighIndex[2]] << ", " << days[HighIndex[3]] << " and " <<days[HighIndex[4]] << std::endl;
    
    else if(GetCount(pounds,GetHighest(pounds,i),i) == 6)
    output << "\nHighest: " <<  GetHighest(pounds,i)<< " pounds on " << days[HighIndex[0]] << ", " <<  days[HighIndex[1]] << ", " << days[HighIndex[2]] << ", " << days[HighIndex[3]] << ", " << days[HighIndex[4]] << " and " << days[HighIndex[5]] << std::endl;
   
    output << std::setprecision(2) << std::fixed;
    
    output << "\nAverage: " << average << std::endl;
    
    return output.str();
}
//--------------------------------------------------------------------------------------------------
