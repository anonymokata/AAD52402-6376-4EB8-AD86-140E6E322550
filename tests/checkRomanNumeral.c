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

START_TEST(toIntegerReturnsFiveWhenV)
{
    ck_assert_int_eq (toInteger("V"), 5);
}
END_TEST

START_TEST(toIntegerReturnsTenWhenX)
{
    ck_assert_int_eq (toInteger("X"), 10);
}
END_TEST

START_TEST(toIntegerReturnsFiftyWhenL)
{
    ck_assert_int_eq (toInteger("L"), 50);
}
END_TEST

START_TEST(toIntegerReturnsOneHundredWhenC)
{
    ck_assert_int_eq (toInteger("C"), 100);
}
END_TEST

START_TEST(toIntegerReturnsFiveHundredWhenD)
{
    ck_assert_int_eq (toInteger("D"), 500);
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

START_TEST(toIntegerReturnsThreeWhenIII)
{
    ck_assert_int_eq (toInteger("III"), 3);
}
END_TEST

START_TEST(toIntegerReturnsFourWhenIV)
{
    ck_assert_int_eq (toInteger("IV"), 4);
}
END_TEST

Suite* romanNumeralSuite(void)
{
    Suite* s = suite_create("RomanNumeralSuite");

    TCase* tc_core = tcase_create("Core");
    tcase_add_test(tc_core, toIntegerReturnsZero);
    tcase_add_test(tc_core, toIntegerReturnsOneWhenI);
    tcase_add_test(tc_core, toIntegerReturnsFiveWhenV);
    tcase_add_test(tc_core, toIntegerReturnsTenWhenX);
    tcase_add_test(tc_core, toIntegerReturnsFiftyWhenL);
    tcase_add_test(tc_core, toIntegerReturnsOneHundredWhenC);
    tcase_add_test(tc_core, toIntegerReturnsFiveHundredWhenD);
    tcase_add_test(tc_core, toIntegerReturnsOneThousandWhenM);
    tcase_add_test(tc_core, toIntegerReturnsNegativeOneWhenInvalidCharacter);
    tcase_add_test(tc_core, toIntegerReturnsZeroWhenEmptyString);
    tcase_add_test(tc_core, toIntegerReturnsTwoWhenII);
    tcase_add_test(tc_core, toIntegerReturnsThreeWhenIII);
    tcase_add_test(tc_core, toIntegerReturnsFourWhenIV);
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
