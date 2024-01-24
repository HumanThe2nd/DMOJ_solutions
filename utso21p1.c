// UTS Open '21 P1 - COVID Party
// By: Dan Shan
#include <stdio.h>
int main() {
int n,s=2,c=1,d=3,dc=0;
scanf("%d",&n);
while(s<n){
	c++;
	s+=d;
	if(!dc)dc=1;
	else{
		dc=0;
		d+=2;
	}
}
printf("%d\n",c);
}
