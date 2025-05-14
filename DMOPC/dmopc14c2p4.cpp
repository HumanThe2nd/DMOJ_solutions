// DMOPC '14 Contest 2 P4 - Deforestation
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n,q;
  scanf("%d",&n);
  vector<int> m,psa;
  for(int i=0;i<n;i++){
    int mass;
    scanf("%d",&mass);
    m.push_back(mass);
  }
  psa.push_back(m.front());
  for(int i=1;i<n;i++){
    psa.push_back(psa[i-1]+m[i]);
  }
  scanf("%d",&q);
  for(int i=0;i<q;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d %s",psa[b]-psa[a-1],"\n");
  }
}
