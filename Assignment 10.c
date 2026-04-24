//simple calculator
#include <stdio.h>
int main()
{
    int choice, i, num;
    float a, b, result;
    long fact = 1;
printf("1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Power\n6.Factorial\n");
printf("Enter your choice: ");
scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            scanf("%f %f", &a, &b);
            printf("Result = %.2f", a + b);
            break;

        case 2:
            scanf("%f %f", &a, &b);
            printf("Result = %.2f", a - b);
            break;

        case 3:
            scanf("%f %f", &a, &b);
            printf("Result = %.2f", a * b);
            break;

        case 4:
            scanf("%f %f", &a, &b);
            if(b != 0)
                printf("Result = %.2f", a / b);
            else
                printf("Division by zero not allowed");
            break;

        case 6:
            scanf("%d", &num);
            for(i = 1; i <= num; i++)
                fact = fact * i;
            printf("Factorial = %ld", fact);
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}
