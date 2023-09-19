//============================================================================
// Name        : CCC '03 S3 - Floor Plan
// Author      : Dan Shan
//============================================================================
// Goal: - find out how many rooms you can fill
//       - find the remainder of tiles
// Approach: BFS every point if not visited
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t,x,y,c=0;
	scanf("%d %d %d",&t,&x,&y);
	vector<vector<bool>> visited;
	vector<int> sizes;
	for(int i=0;i<x;i++){
		char row[x];
		vector<bool> r;
		scanf("%s",row);
		for(int j=0;j<y;j++){
			char in=row[j];
			r.push_back(in=='I');
		}
		visited.push_back(r);
	}
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			if(!visited[i][j]){
				int s = 0;
				queue<int> qx,qy;
				qx.push(i);
				qy.push(j);
				while(!qy.empty()){
					int xi = qx.front(); qx.pop();
					int yi = qy.front(); qy.pop();
					if(!visited[xi][yi])s++;
					visited[xi][yi]=1;

					if(xi<x-1){if(!visited[xi+1][yi]){
							qx.push(xi+1);qy.push(yi);}}

					if(xi>0){if(!visited[xi-1][yi]){
							qx.push(xi-1);qy.push(yi);}}

					if(yi>0){if(!visited[xi][yi-1]){
							qx.push(xi);qy.push(yi-1);}}

					if(yi<y-1){if(!visited[xi][yi+1]){
							qx.push(xi);qy.push(yi+1);}}

				}
				sizes.push_back(s);
			}
		}
	}
	sort(sizes.begin(),sizes.end(),greater<>());
	for(auto x:sizes){if(x<=t){t-=x;c++;}else break;}
	if(c!=1)printf("%d rooms, %d square metre(s) left over",c,t);
	else printf("1 room, %d square metre(s) left over",t);
}
