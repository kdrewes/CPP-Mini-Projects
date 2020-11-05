/**
 In a post to the class, answer the following questions:
 
 Please write and post your solution to the "FillBuzz" question:  "Write a program that prints the numbers from 1 to 100.
 But for multiples of three print “Fizz” instead of the number and for the multiples of five print “Buzz”.
 For numbers which are multiples of both three and five print “FizzBuzz” "

 */
#include<iostream>
using namespace std;

bool booleon(int x, int y)
{
    if(x%y==0)
        return true; return false;
}
void FizzBuzz(int f, int l, string &palabra)
{
    string temp;
    
    if(f<=l)
    {
        if(booleon(f,3) && !booleon(f,5))
        {
            temp = "Fizz ";
            palabra=palabra+temp;
            FizzBuzz(f+1,l,palabra);
            
        }
        else if(booleon(f,5) && !booleon(f,3))
        {
            temp = "Buzz ";
            palabra=palabra+temp;
            FizzBuzz(f+1,l,palabra);
        }
        else if(booleon(f,15))
        {
            temp = "FizzBuzz ";
            palabra=palabra+temp;
            FizzBuzz(f+1,l,palabra);
        }
        else
        {
            palabra = palabra+to_string(f)+ " ";
            FizzBuzz(f+1,l,palabra);
        }
        
    }
}

int main()
{
    string fizzbuzz;
    FizzBuzz(1,100,fizzbuzz);
    cout << fizzbuzz;
    
    return 0;
}
