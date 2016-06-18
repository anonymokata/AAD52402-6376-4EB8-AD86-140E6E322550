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

void romanNumeralStringToInteger(int* value, const char* startPtr, const char* evalPtr)
{
    if(value < 0)
    {
        return;
    }
       
    if(evalPtr < startPtr)
    {
        return;
    }

    int evalValue = characterValue(*evalPtr);

    const char rightChar = *(evalPtr + 1);
    if(rightChar && characterValue(rightChar) > evalValue)
    {
        *value -= evalValue;
    }
    else
    {
        *value += evalValue;
    }

    romanNumeralStringToInteger(value, startPtr, evalPtr - 1);
}
