#include <stdio.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void displayStudents(const struct Student* students, int size) {
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

int main() {
    const int size = 3;
    struct Student students[size] = {
        {1001, "John", 85.5},
        {1002, "Emma", 92.0},
        {1003, "Michael", 78.3}
    };

    displayStudents(students, size);

    return 0;
}