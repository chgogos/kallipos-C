#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int student_id;
    float grade;
} student;

typedef struct {
    student students[MAX_STUDENTS];
    int num_students;
} course;

void add_grade_by_id(course *c, int id, float grade) {
    for (int i = 0; i < c->num_students; i++) {
        if (c->students[i].student_id == id) {
            c->students[i].grade = grade;
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

void remove_grade_by_id(course *c, int id) {
    for (int i = 0; i < c->num_students; i++) {
        if (c->students[i].student_id == id) {
            c->students[i].grade = 0.0;  // Θεωρούμε ότι η αφαίρεση του βαθμού σημαίνει επαναφορά στο 0.0
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

void print_student_list(course *c) {
    for (int i = 0; i < c->num_students; i++) {
        printf("Name: %s, ID: %d, Grade: %.2f\n", c->students[i].name, c->students[i].student_id, c->students[i].grade);
    }
}

int main(void) {
    course my_course;
    my_course.num_students = 3;

    strcpy(my_course.students[0].name, "Nikos");
    my_course.students[0].student_id = 1;
    my_course.students[0].grade = 0.0;

    strcpy(my_course.students[1].name, "Maria");
    my_course.students[1].student_id = 2;
    my_course.students[1].grade = 0.0;

    strcpy(my_course.students[2].name, "Petros");
    my_course.students[2].student_id = 3;
    my_course.students[2].grade = 0.0;

    add_grade_by_id(&my_course, 2, 8.5);
    print_student_list(&my_course);  // Εκτύπωση της λίστας μετά την προσθήκη βαθμολογίας

    printf("\nRemoving grade for Maria...\n");
    remove_grade_by_id(&my_course, 2);
    print_student_list(&my_course);  // Εκτύπωση της λίστας μετά την αφαίρεση βαθμολογίας

    return 0;
}
