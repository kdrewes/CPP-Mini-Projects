//This program will allow the user to find vowels within a sentence.
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

int FindA(char *, char);
int FindE(char *, char);
int FindI(char *, char);
int FindO(char *, char);
int FindU(char *, char);

int main()
{
    const int SIZE = 100;
    char Sentence[SIZE];
    char a = 'a';
    char e = 'e';
    char i = 'i';
    char o = 'o';
    char u = 'u';
    char Option;
   

do
{
    cout << "Enter a sentence and I will tell you how many of each vowel are contained in the sentence: \n";
    cin.ignore();
    cin.getline(Sentence,SIZE);
    cout << endl;
   
    while (atoi(Sentence) < 0 || atoi(Sentence) > 0 || atof(Sentence) < 0 || atof(Sentence) > 0 )
    {
        
        cout << "I'm sorry you may not enter a number, please re-input a sentence.  Thank you \n";
         cin.getline(Sentence,SIZE);
        
    }
    
    cout << "This sentence contains the letter 'a' " << FindA(Sentence, a) << " times \n";
    cout << "This sentence contains the letter 'e' " << FindE(Sentence, e) << " times \n";
    cout << "This sentence contains the letter 'i' " << FindI(Sentence, i) << " times \n";
    cout << "This sentence contains the letter 'o' " << FindO(Sentence, o) << " times \n";
    cout << "This sentence contains the letter 'u' " << FindU(Sentence, u) << " times \n";
    cout << endl;
    cout << "Would you like to continue the program (Y/N) ? \n";
    cin >> Option;
    
while (Option != 'y' && Option != 'Y' && Option != 'N' && Option != 'n' )
{
    
    cout << "Please input Y or N.  Thank you \n";
    cin >> Option;
    
    
}
    
    
}
    while (Option == 'y' || Option == 'Y');

    
    return 0;
}

int FindA(char *Sentence, char a)
{
    int NumberOfOccurences = 0;
    int Counter = 0;
    
    while (Sentence[Counter] != '\0')
    {
        
        if (Sentence[Counter] == a)
        {
            
            NumberOfOccurences++;
            
        }
        
        Counter++;
        
    }
    
    
    return NumberOfOccurences;
    
}

int FindE(char *Sentence, char e)
{
    int NumberOfOccurences = 0;
    int Counter = 0;
    
    while (Sentence[Counter] != '\0')
    {
        
        if (Sentence[Counter] == e)
        {
            
            NumberOfOccurences++;
            
        }
        
        Counter++;
        
    }
    
    
    return NumberOfOccurences;
    
}

int FindI(char *Sentence, char i)
{
    int NumberOfOccurences = 0;
    int Counter = 0;
    
    while (Sentence[Counter] != '\0')
    {
        
        if (Sentence[Counter] == i)
        {
            
            NumberOfOccurences++;
            
        }
        
        Counter++;
        
    }
    
    
    return NumberOfOccurences;
    
}

int FindO(char *Sentence, char o)
{
    int NumberOfOccurences = 0;
    int Counter = 0;
    
    while (Sentence[Counter] != '\0')
    {
        
        if (Sentence[Counter] == o)
        {
            
            NumberOfOccurences++;
            
        }
        
        Counter++;
        
    }
     return NumberOfOccurences;
}

    int FindU(char *Sentence, char u)
    {
        int NumberOfOccurences = 0;
        int Counter = 0;
        
        while (Sentence[Counter] != '\0')
        {
            
            if (Sentence[Counter] == u)
            {
                
                NumberOfOccurences++;
                
            }
            
            Counter++;
            
        }
    
    
    return NumberOfOccurences;
    
}
