/*
MWC '15 #1 P5: Love Guru
Author: Dan Shan
Date: 2024-11-11
Modular arithmetic
every exponent repeats its unit digit mod 4
*special case* when mod 4 = 0, unit = n ^ 4 instead of n ^ 0
*/
#include <stdio.h>
#include <math.h>
int main() {
	int a=0,b=0,c=1;
	char s=getchar_unlocked();
	while(s!='\n'){
		if(s<'a') s+='a'-'A'; // lowercase all letters
		if(c%4) a+=pow((s-'a'+1)%10,c%4);
		else a+=pow((s-'a'+1)%10,4);
		a%=10; c++;
		s=getchar_unlocked();
	} c=1;
	s=getchar_unlocked();
	while(s!='\n'){
		if(s<'a') s+='a'-'A'; // lowercase all letters
		if(c%4) b+=pow((s-'a'+1)%10,c%4);
		else b+=pow((s-'a'+1)%10,4);
		b%=10; c++;
		s=getchar_unlocked();
	}
	if(!a) a+=10;
	if(!b) b+=10;
	printf("%d\n",a+b);
}
