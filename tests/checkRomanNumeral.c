#include <stdlib.h>
#include <check.h>
#include "../src/romanNumeral.h"

//======================================================
// toInteger Tests
//======================================================

START_TEST(test_toIntegerReturnsNegativeOneWhenNullPointer)
{
    ck_assert_int_eq (toInteger(NULL), -1);
}
END_TEST

START_TEST(test_toIntegerReturnsZero)
{
    ck_assert_int_eq (toInteger(""), 0);
}
END_TEST

START_TEST(test_toIntegerReturnsOneWhenI)
{
    ck_assert_int_eq (toInteger("I"), 1);
}
END_TEST

START_TEST(test_toIntegerReturnsTenWhenX)
{
    ck_assert_int_eq (toInteger("X"), 10);
}
END_TEST

START_TEST(test_toIntegerReturnsOneHundredWhenC)
{
    ck_assert_int_eq (toInteger("C"), 100);
}
END_TEST

START_TEST(test_toIntegerReturnsOneThousandWhenM)
{
    ck_assert_int_eq (toInteger("M"), 1000);
}
END_TEST

START_TEST(test_toIntegerReturnsNegativeOneWhenInvalidCharacter)
{
    ck_assert_int_eq (toInteger("A"), -1);
}
END_TEST

START_TEST(test_toIntegerReturnsZeroWhenEmptyString)
{
    ck_assert_int_eq (toInteger(""), 0);
}
END_TEST

START_TEST(test_toIntegerReturnsTwoWhenII)
{
    ck_assert_int_eq (toInteger("II"), 2);
}
END_TEST

START_TEST(test_toIntegerReturnsFourWhenIV)
{
    ck_assert_int_eq (toInteger("IV"), 4);
}
END_TEST

START_TEST(test_toIntegerReturnsThreeWhenIII)
{
    ck_assert_int_eq (toInteger("III"), 3);
}
END_TEST

START_TEST(test_toIntegerReturnsNegativeOneWhenIIII)
{
    ck_assert_int_eq (toInteger("IIII"), -1);
}
END_TEST

START_TEST(test_toIntegerReturnsThirtyWhenXXX)
{
    ck_assert_int_eq (toInteger("XXX"), 30);
}
END_TEST

START_TEST(test_toIntegerReturnsNegativeOneWhenXXXX)
{
    ck_assert_int_eq (toInteger("XXXX"), -1);
}
END_TEST

START_TEST(test_toIntegerReturnsThreeHundredWhenCCC)
{
    ck_assert_int_eq (toInteger("CCC"), 300);
}
END_TEST

START_TEST(test_toIntegerReturnsNegativeOneWhenCCCC)
{
    ck_assert_int_eq (toInteger("CCCC"), -1);
}
END_TEST

START_TEST(test_toIntegerReturnsFiveWhenV)
{
    ck_assert_int_eq (toInteger("V"), 5);
}
END_TEST

START_TEST(test_toIntegerReturnsNegativeOneWhenVV)
{
    ck_assert_int_eq (toInteger("VV"), -1);
}
END_TEST

START_TEST(test_toIntegerReturnsFiftyWhenL)
{
    ck_assert_int_eq (toInteger("L"), 50);
}
END_TEST

START_TEST(test_toIntegerReturnsNegativeOneWhenLL)
{
    ck_assert_int_eq (toInteger("LL"), -1);
}
END_TEST

START_TEST(test_toIntegerReturnsFiveHundredWhenD)
{
    ck_assert_int_eq (toInteger("D"), 500);
}
END_TEST

START_TEST(test_toIntegerReturnsNegativeOneWhenDD)
{
    ck_assert_int_eq (toInteger("DD"), -1);
}
END_TEST

START_TEST(test_toIntegerReturnsThreeThousandWhenMMM)
{
    ck_assert_int_eq (toInteger("MMM"), 3000);
}
END_TEST

START_TEST(test_toIntegerReturnsNegativeOneWhenMMMM)
{
    ck_assert_int_eq (toInteger("MMMM"), -1);
}
END_TEST

//======================================================
// timesCharacterRepeated Tests
//======================================================

START_TEST(test_timesCharacterRepeatedReturnsZeroWhenEmptyString)
{
    ck_assert_int_eq (timesCharacterRepeated(""), 0);
}
END_TEST

START_TEST(test_timesCharacterRepeatedReturnsOneWhenI)
{
    ck_assert_int_eq (timesCharacterRepeated("I"), 1);
}
END_TEST

