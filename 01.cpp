#define _CRT_SECURE_NO_WARNINGS
// No.1 小综合  从指定的文本文件中读出数据,并显示

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




// No.2 注意读写格式  
//先从键盘输入10个整数对a,b，并将其写到文本文件中；
//然后，从文件中将其读出，显示在屏幕上。

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    FILE* fp;
    int a, b, c, d, i, k;

    fp = fopen("file1.txt","w");
    if ( fp == NULL){
        printf("打开文件失败\n");
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
        printf("打开文件失败\n");
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





//No.3  二进制文件    
// 从键盘依次输入学生的信息到结构体变量s_data中，
// 再将s_data数据写到"stu.dat"文件中（stu.dat格式为二进制文件），
//最后从"stu.dat"文件中读取所有学生的信息并显示。


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

    fp = fopen("stu.dat","wb"); // 以二进制打开文件供写 
    if (fp == NULL){
        printf("File can not be opened \n");
        exit(0);
    }
    for (i = 0; i < 10; i++){
        scanf("%s %f", s_data.name, &s_data.score);
        fwrite(&s_data, sizeof(struct student), 1 ,fp);
    }
    fclose(fp);
    fp = fopen("stu.dat","r");   //以只读的方式打开二进制文件
    while (fread(&s_data, sizeof(s_data),1, fp) ==1) //成功读取一个结构体变量的数据，则循环 
    {
        printf("姓名：%s,成绩：%6.2f：\n", s_data.name, s_data.score);  //输出结构体变量中的数据
    }
    fclose(fp);
    return 0;
}







// No.5  函数题  请编写函数，规定读取的多少，从文件中读取字符串

#include <stdio.h>
#include <string.h>

void FGetStr(char* str, int size, FILE* file)
{
    for (int i = 1; *str = fgetc(file); ++i, ++str) {
        if (*str == '\n' || *str == EOF || i >= size) break;
    }

    if (*str != '\n')
        fseek(file, -1L, 1);  //光标从当前位置往后退一字节
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




// No.6  函数题   
// 编写函数，从给定的输入文本文件中按行读入，
//并按行写入给定的输出文件中。要求：1）去除每行的前导空格或制表符。2）每行前加行号。

void fileRW(FILE* fin, FILE* fout)
{
    char str;
    int i = 1, j = 1;
    while (1) {
        str = fgetc(fin);
        if (i == j && str != EOF)//准备打印行号
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

