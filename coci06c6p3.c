/*
COCI '06 Contest 6 #3 Maraton
Author: HumanThe2nd
Date: 2025-04-29
Check all 3 adjacent cells that form a line (skip '.')
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main() {
    int n;
    scanf("%d",&n);
    char s[n][n+1];
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s[i][j]=='.') continue;
            if(j>1&&s[i][j-1]==s[i][j]&&s[i][j-2]==s[i][j]) return !printf("%c\n",s[i][j]);
            if(i>1&&s[i-1][j]==s[i][j]&&s[i-2][j]==s[i][j]) return !printf("%c\n",s[i][j]);
            if(i>1&&j>1&&s[i-1][j-1]==s[i][j]&&s[i-2][j-2]==s[i][j]) return !printf("%c\n",s[i][j]);
            if(i>1&&j<n-2&&s[i-1][j+1]==s[i][j]&&s[i-2][j+2]==s[i][j]) return !printf("%c\n",s[i][j]);
        }
    }
    puts("ongoing");
}
