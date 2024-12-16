/*
ACM U of T Tryouts C2 A - The Super Mario Blues
Author: Dan Shan
Date: 2024-12-16
Simplify string with worlds and levels to just levels as an integer using modulus
Brute force fastest time
*/
#include <stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        getchar_unlocked();
        char w=getchar_unlocked();
        getchar_unlocked();
        char l=getchar_unlocked();
        int c=l-'0'-1+(w-'0'-1)*4,res=0;
        while(c<32){
            res++;
            if(c==1) c=12;
            else if(c==13) c=28;
            else c++;
        }
        printf("%d",res);
        putchar_unlocked('\n');
    }
}
