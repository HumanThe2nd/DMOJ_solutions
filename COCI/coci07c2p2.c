#include <stdio.h>
// COCI '07 Contest 2 #2 Crne
// Author: Dan Shan
// O(n) solution using pattern tracing
// 1:2, 2:4, 3:6, 4:9, 5:12, 6:16, 7:20
// 1:1, 2:2, 3:2, 4:3, 5:3,  6:4,  7:4
int main(int argc, char *argv[]) {
    int n,c=0;
    scanf("%d",&n);
    for(int i=0;i<=n;i++){
        c+=i/2+1;
    }
    printf("%d\n",c);
}