START_TEST(test_timesCharacterRepeatedReturnsTwoWhenII)
{
    ck_assert_int_eq (timesCharacterRepeated("II"), 2);
}
END_TEST

START_TEST(test_timesCharacterRepeatedReturnsOneWhenIV)
{
    ck_assert_int_eq (timesCharacterRepeated("IV"), 1);
}
END_TEST

//======================================================
// toRomanNumeral Tests
//======================================================

START_TEST(test_toRomanNumeralDoesNotSegfaultWhenNullPointerPassedIn)
{
    toRomanNumeral(NULL, 0);
}
END_TEST

START_TEST(test_toRomanNumeralDoesNothingWhenNegativeInteger)
{
    char str[128] = "some_string";
    toRomanNumeral(str, -1);
    ck_assert_str_eq (str, "some_string");
}
END_TEST

START_TEST(test_toRomanNumeralSetsEmptyStringWhenZero)
{
    char str[128] = "";
    toRomanNumeral(str, 0);
    ck_assert_str_eq (str, "");
}
END_TEST

START_TEST(test_toRomanNumeralSetsIWhenOne)
{
    char str[128] = "";
    toRomanNumeral(str, 1);
    ck_assert_str_eq (str, "I");
}
END_TEST

START_TEST(test_toRomanNumeralSetsVWhenFive)
{
    char str[128] = "";
    toRomanNumeral(str, 5);
    ck_assert_str_eq (str, "V");
}
END_TEST

START_TEST(test_toRomanNumeralSetsXWhenTen)
{
    char str[128] = "";
    toRomanNumeral(str, 10);
    ck_assert_str_eq (str, "X");
}
END_TEST

START_TEST(test_toRomanNumeralSetsLWhenFifty)
{
    char str[128] = "";
    toRomanNumeral(str, 50);
    ck_assert_str_eq (str, "L");
}
END_TEST

START_TEST(test_toRomanNumeralSetsCWhenOneHundred)
{
    char str[128] = "";
    toRomanNumeral(str, 100);
    ck_assert_str_eq (str, "C");
}
END_TEST

START_TEST(test_toRomanNumeralSetsDWhenFiveHundred)
{
    char str[128] = "";
    toRomanNumeral(str, 500);
    ck_assert_str_eq (str, "D");
}
END_TEST

START_TEST(test_toRomanNumeralSetsMWhenOneThousand)
{
    char str[128] = "";
    toRomanNumeral(str, 1000);
    ck_assert_str_eq (str, "M");
}
END_TEST

START_TEST(test_toRomanNumeralSetsIVWhenFour)
{
    char str[128] = "";
    toRomanNumeral(str, 4);
    ck_assert_str_eq (str, "IV");
}
END_TEST

START_TEST(test_toRomanNumeralSetsIXWhenNine)
{
    char str[128] = "";
    toRomanNumeral(str, 9);
    ck_assert_str_eq (str, "IX");
}
END_TEST

START_TEST(test_toRomanNumeralSetsXLWhenForty)
{
    char str[128] = "";
    toRomanNumeral(str, 40);
    ck_assert_str_eq (str, "XL");
}
END_TEST

START_TEST(test_toRomanNumeralSetsXLWhenNinety)
{
    char str[128] = "";
    toRomanNumeral(str, 90);
    ck_assert_str_eq (str, "XC");
}
END_TEST

START_TEST(test_toRomanNumeralSetsCDWhenFourHundred)
{
    char str[128] = "";
    toRomanNumeral(str, 400);
    ck_assert_str_eq (str, "CD");
}
END_TEST

START_TEST(test_toRomanNumeralSetsCMWhenNineHundred)
{
    char str[128] = "";
    toRomanNumeral(str, 900);
    ck_assert_str_eq (str, "CM");
}
END_TEST

//======================================================
// addition Tests
//======================================================

START_TEST(test_addRomanNumeralsDoesNothingWhenLHSIsNull)
{
    char result[128] = "";
    char* romanNumeral1 = NULL;
    char romanNumeral2[] = "X";
    addRomanNumerals(result, romanNumeral1, romanNumeral2);
    ck_assert_str_eq (result, "");
}
END_TEST

START_TEST(test_addRomanNumeralsDoesNothingWhenRHSIsNull)
{
    char result[128] = "";
    char romanNumeral1[] = "X";
    char* romanNumeral2 = NULL;
    addRomanNumerals(result, romanNumeral1, romanNumeral2);
    ck_assert_str_eq (result, "");
}
END_TEST

