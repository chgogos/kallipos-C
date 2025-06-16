#include <stdio.h>
#include <string.h>

void replace_with_next_ascii(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = str[i] + 1;
    }
}

int main(void) {
    char string[100]; 

    printf("Enter a string: "); 
    fgets(string, sizeof(string), stdin); 
    string[strcspn(string, "\n")] = '\0'; // Αφαιρούμε τον χαρακτήρα νέας γραμμής
    replace_with_next_ascii(string); 
    printf("Modified string: %s\n", string);
    return 0;
}
