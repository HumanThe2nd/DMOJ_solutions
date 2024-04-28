// Title: A Game
// Author: Dan Shan
// Dynamic progamming
#include<stdio.h>
#define min(a,b)((a)<(b)?(a):(b))
#define max(a,b)((a)>(b)?(a):(b))
int scan() {
    int num = 0;
    char c = getchar_unlocked();
    while (c>'9'||c<'0') c = getchar_unlocked();
    while (c>='0'&&c<='9') {
        num=num*10+c-'0';
        c=getchar_unlocked();
    }
    return num;
}

int main(){
    int n=scan();
    int a[n];
    for(int i=0;i<n;i++) a[i]=scan();
    int dp[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dp[i][j] = 0;
    for(int g=0;g<n;g++){
        for(int j=g;j<n;j++){
            int i = j-g;
            int x = ((i+2)<=j) ? dp[i+2][j] : 0;
            int y = ((i+1)<=(j-1)) ? dp[i+1][j-1] : 0;
            int z = (i<=(j-2)) ? dp[i][j-2] : 0;
            dp[i][j] = max(a[i]+min(x,y),a[j]+min(y,z));
        }
    }
    printf("%d\n",dp[0][n-1]);
}
