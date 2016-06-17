int romanNumeralStringToInteger(const char* str)
{
    if(str[0] == 'I')
    {
        return 1;
    }
    else if(str[0] == 'V')
    {
        return 5;
    }
    else if(str[0] == 'X')
    {
        return 10;
    }
    else if(str[0] == 'L')
    {
        return 50;
    }
    else if(str[0] == 'C')
    {
        return 100;
    }
    else if(str[0] == 'D')
    {
        return 500;
    }
    else if(str[0] == 'M')
    {
        return 1000;
    }

    return 0;
}
