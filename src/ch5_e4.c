#include <stdio.h>

#define ROWS 5
#define COLUMNS 3

int main() {
    int array[ROWS][COLUMNS];

    // Συμπλήρωση του πίνακα από το χρήστη
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("Εισάγετε το στοιχείο στη θέση [%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    // Εύρεση και εκτύπωση της μέγιστης τιμής ανά στήλη
    for (int j = 0; j < COLUMNS; j++) {
        int max_val = array[0][j];
        for (int i = 1; i < ROWS; i++) {
            if (array[i][j] > max_val) {
                max_val = array[i][j];
            }
        }
        printf("Η μέγιστη τιμή της στήλης %d είναι: %d\n", j, max_val);
    }

    return 0;
}
