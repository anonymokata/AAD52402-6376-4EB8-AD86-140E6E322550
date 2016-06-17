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

    return 0;
}
