��I��
//˼·һ�� ����������Ϊn��ÿ�ΰѵ�һ���ַ��ŵ���������ַ�
��ǰŲ�����ظ�n��
//ע�� ָ�����漰ѭ��ʱ����++ --��ָ����Ͳ�֪��ָ����ȥ�ˣ�
��ѭ�������ͷ��

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
void rotate(char* p, int n) {
	while (n--) {
		char t = *p;
		int l = strlen(p);
		for (int i = 0; i < l - 1; i++)
			*(p + i) = *(p + 1 + i);
		*(p + l - 1) = t;
	}
}
int main()
{
	char a[20] = "abcdefg";
	int n;
	scanf("%d", &n);
	rotate(a, n);
	puts(a);
}


//˼·���� ����˼�롣�� abcdefg,����2�����ȷֿ���
ab  cdefg  ��  ��������ͬʱ��ת
ba  gfedc  ��  �����������һ����ת���ɡ�

#include <stdio.h>
#include <string.h>
void reverse(char* left, char* right) {
	while (left < right) {
		char t;
		t = *left; *left = *right; *right = t;
		left++; right--;
	}
}
int main()
{
	char a[20] = "abcdefg";
	int n;
	int l = strlen(a);
	scanf("%d", &n);
	reverse(a, a + n - 1);
	reverse(a + n, a + l - 1);
	reverse(a, a + l - 1);
	puts(a);
}


��II�����������ַ�������ͣ������һ����������һ���͵ڶ�����ϣ�����һ����

//˼·һ�� ̤̤ʵʵһ��һ������

#include <stdio.h>
#include <string.h>
void rotate(char* p) {
	char t = *p;
	int l = strlen(p);
	for (int i = 0; i < l - 1; i++)
		*(p + i) = *(p + 1 + i);
	*(p + l - 1) = t;

}
int main()
{
	char a[20] = "abcdefg", b[20] = "abcdefg";
	int l = strlen(a);
	while (l--) {
		rotate(a);
		if (strcmp(a, b) == 0) {
			printf("bingo");
			return 0;
		}
	}
	printf("no");
	return 0;
}


//˼·���� abcdefgabcdefg    ��������֮������
//�˷����뱣֤ a b �����ַ�������Ч����һ��

#include <stdio.h>
#include <string.h>
int main()
{
	char a[20] = "abcdefg", b[20] = "efgabcd";
	strncat(a, a, strlen(a));
	if (strstr(a, b) == NULL) printf("no");
	else printf("bingo");
	return 0;
}


