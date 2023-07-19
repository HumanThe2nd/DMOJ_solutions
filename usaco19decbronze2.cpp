// USACO 2019 December Bronze P2 - Where Am I?
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  unordered_set<string> p;
  int n,m=1,l=1,hi;
  string hs="";
  scanf("%d",&n);
  char c[100];
  scanf("%s",c);
  for (int len = 1; len <= n; len++)
    {   
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;           
            for (int k = i; k <= j; k++){
              hs+=c[k];
            }
          if(find(p.begin(),p.end(),hs)==p.end()) p.insert(hs);
          else {if(hs.length()+1>m)m=hs.length()+1;}
          hs="";
        }
    }
  printf("%d %s",m,"\n");
}
