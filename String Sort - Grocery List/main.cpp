/**
 Use an algorithm to sort a list of groceries either using a string[] or char[] array.  For example:
 
 Unsorted:
 ice cream, cheese, fritos, apple sauce
 
 Sorted:
 apple sauce, cheese, fritos, ice cream
 */

#include <iostream>
#include <string>
#define LENGTH 10
using namespace std;

class Groceries
{
private:
    string grocery_list[LENGTH];
public:
    void groceryList(string list[], int length);
    void BubbleSort(string list[], int length);
    void Print(string list[],int counter);
}groceries;
//--------------------------------------------------------------------------------------
void Groceries::groceryList(string list[], int length)
{
    int i = 0;
    
    cout <<"Type list of groceries below:\n" << endl;
    
    for(i = 0; i < length; i++)
    {
    cout << i+1 << " - ";
    getline(cin,list[i]);
    }
}
//--------------------------------------------------------------------------------------
void Groceries :: BubbleSort(string list[], int length)
{
    int i=0, //represents the beginning variable in the first for loop.
        j=0;  //represents the beginning variable in the second for loop.
    
    string temp;
    
    for(i = 0; i < length-1; i++)
    {
        for(j = i+1;j<length; j++)
        {
            if(list[i].compare(list[j])>0)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}
//--------------------------------------------------------------------------------------
void Groceries :: Print(string list[],int counter)
{
    grocery_list[counter] = list[counter];
    cout << grocery_list[counter] << endl;
}
//--------------------------------------------------------------------------------------
int main(int argc, const char * argv[])
{
    string list[LENGTH];
    groceries.groceryList(list,LENGTH);
    cout << "\n---------UnSorted List---------\n";
    for(int i = 0; i < LENGTH; i++) {groceries.Print(list,i);}
    groceries.BubbleSort(list,LENGTH);
    cout << "\n---------Sorted List---------\n";
    for(int i = 0; i < LENGTH; i++) {groceries.Print(list,i);}
    cout << endl;
    
}
//--------------------------------------------------------------------------------------
