#include <stdio.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void initializeStudents(struct Student* students, int size) {
    for (int i = 0; i < size; i++) {
        students[i].rollno = 0;
        students[i].name[0] = '\0';
        students[i].marks = 0.0;
    }
}

int main() {
    const int size = 5;
    struct Student students[size];

    initializeStudents(students, size);

    printf("Initialized structure:\n");
    for (int i = 0; i < size; i++) {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }

    return 0;
}
