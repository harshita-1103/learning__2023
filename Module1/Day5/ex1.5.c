#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseString(const char* input, struct Student* students, int size) {
    const char* delimiter = " ";

    char* token = strtok(input, delimiter);
    int index = 0;

    while (token != NULL && index < size) {
        students[index].rollno = atoi(token);

        token = strtok(NULL, delimiter);
        strncpy(students[index].name, token, sizeof(students[index].name));

        token = strtok(NULL, delimiter);
        students[index].marks = atof(token);

        token = strtok(NULL, delimiter);
        index++;
    }
}

int main() {
    const char* input = "1001 Aron 100.00";
    const int size = 1;
    struct Student students[size];

    parseString(input, students, size);

    printf("Parsed structure:\n");
    for (int i = 0; i < size; i++) {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }

    return 0;
}