#include <stdio.h>

// Δήλωση της συνάρτησης που δέχεται πίνακα ως όρισμα
void print_array_size(int arr[]) {
    // Εκτύπωση του μεγέθους του πίνακα εντός της συνάρτησης
    printf("Inside function: Array size = %zu bytes\n", sizeof(arr));
}

void print_elements(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int numbers[5] = {1, 2, 3, 4, 5};
    // Εκτύπωση του μεγέθους του πίνακα εκτός της συνάρτησης
    printf("Outside function: Array size = %zu bytes\n", sizeof(numbers));
    print_array_size(numbers);
    // Εκτύπωση των στοιχείων του πίνακα
    print_elements(numbers, 5);
    return 0;
}
