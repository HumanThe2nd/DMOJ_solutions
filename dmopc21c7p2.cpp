// DMOPC '21 Contest 7 P2 - Knitting Scarves
// by: Dan Shan (Assisted by Ivan)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int N,Q;
  scanf("%d %d",&N,&Q);
  vector<int> before(N + 2), after(N + 2);
    for (int i = 0; i < N; i++) {
        before[i] = i - 1;
        after[i] = i + 1;
    }
  for(int i=0;i<Q;i++){
    int s,e,c,t,p;
    scanf("%d %d %d",&s,&e,&c);
    p = before[s];
    after[p] = after[e];
    t = after[e];
    before[t] = before[s];
    t=after[c];
    before[t]=e;
    after[e]=t;
    after[c]=s;
    before[s]=c;
  }
  int i = 0;
  vector<int> r;
  for (int j = 0; j < N; j++) {
      i = after[i];
      r.push_back(i);
  }
  for (int j = 0; j < r.size(); j++) {
      printf("%d %s",r[j],"");
  }
}
