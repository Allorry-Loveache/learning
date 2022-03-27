#define _CRT_SECURE_NO_WARNINGS
#include"Date.h"
int main()
{
	Date d1;
	d1.Print();
	int x;
	cin >> x;
	d1 += x;
	d1.Print();
}