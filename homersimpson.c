/*
Homer Simpson
Author: HumanThe2nd
Date: 2025-03-17
Dyanamic programming:
Store 2 dp arrays, one with beer and one with burgers eaten
for every second up to t, he has 3 choices check each choice
Prioritize minimum beer, tiebreaker with maximum burger consumption
*/
#include <stdio.h>
int scan() {
    int num = 0;
    char c = getchar();
    if(c==EOF) return -1;
    while (c>'9'||c<'0') c = getchar();
    while (c>='0'&&c<='9') {
        num=num*10+c-'0';
        c=getchar();
    }
    return num;
}
int main(){
    while(1){
        int n=scan(),m=scan(),t=scan();
        if(n<0) break; // finished
        int dp[t+1],b[t+1];
        for(int i=0;i<=t;i++) {
            b[i]=0; dp[i]=-2e9;
        } dp[0]=0;
        for(int i=0;i<t;i++){
            if(i+n<=t) {
                if(b[i]<b[i+n]||(b[i]==b[i+1]&&dp[i]+1>dp[i+n])) {
                    b[i+n]=b[i];
                    dp[i+n]=dp[i]+1;
                }
            }
            if(i+m<=t) {
                if(b[i]<b[i+m]||(b[i]==b[i+1]&&dp[i]+1>dp[i+m])) {
                    b[i+m]=b[i];
                    dp[i+m]=dp[i]+1;
                }
            }
            if(dp[i+1]<0) { // "drink beer"
                b[i+1]=b[i]+1;
                dp[i+1]=dp[i]; 
            }
        }
        if(!b[t]) printf("%d\n",dp[t]);
        else printf("%d %d\n",dp[t],b[t]);
    }
}
