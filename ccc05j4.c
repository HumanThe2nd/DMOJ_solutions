// CCC '05 J4 - Cross Spiral
// Author: Dan Shan
// Date: 2024-09-04
// Note: Code assumes cut-out rectangles always exist 
// Break immedaitely if pattern can't be followed, exception is when starting.
#include <stdio.h>
int main() {
	int x,y,xc,yc,s;
    scanf("%d %d %d %d %d",&y,&x,&yc,&xc,&s);
    int v[x][y];
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++) v[i][j]=0;
    }
    for(int i=0;i<xc;i++){
        for(int j=0;j<yc;j++) {
            v[i][j]=1;
            v[x-i-1][j]=1;
            v[x-i-1][y-j-1]=1;
            v[i][y-j-1]=1;
        } 
    }
    xc=0; v[xc][yc]=1;
    while(s&&!v[xc][yc+1]){ // first right is optional
        yc++; s--; v[xc][yc]=1;
    }
    while(s){ // cycle
        int f=0;
        while(s&&v[xc][yc+1]){ // down
            xc++; s--; v[xc][yc]=1; f=1;
        }
        if(!f) break; // can't move
        f=0;
        while(s&&yc+1<y&&!v[xc][yc+1]){ // right
            yc++; s--; v[xc][yc]=1; f=1;
        }
        if(!f) break; // can't move
        f=0;
        while(s&&xc+1<x&&!v[xc+1][yc]){ // down
            xc++; s--; v[xc][yc]=1; f=1;
        }
        if(!f) break; // can't move
        f=0;
        while(s&&v[xc+1][yc]){ // left
            yc--; s--; v[xc][yc]=1; f=1;
        }
        if(!f) break; // can't move
        f=0;
        while(s&&xc+1<x&&!v[xc+1][yc]){ // down
            xc++; s--; v[xc][yc]=1; f=1;
        }
        if(!f) break; // can't move
        f=0;
        while(s&&!v[xc][yc-1]){ // left
            yc--; s--; v[xc][yc]=1; f=1;
        }
        if(!f) break; // can't move
        f=0;
        while(s&&v[xc][yc-1]){ // up
            xc--; s--; v[xc][yc]=1; f=1;
        }
        if(!f) break; // can't move
        f=0;
        while(s&&yc>0&&!v[xc][yc-1]){ // left
            yc--; s--; v[xc][yc]=1; f=1;
        }
        if(!f) break; // can't move
        f=0;
        while(s&&!v[xc-1][yc]){ // up
            xc--; s--; v[xc][yc]=1; f=1;
        }
        if(!f) break; // can't move
        f=0;
        while(s&&v[xc-1][yc]){ // right
            yc++; s--; v[xc][yc]=1; f=1;
        }
        if(!f) break; // can't move
        f=0;
        while(s&&!v[xc-1][yc]){ // up
            xc--; s--; v[xc][yc]=1; f=1;
        }
        if(!f) break; // can't move
        f=0;
        while(s&&!v[xc][yc+1]){ // right
            yc++; s--; v[xc][yc]=1; f=1;
        }
        if(!f) break; // can't move
        f=0;
    }
    printf("%d\n%d\n",yc+1,xc+1);
}
