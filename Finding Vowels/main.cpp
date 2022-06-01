//This program will allow the user to find vowels within a sentence.

#include<iostream>
#include<string>
#include<cstdlib>
#define SIZE 100

struct Structure
{
   
    char sentence[SIZE];
    char a = 'a',
         e = 'e',
         i = 'i',
         o = 'o',
         u = 'u',
          option;
    
    friend std::istream & operator >> (std::istream &input, Structure &s)
    {
        std::cout << "\nEnter sentence: ";
        input >> s.sentence;
       
        while (atoi(s.sentence) < 0 || atoi(s.sentence) > 0 || atof(s.sentence) < 0 || atof(s.sentence) > 0 )
        {
            std::cout << "\nInvalid entry, please re-enter: ";
            input >> s.sentence;
            
        }
        
        return input;
    }
    
}structure;

int Find(char *, char);
void Print(Structure&);

//-----------------------------------------------------------------------------
int main()
{
   
    
    std::cout << "--------------------------------------------\n\n\tThis program will determine how many\n\tof each vowel are contained within\n\ta the following sentence.\n\n--------------------------------------------\n";
do
{
    
    std::cin >> structure;
    Print(structure);
    std::cout << "\nWould you like to continue the program (Y/N) ? ";
    
}
while (std::cin >> structure.option && structure.option && (structure.option == 'Y' || structure.option == 'y'));
    
    std::cout << std::endl;
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
void Print(Structure &structure)
{
    std::cout << "\n--------------------------------------------";
    std:: cout << "\n\nThis sentence contains the letter 'a' " << Find(structure.sentence, structure.a) << " times \n";
    std::cout << "This sentence contains the letter 'e' " << Find(structure.sentence, structure.e) << " times \n";
    std::cout << "This sentence contains the letter 'i' " << Find(structure.sentence, structure.i) << " times \n";
    std::cout << "This sentence contains the letter 'o' " << Find(structure.sentence, structure.o) << " times \n";
    std::cout << "This sentence contains the letter 'u' " << Find(structure.sentence, structure.u) << " times \n";
}
//-----------------------------------------------------------------------------
