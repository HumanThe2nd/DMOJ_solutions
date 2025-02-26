// CCC '96 S1 - Deficient, Perfect, and Abundant
// By: Dan Shan
#include <stdio.h>
int main(){
int n;
scanf("%d",&n);
for(int i=0;i<n;i++){
	int s=0,a;
	scanf("%d",&a);
	for(int j=1;j<a;j++) if(!(a%j))s+=j;
	if(s>a)printf("%d is an abundant number.\n",a);
	else printf("%d is a %s number.\n",a,s==a?"perfect":"deficient");
}
}
