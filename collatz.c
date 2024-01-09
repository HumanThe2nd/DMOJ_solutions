// 3n+1
// By: Dan Shan
#include<stdio.h>
int main(){
int n,c=0;
scanf("%d",&n);
while(n>1){
	c++;
	if(n&1){
		n*=3;
		n++;
	}
	else n>>=1;
}
printf("%d\n",c);
}
