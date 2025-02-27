// Another Contest 8 Problem 1 - Trash Push
// By: Dan Shan
#include <stdio.h>
#include<math.h>
int main(){
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int n,k;
		scanf("%d %d",&n,&k);
		printf("%d\n",(int)ceil((double)n/k));
	}

}
