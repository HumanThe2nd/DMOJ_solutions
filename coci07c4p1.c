/*
COCI '07 Contest 4 #1 Vauvau
Author : Dan Shan
Date: 2025-02-24
Modulus on the time (subtract 1 for 1-indexing)
*/
#include <stdio.h>
int main() {
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    b+=a; d+=c; // for modulo
    for(int i=0;i<3;i++){
        int ai;
        scanf("%d",&ai);
        ai--;
        int f=ai%b<a,f2=ai%d<c;
        if(f&&f2) puts("both");
        else if(f||f2) puts("one");
        else puts("none");
    }
}
