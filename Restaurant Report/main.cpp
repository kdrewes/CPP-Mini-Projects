/**Write a program to help a restaurant owner keep track of how many pounds of food each category of diners eats each day during a typical week. There are 3 categories of diners: Kids, Adults and Seniors.
 //Do not use global variables, pointers or vectors for this program.
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
#define DAYS 7
#define CATEGORY 3
using namespace std;
//--------------------------------------------------------------------------------------------------
//Function Prototypes:
void Input(long double, const string [], const string [], long double []);

bool Compare(long double,long double,bool);

long double GetLowest(long double [1][DAYS], int, int &);

long double GetHighest(long double [1][DAYS], int, int &);
//--------------------------------------------------------------------------------------------------

namespace command
{

void space(){cout << '\n';}

void space(int size)

{
    string temp;
    for(int i = 0; i < size; i++){temp += '\n';}
   
    cout << temp;
}
}
//--------------------------------------------------------------------------------------------------

bool Compare(long double number,long double number2,bool flag)
{
        if(flag)
        {
            if(number < number2) {return true;}
            return false;
        }
        else
        {
            if(number > number2) {return true;}
            return false;
        }
}
//--------------------------------------------------------------------------------------------------
long double GetLowest(long double pounds[1][DAYS],int x, int &lowIndex)
{
    long double lowest;
    
    lowest = pounds[x][0];
    
    for(int z = x; z < DAYS; z++)
    {
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
    long double highest;
    
    highest = pounds[x][0];
    
    for(int z = x; z < DAYS; z++)
    {
        if(Compare(highest,pounds[x][z],true))
        {
            highest = pounds[x][z];
            highIndex = z;
        }
    }
    
    return highest;
}
//--------------------------------------------------------------------------------------------------
void Input(long double pounds[CATEGORY][DAYS], const string categories[], const string days[], long double average[])
{
    int sum = 0,
        x = -1,
        lowIndex = 0,
        highIndex = 0;
    
    long double highest,
                lowest,
                lowestArray[CATEGORY],
                highestArray[CATEGORY];
    
    string information,
           document[CATEGORY];
    
    ostringstream o;
    
    divides<double>Divides;
    
    for(int i = 0; i < CATEGORY; i++)
    {
        
        cout << categories[i];
        o << categories[i] << endl;
        command::space();
      
        for(int j = 0; j < DAYS; j++)
        {
            try
            {
            cout << days[j] << ": ";
            cin >> pounds[i][j];
                
                if(Compare(pounds[i][j],0,true)){throw pounds[i][j];}
                command::space();
                o << days[j] << ": " << pounds[i][j] << " Pounds " << endl << endl;
                sum += pounds[i][j];
                information += o.str();
                o.str("");
                o.clear();
            }
            catch(long double exception)
            {
                while(Compare(pounds[i][j],0,true))
                {
                cout << "\nInvalid entry, please re-enter:\n\n" << days[j] << " : ";
                cin >> pounds[i][j];
                }
                sum += pounds[i][j];
                command::space();
                o << days[j] << ": " << pounds[i][j] << " Pounds " << endl << endl;
                information += o.str();
                o.str("");
                o.clear();
            }
        }
        
        average[i] = Divides(static_cast<long double>(sum),DAYS);
        
        ++x;
 
        lowest = GetLowest(pounds,x,lowIndex);

        lowestArray[x] = lowest;

        highest = GetHighest(pounds,x,highIndex);

        highestArray[x] = highest;
        
        o << "\nLowest: " << lowestArray[i] << " pounds on " << days[lowIndex] << endl;
        o << "\nHighest: " << highestArray[i] << " pounds on " << days[highIndex] << endl;
        o << "\nAverage: " << average[i] << " Pounds " << endl;
       
        information += o.str();
        
        document[i] = information + '\n';
 
        information.clear();
        
        sum = 0, lowest = 0, highest = 0, lowIndex = 0, highIndex = 0;
        
        o.str("");
        o.clear();
    }
    
    for(int i = 0; i < CATEGORY; i++){cout << document[i];}
}
//--------------------------------------------------------------------------------------------------
int main(int argc, const char * argv[])
{
    long double pounds[CATEGORY][DAYS],
                average[CATEGORY];
    
    const string categories [CATEGORY] =
    {"---------- Kids ----------","---------- Adults ----------","---------- Seniors ----------"};
    
    const string days [DAYS] =
    {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    
    Input(pounds,categories,days,average);
    
    command::space();
    return 0;
}
