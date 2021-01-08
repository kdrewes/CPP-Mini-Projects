/**
 This program finds the area of shapes
 */
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>

#define PIE 3.14159265359
#define RIGHT_ANGLE 90
using namespace std;

//Structures:
struct Dimensions
{
    //Area of a Rectangle:
    double rectangle_length;//Length of Rectangle
    double rectangle_width; //Width of Rectangle
    
    //Area of a Triangle
    double triangle_length;//Length of Triangle
    double triangle_width; //Width of Triangle
    
    //Area of a Circle
    double radius; //Radius of Circle
    
    //Right Triangle Trigonometry - Allows user to determine the sides and angles a right triangle
    double opposite; //Side opposite of the angle
    double adjacent; //Side adjacent of the angle
    double hypotenuse; //Hypotenuse of triangle, or the longest side.
    double opposite_angle; // Represents the angle of the opposite side.
    double adjacent_angle; // Represents the angle of the opposite side.
    
};
struct Area
{
    double AreaOfRectangle;
    double AreaOfTriangle;
    double AreaOfCircle;
    Dimensions SizeOfRectangle;
    Dimensions SizeOfTriangle;
    Dimensions SizeOfRadius;
    Dimensions RightTriangleTrigonometry;
};
//-----------------------------------------------------------------------------
//Functions:
Dimensions GetInputOfLengthAndWidth();
double GetAreaOfRectangle(double length, double width);
void DisplayRectangle(const Area &TempInfo);

Dimensions GetInputOfTriangle();
double GetAreaOfTriangle(double TriangleLength, double TriangleWidth);
void DisplayTriangle(const Area &TempInfo);

Dimensions GetInputOfRadius();
double GetAreaOfCircle(double radius);
void DisplayCircle(const Area &TempInfo);

//Right Triangle Trigonometry:
Dimensions GetInputOfRightTriangle();
void SetSide(int num, string &name);
void SetAngle(int num, string &name);
Dimensions GetCalculations(string side_name, string angle_name, double side, double angle);
void DisplayResults(const Area &TempInfo);


//Triangle Sketch
void Triangle_Menu()
{
    cout << "\n                                |\n";
    cout << "------ Select Side: ------      |\\\n";
    cout << "1) Side A \t 2) Side B          |B\\\n";
    cout << "3) Side C                       |  \\\n";
    cout << "--------------------------     A|   \\ C\n";
    cout << "                                |    \\\n";
    cout << "                                |_    \\\n";
    cout << "                                |_|__A(\\\n";
    cout << "                                   B\n";

}

//-----------------------------------------------------------------------------
int main()
{
    Area Info;
    int option = 0;
    
    do
    {
        cout << "\n------------------- Select Option: -------------------\n";
        cout << "1) Area of Rectangle \t 2) Area of Triangle\n" << left;
        cout << "3) Area of Circle \t     4) Right Triangle Trigonometry\n";
        
        cout << "\nselect: ";
        cin >> option;
        
        
        switch(option)
        {
            case 1:
            
                Info.SizeOfRectangle = GetInputOfLengthAndWidth(); // Prompts user to input the length and width.  Once the user inputs the necessary data the program will display the area of a rectangle.
                Info.AreaOfRectangle = GetAreaOfRectangle(Info.SizeOfRectangle.rectangle_length, Info.SizeOfRectangle.rectangle_width);
                DisplayRectangle(Info);//This function will display the area of the rectangle based on the information that was entered by the user.
                break;
            
                
            case 2:
            
                //These functions pertain to the area of a triangle
                Info.SizeOfTriangle = GetInputOfTriangle();
                Info.AreaOfTriangle = GetAreaOfTriangle(Info.SizeOfTriangle.triangle_length, Info.SizeOfTriangle.triangle_width);
                DisplayTriangle(Info);
                
                break;
            
            case 3:
            
                //These functions pertain to the area of a Rectangle
                Info.SizeOfRadius = GetInputOfRadius();// Prompts user to input the radius of a circle.  Once the user inputs the necessary data the program will display the area of a rectangle.
                Info.AreaOfCircle = GetAreaOfCircle(Info.SizeOfRadius.radius);
                DisplayCircle(Info);
                break;
            
                
            case 4:
            
                Info.RightTriangleTrigonometry = GetInputOfRightTriangle();
                //These functions pertain to the area of a Rectangle
                break;
            
            default:
            
                if(option != 5)
                cout << "\nInvalid entry, please re-enter. \n";
                break;
            
        }
        
    }while(option!=5);
    
    cout << endl;

    return 0;
}
//-----------------------------------------------------------------------------
Dimensions GetInputOfLengthAndWidth()
{
    Dimensions Info;
    
    cout << "\nRectangle: \n";
    
    cout << "\nInput Length: ";
    cin >> Info.rectangle_length;
    cout << "Input Width: ";
    cin >> Info.rectangle_width;
    
    return Info;
}
//-----------------------------------------------------------------------------

