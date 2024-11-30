/*
Arcadia Computing Contest 1 P2 - Chemistry
Author: Dan Shan
Date: 2024-11-30
1 person -> 1 test
(people > 1) and (1 row or 1 column) -> alternate 2 tests
otherwise: alternate 2 test per row and alternate the 2 test each adjacent row
Note: printing as characters instead of integers passes 4 times as fast
*/
#include <stdio.h>
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    if(n*m==1) putchar_unlocked('1');
    else if(n==1||m==1) putchar_unlocked('2');
    else putchar_unlocked('4');
    putchar_unlocked('\n');
    if(m==1){ // alternate 1 with 2 instead of 3
        for(int i=0;i<n;i++) {
            putchar_unlocked((i&1)+'1');
            putchar_unlocked('\n');
        }
        return 0;
    }
    for(int i=0;i<n;i++){
        int alt=(i&1)<<1;
        for(int j=0;j<m;j++){
            putchar_unlocked((j&1)+alt+'1');
            if(j<m-1) putchar_unlocked(' ');
        }
        putchar_unlocked('\n');
    }
}
