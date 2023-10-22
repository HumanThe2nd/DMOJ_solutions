//============================================================================
// Name        : Mock CCC '19 Contest 1 J3 - Pusheen Eats Tuna Sashimi and Tuna Nigiri
// Author      : Dan Shan
//============================================================================
// Goal: check if number is divisible by multiplies of 2 numbers 
// Approach: brute force each combination if one works return yes
#include<stdio.h>
int main(){
int t;
scanf("%d",&t);
for(int i=0;i<t;i++){
	int a,b,n,y=0;
	scanf("%d %d %d",&a,&b,&n);
	if(!(n%b%a)||!(n%a%b))y=1;
for(int k=1;k<n;k++){
		if(n%(k*a)%b==0)y=1;
		else if(n%(k*b)%a==0)y=1;
}
if(y)printf("YES\n");
else printf("NO\n");
}
}
