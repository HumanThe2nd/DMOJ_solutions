// CCC '00 S2 - Babbling Brooks
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n;
  scanf("%d",&n);
  bool run =1;
  vector<double> streams;
  while(run==1){
    int i;
    scanf("%d",&i);
    if(i==77)break; // end 
    else if(i==88){ // join
      int s;
      scanf("%d",&s);
      streams[s-1] += streams[s];
      streams.erase(streams.begin()+s);
    }
    else if(i==99){ // split
      double n2,p; // percentage that flows left
      scanf("%lf %lf",&n2,&p);
      streams.insert(streams.begin()+n2-1,0);
      streams[n2-1] = streams[n2]*p/100;
      streams[n2] *= (100-p)/100;
    }
    else streams.push_back(i);
    for(auto x:streams){
  }
  }
  for(auto x:streams){
    printf("%d %s",int(x),"");
  }
}
