//gcd
#include <stdio.h>
int main(){
int a,b,i,gcd,temp1,temp2;
printf("enter two numbers:");
scanf("%d%d",&a,&b);
int scd=-1;
for(i=2;i<=a &&i<=b;i++){
if(a%i==0 &&b%i==0)
{
scd=i;
break;
}
}
if(scd !=-1)
printf("smallest common divisor:%d\n",scd);
else
printf("no common divisor other than 1\n");
temp1=a;
temp2=b;
while(temp2!=0)
{
int r =temp1%temp2;
temp1=temp2;
temp2=r;
}
gcd=temp1;
printf("gcd:%d\n",gcd);
return 0;
}

