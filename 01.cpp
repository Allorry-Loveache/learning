#define _CRT_SECURE_NO_WARNINGS
// No.1 С�ۺ�  ��ָ�����ı��ļ��ж�������,����ʾ

#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE* fp;
    int xuehao;
    char name[10];
    int age;
    int i, number = 0, sum = 0;
    if ((fp = fopen("stu.txt", "w+")) == NULL) {
        printf("can't open file\n");
        exit(1);
    }
    for (i = 0; i < 3; i++) {
        scanf("%d%s%d", &xuehao, name, &age);
        fprintf(fp, "%d %s %d\n", xuehao, name, age);
    }
    rewind(fp);
    while (!feof(fp)) {
        if (fscanf(fp, "%d %s %d", &xuehao, name, &age) == 3) {
            ++number;
            sum += age;
        }
    }
    fprintf(fp, "The number is %d\n", number);
    fprintf(fp, "The age is %d\n", sum / number);
    fclose(fp);
    return 0;
}




// No.2 ע���д��ʽ  
//�ȴӼ�������10��������a,b��������д���ı��ļ��У�
//Ȼ�󣬴��ļ��н����������ʾ����Ļ�ϡ�

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    FILE* fp;
    int a, b, c, d, i, k;

    fp = fopen("file1.txt","w");
    if ( fp == NULL){
        printf("���ļ�ʧ��\n");
        exit(0);
    }
    for (i = 0; i < 10; i++)
    {
        scanf("%d,%d", &a, &b);
        fprintf(fp, "(%d:%d)\n", a, b);
    }
    fclose(fp);
    fp = fopen("file1.txt", "r");
    if (fp == NULL){
        printf("���ļ�ʧ��\n");
        exit(0);
    }
    k = fscanf( fp, "(%d:%d\n)", &a, &b);
    while (k ==2){
        printf("%d,%d\n", a, b);
        k = fscanf(fp, "(%d:%d\n)", &a, &b);
    }
    fclose(fp);
    return 0;
}





//No.3  �������ļ�    
// �Ӽ�����������ѧ������Ϣ���ṹ�����s_data�У�
// �ٽ�s_data����д��"stu.dat"�ļ��У�stu.dat��ʽΪ�������ļ�����
//����"stu.dat"�ļ��ж�ȡ����ѧ������Ϣ����ʾ��


#include<stdio.h>
#include<stdlib.h>
struct student
{
    char name[9];
    float score;
} s_data;
int main()
{
    FILE* fp;
    int i;

    fp = fopen("stu.dat","wb"); // �Զ����ƴ��ļ���д 
    if (fp == NULL){
        printf("File can not be opened \n");
        exit(0);
    }
    for (i = 0; i < 10; i++){
        scanf("%s %f", s_data.name, &s_data.score);
        fwrite(&s_data, sizeof(struct student), 1 ,fp);
    }
    fclose(fp);
    fp = fopen("stu.dat","r");   //��ֻ���ķ�ʽ�򿪶������ļ�
    while (fread(&s_data, sizeof(s_data),1, fp) ==1) //�ɹ���ȡһ���ṹ����������ݣ���ѭ�� 
    {
        printf("������%s,�ɼ���%6.2f��\n", s_data.name, s_data.score);  //����ṹ������е�����
    }
    fclose(fp);
    return 0;
}







// No.5  ������  ���д�������涨��ȡ�Ķ��٣����ļ��ж�ȡ�ַ���

#include <stdio.h>
#include <string.h>

void FGetStr(char* str, int size, FILE* file)
{
    for (int i = 1; *str = fgetc(file); ++i, ++str) {
        if (*str == '\n' || *str == EOF || i >= size) break;
    }

    if (*str != '\n')
        fseek(file, -1L, 1);  //���ӵ�ǰλ��������һ�ֽ�
    *str = '\0';
}

int main()
{
    FILE* f;
    char a[10]="", b[10]="";
    f = fopen("MyStr.txt", "w");
    fprintf(f, "%s\n%s", "haoye","woqu");
    fclose(f);
    f = fopen("MyStr.txt", "r");
    if (f)
    {
        FGetStr(a, 10, f);
        FGetStr(b, 10, f);
        puts(a);
        puts(b);
        fclose(f);
    }
    return 0;
}




// No.6  ������   
// ��д�������Ӹ����������ı��ļ��а��ж��룬
//������д�����������ļ��С�Ҫ��1��ȥ��ÿ�е�ǰ���ո���Ʊ����2��ÿ��ǰ���кš�

void fileRW(FILE* fin, FILE* fout)
{
    char str;
    int i = 1, j = 1;
    while (1) {
        str = fgetc(fin);
        if (i == j && str != EOF)//׼����ӡ�к�
        {
            fprintf(fout, "%d:", j++);
            while (str == ' ' || str == '\t')
                str = fgetc(fin);
        }
        if (str == '\n')
            i++;
        if (str == EOF)
            break;
        fputc(str, fout);
    }
}
#include <stdio.h>
void fileRW(FILE *fin,FILE *fout);
int main(){
    char fname[20];gets(fname);
        FILE *fpr=fopen(fname,"r");
      FILE *fpw=fopen("file2.txt","w");  
        fileRW(fpr,fpw);
        fclose(fpr);fclose(fpw);
    return 0;
}

