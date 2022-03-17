#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string a;
string b[27] = { "#","one","two","three","four",
"five","six","seven","eight","nine","ten","eleven",
"twelve", "thirteen", "fourteen", "fifteen", "sixteen",
"seventeen", "eighteen", "nineteen", "twenty"," a ",   //Õâ¸öaÍ¦·³µÄ
"both","another","first","second","third" };//¶ÔÓ¦
int d[30] = { 0,1,4,9,16,25,36,49,64,81,00,21,44,69,96,25,56,89,24,61,0,1,4,1,1,4,9 };
int c[10];
int main()
{
	int i, j = 0, flag = 1;
	getline(cin, a);
	for (i = 0; i < 27; i++) {
		if (a.find(b[i]) < a.length()) {
			c[j++] = d[i];
		}
	}
	if (j == 0) {
		printf("0");
		return 0;
	}
	sort(c, c + j);
	for (i = 0; i < j; i++) {
		if (flag) {
			if (c[i] == 0) continue;
			printf("%d", c[i]);
			flag = 0;
		}
		else {
			printf("%02d", c[i]);
		}
	}
}
