#include"contact.h"
void menu() {
	printf("**********************************\n");
	printf("****  1.add     2. del     *******\n");
	printf("****  3.search  4. modify  *******\n");
	printf("****  5. sort   6.print    *******\n");
	printf("****  7.addcap  0. exit    *******\n");
	printf("**********************************\n");
}
void initialize(con* contact) {
	contact->data=(con*)calloc(addsize, sizeof(person));
	if (contact->data == NULL) {
		perror(initialize);
		return;
	}
	contact->number = 0;
	contact->capacity = addsize;
}
void operate(int t,con* contact) {
	printf("����������\n"); 
	scanf("%s",contact->data[t].name);
	printf("�����Ա�\n"); 
	scanf("%s", contact->data[t].sex);
	printf("�������䣺\n"); 
	scanf("%d", &contact->data[t].age);
	printf("����绰���룺\n");
	scanf("%s", contact->data[t].phone);
	printf("�����ַ��\n");
	scanf("%s", contact->data[t].addr);
	printf("�������\n"); 
}
int finding(char *target, con*contact) {
	for (int i = 0; i < contact->number; i++) 
		if (strcmp(contact->data[i].name, target)==0) return i;
	return 0;
}
void print(con*contact) {
	printf("%-15s\t%-10s\t%-5s\t%-12s\t%-20s\n", "����", "�Ա�", "����", "����", "��ַ");
	for (int i = 0; i < contact->number; i++)
		printf("%-15s\t%-10s\t%-5d\t%-12s\t%-20s\n", contact->data[i].name, contact->data[i].sex, 
			contact->data[i].age, contact->data[i].phone, contact->data[i].addr);
}
int compar(const void* i1, const void* i2) {
	const person* p1 = (const person*)i1;
	const person* p2 = (const person*)i2;
	return strcmp(p1->name, p2->name);
}
void addcap(con* contact) {
	person *p=realloc(contact->data, (contact->capacity + addsize) * sizeof(person));
	if (p != NULL) 
		contact->data = p;
	else {
		perror(addcap);
		return;
	}
}