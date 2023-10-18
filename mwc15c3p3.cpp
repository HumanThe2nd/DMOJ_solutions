//============================================================================
// Name        : MWC '15 #3 P3: Bad News
// Author      : Dan Shan
//============================================================================
// Goal: scan a graph if adjacent letters form a word
// Approach: for each word for each occurence of its starting letter try BFS
//           for BFS track depth if depth=word length, good puzzle else bad
#include<bits/stdc++.h>
using namespace std;
int main() {
int n,q;
cin >> n >> q;
char g[n][n];
int dx[] = {0,0,-1,1,1,-1,1,-1}, dy[] = {-1,1,0,0,1,-1,-1,1};
for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		cin>>g[i][j];
	}
}

for(int it=0;it<q;it++){ // taking queries
	string query;
	cin >> query;
	bool good = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){ // iterate grid
			if(g[i][j]==query[0]){
				queue<int> qx,qy,d;
				qx.push(i); qy.push(j); d.push(1);
				bool v[n][n];
				memset(v,0,sizeof(v));
				while(!qx.empty()){
				int xi = qx.front(), yi = qy.front(), di = d.front();
				v[xi][yi]=1;
				if(di==(int)query.length()){good=1; break;}
				qx.pop(); qy.pop(); d.pop();
				for(int b=0;b<8;b++){
					if(xi+dx[b]>=0&&xi+dx[b]<n&&yi+dy[b]>=0&&yi+dy[b]<n){ // prevent seg fault
					if(g[xi+dx[b]][yi+dy[b]]==query[di]&&!v[xi+dx[b]][yi+dy[b]]) {
						qx.push(xi+dx[b]); qy.push(yi+dy[b]); d.push(di+1);
					}
					}
				}
				}
			}
		}
	}
	if(good) printf("good puzzle!\n");
	else printf("bad puzzle!\n");
}
}
