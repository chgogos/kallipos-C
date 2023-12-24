#ifndef CH13_P1_UTILITY_H
#define CH13_P1_UTILITY_H

#define PI 3.141592

typedef enum {
  EUROPE,
  ASIA,
  AFRICA,
  NORTH_AMERICA,
  SOUTH_AMERICA,
  OCEANIA,
  ANTARCTICA
} Continent;

typedef struct {
  double lat;
  double lon;
  char city_name[100];
  Continent continent;
} geo_city;

double distance(double lat1, double lon1, double lat2, double lon2);
double deg2rad(double deg);
double rad2deg(double rad);

#endif
