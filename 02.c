#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> //����հɣ������Ա���ˣ�
int a[9];     //��Ϊɶ��ָ�룿��������NB��
void s(int t, int* a, char* x, char* y) {
	switch (t) {  //ʮ��ǧ��Ķ���
	case 9:*x = 'Y'; break;
	case 8:case 4:*x = 'Q'; break;
	case 7:case 3:*x = 'B'; break;
	case 6:case 2:*x = 'S'; break;
	case 5:*x = 'W'; break;
	default:*x = NULL; break;
	}
	switch (a[t - 1]) {  //���ֶ���
	case 0:*y = 'a'; break;
	case 1:*y = 'b'; break;
	case 2:*y = 'c'; break;
	case 3:*y = 'd'; break;
	case 4:*y = 'e'; break;
	case 5:*y = 'f'; break;
	case 6:*y = 'g'; break;
	case 7:*y = 'h'; break;
	case 8:*y = 'i'; break;
	case 9:*y = 'j'; break;
	default:break;
	}
}
int main()
{
	int n, i;   int flag = 1;
	scanf("%d", &n);
	for (i = 0; n > 0; i++) {  //���䵹�������
		a[i] = n % 10;
		n /= 10;
	}
	int t = i;     //t����iȥ�ݼ���i������Ϊ������λ��
	char x = NULL, y = NULL;
	while (t) {  //����ѭ��t��           
		s(t, a, &x, &y);   //��ָ����ȡ��Ҫ�Ķ��� 
		/*�ų�1000����һǧ������*/
		if ((t == 1 || t == 5) && y == 'a' ||
			t >= 2 && a[t - 1] == 0 && a[t - 2] == 0);  //��ʱɶ������ 
		else  printf("%c", y);
		/*������λ,��1�ڲ���һ����*/
		if (t == 5)
			if (i >= 9 && !a[i - 2] && !a[i - 3] && !a[i - 4] && !a[i - 5]);
			else printf("%c", x);
		/*Ȼ��������ֲ���0���Ͷ�����*/
		else if (y != 'a') printf("%c", x);
		t--;
	}
}