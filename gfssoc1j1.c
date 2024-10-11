// GFSSOC '14 Winter J1 - Flying Plushies
// Author: Dan Shan
// Date: 2024-10-10
#include <stdio.h>
int main() {
	int m,n,c=0;
	scanf("%d %d",&m,&n);
	while(n--){
		int a;
		scanf("%d",&a);
		if(m<=a) c++;
	}
	printf("%d\n",c);
}
