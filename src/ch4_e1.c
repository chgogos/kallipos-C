#include <stdio.h>

double temperature_conversion(double temperature, char scale) {
    if (scale == 'C' || scale == 'c') {
        // Μετατροπή από Κελσίου σε Φάρεναϊτ
        return temperature * 9.0/5.0 + 32;
    } else if (scale == 'F' || scale == 'f') {
        // Μετατροπή από Φάρεναϊτ σε Κελσίου
        return (temperature - 32) * 5.0/9.0;
    } else {
        // Λάθος κλίμακα
        printf("Λάθος κλίμακα. Παρακαλώ εισάγετε 'C' ή 'F'.\n");
        return -1;
    }
}

int main(void) {
    double temp;
    char scale;

    printf("Παρακαλώ εισάγετε τη θερμοκρασία: ");
    scanf("%lf", &temp);
    printf("Εισάγετε την κλίμακα (C/F): ");
    scanf(" %c", &scale); // Προσοχή στο κενό πριν το %c για να προσπεράσει το newline

    double converted_temp = temperature_conversion(temp, scale);
    if (converted_temp != -1) {
        if (scale == 'C' || scale == 'c') {
            printf("%.2lf°C αντιστοιχούν σε %.2lf°F\n", temp, converted_temp);
        } else {
            printf("%.2lf°F αντιστοιχούν σε %.2lf°C\n", temp, converted_temp);
        }
    }

    return 0;
}
