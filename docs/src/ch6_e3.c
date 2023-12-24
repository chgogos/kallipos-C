#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100
#define ISBN_LENGTH 13

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    char isbn[ISBN_LENGTH];
    int published_year;
    int copies;
} book;

book library[MAX_BOOKS];
int book_count = 0;

void addBook(void) {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }
    printf("Enter title: ");
    fgets(library[book_count].title, TITLE_LENGTH, stdin);
    strtok(library[book_count].title, "\n");  // αφαίρεση του χαρακτήρα αλλαγής γραμμής

    printf("Enter author: ");
    fgets(library[book_count].author, AUTHOR_LENGTH, stdin);
    strtok(library[book_count].author, "\n");

    printf("Enter ISBN: ");
    fgets(library[book_count].isbn, ISBN_LENGTH, stdin);
    strtok(library[book_count].isbn, "\n");

    printf("Enter published year: ");
    scanf("%d", &library[book_count].published_year);

    printf("Enter number of copies available: ");
    scanf("%d", &library[book_count].copies);

    book_count++;
    printf("Book added successfully!\n");
}

void display_books(void) {
    for (int i = 0; i < book_count; i++) {
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("ISBN: %s\n", library[i].isbn);
        printf("Published Year: %d\n", library[i].published_year);
        printf("Copies Available: %d\n\n", library[i].copies);
    }
}

int main(void) {
    int choice;
    do {
        printf("\nLibrary Management System:\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // για την "κατανάλωση" του χαρακτήρα αλλαγής γραμμής μετά τη scanf

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                display_books();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 3);
    return 0;
}
