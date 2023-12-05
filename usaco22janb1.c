// USACO 2022 January Bronze P1 - Herdle
// Dan Shan
#include <stdio.h>
char s[6][4];
int y,g;
int main(){
for(int i=0;i<6;i++) scanf("%s",s[i]);
for(int i=0;i<3;i++){
	for(int j=0;j<3;j++){
		if(s[i][j]==s[i+3][j]){
			g++;
			s[i][j]='*';
			s[i+3][j]='*';
		}
	}
}
for(int i=3;i<6;i++){
	for(int j=0;j<3;j++){
	    if(s[i][j]=='*') continue;
		for(int k=0;k<3;k++){
			for(int p=0;p<3;p++){
				if(s[i][j]==s[k][p]){
				    y++;
					s[k][p]='*';
					k=3; p=3;
				}
			}
		}
	}
}
printf("%d\n%d\n",g,y);
}
