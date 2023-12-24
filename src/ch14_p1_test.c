#include "ch14_p1.h"
#include "unity.h"

void setUp(void) {}

void tearDown(void) {}

void test_has_size_ok(void) {
  TEST_ASSERT_TRUE(has_size_ok("abcde"));
  TEST_ASSERT_FALSE_MESSAGE(has_size_ok("ab"),
                            "The password must be at least 5 characters long");
  TEST_ASSERT_FALSE_MESSAGE(
      has_size_ok("012345678901234567890"),
      "The password must be no more than 20 characters long");
}

void test_has_digit(void) {
  TEST_ASSERT_TRUE(has_digit("abcde1"));
  TEST_ASSERT_FALSE_MESSAGE(has_digit("abcdef"),
                            "The password must have at least one digit");
}

void test_has_lowercase_letter(void) {
  TEST_ASSERT_TRUE(has_lowercase_letter("12345a"));
  TEST_ASSERT_FALSE_MESSAGE(
      has_lowercase_letter("12345A"),
      "The password must have at least one lowercase letter");
}

void test_has_uppercase_letter(void) {
  TEST_ASSERT_TRUE(has_uppercase_letter("ABCDEF"));
  TEST_ASSERT_FALSE_MESSAGE(
      has_uppercase_letter("123abc"),
      "The password must have at least one uppercase letter");
}

void test_is_valid_password(void) {
  TEST_ASSERT_TRUE(is_valid_password("A1234b"));
  TEST_ASSERT_TRUE(is_valid_password("abc123ABC"));
  TEST_ASSERT_FALSE(is_valid_password("Ab12"));
  TEST_ASSERT_FALSE(is_valid_password("Ab12345678901234567890"));
  TEST_ASSERT_FALSE(is_valid_password("AB123"));
  TEST_ASSERT_FALSE(is_valid_password("123ab"));
  TEST_ASSERT_FALSE(is_valid_password("AB123"));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_has_size_ok);
  TEST_IGNORE_MESSAGE("Not implemented yet");
  RUN_TEST(test_has_digit);
  RUN_TEST(test_has_lowercase_letter);
  RUN_TEST(test_has_uppercase_letter);
  RUN_TEST(test_is_valid_password);
  return UNITY_END();
}
