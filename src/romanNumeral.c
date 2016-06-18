#include <stdio.h>

int characterValue(const char c)
{
    switch (c)
    {
        case 'I' : return 1;
        case 'V' : return 5;
        case 'X' : return 10;
        case 'L' : return 50;
        case 'C' : return 100;
        case 'D' : return 500;
        case 'M' : return 1000;
        default  : return -1;
    }
}

void romanNumeralStringToInteger(int* value, const char* startChar, const char* endChar)
{
    if(value < 0)
    {
        return;
    }
       
    if(endChar < startChar)
    {
        return;
    }

    *value += characterValue(*endChar);

    romanNumeralStringToInteger(value, startChar, endChar - 1);
}
