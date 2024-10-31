/*
ACM U of T Tryouts C0 B - Interleaving Leaves
Author: Dan Shan
Date: 2024-Oct-31
print 2 strings backwards
*/
#include <stdio.h>
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		char s[1001],s2[1001];
		scanf("%d %s %s",&n,s,s2);
		while(n--){
			printf("%c%c",s2[n],s[n]);
		}
		putchar('\n');
	}
}
