//============================================================================
// Name        : CCC '05 S2 - Mouse Move
// Author      : Dan Shan
//============================================================================
// Goal: find x and y coords after each adjustment given limits
// Approach: update x and y after each input and if less than 0 or greater than
//           the limit for that coordinate update it to 0 or limit respectively
#include<stdio.h>
int main(){
int c,r,xi=0,yi=0;
scanf("%d %d",&c,&r);
while(1){
	int x,y;
	scanf("%d %d",&x,&y);
	if(!x&&!y)break;
	xi+=x;
	if(xi>c)xi=c;
	if(xi<0)xi=0;
	yi+=y;
	if(yi>r)yi=r;
	if(yi<0)yi=0;
	printf("%d %d\n",xi,yi);
}
}
