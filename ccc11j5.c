// CCC '11 J5 - Unfriend
// By: Dan Shan
#include <stdio.h>
int main() {
int n,p[7]={1,1,1,1,1,1,1};
scanf("%d",&n);
for(int i=1;i<n;i++){
	int a;
	scanf("%d",&a);
	p[a]*=(1+p[i]);
}
printf("%d\n",p[n]);
}
