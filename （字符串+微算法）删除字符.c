
void delchar(char* str, char c)
{
	int i, j = 0;
	for (i = 0; *(str + i) != '\0'; i++) 
		if (*(str + i) != c)
			*(str + (j++)) = *(str + i);
	*(str + j) = '\0';
}
// a    b b a a a a a b  
