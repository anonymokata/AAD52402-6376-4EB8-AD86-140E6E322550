#include <stdlib.h>
#include <check.h>

START_TEST(romanNumeralStringToIntegerReturnsZero)
{
    ck_assert_int_eq (romanNumeralStringToInteger(""), 0);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsOneWhenI)
{
    ck_assert_int_eq (romanNumeralStringToInteger("I"), 1);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsFiveWhenV)
{
    ck_assert_int_eq (romanNumeralStringToInteger("V"), 5);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsTenWhenX)
{
    ck_assert_int_eq (romanNumeralStringToInteger("X"), 10);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsFiftyWhenL)
{
    ck_assert_int_eq (romanNumeralStringToInteger("L"), 50);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsOneHundredWhenC)
{
    ck_assert_int_eq (romanNumeralStringToInteger("C"), 100);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsFiveHundredWhenD)
{
    ck_assert_int_eq (romanNumeralStringToInteger("D"), 500);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsOneThousandWhenM)
{
    ck_assert_int_eq (romanNumeralStringToInteger("M"), 1000);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsZeroWhenInvalidCharacter)
{
    ck_assert_int_eq (romanNumeralStringToInteger("A"), 0);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsZeroWhenEmptyString)
{
    ck_assert_int_eq (romanNumeralStringToInteger("A"), 0);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsTwoWhenII)
{
    ck_assert_int_eq (romanNumeralStringToInteger("II"), 2);
}
END_TEST

Suite* romanNumeralSuite(void)
{
    Suite* s = suite_create("RomanNumeralSuite");

    TCase* tc_core = tcase_create("Core");
    tcase_add_test(tc_core, romanNumeralStringToIntegerReturnsZero);
    tcase_add_test(tc_core, romanNumeralStringToIntegerReturnsOneWhenI);
    tcase_add_test(tc_core, romanNumeralStringToIntegerReturnsFiveWhenV);
    tcase_add_test(tc_core, romanNumeralStringToIntegerReturnsFiftyWhenL);
    tcase_add_test(tc_core, romanNumeralStringToIntegerReturnsFiveHundredWhenD);
    tcase_add_test(tc_core, romanNumeralStringToIntegerReturnsOneThousandWhenM);
    tcase_add_test(tc_core, romanNumeralStringToIntegerReturnsZeroWhenInvalidCharacter);
    tcase_add_test(tc_core, romanNumeralStringToIntegerReturnsZeroWhenEmptyString);
    tcase_add_test(tc_core, romanNumeralStringToIntegerReturnsTwoWhenII);
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
