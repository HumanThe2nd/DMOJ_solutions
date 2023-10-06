//============================================================================
// Name        : STNBD P1 - Ren Ashbell
// Author      : Dan Shan
//============================================================================
// Goal: check if first input greater than rest
// Approach: store first input for each other input if greater or equal print
//			 no and return if loop finished and return yes
#include <iostream>
int main() {
int n,a;
scanf("%d %d",&n,&a);
for(int i=0;i<n;i++){
	int in;
	scanf("%d",&in);
	if(in>=a){printf("NO\n");return 0;}
}
printf("YES\n");
}
