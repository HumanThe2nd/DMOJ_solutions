//============================================================================
// Name        : Catch the Cat
// Author      : Dan Shan
//============================================================================
// Goal:
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	int x,y;
	scanf("%d %d",&x,&y);
	unordered_set<int> visited;
	queue<int> queue, t;
  if(x==y)printf("0\n");
  else {
	queue.push(x);
	t.push(1);
	while(!queue.empty()){
		int p = queue.front(),ti = t.front();
		queue.pop(); t.pop();
		if(p*2<=pow(10,5)) {if(p*2==y){printf("%d\n",ti);break;}
				else if(visited.find(p*2)==visited.end()){
					visited.insert(p*2);
					queue.push(p*2);t.push(ti+1);}
							}
		if(p+1<=pow(10,5)) {if(p+1==y){printf("%d\n",ti);break;}
				else if(visited.find(p+1)==visited.end()){
					visited.insert(p+1);
					queue.push(p+1);t.push(ti+1);}
		}
		if(p>0) {if(p-1==y){printf("%d\n",ti);break;}
				else if(visited.find(p-1)==visited.end()){
					visited.insert(p-1);
					queue.push(p-1);t.push(ti+1);}
				}
		if(p/2>=0&&!p%2) {if(p/2==y){printf("%d\n",ti);break;}
				else if(visited.find(p/2)==visited.end()){
					visited.insert(p/2);
					queue.push(p/2);t.push(ti/2);}
				}
	}
  }
}
