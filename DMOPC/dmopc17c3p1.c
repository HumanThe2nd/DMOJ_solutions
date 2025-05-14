/*
DMOPC '17 Contest 3 P1 - An Early Christmas Present
Author: Dan Shan
Date: 2025-01-19
min element
*/
#include <stdio.h>
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    n--;
    while(n--){
        int ai;
        scanf("%d",&ai);
        if(ai<m) m=ai;
    }
    printf("%d\n",m);
}
