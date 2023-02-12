#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

string fileData;
ifstream myFile;
string filepath;
int currentLine = 0;

vector<string> validLines = {};
map<int, vector<int>> allCollectedNumbers = {};


bool checkLineValid(string stringToCheck);
void retreiveAndSortNumbers(string lineText, int currentLine);
void printOutNumbers();

int main() {


    cout << "Enter full filepath: " << endl;
    cin >> filepath;

    //myFile.open("/Users/welkom/Downloads/newFile.txt");
    myFile.open(filepath);

    //check if file could be opened
    if(myFile.is_open())
    {
        //int currentLine;
        while (getline(myFile, fileData))
        {
           // currentLine += 1;
            bool valid = checkLineValid(fileData);
            if(valid)
            {
                // validLines.push_back(fileData);
                // cout << "Valid Line: " << fileData << endl;
                retreiveAndSortNumbers(fileData, currentLine);

            }
            else if(!valid){
                cout << "line " << currentLine << " is invalid: " << fileData << endl;
            }
        }
    }
    else
    {
        cout << "\nError: Could not open File.\nMake sure the file exist and the give the fullpath\n\n" << endl;
    }

    printOutNumbers();
    myFile.close();
    return 0;
}

bool checkLineValid(string stringToCheck)
{
    bool lineIsValid = true;
    currentLine += 1;
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

void retreiveAndSortNumbers(string lineText, int currentLine)
{
    int parsedStringInt = 0;
    vector<int> collectedNumbers = {};
    vector<string> numberStrings = {};
    string numberToAdd;
    for(int currentIndex = 0; currentIndex < lineText.length(); currentIndex++)
    {
        if(lineText[currentIndex] == ' ' || lineText[currentIndex] == '\t')
        {
            if(numberToAdd.length() != 0)
            {
                numberStrings.push_back(numberToAdd);
            }
            numberToAdd.clear();
            continue;
        }

        numberToAdd += lineText[currentIndex];
        if(currentIndex == lineText.length() - 1){
            numberStrings.push_back(numberToAdd);
        }
    }

    //Convert numbers inline to string
    for(string numberString : numberStrings)
    {
        
        for(int i = 0; i < numberString.length(); i++)
        {
            int x = numberString[i] - '0';
            x *= pow(10, (numberString.length() - 1 - i));
            parsedStringInt += x;
        }

        collectedNumbers.push_back(parsedStringInt);
        parsedStringInt = 0;
    }
    
    allCollectedNumbers[currentLine] = collectedNumbers;
}

void printOutNumbers()
{
     //print out number
    for(auto x : allCollectedNumbers)
    {
        cout << "Line " << x.first << ":" ;

        for(int number : x.second){
            cout << number << " ";
        }

        cout << endl;
    }
}