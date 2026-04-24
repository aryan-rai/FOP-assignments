//partition odd even
#include <stdio.h>
int main(){
int n,i;
printf("enter number of elements:");
scanf("%d",&n);
int arr[n];
printf("enter integer:");
for(i=0;i<n;i++){
scanf("%d",&arr[i]);
}
printf("\neven numbers are:");
for(i=0;i<n;i++){
if(arr[i] % 2==0){
printf("%d",arr[i]);
}
}
printf("\nodd numbers are:");
for(i=0;i<n;i++){
if(arr[i] % 2!=0){
printf("%d",arr[i]);
}
}
return 0;
}

