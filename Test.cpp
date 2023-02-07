#include <iostream>
#include <math.h>
using namespace std;

bool checkRoundUp(string stringToParse);
int parseDecimalString(string stringToParse);
int parseHexString(string stringToParse);

int main(){
    string decString = "15. 5463";
    string hexString = "15 50 60 3C";
    int x = parseDecimalString(decString);
    int y = parseHexString(hexString);
    
    cout << "Parsed Decimal String: " << x << endl;
    cout << "Parsed Hex String: " << y << endl;
}

/*
converts provided decimal text to an int by iterating through each character.
*/
int parseDecimalString(string stringToParse)
{
    int parsedStringInt = 0;
    bool roundUpNumber = false;
    string secondHalf = "";
    string firstHalve = "";
    int decimalPosition = 0;

    //seperate first and second halves.
    for(int i = 0; i < stringToParse.length(); i++)
    {
        char currentChar = stringToParse[i];
        if(currentChar == ' ')
        {
            continue;
        }
        
        if(currentChar == '.')
        {
            decimalPosition = i;
            
            //get second half i.e after decimal point.
            for(int y = i + 1; y < stringToParse.length(); y++)
            {
                 if(stringToParse[y] == ' ')
                 {
                     continue;
                 }
                secondHalf += stringToParse[y];
            }
            cout << firstHalve << "" << secondHalf << endl;
            break;
        }

        firstHalve += currentChar;
    }


    for(int i =0; i < firstHalve.length(); i++)
    {
        int x = firstHalve[i] - '0';
        x *= pow(10, (firstHalve.length() - 1 - i));
        parsedStringInt += x;
    }


    if(checkRoundUp(secondHalf)){
        parsedStringInt += 1;
    }

    return parsedStringInt;

}

/*
checks if the final int should be rounded up.
*/
bool checkRoundUp(string stringToParse){
    bool roundUpNumber = false;
    bool addOneToNextValue = false;
    
    //iterate from the last value in order to round up the next value.
    for ( int i = stringToParse.length() - 1; i >= 0; i--)
    {
        char currentChar = stringToParse[i];
        int x = currentChar - '0';
        if(addOneToNextValue){
            x += 1;
        }

        if(x >= 5){
            if(i == 0)
            {
                roundUpNumber = true;
                break;
            }
            else{
                addOneToNextValue = true;
            }
        }
    }
    return roundUpNumber;
}

/*
converts provided HexString to an int by iterating through each character.
*/
int parseHexString(string stringToParse)
{
    int parsedStringInt = 0;
    int stringLength = stringToParse.length() - 1;
    for(int i = 0; i < stringToParse.length(); i++)
    {
        char c = stringToParse[i];
        int a = 0;
        switch(c)
        {
            case 'A':
                a = 10 * pow(16,stringLength - i);
                break;
            
            case 'B':
                a = 11 * pow(16,stringLength - i);
                break;
            case 'C':
                a = 12 * pow(16,stringLength - i);
                break;
            case 'D':
                a = 13 * pow(16,stringLength - i);
                break;
            case 'E':
                a = 14 * pow(16,stringLength - i);
                break;
            case 'F':
                a = 15 * pow(16,stringLength - i);
                break;
            /*
            Decided to take the longer literal route
            default:
                a = (c - '0') * pow(16,i);
                break;
                */

            case '0':
                a = 0 * pow(16,stringLength - i);
                break;
            case '1':
                a = 1 * pow(16,stringLength - i);
                break;
            case '2':
                a = 2 * pow(16,stringLength - i);
                break;
            case '3':
                a = 3 * pow(16,stringLength - i);
                break;
            case '4':
                a = 4 * pow(16,stringLength - i);
                break;
            case '5':
                a = 5 * pow(16,stringLength - i);
                break;
            case '6':
                a = 6 * pow(16,stringLength - i);
                break;
            case '7':
                a = 7 * pow(16,stringLength - i);
                break;
            case '8':
                a = 8 * pow(16,stringLength - i);
                break;
            case '9':
                a = 9 * pow(16,stringLength - i); 
            
            default:
            //bad input
                break;
        }
        parsedStringInt += a;
    }
    return parsedStringInt;
}