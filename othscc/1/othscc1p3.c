// OTHS Coding Competition 1 (Mock CCC) J3 - Explosion
// By: Dan Shan
#include <stdio.h>
int main(){
	int n,d,c=1,c2=1,m=1,l;
	scanf("%d %d %d",&n,&d,&l);
	for(int i=1;i<n;i++){
		int h;
		scanf("%d",&h);
		if(h-l<=d&&h-l>=-d)c++;
		else{
			if(c>m)m=c;
			c=1;
			c2++;
		}
		l=h;
	}
	if(c>m)m=c;
	printf("%d\n%d\n",c2,m);
}
