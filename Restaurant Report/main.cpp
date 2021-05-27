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
#define DAYS 7 //Represents the total number of days
#define CATEGORY 3 //Represents the number of categories which includes: kids, adults and seniors.
using namespace std;
//--------------------------------------------------------------------------------------------------
//Function Prototypes:
bool Compare(int,int,bool);  
void Input(int, const string [], const string [], long double []); 
//--------------------------------------------------------------------------------------------------
namespace command
{
char tab = '\t';

void space(){cout << '\n';}

void space(int size)
{
    string temp;
    for(int i = 0; i < size; i++){temp += '\n';}
   
    cout << temp;
}
}
//--------------------------------------------------------------------------------------------------
bool Compare(int number,int i,bool flag)
{
        if(flag)
        {
            if(number < i) {return true;}
            return false;
        }
        else
        {
            if(number > i) {return true;}
            return false;
        }
}
//--------------------------------------------------------------------------------------------------

void Input(int pounds[CATEGORY][DAYS], const string categories[], const string days[], double average[])
{
    int sum = 0,
        x = -1,
        lowIndex = 0,
        highIndex = 0;
    
         double highest,
                lowest,
                lowestArray[CATEGORY],
                highestArray[CATEGORY];
    
    string document[CATEGORY];
    ostringstream o; string information;
    for(int i = 0; i < CATEGORY; i++)
    {

        cout << categories[i];
        o << categories[i] << endl;;
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
            catch(int exception)
            {
                while(Compare(exception,0,true))
                {
                cout << "\nInvalid entry, please re-enter:\n\n" << days[j] << " : ";
                cin >> exception;
                }
                pounds[i][j] = exception; sum += pounds[i][j];
                command::space();
                o << days[j] << pounds[i][j]; information += o.str();
                o.str("");
                o.clear();
            }
        }
        average[i] = (static_cast<double>(sum) / DAYS);
        
        lowest = pounds[++x][0];
        for(int z = x; z < DAYS; z++)
        {
            if(Compare(lowest,pounds[x][z],false))
            {
                lowest = pounds[x][z];
                lowIndex = z;
            }
        }
        lowestArray[x] = lowest; --x;
        highest = pounds[++x][0];
        for(int z = x; z < DAYS; z++)
        {
            if(Compare(highest,pounds[x][z],true))
            {
                highest = pounds[x][z];
                highIndex = z;
            }
        }
        highestArray[x] = highest;
        
        o << "\nLowest: " << lowestArray[i] << " pounds on " << days[lowIndex] << endl;
        o << "\nHighest: " << highestArray[i] << " pounds on " << days[highIndex] << endl;
        o << "\nAverage: " << average[i] << " Pounds " << endl;
       
        information += o.str();
        document[i] = information + '\n';
        information.clear();
        sum = 0, lowest = 0, highest = 0;
        o.str("");
        o.clear();
    }
    for(int i = 0; i < CATEGORY; i++){cout << document[i];}
}
//--------------------------------------------------------------------------------------------------
int main(int argc, const char * argv[])
{
    int pounds[CATEGORY][DAYS];
    double average[CATEGORY];
    const string categories [CATEGORY] = {"---------- Kids ----------","---------- Adults ----------","---------- Seniors ----------"};
    const string days [DAYS] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    
    Input(pounds,categories,days,average);
    
    command::space(2);
    return 0;
}
