#include <check.h>
#include <bms_utils.h>

START_TEST (sanity_check)
{
    fail_unless(5 == 5, "this should succeed");
}
END_TEST

START_TEST (test_create_timestamp)
{
    fail_unless(-7199 == create_timestamp(1970, 0, 1, 0, 0, 1, 0), "this should succeed");
    fail_unless(325461600 == create_timestamp(1980, 3, 25, 0, 0, 0, 0), "this shouldn't fail");
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, sanity_check);
    tcase_add_test(tc1_1, test_create_timestamp);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}