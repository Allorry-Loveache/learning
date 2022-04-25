#include"vector.h"
int main()
{
	allorry::vector<int> v;
	v.resize(4,100);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	for (allorry::vector<int>::iterator i = v.begin(); i < v.end(); i++) {
		cout << *i << ' ';
	}
	cout << endl;
	v.insert(v.begin() + 4, 77);
	for (allorry::vector<int>::iterator i = v.begin(); i < v.end(); i++) {
		cout << *i << ' ';
	}
	cout << endl;
	v.erase(v.begin() + 4);
	for (allorry::vector<int>::iterator i = v.begin(); i < v.end(); i++) {
		cout << *i << ' ';
	}
}