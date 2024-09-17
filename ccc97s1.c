// CCC '97 S1 - Sentences
// Author: Dan Shan
// Date: 2024-09-17
// 3 layer loop
#include <stdio.h>
int main() {
    int t;
	scanf("%d",&t);
	while(t--){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		char s[a][26],s2[b][26],s3[c][26];
		for(int i=0;i<a;i++) { 
			getchar_unlocked();
			scanf("%[^\n]",s[i]);
		}
		for(int i=0;i<b;i++) { 
			getchar_unlocked();
			scanf("%[^\n]",s2[i]);
		}
		for(int i=0;i<c;i++) { 
			getchar_unlocked();
			scanf("%[^\n]",s3[i]);
		}
		for(int i=0;i<a;i++){
			for(int j=0;j<b;j++){
				for(int k=0;k<c;k++){
					printf("%s %s %s.\n",s[i],s2[j],s3[k]);
				}
			}
		}
	}
}
