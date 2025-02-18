/*
Greater New York Regional 2012 - Mystery
Author: Dan Shan
Date: 2025-02-18
start at index d-1 (0-indexed)
for each x increase or decrement d to adjust the n=index modulo the length of the characters and output the current character
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int t,d;
    scanf("%d ",&t);
    for(int ti=1;ti<=t;ti++){
        printf("%d ",ti);
        scanf("%d",&d);
        getchar(); // clear newline
        char s[94];
        int n,l=0,c=0;
        s[0]=getchar();
        while(s[l]!='\n'){
            l++;
            s[l]=getchar();
        }
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int ai;
            scanf("%d",&ai);
            c+=ai+l;
            putchar(s[c%l]);
        }
        putchar('\n');
    }
}
