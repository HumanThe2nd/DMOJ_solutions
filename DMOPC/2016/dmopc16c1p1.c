/*
DMOPC '16 Contest 1 P1 - A New Chapter
Author: Dan Shan
Date: 2025-07-01
Count matching parity (number equals index modulo 2)
*/
#include <stdio.h>
int main() {
    int n,c=0;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        int ai;
        scanf("%d",&ai);
        c+=(ai&1)==(i&1);
    }
    printf("%d\n",c);
}
