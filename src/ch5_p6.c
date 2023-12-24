#include <stdio.h>

int calculate_sum(int arr[][4][2]) {
  int sum = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 2; k++) {
        sum += arr[i][j][k];
      }
    }
  }
  return sum;
}

int main(void) {
  int array[3][4][2] = {{{1, 2}, {3, 4}, {5, 6}, {7, 8}},
                        {{9, 10}, {11, 12}, {13, 14}, {15, 16}},
                        {{17, 18}, {19, 20}, {21, 22}, {23, 24}}};
  int sum = calculate_sum(array);
  printf("Sum of all elements in the 3D array: %d\n", sum);
  return 0;
}
