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

    if(*endChar == 'I')
    {
        *value += 1;
    }
    else if(*endChar == 'V')
    {
        *value += 5;
    }
    else if(*endChar == 'X')
    {
        *value += 10;
    }
    else if(*endChar == 'L')
    {
        *value += 50;
    }
    else if(*endChar == 'C')
    {
        *value += 100;
    }
    else if(*endChar == 'D')
    {
        *value += 500;
    }
    else if(*endChar == 'M')
    {
        *value += 1000;
    }
    else
    {
        *value = -1;
    }

    romanNumeralStringToInteger(value, startChar, endChar - 1);
}
