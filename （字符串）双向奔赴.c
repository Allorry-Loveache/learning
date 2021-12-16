#include<stdio.h>
#include<string.h>
int main()
{
    char a[81]; int i;
    gets(a);
    int l = strlen(a);
    for (i = 0; i < l; i++)
	 if (a[i] >= 'A' && a[i] <= 'Z') 
	     a[i] = 'A' + 25 - (a[i]-'A');
	 
    puts(a);
}
