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

START_TEST (test_create_client)
{
    struct Person *temp = create_client("1", "Test Testing", "test@testing.com", 1980, 3, 25);

    ck_assert_str_eq(temp->id, "1");
    ck_assert_str_eq(temp->name, "Test Testing");
    ck_assert_str_eq(temp->email, "test@testing.com");
    ck_assert_int_eq(temp->date_of_birth, 325461600);
}
END_TEST

START_TEST (test_create_account)
{
    struct Account *temp = create_account("1001001", "000001001");

    ck_assert_str_eq(temp->account_no, "1001001");
    ck_assert_str_eq(temp->owner, "000001001");
    ck_assert_str_eq(temp->balance, "0");
}
END_TEST

START_TEST (test_create_transaction)
{
    struct Transaction *temp = create_transaction("000001001", "000020001", "100");

    ck_assert_str_eq(temp->sender, "000001001");
    ck_assert_str_eq(temp->receiver, "000020001");
    ck_assert_str_eq(temp->amount, "100");
}
END_TEST

START_TEST (test_edit_transaction_date)
{
    struct Transaction *temp = create_transaction("000001001", "000020001", "100");
    time_t test_time = create_timestamp(1980, 3, 25, 0, 0, 0, 0);
    edit_transaction_date(temp, test_time);

    ck_assert_int_eq(temp->date_of_transaction, 325461600);
}
END_TEST

START_TEST (test_edit_transaction_date_with_zeros)
{
    struct Transaction *temp = create_transaction("000001001", "000020001", "100");
    time_t test_time = create_timestamp(0, 0, 0, 0, 0, 0, 0);
    edit_transaction_date(temp, test_time);

    ck_assert_int_eq(temp->date_of_transaction, -62167311589);
}
END_TEST

START_TEST (test_insert_head)
{
    struct Node *test_head = NULL, *test_tail = NULL;
    unsigned tests_size = sizeof(struct Person); 
    
    struct Person *test2 = create_client("000001001\0", "Alli Halonen\0", "alli@simo.com\0", 1975, 2, 1);
    struct Person *test1 = create_client("000020001\0", "Bertta Permanto\0", "bertta@timo.com\0", 1965, 4, 23);
    struct Person *test3 = create_client("000021001\0", "Caleb Kuolema\0", "caleb@simo.com\0", 1945, 2, 1);
    struct Person *test4 = create_client("000220001\0", "Aarvid Jauhiainen\0", "daavid@timo.com\0", 1980, 3, 25);

    insert_head(&test_head, &test_tail, test3, tests_size);
    insert_head(&test_head, &test_tail, test2, tests_size);
    insert_head(&test_head, &test_tail, test1, tests_size);
    insert_head(&test_head, &test_tail, test4, tests_size);

    struct Person *temp = (struct Person *)test_head->data;
    ck_assert_str_eq(temp->id, "000220001");
    ck_assert_str_eq(temp->name, "Aarvid Jauhiainen");
    ck_assert_str_eq(temp->email, "daavid@timo.com");
    ck_assert_int_eq(temp->date_of_birth, 325461600);
}
END_TEST

START_TEST (test_insert_tail)
{
    struct Node *test_head = NULL, *test_tail = NULL;
    unsigned tests_size = sizeof(struct Person); 
    
    struct Person *test2 = create_client("000001001\0", "Alli Halonen\0", "alli@simo.com\0", 1975, 2, 1);
    struct Person *test1 = create_client("000020001\0", "Bertta Permanto\0", "bertta@timo.com\0", 1965, 4, 23);
    struct Person *test3 = create_client("000021001\0", "Caleb Kuolema\0", "caleb@simo.com\0", 1945, 2, 1);
    struct Person *test4 = create_client("000220001\0", "Aarvid Jauhiainen\0", "daavid@timo.com\0", 1980, 3, 25);

    insert_head(&test_head, &test_tail, test3, tests_size);
    insert_tail(&test_head, &test_tail, test2, tests_size);
    insert_tail(&test_head, &test_tail, test1, tests_size);
    insert_tail(&test_head, &test_tail, test4, tests_size);

    struct Person *temp = (struct Person *)test_tail->data;
    ck_assert_str_eq(temp->id, "000220001");
    ck_assert_str_eq(temp->name, "Aarvid Jauhiainen");
    ck_assert_str_eq(temp->email, "daavid@timo.com");
    ck_assert_int_eq(temp->date_of_birth, 325461600);
}
END_TEST

START_TEST (test_insert_middle)
{
    struct Node *test_head = NULL, *test_tail = NULL;
    unsigned tests_size = sizeof(struct Person); 
    
    struct Person *test2 = create_client("000001001\0", "Alli Halonen\0", "alli@simo.com\0", 1975, 2, 1);
    struct Person *test1 = create_client("000020001\0", "Bertta Permanto\0", "bertta@timo.com\0", 1965, 4, 23);
    struct Person *test3 = create_client("000021001\0", "Caleb Kuolema\0", "caleb@simo.com\0", 1945, 2, 1);
    struct Person *test4 = create_client("220001\0", "Aarvid Jauhiainen\0", "daavid@timo.com\0", 1980, 3, 25);

    insert_head(&test_head, &test_tail, test3, tests_size);
    insert_head(&test_head, &test_tail, test2, tests_size);
    insert_head(&test_head, &test_tail, test1, tests_size);
    insert_middle(&test_head, test_head, test4, tests_size);

    struct Person *temp = (struct Person *)test_head->next->data;
    ck_assert_str_eq(temp->id, "220001");
    ck_assert_str_eq(temp->name, "Aarvid Jauhiainen");
    ck_assert_str_eq(temp->email, "daavid@timo.com");
    ck_assert_int_eq(temp->date_of_birth, 325461600);
}
END_TEST

START_TEST (test_get_list_lenght)
{
    struct Node *test_head = NULL, *client_tail = NULL;
    unsigned tests_size = sizeof(struct Person); 
    
    struct Person *test1 = create_client("000001001\0", "Alli Halonen\0", "alli@simo.com\0", 1975, 2, 1);
    struct Person *test2 = create_client("000020001\0", "Bertta Permanto\0", "bertta@timo.com\0", 1965, 4, 23);
    struct Person *test3 = create_client("000021001\0", "Caleb Kuolema\0", "caleb@simo.com\0", 1945, 2, 1);
    struct Person *test4 = create_client("000220001\0", "Daavid Jauhiainen\0", "daavid@timo.com\0", 2020, 4, 23);

    insert_head(&test_head, &client_tail, test3, tests_size);
    insert_head(&test_head, &client_tail, test2, tests_size);
    insert_head(&test_head, &client_tail, test1, tests_size);
    insert_head(&test_head, &client_tail, test4, tests_size);

    ck_assert_int_eq(get_list_lenght(test_head), 4);
}
END_TEST



int main(void)
{
    Suite *s1 = suite_create("BMS_utils");
    TCase *tc1_1 = tcase_create("BMS_utils");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, sanity_check);
    tcase_add_test(tc1_1, test_create_timestamp);
    tcase_add_test(tc1_1, test_create_client);
    tcase_add_test(tc1_1, test_create_account);
    tcase_add_test(tc1_1, test_create_transaction);
    tcase_add_test(tc1_1, test_edit_transaction_date);
    tcase_add_test(tc1_1, test_edit_transaction_date_with_zeros);
    tcase_add_test(tc1_1, test_get_list_lenght);
    tcase_add_test(tc1_1, test_insert_head);
    tcase_add_test(tc1_1, test_insert_tail);
    tcase_add_test(tc1_1, test_insert_middle);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}