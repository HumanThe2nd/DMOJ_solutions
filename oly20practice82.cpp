// Bob and Bus Stops
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int N,Q;
  scanf("%d %d",&N,&Q);
  vector<int> locations;
  for(int i=0;i<N;i++){
    int p;
    scanf("%d",&p);
    locations.push_back(p);
  }
  sort(locations.begin(),locations.end());
  for(int i =0;i<Q;i++){
    int s,e,d;
    scanf("%d %d",&s,&e);
    d = upper_bound(locations.begin(),locations.end(),e)- lower_bound(locations.begin(),locations.end(),s);
    printf("%d %s",d,"\n");
  }
}
