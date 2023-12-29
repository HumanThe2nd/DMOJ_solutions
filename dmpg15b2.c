// DMPG '15 B2 - Trunk in Trunk
// By: Dan Shan
#include <stdio.h>
int main(){
	int a,b,c,d,e,f;
	scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
	if(a<=d&&b<=e&&c<=f)printf("Y\n");
	else if(a<=d&&b<=f&&c<=e)printf("Y\n");
	else if(a<=f&&b<=d&&c<=e)printf("Y\n");
	else if(a<=f&&b<=e&&c<=d)printf("Y\n");
	else if(a<=e&&b<=d&&c<=f)printf("Y\n");
	else if(a<=e&&b<=f&&c<=d)printf("Y\n");
	else printf("N\n");
}
