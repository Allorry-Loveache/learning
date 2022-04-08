#include<string>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
string a;
int main()
{
	char ch;
	int i, x = 0, y = 0;
	while (ch = getchar()) {
		if (ch == 'E') break;
		if (ch == '\n') continue;
		a += ch;
	}
	for (i = 0; a[i] != '\0'; i++) {
		if (a[i] == 'W') x++;
		if (a[i] == 'L') y++;
		if (x >= 11 || y >= 11) {
			if (abs(x - y) >= 2) {
				printf("%d:%d\n", x, y);
				x = 0, y = 0;
			}
		}
	}
	printf("%d:%d\n\n", x, y);
	x = 0, y = 0;
	for (i = 0; a[i] != '\0'; i++) {
		if (a[i] == 'W') x++;
		if (a[i] == 'L') y++;
		if (x >= 21 || y >= 21) {
			if (abs(x - y) >= 2) {
				printf("%d:%d\n", x, y);
				x = 0, y = 0;
			}
		}
	}
	printf("%d:%d\n", x, y);
}