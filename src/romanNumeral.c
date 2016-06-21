#include "romanNumeral.h"
#include <string.h>
#include <stdio.h>

const int INVALID_TOTAL_VALUE = -1;
const int INVALID_CHARACTER_VALUE = -1;

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
        default  : return INVALID_CHARACTER_VALUE;
    }
}

int isCharacterToRightGreater(const int characterValue, const char* ptr)
{
    const char rightChar = *(ptr + 1);
    return rightChar != '\0' && characterToValue(rightChar) > characterValue;
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
    switch (*ptr)
    {
        case 'I' :
        case 'X' :
        case 'C' :
            return 3;
        case 'V' :
        case 'L' :
        case 'D' :
        case 'M' :
            return 1;
        default:
            return 0;
    }
}

void toIntegerInternal(int* totalValue, const char* startPtr, const char* ptr)
{
    if(*totalValue == INVALID_TOTAL_VALUE || ptr < startPtr)
    {
        return;
    }
       
    int characterValue = characterToValue(*ptr);
    if(characterValue != INVALID_CHARACTER_VALUE && timesCharacterRepeated(ptr) > maximumAllowedRepeats(ptr))
    {
        *totalValue = INVALID_TOTAL_VALUE;
        return;
    }

    if(isCharacterToRightGreater(characterValue, ptr))
    {
        characterValue *= -1;
    }

    *totalValue += characterValue;

    toIntegerInternal(totalValue, startPtr, ptr - 1);
}

int toInteger(const char* str)
{
    int i = 0;
    toIntegerInternal(&i, str, &str[ strlen(str) - 1 ]);
    return i;
}

void toRomanNumeralInternal(char* str, char* ptr, const int totalValue)
{
    int value = 0;
    int offset = 1;
    if(totalValue >= 1000)
    {
        *ptr = 'M';
        value = 1000;
    }
    else if(totalValue >= 900)
    {
        *ptr = 'C';
        *(ptr + 1) = 'M';
        offset = 2;
        value = 900;
    }
    else if(totalValue >= 500)
    {
        *ptr = 'D';
        value = 500;
    }
    else if(totalValue >= 400)
    {
        *ptr = 'C';
        *(ptr + 1) = 'D';
        offset = 2;
        value = 400;
    }
    else if(totalValue >= 100)
    {
        *ptr = 'C';
        value = 100;
    }
    else if(totalValue >= 90)
    {
        *ptr = 'X';
        *(ptr + 1) = 'C';
        offset = 2;
        value = 90;
    }
    else if(totalValue >= 50)
    {
        *ptr = 'L';
        value = 50;
    }
    else if(totalValue >= 40)
    {
        *ptr = 'X';
        *(ptr + 1) = 'L';
        offset = 2;
        value = 40;
    }
    else if(totalValue >= 10)
    {
        *ptr = 'X';
        value = 10;
    }
    else if(totalValue >= 9)
    {
        *ptr = 'I';
        *(ptr + 1) = 'X';
        offset = 2;
        value = 9;
    }
    else if(totalValue >= 5)
    {
        *ptr = 'V';
        value = 5;
    }
    else if(totalValue >= 4)
    {
        *ptr = 'I';
        *(ptr + 1) = 'V';
        offset = 2;
        value = 4;
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

    toRomanNumeralInternal(str, ptr + offset, totalValue - value);
}

void toRomanNumeral(char* str, const int totalValue)
{
    *str = '\0';
    toRomanNumeralInternal(str, str, totalValue);
}
