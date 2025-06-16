#include <stdio.h>
#include <math.h>

// Δήλωση του τύπου δεδομένων για τον κύκλο
typedef struct {
    double x;
    double y;
    double radius;
} circle;

// Συνάρτηση ανάγνωσης των στοιχείων ενός κύκλου
circle read_circle(void) {
    circle c;
    printf("Δώσε τη συντεταγμένη x του κέντρου του κύκλου: ");
    scanf("%lf", &c.x);
    printf("Δώσε τη συντεταγμένη y του κέντρου του κύκλου: ");
    scanf("%lf", &c.y);
    printf("Δώσε την ακτίνα του κύκλου: ");
    scanf("%lf", &c.radius);
    return c;
}

// Συνάρτηση εκτύπωσης του εμβαδού του κύκλου
void print_area(circle c) {
    double area = M_PI * c.radius * c.radius;
    printf("Το εμβαδόν του κύκλου είναι: %lf\n", area);
}

// Συνάρτηση εκτύπωσης της περιμέτρου του κύκλου
void print_perimeter(circle c) {
    double perimeter = 2 * M_PI * c.radius;
    printf("Η περιμέτρος του κύκλου είναι: %lf\n", perimeter);
}

int main(void) {
    circle c = read_circle();
    print_area(c);
    print_perimeter(c);
    return 0;
}
