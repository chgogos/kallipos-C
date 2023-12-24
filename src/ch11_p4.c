#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Για την getopt και την optarg

int main(int argc, char **argv) {
  int aflag = 0, bvalue = 0, option;
  double dvalue = 0.0;
  // Η μεταβλητή options περιέχει τα σύμβολα των παραμέτρων που αναμένεται να
  // δεχθεί το πρόγραμμα, το ':' μετά από ένα σύμβολο υποδηλώνει ότι η
  // παράμετρος αναμένει μια τιμή
  char *options = "ab:d:";
  // Χρησιμοποιούμε την getopt για να αναλύσουμε τις παραμέτρους της γραμμής εντολών
  while ((option = getopt(argc, argv, options)) != -1) {
    switch (option) {
    case 'a': // Σε περίπτωση που η παράμετρος είναι -a
      aflag = 1;
      break;
    case 'b': // Σε περίπτωση που η παράμετρος είναι -b
      bvalue = atoi(optarg); // optarg περιέχει τη συμβολοσειρά της τιμής που
                             // ακολουθεί το -b
      break;
    case 'd': // Σε περίπτωση που η παράμετρος είναι -d
      dvalue = atof(optarg); // optarg περιέχει τη συμβολοσειρά της τιμής που
                             // ακολουθεί το -d
      break;
    case '?': // Σε περίπτωση άγνωστης παραμέτρου
      printf("Error in parsing\n");
      return EXIT_FAILURE;
    }
  }
  printf("Command line arguments: a=%d  b=%d d=%lf\n", aflag, bvalue, dvalue);
  return 0;
}
