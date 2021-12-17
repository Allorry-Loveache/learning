void delchar(char* str, char c)
{
	int i, j = 0;
	for (i = 0; *(str + i) != '\0'; i++) 
		if (*(str + i) != c)
			*(str + (j++)) = *(str + i);
	*(str + j) = '\0';
}
// a    b b a a a a a b  -> b b b \0


// //个人做法，让两个指针前后追逐,str在前，进行判断和覆盖
// void delchar(char* str, char c) {
//     char* t = str;
//     while (*str != '\0') 
//         if (*str == c) str++;
//         else {
//             *t = *str;
//             str++; t++;
//         }
//     *t = '\0';   
// }
