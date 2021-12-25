#include <stdio.h>
#include <string.h>
int main(){
    char *mon[13] = {"0",
            "january","february","march","april",
            "may","june","july","august",
            "september","october","november","december"};
    char word[20], i;

 do{
        scanf("%s", word);
//        for(i=0; i<strlen(word); i++){
//            if(word[i]>='A' && word[i]<='Z')
//                word[i] = word[i] - 'A' + 'a';
//        }
        for(char *p=word; *p!=0; p++){
            if(*p>='A' && *p<='Z')
                *p = *p - 'A' + 'a';
        }
        for(i=1; i<=12 && strcmp(word,mon[i])!=0; i++);
        
          //如果不匹配，就继续匹配，成功了就退出
        if(i<=12) printf("%d\n", i);
        else {
            printf("?\n");
            break;
        }
    }while(1);
    return 0;
}
