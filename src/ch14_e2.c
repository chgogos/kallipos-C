#include "unity.h"

void setUp() {}

void tearDown() {}

// Υπολογισμός του παραγοντικού του n (συνάρτηση που ελέγχεται)
long factorial(int n) {
  if (n < 0)
    return -1;
  if (n == 0)
    return 1;
  return n * factorial(n - 1);
}

void test_factorial_zero(void) { TEST_ASSERT_EQUAL_INT64(1, factorial(0)); }

void test_factorial_one(void) { TEST_ASSERT_EQUAL_INT64(1, factorial(1)); }

void test_factorial_positive(void) {
  TEST_ASSERT_EQUAL_INT64(120, factorial(5));
  TEST_ASSERT_EQUAL_INT64(3628800, factorial(10));
}

void test_factorial_negative(void) {
  TEST_ASSERT_EQUAL_INT64(-1, factorial(-5));
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_factorial_zero);
  RUN_TEST(test_factorial_one);
  RUN_TEST(test_factorial_positive);
  RUN_TEST(test_factorial_negative);

  return UNITY_END();
}
