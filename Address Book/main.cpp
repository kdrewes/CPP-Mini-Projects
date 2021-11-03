/**
 Write a program that will read in an array or vector of records of people's names and addresses from the keyboard and then and writes that information to an output file.  Declare a structure called AddressBook to hold a record.
 
 •Read an array of records from the keyboard by prompting for data till the user enters a sentinel to quit. The program should keep track of the number of records read.

 •Read from the file back to another array of records, and store this information to a text file. Left justify the information for each field.
 -Lastly, create a menu that consist of the following options:
 
 1) Add records
 2) delete records by serach for the first name of the individuals
 3) displays the records onto the console
 4) Exits out of the program
 
 Output Run
 First Name: Jackie
 Last Name: Doe
 Address: 555 Golf Club Road
 City: Pleasant Hill
 State: CA
 Zip: 94523
  
 First Name: John
 Last Name: Anon
 Address:  10007 Side Street
 City: San Ramon
 State: CA
 Zip: 94582
  
 First Name: Sandy
 Last Name: Beach
 Address: 2345 Ocean Avenue
 City: Santa Cruz
 State: CA
 Zip: 95060
  
 First Name: June
 Last Name: Empire
 Address: 245 33rd Street
 City: New York
 State: NY
 Zip: 10017
 */
#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;
//-----------------------------------------------------------------------------------------------------------------------------------

    struct AddressBook
    {
    std::string firstName;
    std::string lastName;
    std::string address;
    std::string city;
    std::string state;
    std::string zip;
     
    int option;
    char insert;
    
    friend ostream & operator << (ostream&o, const AddressBook& a)
        {
            
            o << "\nFirst Name: " << a.firstName << endl;
            o << "\nLast Name: " << a.lastName << endl;
            o << "\nAddress: " << a.address << endl;
            o << "\nCity: " << a.city << endl;
            o << "\nState: " << a.state << endl;
            o << "\nZip: " << a.zip << endl << endl;
            return o;
        }
        
    }addressBook;
//-----------------------------------------------------------------------------------------------------------------------------------
string ToString(std::string firstName,std::string lastName,std::string address,std::string city,std::string state,std::string zip)
        {
            ostringstream o;
            o << "\nFirst Name: " << firstName << flush;
            o << "\nLast Name: " << lastName << flush;
            o << "\nAddress: " << address << flush;
            o << "\nCity: " << city << flush;
            o << "\nState: " << state << flush;
            o << "\nZip: " << zip << flush;
            o << endl << endl << flush;
            return o.str();
        }
