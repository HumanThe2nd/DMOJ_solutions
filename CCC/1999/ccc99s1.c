// CCC '99 S1 - Card Game
// Author: Dan Shan
// Date: 2024-09-17
#include <stdio.h>
int check(char c){
	if(c=='j'||c=='q'||c=='k'||c=='a') return 0;
	return 1; 
}
int main() {
    char s[52][6];
	int a[]={0,0};
	for(int i=0;i<52;i++) scanf("%s",s[i]);
	for(int i=0;i<51;i++){
		if(s[i][0]=='j'&&check(s[i+1][0])) {
			a[i&1]++;
			printf("Player %c scores 1 point(s).\n",'A'+(i&1));
		}
		else if(s[i][0]=='q'&&i<50&&check(s[i+1][0])&&check(s[i+2][0])) {
			a[i&1]+=2;
			printf("Player %c scores 2 point(s).\n",'A'+(i&1));
		}
		else if(s[i][0]=='k'&&i<49&&check(s[i+1][0])&&check(s[i+2][0])&&check(s[i+3][0])) {
			a[i&1]+=3;
			printf("Player %c scores 3 point(s).\n",'A'+(i&1));
		}
		else if(s[i][0]=='a'&&i<48&&check(s[i+1][0])&&check(s[i+2][0])&&check(s[i+3][0])&&check(s[i+4][0])) {
			a[i&1]+=4;
			printf("Player %c scores 4 point(s).\n",'A'+(i&1));
		}
	}
	printf("Player A: %d point(s).\nPlayer B: %d point(s).\n",a[0],a[1]);
}
