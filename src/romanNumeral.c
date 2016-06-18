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

    if(*startChar == 'I')
    {
        *value += 1;
    }
    else if(*startChar == 'V')
    {
        *value += 5;
    }
    else if(*startChar == 'X')
    {
        *value += 10;
    }
    else if(*startChar == 'L')
    {
        *value += 50;
    }
    else if(*startChar == 'C')
    {
        *value += 100;
    }
    else if(*startChar == 'D')
    {
        *value += 500;
    }
    else if(*startChar == 'M')
    {
        *value += 1000;
    }
    else
    {
        *value = -1;
    }

    romanNumeralStringToInteger(value, startChar, endChar - 1);
}
