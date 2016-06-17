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

Suite* romanNumeralSuite(void)
{
    Suite* s = suite_create("RomanNumeralSuite");

    TCase* tc_core = tcase_create("Core");
    tcase_add_test(tc_core, romanNumeralStringToIntegerReturnsZero);
    tcase_add_test(tc_core, romanNumeralStringToIntegerReturnsOneWhenI);
    tcase_add_test(tc_core, romanNumeralStringToIntegerReturnsFiveWhenV);
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
