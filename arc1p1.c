/*
Another Random Contest 1 P1 - Chessgame
Author: Dan Shan
Date: 2025-01-23
iterate each row and column up and down marking possible positions
*/
#include <stdio.h>
int main(){
    int n,m,c=0;
    scanf("%d %d",&n,&m);
    char a[n][m];
    for(int i=0;i<n;i++){ getchar();
        int f=0;
        for(int j=0;j<m;j++){
            a[i][j]=getchar();
            if(a[i][j]=='*') f++;
            else if(f>1){
                a[i][j]='v';
                c++;
            }
        }
        if(f<2) continue;
        f=0; // backward cannons
        for(int j=m-1;j>=0;j--){
            if(a[i][j]=='*') f++;
            else if(f>1&&a[i][j]=='.'){
                a[i][j]='v';
                c++;
            }
        }
    }
    for(int i=0;i<m;i++){
        int f=0;
        for(int j=0;j<n;j++){
            if(a[j][i]=='*') f++;
            else if(f>1&&a[j][i]=='.'){
                a[j][i]='v';
                c++;
            }
        }
        if(f<2) continue;
        f=0; // backward cannons
        for(int j=n-1;j>=0;j--){
            if(a[j][i]=='*') f++;
            else if(f>1&&a[j][i]=='.'){
                a[j][i]='v';
                c++;
            }
        }
    }
    printf("%d\n",c);
}
