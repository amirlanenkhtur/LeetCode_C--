#include <iostream>
#include <string.h>

using namespace std;

int romanToInt(string s) {
    int repeat=0, num = 0, index = 0, indexNumeral=0;
    char letter = s.at(0);
    const string numerals = "MDCLXVI";
    int value[7] = {1000, 500, 100, 50, 10, 5, 1};

    switch(s.at(index)){
        case 'M':
            indexNumeral = 0;
            break;
        case 'D':
            indexNumeral = 1;
            break;
        case 'C':
            indexNumeral = 2;
            break;
        case 'L':
            indexNumeral = 3;
            break;
        case 'X':
            indexNumeral = 4;
            break;
        case 'V':
            indexNumeral = 5;
            break;
        case 'I':
            indexNumeral = 6;
            break;
    }
    while (index<s.length()){
        if (s.at(index) == numerals.at(indexNumeral)){
            repeat++;
        }
        else if ((indexNumeral>=1) && (s.at(index)==numerals.at(indexNumeral-1))){
            num = num + (value[indexNumeral-1] - value[indexNumeral]);
            repeat = 0;
        }
        else if ((indexNumeral>=2) && (s.at(index) == numerals.at(indexNumeral-2))){
            num = num + (value[indexNumeral-2] - value[indexNumeral]);
            repeat = 0;
        }
        else {
            num = num + ((value[indexNumeral] * repeat));
            repeat = 1;
            indexNumeral = numerals.find(s.at(index));
        }
        index++;
    }

    num = num + ((value[indexNumeral] * repeat));
    return num;
};

int main(){
    int output;
    output = romanToInt("MCMXCIV");
    cout << output;
}