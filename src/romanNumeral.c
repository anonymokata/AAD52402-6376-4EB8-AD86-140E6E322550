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

int isCharacterToRightGreater(const int value, const char* ptr)
{
    const char rightChar = *(ptr + 1);
    return rightChar != '\0' && characterToValue(rightChar) > value;
}

int timesCharacterRepeated(const char* ptr)
{
    if(*ptr == '\0')
    {
        return 0;
    }

    if(*ptr == *(ptr + 1))
    {
        return 1 + timesCharacterRepeated(ptr + 1);
    }

    return 1;
}

int maximumAllowedRepeats(const char* ptr)
{
    int repeats = 1;
    if(*ptr == 'I' || *ptr == 'X' || *ptr == 'C')
    {
        repeats = 3;
    }
    return repeats;
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

    if(value > 0)
    {
        if(timesCharacterRepeated(ptr) > maximumAllowedRepeats(ptr))
        {
            *totalValue = -1;
            return;
        }
    }

    if(isCharacterToRightGreater(value, ptr))
    {
        value *= -1;
    }

    *totalValue += value;

    toIntegerInternal(totalValue, startPtr, ptr - 1);
}

int toInteger(const char* str)
{
    int i = 0;
    toIntegerInternal(&i, str, &str[ strlen(str) - 1 ]);
    return i;
}


void toRomanNumeral(const char* str, char* ptr, const int totalValue)
{
    int value = 0;
    if(totalValue >= 50)
    {
        *ptr = 'L';
        value = 50;
    }
    else if(totalValue >= 10)
    {
        *ptr = 'X';
        value = 10;
    }
    else if(totalValue >= 5)
    {
        *ptr = 'V';
        value = 5;
    }
    else if(totalValue >= 1)
    {
        *ptr = 'I';
        value = 1;
    }
    else
    {
        *ptr = '\0';
        return;
    }

    toRomanNumeral(str, ptr + 1, totalValue - value);
}
