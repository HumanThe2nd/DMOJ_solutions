/*
Adding Reversed Numbers
Author: Dan Shan
Date: 2024-Oct-30
reverse integer algorithm
Note: be careful of trailing zeros when outputting as they will become leading if unremoved
*/
#include <stdio.h>
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b,a2=0,b2=0;
		scanf("%d %d",&a,&b);
		while(a){
			a2*=10;
			a2+=a%10;
			a/=10; 
		}
		while(b){
			b2*=10;
			b2+=b%10;
			b/=10;
		}
		a2+=b2;
		while(a2%10==0&&a2) a2/=10;
		while(a2){
			printf("%d",a2%10);
			a2/=10;
		}
		putchar('\n');
	}
}
