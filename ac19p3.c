/*
Appleby Contest '19 P3 - A Recursion Problem
Author: Dan Shan
Date: 2024-11-03
Time complexity: O(n)
for every number add it to the sum, if led by a negative subtract instead
*/
#include <stdio.h>
int main() {
	int c=0,t=0,n=0;
	char s=getchar_unlocked();
	while(s!='\n'){
		if(s=='-') n=1;
		else if(s>='0'&&s<='9'){
			t*=10; t+=s-'0';
		}
		else{
			if(n) t*=-1;
			c+=t;
			t=0; n=0;
		}
		s=getchar_unlocked();
	}
	if(n) t*=-1;
	c+=t;
	t=0; n=0;
	printf("%d\n",c);
}
