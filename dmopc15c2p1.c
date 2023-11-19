// DMOPC '15 Contest 2 P1 - Grumpy Dwarf
// By: Dan Shan 
// Simulation of dividing with remainders till division is less than 1 tracking sum of numerators
#include<stdio.h>
int main(){
int n,k,s;
scanf("%d %d",&n,&k);
s=n;
while(n>=k){
	s+=n/k;
	n = n%k+n/k;
}
printf("%d\n",s);
}
