#include<iostream>
#include<map>
using namespace std;
int main()
{
	string a;
	map<string, int> m;
	map<string, int>::iterator i;
	while (cin >> a) {
		if (a == "#") break;
		i = m.find(a);
		if (i == m.end()) m.insert(make_pair(a, 1));
		else i->second++;
	}
	for (i = m.begin(); i != m.end(); i++) {
		cout << i->first << ':' << i->second << endl;
	}
	return 0;
}
