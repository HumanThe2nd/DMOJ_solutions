//============================================================================
// Name        : HCCC '08 S3 - Maze
// Author      : Dan Shan
//============================================================================
// Goal: for t cases: given a
// Approach: create a graph and run BFS if unreachable distance will be
//           -1 otherwise it will be the distance
#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
int main() {
int t;
scanf("%d",&t);
for(int _=0;_<t;_++){
	int r,c,dist=-1;
	scanf("%d %d",&r,&c);
	bool visited[r][c];
	char graph[r][c];
	for(int i=0;i<r;i++){
		char row[c];
		scanf("%s",row);
		for(int j=0;j<c;j++){
			if(row[j]=='*')visited[i][j]=1;
			else visited[i][j]=0;
			graph[i][j]=row[j];
		}
	}
	queue<int> qx,qy,d;
	qx.push(0);qy.push(0);d.push(1);
	while(!qx.empty()){
		int xi = qx.front(),yi = qy.front(),di = d.front();
		if(xi==r-1&&yi==c-1){dist=di;break;}
		qx.pop(); qy.pop(); d.pop();
		if(xi<r-1){if(!visited[xi+1][yi]&&graph[xi][yi]!='-'){
						visited[xi+1][yi]=1;
						qx.push(xi+1);qy.push(yi);d.push(di+1);}}

		if(xi>0){if(!visited[xi-1][yi]&&graph[xi][yi]!='-'){
						visited[xi-1][yi]=1;
						qx.push(xi-1);qy.push(yi);d.push(di+1);}}

		if(yi>0){if(!visited[xi][yi-1]&&graph[xi][yi]!='|'){
						visited[xi][yi-1]=1;
						qx.push(xi);qy.push(yi-1);d.push(di+1);}}

		if(yi<c-1){if(!visited[xi][yi+1]&&graph[xi][yi]!='|'){
						visited[xi][yi+1]=1;
						qx.push(xi);qy.push(yi+1);d.push(di+1);}}

	}
	printf("%d\n",dist);
}
}
