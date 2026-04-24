#include <stdio.h>
int main()
{
int m1, m2, m3, m4, m5, total;
float percentage;
printf("Enter marks of five subjects: ");
scanf("%d %d %d %d %d", &m1, &m2, &m3, &m4, &m5);
if(m1 >= 40 && m2 >= 40 && m3 >= 40 && m4 >= 40 && m5 >= 40)
{
total = m1 + m2 + m3 + m4 + m5;
percentage = total / 5.0;
printf("Total Marks = %d\n", total);
printf("Percentage = %.2f%%\n", percentage);
printf("Result: PASS\n");

if(percentage >= 75)
printf("Grade: Distinction");
else if(percentage >= 60)
printf("Grade: First Division");
else if(percentage >= 50)
printf("Grade: Second Division");
else
printf("Grade: Third Division");
}
else
{
printf("Result: FAIL");
}
return 0;
}
