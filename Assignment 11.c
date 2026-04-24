#include <stdio.h>
#include <math.h>
int main()
{
    int num, choice, i, flag = 1;
    long fact = 1;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("\nMenu:");
    printf("\n1. Square Root");
    printf("\n2. Square");
    printf("\n3. Cube");
    printf("\n4. Check Prime");
    printf("\n5. Factorial");
    printf("\n6. Prime Factors");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            if(num >= 0)
                printf("Square Root = %.2f", sqrt(num));
            else
                printf("Square root not defined for negative numbers");
            break;
        case 2:
            printf("Square = %d", num * num);
            break;
        case 3:
            printf("Cube = %d", num * num * num);
            break;
        case 4:
            if(num <= 1)
                flag = 0;
            for(i = 2; i <= num / 2; i++)
            {
                if(num % i == 0)
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)
                printf("%d is a Prime number", num);
            else
                printf("%d is not a Prime number", num);
            break;
        case 5:
            if(num < 0)
            {
                printf("Factorial not defined for negative numbers");
            }
            else
            {
                for(i = 1; i <= num; i++)
                    fact = fact * i;
                printf("Factorial = %ld", fact);
            }
            break;
        case 6:
            printf("Prime Factors are: ");
            for(i = 2; i <= num; i++)
            {
                while(num % i == 0)
                {
                    printf("%d ", i);
                    num = num / i;
                }
            }
            break;
        default:
            printf("Invalid choice");
    }
    return 0;
}
