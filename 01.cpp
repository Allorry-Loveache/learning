#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
inline string read() {
	string a;
	char ch = getchar();
	while (ch == ' ' || ch == '\r' || ch == '\n') {
		ch = getchar();
	}
	while (ch != ' ' && ch != '\r' && ch != '\n') {
		a += ch;
		ch = getchar();
	}
	return a;
}
inline void write(string a) {
	int i = 0;
	while (a[i] != '\0') putchar(a[i++]);
}
inline bool cmp(string a, string b) {
	return a + b > b + a;
	//return a>b不对
	//a=321，b=32；a+b=32132，b+a=32321
	//避免出现32132>32321的情况
}
string a[25];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) a[i] = read();
	sort(a, a + n, cmp);
	for (int i = 0; i < n; i++) write(a[i]);
	return 0;
}