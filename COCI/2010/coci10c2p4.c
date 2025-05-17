// COCI '10 Contest 2 #4 Knjige
// By: Dan Shan
#include <stdio.h>
int main() {
int n,a[300001];
scanf("%d",&n);
for(int i=0;i<n;i++) scanf("%d",&a[i]);
int f=0,c=0,nt=n;
for(int i=n;i>0;i--){
	if(a[i]==n) f=1;
	if(!f) continue;
	if(a[i]==nt){
		c++;
		nt--;
	}
}
if(a[0]==nt)c++;
printf("%d\n",n-c);
}
