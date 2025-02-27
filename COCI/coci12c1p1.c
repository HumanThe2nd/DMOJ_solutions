/*
COCI '12 Contest 1 #1 DOM
Author: Dan Shan
Date: 2024-12-04
*/
#include <stdio.h>
int main() {
	char t[]="CAMBRIDGE";
	while(1){
		char si=getchar_unlocked();
		if(si=='\n') break;
		int f=1;
		for(int j=0;j<9;j++){
			if(si!=t[j]) continue;
			f=0; break;
		}
		if(f) putchar_unlocked(si);
	}
	putchar_unlocked('\n');
}
