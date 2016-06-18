#include <stdlib.h>
#include <check.h>
#include "../src/romanNumeral.h"

//======================================================
// toInteger Tests
//======================================================

START_TEST(toIntegerReturnsZero)
{
    ck_assert_int_eq (toInteger(""), 0);
}
END_TEST

START_TEST(toIntegerReturnsOneWhenI)
{
    ck_assert_int_eq (toInteger("I"), 1);
}
END_TEST

START_TEST(toIntegerReturnsTenWhenX)
{
    ck_assert_int_eq (toInteger("X"), 10);
}
END_TEST

START_TEST(toIntegerReturnsOneHundredWhenC)
{
    ck_assert_int_eq (toInteger("C"), 100);
}
END_TEST

START_TEST(toIntegerReturnsOneThousandWhenM)
{
    ck_assert_int_eq (toInteger("M"), 1000);
}
END_TEST

START_TEST(toIntegerReturnsNegativeOneWhenInvalidCharacter)
{
    ck_assert_int_eq (toInteger("A"), -1);
}
END_TEST

START_TEST(toIntegerReturnsZeroWhenEmptyString)
{
    ck_assert_int_eq (toInteger(""), 0);
}
END_TEST

START_TEST(toIntegerReturnsTwoWhenII)
{
    ck_assert_int_eq (toInteger("II"), 2);
}
END_TEST

START_TEST(toIntegerReturnsFourWhenIV)
{
    ck_assert_int_eq (toInteger("IV"), 4);
}
END_TEST

START_TEST(toIntegerReturnsThreeWhenIII)
{
    ck_assert_int_eq (toInteger("III"), 3);
}
END_TEST

START_TEST(toIntegerReturnsNegativeOneWhenIIII)
{
    ck_assert_int_eq (toInteger("IIII"), -1);
}
END_TEST

START_TEST(toIntegerReturnsThirtyWhenXXX)
{
    ck_assert_int_eq (toInteger("XXX"), 30);
}
END_TEST

START_TEST(toIntegerReturnsNegativeOneWhenXXXX)
{
    ck_assert_int_eq (toInteger("XXXX"), -1);
}
END_TEST

START_TEST(toIntegerReturnsThreeHundredWhenCCC)
{
    ck_assert_int_eq (toInteger("CCC"), 300);
}
END_TEST

START_TEST(toIntegerReturnsNegativeOneWhenCCCC)
{
    ck_assert_int_eq (toInteger("CCCC"), -1);
}
END_TEST

START_TEST(toIntegerReturnsFiveWhenV)
{
    ck_assert_int_eq (toInteger("V"), 5);
}
END_TEST

START_TEST(toIntegerReturnsNegativeOneWhenVV)
{
    ck_assert_int_eq (toInteger("VV"), -1);
}
END_TEST

START_TEST(toIntegerReturnsFiftyWhenL)
{
    ck_assert_int_eq (toInteger("L"), 50);
}
END_TEST

START_TEST(toIntegerReturnsNegativeOneWhenLL)
{
    ck_assert_int_eq (toInteger("LL"), -1);
}
END_TEST

START_TEST(toIntegerReturnsFiveHundredWhenD)
{
    ck_assert_int_eq (toInteger("D"), 500);
}
END_TEST

START_TEST(toIntegerReturnsNegativeOneWhenDD)
{
    ck_assert_int_eq (toInteger("DD"), -1);
}
END_TEST

//======================================================
// timesCharacterRepeated Tests
//======================================================

START_TEST(timesCharacterRepeatedReturnsZeroWhenEmptyString)
{
    ck_assert_int_eq (timesCharacterRepeated(""), 0);
}
END_TEST

START_TEST(timesCharacterRepeatedReturnsOneWhenI)
{
    ck_assert_int_eq (timesCharacterRepeated("I"), 1);
}
END_TEST

START_TEST(timesCharacterRepeatedReturnsTwoWhenII)
{
    ck_assert_int_eq (timesCharacterRepeated("II"), 2);
}
END_TEST

START_TEST(timesCharacterRepeatedReturnsOneWhenIV)
{
    ck_assert_int_eq (timesCharacterRepeated("IV"), 1);
}
END_TEST

//======================================================
// toRomanNumeral Tests
//======================================================

START_TEST(toRomanNumeralSetsEmptyStringWhenZero)
{
    char str[128] = "";
    toRomanNumeral(str, 0);
    ck_assert_str_eq (str, "");
}
END_TEST

START_TEST(toRomanNumeralSetsIWhenOne)
{
    char str[128] = "";
    toRomanNumeral(str, 1);
    ck_assert_str_eq (str, "I");
}
END_TEST

START_TEST(toRomanNumeralSetsVWhenFive)
{
    char str[128] = "";
    toRomanNumeral(str, 5);
    ck_assert_str_eq (str, "V");
}
END_TEST

START_TEST(toRomanNumeralSetsXWhenTen)
{
    char str[128] = "";
    toRomanNumeral(str, 10);
    ck_assert_str_eq (str, "X");
}
END_TEST

