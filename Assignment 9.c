//armstrong
#include <stdio.h>
int main()
{
int num, temp, digit, sum = 0;
printf("Enter a three digit number: ");
scanf("%d", &num);
temp = num;
while(temp != 0)
{
digit = temp % 10;
sum = sum + (digit * digit * digit);
temp = temp / 10;
}
if(sum == num)
printf("%d is an Armstrong number", num);
else
printf("%d is not an Armstrong number", num);
return 0;
}
