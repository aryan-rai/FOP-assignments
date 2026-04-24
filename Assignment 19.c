//struct employee
#include <stdio.h>
#include <string.h>
struct EMPLOYEE {
char name[50];
char designation[50];
char gender[10];
char doj[20];
float salary;
};
int main() {
struct EMPLOYEE e[100];
int n, i, male = 0, female = 0;
printf("Enter number of employees: ");
scanf("%d", &n);
for(i = 0; i < n; i++) 
{
printf("\n--- Employee %d ---\n", i+1);
printf("Enter Name: ");
scanf("%s", e[i].name);
printf("Enter Designation: ");
scanf("%s", e[i].designation);
printf("Enter Gender (Male/Female): ");
scanf("%s", e[i].gender);
printf("Enter Date of Joining: ");
scanf("%s", e[i].doj);
printf("Enter Salary: ");
scanf("%f", &e[i].salary);
if(strcmp(e[i].gender, "Male") == 0)
male++;
else
female++;
}
printf("\nTotal employees = %d", n);
printf("\nMale employees = %d", male);
printf("\nFemale employees = %d", female);
printf("\nEmployees with salary > 10000: ");
for(i = 0; i < n; i++) 
{
if(e[i].salary > 10000)
printf("%s ", e[i].name);
}
printf("\nEmployees with designation AsstManager: ");
for(i = 0; i < n; i++) 
{
if(strcmp(e[i].designation, "AsstManager") == 0)
printf("%s ", e[i].name);
}
return 0;
}

