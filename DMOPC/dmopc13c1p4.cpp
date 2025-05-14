//============================================================================
// Name        : DMOPC '13 Contest 1 P4 - AFK
// Author      : Dan Shan
//============================================================================
// Goal: Take in a maze and find shortest path if greater than 60 or
//       if impossible print "#notworth"
// Approach: Run BFS from start to end return depth if over 60 or impossible
// print "#notworth"
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main(){
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int l,w,ex,ey,dist=0;
		queue<int> x,y,d;
		scanf("%d %d",&l,&w);
		bool room[w][l],visited[w][l];
		memset(visited, 0, sizeof(visited));
		for(int j=0;j<w;j++){
			char line[l];
			scanf("%s",line);
			for(int k=0;k<l;k++){
				if(line[k]=='C'){x.push(j);y.push(k);}
				else if(line[k]=='W'){ex=j;ey=k;}
				room[j][k]=(line[k]=='X');
			}
		}
		d.push(0);
		while(!x.empty()){
			int xi=x.front(),yi=y.front(),di=d.front();
			if(di>=60){dist=0; break;}
			else if(xi==ex&&yi==ey){dist=di;break;}
			x.pop(); y.pop(); d.pop();
			if(xi<w-1){if(!visited[xi+1][yi]&&!room[xi+1][yi]){
				visited[xi+1][yi]=1;
				x.push(xi+1);y.push(yi);d.push(di+1);}}

				if(xi>0){if(!visited[xi-1][yi]&&!room[xi-1][yi]){
						visited[xi-1][yi]=1;
						x.push(xi-1);y.push(yi);d.push(di+1);}}

				if(yi>0){if(!visited[xi][yi-1]&&!room[xi][yi-1]){
					visited[xi][yi-1]=1;
						x.push(xi);y.push(yi-1);d.push(di+1);}}

				if(yi<l-1){if(!visited[xi][yi+1]&&!room[xi][yi+1]){
						visited[xi][yi+1]=1;
						x.push(xi);y.push(yi+1);d.push(di+1);}}

		}
		if(!dist)printf("#notworth\n");
		else printf("%d\n",dist);
	}
}
