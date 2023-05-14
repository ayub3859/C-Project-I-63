#include <stdio.h>

#define MAX_STUDENTS 100

struct Student {
    char name[50];
    int rollNo;
    float marks;
    char grade;
};

void calculateGrade(struct Student *student) {
    if (student->marks >= 90)
        student->grade = 'A';
    else if (student->marks >= 80)
        student->grade = 'B';
    else if (student->marks >= 70)
        student->grade = 'C';
    else if (student->marks >= 60)
        student->grade = 'D';
    else
        student->grade = 'F';
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents, i;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    if (numStudents > MAX_STUDENTS) {
        printf("Maximum number of students exceeded. Please try again.\n");
        return 1;
    }

    for (i = 0; i < numStudents; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Enter name: ");
        scanf(" %[^\n]s", students[i].name);
        printf("Enter roll number: ");
        scanf("%d", &students[i].rollNo);
        printf("Enter marks: ");
        scanf("%f", &students[i].marks);
        calculateGrade(&students[i]);
    }

    printf("\n\nStudent Data:\n");
    printf("----------------------------------------------\n");
    printf("Name\t\tRoll No\tMarks\tGrade\n");
    printf("----------------------------------------------\n");

    for (i = 0; i < numStudents; i++) {
        printf("%-15s%-8d%.2f\t%c\n", students[i].name, students[i].rollNo, students[i].marks, students[i].grade);
    }

    printf("----------------------------------------------\n");

    return 0;
}