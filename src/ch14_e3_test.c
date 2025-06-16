#include "ch14_e3_array.h"
#include "unity.h"

void setUp(void) {}

void tearDown(void) {}

void test_find_existing_element(void) {
  int array[] = {1, 2, 3, 4, 5};
  TEST_ASSERT_EQUAL_INT(2, find_index(array, 5, 3));
}

void test_find_non_existing_element(void) {
  int array[] = {1, 2, 3, 4, 5};
  TEST_ASSERT_EQUAL_INT(-1, find_index(array, 5, 6));
}

void test_find_element_in_empty_array(void) {
  int array[] = {};
  TEST_ASSERT_EQUAL_INT(-1, find_index(array, 0, 1));
}

void test_find_element_multiple_occurrences(void) {
  int array[] = {1, 2, 3, 2, 1};
  TEST_ASSERT_EQUAL_INT(1, find_index(array, 5, 2));
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_find_existing_element);
  RUN_TEST(test_find_non_existing_element);
  RUN_TEST(test_find_element_in_empty_array);
  RUN_TEST(test_find_element_multiple_occurrences);

  return UNITY_END();
}
