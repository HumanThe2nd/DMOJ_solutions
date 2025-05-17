/*
COCI '14 Contest 4 #1 Cesta
Author: HumanThe2nd
Date: 2025-04-23
Conditions:
1. sum of digits must be divisible by 3
2. number must contain a 0
If valid: output digits sorted in non-increasing order
Note: This code uses counting sort as digits are between 0 and 9 inclusive
Time Complexity: O(length(N)+9) -> O(length(N))
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int f[10],c=0;
int main() {
    char s[100001],z=0;
    scanf("%s",s);
    for(int i=0;i<100001;i++){
        if(s[i]<'0'||s[i]>'9') break;
        int ai=s[i]-'0';
        if(!ai) z=1; // zero found
        c+=ai;
        f[ai]++; // count frequencies
    }
    if(!z||(c%3)) return puts("-1")*0;
    for(int i=9;i>=0;i--){
        for(int j=0;j<f[i];j++) putchar(i+'0');
    }
    putchar('\n');
}
