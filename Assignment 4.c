#include<stdio.h>
int main()
{
float hra,basic,ta,gross,tax,net;
printf("enter the basic salary:");
scanf("%f",&basic);

hra=basic*0.1;
ta=basic*0.05;

gross=basic+hra+ta;
tax=0.02*gross;
net=0.02*gross;

printf("gross salary=%2f\n",gross);
printf("net salary=%2f\n",net);
printf("hra=%2f\n",hra);
printf("ta=%2f\n",ta);
return 0;
}
