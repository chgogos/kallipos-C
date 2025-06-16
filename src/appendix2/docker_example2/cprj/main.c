#include <stdio.h>
#include <gmp.h>

int main(void) {
    mpz_t num1, num2, result;
    mpz_inits(num1, num2, result, NULL);
    mpz_set_str(num1, "123456789012345678901234567890", 10);
    mpz_set_str(num2, "987654321098765432109876543210", 10);
    mpz_add(result, num1, num2);
    gmp_printf("Result: %Zd\n", result);
    mpz_clears(num1, num2, result, NULL);
    return 0;
}
