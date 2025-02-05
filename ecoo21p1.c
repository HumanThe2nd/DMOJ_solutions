/*
ECOO '21 P1 - Many Messages
Author: Dan Shan
Date: 2025-02-05
check 3 times at each addition of interval 'b' to start time 'a'
if none are sufficiently large: "Who knows..."
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    for(int i=0;i<3;i++){
        a+=b;
        if(a>=c) return printf("%d\n",a)*0;
    }
    puts("Who knows...");
}
