#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int i, year, day, month, t = 0;
	scanf("%d/%d/%d", &year, &month, &day);
	int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (year % 4 == 0 && year % 100 || year % 400 == 0)
		a[2] = 29;               //»ÚƒÍ≈–∂œ
	for (i = 1; i < month; i++)
		t += a[i];
	t += day;
	printf("%d", t);

}