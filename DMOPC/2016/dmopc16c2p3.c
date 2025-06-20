// DMOPC '16 Contest 2 P3 - Queries
// By: Dan Shan
// Theory: put all 'a' on one side and all 'b' on the other side
#include <stdio.h>
int main() {
	int t;
	scanf("%d",&t);
	for(int ti=0;ti<t;ti++){
		int n,m,m1=0,m2=0;
		scanf("%d %d",&n,&m);
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			if(a>m1)m1=a;
			if(b>m2)m2=b;
		}
		if(m1+m2>n){
			printf("-1\n");
			continue;
		}
		for(int i=0;i<m1;i++)printf("a");
		for(int i=m1;i<n;i++)printf("b");
		printf("\n");
	}
}
