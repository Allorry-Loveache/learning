#include"contact.h"
int main()
{
	con contact;
	initialize(&contact);
	while (1) {
		menu();
		char target[max];
		int n,i,t;
		printf("�����ʲô��\n");
		scanf("%d", &n);
		switch (n) {
		case EXIT: {
			printf("�ݰ�������\n");
			free(contact.data);
			return 0;
		}
		case ADD: 
			if (contact.number == contact.capacity) {
				printf("�洢�ռ䲻�㣬������\n");
				break;
			}
			operate(contact.number,&contact); contact.number++; break;
		case DEL:
			printf("����Ҫɾ����������\n");
			scanf("%s", target);
			t = finding(target,&contact);
			if (t == 0) printf("û����ˣ�ɵȱ\n");
			else {
				for (i = t; i < contact.number - 1; i++) 
					contact.data[i] = contact.data[i + 1];
				contact.number--;
				printf("ɾ�����\n");
			}
			break;
		case SEARCH: 
			printf("����Ҫ���ҵ�������\n");
			scanf("%s", target);
			t = finding(target,&contact);
			if (t == 0) printf("û����ˣ�ɵȱ\n");
			else {
				printf("%-15s\t%-10s\t%-5s\t%-12s\t%-20s\n", "����", "�Ա�", "����", "����", "��ַ");
				printf("%-15s\t%-10s\t%-5d\t%-12s\t%-20s\n", contact.data[t].name, contact.data[t].sex, 
					contact.data[t].age, contact.data[t].phone, contact.data[t].addr);
			}
			break;
		case MODIFY: 
			printf("����Ҫ�޸ĵ�������\n");
			scanf("%s", target);
			t = finding(target,&contact);
			if (t == 0) printf("û����ˣ�ɵȱ\n");
			else {
				printf("��������ʼ�޸�\n");
				operate(t,&contact);
			}
			break;
		case SORT:
			qsort(contact.data, contact.number, sizeof(person), compar);
			break;
		case PRINT: print(&contact); break;
		case ADDCAP: addcap(&contact); printf("�������\n");  contact.capacity+=addsize;  break;
		}
		if (n == 0) break;
	}
}