int romanNumeralStringToInteger(const char* str)
{
    if(strcmp(str, "I") == 0)
    {
        return 1;
    }
    else if(strcmp(str, "V") == 0)
    {
        return 5;
    }
    else if(strcmp(str, "X") == 0)
    {
        return 10;
    }
    else if(strcmp(str, "L") == 0)
    {
        return 50;
    }
    else if(strcmp(str, "C") == 0)
    {
        return 100;
    }
    else if(strcmp(str, "D") == 0)
    {
        return 500;
    }

    return 0;
}
