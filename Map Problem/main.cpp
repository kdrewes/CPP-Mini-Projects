/**
 
 Write a program that creates a map containing course numbers and the room numbers of the rooms where the courses meet.  The map should have the following key - value pairs.
 
 Course Number (Key)    Room Number (Value)
 CS101                  3004
 CS102                  4501
 CS103                  6755
 NT110                  1244
 CM241                  1411
 
 The program should include the name of each subject the course numbers are associated with.
 
 Course Number (Key)    Subject (Value)
 CS101                  Computer Science
 CS102                  Computer Science
 CS103                  Computer Science
 NT110                  Networking
 CM241                  Chemistry
 
 The Program should also create a map containing course numbers and the names of the instructors that teach each course.
 The map should have the following key - value pairs.
 
 Course Number (Key)    Instructor (Value)
 CS101                  Haynes
 CS102                  Alvarado
 CS103                  Rich
 NT110                  Burke
 CM241                  Lee
 
 The program should also create a map containing course numbers and the meeting times of each course.  The map should have the following key - value pairs:
 
 Course Number (Key)    Meeting Times (Value)
 CS101                  8:00 AM
 CS102                  9:00 AM
 CS103                  10:00 AM
 NT110                  11:00 AM
 CM241                  1:00 PM
 
 The program should let the user enter a course number, then it should display the course's room number, instructor and meeting time.
 
 */
#include<iostream>
#include<map>
#include<sstream>
#include<fstream>
//-------------------------------------------------------------------

void Lower_To_Upper(std::string&);
void Print(std::map<std::string,int>,
           std::map<std::string,std::string>,
           std::map<std::string,std::string>,
           std::map<std::string,std::string>,
           std::map<std::string,int>::iterator,
           std::map<std::string,std::string>::iterator,
           std::map<std::string,std::string>::iterator,
           std::map<std::string,std::string>::iterator,
           std::string,
           std::ofstream&);
std::string ToString(std::map<std::string,int>,
                     std::map<std::string,std::string>,
                     std::map<std::string,std::string>,
                     std::map<std::string,std::string>,
                     std::map<std::string,int>::iterator,
                     std::map<std::string,std::string>::iterator,
                     std::map<std::string,std::string>::iterator,
                     std::map<std::string,std::string>::iterator,
                     std::string);
//-------------------------------------------------------------------

int counter = 0;

int main ()
{
    typedef int room_number;
    typedef std::string course,
                        subject,
                        instructor,
                        time;
    
    std::ofstream file("Class Directory.txt",std::ios::out);
    
    std::map<course,room_number> RoomNumber =
    {{"CS101", 3004},
     {"CS102", 4501},
     {"CS103", 6755},
     {"NT110", 1244},
     {"CM241", 1411}};
    
    std::map<course,subject> Subject =
    {{"CS101", "Computer Science"},
     {"CS102", "Computer Science"},
     {"CS103", "Computer Science"},
     {"NT110", "Networking"},
     {"CM241", "Chemistry"}};
    
    std::map<course,instructor> Instructor =
    {{"CS101", "Haynes"},
     {"CS102", "Alvarado"},
     {"CS103", "Rich"},
     {"NT110", "Burke"},
     {"CM241", "Lee"}};
    
    std::map<course,time> Time =
    {{"CS101", "8:00 AM"},
     {"CS102", "9:00 AM"},
     {"CS103", "10:00 AM"},
     {"NT110", "11:00 AM"},
     {"CM241", "1:00 PM"}};
    
    std::string print;
    char insert;
    course courseNumber;
    
    do
    {
    std::cout << "----- Class Directory -----";
    std::cout << "\nCourse Number: ";
    std::getline(std::cin,courseNumber);
    
    std::map<course, int>::iterator it;
    std::map<course, subject>::iterator it2;
    std::map<course, instructor>::iterator it3;
    std::map<course, time>::iterator it4;
    
    Print(RoomNumber,Subject,Instructor,Time,it,it2,it3,it4,courseNumber,file);
    print += ToString(RoomNumber,Subject,Instructor,Time,it,it2,it3,it4,courseNumber);
    std::cout << "Insert Course (Y/N) ? ";
    std::cin >> insert; insert = toupper(insert);
    if(insert=='Y'){std::cout << std::endl;++counter;}
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        
    }while(insert=='Y');
    file << "\f";
    file.close();
    std::cout<<print;
    std::cout<<std::endl<<std::endl;
    return 0;
}
//-------------------------------------------------------------------
void Lower_To_Upper(std::string &u)
{
    int size = u.length();
    for (int i = 0; i < size; i++){u[i] = toupper(u[i]);}
}
//-------------------------------------------------------------------
void Print(std::map<std::string,int>RoomNumber,
           std::map<std::string,std::string>Subject,
           std::map<std::string,std::string>Instructor,
           std::map<std::string,std::string>Time,
           std::map<std::string,int>::iterator it,
           std::map<std::string,std::string>::iterator it2,
           std::map<std::string,std::string>::iterator it3,
           std::map<std::string,std::string>::iterator it4,
           std::string courseNumber,
           std::ofstream&file)
{
    Lower_To_Upper(courseNumber);
    it = RoomNumber.find(courseNumber);
    it2 = Subject.find(courseNumber);
    it3 = Instructor.find(courseNumber);
    it4 = Time.find(courseNumber);
   
    if (it != RoomNumber.end() && it2 != Subject.end() && it3 != Instructor.end() && it4 != Time.end())
    {
        std::cout <<"\n--------- " << it->first <<  " ---------\n";
        std::cout << "Course Number: " << it->first;
        std::cout << "\n\nRoom Number: #" << it->second;
        std::cout << "\n\nSubject: " << it2->second;
        std::cout << "\n\nInstructor: " << it3->second;
        std::cout << "\n\nTime: " << it4->second;
        
        if(counter>0){file << std::endl;}
        file <<"\n--------- " << it->first <<  " ---------\n";
        file << "Course Number: " << it->first;
        file << "\n\nRoom Number: #" << it->second;
        file << "\n\nSubject: " << it2->second;
        file << "\n\nInstructor: " << it3->second;
        file << "\n\nTime: " << it4->second;
        
        std::cout <<"\n-------------------------\n\n";
    }
    else{std::cout << "\nUnable to find information \n\n";}
    
}
//-------------------------------------------------------------------
std::string ToString(std::map<std::string,int>RoomNumber,
                     std::map<std::string,std::string>Subject,
                     std::map<std::string,std::string>Instructor,
                     std::map<std::string,std::string>Time,
                     std::map<std::string,int>::iterator it,
                     std::map<std::string,std::string>::iterator it2,
                     std::map<std::string,std::string>::iterator it3,
                     std::map<std::string,std::string>::iterator it4,
                     std::string courseNumber)
{
    std::ostringstream o;
    Lower_To_Upper(courseNumber);
    it = RoomNumber.find(courseNumber);
    it2 = Subject.find(courseNumber);
    it3 = Instructor.find(courseNumber);
    it4 = Time.find(courseNumber);
   
    if(counter==0){o<<"\n-------------------------\n";}
    if (it != RoomNumber.end() && it2 != Subject.end() && it3 != Instructor.end() && it4 != Time.end())
    {
        if(counter>0) { o << std::endl; }
        o <<"\n--------- " << it->first <<  " ---------\n";
        o << "Course Number: " << it->first;
        o << "\n\nRoom Number: #" << it->second;
        o << "\n\nSubject: " << it2->second;
        o << "\n\nInstructor: " << it3->second;
        o << "\n\nTime: " << it4->second;
    }
    return o.str();
}