START_TEST(toRomanNumeralSetsLWhenFifty)
{
    char str[128] = "";
    toRomanNumeral(str, 50);
    ck_assert_str_eq (str, "L");
}
END_TEST

START_TEST(toRomanNumeralSetsCWhenOneHundred)
{
    char str[128] = "";
    toRomanNumeral(str, 100);
    ck_assert_str_eq (str, "C");
}
END_TEST

START_TEST(toRomanNumeralSetsDWhenFiveHundred)
{
    char str[128] = "";
    toRomanNumeral(str, 500);
    ck_assert_str_eq (str, "D");
}
END_TEST

START_TEST(toRomanNumeralSetsMWhenOneThousand)
{
    char str[128] = "";
    toRomanNumeral(str, 1000);
    ck_assert_str_eq (str, "M");
}
END_TEST

START_TEST(toRomanNumeralSetsIVWhenFour)
{
    char str[128] = "";
    toRomanNumeral(str, 4);
    ck_assert_str_eq (str, "IV");
}
END_TEST

START_TEST(toRomanNumeralSetsIXWhenNine)
{
    char str[128] = "";
    toRomanNumeral(str, 9);
    ck_assert_str_eq (str, "IX");
}
END_TEST

START_TEST(toRomanNumeralSetsXLWhenForty)
{
    char str[128] = "";
    toRomanNumeral(str, 40);
    ck_assert_str_eq (str, "XL");
}
END_TEST

START_TEST(toRomanNumeralSetsXLWhenNinety)
{
    char str[128] = "";
    toRomanNumeral(str, 90);
    ck_assert_str_eq (str, "XC");
}
END_TEST

START_TEST(toRomanNumeralSetsCDWhenFourHundred)
{
    char str[128] = "";
    toRomanNumeral(str, 400);
    ck_assert_str_eq (str, "CD");
}
END_TEST

START_TEST(toRomanNumeralSetsCMWhenNineHundred)
{
    char str[128] = "";
    toRomanNumeral(str, 900);
    ck_assert_str_eq (str, "CM");
}
END_TEST

//======================================================
// Addition Tests
//======================================================

START_TEST(addEmptyStringandEmptyStringReturnsEmptyString)
{
    char str[128] = "";
    toRomanNumeral( str, toInteger("") + toInteger("") );
    ck_assert_str_eq (str, "");
}
END_TEST

START_TEST(addEmptyStringandIReturnsI)
{
    char str[128] = "";
    toRomanNumeral( str, toInteger("") + toInteger("I") );
    ck_assert_str_eq (str, "I");
}
END_TEST

START_TEST(addIandIReturnsII)
{
    char str[128] = "";
    toRomanNumeral( str, toInteger("I") + toInteger("I") );
    ck_assert_str_eq (str, "II");
}
END_TEST

START_TEST(addIandVReturnsVI)
{
    char str[128] = "";
    toRomanNumeral( str, toInteger("I") + toInteger("V") );
    ck_assert_str_eq (str, "VI");
}
END_TEST

START_TEST(addIIandIIReturnsIV)
{
    char str[128] = "";
    toRomanNumeral( str, toInteger("II") + toInteger("II") );
    ck_assert_str_eq (str, "IV");
}
END_TEST

START_TEST(addXandXReturnsXX)
{
    char str[128] = "";
    toRomanNumeral( str, toInteger("X") + toInteger("X") );
    ck_assert_str_eq (str, "XX");
}
END_TEST

START_TEST(addIVandVReturnsIX)
{
    char str[128] = "";
    toRomanNumeral( str, toInteger("IV") + toInteger("V") );
    ck_assert_str_eq (str, "IX");
}
END_TEST

//======================================================
// Subtraction Tests
//======================================================

START_TEST(subtractIFromIReturnsEmptyString)
{
    char str[128] = "";
    toRomanNumeral( str, toInteger("I") - toInteger("I") );
    ck_assert_str_eq (str, "");
}
END_TEST

START_TEST(subtractEmptyStringFromIReturnsI)
{
    char str[128] = "";
    toRomanNumeral( str, toInteger("I") - toInteger("") );
    ck_assert_str_eq (str, "I");
}
END_TEST

START_TEST(subtractIVFromXIReturnsVI)
{
    char str[128] = "";
    toRomanNumeral( str, toInteger("X") - toInteger("IV") );
    ck_assert_str_eq (str, "VI");
}
END_TEST

START_TEST(subtractIFromVReturnsIV)
{
    char str[128] = "";
    toRomanNumeral( str, toInteger("V") - toInteger("I") );
    ck_assert_str_eq (str, "IV");
}
END_TEST