//-----------------------------------------------------------------------------------------------------------------------------------
void Find(vector<std::string>&AddressBookString, vector<AddressBook>&AddressBookVector, string firstName, string lastName, bool&valid)
{
    valid = false;
    for(vector<string>::size_type i = 0; i < AddressBookString.size(); i++)
    {
        if((AddressBookString[i].find(firstName + '\n') != string::npos) && (AddressBookString[i].find(lastName + '\n') != string::npos))
        {
            AddressBookString.erase(AddressBookString.begin() + i);
            AddressBookVector.erase(AddressBookVector.begin() + i);
            cout << '\n' << firstName << ' ' << lastName << " has been successfully deleted.\n\n";
            valid = true;
            break;
        }
    }
    if(!valid){cout << endl << firstName << ' ' << lastName << " could not be found.\n\n";}
    
}
//-----------------------------------------------------------------------------------------------------------------------------------
void Input()
{
    static int counter = 0,
               option;
    
    string firstName,
           lastName,
           address,
           city,
           state,
           zip;

    char insert;
 
    ofstream writeFile; ifstream readFile; ostringstream ostream;
 
    std::vector<AddressBook>AddressBookVector;
    std::vector<std::string>AddressBookString;
    
    do
    {
        
        cout << "---------------- Menu: ----------------\n";
        cout << "1) Add Entry" << "\t\t\t2) Delete Entry\n\n";
        cout << "3) Display" << "\t\t\t\t4) Exit\n";
        cout << "---------------------------------------\n";
        cout << "Select: ";
        cin >> option;
        cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
       switch(option)
       {
   case 1:
    {
        do
    {
        ++counter;
        ostringstream o;
        o <<  "\n-------------- Entry #" << counter << " ---------------\n";
        string header = o.str();
        cout << header;
        cout << "First Name: " << flush;
        getline(cin,firstName);
        cout << "\nLast Name: " << flush;
        getline(cin,lastName);
        cout << "\nStreet Address: " << flush;
        getline(cin,address);
        cout << "\nCity: " << flush;
        getline(cin,city);
        cout << "\nState: " << flush;
        getline(cin,state);
        cout << "\nZip Code: " << flush;
        getline(cin,zip);
        
        addressBook = {firstName,lastName,address,city,state,zip,option,insert};
        AddressBookVector.push_back(addressBook);
        AddressBookString.push_back(
                                    ToString(firstName,lastName,address,city,state,zip));
        
        cout << "\nPlease indicate if you would like\nto write a new record (Y/N) ";
        cin >> insert; insert = toupper(insert);
        cin.ignore(numeric_limits<std::streamsize>::max(),'\n');

        }while (insert == 'Y');
    
              writeFile.open("AddressBook.doc", ios::out | ios::trunc);
              readFile.open("AddressBook.doc", ios::in | ios::trunc);
       
              writeFile.seekp(0,ios::end);
              size_t fileSize = writeFile.tellp();
        
              if(fileSize==0) {writeFile << "----------- Address Book: -----------\n";}
              for(vector<AddressBook>::size_type i = 0; i < AddressBookVector.size(); i++)
              {
                  writeFile << AddressBookVector[i];
                  writeFile << "--------------------------------------\n";
              }

               readFile.close();
               writeFile.close();
    
        cout << "\n----------- Address Book: -----------\n";
               readFile.open("AddressBook.doc", ios::in);
               if(!readFile)
               {
                   cerr << "\nFile is unable to open\n";
                   exit(1);
               }
               string content;
               while(getline(readFile,content))
               {
                   if(!(content.find("----------- Address Book: -----------") != string::npos) &&
                      !(content.find("--------------------------------------") != string::npos))
                      {cout << content << endl;}
               }

               readFile.close();
               break;
       }
           case 2:
           {
               
               do
               {
               cout << "---------------- Delete: ----------------\n";
               cout << "\nFirst Name: ";
               getline(cin,firstName);
               cout << "\nLast Name: ";
               getline(cin,lastName);
               
               bool valid;
                   
               Find(AddressBookString,AddressBookVector,firstName,lastName,valid);
               
               
               if(valid)
               {
               writeFile.open("AddressBook.doc", ios::out | ios::trunc);
               writeFile << "----------- Address Book: -----------\n";
               for(vector<AddressBook>::size_type i = 0; i < AddressBookVector.size(); i++)
                   {
                   writeFile << AddressBookVector[i];
                   writeFile << "--------------------------------------\n";
               }
                   --counter;
                   writeFile.close();
               }
                   if(counter>0)
                   {
                   cout << "Please indicate if you would like\nto delete a new record (Y/N) ";
                   cin >> insert; insert = toupper(insert);
                   cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
                   }
                   else {insert='N';} cout << endl;
                   
               }while(insert=='Y');
               
               break;
           }
               
           case 3:
           {
               writeFile.open("AddressBook.doc", ios::out | ios::trunc);
               writeFile << "----------- Address Book: -----------\n";
               for(vector<AddressBook>::size_type i = 0; i < AddressBookVector.size(); i++)
               {
                   writeFile << AddressBookVector[i];
                   writeFile << "--------------------------------------\n";
                   
               }
               writeFile.close();
               
               cout << "\n------------ Address Book: ------------\n";
               
               for(vector<AddressBook>::size_type i = 0; i < AddressBookVector.size(); i++) {cout << AddressBookVector[i];}
               break;
           }
           case 4:
           {
               exit(0);
               break;
           }
           default:
               cout << "\nInvalid entry, please re-enter\n";
               break;
       }
    }while(option!=4);
    
    cout << endl;
}
//-----------------------------------------------------------------------------------------------------------------------------------
int main ()
{
    Input();
    
    return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------
