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
