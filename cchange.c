#include <stdio.h>
int main() {
    int x,n;
    scanf("%d %d",&x,&n);
    int a[n],dp[x+1]; dp[0]=0;
    for(int i=1;i<=x;i++) dp[i]=1e9;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=x;i++){
    	for(int j=0;j<n;j++){
    		if(a[j]<=i&&dp[i-a[j]!=1e9]){
    			int cur = dp[i-a[j]];
    			if(cur!=1e9&&cur+1<dp[i]) dp[i]=cur+1;
    		}
    	}
    }
    printf("%d\n",dp[x]);
}
