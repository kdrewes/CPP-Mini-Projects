#include <iostream>

//----------------------------------------------------------------------

bool containsPair(const int []);

bool containsTwoPair(const int []);

bool containsThreeOfaKind(const int []);

bool containsStraight(const int []);

bool containsStraightHelper(const int []);

bool containsFullHouse(const int []);

bool containsFourOfaKind(const int []);

bool IsDifferent(const int []);

bool IsDifferentHelper(const int [],int,bool&,int&);

bool NoPairs(const int []);

bool NoPairsHelper(const int [],int);

int Counter(const int []);

void CounterHelper(const int [], int, int&);

int Lowest(const int [],int);

int Highest(const int [],int);

void Input(int []);

void Result(int [],size_t);

//----------------------------------------------------------------------
const int HAND_SIZE = 5;
int main()
{
    int hand[HAND_SIZE];
    
    Input(hand);
    
    Result(hand,sizeof(hand)/sizeof(hand[0]));
   
    std::cout << std::endl;
    
    return 0;
}
//----------------------------------------------------------------------

bool containsPair(const int hand[])
{
    if(Counter(hand)==1)
    return true; return false;
}
//----------------------------------------------------------------------

bool containsTwoPair(const int hand[])
{
    if(Counter(hand)==2 && IsDifferent(hand))
    return true; return false;
}

//----------------------------------------------------------------------

bool  containsThreeOfaKind(const int hand[])
{
    if(Counter(hand)==3 && !IsDifferent(hand))
    return true; return false;
}
//----------------------------------------------------------------------

bool  containsStraight(const int hand[])
{
    if(NoPairs(hand))
        if(containsStraightHelper(hand)) return true;
    return false;
}
//----------------------------------------------------------------------

bool containsStraightHelper(const int hand[])
{
    bool confirmation = false;
    int low = Lowest(hand,HAND_SIZE);
    int temp = 0;
  
    for(int i = 0; i < HAND_SIZE; i++)
    {
        for(int j = 0; j < HAND_SIZE; j++)
        {
            if(hand[j]-low == 1)
            {
                confirmation = true;
                temp = hand[j];
            }
        }
        
        if(confirmation)
        low = temp;
        
        if(!confirmation && i != 4)
            return false;
        
            confirmation = false;
        
    }       return true;
}
//----------------------------------------------------------------------

bool  containsFullHouse(const int hand[])
{
    if(Counter(hand)==4 && IsDifferent(hand))
        return true; return false;
}
//----------------------------------------------------------------------

bool  containsFourOfaKind(const int hand[])
{
    if(Counter(hand)==6 && !IsDifferent(hand))
    return true; return false;
}
//----------------------------------------------------------------------

bool IsDifferent(const int hand[])
{
    bool flag = true; int temp = 0;
    for(int i = 0; i < HAND_SIZE; i++)
    if(IsDifferentHelper(hand,i,flag,temp)) return true;

    return false;
}
//----------------------------------------------------------------------

bool IsDifferentHelper(const int hand[], int i, bool &flag, int &temp)
{
    for(int j = 0; j < HAND_SIZE; j++)
    {
        if((hand[i]==hand[j]) && i!=j)
        {
            if(flag)
            {
                temp = hand[j];
                flag = false;
            }
            else if(temp!=hand[j])
                return false;
        }
    }           return true;
}
//----------------------------------------------------------------------

bool NoPairs(const int hand[])
{
    for(int i = 0; i < HAND_SIZE; i++)
    if(!NoPairsHelper(hand,i))return false;
    return true;
}
//----------------------------------------------------------------------

bool NoPairsHelper(const int hand[],int i)
{
    for(int j = 0; j < HAND_SIZE; j++)
    {
        if((hand[i]==hand[j]) && i!=j )
            return false;
    }       return true;
}
//----------------------------------------------------------------------

int Counter(const int hand[])
{
    int counter = 0;
    
    for(int i = 0; i < HAND_SIZE; i++)
        CounterHelper(hand,i,counter);
    
        return counter;
}
//----------------------------------------------------------------------

void CounterHelper(const int hand[],int i,int &counter)
{
    for(int j = i+1; j < HAND_SIZE; j++)
        if((hand[i]==hand[j]) && i!=j )
            counter++;
}
//----------------------------------------------------------------------

int Highest(const int array [],int size)
{
    int i = 0,
        highest = INT_MIN;
    
    for(i = 0; i < size; i++)
        if(array[i] > highest)
            highest = array[i];
    
    return highest;
}
//----------------------------------------------------------------------

int Lowest(const int array [],int size)
{
    int i = 0, low = INT_MAX;
    
    for(i = 0; i < size; i++)
        if(array[i] < low)
            low = array[i];
    
    return low;
}
//----------------------------------------------------------------------

void Input(int hand [])
{
    std::cout << "Enter 5 numeric cards, no face cards. Use 1 - 9." << std::endl;
    
    for(int i = 0; i < HAND_SIZE;i++)
    {
        std::cout << "\nCard " << i+1 << ": ";
        std::cin >> hand[i];
        
        if(!std::cin || (hand[i] < 1) || (hand[i] > 9))
        {
            std::cout << "\nInvalid Entry, please re-enter\n";
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            --i;
        }
    }
}
//----------------------------------------------------------------------

void Result(int hand [],size_t size)
{
    if(NoPairs(hand) && !containsStraight(hand))
        std::cout << "\nHighest card is " << Highest(hand,size);
    else
    {
    if(containsPair(hand))
        std:: cout << "\ncontains a pair" << std::endl;
    
    else if (containsTwoPair(hand))
        std::cout << "\ncontains a two pair" << std::endl;
    
    else if (containsThreeOfaKind(hand))
        std::cout << "\ncontains a three of a kind" << std::endl;

    else if (containsStraight(hand))
        std::cout << "\ncontains a straight" << std::endl;

    else if (containsFullHouse(hand))
        std::cout << "\ncontains a full house" << std::endl;

    else if (containsFourOfaKind(hand))
        std::cout << "\ncontains a four of a kind" << std::endl;
    }
}
//----------------------------------------------------------------------
