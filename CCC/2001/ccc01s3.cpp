// CCC '01 S3 - Strategic Bombing
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class graph{
  public:
  unordered_map<char, list<char>> adj;
  void addEdge(char s, char e);
  void remove(char s, char e);
  bool BFS(char s);
};
void graph::addEdge(char s,char e){
  adj[s].push_back(e);
  adj[e].push_back(s);
}
void graph::remove(char s, char e){
  adj[s].remove(e);
  adj[e].remove(s);
}
bool graph::BFS(char s){
  unordered_set<char> visited;
  bool reach = 0;
  list<char> queue;
  visited.insert(s);
  queue.push_back(s);
  while(!queue.empty()){
    s = queue.front();
    if(s=='B'){reach =1;break; break;}
    queue.pop_front();
    for(auto x: adj[s]){
      if(x=='B'){reach =1;break; break;}
      if(visited.find(x)==visited.end()){
        visited.insert(x);
        queue.push_back(x);
      }
    }
  }
  return reach;
}
int main(){
  int c=0;
  bool r=1;
  graph g;
  vector<int> S,E;
  while(r){
    char in[2];
    scanf("%s",in);
    if(in[0]=='*') break;
    g.addEdge(in[0],in[1]);
    S.push_back(in[0]);
    E.push_back(in[1]);
  }
  int n = S.size();
  for(int i=0;i<n;i++){
  int s = S[i], e= E[i];
  g.remove(s,e);
  if(!g.BFS('A')){c++;printf("%c%c\n",s,e);}
  g.addEdge(s,e);
  }
  printf("There are %d disconnecting roads.\n",c);
}
