#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

// -----------------------------------------------------------------------------
struct Output

{

    string input,

           output,

           reason;

    Output()
    {
        input = "";

        output = "";

        reason = "";
        
    }

    Output(string input, string output, string reason)
    {
        this->input = input;

        this->output = output;

        this->reason = reason;
    }

    friend ostream & operator << (ostream& stream, Output& o)
    {
        stream << "------------------------- Display Results -------------------------";

        stream << "\n\nInput: " << o.input << endl;

        stream << "\n\nOutput: " << o.output << endl;

        stream << "\n\nReason: " << o.reason << endl;

        return stream;
    }
};


void Tokenize(string htmlTags[], size_t size);

Output CheckTag(string syntax);

bool CheckTagHelper(char character, std::vector<string> &collectTags,
                    bool &isOpenArrow, string & concatenateTAG,
                    pair <string, string> & properties);

void CompareTags(vector <string> collectTags, pair<string, string> & properties);

void Print(Output output);

// -----------------------------------------------------------------------------
int main()
{
    string htmlTags[] =
    {
        "<div><br><p> Hola Mundo </p></br></div>",

        "</div><br><p> Hola Mundo </p></br><div>",

        "<div> <h1> Como estace ? </h1> </b>",

        "<div><span><p>No Me puedo quejar </p></span></div>"

    };

    Tokenize(htmlTags, sizeof(htmlTags) / sizeof(htmlTags[0]));

    return 0;
}

// -----------------------------------------------------------------------------
void Tokenize(string htmlTags[], size_t size)
{
    Output outputObject;

    for (int i = 0; i < size; i++)
        Print(CheckTag(htmlTags[i]));
    
    cout << "-------------------------------------------------------------------\n\n";
}

// -----------------------------------------------------------------------------
Output CheckTag(string syntax)
{
    typedef string output, reason;

    bool isOpenArrow = false;

    string concatenateTAG = "";
    
    pair<output, reason> properties;

    vector<string>collectTags;

    for (int i = 0; i < syntax.size(); i++)
    {
        if (!CheckTagHelper(syntax[i], collectTags, isOpenArrow, concatenateTAG, properties))
            return { syntax, properties.first, properties.second };
    }

    CompareTags(collectTags,properties);

    return { syntax, properties.first, properties.second };
}

// -----------------------------------------------------------------------------
bool CheckTagHelper(char character, vector<string> &tagVector, bool& isOpenArrow,
                    string & concatenateTAG, pair <string,string> & properties)
{

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
    
    else
    {
        if (isOpenArrow)
            concatenateTAG += character;
    }
    
    return true;
}

// -----------------------------------------------------------------------------
void CompareTags(vector <string> collectTags, pair<string, string>& properties)
{
    bool isError = false;

    int start = 0,
        end = collectTags.size() - 1;
    
    while (start < end)
    {
        string beginningTag = collectTags[start];

        string endTag = collectTags[end];

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

            properties.second = "End Tag, " + endTag + ", must have '/' " + "\n\n\t\tPlease correct error";

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

    if (!isError)
    {
        properties.first = "True";

        properties.second = "Syntax is correctly executed";
    }
}
// -----------------------------------------------------------------------------
void Print(Output output)
{
    cout << output << endl;
}

// -----------------------------------------------------------------------------

