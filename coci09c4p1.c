// COCI '09 Contest 4 #1 Autori
// Author: Dan Shan
// Date: 2024-10-21
// print capital letters
#include <stdio.h>
int main() {
	int r=0;
	char s[51];
	while(1){
		char c=getchar_unlocked();
		if(c=='\n') break;
		if(c<'a'&&c!='-') {
			s[r]=c; r++;
		}
	} s[r]='\0';
	printf("%s\n",s);
}
