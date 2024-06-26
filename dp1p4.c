// Counting Subsequences
// Author: Dan Shan
// subsequences double each time
// by subtracting dp of last value where each character occurs it could mathematically compute the distinct subsequences
// Time Complexity: O(n)
#include<stdio.h>
int main() {
	int i=0,dp[100002],a[26]; dp[0]=1;
	for(int i=0;i<26;i++) a[i]=-1;
	while(1){
		i++;
		char s=getchar_unlocked();
		if(s=='\n') break;
		dp[i]=dp[i-1]*2; 
		if(a[s-'a'!=-1]) dp[i]-=dp[a[s-'a']];
		a[s-'a']=i-1;
		dp[i]%=10007;
	}
	printf("%d\n",dp[i-1]-1);
}
