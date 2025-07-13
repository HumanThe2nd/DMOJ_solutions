/*
BlueBook - Grades
Author: Dan Shan
Date: 205-07-12
If conditions
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        if(n>100||n<0) puts("X");
        else if(n>79) puts("A");
        else if(n>69) puts("B");
        else if(n>59) puts("C");
        else if(n>49) puts("D");
        else puts("F");
    }
}
