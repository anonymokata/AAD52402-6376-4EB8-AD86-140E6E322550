#include "romanNumeral.h"
#include <string.h>
#include <stdio.h>

int characterToValue(const char c)
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

void ifCharacterToRightIsGreaterMakeValueNegative(int* value, const char* ptr)
{
    const char rightChar = *(ptr + 1);
    if(rightChar && characterToValue(rightChar) > *value)
    {
        *value *= -1;
    }
}

void toIntegerInternal(int* totalValue, const char* startPtr, const char* ptr)
{
    if(totalValue < 0)
    {
        return;
    }
       
    if(ptr < startPtr)
    {
        return;
    }

    int value = characterToValue(*ptr);

    ifCharacterToRightIsGreaterMakeValueNegative(&value, ptr);

    *totalValue += value;

    toIntegerInternal(totalValue, startPtr, ptr - 1);
}

int toInteger(const char* str)
{
    int i = 0;
    toIntegerInternal(&i, str, &str[ strlen(str) - 1 ]);
    return i;
}
