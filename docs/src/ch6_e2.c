#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20

typedef struct {
    char first_name[MAX_NAME_LENGTH];
    char last_name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_LENGTH];
} contact;

// Συνάρτηση ανάγνωσης νέας επαφής
contact read_contact(void) {
    contact new_contact;
    printf("Δώσε το όνομα: ");
    scanf("%49s", new_contact.first_name);
    printf("Δώσε το επίθετο: ");
    scanf("%49s", new_contact.last_name);
    printf("Δώσε τον τηλεφωνικό αριθμό: ");
    scanf("%19s", new_contact.phone_number);
    return new_contact;
}

// Συνάρτηση αλλαγής του τηλεφωνικού αριθμού μιας επαφής
void change_phone_number(contact *contacts, int n) {
    char lname[MAX_NAME_LENGTH];
    printf("Δώσε το επίθετο της επαφής που θέλεις να αλλάξεις: ");
    scanf("%49s", lname);

    for(int i = 0; i < n; i++) {
        if(strcmp(contacts[i].last_name, lname) == 0) {
            printf("Δώσε τον νέο τηλεφωνικό αριθμό: ");
            scanf("%19s", contacts[i].phone_number);
            return;
        }
    }
    printf("Δεν βρέθηκε επαφή με αυτό το επίθετο.\n");
}

// Συνάρτηση για την ταξινόμηση των επαφών με βάση το επίθετο
void sort_contacts(contact *contacts, int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(strcmp(contacts[i].last_name, contacts[j].last_name) > 0) {
                contact temp = contacts[i];
                contacts[i] = contacts[j];
                contacts[j] = temp;
            }
        }
    }
}

int main(void) {
    contact contacts[MAX_CONTACTS];
    int n = 0;  // Πόσες επαφές έχουν εισαχθεί

    int choice;
    while(1) {
        printf("\nΜενού:\n");
        printf("1. Προσθήκη νέας επαφής\n");
        printf("2. Αλλαγή τηλεφωνικού αριθμού\n");
        printf("3. Ταξινόμηση επαφών\n");
        printf("4. Εμφάνιση λίστας επαφών\n");
        printf("5. Έξοδος\n");
        printf("Επέλεξε μια επιλογή: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(n < MAX_CONTACTS) {
                    contacts[n] = read_contact();
                    n++;
                } else {
                    printf("Ο πίνακας επαφών είναι πλήρης.\n");
                }
                break;
            case 2:
                change_phone_number(contacts, n);
                break;
            case 3:
                sort_contacts(contacts, n);
                break;
            case 4:
                for(int i = 0; i < n; i++) {
                    printf("%s %s - %s\n", contacts[i].first_name, contacts[i].last_name, contacts[i].phone_number);
                }
                break;
            case 5:
                return 0;
            default:
                printf("Λάθος επιλογή.\n");
        }
    }
}
