/*
CCO '08 P5 - Candy
Author: HumanThe2nd
Date: 2025-03-11
Dyanamic programming
States: possible or not possible
Outer loop: each candy type
Middle loop: 1 to v[i] calorie of selected candy
Inner loop: each dp state incrementing by v[i]
Time complexity: O(N*T), where T is the total calories
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int dp[5000001];
int main(){
    int n,t=0;
    scanf("%d",&n);
    int a[n],v[n];
    for(int i=0;i<n;i++){
        scanf("%d %d",&a[i],&v[i]);
        t+=a[i]*v[i];
    } dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<v[i];j++){
            int c=a[i]+1,k=j;
            for(int k=j;k<=t/2;k+=v[i]){
                if(dp[k]) c=0;
                else if(c<a[i]){
                    dp[k]=1;
                    c++;
                }
            }
        }
    }
    for(int i=t/2;i>=0;i--) if(dp[i]) return printf("%d\n",t-2*i)*0;
}
