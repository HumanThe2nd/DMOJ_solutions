//============================================================================
// Name        : CCC '10 J5 - Knight Hop
// Author      : Dan Shan
//============================================================================
// Goals: find shortest path for a knight to travel between 2 points
// Approach: Breadth first search sweeping each first second third etc moves until point is reached
#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<vector<int>> moves = {{1, 2}, {2, 1}, {-1, 2},
				{2, -1}, {1, -2}, {-2, 1}, {-1, -2}, {-2, -1}};
	vector<vector<bool>> visited(8, vector<bool>(8));
	int x,y,xf,yf;
	scanf("%d %d %d %d",&x,&y,&xf,&yf);
	int c=0;
	queue<int> qx,qy,dist;
	qx.push(x); qy.push(y); dist.push(c);
	while(x!=xf||y!=yf){
		visited[x-1][y-1]=1;
		c = dist.front(); dist.pop();
		x = qx.front();	qx.pop();
		y = qy.front(); qy.pop();
		if(x==xf&&y==yf) break;
		for(auto p:moves){
			int xd = x+p[0], yd = y+p[1];
			if(xd==xf&&yd==yf) {x=xf;y=yf;c++;break;}
			else if(xd>0&&xd<9&&yd>0&&yd<9&&!visited[xd-1][yd-1]){
				qx.push(xd);qy.push(yd); dist.push(c+1);
			}
		}
	}
	printf("%d\n",c);
}
