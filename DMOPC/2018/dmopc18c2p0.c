/*
DMOPC '18 Contest 2 P0 - Mimi and Video Games
Author: Dan Shan
Date: 2025-03-01
maximum cover = r/a floored
if maximum is greater than the grid dimensions output grid edge instead
*/
#include <stdio.h>
int main() {
    int n,a,r;
    scanf("%d %d %d",&n,&a,&r);
    int p=r/a;
    if(p>n) p=n;
    printf("%d\n",p);
}
