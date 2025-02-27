/*
COCI '07 Contest 4 #2 Veci
Author: Dan Shan
Date: 2025-02-26
input number as a string, start from the right store frequencies of each number
if any number has a greater number appear before it, replace it and sort the right side of the replacement in non-descending order
if no larger values exist for each digit, its impossible
Note: Brute force passes as well (probably the intended)
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int a[10];
int main() {
    char s[10];
    int l=0;
    s[l]=getchar();
    while(s[l]!='\n') l++,s[l]=getchar();
    for(int i=l-1;i>=0;i--){
        a[s[i]-'0']++;
        for(int j=0;j<10;j++){
            if(a[j]&&j>s[i]-'0'){ // valid swap found
                s[i]=j+'0';
                a[j]--;
                for(int k=0;k<=i;k++) putchar(s[k]);
                for(int k=0;k<10;k++){
                    for(int ii=0;ii<a[k];ii++) putchar('0'+k);
                }
                putchar('\n');
                return 0;
            }
        }
    }
    puts("0");
}
