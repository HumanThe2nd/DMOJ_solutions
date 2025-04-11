/*
Cheerio Contest 3 P1 - Wet Floor
Author: HumanThe2nd
Date: 2025-04-10
Replace neighbour '.'s with 'C's
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")  
int main() {
   int n,m;
   scanf("%d %d",&n,&m);
   char s[n][m+1];
   for(int i=0;i<n;i++){
    scanf("%s",s[i]);
   }
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(s[i][j]!='W') continue;
        if(i&&s[i-1][j]=='.') s[i-1][j]='C';
        if(i+1<n&&s[i+1][j]=='.') s[i+1][j]='C';
        if(j&&s[i][j-1]=='.') s[i][j-1]='C';
        if(j+1<m&&s[i][j+1]=='.') s[i][j+1]='C';
    }
   }
   for(int i=0;i<n;i++) puts(s[i]);
}
