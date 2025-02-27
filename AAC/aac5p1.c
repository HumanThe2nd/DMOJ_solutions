// An Animal Contest 5 P1 - Bamboo Cookies
// By: Dan Shan
#include <stdio.h>
int n,e,o,j;
int main() {
scanf("%d",&n);
for(int i=0;i<n;i++){
	scanf("%d",&j);
	j%2?e++:o++;
}
printf("%d\n",o/2+e/2);
}
