// COCI '17 Contest 1 #1 Cezar
// Author: Dan Shan
#include <stdio.h>
int main() {
	int n,a[12],c=0; a[10]=16; a[11]=4;
	for(int i=2;i<10;i++) a[i]=4;
	scanf("%d",&n);
	while(n--){
		int ai;
		scanf("%d",&ai);
		c+=ai; a[ai]--;
	} int c2=0;
	for(int i=2;i<=21-c&&i<12;i++){
		c2+=a[i];
	} 
	printf("%s\n",(c2>=(50-n)/2)?"VUCI":"DOSTA");
}
