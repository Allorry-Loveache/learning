
Code：
void hollowPyramid(int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
	for (j = 0; j < n - i; j++) 
	    printf(" ");
	for (j = 0; j < 2 * i - 1; j++) 
	    if (j == 0 || j == 2 * i - 2 || i == n) 
		printf("%d",i);
	    else
		printf(" ");
	    printf("\n");
    }
}
// // 空心菱形
// void hollowPyramid(int n) {
// 	int i, j;
// 	for (i = 1; i <= n; i++) {
// 	    for (j = 0; j < n - i; j++) 
// 		printf(" ");
// 	    for (j = 0; j < 2 * i - 1; j++) 
// 		if (j == 0 || j == 2 * i - 2) 
// 		   printf("%d",i);
// 		else 
// 		    printf(" ");
// 		printf("\n");
// 	}
// 	for (i = n - 1; i > 0; i--) {
// 	    for (j = 0; j < n - i; j++) 
// 		printf(" ");
//
// 	    for (j = 0; j < 2 * i - 1; j++) 
// 		if (j == 0 || j == 2 * i - 2) 
// 		    printf("%d",i);
// 		else 
// 		    printf(" ");
// 		printf("\n");
// 	}
// }
// // 空心菱形
