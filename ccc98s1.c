// CCC '98 S1 - Censor
// By: Dan Shan
#include <stdio.h>
int main() {
	int n;
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++){
		char s[81];
		int c=0, j;
		for(j=0;j<80;j++){
			s[j]=getchar();
			if(s[j]=='\n') {
				if(c==4){
					for(int k=1;k<=4;k++)
					s[j-k]='*';
				}
				break;
			}
			if(s[j]==' '){
				if(c==4){
					for(int k=1;k<=4;k++)
					s[j-k]='*';
				}
				c=0;
				continue;
			}
			c++;
		}
		s[j]='\0';
		printf("%s\n",s);
	}
}
