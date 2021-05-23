/**
 Write a program that will read in an array of records of people's names and addresses from the keyboard and then and writes that information to an output file.
 •Each record will consist of the following fields: first name 15 characters, last name 15 characters, street address 30 characters, city 20 characters, state 10 characters, zip long integer. Declare a structure called AddressBook to hold a record.
 •Read an array of records from the keyboard by prompting for data till the user enters a sentinel to quit. The program should keep track of the number of records read.
 •Store this information to a binary file.
 •Read from the binary file back to another array of records, and store this information to a text file. Left justify the information for each field.
 •Assume a maximum of 20 records.
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
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
//------------------------------------------------------------------------------------------
const int SIZE_OF_FIRST_NAME = 15, SIZE_OF_LAST_NAME = 15, STREET_ADDRESS = 30, CITY = 20, STATE = 10, ZIPCODE = 5;
//------------------------------------------------------------------------------------------
struct AddressBook
{
    char FirstName[SIZE_OF_FIRST_NAME],
         LastName[SIZE_OF_LAST_NAME],
         StreetAddress[STREET_ADDRESS],
         City[CITY],
         State[STATE];
    int  Zip;
};
//------------------------------------------------------------------------------------------
void menu()
{
    cout << "---------------- Menu: ----------------\n";
    cout << "1) Add Entry" << "\t\t\t2) Delete Entry\n\n";
    cout << "3) Display" << "\t\t\t\t4) Exit\n";
    cout << "---------------------------------------\n";
}

int main()
{
    int counter = 0,
        select;
    AddressBook Address[20],
                Address2[20];
    string content,
            name,
            temp,
            address_book = "AddressBook.doc";
    char    insert;
    fstream file;

    do
    {
        
        menu();
        cout << "Select: ";
        cin >> select;
        cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
        switch (select)
        {
        case 1:
        {
           
            do
            {
                
                cout <<  "\n-------------- Entry #" << counter + 1 << " ---------------\n";
                cout << "First Name: ";
                cin.getline(Address[counter].FirstName, SIZE_OF_FIRST_NAME);
                cout << "\nLast Name: ";
                cin.getline(Address[counter].LastName, SIZE_OF_LAST_NAME);
                cout << "\nStreet Address: ";
                cin.getline(Address[counter].StreetAddress, STREET_ADDRESS);
                cout << "\nCity: ";
                cin.getline(Address[counter].City, CITY);
                cout << "\nState: ";
                cin.getline(Address[counter].State, STATE);
                cout << "\nZip Code: ";
                cin >> Address[counter].Zip;
                counter++;
                cout << "\nPlease indicate if you would like\nto write a new record (Y/N) ";
                cin >> insert; insert = toupper(insert);
                
                cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
             
            } while (insert == 'Y' and counter < 20);

            file.open(address_book, ios::out | ios::binary);
            
            file.write(reinterpret_cast<char *>(&Address), sizeof(Address));

            file.close();

            file.open(address_book, ios::in | ios::binary);

            file.read(reinterpret_cast<char *>(&Address2), sizeof(Address2));
            file.close();

            file.open("AddressBook.txt", ios::out);

            size_t fileSize = file.tellp();
            if(fileSize==0) {file << "----------- Address Book: -----------";}
            
            for (int i = 0; i < counter; i++)
            {
                
                file << "\nFirst Name: " << Address2[i].FirstName;
                file << "\nLast Name: " << Address2[i].LastName;
                file << "\nAddress: " << Address2[i].StreetAddress;
                file << "\nCity: " << Address2[i].City;
                file << "\nState: " << Address2[i].State;
                file << "\nZip: " << Address2[i].Zip;
                file << endl;
                file << "------------------------------------";
            }
            
            
            file.close();
            cout << endl;
            break;
        }
        case 2:
        {
            string firstName,
                   lastName;
            int length = counter;
            bool valid = false;
            char insert;
            
            do
            {
            cout << "\n--------------- Delete: ---------------\n";
            cout << "First Name: ";
            cin >> firstName;
            cout << "\nLast Name: ";
            cin >> lastName;
            
            for (int i = 0; i < length; i++)
            {
                
                if (!strcmp(Address2[i].FirstName, firstName.c_str()) && !strcmp(Address2[i].LastName, lastName.c_str()))
                {
                    valid = true;
                    int j = i;
                    while (j + 1 < counter)
                    {
                        Address2[j] = Address2[j + 1];
                        Address[j] = Address[j + 1];
                        j++;
                    }
                    length--; counter--;
                }
            }
            
            if(valid){cout << '\n' << firstName << ' ' << lastName << " has been deleted\n\n"; valid = false;}
            else {cout << endl << firstName << ' ' << lastName << " could not be found.\n\n";}
            
            if(length>0)
            {
            cout << "Would you like to delete\na new record (Y/N) ";
            cin >> insert; insert = toupper(insert);
            cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
            }
            else {insert='N';} cout << endl;
            
        }while(insert=='Y');
            
            file.open(address_book, ios::out | ios::binary | ios::trunc);
            file.write(reinterpret_cast<char *>(&Address2), sizeof(Address2));
            file.close();
            file.open("AddressBook.txt", ios::out);
            file << "----------- Address Book: -----------";
            for (int i = 0; i < length; i++)
            {
                file << "\nFirst Name: " << Address2[i].FirstName;
                file << "\nLast Name: " << Address2[i].LastName;
                file << "\nAddress: " << Address2[i].StreetAddress;
                file << "\nCity: " << Address2[i].City;
                file << "\nState: " << Address2[i].State;
                file << "\nZip: " << Address2[i].Zip;
                file << endl;
                file << "------------------------------------";
            }
            counter = length;
            file.close();
            break;
        }
        case 3:
        {
            cout << "\n----------- Address Book: -----------";
            for (int i = 0; i < counter; i++)
            {
                cout << "\nFirst Name: " << Address2[i].FirstName;
                cout << "\nLast Name: " << Address2[i].LastName;
                cout << "\nAddress: " << Address2[i].StreetAddress;
                cout << "\nCity: " << Address2[i].City;
                cout << "\nState: " << Address2[i].State;
                cout << "\nZip: " << Address2[i].Zip;
                if(i!=counter-1){cout << "\n------------------------------------";}
                else {cout << "\n\n";}
            }
            break;
        }
        
        default:
        {
            cout << "\nInvalid entry, please re-enter.";
            break;
        }
        }

    } while (select != 4);
    
    return 0;
}
//------------------------------------------------------------------------------------------
