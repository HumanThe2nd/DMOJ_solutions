/*
CCC '96 S2 - Divisibility by 11
Author: Dan Shan
Date: 2024-11-07
subtract:
decrement rightmost nonzero digit by 1, every 0 between nonzero digit and deleted digit becomes 9
Check if 2 digits of final number are equal
2 newlines between cases
1 newline at the end
*/
#include <stdio.h>
int main() {
	int n;
	scanf("%d ",&n);
	while(n--){
		char s[51],s2[51];
		int l=0,r=0;
		s[0]=getchar_unlocked();
		s2[0]=s[0];
		while(s[r]!='\n'){
			r++; s[r]=getchar_unlocked();
			s2[r]=s[r];
		} s2[r]='\0'; r--;
		printf("%s\n",s2);
		while(r-l>1){
			r--;
			s[r]-=(s[r+1]-'0');
			if(s[r]<'0'){ // borrow digits
				s[r]+=10;
				for(int j=r-1;j>=l;j--){ // find first nonzero digit
					if(s[j]=='0') s[j]='9';
					else{
						s[j]--;
						break;
					}
				}
			}
			while(s[l]=='0') l++;
			for(int i=l;i<=r;i++){
				putchar_unlocked(s[i]);
			} putchar_unlocked('\n');
		}
		if(s[l]==s[r]&&l!=r) printf("The number %s is divisible by 11.\n",s2);
		else printf("The number %s is not divisible by 11.\n",s2);
		if(n) putchar_unlocked('\n');
	}
}
