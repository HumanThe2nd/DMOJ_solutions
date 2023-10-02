//============================================================================
// Name        : HCI '16 - Oversleep
// Author      : Dan Shan
//============================================================================
// Goal: Find shortest path in maze and determine if possible to finish
// Approach: create a graph and run BFS if unreachable distance will be
//           -1 otherwise it will be the distance
#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
int main() {
int x,y,ex,ey;
scanf("%d %d",&x,&y);
bool visited[x][y];
queue<int> qx,qy,d;
for(int i=0;i<x;i++){
	char row[y];
	scanf("%s",row);
	for(int j=0;j<y;j++){
		if(row[j]=='s'){qx.push(i),qy.push(j);d.push(-1);}
		else if(row[j]=='e'){ex=i;ey=j;}
		visited[i][j]=row[j]=='X';
	}
}
int dist = -1;
while(!qx.empty()){
	int xi = qx.front(),yi = qy.front(),di = d.front();
	if(xi==ex&&yi==ey){dist=di;break;}
	qx.pop(); qy.pop(); d.pop();
	if(xi<x-1){if(!visited[xi+1][yi]){
					visited[xi+1][yi]=1;
					qx.push(xi+1);qy.push(yi);d.push(di+1);}}

	if(xi>0){if(!visited[xi-1][yi]){
					visited[xi-1][yi]=1;
					qx.push(xi-1);qy.push(yi);d.push(di+1);}}

	if(yi>0){if(!visited[xi][yi-1]){
					visited[xi][yi-1]=1;
					qx.push(xi);qy.push(yi-1);d.push(di+1);}}

	if(yi<y-1){if(!visited[xi][yi+1]){
					visited[xi][yi+1]=1;
					qx.push(xi);qy.push(yi+1);d.push(di+1);}}

}
printf("%d\n",dist);
}
