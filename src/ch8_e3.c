#include <stdio.h>

// Αντικαθιστά κάθε εμφάνιση του χαρακτήρα `symbol` στο αλφαριθμητικό `str` με τον χαρακτήρα 'X'
void replace_char_with_x(char *str, char symbol) {
    while (*str) {
        if (*str == symbol) {
            *str = 'X';
        }
        str++;
    }
}

int main(void) {
    char str[100];
    char symbol;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    printf("Enter the character you want to replace with 'X': ");
    scanf("%c", &symbol);
    replace_char_with_x(str, symbol);
    printf("Resulting string: %s\n", str);
    return 0;
}
