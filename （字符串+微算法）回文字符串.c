

//常规方法不多赘述，初级指针玩起来
//本题暂不考虑大小写，大不了所有字母都转换成小写）

bool palindrome(char* s) {
    char* t = s;
    while (*s++); s -= 2;  //只要s不是\0，指针一直右移，过头了，就-2
    while ( *t != '\0')    //双向奔赴，进行判断
        if(*t++ != *s--) return false;  //只要不是回文，直接打断施法
    return true;
}
