/*
BlueBook - Leap Year
Author: Dan Shan
Date: 2025-07-13
Leap year: (divisible by 400) or [(divisible by 4) and (not divisible by 100)] or [(not divisible by 4) and (divisible by 100)]
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        if(n%400==0||(n%4&&n%100==0)||(n%4==0&&n%100)) puts("1");
        else puts("0");
    }
}
