/*
WC '17 Contest 2 J2 - Breeding an Army
Author: Dan Shan
Date: 2025-08-11
Res = min(material_given / material_needed)
*/
#include <stdio.h>

int main() {
    int a,b,c,a2,b2,c2;
    scanf("%d %d %d %d %d %d",&a,&b,&c,&a2,&b2,&c2);
    int res=a2/a;
    if(b2/b<res) res=b2/b;
    if(c2/c<res) res=c2/c;
    printf("%d\n",res);
}
