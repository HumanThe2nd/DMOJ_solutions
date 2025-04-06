/*
Amplitude Hackathon Winter '24 Problem 4 - Dance Dance Revolution
Author: HumanThe2nd
Date: 2025-04-05
max subsequences of string 2 in string 1
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main() {
    char s[1001],s2[1001];
    int n=0,m=0,c=0;
    scanf("%s %s",s,s2);
    while(s[n]!='\0') n++;
    while(s2[m]!='\0') m++;
    for(int i=0;i<n;i++){
        if(s[i]==s2[c%m]) c++;
    }
    printf("%d\n",c/m);
}
