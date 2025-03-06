/*
DMPG '18 B2 - Mimi and Modulus
Author: HumanThe2nd
Date: 2025-03-05
minimum(n,m-1)
*/
#include <stdio.h>
int main() {
    int a,b;
    scanf("%d %d",&a,&b);
    if(a<b) printf("%d\n",a);
    else printf("%d\n",b-1);
}
