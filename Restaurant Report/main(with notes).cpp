// This file is the exact same as 'main.cpp' except it includes notes. Please feel free to remove asterisks if you would like to view the full code.  Thank you


/**
 Write a program to help a restaurant owner keep track of how many pounds of food each category of diners eats each day during a typical week. There are 3 categories of diners: Kids, Adults and Seniors.
 Do not use global variables, pointers or vectors for this program.
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
#define DAYS 7 //Represents the total number of days
#define CATEGORY 3 //Represents the number of categories which includes: kids, adults and seniors.
using namespace std;
//--------------------------------------------------------------------------------------------------
//Function Prototypes:
void Input(long double, const string [], const string [], long double []); //Allows the user to input necessary data.

bool Compare(long double,long double,bool); //Used to compare the size of two variables.  Created for organizational purposes.

long double GetLowest(long double [1][DAYS], int, int &); //Retrieves the least amount of food eaten for each category.
long double GetHighest(long double [1][DAYS], int, int &); //Retrieves the highest amount of food eaten for each category.
//--------------------------------------------------------------------------------------------------
//I've created my own library which allows me to implement basic commands
namespace command
{

void space(){cout << '\n';} //Allows programmer to implement space command without having to type in any output.

void space(int size)//Allows programmer to implement multiple space command without having to type in any output.
{
    string temp;
    for(int i = 0; i < size; i++){temp += '\n';}
   
    cout << temp;
}
}
//--------------------------------------------------------------------------------------------------

int main()
{
    long double pounds[CATEGORY][DAYS], //Used to store the amount of food eaten for each category
                average[CATEGORY]; //Used to store the average amount of food eaten for each category
    
    //Used to store the different types of categories
    const string categories [CATEGORY] = {"---------- Kids ----------","---------- Adults ----------","---------- Seniors ----------"};
    
    //Used to store each day
    const string days [DAYS] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    
    //Allows the user to input the necessary data.
    Input(pounds,categories,days,average);
    
    command::space();
    return 0;
}

//Used to compare the size of two variables.  Created for organizational purposes.
bool Compare(long double number,long double number2,bool flag)
{
        //If flag is true than it means we are determining if number is less than number2
        if(flag)
        {
            if(number < number2) {return true;}
            return false;
        }
        //If flag is false than it means we are determining if number is greater than number2
        else
        {
            if(number > number2) {return true;}
            return false;
        }
}
//--------------------------------------------------------------------------------------------------
long double GetLowest(long double pounds[1][DAYS],int x, int &lowIndex)
{
    //Initialized lowest variable.
    long double lowest;
    
    //Initializes the amount for the 'lowest' variable.
    lowest = pounds[x][0];
    
    //Used to determine the lowest amount of food eaten.
    for(int z = 0; z < DAYS; z++)
    {
        //Compares the size of each index of the array pounds[x][z].
        if(Compare(lowest,pounds[x][z],false))
        {
            lowest = pounds[x][z];
            lowIndex = z;
        }
    }
    
    return lowest;
}
//--------------------------------------------------------------------------------------------------
long double GetHighest(long double pounds[1][DAYS],int x, int &highIndex)
{
    //Initialized highest variable.
    long double highest;
    
    //Initializes the amount for the 'highest' variable.
    highest = pounds[x][0];
    
    //Used to determine the highest amount of food eaten.
    for(int z = 0; z < DAYS; z++)
    {
        //Compares the size of each index of the array pounds[x][z].
        if(Compare(highest,pounds[x][z],true))
        {
            highest = pounds[x][z];
            highIndex = z;
        }
    }
    
    return highest;
}
//--------------------------------------------------------------------------------------------------
void Input(long double pounds[CATEGORY][DAYS], const string categories[], const string days[], long double average[]) //Allows the user to input the necessary data.
{
    int sum = 0, //Used to determine the sum of all the pounds for each particular category (kids,adults and seniors).  From there, it will be used to determine the average amount (average = sum/CATEGORY)
        x = -1, //Used to count the index (of category) for each multidimensional array.  This will be used to determine the greatest amount of food eaten and the least amount of food eaten.  The reason why I've intialized it to -1 is so I can increments each index by using the prefix method.
        lowIndex = 0, //Used to determine the specific day that the least amount of food was eaten for each category (kids, adults and seniors).
        highIndex = 0; //Used to determine the specific day that the greatest amount of food was eaten for each category (kids, adults and seniors).
    
    long double highest, //Represents the greatest amount of food eaten for each category (kids, adults and seniors).
                lowest, //Represents the least amount of food eaten for each category (kids, adults and seniors).
                lowestArray[CATEGORY], //An array used to store the least amount of food eaten for each category (kids, adults and seniors).
                highestArray[CATEGORY]; //An array used to store the greatest amount of food eaten for each category (kids, adults and seniors).
    
    string information, //Used to collect all the data from ostringstream variable.  From there, it will transfer the data into the 'document[CATEGORY]' array for each category (kids, adults and seniors).  The variable will automatically clear after each iteration.
           document[CATEGORY]; //Used to store the information collected by the 'information' string variable.
    
    ostringstream o; //Used to convert all data types into a string variable refered to as 'information.'
    
    divides<long double>Divide; //Used to determine the average pounds eaten (sum/DAYS).
    
    //Used to iterate through the first dimension (CATEGORY) of the multidimensional array.
    for(int i = 0; i < CATEGORY; i++)
    {
        //Displays each category depending on the iteration.  Used as a header.
        cout << categories[i];
        o << categories[i] << endl; //Collects the information which will be later transferred into the document[] array.
        command::space(); //Creates a space.
        
        //Used to iterate through the second dimension (CATEGORY) of the multidimensional array.
        for(int j = 0; j < DAYS; j++)
        {
            //An exception used to determine if pounds[CATEGORY][DAYS] is a negative number.
            try
            {
            cout << days[j] << ": "; //Displays each day.
            cin >> pounds[i][j]; //Prompts used to enter the amount of food eaten for each day (days[j]).
                
                //Determines if pounds[i][j] is less than 0
                if(Compare(pounds[i][j],0,true)){throw pounds[i][j];}
                command::space();
                o << days[j] << ": " << pounds[i][j] << " Pounds " << endl << endl; //Used to collect the information.
                sum += pounds[i][j]; //Determine the sum of all the food eaten for each individual category.
                information += o.str(); //Transfers the information into the 'information' variable.
                o.str(""); //Clears the ostringstream operator.
                o.clear(); //Clears any error flags that may have generated.
                
            }
            //Catches the exception error if the pounds[i][j] was declared negative.
            catch(long double exception)
            {
                //Determines if the exception variable is less than 0
                while(Compare(pounds[i][j],0,true))
                {
                cout << "\nInvalid entry, please re-enter:\n\n" << days[j] << " : "; //Prompts used to re-enter information
                cin >> pounds[i][j];
                }
                sum += pounds[i][j]; //Determines the sum of all the food eaten for each individual category.
                command::space();
                o << days[j] << ": " << pounds[i][j] << " Pounds " << endl << endl; //Used to collect the information.
                information += o.str();  //Collects the information which will be later transferred into the document[] array.
                o.str(""); //Clears the ostringstream operator.
                o.clear(); //Clears any error flags that may have generated.
            }
        }
        //Calculates the average of each category.
        average[i] = Divide(static_cast<long double>(sum),DAYS);
        
        //Increments counter.  This counter is used to determine the highest and lowest amount of food eaten.  It must iterated during each loop because it will be comparing the amount food eaten for each category of the pounds[CATEGORY][DAYS] array.
        ++x;
        
        //Retrieves the least amount of food eaten for each category.
        lowest = GetLowest(pounds,x,lowIndex);
        
        //Tranfers the lowest amount of food to an array for each category
        lowestArray[x] = lowest;
    
        //Retrieves the greatest amount of food eaten for each category.
        highest = GetHighest(pounds,x,highIndex);
        //Tranfers the greatest amount of food to an array for each category
        highestArray[x] = highest;
        
        //Collects the data for the lowest amount of food eaten, greatest amount eaten and average amount which will subsequently be passed on to the 'information string.
        o << "\nLowest: " << lowestArray[i] << " pounds on " << days[lowIndex] << endl;
        
        o << "\nHighest: " << highestArray[i] << " pounds on " << days[highIndex] << endl;
        
        o << "\nAverage: " << average[i] << " Pounds " << endl;
       
        //Transfers the information from the ostringstream variable to the 'information' variable
        information += o.str();
        
        //Transfers the information from the 'information variable to the document[] array.
        document[i] = information + '\n';
        
        //Clears the 'information' variable.
        information.clear();
        
        //Resets the sum, lowest and highest variables so they won't interfere with the subsequent loops.
        sum = 0, lowest = 0, highest = 0, lowIndex = 0, highIndex = 0;
        
        //Clears the ostringstream operator.
        o.str("");
        
        //Clears any error flags that may have generated.
        o.clear();
    }
    for(int i = 0; i < CATEGORY; i++){cout << document[i];}
}
//--------------------------------------------------------------------------------------------------
