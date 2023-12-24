#include "ch13_p1_io.h"
#include "ch13_p1_utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_cities(const char *filename, geo_city *cities, int *num_cities) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    return;
  }

  char line[100];
  int count = 0;
  while (fgets(line, sizeof(line), fp) != NULL && count < MAX_CITIES) {
    char *token = strtok(line, ";");
    strncpy(cities[count].city_name, token,
            sizeof(cities[count].city_name) - 1);

    token = strtok(NULL, ";");
    cities[count].lat = atof(token);

    token = strtok(NULL, ";");
    cities[count].lon = atof(token);

    token = strtok(NULL, "\n");
    if (strcmp(token, "Europe") == 0)
      cities[count].continent = EUROPE;
    else if (strcmp(token, "Asia") == 1)
      cities[count].continent = ASIA;
    else if (strcmp(token, "Africa") == 2)
      cities[count].continent = AFRICA;
    else if (strcmp(token, "North America") == 3)
      cities[count].continent = NORTH_AMERICA;
    else if (strcmp(token, "South America") == 4)
      cities[count].continent = SOUTH_AMERICA;
    else if (strcmp(token, "Oceania") == 5)
      cities[count].continent = OCEANIA;
    else if (strcmp(token, "Antarctica") == 6)
      cities[count].continent = ANTARCTICA;

    count++;
  }
  fclose(fp);

  if (count == MAX_CITIES) {
    fprintf(stderr, "Warning: reached maximum number of records\n");
  }

  *num_cities = count;
}
