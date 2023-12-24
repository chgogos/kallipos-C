#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int* array;
    int current_size, new_size, i;
    char choice;

    printf("Enter the initial size of the array: ");
    scanf("%d", &current_size);

    array = (int*)malloc(current_size * sizeof(int));
    if(array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for(i = 0; i < current_size; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &array[i]);
    }

    do {
        printf("Do you want to add more elements? (Y/N): ");
        scanf(" %c", &choice); 

        if(choice == 'Y' || choice == 'y') {
            printf("Enter the number of additional elements: ");
            scanf("%d", &new_size);

            // επέκταση του πίνακα με χρήση της realloc.
            int* temp = realloc(array, (current_size + new_size) * sizeof(int));
            if(temp == NULL) {
                fprintf(stderr, "Reallocation failed\n");
                free(array);
                return 1;
            }
            array = temp;

            // εισαγωγή των νέων στοιχείων στο τέλος του πίνακα.
            for(i = current_size; i < current_size + new_size; i++) {
                printf("Enter element %d: ", i);
                scanf("%d", &array[i]);
            }
            current_size += new_size;
        }
    } while(choice == 'Y' || choice == 'y');

    printf("Array elements are:\n");
    for(i = 0; i < current_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}
