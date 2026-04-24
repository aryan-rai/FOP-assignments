//sine sum series
#include <stdio.h>
int factorial(int n) 
{
int i, fact = 1;
for(i = 1; i <= n; i++) 
{
fact = fact * i;
}
return fact;
}
float power(float x, int n) 
{
int i;
float result = 1;
for(i = 1; i <= n; i++) 
{
result = result * x;
}
return result;
}
int main() {
float x, sum = 0;
int n, i;
printf("Enter value of x (in radians): ");
scanf("%f", &x);
printf("Enter number of terms: ");
scanf("%d", &n);
for(i = 0; i < n; i++) 
{
float term = power(x, 2*i+1) / factorial(2*i+1);
if(i % 2 == 0)
sum = sum + term;
else
sum = sum - term;
}
printf("Sum of sine series = %f", sum);
return 0;
}

