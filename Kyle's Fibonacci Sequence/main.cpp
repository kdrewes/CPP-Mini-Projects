//Kyle's Fibonacci Sequence

/**

 Disclaimer:
 This program was created by me.  It was not copied or duplicated in anyway.  
 If you happen to find a program that is conducted in this same format prior 
 to 4/3/2022, please let me know and I will remove this code immediately.  Thank you.
 
 */
#include <iostream>

namespace command
{
//-----------------------------------------------
void space(size_t space)
{
    for(size_t i = 0; i < space; i++)
        std::cout << std::endl;
}
//-----------------------------------------------
}
class Fibonacci
{
private:
       int number1,
           number2,
           sum;
    
    size_t i;

public:
    Fibonacci();
    
    void Initializer();
    void SetNumber1(int);
    void SetNumber2(int);
    void SetSum(int);
    void SetUpdater(size_t);
    void Updater();
    void fibonacci();
    void Print();
    
    bool Condition(int);
    
    int GetNumber1() const;
    int GetNumber2() const;
    int GetSum() const;
    
    size_t GetUpdater() const;
    
};
//-----------------------------------------------
Fibonacci :: Fibonacci()
{
    number1 = 0;
    number2 = 1;
    sum = 0;
    i = 0;
}
//-----------------------------------------------
void Fibonacci :: Initializer()
{
    SetSum(GetNumber1() + GetNumber2());
}
//-----------------------------------------------
void Fibonacci :: SetNumber1(int number1)
{
    this -> number1 = number1;
}
//-----------------------------------------------
void Fibonacci :: SetNumber2(int number2)
{
    this -> number2 = number2;
}
//-----------------------------------------------
void Fibonacci :: SetSum(int sum)
{
    this -> sum = sum;
}
//-----------------------------------------------
void Fibonacci :: SetUpdater(size_t i)
{
    this -> i += i;
}
//-----------------------------------------------
void Fibonacci :: Updater()
{
    fibonacci();
    SetUpdater(1);
}
//-----------------------------------------------
void Fibonacci :: fibonacci()
{
    SetNumber1(GetNumber2());
    SetNumber2(GetSum());
    SetSum(GetNumber1() + GetNumber2());
}
//-----------------------------------------------
void Fibonacci :: Print()
{
    std::string plus = " + ",
                equals = " = ";
    
    std::cout << GetNumber1() << plus << GetNumber2()
    << equals << GetSum();
    
    command::space(2);
}
//-----------------------------------------------
bool Fibonacci :: Condition(int limit)
{
    return GetUpdater() < limit;
}
//-----------------------------------------------
int Fibonacci :: GetNumber1() const
{
    return number1;
}
//-----------------------------------------------
int Fibonacci :: GetNumber2() const
{
    return number2;
}
//-----------------------------------------------
int Fibonacci :: GetSum() const
{
    return sum;
}
//-----------------------------------------------
size_t Fibonacci :: GetUpdater() const
{
    return i;
}
//-----------------------------------------------
int main()
{
    Fibonacci f;
    
    std::cout << "----------------- Fibonacci Sequence -----------------\n";
    
    for(f.Initializer(); f.Condition(10); f.Updater())
        f.Print();

    return 0;
}
