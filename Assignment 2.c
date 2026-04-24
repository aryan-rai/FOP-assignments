//arithmatic operation
#include <stdio.h>
int main()
{
int choice;
float num1, num2, result;
printf("Menu:\n");
printf("1. Addition\n");
printf("2. Subtraction\n");
printf("3. Multiplication\n");
printf("4. Division\n");
printf("Enter your choice: ");
scanf("%d", &choice);
printf("Enter two numbers: ");
scanf("%f %f", &num1, &num2);
switch(choice)
{
case 1:
result = num1 + num2;
printf("Addition = %.2f", result);
break;
case 2:
result = num1 - num2;
printf("Subtraction = %.2f", result);
break;
case 3:
result = num1 * num2;
printf("Multiplication = %.2f", result);
break;
case 4:
if(num2 != 0)
{
result = num1 / num2;
printf("Division = %.2f", result);
}
else
{
printf("Division by zero is not allowed");
}
break;
default:
printf("Invalid Choice");
}
return 0;
}
