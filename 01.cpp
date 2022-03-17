#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double y, temp;
	int x;

	for (y = 1; y >= -1; y -= 0.1) {
		temp = abs(asin(y)) * 10;
		if (y >= 0) {
			for (x = 0; x < temp; x++) {
				cout << ' ';
			}
			cout << '*';
			for (; x < 31 - temp; x++) {
				cout << ' ';
			}
			cout << '*' << endl;
		}
		else {
			for (x = 0; x < 31 + temp; x++) {
				cout << ' ';
			}
			cout << '*';
			for (; x < 62 - temp; x++) {
				cout << ' ';
			}
			cout << '*' << endl;
		}
	}
}
