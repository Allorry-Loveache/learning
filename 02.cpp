#include<iostream>
#include<vector>
using namespace std;
int main()
{
	//ɾ��ż��
	vector <int> v = { 2,14,21,54,33,75,976,23,5,754,12,53,0 };
	vector<int>::iterator i = v.begin();
	/*for (; i < v.end(); i++) {
		if (*i % 2 == 0) v.erase(i);
	  }
	  �ô��뱨��erase������һЩԪ��
	*/
	//���ϴ��뱨����������Ϊ��ȷ����
	while (i != v.end()) {
		if (*i % 2 == 0)  i = v.erase(i);  //����ɾ��λ�õ���һ��λ��
		else i++;
	}
	for (i = v.begin(); i < v.end(); i++) {
		cout << *i << ' ';
	}
}
