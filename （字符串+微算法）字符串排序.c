#include<stdio.h>
#include<string.h>
int main()
{
    char a[5][81],t[81]; int i,j;
    for (i = 0; i < 5; i++)
	scanf("%s", &a[i]);
    for(i=0;i<4;i++)
	for (j = 0; j < 4 - i; j++) 
	    if (strcmp(a[j], a[j + 1]) > 0) {
		strcpy(t, a[j]);
		strcpy(a[j], a[j+1]);
		strcpy(a[j+1], t);
	    }
    printf("After sorted:\n");
    for (i = 0; i < 5; i++)
	puts(a[i]);
}
