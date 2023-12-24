#include "ch14_e1.h"
#include "unity.h"

void setUp(void) {}

void tearDown(void) {}

void test_size_should_be_from_5_to_20(void) {
  TEST_ASSERT_FALSE_MESSAGE(is_valid_password("ab0!"),
                            "At least 5 characters are needed");
  TEST_ASSERT_FALSE_MESSAGE(is_valid_password("ab0!1234567890123456789"),
                            "At most 20 characters are needed");
}

void test_at_least_one_digit(void) {
  TEST_ASSERT_FALSE_MESSAGE(is_valid_password("abcdef"),
                            "At least one digit must exists");
}

void test_at_least_one_lowercase_letter(void) {
  TEST_ASSERT_FALSE_MESSAGE(is_valid_password("A123456@"),
                            "At least one lowercase letter must exists");
}

void test_at_least_one_uppercase_letter(void) {
  TEST_ASSERT_FALSE_MESSAGE(is_valid_password("a123456@"),
                            "At least one uppercase letter must exists");
}

void test_at_least_one_special(void) {
  TEST_ASSERT_FALSE_MESSAGE(is_valid_password("abc123"),
                            "At least one special character must exists");
  TEST_ASSERT_TRUE(is_valid_password("a1234@"));
}

void test_weak_passwords(void) {
  TEST_ASSERT_FALSE_MESSAGE(is_valid_password("password"), "Weak password");
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_size_should_be_from_5_to_20);
  RUN_TEST(test_at_least_one_digit);
  RUN_TEST(test_at_least_one_lowercase_letter);
  RUN_TEST(test_at_least_one_uppercase_letter);
  TEST_IGNORE_MESSAGE("Not implemented yet");
  RUN_TEST(test_weak_passwords);
  RUN_TEST(test_at_least_one_special);
  return UNITY_END();
}
