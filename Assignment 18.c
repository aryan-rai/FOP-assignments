//string palindrome
#include <stdio.h>
#include <string.h>
int main() {
char str[100], str2[100], rev[100];
int i, len;
printf("Enter a string: ");
scanf("%s", str);
len = strlen(str);
printf("Length of string = %d\n", len);
for(i = 0; i < len; i++) 
{
rev[i] = str[len - i - 1];
}
rev[len] = '\0';
printf("Reversed string = %s\n", rev);
if(strcmp(str, rev) == 0)
printf("The string is a Palindrome\n");
else
printf("The string is not a Palindrome\n");
printf("Enter another string: ");
scanf("%s", str2);
if(strcmp(str, str2) == 0)
printf("Strings are equal\n");
else
printf("Strings are not equal\n");
if(strstr(str, str2) != NULL)
printf("Substring found in main string\n");
else
printf("Substring not found\n");
return 0;
}
