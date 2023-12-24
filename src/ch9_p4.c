#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n, i, element;
  int *v, *save_pointer;
  printf("Input number of elements: ");
  scanf("%d", &n);
  v = malloc(n * sizeof(int));
  save_pointer = v;
  printf("Start: pointer to the start of the array: %p\n", (void *)v);
  for (i = 0; i < n; i++) {
    printf("Input value of element %d: ", i);
    scanf("%d", &v[i]);
  }
  printf("Search for element: ");
  scanf("%d", &element);
  i = 0;
  while (i != n && *v++ != element) {
    i++;
  }
  if (i != n) {
    printf("Element %d is found at %d position \n", element, i);
  } else {
    printf("Element %d not found\n", element);
  }
  v = save_pointer;
  printf("Finish: pointer to the start of the array: %p\n", (void *)v);
  free(v);
  return 0;
}
