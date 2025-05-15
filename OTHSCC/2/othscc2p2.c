/*
OTHS Coding Competition 2 P2 - Ghoul Investigators
Author: Dan Shan
Date: 2024-07-25
Basic comparison
*/
#include <stdio.h>
int main() {
    short k,n,m=0;
    scanf("%hd %hd",&k,&n);
    while(n--){
        short  a;
        scanf("%hd",&a);
        if(a>m) m=a;
    }
    printf("%s\n",k>m?"run away":"fight");
}
