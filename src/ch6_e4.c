#include <stdio.h>
#include <string.h>

#define STRING_SIZE 20

typedef union {
    int intValue;
    float floatValue;
    char stringValue[STRING_SIZE];
} data_value;

void display_menu(void) {
    printf("1. Input an integer\n");
    printf("2. Input a float\n");
    printf("3. Input a string\n");
    printf("4. View as an integer\n");
    printf("5. View as a float\n");
    printf("6. View as a string\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

int main(void) {
    data_value data;
    int choice;

    do {
        display_menu();
        scanf("%d", &choice);
        getchar();  // για την "κατανάλωση" του χαρακτήρα αλλαγής γραμμής μετά τη scanf
        switch (choice) {
            case 1:
                printf("Enter integer: ");
                scanf("%d", &data.intValue);
                break;
            case 2:
                printf("Enter float: ");
                scanf("%f", &data.floatValue);
                break;
            case 3:
                printf("Enter string: ");
                fgets(data.stringValue, STRING_SIZE, stdin);
                strtok(data.stringValue, "\n");  //  αφαίρεση του χαρακτήρα αλλαγής γραμμής
                break;
            case 4:
                printf("Data as integer: %d\n", data.intValue);
                break;
            case 5:
                printf("Data as float: %f\n", data.floatValue);
                break;
            case 6:
                printf("Data as string: %s\n", data.stringValue);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 7);
    return 0;
}
