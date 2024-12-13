/*
COCI '10 Contest 4 #1 Avion
Author: Dan Shan
Date: 2024-12-12
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int f=0;
	for(int i=1;i<=5;i++){
        char s[10];
        int l=0;
        s[0]=getchar_unlocked();
        while(s[l]!='\n') {
            l++;
            s[l]=getchar_unlocked();
            if(l>1&&s[l]=='I'&&s[l-1]=='B'&&s[l-2]=='F'){
                if(f) putchar_unlocked(' ');
                printf("%d",i);
                f=1;
            }
        }
    }
    if(!f) printf("HE GOT AWAY!");
    putchar_unlocked('\n');
}
