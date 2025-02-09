/*
Mock CCC '19 Contest 2 J4 - Tudor Buys Some Cheesecake
Author: Dan Shan
Date: 2025-02-09
Frequency arrays
*/
#include <stdio.h>
int f[26];
int main() {
   char a=getchar();
   int c=0;
   while(a!='\n') f[a-'A']++,a=getchar();
   a=getchar();
   while(a!='\n'){
        if(f[a-'A']) f[a-'A']--;
        a=getchar();
    }
    for(int i=0;i<26;i++) c+=f[i];
    printf("%d\n",c);
}
