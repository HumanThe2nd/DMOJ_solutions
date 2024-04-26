// DMOPC '14 Contest 4 P3 - Golden Lily
// simple iterative Dynamic programming problem
// note: inversion of x and y axis in this problem is important
#include<stdio.h>
#define min(a,b)((a)<(b)?(a):(b))

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

int main() {
    int d=scan(),l=scan();
    int a[l][d],dp[l][d];
    for(int i=0;i<l;i++){
        for(int j=0;j<d;j++) {
            a[i][j]=scan();
            dp[i][j]=2e9;
        }
    }
    dp[0][0]=a[0][0];
    for(int i=1;i<d;i++) dp[0][i]=a[0][i]+dp[0][i-1];
    int y=scan(),x=scan();
    for(int i=1;i<l;i++){
        dp[i][0]=min(dp[i][0],dp[i-1][0]+a[i][0]);
        for(int j=1;j<d;j++){
            dp[i][j]=min(dp[i][j],dp[i-1][j]+a[i][j]);
            dp[i][j]=min(dp[i][j],dp[i][j-1]+a[i][j]);
        }
        for(int j=d-1;j>0;j--){
            dp[i][j-1]=min(dp[i][j-1],dp[i][j]+a[i][j-1]);
        }
        for(int j=1;j<d;j++){
            dp[i][j]=min(dp[i][j],dp[i][j-1]+a[i][j]);
        }
    }
    printf("%d\n",dp[x][y]);
}
