// Distinct Array
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int main() {
  unordered_set<int> s;
  int n;
  scanf("%d",&n);
  bool d=1;
  for(int i=0;i<n;i++){
    int in;
    scanf("%d",&in);
    if(s.find(in)!=s.end()) {d=0; break;}
    else s.insert(in);
  }
  if(d) printf("YES");
  else printf("NO");
}
