// DMOPC '18 Contest 4 P2 - Dr. Henri and Responsibility
// By: Dan Shan
// Bounded knapsack modified
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
    int n=scan(),s=0;
    int a[n],dp[n*700+1];
    for(int i=0;i<n;i++){
        a[i]=scan();
        s+=a[i];
    }
    for(int i=1;i<=n*700;i++){
        dp[i]=0;
    } dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=n*700;j>=0;j--){
            if(!dp[j]||a[i]+j>n*700) continue;
            dp[j+a[i]]=1;
        }
    } int m = 2e9;
    for(int i=0;i<=n*700;i++){
        if(!dp[i]) continue;
        m = min(m,max(i,s-i)-min(i,s-i));
    }
    printf("%d",m);
}
