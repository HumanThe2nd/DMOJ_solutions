/*
OTHS Coding Competition 4 P2 - Furina's Rounding
Author: Dan Shan
Date: 2025-05-03
1. Every digit after the 1st: 9 - original_digit
2. Last digits: 10 - original_digit
3. Print the difference in the digits if the original number isn’t already rounded to one digit
I/O as a string or integer array 
Time Complexity: O(N)
*/
#include <stdio.h>
#include <string.h>
int main(){
    char s[1000002],res[1000002];
    scanf("%s",s);
    int l=strlen(s),f=1,b=0;
    for(int i=l-1;i>0;i--){
        res[i-1]='9'-s[i]+'0';
        if(f){
            res[i-1]++;
            if(s[i]!='0') f=0;
            else res[i-1]='0'; // modulus
        }
    }
    if(f) return !puts("0");
    while(b<l-2&&res[b]=='0') b++;
    for(int i=b;i<l-1;i++) putchar(res[i]);
    putchar('\n');
}