START_TEST(test_addRomanNumeralsAddsOneAndOneToTwo)
{
    char result[128] = "";
    char romanNumeral1[] = "I";
    char romanNumeral2[] = "I";
    addRomanNumerals(result, romanNumeral1, romanNumeral2);
    ck_assert_str_eq (result, "II");
}
END_TEST

START_TEST(test_addRomanNumeralsAddsTwoAndTwoToFour)
{
    char result[128] = "";
    char romanNumeral1[] = "II";
    char romanNumeral2[] = "II";
    addRomanNumerals(result, romanNumeral1, romanNumeral2);
    ck_assert_str_eq (result, "IV");
}
END_TEST

//======================================================
// subtraction Tests
//======================================================

START_TEST(test_subtractRomanNumeralsDoesNothingWhenLHSIsNull)
{
    char result[128] = "";
    char* romanNumeral1 = NULL;
    char romanNumeral2[] = "X";
    addRomanNumerals(result, romanNumeral1, romanNumeral2);
    ck_assert_str_eq (result, "");
}
END_TEST

START_TEST(test_subtractRomanNumeralsDoesNothingWhenRHSIsNull)
{
    char result[128] = "";
    char romanNumeral1[] = "X";
    char* romanNumeral2 = NULL;
    addRomanNumerals(result, romanNumeral1, romanNumeral2);
    ck_assert_str_eq (result, "");
}
END_TEST

START_TEST(test_subtractRomanNumeralsSubtractsThreeMinusTwoResultingInOne)
{
    char result[128] = "";
    char romanNumeral1[] = "III";
    char romanNumeral2[] = "II";
    subtractRomanNumerals(result, romanNumeral1, romanNumeral2);
    ck_assert_str_eq (result, "I");
}
END_TEST

START_TEST(test_subtractRomanNumeralsSubtractsFourMinusOneResultingInThree)
{
    char result[128] = "";
    char romanNumeral1[] = "IV";
    char romanNumeral2[] = "I";
    subtractRomanNumerals(result, romanNumeral1, romanNumeral2);
    ck_assert_str_eq (result, "III");
}
END_TEST

