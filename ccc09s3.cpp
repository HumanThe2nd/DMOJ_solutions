//============================================================================
// Name        : CCC '09 S3 - Degrees Of Separation
// Author      : Dan Shan
//============================================================================
// Goal: - graph edges
//       - check adjacents of points
// 		   - check adjacents of adjacent points
//       - BFS the shorest path
// Approach: complete tasks using bfs and partial bfs
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	unordered_map<int, set<int>> adj;
  adj[1].insert(6);adj[2].insert(6);adj[3].insert(6);adj[4].insert(6);adj[5].insert(6); adj[3].insert(5);adj[3].insert(4);adj[4].insert(5);adj[6].insert(7);adj[7].insert(8); adj[8].insert(9);adj[9].insert(12);adj[9].insert(10);adj[10].insert(11); adj[11].insert(12);adj[3].insert(15);adj[12].insert(13);adj[13].insert(15); adj[13].insert(14);adj[16].insert(18);adj[16].insert(17);adj[17].insert(18);
adj[6].insert(1);adj[6].insert(2);adj[6].insert(3);adj[6].insert(4);adj[6].insert(5); adj[5].insert(3);adj[4].insert(3);adj[5].insert(4);adj[7].insert(6);adj[8].insert(7); adj[9].insert(8);adj[12].insert(9);adj[10].insert(9);adj[11].insert(10); adj[12].insert(11);adj[15].insert(3);adj[13].insert(12);adj[15].insert(13); adj[14].insert(13);adj[18].insert(16);adj[17].insert(16);adj[18].insert(17);
  while(1){
    char in[1];
    int n1,n2;
    scanf("%s",in);
    if(in[0]=='q') break;
    if(in[0]=='n'||in[0]=='f')scanf("%d",&n1);
    else scanf("%d %d",&n1,&n2);
    if(in[0]=='i'){adj[n1].insert(n2);adj[n2].insert(n1);}
    else if(in[0]=='d'){adj[n1].erase(n2);adj[n2].erase(n1);}
    else if(in[0]=='n'){int s=adj[n1].size();
    printf("%d\n",s);}
    else if(in[0]=='f'){
      set<int> ff;
      for(auto x: adj[n1]){
        for(auto y: adj[x]){
          if(adj[n1].find(y)==adj[n1].end()&&x!=n1)
          ff.insert(y);
        }
      }
      int s = ff.size()-1;
      printf("%d\n",s);
    }
    else if(in[0]=='s'){
    	int c=0;
    	unordered_set<int> visited;
    	queue<int> queue,dist;
    	queue.push(n1);
    	dist.push(1);
    	while(!queue.empty()){
    			if(c) break;
    			int s = queue.front();
    			visited.insert(s);
    			int d = dist.front();
    			queue.pop();
    			dist.pop();
    		for(auto x:adj[s]){
    			if(x==n2){c=d;break;}
    			if(visited.find(x)==visited.end()){
    				queue.push(x);
    				dist.push(d+1);
    			}
    		}
    		}
    		if(c)printf("%d\n",c);
    	  else printf("Not connected\n");
    }
  }
}
