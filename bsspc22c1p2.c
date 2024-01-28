// BSSPC '22 P2 - Rhyming Numbers
// By: Dan Shan
#include <stdio.h>
int main() {
int n;
scanf("%d",&n);
for(int i=0;i<n;i++){
	int a,b;
	scanf("%d %d",&a,&b);
	a%=100; b%=100;
	if(a==17||b==17)printf("NO\n");
	else if(a==11&&b%10==7)printf("YES\n");
	else if(a%10==7&&b==11)printf("YES\n");
	else printf("NO\n");
}
}
