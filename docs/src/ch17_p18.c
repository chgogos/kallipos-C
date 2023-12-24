#include <math.h>
#include <stdio.h>
#include <tgmath.h>

int main(void) {
  double angle_in_deg = 65.155; // γωνία σε μοίρες
  double angle_in_rad =
      angle_in_deg * acos(-1.0) / 180.0; // γωνία σε ακτίνια (double)
  float angle_in_rad_f =
      (float)angle_in_deg * acos(-1.0F) / 180.0F; // γωνία σε ακτίνια (float)
  long double angle_in_rad_Lf = (long double)angle_in_deg * acos(-1.0L) /
                                180.0L; // γωνία σε ακτίνια (long double)
  // χρήση macro sin από το <tgmath.h>
  printf("sinf(%.9f) using macro=%.9f\n", angle_in_rad_f, sin(angle_in_rad_f));
  printf("sin(%.17lf) using macro=%.17lf\n", angle_in_rad, sin(angle_in_rad));
  printf("sinl(%.21Lf) using macro=%.21Lf\n", angle_in_rad_Lf,
         sin(angle_in_rad_Lf));
  return 0;
}
