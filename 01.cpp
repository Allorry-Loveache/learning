//boy �� girl û�е����غϣ���������ص�˼��
//���������û����ô����

#include<stdio.h>
int main()
{
	char a[20000];
	gets(a);
	int sum1 = 0, sum2 = 0;
	for (int i = 0; a[i] != '\0'; i++) {
		if (a[i] == 'b' || a[i + 1] == 'o' || a[i + 2] == 'y') {
			sum1++;
		}
		if (a[i] == 'g' || a[i + 1] == 'i' || a[i + 2] == 'r' || a[i + 3] == 'l') {
			sum2++;
		}
	}
	printf("%d\n%d", sum1, sum2);
}

