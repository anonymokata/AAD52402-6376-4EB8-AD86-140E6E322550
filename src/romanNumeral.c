#include "romanNumeral.h"
#include <string.h>
#include <stdio.h>

const int INVALID_TOTAL_VALUE = -1;
const int INVALID_CHARACTER_VALUE = -1;

typedef struct ValueToStringMap_S
{
    int value;
    char* str;
} ValueToStringMap;

const ValueToStringMap VALUE_TO_STRING_MAP[] = {
    { 1000, "M" },
    { 900, "CM" },
    { 500, "D" },
    { 400, "CD" },
    { 100, "C" },
    { 90, "XC" },
    { 50, "L" },
    { 40, "XL" },
    { 10, "X" },
    { 9, "IX" },
    { 5, "V" },
    { 4, "IV" },
    { 1, "I" }
};
const int VALUE_TO_STRING_MAP_LENGTH = sizeof(VALUE_TO_STRING_MAP) / sizeof(VALUE_TO_STRING_MAP[0]);

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
    const char rightChar = ptr[1];
    return rightChar != '\0' && characterToValue(rightChar) > characterValue;
}

void timesCharacterRepeatedInternal(const char* ptr, int* countPtr)
{
    if(ptr[0] != ptr[1])
    {
	return;
    }

    ++(*countPtr);
    timesCharacterRepeatedInternal(&ptr[1], countPtr);
}

int timesCharacterRepeated(const char* ptr)
{
    if(ptr[0] == '\0')
    {
        return 0;
    }

    int count = 1;
    timesCharacterRepeatedInternal(ptr, &count);
    return count;
}

int maximumAllowedRepeats(const char* ptr)
{
    switch (ptr[0])
    {
        case 'I' :
        case 'X' :
        case 'C' :
        case 'M' :
            return 3;
        case 'V' :
        case 'L' :
        case 'D' :
            return 1;
        default:
            return 0;
    }
}

void toIntegerInternal(int* value, const char* startPtr, const char* ptr)
{
    if(*value == INVALID_TOTAL_VALUE || ptr < startPtr)
    {
        return;
    }
       
    int characterValue = characterToValue(ptr[0]);
    if(characterValue != INVALID_CHARACTER_VALUE && timesCharacterRepeated(ptr) > maximumAllowedRepeats(ptr))
    {
        *value = INVALID_TOTAL_VALUE;
        return;
    }

    if(isCharacterToRightGreater(characterValue, ptr))
    {
        characterValue *= -1;
    }

    *value += characterValue;

    toIntegerInternal(value, startPtr, &ptr[-1]);
}

int toInteger(const char* str)
{
    if(str == NULL)
    {
        return INVALID_TOTAL_VALUE;
    }

    int i = 0;
    toIntegerInternal(&i, str, &str[ strlen(str) - 1 ]);
    return i;
}

void toRomanNumeralInternal(char* ptr, int* value)
{
    if(*value < VALUE_TO_STRING_MAP[VALUE_TO_STRING_MAP_LENGTH - 1].value)
    {
        return;
    }   

    int i = 0;
    for(i = 0; i < VALUE_TO_STRING_MAP_LENGTH; ++i)
    {
        if(*value >= VALUE_TO_STRING_MAP[i].value)
        {
            *value -= VALUE_TO_STRING_MAP[i].value;
            strcat(ptr, VALUE_TO_STRING_MAP[i].str);
            break;
        }
    }

    toRomanNumeralInternal(ptr, value);
}

void toRomanNumeral(char* str, const int value)
{
    if(str != NULL && value >= 0 && value < 4000)
    {
        str[0] = '\0';
        int val = value;
        toRomanNumeralInternal(str, &val);
    }
}

void addRomanNumerals(char* result, const char* romanNumeral1, const char* romanNumeral2)
{
    if(romanNumeral1 != NULL && romanNumeral2 != NULL)
    {
        toRomanNumeral(result, toInteger(romanNumeral1) + toInteger(romanNumeral2));
    }
}

void subtractRomanNumerals(char* result, const char* romanNumeral1, const char* romanNumeral2)
{
    if(romanNumeral1 != NULL && romanNumeral2 != NULL)
    {
        toRomanNumeral(result, toInteger(romanNumeral1) - toInteger(romanNumeral2));
    }
}
