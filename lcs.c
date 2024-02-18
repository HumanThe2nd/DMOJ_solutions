// Longest Common Subsequence
// By: Dan Shan
#include <stdio.h>
#define MAX(a,b)((a)>(b)?(a):(b))
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    int a[n],a2[m],p[m+1],cur[m+1];
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<m;i++){
    	scanf("%d",&a2[i]);
    	p[i]=0; cur[0]=0;
    }p[m]=0;cur[m]=0;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		if(a[i-1]==a2[j-1])cur[j]=p[j-1]+1;
    		else cur[j]= MAX(cur[j-1],p[j]);
    	}
    	for(int j=0;j<=m;j++) p[j]=cur[j];
    }
    printf("%d\n",cur[m]);
}
