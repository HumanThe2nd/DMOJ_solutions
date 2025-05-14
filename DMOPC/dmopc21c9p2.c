/*
DMOPC '21 Contest 9 P2 - String Puzzle
Author: Dan Shan
Date: 2025-01-24
push characters into stack merging duplicates
if stack only has 1 char and it matches the next s2 char then delete it from both
if stack and both strings are empty, the puzzle is possible
*/
#include <stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    getchar();
    while(t--){
        char s[1000001],s2[1000001],stk[10000001];
        int r=0,r2=0,l=0;
        s[0]=getchar();
        while(s[r]!=' ') s[++r]=getchar();
        s2[0]=getchar();
        while(s2[r2]!='\n') s2[++r2]=getchar();
        --r; --r2;
        while(r>=0&&r2>=0){
            stk[l++]=s[r--]; // add to stack
            while(l>1&&stk[l-1]==stk[l-2]) stk[l-2]++,l--; // merge dupes
            if(l==1&&stk[0]==s2[r2]) l--,r2--;
        }
        if(!l&&r<0&&r2<0) puts("YES");
        else puts("NO");
    }
}
