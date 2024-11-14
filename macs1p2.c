#include <stdio.h>
int main() {
	int n,c=3;
	scanf("%d",&n);
	char s[n+1];
	scanf("%s",s);
	getchar_unlocked();
	for(int i=0;i<n;i++){
		char s2=getchar_unlocked();
		if(s[i]=='S'&&s2=='S') c--;
		if(!c) return printf("NO\n")*0;
	}
	printf("YES\n");
}
