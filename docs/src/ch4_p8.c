#include <stdio.h>

void tower_of_hanoi(int n, char source, char destination, char aux) {
  if (n == 1) {
    printf("Move disk 1 from %c to %c\n", source, destination);
    return;
  }
  tower_of_hanoi(n - 1, source, aux, destination);
  printf("Move disk %d from %c to %c\n", n, source, destination);
  tower_of_hanoi(n - 1, aux, destination, source);
}

int main(void) {
  int num_disks;
  printf("Enter the number of disks: ");
  scanf("%d", &num_disks);
  printf("Solution:\n");
  tower_of_hanoi(num_disks, 'A', 'C', 'B');
  return 0;
}
