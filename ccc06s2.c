// CCC '06 S2 - Attack of the CipherTexts
// Author: Dan Shan
// Date: 2024-09-30
// mapping characters to each other
// 27 characters including the whitespace
// Note: Special case where 26 character are used and the last has to be solved
#include <stdio.h>
int a[91],a2[91];
int main() {
	char s[81];
	int l=0;
	s[0]=getchar_unlocked();
	while(s[l]!='\n'){
		l++; s[l]=getchar_unlocked();
	}
	for(int i=0;i<l;i++){
		char si=getchar_unlocked();
		a[si]=s[i];
		a2[s[i]]=1;
	}
	int c1=0,c2=0; // track number of chaarcters
	char char1,char2;
	for(int i=0;i<26;i++){
		if(a[i+'A']) c1++;
		else char1=i+'A';
		if(a2[i+'A']) c2++;
		else char2=i+'A';
	}
	if(a[' ']) c1++;
	else char1=' ';
	if(a2[' '])c2++;
	else char2=' ';
	if(c1==26&&c2==26){ // one of each unknown
	a[char1]=char2;
	}
	l=0; getchar_unlocked();
	s[0]=getchar_unlocked();
	while(s[l]!='\n'&&s[l]!=EOF){
		if(a[s[l]]==0) putchar_unlocked('.');
		else putchar_unlocked(a[s[l]]);
		l++;
		s[l]=getchar_unlocked();
	} putchar_unlocked('\n');
}
