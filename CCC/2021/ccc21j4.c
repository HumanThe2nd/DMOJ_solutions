// CCC '21 J4 - Arranging Books
// By: Dan Shan
#include <stdio.h>
#include <string.h>
int main(){
char s[500001];
scanf("%s",s);
int sl = strlen(s),l=0,m=0,nl=0,ml=0,nm=0,lm=0;
for(int i=0;i<sl;i++){
	if(s[i]=='L')l++;
	else if(s[i]=='M')m++;
}
for(int i=0;i<l;i++){
	if(s[i]!='L')nl++;
	if(s[i]=='M')ml++;
}
for(int i=l;i<l+m;i++){
	if(s[i]!='M')nm++;
	if(s[i]=='L')lm++;
}
int c = nl+nm-(ml<lm?ml:lm);
printf("%d\n",c);
}
