#include "ch13_p1_io.h"
#include "ch13_p1_utility.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Error: a filename must be provided as a command line argument.\n");
    return 1;
  }

  geo_city *cities = malloc(MAX_CITIES * sizeof(geo_city));
  if (cities == NULL) {
    fprintf(stderr, "Error allocating memory for records\n");
    return 1;
  }

  char *filename = argv[1];
  int N;
  read_cities(filename, cities, &N);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j)
        continue;
      double d =
          distance(cities[i].lat, cities[i].lon, cities[j].lat, cities[j].lon);
      printf("%s to %s distance %.1fkm\n", cities[i].city_name,
             cities[j].city_name, d);
    }
  }

  free(cities);
  return 0;
}
