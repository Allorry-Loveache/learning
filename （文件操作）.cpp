1.   把文件里的内容转换成小写，输出
3.   把文件里的数字类型求和，并且输入文件末尾
2.   后移3个位数加密账号和密码
4.   把有“for：的行输出



//第一题
//#define _CRT_SECURE_NO_WARNINGS
//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//
//	FILE* p = fopen("text.txt", "r");
//	char t[100], ch;
//	int sum = 0, flag=1;
//	while (!feof(p)) {
//		ch = fgetc(p);
//		if (ch == '\n') flag = 0;
//		else {
//			if (flag == 0) sum++, flag = 1;
//		}
//		if (ch >= 65 && ch <= 90) ch += 32;
//		cout << ch;
//	}
//	cout << endl << sum;
//}


//第三题
//#define _CRT_SECURE_NO_WARNINGS
//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//
//	FILE* p = fopen("text2.txt", "r");
//	char t[100], ch;
//	int count = 0;
//	int flag = 1;
//	int sum = 0;
//	while (!feof(p)) {
//		ch = fgetc(p);
//		if (ch >= '0' && ch <= '9')
//		{
//			count = count * 10 + ch - '0';
//		}
//		else {
//			sum += count;
//			count = 0;
//		}
//	}
//	p = fopen("text2.txt", "a+");
//	fprintf(p, "%d", sum);
//	fclose(p);
//	
//	cout << endl << sum;
//}



//第二题
//本题一个文件里放本来的密码
//我把加密后的文件放到了另一个文件里
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{

	FILE* p = fopen("text3.txt", "a+");
	FILE* p2 = fopen("jiami.txt", "w");
	char ch = '0';
	while (!feof(p)) {
		ch = fgetc(p);
		if (ch == '\n') {
			fputc('\n', p2);
			continue;
		}
		else if (ch == ' ') {
			fputc(' ', p2);
			continue;
		}
		ch += 3;
		if (ch <= 70 && ch > '9') ch -= 10;
		else if (ch > 122) ch -= 26;
		fputc(ch, p2);
	}

}




#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{

	FILE* p = fopen("text.txt", "a+");
	FILE* p2 = fopen("jiami.txt", "w");
	char ch = '0';
	char t[100];
	while (!feof(p)) {
		fgets(t, 100, p);
		if (strstr(t, "for"))
			cout << t;
	}

}
