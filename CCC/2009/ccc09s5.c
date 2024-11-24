// CCC '09 S5 - Wireless
// Author: Dan Shan
// Date: 2024-09-29
// Theory: array of difference array adding each left edge of the circle and subtracting the right
// find the left and right edges using pythagorean iterating x and solving for y rounded down to integers
// note: cicles may go out of bounds. If the left edge of the circle is out of bounds start the left edge at y=0 to account for the portion within the grid
#include <stdio.h>
#include <math.h>
int scan() {
    int num = 0;
    char c = getchar_unlocked();
    while (c>'9'||c<'0') c = getchar_unlocked();
    while (c>='0'&&c<='9') {
        num=num*10+c-'0';
        c=getchar_unlocked();
    }
    return num;
}
int a[1001][30001];
int main() {
	int m=scan(),n=scan(),k=scan();
	while(k--){
		int x=scan(),y=scan(),r=scan(),b=scan();
		int xi=r;
		while(xi>=-r){
			int yi=sqrt(r*r-xi*xi);
			if(x+xi>=0&&x+xi<=n&&y-yi>=0&&y-yi<=m) a[x+xi][y-yi]+=b;
			if(x+xi>=0&&x+xi<=n&&y+yi+1>=0&&y+yi+1<=m) a[x+xi][y+yi+1]-=b;
			if(x+xi>0&&x+xi<=n&&y-yi<0)a[x+xi][0]+=b;
			xi--;
		}
	}
	int max=0,c=0;
	for(int i=0;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]+=a[i][j-1];
			if(a[i][j]>max) {
				max=a[i][j];
				c=0;
			}
			if(a[i][j]==max) c++;
		}
	}
	printf("%d\n%d\n",max,c);
}
