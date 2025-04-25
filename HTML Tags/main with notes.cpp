#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

// -----------------------------------------------------------------------------
// Structure used to store results
struct Output

{
    // Declare output variables
    string input,         // Display individual tag

           output,        // Determine if output is true/false

           reason;        // Provide reason for output

    // Default Constructor
    Output()
    {
        input = "";

        output = "";

        reason = "";
    }


    // Paramaterized Constructor
    Output(string input, string output, string reason)
    {
        this->input = input;

        this->output = output;

        this->reason = reason;
    }

    // Display object
    friend ostream & operator << (ostream& stream, Output& o)
    {
        stream << "------------------------- Display Results -------------------------";

        stream << "\n\nInput: " << o.input << endl;

        stream << "\n\nOutput: " << o.output << endl;

        stream << "\n\nReason: " << o.reason << endl;

        return stream;
    }
};

// ------------------------ Prototypes ------------------------

// Execute tokenization algorithm
void Tokenize(string htmlTags[], size_t size);

// Determine if html elements are correctly written
Output CheckTag(string syntax);

// Produce Helper function for bool CheckTags(string htmlTags[])
bool CheckTagHelper(char character, std::vector<string> &collectTags,
                    bool &isOpenArrow, string & concatenateTAG,
                    pair <string, string> & properties);

// Compare each tag to determine if syntax is correctly exectued
void CompareTags(vector <string> collectTags, pair<string, string> & properties);

// Print output
void Print(Output output);

// -----------------------------------------------------------------------------
int main()
{
    // Declare tag array
    string htmlTags[] =
    {
        "<div><br><p> Hola Mundo </p></br></div>",

        "</div><br><p> Hola Mundo </p></br><div>",

        "<div> <h1> Como estace ? </h1> </b>",

        "<div><span><p>No Me puedo quejar </p></span></div>"

    };

    // Generate output
    Tokenize(htmlTags, sizeof(htmlTags) / sizeof(htmlTags[0]));

    return 0;
}

// -----------------------------------------------------------------------------
// Tokenize dataset
void Tokenize(string htmlTags[], size_t size)
{
    // Instantiate object - used to collect final result
    Output outputObject;

    // Traverse through dataset
    for (int i = 0; i < size; i++)

        // Display output
        Print(CheckTag(htmlTags[i]));
    

    // Ending line
    cout << "-------------------------------------------------------------------\n\n";
}

// -----------------------------------------------------------------------------
// Determine if html elements are correctly written
Output CheckTag(string syntax)
{
    // Implement typedef for organizational purposes
    typedef string output, reason;
    
    // Determine if tag is open or closed
    bool isOpenArrow = false;

    // Concatenate tag
    string concatenateTAG = "";
    
    // Display reason for output
    pair <output, reason> properties;

    // Collect tags utilizing vector
    vector<string>collectTags;

    // Traverse through each tag and tokenize data
    for (int i = 0; i < syntax.size(); i++)
    {
        if (!CheckTagHelper(syntax[i], collectTags, isOpenArrow, concatenateTAG, properties))
            return { syntax, properties.first, properties.second };
    }

    // Compare each tag to determine if syntax is correctly exectued
    CompareTags(collectTags,properties);

    return { syntax, properties.first, properties.second };
}

// -----------------------------------------------------------------------------
// Produce Helper function for bool CheckTags(string htmlTags[])
bool CheckTagHelper(char character, vector<string> &tagVector, bool& isOpenArrow,
                    string & concatenateTAG, pair <string,string> & properties)
{

    // Execute condition if '<' or '>' is detected
    if (character == '<' || character == '>')
    {
        if (character == '<' && !isOpenArrow)
        {
            isOpenArrow = true;
            return true;
        }
            
        else if(character == '<' && isOpenArrow)
        {
            properties.second = "\nError - extra " + string(1, character) + " was detected was tag wasn't closed";
            return false;
        }

        else if (character == '>' && isOpenArrow)
        {
            tagVector.push_back(concatenateTAG);

            concatenateTAG = "";

            isOpenArrow = false;

            return true;
        }

        else if(character == '>' && !isOpenArrow)
        {
            properties.second = "\nError - " + string(1, character) + " was detected when tag wasn't open";
            return false;
        }
    }
    
    // Execute condition if character is detected
    else
    {
        if (isOpenArrow)
            concatenateTAG += character;

    }
    
    return true;
}

// -----------------------------------------------------------------------------
// Compare each tag to determine if syntax is correctly exectued
void CompareTags(vector <string> collectTags, pair<string, string>& properties)
{
    // Declare error variable
    bool isError = false;

    // Declare iterator variables
    int start = 0,
        end = collectTags.size() - 1;

    while (start < end)
    {
        // Declare beginning tag
        string beginningTag = collectTags[start];

        // Declare end tag
        string endTag = collectTags[end];

        // Determine if end tag contains slash in beginning
        bool noSlash = false;

        if (endTag[0] == '/')
        {
            endTag.erase(0, 1);
            noSlash = false;
        }

        else if (endTag[0] != '/')
            noSlash = true;

        if (noSlash && beginningTag == endTag && !isError)
        {
            properties.first = beginningTag;

            properties.second = "End Tag, " + endTag + ", must have '/'\n\n\tPlease correct error";

            isError = true;
        }
        
        else if (noSlash && beginningTag != endTag)
        {
            properties.first = "False";
            
            if(beginningTag != "/")
                properties.second = "End tag should be </" + endTag + "> not <" + endTag + ">\n\n\t\tPlease correct error";
            
            else
            {
                string beginningError = beginningTag;
                beginningTag.erase(0,1);
                properties.second = "Beginning tag should be <" + beginningTag + "> not <" + beginningError + "> and end tag should be </" + endTag + "> not <" + endTag + ">\n\n\t\tPlease correct error";
            }
                
            isError = true;

            break;
        }

        else if (!noSlash && beginningTag != endTag && !isError)
        {
            properties.first = beginningTag;

            properties.second = "Please correct begining tag <" + beginningTag + "> and end tag <" + endTag + ">";

            isError = true;
        }

        else if (beginningTag[0] == '/')
        {
            properties.first = "False";

            properties.second = "Error - Beginning tag contains '/'\n\n\tPlease correct error";

            break;
        }

        else if (beginningTag != endTag && isError)
        {
            properties.first = "False";

            properties.second = "Error - More than one syntactical error detected.\n\nPlease correct errors";

            break;
        }

        start += 1;
        end -= 1;

    }

    // Determines if syntax was correctly implemented
    if (!isError)
    {
        properties.first = "True";

        properties.second = "Syntax is correctly executed";
    }
}
// -----------------------------------------------------------------------------
// Print output
void Print(Output output)
{
    cout << output << endl;
}

// -----------------------------------------------------------------------------

