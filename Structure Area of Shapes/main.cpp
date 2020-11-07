//Find the area of rectangle, triangle and circle:
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//-------------------------------------------------------------------------------------------------------------------------------

//Constant Integer(s):
const double PIE = 3.14159265359;

//Structures:


struct dimensions
{
    double length;//Length of Rectangle
    double width; //Width of Rectangle
    double TriangleLength;//Length of Triangle
    double TriangleWidth; //Width of Triangle
    double radius; //Radius of Circle
};
struct Area
{
    double AreaOfRectangle;
    double AreaOfTriangle;
    double AreaOfCircle;
    dimensions SizesOfLengthAndWidth;
    dimensions SizesOfTriangle;
    dimensions SizeOfRadius;
    
};
//-------------------------------------------------------------------------------------------------------------------------------

//Prototypes:
dimensions GetInputOfLengthAndWidth();
double GetAreaOfRectangle(double length, double width);
void DisplayResultsOfLengthAndWidth(const Area &TemporaryInfo);

dimensions GetInputOfTriangle();
double GetAreaOfTriangle(double TriangleLength, double TriangleWidth);
void DisplayResultsOfTriangle(const Area &TempInfoTriangle);

dimensions GetInputOfRadius();
double GetAreaOfCircle(double radius);
void DisplayResultsOfCircle(const Area &TempInfo);
//-------------------------------------------------------------------------------------------------------------------------------

int main()
{
    Area Info;

    //These functions pertain to the area of a Rectangle
    Info.SizesOfLengthAndWidth = GetInputOfLengthAndWidth(); // Prompts user to input the length and width.  Once the user inputs the necessary data the program will display the area of a rectangle.
    Info.AreaOfRectangle = GetAreaOfRectangle(Info.SizesOfLengthAndWidth.length, Info.SizesOfLengthAndWidth.width);
     DisplayResultsOfLengthAndWidth(Info);//This function will display the area of the rectangle based on the information that was entered by the user.
    
    //These functions pertain to the area of a triangle
    Info.SizesOfTriangle = GetInputOfTriangle();
    Info.AreaOfTriangle = GetAreaOfTriangle(Info.SizesOfTriangle.TriangleLength, Info.SizesOfTriangle.TriangleWidth);
    DisplayResultsOfTriangle(Info);
    
    
    //These functions pertain to the area of a Rectangle
    Info.SizeOfRadius = GetInputOfRadius();// Prompts user to input the radius of a circle.  Once the user inputs the necessary data the program will display the area of a rectangle.
    Info.AreaOfCircle = GetAreaOfCircle(Info.SizeOfRadius.radius);
    DisplayResultsOfCircle(Info);

    return 0;
}
//-------------------------------------------------------------------------------------------------------------------------------
dimensions GetInputOfLengthAndWidth()
{
    dimensions Info;
    
    cout << "Please input the length: \n";
    cin >> Info.length;
    cout << "Please input the width: \n";
    cin >> Info.width;
    
    return Info;
}
//-----------------------------------------------------------------------------------------------------------------------------
    


double GetAreaOfRectangle(double length, double width)
{
    double AreaOfRectangle;
    
    AreaOfRectangle = length*width;
    
    return AreaOfRectangle;
    
    
}

//-----------------------------------------------------------------------------------------------------------------------------


void DisplayResultsOfLengthAndWidth(const Area &TemporaryInfo)
{
    
    cout << "The Area of the rectange is " << TemporaryInfo.AreaOfRectangle << endl;
    cout << "---------------------------------" << endl;


    
}
//-----------------------------------------------------------------------------------------------------------------------------
dimensions GetInputOfTriangle()
{
    
    dimensions TriangleInfo;
    
    cout << "Input the length of the triangle" << endl;
    cin >> TriangleInfo.TriangleLength;
    cout << "Input the width of the triangle" << endl;
    cin >> TriangleInfo.TriangleWidth;
    
    return TriangleInfo;
    
}


//-----------------------------------------------------------------------------------------------------------------------------
double GetAreaOfTriangle(double TriangleLength, double TriangleWidth )
{
    double AreaOfTriangle;
    
    AreaOfTriangle = (TriangleLength*TriangleWidth)/2;
    
    return AreaOfTriangle;
    
    
}

//-----------------------------------------------------------------------------------------------------------------------------
void DisplayResultsOfTriangle(const Area &TempInfoTriangle)
{

    cout << "The Area of the triangle is " << TempInfoTriangle.AreaOfTriangle << endl;
    cout << "---------------------------------" << endl;

}
//-----------------------------------------------------------------------------------------------------------------------------
dimensions GetInputOfRadius()
{
    dimensions Info;
    
    cout << "Please input the radius of the circle: " << endl;
    cin >> Info.radius;
    
    return Info;
    
}
//-----------------------------------------------------------------------------------------------------------------------------
    double GetAreaOfCircle(double radius)
{
    double CircleArea;
    
    CircleArea = PIE * pow(radius,2);
    
    return CircleArea;
}
//-----------------------------------------------------------------------------------------------------------------------------
void DisplayResultsOfCircle(const Area &TempInfo)
{
    
    cout << "The Area of the circle is " << TempInfo.AreaOfCircle << endl;
    cout << "------------------------------";

    
    
}

//-----------------------------------------------------------------------------------------------------------------------------