double GetAreaOfRectangle(double length, double width)
{
    double AreaOfRectangle;
    multiplies<double>Multiply;
    
    AreaOfRectangle = Multiply(length,width);
    
    return AreaOfRectangle;

}

//-----------------------------------------------------------------------------


void DisplayRectangle(const Area &TemporaryInfo)
{
    cout << setprecision(2);
    cout << "\nThe Area of the rectange is " << TemporaryInfo.AreaOfRectangle << endl;
  
}
//-----------------------------------------------------------------------------
Dimensions GetInputOfTriangle()
{
    
    Dimensions Info;
    
    cout << "\nTriangle: \n";
    
    cout << "\nInput the length of the triangle ";
    cin >> Info.triangle_length;
    cout << "Input the width of the triangle ";
    cin >> Info.triangle_width;
    
    return Info;
    
}
//-----------------------------------------------------------------------------
double GetAreaOfTriangle(double TriangleLength, double TriangleWidth )
{
    double AreaOfTriangle;
    multiplies<double>Multiply;
    divides<double>Divide;
    
    AreaOfTriangle = Divide(Multiply(TriangleLength,TriangleWidth),2);
    
    return AreaOfTriangle;
    
    
}
//-----------------------------------------------------------------------------
void DisplayTriangle(const Area &TempInfoTriangle)
{

    cout << setprecision(2) << fixed;
    cout << "\nThe Area of the triangle is " << TempInfoTriangle.AreaOfTriangle << endl;
 

}
//-----------------------------------------------------------------------------
Dimensions GetInputOfRadius()
{
    Dimensions Info;
    
    cout << "\nCircle: \n";
    
    cout << "\nInput Radius: ";
    cin >> Info.radius;
    
    return Info;
}
//-----------------------------------------------------------------------------
    double GetAreaOfCircle(double radius)
{
    double CircleArea;
    multiplies<double>Multiply;
    
    CircleArea = Multiply(PIE,pow(radius,2));
    
    return CircleArea;
}
//-----------------------------------------------------------------------------
void DisplayCircle(const Area &TempInfo)
{
    cout << setprecision(2) << fixed;
    cout << "\nThe Area of the circle is " << TempInfo.AreaOfCircle << endl;
    

}
//-----------------------------------------------------------------------------
Dimensions GetInputOfRightTriangle()
{
    Dimensions Info;
    string side_name,angle_name;
    int side_option,angle_option;
    double side,
           angle;
    
    Triangle_Menu();
    
    cout << "\nselect: ";
    cin >> side_option;
    
    while (side_option<=0 || side_option > 3)
    {
        cout << "\nInvalid entry, please re-enter: ";
        cin >> side_option;
    }
    
    SetSide(side_option,side_name);
    
    cout << "\nInput " << side_name << ": ";
    cin >> side;
    
    while (side <= 0 || side >= RIGHT_ANGLE )
    {
        if(side <= 0)
        {
        cout << "\nSide cannot less or equal\nto 0,please re-enter: ";
        cin >> side;
        }
        
        if(side >= 90)
        {
        cout << "\nSide cannot be greater or equal\nto 90 please re-enter: ";
        cin >> side;
        }
    }
    
    cout << "\n--------- Select Angle: ---------\n";
    cout << "1) Angle A \t\t 2) Angle B\n" << left;
    cout << "\nselect: ";
    cin >> angle_option;
    
    while (angle_option<=0 || angle_option > 2)
    {
        cout << "\nInvalid entry, please re-enter: ";
        cin >> angle_option;
    }
    
    SetAngle(angle_option,angle_name);
    
    cout << "\nInput " << angle_name << ": ";
    cin >> angle;
    
    while (angle >= 90 || angle <= 0)
    {
        if(angle >= 90)
        {
            cout << "\nAngle cannot be greater or equal\nto 90, please re-enter: ";
            cin >> angle;
        }
        if(angle <= 0)
        {
            cout << "\nAngle cannot be less or equal\nto 0, please re-enter: ";
            cin >> angle;
        }
    }
    
    
    Info = GetCalculations(side_name,angle_name,side,angle);
    
    return Info;
}
//-----------------------------------------------------------------------------
void SetSide(int num, string &name)
{
    if(num==1){name = "Side A";}
    if(num==2){name = "Side B";}
    if(num==3){name = "Side C";}
}
//-----------------------------------------------------------------------------
void SetAngle(int num, string &name)
{
    if(num==1){name = "Angle A";}
    if(num==2){name = "Angle B";}
}
//-----------------------------------------------------------------------------
Dimensions GetCalculations(string side_name, string angle_name, double side, double angle)
{
    Dimensions info;
    multiplies<double>Multiply;
    divides<double>Divide;
    
    if(side_name.compare("Side A")==0)
    {
        if(angle_name.compare("Angle A")==0)
        {
            info.opposite = side;
            info.opposite_angle = angle;
            info.hypotenuse = Divide((side),sin(angle * (PIE/180)));
            info.adjacent = Divide((side),tan(angle * (PIE/180)));
            info.adjacent_angle = 180 - (angle+RIGHT_ANGLE);
            
            cout << setprecision(2) << fixed;
            cout << "\n---------- Results: ----------\n";
            cout << right <<"\n                            |\n";
            cout << "Side A: " << info.opposite <<  right << "               |\\\n";
            cout << "Side B: " << info.adjacent <<  right << "               |" << " \\\n";
            cout << "Side C: " << info.hypotenuse << right << "               |  \\\n";
            cout << "Angle A: " << info.opposite_angle << right << "         " << info.opposite << "|   \\" << info.hypotenuse <<"\n";
            cout << "Angle B: " << info.adjacent_angle << right << "              |    \\\n";
            cout << "Right Angle: " << RIGHT_ANGLE << right << "             |_    \\\n";
            cout << right << "                            |_|__A(\\\n";
            cout << right << "                             " << info.adjacent << "\n";
        }
        else if(angle_name.compare("Angle B")==0)
        {
            info.adjacent = side;
            info.adjacent_angle = angle;
            info.hypotenuse = Divide((side),cos(angle * (PIE/180)));
            info.opposite = Multiply((side),tan(angle * (PIE/180)));
            info.opposite_angle = 180 - (angle+RIGHT_ANGLE);
            
            cout << setprecision(2) << fixed;
            cout << "\n---------- Results: ----------\n";
            cout << right <<"\n                            |\n";
            cout << "Side A: " << info.adjacent <<  right << "               |\\\n";
            cout << "Side B: " << info.opposite <<  right << "               |" << " \\\n";
            cout << "Side C: " << info.hypotenuse << right << "               |  \\\n";
            cout << "Angle A: " << info.opposite_angle << right << "         " << info.adjacent << "|   \\" << info.hypotenuse <<"\n";
            cout << "Angle B: " << info.adjacent_angle << right << "              |    \\\n";
            cout << "Right Angle: " << RIGHT_ANGLE << right << "             |_    \\\n";
            cout << right << "                            |_|__A(\\\n";
            cout << right << "                             " << info.opposite << "\n";
        }
    }
    if(side_name.compare("Side B")==0)/////////
    {
        if(angle_name.compare("Angle A")==0)
        {
            info.adjacent = side;
            info.adjacent_angle = angle;
            info.hypotenuse = Divide((side),cos(angle * (PIE/180)));
            info.opposite = Multiply((side),tan(angle * (PIE/180)));
            info.opposite_angle = 180 - (angle+RIGHT_ANGLE);
            
            cout << setprecision(2) << fixed;
            cout << "\n---------- Results: ----------\n";
            cout << right <<"\n                            |\n";
            cout << "Side A: " << info.opposite <<  right << "               |\\\n";
            cout << "Side B: " << info.adjacent <<  right << "               |" << " \\\n";
            cout << "Side C: " << info.hypotenuse << right << "               |  \\\n";
            cout << "Angle A: " << info.adjacent_angle << right << "         " << info.opposite << "|   \\" << info.hypotenuse <<"\n";
            cout << "Angle B: " << info.opposite_angle << right << "              |    \\\n";
            cout << "Right Angle: " << RIGHT_ANGLE << right << "             |_    \\\n";
            cout << right << "                            |_|__A(\\\n";
            cout << right << "                             " << info.adjacent << "\n";
        }
        else if(angle_name.compare("Angle B")==0)
        {
            info.opposite = side;
            info.opposite_angle = angle;
            info.hypotenuse = Divide((side),sin(angle * (PIE/180)));
            info.adjacent = Divide((side),tan(angle * (PIE/180)));
            info.adjacent_angle = 180 - (angle+RIGHT_ANGLE);
            
            cout << setprecision(2) << fixed;
            cout << "\n---------- Results: ----------\n";
            cout << right <<"\n                            |\n";
            cout << "Side A: " << info.adjacent <<  right << "                |\\\n";
            cout << "Side B: " << info.opposite <<  right << "               |" << " \\\n";
            cout << "Side C: " << info.hypotenuse << right << "               |  \\\n";
            cout << "Angle A: " << info.adjacent_angle << right << "         " << info.adjacent << "|   \\" << info.hypotenuse <<"\n";
            cout << "Angle B: " << info.opposite_angle << right << "              |    \\\n";
            cout << "Right Angle: " << RIGHT_ANGLE << right << "             |_    \\\n";
            cout << right << "                            |_|__A(\\\n";
            cout << right << "                             " << info.opposite << "\n";
        }

    }
    if(side_name.compare("Side C")==0)
    {
        if(angle_name.compare("Angle A")==0)
        {
            info.hypotenuse = side;
            info.opposite_angle = angle;
            info.opposite = Multiply((side),sin(angle * (PIE/180)));
            info.adjacent = Multiply((side),cos(angle * (PIE/180)));
            info.adjacent_angle = 180 - (angle+RIGHT_ANGLE);
            
            cout << setprecision(2) << fixed;
            cout << "\n---------- Results: ----------\n";
            cout << right <<"\n                           |\n";
            cout << "Side A: " << info.opposite <<  right << "               |\\\n";
            cout << "Side B: " << info.adjacent <<  right << "               |" << " \\\n";
            cout << "Side C: " << info.hypotenuse << right << "               |  \\\n";
            cout << "Angle A: " << info.opposite_angle << right << "         " << info.opposite << "|   \\" << info.hypotenuse <<"\n";
            cout << "Angle B: " << info.adjacent_angle << right << "              |    \\\n";
            cout << "Right Angle: " << RIGHT_ANGLE << right << "             |_    \\\n";
            cout << right << "                            |_|__A(\\\n";
            cout << right << "                             " << info.adjacent << "\n";
        }
        else if(angle_name.compare("Angle B")==0)
        {
            info.hypotenuse = side;
            info.opposite_angle = angle;
            info.opposite = Multiply((side),sin(angle * (PIE/180)));
            info.adjacent = Multiply((side),cos(angle * (PIE/180)));
            info.adjacent_angle = 180 - (angle + RIGHT_ANGLE);
            
            cout << setprecision(2) << fixed;
            cout << "\n---------- Results: ----------\n";
            cout << right <<"\n                           |\n";
            cout << "Side A: " << info.adjacent <<  right << "               |\\\n";
            cout << "Side B: " << info.opposite <<  right << "               |" << " \\\n";
            cout << "Side C: " << info.hypotenuse << right << "               |  \\\n";
            cout << "Angle A: " << info.adjacent_angle << right << "         " << info.adjacent << "|   \\" << info.hypotenuse <<"\n";
            cout << "Angle B: " << info.opposite_angle << right << "              |    \\\n";
            cout << "Right Angle: " << RIGHT_ANGLE << right << "             |_    \\\n";
            cout << right << "                            |_|__A(\\\n";
            cout << right << "                             " << info.opposite << "\n";

        }
        
    }
    return info;
}
//-----------------------------------------------------------------------------
