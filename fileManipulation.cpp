#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool checkLineValid(string stringToCheck);
int main() {
    string fileData;
    ifstream myFile;
    string filepath;

    vector<string> validLines = {};

    //vector<int> ;

    cout << "Enter full filepath: " << endl;
    cin >> filepath;

   //myFile.open("/Users/welkom/Downloads/newFile.txt");
    myFile.open(filepath);

    //check if file could be
    if(myFile.is_open())
    {
        while (getline(myFile, fileData))
        {
            bool valid = checkLineValid(fileData);
            if(valid)
            {
                validLines.push_back(fileData);
                cout << "Valid Line: " << fileData << endl;

            }
            else if(!valid){
                cout << "Invalid line: " << fileData << endl;
            }
        }
    }
    else
    {
        cout << "\nError: Could not open File.\nMake sure the file exist and the give the fullpath\n\n" << endl;
    }

    for(string s : validLines)
    {
        cout << s << endl;
    }


    myFile.close();
    return 0;
}

bool checkLineValid(string stringToCheck)
{
bool lineIsValid = true;

//check if provided string has any disqualifying characters.
for(char c : stringToCheck){

    switch (c)
    {
        case '0':
            break;
        case '1':
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            break;
        case '6':
            break;
        case '7':
            break;
        case '8':
            break;
        case '9':
            break;
        case ' ':
            break;
        case '\t':
            break;
        default:
            return lineIsValid = false;
    }
}
return lineIsValid;
}