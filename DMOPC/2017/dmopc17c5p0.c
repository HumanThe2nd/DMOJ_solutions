/*
DMOPC '17 Contest 5 P0 - Mimi and Pizza
Author: Dan Shan
Date: 2025-06-23
nested if statements
*/
#include <stdio.h>
int main() {
    int b,p;
    char s[2];
    scanf("%d %d %s",&b,&p,s);
    if(s[0]=='Y'){
        if(b-5*p>=0) return !puts("B");
        if(b-2*p>=0) return !puts("D");
    }
    else{
        if(b-5*p>=0) return !puts("A");
        if(b-2*p>=0) return !puts("C");
    }
    puts("NO PIZZA");
}
