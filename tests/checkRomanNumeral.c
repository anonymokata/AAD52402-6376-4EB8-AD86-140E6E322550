#include <stdlib.h>
#include <check.h>
#include "../src/romanNumeral.h"

START_TEST(romanNumeralStringToIntegerReturnsZero)
{
    ck_assert_int_eq (toInteger(""), 0);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsOneWhenI)
{
    ck_assert_int_eq (toInteger("I"), 1);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsFiveWhenV)
{
    ck_assert_int_eq (toInteger("V"), 5);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsTenWhenX)
{
    ck_assert_int_eq (toInteger("X"), 10);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsFiftyWhenL)
{
    ck_assert_int_eq (toInteger("L"), 50);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsOneHundredWhenC)
{
    ck_assert_int_eq (toInteger("C"), 100);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsFiveHundredWhenD)
{
    ck_assert_int_eq (toInteger("D"), 500);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsOneThousandWhenM)
{
    ck_assert_int_eq (toInteger("M"), 1000);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsNegativeOneWhenInvalidCharacter)
{
    ck_assert_int_eq (toInteger("A"), -1);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsZeroWhenEmptyString)
{
    ck_assert_int_eq (toInteger(""), 0);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsTwoWhenII)
{
    ck_assert_int_eq (toInteger("II"), 2);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsThreeWhenIII)
{
    ck_assert_int_eq (toInteger("III"), 3);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsFourWhenIV)
{
    ck_assert_int_eq (toInteger("IV"), 4);
}
END_TEST

Suite* romanNumeralSuite(void)
{
    Suite* s = suite_create("RomanNumeralSuite");

    TCase* tc_core = tcase_create("Core");
    tcase_add_test(tc_core, romanNumeralStringToIntegerReturnsZero);
    tcase_add_test(tc_core, romanNumeralStringToIntegerReturnsOneWhenI);
    tcase_add_test(tc_core, romanNumeralStringToIntegerReturnsFiveWhenV);
    tcase_add_test(tc_core, romanNumeralStringToIntegerReturnsTenWhenX);
    tcase_add_test(tc_core, romanNumeralStringToIntegerReturnsFiftyWhenL);
    tcase_add_test(tc_core, romanNumeralStringToIntegerReturnsOneHundredWhenC);
    tcase_add_test(tc_core, romanNumeralStringToIntegerReturnsFiveHundredWhenD);
    tcase_add_test(tc_core, romanNumeralStringToIntegerReturnsOneThousandWhenM);
    tcase_add_test(tc_core, romanNumeralStringToIntegerReturnsNegativeOneWhenInvalidCharacter);
    tcase_add_test(tc_core, romanNumeralStringToIntegerReturnsZeroWhenEmptyString);
    tcase_add_test(tc_core, romanNumeralStringToIntegerReturnsTwoWhenII);
    tcase_add_test(tc_core, romanNumeralStringToIntegerReturnsThreeWhenIII);
    tcase_add_test(tc_core, romanNumeralStringToIntegerReturnsFourWhenIV);
    suite_add_tcase(s, tc_core);
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
