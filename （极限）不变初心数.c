
#include <stdio.h>
int sumDigits(int n){
    int sum=0;
    while(n!=0){
        sum += n%10;
        n /= 10;
    }
    return sum;
}
int main(){
    int n;
    scanf("%d", &n);
    int k, heart, j;
    for(int i=0; i<n; i++){
        scanf("%d", &k);
        heart = sumDigits(k+k);
        for(j=3; j<=9 && (heart==sumDigits(k*j)); j++);
        if(j<10) printf("NO\n");
        else printf("%d\n", heart);
    }
    return 0;
}
