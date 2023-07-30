// DMPG '18 G1 - Musical Chairs
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n,k,res;
  unordered_set<int> e;
  unordered_map<int, int> m; // key: location, num value: student
  scanf("%d %d",&n,&k);
  for(int i=1;i<k+1;i++){
    int in;
    scanf("%d",&in);
    e.insert(in);
  }
  for(int i=1;i<k+2;i++){
    int in;
    scanf("%d",&in);
    m[in] = i;
  }
  stack<int> p;
  for(int i=1;i<n+1;i++){
    if(m.find(i)!=m.end()){ 
    auto it = m.find(i);
    res = it->second;
    p.push(res);
    }
    if(e.find(i)!=e.end()&&p.size()!=0) p.pop();
    }
  for(int i=1;i<n+1;i++){
    if(e.find(i)!=e.end()&&p.size()>1) p.pop();
    }
  printf("%d %s",p.top(),"\n");
}
