int romanNumeralStringToInteger(const char* str)
{
    if(str[0] == '\0')
    {
        return 0;
    }

    if(str[0] == 'I')
    {
        return 1 + romanNumeralStringToInteger(str + 1);
    }

    if(str[0] == 'V')
    {
        return 5;
    }

    if(str[0] == 'X')
    {
        return 10;
    }

    if(str[0] == 'L')
    {
        return 50;
    }

    if(str[0] == 'C')
    {
        return 100;
    }

    if(str[0] == 'D')
    {
        return 500;
    }

    if(str[0] == 'M')
    {
        return 1000;
    }

    return 0;
}
