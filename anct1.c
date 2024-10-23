// Troubling Times
// Author: Dan Shan
// Date: 2024-10-23
// check modulus
#include <stdio.h>
int main() {
	int n,d,m=2e9;
	scanf("%d %d",&n,&d);
	if(!d) return printf("0\n")*0;
	if(d<0) d*=-1;
	while(n--){
		int ai;
		scanf("%d",&ai);
		if(d%ai==0&&d/ai<m) m=d/ai;
	}
	if(m==2e9) printf("This is not the best time for a trip.\n");
	else printf("%d\n",m);
}
