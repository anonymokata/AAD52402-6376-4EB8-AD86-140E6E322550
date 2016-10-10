#ifndef ROMAN_NUMERAL_H
#define ROMAN_NUMERAL_H

int toInteger(const char* str);
void toRomanNumeral(char* str, const int totalValue);
void addRomanNumerals(char* result, const char* romanNumeral1, const char* romanNumeral2);
void subtractRomanNumerals(char* result, const char* romanNumeral1, const char* romanNumeral2);

#endif // ROMAN_NUMERAL_H
