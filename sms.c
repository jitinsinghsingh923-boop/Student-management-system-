#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student
{
    int rollNo;
    char name[50];
    int age;
    char course[50];
    float marks;
};

struct Student students[MAX];
int count = 0;

/* Add Student */
void addStudent()
{
    if (count >= MAX)
    {
        printf("\nStudent limit reached!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &students[count].rollNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", students[count].name);

    printf("Enter Age: ");
    scanf("%d", &students[count].age);

    printf("Enter Course: ");
    scanf(" %[^\n]", students[count].course);

    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);

    count++;

    printf("\nStudent added successfully!\n");
}

/* Display Students */
void displayStudents()
{
    int i;

    if (count == 0)
    {
        printf("\nNo students found!\n");
        return;
    }

    printf("\n========== STUDENT LIST ==========\n");

    for (i = 0; i < count; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("Roll Number : %d\n", students[i].rollNo);
        printf("Name        : %s\n", students[i].name);
        printf("Age         : %d\n", students[i].age);
        printf("Course      : %s\n", students[i].course);
        printf("Marks       : %.2f\n", students[i].marks);
    }
}

/* Search Student */
void searchStudent()
{
    int roll, i;
    int found = 0;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++)
    {
        if (students[i].rollNo == roll)
        {
            printf("\nStudent Found!\n");
            printf("Roll Number : %d\n", students[i].rollNo);
            printf("Name        : %s\n", students[i].name);
            printf("Age         : %d\n", students[i].age);
            printf("Course      : %s\n", students[i].course);
            printf("Marks       : %.2f\n", students[i].marks);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nStudent not found!\n");
    }
}

/* Update Student */
void updateStudent()
{
    int roll, i;
    int found = 0;

    printf("\nEnter Roll Number to update: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++)
    {
        if (students[i].rollNo == roll)
        {
            printf("\nEnter New Name: ");
            scanf(" %[^\n]", students[i].name);

            printf("Enter New Age: ");
            scanf("%d", &students[i].age);

            printf("Enter New Course: ");
            scanf(" %[^\n]", students[i].course);

            printf("Enter New Marks: ");
            scanf("%f", &students[i].marks);

            printf("\nStudent updated successfully!\n");

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nStudent not found!\n");
    }
}

/* Delete Student */
void deleteStudent()
{
    int roll, i, j;
    int found = 0;

    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++)
    {
        if (students[i].rollNo == roll)
        {
            for (j = i; j < count - 1; j++)
            {
                students[j] = students[j + 1];
            }

            count--;

            printf("\nStudent deleted successfully!\n");

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nStudent not found!\n");
    }
}

/* Main Function */
int main()
{
    int choice;

    do
    {
        printf("\n\n========== STUDENT MANAGEMENT SYSTEM ==========\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                printf("\nThank you!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}