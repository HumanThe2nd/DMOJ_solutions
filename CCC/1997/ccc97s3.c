// CCC '97 S3 - Double Knockout Competition
// Author: Dan Shan
// Date: 2024-10-04
// seperate each test case with additional newline
// keep shifting half of one loss to elim followed by wins to one loss
// if wins is 1 only shift if one loss is also 1
#include <stdio.h>
#define max(a,b)((a)>(b)?(a):(b))
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int n,n2=0,n3=0,c=0;
		scanf("%d",&n);
		printf("Round 0: %d undefeated, 0 one-loss, 0 eliminated\n",n);
		while(n||n2>1){ c++;
			if(n2>1){
				n3+=n2>>1;
				n2-=n2>>1;
			}
			else if(n==1&&n2==1){
				n--; n2++;
			}
			if(n>1){
				n2+=n>>1;
				n-=n>>1;
			}
			printf("Round %d: %d undefeated, %d one-loss, %d eliminated\n",c,n,n2,n3);
		}
		printf("There are %d rounds.\n",c);
		if(t) printf("\n");
	}
}