Suite* romanNumeralSuite(void)
{
    Suite* s = suite_create("RomanNumeralSuite");

    TCase* tc_toInteger = tcase_create("toInteger");
    tcase_add_test(tc_toInteger, test_toIntegerReturnsNegativeOneWhenNullPointer);
    tcase_add_test(tc_toInteger, test_toIntegerReturnsZero);
    tcase_add_test(tc_toInteger, test_toIntegerReturnsOneWhenI);
    tcase_add_test(tc_toInteger, test_toIntegerReturnsTenWhenX);
    tcase_add_test(tc_toInteger, test_toIntegerReturnsOneHundredWhenC);
    tcase_add_test(tc_toInteger, test_toIntegerReturnsOneThousandWhenM);
    tcase_add_test(tc_toInteger, test_toIntegerReturnsNegativeOneWhenInvalidCharacter);
    tcase_add_test(tc_toInteger, test_toIntegerReturnsZeroWhenEmptyString);
    tcase_add_test(tc_toInteger, test_toIntegerReturnsTwoWhenII);
    tcase_add_test(tc_toInteger, test_toIntegerReturnsFourWhenIV);
    tcase_add_test(tc_toInteger, test_toIntegerReturnsThreeWhenIII);
    tcase_add_test(tc_toInteger, test_toIntegerReturnsNegativeOneWhenIIII);
    tcase_add_test(tc_toInteger, test_toIntegerReturnsThirtyWhenXXX);
    tcase_add_test(tc_toInteger, test_toIntegerReturnsNegativeOneWhenXXXX);
    tcase_add_test(tc_toInteger, test_toIntegerReturnsThreeHundredWhenCCC);
    tcase_add_test(tc_toInteger, test_toIntegerReturnsNegativeOneWhenCCCC);
    tcase_add_test(tc_toInteger, test_toIntegerReturnsFiveWhenV);
    tcase_add_test(tc_toInteger, test_toIntegerReturnsNegativeOneWhenVV);
    tcase_add_test(tc_toInteger, test_toIntegerReturnsFiftyWhenL);
    tcase_add_test(tc_toInteger, test_toIntegerReturnsNegativeOneWhenLL);
    tcase_add_test(tc_toInteger, test_toIntegerReturnsFiveHundredWhenD);
    tcase_add_test(tc_toInteger, test_toIntegerReturnsNegativeOneWhenDD);
    tcase_add_test(tc_toInteger, test_toIntegerReturnsThreeThousandWhenMMM);
    tcase_add_test(tc_toInteger, test_toIntegerReturnsNegativeOneWhenMMMM);
    suite_add_tcase(s, tc_toInteger);

    TCase* tc_timesCharacterRepeated = tcase_create("timesCharacterRepeated");
    tcase_add_test(tc_timesCharacterRepeated, test_timesCharacterRepeatedReturnsZeroWhenEmptyString);
    tcase_add_test(tc_timesCharacterRepeated, test_timesCharacterRepeatedReturnsOneWhenI);
    tcase_add_test(tc_timesCharacterRepeated, test_timesCharacterRepeatedReturnsTwoWhenII);
    tcase_add_test(tc_timesCharacterRepeated, test_timesCharacterRepeatedReturnsOneWhenIV);
    suite_add_tcase(s, tc_timesCharacterRepeated);

    TCase* tc_toRomanNumeral = tcase_create("toRomanNumeral");
    tcase_add_test(tc_toRomanNumeral, test_toRomanNumeralDoesNotSegfaultWhenNullPointerPassedIn);
    tcase_add_test(tc_toRomanNumeral, test_toRomanNumeralDoesNothingWhenNegativeInteger);
    tcase_add_test(tc_toRomanNumeral, test_toRomanNumeralSetsEmptyStringWhenZero);
    tcase_add_test(tc_toRomanNumeral, test_toRomanNumeralSetsIWhenOne);
    tcase_add_test(tc_toRomanNumeral, test_toRomanNumeralSetsVWhenFive);
    tcase_add_test(tc_toRomanNumeral, test_toRomanNumeralSetsXWhenTen);
    tcase_add_test(tc_toRomanNumeral, test_toRomanNumeralSetsLWhenFifty);
    tcase_add_test(tc_toRomanNumeral, test_toRomanNumeralSetsCWhenOneHundred);
    tcase_add_test(tc_toRomanNumeral, test_toRomanNumeralSetsDWhenFiveHundred);
    tcase_add_test(tc_toRomanNumeral, test_toRomanNumeralSetsMWhenOneThousand);
    tcase_add_test(tc_toRomanNumeral, test_toRomanNumeralSetsIVWhenFour);
    tcase_add_test(tc_toRomanNumeral, test_toRomanNumeralSetsIXWhenNine);
    tcase_add_test(tc_toRomanNumeral, test_toRomanNumeralSetsXLWhenForty);
    tcase_add_test(tc_toRomanNumeral, test_toRomanNumeralSetsXLWhenNinety);
    tcase_add_test(tc_toRomanNumeral, test_toRomanNumeralSetsCDWhenFourHundred);
    tcase_add_test(tc_toRomanNumeral, test_toRomanNumeralSetsCMWhenNineHundred);
    suite_add_tcase(s, tc_toRomanNumeral);

    TCase* tc_addRomanNumerals = tcase_create("addRomanNumerals");
    tcase_add_test(tc_addRomanNumerals, test_addRomanNumeralsDoesNothingWhenLHSIsNull);
    tcase_add_test(tc_addRomanNumerals, test_addRomanNumeralsDoesNothingWhenRHSIsNull);
    tcase_add_test(tc_addRomanNumerals, test_addRomanNumeralsAddsOneAndOneToTwo);
    tcase_add_test(tc_addRomanNumerals, test_addRomanNumeralsAddsTwoAndTwoToFour);
    suite_add_tcase(s, tc_addRomanNumerals);

    TCase* tc_subtractRomanNumerals = tcase_create("subtractRomanNumerals");
    tcase_add_test(tc_addRomanNumerals, test_subtractRomanNumeralsDoesNothingWhenLHSIsNull);
    tcase_add_test(tc_addRomanNumerals, test_subtractRomanNumeralsDoesNothingWhenRHSIsNull);
    tcase_add_test(tc_subtractRomanNumerals, test_subtractRomanNumeralsSubtractsThreeMinusTwoResultingInOne);
    tcase_add_test(tc_subtractRomanNumerals, test_subtractRomanNumeralsSubtractsFourMinusOneResultingInThree);
    suite_add_tcase(s, tc_subtractRomanNumerals);

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