Suite* romanNumeralSuite(void)
{
    Suite* s = suite_create("RomanNumeralSuite");

    TCase* tc_toInteger = tcase_create("toInteger");
    tcase_add_test(tc_toInteger, toIntegerReturnsZero);
    tcase_add_test(tc_toInteger, toIntegerReturnsOneWhenI);
    tcase_add_test(tc_toInteger, toIntegerReturnsTenWhenX);
    tcase_add_test(tc_toInteger, toIntegerReturnsOneHundredWhenC);
    tcase_add_test(tc_toInteger, toIntegerReturnsOneThousandWhenM);
    tcase_add_test(tc_toInteger, toIntegerReturnsNegativeOneWhenInvalidCharacter);
    tcase_add_test(tc_toInteger, toIntegerReturnsZeroWhenEmptyString);
    tcase_add_test(tc_toInteger, toIntegerReturnsTwoWhenII);
    tcase_add_test(tc_toInteger, toIntegerReturnsFourWhenIV);
    tcase_add_test(tc_toInteger, toIntegerReturnsThreeWhenIII);
    tcase_add_test(tc_toInteger, toIntegerReturnsNegativeOneWhenIIII);
    tcase_add_test(tc_toInteger, toIntegerReturnsThirtyWhenXXX);
    tcase_add_test(tc_toInteger, toIntegerReturnsNegativeOneWhenXXXX);
    tcase_add_test(tc_toInteger, toIntegerReturnsThreeHundredWhenCCC);
    tcase_add_test(tc_toInteger, toIntegerReturnsNegativeOneWhenCCCC);
    tcase_add_test(tc_toInteger, toIntegerReturnsFiveWhenV);
    tcase_add_test(tc_toInteger, toIntegerReturnsNegativeOneWhenVV);
    tcase_add_test(tc_toInteger, toIntegerReturnsFiftyWhenL);
    tcase_add_test(tc_toInteger, toIntegerReturnsNegativeOneWhenLL);
    tcase_add_test(tc_toInteger, toIntegerReturnsFiveHundredWhenD);
    tcase_add_test(tc_toInteger, toIntegerReturnsNegativeOneWhenDD);
    suite_add_tcase(s, tc_toInteger);

    TCase* tc_timesCharacterRepeated = tcase_create("timesCharacterRepeated");
    tcase_add_test(tc_timesCharacterRepeated, timesCharacterRepeatedReturnsZeroWhenEmptyString);
    tcase_add_test(tc_timesCharacterRepeated, timesCharacterRepeatedReturnsOneWhenI);
    tcase_add_test(tc_timesCharacterRepeated, timesCharacterRepeatedReturnsTwoWhenII);
    tcase_add_test(tc_timesCharacterRepeated, timesCharacterRepeatedReturnsOneWhenIV);
    suite_add_tcase(s, tc_timesCharacterRepeated);

    TCase* tc_toRomanNumeral = tcase_create("toRomanNumeral");
    tcase_add_test(tc_toRomanNumeral, toRomanNumeralSetsEmptyStringWhenZero);
    tcase_add_test(tc_toRomanNumeral, toRomanNumeralSetsIWhenOne);
    tcase_add_test(tc_toRomanNumeral, toRomanNumeralSetsVWhenFive);
    tcase_add_test(tc_toRomanNumeral, toRomanNumeralSetsXWhenTen);
    tcase_add_test(tc_toRomanNumeral, toRomanNumeralSetsLWhenFifty);
    tcase_add_test(tc_toRomanNumeral, toRomanNumeralSetsCWhenOneHundred);
    tcase_add_test(tc_toRomanNumeral, toRomanNumeralSetsDWhenFiveHundred);
    tcase_add_test(tc_toRomanNumeral, toRomanNumeralSetsMWhenOneThousand);
    tcase_add_test(tc_toRomanNumeral, toRomanNumeralSetsIVWhenFour);
    tcase_add_test(tc_toRomanNumeral, toRomanNumeralSetsIXWhenNine);
    tcase_add_test(tc_toRomanNumeral, toRomanNumeralSetsXLWhenForty);
    tcase_add_test(tc_toRomanNumeral, toRomanNumeralSetsXLWhenNinety);
    tcase_add_test(tc_toRomanNumeral, toRomanNumeralSetsCDWhenFourHundred);
    tcase_add_test(tc_toRomanNumeral, toRomanNumeralSetsCMWhenNineHundred);
    suite_add_tcase(s, tc_toRomanNumeral);

    TCase* tc_addition = tcase_create("AdditionTests");
    tcase_add_test(tc_addition, addEmptyStringandEmptyStringReturnsEmptyString);
    tcase_add_test(tc_addition, addEmptyStringandIReturnsI);
    tcase_add_test(tc_addition, addIandIReturnsII);
    tcase_add_test(tc_addition, addIandVReturnsVI);
    tcase_add_test(tc_addition, addIIandIIReturnsIV);
    tcase_add_test(tc_addition, addIVandVReturnsIX);
    suite_add_tcase(s, tc_addition);

    TCase* tc_subtraction = tcase_create("SubtractionTests");
    tcase_add_test(tc_subtraction, subtractIFromIReturnsEmptyString);
    tcase_add_test(tc_subtraction, subtractEmptyStringFromIReturnsI);
    tcase_add_test(tc_subtraction, subtractIVFromXIReturnsVI);
    tcase_add_test(tc_subtraction, subtractIFromVReturnsIV);
    suite_add_tcase(s, tc_subtraction);

    return s;
}

int main(void)
{
    int numberFailed;
    Suite* s = romanNumeralSuite();
    SRunner* sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    numberFailed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (numberFailed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
