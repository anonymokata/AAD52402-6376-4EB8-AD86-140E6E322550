#include <stdlib.h>
#include <check.h>
#include "../src/romanNumeral.h"

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


// VLD


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

START_TEST(toRomanNumeralSetsEmptyStringWhenZero)
{
    char str[128] = "";
    toRomanNumeral(str, str, 0);
    ck_assert_str_eq (str, "");
}
END_TEST

START_TEST(toRomanNumeralSetsIWhenOne)
{
    char str[128] = "";
    toRomanNumeral(str, str, 1);
    ck_assert_str_eq (str, "I");
}
END_TEST

START_TEST(toRomanNumeralSetsVWhenFive)
{
    char str[128] = "";
    toRomanNumeral(str, str, 5);
    ck_assert_str_eq (str, "V");
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

    suite_add_tcase(s, tc_toRomanNumeral);

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









