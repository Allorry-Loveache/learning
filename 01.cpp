// 1.��strstr�����������
//��������ˣ�ֱ�ӱ��У������ͦ�鷳��

#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000005];
	char b[15];
	int flag = 1, sum = 0, save = 0;
	gets(b); gets(a);
	for (int i = 0; a[i] != '\0'; i++)
		if (a[i] >= 65 && a[i] <= 90) a[i] += 32;
	for (int i = 0; b[i] != '\0'; i++)
		if (b[i] >= 65 && b[i] <= 90) b[i] += 32;
	//����strstr���㷨���в���
	char* p1 = a, * p2 = b, * start = a;
	while (*start) {
		p1 = start;
		p2 = b;
		while (*p1 && *p2) {
			if (*p1 == *p2) {
				p1++; p2++;
			}
			else {
				break;
			}
		}
		//1. ��֤��ͷ�ǿո�  ���߲��Ǳ�ģ����ǵ�������ĸ
		//2. ��֤ĩβ�ǿո������ֹ��
		if (*p2 == '\0' && (start == a || *(start - 1) == ' ') &&
			(*p1 == ' ' || *p1 == '\0')) {
			if (flag) {
				save = start - a;   //�����һ��ָ��֮��ľ���
				flag = 0;
			}
			sum++;
		}
		start++;
	}
	if (flag) {
		printf("-1");
	}
	else printf("%d %d", sum, save);
}



// 2.�������find �� string::npos
#include <iostream>
#include <string>
//�����ռ�
using namespace std;
int main() {
	//���������ַ���
	string a;
	string b;
	//��string�⣬����getline, ֱ�Ӷ���һ����
	getline(cin, a);
	getline(cin, b);
	//ת����Сд�����Զ�ת��Ϊ��д������Сд
	for (int i = 0; i < a.length(); ++i) {
		a[i] = tolower(a[i]);
	}
	for (int i = 0; i < b.length(); ++i) {
		b[i] = tolower(b[i]);
	}
	//��Ϊ�������Ĳ��㣬����Ҫ��ǰ��Ӽ����ո�һ��Ҫ��ͬ����ģ�ͬ����ͬ��������ͬ��
	a = ' ' + a + ' ';
	b = ' ' + b + ' ';
	//�ȿ����᲻���Ҳ�������a.find()��string::npos
	if (b.find(a) == string::npos) {  //string::npos������ֵ���Ҳ����ַ���
		cout << -1 << endl;
	}
	//����ҵõ�
	else {
		int alpha = b.find(a);   //��һ�ε�λ�ã�find��������size_t
		int beta = b.find(a), s = 0;//beta��¼����λ�õ��±꣬ ��������ʼ��Ϊ0
		while (beta != string::npos) {
			++s;//������
			beta = b.find(a, beta + 1);   //��b���±�Ϊbeta+1����ʼ����
		}
		cout << s << " " << alpha << endl;//�����һ�����ܹ��м���
	}
	//��������ֵΪ0��������������
	return 0;
}



// 3.������� insert �� transform
#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
	string a, b;
	cin >> a;
	getchar();//��ʵ�Ҳ�֪��Ҫ��Ҫ�̻س� 
	transform(a.begin(), a.end(), a.begin(), ::tolower);//ʹaСд�� 
	getline(cin, b);
	b.insert(0, " ");//��bǰ��Ӹ��ո� ֮����find���²鲻����һ�� 
	//Ȼ����a����β
	a = a + ' ';
	a.insert(a.begin(), ' ');
	transform(b.begin(), b.end(), b.begin(), ::tolower);//Сд�� 
	if (b.find(a) == -1)
	{
		cout << "-1";
	}
	else
	{
		int sum = 0; int n = 0;
		while (b.find(a, n) != -1)//find�Ҳ����᷵��nposҲ����-1 
		{
			sum++;
			n = b.find(a, n) + 1;//ʣ�¶������ 

		}
		cout << sum << " ";
		cout << b.find(a);
	}
}



