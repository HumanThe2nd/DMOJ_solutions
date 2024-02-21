// Mock CCC '15 S1 - Dupvoting
// By: Dan Shan
#include <stdio.h>
int main() {
int p,u,r1,r2,c=0;
scanf("%d %d %d %d",&p,&u,&r1,&r2);
double r = (double)r1/r2;
for(int i=1;i<u;i++){
	for(int j=1;j<i;j++){ // check net
		if((i-j)*2+j-u+i!=p) continue;
		if((double)(i-j)/j==r||(double)j/(i-j)==r) c++;
		else if((double)(u-i)/j==r||(double)j/(u-i)==r) c++;
		else if((double)(i-j)/(u-i)==r||(double)(u-i)/(i-j)==r) c++;
	}
}
printf("%d\n",c);
}
