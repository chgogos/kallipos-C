#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int id;
  char title[100];
  char author[100];
  int year;
} book;

void add_book(book **books, int *current_count, int *max_size) {
  if (*current_count == *max_size) {
    *max_size *= 2;
    *books = realloc(*books, sizeof(book) * (*max_size));
    if (*books == NULL) {
      printf("Memory allocation failed.\n");
      exit(1);
    }
    printf("Library size doubled. New size is %d books.\n", *max_size);
  }

  printf("Enter book ID: ");
  scanf("%d", &((*books)[*current_count].id));
  printf("Enter book title: ");
  scanf(" %99s", (*books)[*current_count].title);
  printf("Enter author's name: ");
  scanf(" %99s", (*books)[*current_count].author);
  printf("Enter year of publication: ");
  scanf(" %d", &((*books)[*current_count].year));

  (*current_count)++;
}

void display_books(book *books, int current_count) {
  printf("Current books in the library (%d):\n", current_count);
  for (int i = 0; i < current_count; i++) {
    printf("ID: %d, Title: %s, Author: %s, Year: %d\n", books[i].id,
           books[i].title, books[i].author, books[i].year);
  }
}

int main(void) {
  int max_size = 2; // αρχικό μέγεθος της βιβλιοθήκης.
  int current_count = 0;
  book *books = malloc(sizeof(book) * max_size);

  if (books == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  int choice;

  do {
    printf("\nLibrary Menu:\n");
    printf("1. Add a book\n");
    printf("2. Display all books\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      add_book(&books, &current_count, &max_size);
      break;
    case 2:
      display_books(books, current_count);
      break;
    case 3:
      printf("Exiting the program.\n");
      break;
    default:
      printf("Invalid choice. Please try again.\n");
    }
  } while (choice != 3);

  free(books);
  return 0;
}
