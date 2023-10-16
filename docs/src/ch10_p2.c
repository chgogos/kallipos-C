#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct student {
  int id;
  char name[20];
} student_t;

typedef struct node {
  student_t *a_student;
  struct node *next;
} node_t;

void read_student(student_t *s);
void insert_student_at_begin(node_t **head);
void insert_student_at_end(node_t **head);
void delete_student_by_id(node_t **head, int id);
void delete_all_students(node_t **head);
void print_all_students(node_t *head);

int main(void) {
  node_t *head = NULL;
  int choice = 0;
  while (true) {
    printf("--------------------------------------------\n");
    printf("1. Display all students\n");
    printf("2. Insert a student at the begin of the list\n");
    printf("3. Insert a student at the end of the list\n");
    printf("4. Delete student by id\n");
    printf("5. Delete all students\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("--------------------------------------------\n");
    switch (choice) {
    case 1: {
      print_all_students(head);
      break;
    }
    case 2: {
      insert_student_at_begin(&head);
      break;
    }
    case 3: {
      insert_student_at_end(&head);
      break;
    }
    case 4: {
      int id;
      printf("Input student's id to delete: ");
      scanf("%d", &id);
      delete_student_by_id(&head, id);
      break;
    }
    case 5: {
      delete_all_students(&head);
      break;
    }
    case 6: {
      printf("End of program\n");
      return 0;
    }
    default:
      printf("Wrong choice");
    }
  }
  return 0;
}

void read_student(student_t *s) {
  printf("Enter id and name of student: ");
  scanf("%d%s", &s->id, s->name);
}

void insert_student_at_begin(node_t **head) {
  student_t *student_ptr = malloc(sizeof(student_t));
  if (student_ptr == NULL) {
    printf("Unable to allocate memory!\n");
    exit(-1);
  }
  read_student(student_ptr);

  node_t *node_ptr = malloc(sizeof(node_t));
  if (node_ptr == NULL) {
    printf("Unable to allocate memory!\n");
    exit(-1);
  }
  node_ptr->a_student = student_ptr;
  node_ptr->next = NULL;

  if (*head == NULL) {
    *head = node_ptr;
    return;
  }
  node_ptr->next = *head;
  *head = node_ptr;
}

void insert_student_at_end(node_t **head) {
  student_t *student_ptr = malloc(sizeof(student_t));
  if (student_ptr == NULL) {
    printf("Unable to allocate memory!\n");
    exit(-1);
  }
  read_student(student_ptr);

  node_t *node_ptr = malloc(sizeof(node_t));
  if (node_ptr == NULL) {
    printf("Unable to allocate memory!\n");
    exit(-1);
  }
  node_ptr->a_student = student_ptr;
  node_ptr->next = NULL;

  if (*head == NULL) {
    *head = node_ptr;
    return;
  }
  node_t *curr = *head;
  while (curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = node_ptr;
}

void delete_student_by_id(node_t **head, int id) {
  node_t *curr = *head;
  // αν η λίστα είναι άδεια
  if (curr == NULL) {
    printf("There is no student with id=%d (the list is empty!)\n", id);
    return;
  }

  // αν ο φοιτητής βρίσκεται στην κεφαλή της συνδεδεμένης λίστας
  if (curr->a_student->id == id) {
    *head = curr->next;
    free(curr->a_student);
    free(curr);
    printf("Student with id=%d was deleted!\n", id);
    return;
  }

  // αν η λίστα έχει τουλάχιστον 2 κόμβους
  node_t *curr_prev = curr;
  curr = curr->next;
  while (curr != NULL) {
    // αν υπάρχει ο φοιτητής
    if (curr->a_student->id == id) {
      curr_prev->next = curr->next;
      free(curr->a_student);
      free(curr);
      printf("Student with id=%d was deleted!\n", id);
      return;
    }
    curr_prev = curr;
    curr = curr->next;
  }

  // ο φοιτητής δεν υπάρχει στη λίστα
  if (curr == NULL) {
    printf("There is no student with id=%d\n", id);
  }
}

void print_all_students(node_t *head) {
  node_t *curr = head;
  if (curr == NULL) {
    printf("The list is empty\n");
  }
  while (curr != NULL) {
    printf("ID=%d, NAME=%s\n", curr->a_student->id, curr->a_student->name);
    curr = curr->next;
  }
}

void delete_all_students(node_t **head) {
  int c = 0;
  node_t *curr = *head;
  while (curr != NULL) {
    free(curr->a_student);
    node_t *tmp = curr;
    curr = curr->next;
    free(tmp);
    c++;
  }
  *head = NULL;
  printf("List deleted (%d students)\n", c);
}
