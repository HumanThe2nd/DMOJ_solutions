/*
XOR
Author: Dan Shan
Date: 2024-Nov-02
find: xor [a,b]
simplifies to xor range 0 to a-1 with range a to b inclusive
xor 0 to the number can be given by 4 cases using modulus
n%4 = 0: n
n%4 = 1: 1
n%4 = 2: n+1
n%4 = 3: 0
xor the result of a-1 and b
*/
#include <stdio.h>
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b;
		scanf("%d %d",&a,&b);
		a--;
		if(a%4==1) a=1;
		else if(a%4==2) a++;
		else if(a%4==3) a=0;
		if(b%4==1) b=1;
		else if(b%4==2) b++;
		else if(b%4==3) b=0;
		printf("%d\n",a^b);
	}
}
