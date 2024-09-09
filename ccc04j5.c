// CCC '04 J5 - Fractals
// Author: Dan Shan
// Date: 2024-09-08
// find: points on x cord where one of its 4 adjacent sides is not the same as it.
// Steps build fractal with recursion, check points using geometry. 
// Build fractal max width of 81 using recursion
// start with empty 81x81 grid with the function called with w=27,start=(41,-13)
// If l=0 finish building current segment otherwise: 
// for each direction if l>=0 call the build function with l-1,w/3 and new directions
// check points y values along the x cord*(81/w)
// to check each point check the coordinates x-1 and x if within bounds as the point lies between those two grid lines
#include <stdio.h>
int a[81][81];
void build(int l, int w, int x, int y){
    if(l<0) return;
    if(x>=0&&x<81&&y>=0&&y<81){ // above x axis
        for(int i=0;i<=w/2;i++){
            for(int j=0;j<=w/2;j++){ // fill in segment
                a[x+i][y+j]=1;
                a[x+i][y-j]=1;
                a[x-i][y+j]=1;
                a[x-i][y-j]=1;
            }
        }
    } w/=3; l--;
    build(l,w,x+w*2,y);
    build(l,w,x,y+w*2);
    build(l,w,x-w*2,y);
    build(l,w,x,y-w*2);
    build(l,w,x+w,y+w); // build a additional child fractal inside of each big fractal 
    build(l,w,x+w,y-w); // so their children of the child frcatals can come out the corners
    build(l,w,x-w,y+w);
    build(l,w,x-w,y-w);
}
int main() {
	int l,w,x;
    scanf("%d %d %d",&l,&w,&x);
    int ratio=81/w; // adjust size for input grid
    build(l,81,40,-41); // build fractal
    x*=ratio;
    int q[82],c=0;
    for(int i=0;i<81;i+=ratio){
        int f=!i&&!a[x][i];
        if((i&&a[x][i]!=a[x][i-1])) f=1;
        else if(x&&a[x-1][i]!=a[x][i]) f=1;
        else if(x&&i&&a[x-1][i]!=a[x-1][i-1]) f=1; // diagonals
        if(f){
            q[c]=i; c++;
        }
    }
    for(int i=0;i<c-1;i++) printf("%d ",q[i]/ratio+1);
    if(c) printf("%d\n",q[c-1]/ratio+1);
}
