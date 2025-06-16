typedef struct {
  char x;
  int y;
  double z;
} A;

typedef union {
  char x;
  int y;
  double z;
} B;

int main(void) {
  A a = {'a', 42, 3.14};
  B b = {'a'};
  b.y = 42;
  b.z = 3.14;
}