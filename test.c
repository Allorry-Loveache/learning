#include"contact.h"
int main()
{
	person data[1000] = {0,0,0,0,0,};
	int number=0;
	while (1) {
		menu();
		char target[max];
		int n,i,t;
		printf("�����ʲô��\n");
		scanf("%d", &n);
		switch (n) {
		case EXIT: printf("�ݰ�������\n"); return 0;
		case ADD: 
			operate(number,data); number++; break;
		case DEL:
			printf("����Ҫɾ����������\n");
			scanf("%s", target);
			t = finding(target,data,number);
			if (t == 0) printf("û����ˣ�ɵȱ\n");
			else {
				for (i = t; i < number; i++) 
					data[i] = data[i + 1];
				number--;
				printf("ɾ�����\n");
			}
			break;
		case SEARCH: 
			printf("����Ҫ���ҵ�������\n");
			scanf("%s", target);
			t = finding(target,data,number);
			if (t == 0) printf("û����ˣ�ɵȱ\n");
			else {
				printf("%-15s\t%-10s\t%-5s\t%-12s\t%-20s\n", "����", "�Ա�", "����", "����", "��ַ");
				printf("%-15s\t%-10s\t%-5d\t%-12s\t%-20s\n", data[t].name, data[t].sex, data[t].age,
					data[t].phone, data[t].addr);
			}
			break;
		case MODIFY: 
			printf("����Ҫ�޸ĵ�������\n");
			scanf("%s", target);
			t = finding(target,data,number);
			if (t == 0) printf("û����ˣ�ɵȱ\n");
			else {
				printf("��������ʼ�޸�\n");
				operate(t,data);
			}
			break;
		case SORT:
			qsort(data, number, sizeof(data[0]), compar);
			break;
		case PRINT: print(data,number); break;
		}
		if (n == 0) break;
	}
}