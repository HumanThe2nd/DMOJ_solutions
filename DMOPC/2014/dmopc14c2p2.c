/*
DMOPC '14 Contest 2 P2 - Cutting Logs
Author: Dan Shan
Date: 2025-02-02
Store gaps between X's
*/
#include <stdio.h>
int main(){
    int n,r=0,ci=0,q[101];
    scanf("%d ",&n);
    char s[n];
    for(int i=0;i<n;i++) {
        s[i]=getchar();
        if(s[i]=='X') {
            if(i&&s[i-1]=='O') q[r++]=ci;
            ci=0;
        }
        else ci++;
    }
    if(s[n-1]=='O') q[r++]=ci;
    printf("%d\n",r);
    for(int i=0;i<r;i++){
        for(int j=0;j<q[i];j++){
            putchar('O');
        }
        putchar('\n');
    }
}
