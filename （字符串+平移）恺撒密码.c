
#include <stdio.h> 
char a[81];
int main()
{
	int i, j,n;
	gets(a);
	scanf("%d", &n);
	n = n % 26;                     //平移思想
	for (i = 0; a[i] != '\0'; i++) {
		if (a[i] >= 65 && a[i] <= 90) {
            //26个字母循环平移思想
			if(n>=0) a[i]=(a[i] - 65 + n) % 26 + 65;   //右移
			else a[i] = (a[i] - 65 + n+26) % 26 + 65;  //左移
		}
		if (a[i] >= 97 && a[i] <= 122) {
			if (n >= 0) a[i] = (a[i] - 97 + n) % 26 + 97;
			else a[i] = (a[i] - 97 + n + 26) % 26 + 97;
		}
	}
	printf("%s", a);
	return 0;
}
