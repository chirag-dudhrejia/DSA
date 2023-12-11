#include <stdio.h>

struct student
{
    int rollno;
    char name[3][10], sex[7], grade;
    int dob[3], marks[3];
};

// void insert_data(int);
// void display_data(int);

int main()
{
    int n;
    printf("Enter Number Of Students : ");
    scanf("%d", &n);
    struct student stu[50];

    insert_data(stu[1]);

    // for (int i = 0; i < n; i++)
    // {
    //     printf("Enter Roll Number of Student %d : ", i+1);
    //     scanf("%d", &stu[i].rollno);

    //     printf("Enter Name\n");
    //     printf("First Name : ");
    //     scanf("%s", stu[i].name[0]);
    //     printf("Middle Name : ");
    //     scanf("%s", stu[i].name[1]);
    //     printf("Last Name : ");
    //     scanf("%s", stu[i].name[2]);

    //     printf("Gender : ");
    //     scanf("%s", stu[i].sex);

    //     printf("Date OF Birth\n");
    //     printf("Date : ");
    //     scanf("%d", &stu[i].dob[0]);
    //     printf("Month : ");
    //     scanf("%d", &stu[i].dob[1]);
    //     printf("Year : ");
    //     scanf("%d", &stu[i].dob[2]);

    //     printf("Marks\n");
    //     printf("English : ");
    //     scanf("%d", &stu[i].marks[0]);
    //     printf("Maths : ");
    //     scanf("%d", &stu[i].marks[1]);
    //     printf("Computer Science : ");
    //     scanf("%d", &stu[i].marks[2]);
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     printf("Roll No : %d\n", stu[i].rollno);
    //     printf("Name : %s %s %s\n", stu[i].name[0], stu[i].name[1], stu[i].name[2]);
    //     printf("Gender : %s\n", stu[i].sex);
    //     printf("DOB : %d-%d-%d\n", stu[i].dob[0], stu[i].dob[1], stu[i].dob[2]);
    //     printf("Marks\n");
    //     printf("English %d\n", stu[i].marks[0]);
    //     printf("Maths %d\n", stu[i].marks[1]);
    //     printf("Computer Science %d\n", stu[i].marks[2]);

    // }


}

// void insert_data(int n)
// {
//     struct student stu[n];

//     for (int i = 0; i < n; i++)
//     {
//         printf("Enter Roll Number of Student %d : ", i+1);
//         scanf("%d", &stu[i].rollno);

//         printf("Enter Name\n");
//         printf("First Name : ");
//         scanf("%s", stu[i].name[0]);
//         printf("Middle Name : ");
//         scanf("%s", stu[i].name[1]);
//         printf("Last Name : ");
//         scanf("%s", stu[i].name[2]);

//         printf("Gender : ");
//         scanf("%s", stu[i].sex[0]);

//         printf("Date OF Birth\n");
//         printf("Date : ");
//         scanf("%d", &stu[i].dob[0]);
//         printf("Month : ");
//         scanf("%d", &stu[i].dob[1]);
//         printf("Year : ");
//         scanf("%d", &stu[i].dob[2]);

//         printf("Marks\n");
//         printf("English : ");
//         scanf("%d", &stu[i].marks[0]);
//         printf("Maths : ");
//         scanf("%d", &stu[i].marks[1]);
//         printf("Computer Science : ");
//         scanf("%d", &stu[i].marks[2]);
//     }
    
// }

// void display_data(int n)
// {
//     struct student stu[n];
//     for (int i = 0; i < n; i++)
//     {
//         printf("Roll No : %d\n", stu[i].rollno);
//         printf("Name : %s %s %s\n", stu[i].name[0], stu[i].name[1], stu[i].name[2]);
//         printf("Gender : %s\n", stu[i].sex);
//         printf("DOB : %d-%d-%d\n", stu[i].dob[0], stu[i].dob[1], stu[i].dob[2]);
//         printf("Marks\n");
//         printf("English %d\n", stu[i].marks[0]);
//         printf("Maths %d\n", stu[i].marks[1]);
//         printf("Computer Science %d\n", stu[i].marks[2]);
//     }
    
// }