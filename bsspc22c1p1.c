// BSSPC '22 P1 - Bubble Tea Tracker
// By: Dan Shan
#include <stdio.h>
int main() {
int n,c=0;
scanf("%d",&n);
for(int i=0;i<n;i++){
	int xi;
	scanf("%d",&xi);
	c+=xi;
	printf("%d\n",c);
}
}
