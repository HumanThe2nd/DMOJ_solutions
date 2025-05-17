/*
COCI '13 Contest 3 #1 Riječi
Author: Dan Shan
Date: 2025-05-16
each press:
b += a
a += current_b (b before adding a)
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    int k,a=1,b=0;
    scanf("%d",&k);
    for(int i=0;i<k;++i){
        int temp=b;
        b+=a; a=temp;
    } printf("%d %d\n",a,b);
}
