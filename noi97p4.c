// NOI '97 P4 - Perfect Tour
// By: Dan Shan
#include <stdio.h>
int main() {
	int m,n;
	scanf("%d %d",&m,&n);
	int a[n-1]; n--;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<m;i++){
		for(int j=0;j<n;j++){
			int ai;
			scanf("%d",&ai);
			if(ai>a[j]) a[j]=ai;
		}
	}
	int s = a[0],e = a[0];
	for(int i=1;i<n;i++) {
		e=e>0?e+a[i]:a[i];
		s=s>e?s:e;
	}
	printf("%d\n",s);
}
