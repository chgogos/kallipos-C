#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int n, m, num; 
    char character_value;
    printf("Enter the dimensions N (rows) and M (columns) of the array: ");
    scanf("%d %d", &n, &m);

    int total_size = n * m; // Συνολικό πλήθος στοιχείων του πίνακα.

    int *array = malloc(total_size * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    memset(array, 0, total_size * sizeof(int)); // αρχικοποίηση με 0.

    printf("Array after initialization with memset:\n");
    for (int i = 0; i < total_size; i++) {
        if (i > 0 && i % m == 0) {
            printf("\n");
        }
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("Enter an integer n (number of elements to replace): ");
    scanf("%d", &num);
    printf("Enter an ASCII character value for replacement: ");
    scanf(" %c", &character_value);

    if (num > 0 && num <= total_size) {
        // χρήση της memset για αντικατάσταση των num πρώτων στοιχείων.
        memset(array, character_value, num * sizeof(char));
    } else {
        printf("The number n is beyond the array's bounds.\n");
    }

    printf("Array after replacement:\n");
    for (int i = 0; i < total_size; i++) {
        if (i > 0 && i % m == 0) {
            printf("\n"); 
        }
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}
