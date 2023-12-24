#include <stdio.h>

int last_found(int *x, int n, int element) {
    for (int i = n-1; i >= 0; i--) {
        if (x[i] == element) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    int arr[] = {1, 2, 3, 4, 3, 5, 6, 7, 3, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]); // Υπολογισμός του μεγέθους του πίνακα
    int element = 3; // Το στοιχείο που ψάχνουμε
    int position = last_found(arr, n, element);
    if (position != -1) {
        printf("Το στοιχείο %d βρέθηκε για τελευταία φορά στη θέση %d.\n", element, position);
    } else {
        printf("Το στοιχείο %d δεν βρέθηκε στον πίνακα.\n", element);
    }
    return 0;
}
