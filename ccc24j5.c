// CCC '24 J5 - Harvest Waterloo
// By: Dan Shan
// BFS in c
#include <stdio.h>
int main() {
	int R,C,xl[]={0,0,1,-1},yl[]={1,-1,0,0};
	scanf("%d %d",&R,&C);
	char s[R][C+1];
	for(int i=0;i<R;i++)
		scanf("%s",s[i]);
	int qx[R*C+1],qy[R*C+1],l=0,r=1,c=0;
	scanf("%d %d",&qx[0],&qy[0]);
	if(s[qx[0]][qy[0]]=='S')c++;
	else if(s[qx[0]][qy[0]]=='M')c+=5;
	else c+=10;
	s[qx[0]][qy[0]]='*';
	while(l<r){
		int xi=qx[l], yi=qy[l]; l++;
		for(int i=0;i<4;i++){
			int xf=xi+xl[i],yf=yi+yl[i];
			if(xf<0||yf<0||xf>=R||yf>=C||s[xf][yf]=='*') continue;
			if(s[xf][yf]=='S')c++;
			else if(s[xf][yf]=='M') c+=5;
			else c+=10;
			qx[r]=xf,qy[r]=yf;r++; s[xf][yf]='*';
		}
	}
	printf("%d\n",c);
}
