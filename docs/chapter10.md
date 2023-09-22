# Κεφάλαιο 10

## Υλοποίηση δομών δεδομένων και αλγορίθμων στη C

### Υλοποίηση στοίβας
```{.c title="ch10_p1.c" linenums="1"}
#include <stdio.h>
#include <stdlib.h>

typedef struct task {
  int id;
} task_t;

typedef struct stack {
  task_t *tasks;
  int capacity;
  int count;
  task_t *top;
} my_stack_t;

my_stack_t *create_stack(int capacity);
int push(my_stack_t *s, int task_id);
task_t *pop(my_stack_t *s);
void print(my_stack_t *s);
void destroy_stack(my_stack_t *s);

int main(void) {
  // δημιουργία στοίβας με 5 θέσεις
  my_stack_t *stack_ptr = create_stack(5);

  // ώθηση στοιχείων στη στοίβα
  int job_ids[4] = {7, 21, 42, 33};
  for (int i = 0; i < 4; i++) {
    push(stack_ptr, job_ids[i]);
    printf("Task %d pushed, stack size/capacity=%d/%d\n", job_ids[i],
           stack_ptr->count, stack_ptr->capacity);
  }

  // εκτύπωση στοιχείων στοίβας
  print(stack_ptr);

  // απώθηση τεσσάρων στοιχείων από τη στοίβα, 1 προς 1
  for (int i = 0; i < 4; i++) {
    task_t *t = pop(stack_ptr);
    printf("Task %d popped, stack size/capacity=%d/%d\n", t->id,
           stack_ptr->count, stack_ptr->capacity);
  }

  // απόπειρα απώθησης από άδεια στοίβα
  pop(stack_ptr);

  destroy_stack(stack_ptr);
  return 0;
}

my_stack_t *create_stack(int capacity) {
  my_stack_t *s = malloc(sizeof(my_stack_t));
  if (s == NULL) {
    printf("Unable to allocate memory\n");
    exit(-1);
  }
  s->tasks = malloc(sizeof(task_t) * capacity);
  if (s->tasks == NULL) {
    printf("Unable to allocate memory\n");
    exit(-1);
  }
  s->count = 0;
  s->capacity = capacity;
  s->top = NULL;
  return s;
}

int push(my_stack_t *s, int task_id) {
  // έλεγχος αν η στοίβα είναι γεμάτη
  if (s->count == s->capacity) {
    printf("Push of %d failed: maximum capacity of %d is reached!\n", task_id,
           s->capacity);
    return -1;
  }
  // έλεγχος αν η στοίβα δεν έχει στοιχεία
  if (s->top == NULL) {
    s->top = s->tasks;
  } else {
    s->top++;
  }
  s->top->id = task_id;
  s->count++;
  return 0;
}

task_t *pop(my_stack_t *s) {
  // έλεγχος αν η στοίβα είναι άδεια
  if (s->count == 0) {
    printf("Pop failed: the stack is empty!\n");
    return NULL;
  }
  s->count--;
  // έλεγχος αν η στοίβα έχει 1 μόνο στοιχείο
  if (s->top == s->tasks) {
    s->top = NULL;
    return s->tasks;
  } else {
    s->top--;
    return s->top + 1;
  }
}

void print(my_stack_t *s) {
  printf("------\n");
  task_t *b_it = s->top; // iterator προς τα πίσω
  for (int i = 0; i < s->count; i++) {
    if (b_it == s->top) {
      printf("%d <--top\n", b_it->id);
    } else {
      printf("%d\n", b_it->id);
    }
    b_it--;
  }
  printf("------\n");
}

void destroy_stack(my_stack_t *s) {
  free(s->tasks);
  free(s);
}
```

### Υλοποίηση απλά συνδεδεμένης λίστας

```{.c title="ch10_p2.c" linenums="1"}
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
```


### Υλοποίηση δυαδικού δένδρου αναζήτησης

```{.c title="ch10_p3.c" linenums="1"}
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node_t;

void insert_node(node_t **tree_ptr, int value);
void inorder(node_t *tree_ptr);
void preorder(node_t *tree_ptr);
void postorder(node_t *tree_ptr);

int main(void) {
  node_t *root_ptr = NULL;
  int values[] = {5, 16, 8, 3, 7, 9, 11, 1, 2, 22};
  for (int i = 0; i < 10; i++) {
    insert_node(&root_ptr, values[i]);
  }

  printf("Inorder traversal\n");
  inorder(root_ptr);

  printf("\nPreorder traversal\n");
  preorder(root_ptr);

  printf("\nPostorder traversal\n");
  postorder(root_ptr);

  return 0;
}

void insert_node(node_t **tree_ptr, int value) {
  if (*tree_ptr == NULL) {
    *tree_ptr = malloc(sizeof(node_t));
    if (tree_ptr == NULL) {
      printf("Unable to allocate memory\n");
      exit(-1);
    }
    (*tree_ptr)->data = value;
    (*tree_ptr)->left = NULL;
    (*tree_ptr)->right = NULL;
    return;
  }
  if (value < (*tree_ptr)->data) {
    insert_node(&((*tree_ptr)->left), value);
  } else if (value > (*tree_ptr)->data) {
    insert_node(&((*tree_ptr)->right), value);
  }
}

void inorder(node_t *tree_ptr) {
  if (tree_ptr != NULL) {
    inorder(tree_ptr->left);
    printf("%2d ", tree_ptr->data);
    inorder(tree_ptr->right);
  }
}

void preorder(node_t *tree_ptr) {
  if (tree_ptr != NULL) {
    printf("%2d ", tree_ptr->data);
    preorder(tree_ptr->left);
    preorder(tree_ptr->right);
  }
}

void postorder(node_t *tree_ptr) {
  if (tree_ptr != NULL) {
    postorder(tree_ptr->left);
    postorder(tree_ptr->right);
    printf("%2d ", tree_ptr->data);
  }
}
```