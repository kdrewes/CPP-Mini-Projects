//This program will allow the user to find vowels within a sentence.

#include<iostream>
#include<string>
#include<cstdlib>
#define SIZE 100
//-----------------------------------------------------------------------------
struct Structure
{
   
    char sentence[SIZE];
   
    char a = 'a',
         e = 'e',
         i = 'i',
         o = 'o',
         u = 'u',
          option;
    
    friend std::istream & operator >> (std::istream &, Structure &);
    friend std::ostream & operator << (std::ostream &, Structure &);

}structure;
//-----------------------------------------------------------------------------
int Find(char *, char);
//-----------------------------------------------------------------------------
std::istream & operator >> (std::istream &input, Structure &s)
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
//-----------------------------------------------------------------------------
std::ostream & operator << (std::ostream &output, Structure &s)
{
    output << "\n--------------------------------------------";
    output << "\n\nThis sentence contains the letter 'a' " << Find(s.sentence, s.a) << " times \n";
    output << "This sentence contains the letter 'e' " << Find(s.sentence, s.e) << " times \n";
    output << "This sentence contains the letter 'i' " << Find(s.sentence, s.i) << " times \n";
    output << "This sentence contains the letter 'o' " << Find(s.sentence, s.o) << " times \n";
    output << "This sentence contains the letter 'u' " << Find(s.sentence, s.u) << " times \n";
    
    return output;
}

//-----------------------------------------------------------------------------
int main()
{
   std::cout << "--------------------------------------------\n\n\tThis program will determine how many\n\tof each vowel are contained within\n\ta the following sentence.\n\n--------------------------------------------\n";
do
{
    if(structure.option == 'Y' || structure.option == 'y')
        std::cout << "\n--------------------------------------------\n";
    
    std::cin >> structure;
    std::cout << structure;
   
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

