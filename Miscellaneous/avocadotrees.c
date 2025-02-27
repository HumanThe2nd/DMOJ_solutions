/*
Avocado Trees!
Author: Dan Shan
Date: 2024-10-09
conditional PSA + max of array greedy algorithm
*/
#include <stdio.h>
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
int a[1000001],psa[1000002];
int main() {
	int n=scan(),q=scan(),h=scan(),m=0;
	for(int i=0;i<n;i++){
		int ai=scan(),bi=scan();
		if(ai<=h) a[i]+=bi;
	} psa[0]=0;
	for(int i=0;i<n;i++){
		psa[i+1]=psa[i]+a[i];
	}
	while(q--){
		int ai=scan(),bi=scan();
		int mi=psa[bi]-psa[ai-1];
		if(mi>m) m=mi;
	}
	printf("%d\n",m);
}
