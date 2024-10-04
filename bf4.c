// String Finding
// Author: Dan Shan
// Date: 2024-10-03
// Input: text followed by pattern
// Solution: Rabin-Karp pattern search
#include <stdio.h>
int main() {
	char s[1000002],p[1000002];
	long long l=0,l2=0,h=1,i=0;
	long long d=256,ph=0,th=0,q=1e9+7;
	for(l=0;l<1000002;l++){
		s[l]=getchar_unlocked();
		if(s[l]=='\n') break;
	}
	for(l2=0;l2<1000002;l2++){
		p[l2]=getchar_unlocked();
		if(p[l2]=='\n') break;
	}
	for(i=0;i<l2-1;i++) h=(h*d)%q;
	for(i=0;i<l2;i++){
		ph=(d*ph+p[i])%q;
		th=(d*th+s[i])%q;
	}
	for(i=0;i<=l-l2;i++){
		if(ph==th){/* manual checker for hash collisions
			int j=0;
			for(j=0;j<l2;j++){
				if(s[i+j]!=p[j]) break;
			}
			if(j==l2) */return printf("%lld\n",i)*0;
		}
		if(i<l-l2){
			th=(d*(th-s[i]*h)+s[i+l2])%q;
			if(th<0) th+=q;
		}
	}
	printf("-1\n");
}
