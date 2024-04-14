// IOI '14 Practice Task 1 - Square
// By: Dan Shan
#include <stdio.h>
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
    int n=scan();
    int a[n][n],dp[n][n],m=0,c=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=scan();
            if(!i||!j){
                dp[i][j]=a[i][j];
            }
            else dp[i][j]=0;
            if(dp[i][j]>m){
            m=dp[i][j];
            c=1;
            }
            else if(dp[i][j]==m) c++;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(a[i][j]==1){
                dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                if(dp[i][j]>m){
                    m=dp[i][j]; c=1;
                }
                else if(dp[i][j]==m) c++;
            }
        }
    }
    printf("%d",m*c);
}
