//factorial recursion
#include<stdio.h>

int fact_recur(int n)
{
 if (n==0 || n==1)
 return 1;
 else 
 return n*fact_recur(n-1);
}

int fact_iter(int n) 
{
int i, fact = 1;
for(i = 1; i <= n; i++) 
{
fact = fact * i;
}
return fact;
}    

int main()
{
int n;

printf("Enter a number: ");
scanf("%d", &n);

if(n < 0) 
{
printf("Factorial not defined for negative numbers.\n");
} 
else 
{
printf("Factorial (Iterative) = %d\n", fact_iter(n));
printf("Factorial (Recursive) = %d\n", fact_recur(n));
}
}


