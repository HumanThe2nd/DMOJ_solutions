// CCC '11 S3 - Alice Through the Looking Glass
// Author: Dan Shan
// Date: 2024-10-02
#include <stdio.h>
#include <math.h>
int search(int m, int x, int y){
	if(!m) return 0;
	int p=pow(5,m-1);
	int xi=x/p,yi=y/p;
	if(!xi&&!yi) return 0;
	if((xi>0&&xi<4&&!yi)||(xi==2&&yi==1)) return 1;
	if(((xi==1||xi==3)&&yi==1)||(xi==2&&yi==2)) return search(m-1,x%p,y%p);
	return 0;
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int m,x,y;
		scanf("%d%d%d",&m,&x,&y);
		if(search(m,x,y)) printf("crystal\n");
		else printf("empty\n");
	}
}
