
#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

int searchStudent(const struct Student* students, int size, const char* name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return i;  // Return the index if name matches
        }
    }

    return -1;  // Return -1 if name is not found
}

void displayStudent(const struct Student* student) {
    printf("Roll No: %d\n", student->rollno);
    printf("Name: %s\n", student->name);
    printf("Marks: %.2f\n", student->marks);
    printf("\n");
}

int main() {
    const int size = 5;
    struct Student students[size] = {
        {1001, "John", 85.5},
        {1002, "Emma", 92.0},
        {1003, "Michael", 78.3},
        {1004, "Sophia", 89.7},
        {1005, "Daniel", 95.2}
    };

    const char* searchName = "Michael";
    int index = searchStudent(students, size, searchName);

    if (index != -1) {
        printf("Student found:\n");
        displayStudent(&students[index]);
    } else {
        printf("Student not found.\n");
    }

    return 0;
}