#include <stdio.h>

#define ARRAY_SIZE 10

// Συνάρτηση που αντιστρέφει τον πίνακα χρησιμοποιώντας δείκτες
void reverse_array(int* start, int* end) {
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main(void) {
    int arr[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    printf("Πίνακας πριν την αντιστροφή:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // reverse_array(arr, arr + ARRAY_SIZE - 1);
    reverse_array(&arr[3], &arr[8]);
    
    printf("Πίνακας μετά την αντιστροφή:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
