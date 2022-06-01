//This program will allow the user to find vowels within a sentence.

#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

int Find(char *, char);
//-----------------------------------------------------------------------------
int main()
{
    const int SIZE = 100;
         char sentence[SIZE];
         char a = 'a',
              e = 'e',
              i = 'i',
              o = 'o',
              u = 'u',
              option;
    
    cout << "--------------------------------------------\n\n\tThis program will determine how many\n\tof each vowel are contained within\n\ta the following sentence.\n\n--------------------------------------------";
do
{
    
    cout << "\n\nEnter sentence: ";
    cin.ignore();
    cin.getline(sentence,SIZE);
   
    while (atoi(sentence) < 0 || atoi(sentence) > 0 || atof(sentence) < 0 || atof(sentence) > 0 )
    {
        cout << "\nInvalid entry, please re-enter: ";
        cin.getline(sentence,SIZE);
        
    }
    cout << "\n--------------------------------------------";
    cout << "\n\nThis sentence contains the letter 'a' " << Find(sentence, a) << " times \n";
    cout << "This sentence contains the letter 'e' " << Find(sentence, e) << " times \n";
    cout << "This sentence contains the letter 'i' " << Find(sentence, i) << " times \n";
    cout << "This sentence contains the letter 'o' " << Find(sentence, o) << " times \n";
    cout << "This sentence contains the letter 'u' " << Find(sentence, u) << " times \n";
    cout << endl;
    cout << "Would you like to continue the program (Y/N) ? ";
    cin >> option;
    option = toupper(option);
    
    while (option != 'y' && option != 'Y' && option != 'N' && option != 'n' )
    {
    cout << "\nPlease input Y or N.  Thank you ";
    cin >> option;
    option = toupper(option);
    }
    
    cout << "\n--------------------------------------------";
    
}
while (option == 'y' || option == 'Y');
    
    return 0;
}
//-----------------------------------------------------------------------------
int Find(char *sentence, char letter)
{
    int occurrences = 0,
        counter = 0;
    
    while (sentence[counter] != '\0')
        if (sentence[counter++] == letter)
            occurrences++;
        return occurrences;
}
//-----------------------------------------------------------------------------
