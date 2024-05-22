// Baltic OI '14 P2 - Three Friends
// By: Dan Shan
#include<stdio.h>
int main() {
	int l=0;
	char c[2000002];
	while(1){
		c[l]=getchar_unlocked();
		if(c[l]=='\n')break;
		l++;
	}
	if(!(l&1)) return printf("NOT POSSIBLE\n")*0;
	int f=0,o=0;
	for(int i=0;i<l/2;i++){
		if(c[i]!=c[l/2+i+f]){
			f++; i--;
			if(f>1)break;
		}
	}
	if(f<2) o++;
	f=0;
	for(int i=0;i<l/2;i++){
		if(c[i+f]!=c[l/2+i+1]){
			f++; i--;
			if(f>1)break;
		}
	}
	if(f==1&&o) printf("NOT UNIQUE");
	else if(f>1&&!o) printf("NOT POSSIBLE");
	else if(o==1){
		for(int i=0;i<l/2;i++) putchar_unlocked(c[i]);
	}
	else{
		for(int i=l/2+1;i<l;i++) putchar_unlocked(c[i]);
	}
	putchar_unlocked('\n');
}
