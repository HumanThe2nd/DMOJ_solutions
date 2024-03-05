/*
Name: Path Finder
By: Dan Shan
Theory: BFS from left edges and bottom edges to top and right edges
if path found then a path from 1,1 to n,m can't exist
note: the graph can't be represented in a 2d array as theres up to 2.5e12 elements
an unordered set can be used to store all walls in each row/col which is up to 5e5
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,k,xp[]={0,0,-1,1,-1,-1,1,1},yp[]={-1,1,0,0,-1,1,-1,1};
	cin >> n >> m >> k;
	vector<unordered_set<int>> row(n+1),vr(n+1);
	for(int i=0;i<k;i++){
		int a,b;
		cin >> a >> b;
		row[a].insert(b);
	}
	queue<int> qx,qy; 
	for(int i=2;i<=n;i++){
		if(row[i].find(1)==row[i].end()||vr[i].find(1)!=vr[i].end()) continue; 
		vr[i].insert(1);
		qx.emplace(i); qy.emplace(1);
	}
	for(int i=1;i<m;i++){
		if(row[n].find(i)==row[n].end()||vr[n].find(i)!=vr[n].end()) continue; 
		vr[n].insert(i);
		qx.emplace(n); qy.emplace(i);
	}
	while(!qx.empty()){
		int xi=qx.front(), yi=qy.front();
		qx.pop(); qy.pop();
		if(xi==1||yi==m){ // blockage found 
			printf("NO\n");
			return 0;
		}
		for(int i=0;i<8;i++){
			int xii=xi+xp[i],yii=yi+yp[i];
			if(xii>n)continue;
			if(row[xii].find(yii)==row[xii].end()||vr[xii].find(yii)!=vr[xii].end()) continue;
			vr[xii].insert(yii);
			qx.emplace(xii); qy.emplace(yii);
		}
	}
	printf("YES\n"); // no blockage found
}
