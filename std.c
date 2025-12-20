#include <stdio.h>

int main() {
    FILE *fp;
    char name[50];
    int roll;
    float m1, m2, m3, m4, m5, avg;

    // Open file in append mode
    fp = fopen("student_records.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Input student details
    printf("Enter student name: ");
    scanf("%s", name);
    printf("Enter roll number: ");
    scanf("%d", &roll);

    printf("Enter marks of 5 subjects: ");
    scanf("%f %f %f %f %f", &m1, &m2, &m3, &m4, &m5);

    avg = (m1 + m2 + m3 + m4 + m5) / 5;

    // Display result on screen
    printf("\nStudent Name: %s", name);
    printf("\nRoll Number: %d", roll);
    printf("\nAverage: %.2f", avg);

    // Calculate grade
    char grade;
    if (avg >= 90) grade = 'A';
    else if (avg >= 80) grade = 'B';
    else if (avg >= 70) grade = 'C';
    else if (avg >= 60) grade = 'D';
    else grade = 'F';

    printf("\nGrade: %c\n", grade);

    // Write data to file
    fprintf(fp, "Name: %s | Roll: %d | Average: %.2f | Grade: %c\n", name, roll, avg, grade);

    fclose(fp);

    printf("\nRecord saved successfully in student_records.txt!\n");

    return 0;
}

