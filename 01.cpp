#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <assert.h>

void Swap(char* buf1, char* buf2, size_t width)
{
    unsigned int i = 0;
    assert(buf1 && buf2);
    for (i = 0; i < width; i++)//按字节大小交换
    {
        char tmp = *buf1;
        *buf1 = *buf2;
        *buf2 = tmp;
        buf1++;
        buf2++;
    }
}
void bubble_sort(void* base, int num, int width,
    int(*cmp)(const void* e1, const void* e2))
{
    int i = 0;
    int j = 0;
    int flag = 0;
    assert(base && cmp);
    for (i = 0; i < num - 1; i++)
    {
        flag = 0;
        for (j = 0; j < num - 1 - i; j++)
            if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
            {
                Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
                flag = 1;
            }
    }
}
struct Stu
{
    char name[20];
    int age;
};

int cmp_int(const void* e1, const void* e2)//整形比较
{
    return *(int*)e1 - *(int*)e2;
}


cmp_stu_age(const void* e1, const void* e2)
{
    return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;//箭头的优先级高，所以在强制转换时，应该加上“（）”
}
cmp_stu_name(const void* e1, const void* e2)
{
    return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}
char* cmp_str(const void* e1, const void* e2)//字符串比较
{
    return strcmp(*(char**)e1, *(char**)e2);

}
int main()
{
    int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    /*struct Stu arr[] = { { "zhangsan", 20 }, { "liying", 18 }, { "wangwu", 15 } };
    int sz = sizeof(arr) / sizeof(arr[0]);*/
    /*char* arr[] = { "abcds", "qqqqqq", "bbbbbb" };
    int sz = sizeof(arr) / sizeof(arr[0]);*/
    bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    system("pause");
    return 0;
}

