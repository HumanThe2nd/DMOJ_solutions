// CCC '15 S2 - Jerseys
// By: Dan Shan
// Storing and comparing data
#include<stdio.h>
int j,a,c;
char s[1000000];
int main(){
scanf("%d %d",&j,&a);
for(int i=0;i<j;i++){
	char s2[2];
	scanf("%s",s2);
	s[i]=s2[0];
}
for(int i=0;i<a;i++){
	int n;
	char s2[2];
	scanf("%s %d",s2,&n);
	if(s2[0]==s[n-1]||(s2[0]=='M'&&s[n-1]=='L')||
	   (s2[0]=='S'&&(s[n-1]=='M'||s[n-1]=='L'))) {
		c++;
		s[n-1]='N';
	}
}
printf("%d\n",c);
}
