#include <stdlib.h>
#include <check.h>

int helper(const char* str)
{
    int i = 0;
    romanNumeralStringToInteger(&i, str, &str[ strlen(str) - 1 ]);
    return i;
}

START_TEST(romanNumeralStringToIntegerReturnsZero)
{
    ck_assert_int_eq (helper(""), 0);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsOneWhenI)
{
    ck_assert_int_eq (helper("I"), 1);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsFiveWhenV)
{
    ck_assert_int_eq (helper("V"), 5);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsTenWhenX)
{
    ck_assert_int_eq (helper("X"), 10);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsFiftyWhenL)
{
    ck_assert_int_eq (helper("L"), 50);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsOneHundredWhenC)
{
    ck_assert_int_eq (helper("C"), 100);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsFiveHundredWhenD)
{
    ck_assert_int_eq (helper("D"), 500);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsOneThousandWhenM)
{
    ck_assert_int_eq (helper("M"), 1000);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsNegativeOneWhenInvalidCharacter)
{
    ck_assert_int_eq (helper("A"), -1);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsZeroWhenEmptyString)
{
    ck_assert_int_eq (helper(""), 0);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsTwoWhenII)
{
    ck_assert_int_eq (helper("II"), 2);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsThreeWhenIII)
{
    ck_assert_int_eq (helper("III"), 3);
}
END_TEST

START_TEST(romanNumeralStringToIntegerReturnsFourWhenIV)
{
    ck_assert_int_eq (helper("IV"), 4);
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
