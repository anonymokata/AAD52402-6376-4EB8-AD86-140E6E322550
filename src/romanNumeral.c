void romanNumeralStringToInteger(int* value, const char* str)
{
    if (value < 0 || str[0] == '\0')
    {
        return;
    }

    if(str[0] == 'I')
    {
        *value += 1;
    }
    else if(str[0] == 'V')
    {
        *value += 5;
    }
    else if(str[0] == 'X')
    {
        *value += 10;
    }
    else if(str[0] == 'L')
    {
        *value += 50;
    }
    else if(str[0] == 'C')
    {
        *value += 100;
    }
    else if(str[0] == 'D')
    {
        *value += 500;
    }
    else if(str[0] == 'M')
    {
        *value += 1000;
    }
    else
    {
        *value = -1;
    }

    romanNumeralStringToInteger(value, str + 1);
}
