/*
Amplitude Hackathon '23 Practice Problem 2 - Go Amplitude!
Author: Dan Shan
Date: 2024-11-19
modulo 11 rule
iterate left to right:
n = (10 n + next digit)%11
*/
#include <stdio.h>
int main() {
    int n=0;
    char s[]="GOAMPLITUDE",c=getchar_unlocked();
    while(c!='\n'){
        n=(n*10+c-'0')%11;
        c=getchar_unlocked();
    }
    n+=10; n%=11;
    putchar(s[n]);
    putchar('\n');
}
