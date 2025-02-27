//============================================================================
// Name        : COCI '06 Contest 1 #4 Slikar
// Author      : Dan Shan
//============================================================================
// Goal: minimum path between 2 points on a graph
// Approach: flood once each time t increases while running BFS, print time if d reached
// note: coordinates are 0 indexed
#include<bits/stdc++.h>
int r,c,Dx,Dy,sx,sy,fx,fy; // f for the flood
int dx[] = {-1,1,0,0},dy[] = {0,0,-1,1};
int main(){
scanf("%d %d",&r,&c);
bool g[r][c];
std::queue<int> qx,qy,qt,qfx,qfy,qft; // main bfs for path and second bfs for flood
for(int i=0;i<r;i++){
	char col[c+1];
	scanf("%s",col);
	for(int j=0;j<c;j++){
		if(col[j]=='*'){qfx.push(i); qfy.push(j); qft.push(0);}
		else if(col[j]=='D'){Dx=i;Dy=j;}
		else if(col[j]=='S'){sx=i;sy=j;}
		g[i][j]=col[j]=='.'||col[j]=='D'; // mark 0 for invalid squares 1 otherwise
	}
}
qx.push(sx); qy.push(sy); qt.push(1);
while(!qx.empty()){ // BFS movements
	int xi = qx.front(),yi = qy.front(),ti = qt.front();
	for(int i=0;i<4;i++){
		    if(dx[i]+xi>=0 && dx[i]+xi<r && dy[i]+yi>=0 && dy[i]+yi<c && g[dx[i]+xi][dy[i]+yi]){
		        if(dx[i]+xi==Dx&&dy[i]+yi==Dy){
		            printf("%d\n",ti);
		            return 0; // end program when den reached
		        }
		        g[dx[i]+xi][dy[i]+yi]=0; // prevent revisit
		        qx.push(dx[i]+xi); qy.push(dy[i]+yi); qt.push(ti+1);
		    }
		}
	if(qft.front()<=ti){ // flood moves if time increases
		while(!qfx.empty()&&ti>=qft.front()){ // flood BFS
			int fxi = qfx.front(), fyi= qfy.front(),tfi = qft.front();
			qfx.pop(); qfy.pop(); qft.pop();
			for(int i=0;i<4;i++){
			    if(dx[i]+fxi>=0 && dx[i]+fxi<r && dy[i]+fyi>=0 && dy[i]+fyi<c && g[dx[i]+fxi][dy[i]+fyi]
			        &&(dx[i]+fxi!=Dx||dy[i]+fyi!=Dy)){
			        g[dx[i]+fxi][dy[i]+fyi]=0; // floods adjacent squares
			        qfx.push(dx[i]+fxi); qfy.push(dy[i]+fyi); qft.push(tfi+1);
			    }
			}

		}
	}
	qx.pop(); qy.pop(); qt.pop();

}
printf("KAKTUS\n"); // if unreachable output KAKTUS
}
