// Another Sorting
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int n;
  scanf("%d",&n);
  vector<int> v;
  for(int i=0;i<n;i++){
    int in;
    scanf("%d",&in);
    v.push_back(in);
  }
  sort(v.begin(),v.end(),[&](int x,int y){return x/10>y/10;});
  stable_sort(v.begin(),v.end(),[&](int x,int y){return x%10<y%10;});
  int s = v.size()-1;
  for(int i=0;i<s;i++){
    printf("%d ",v[i]);
  }
  printf("%d\n",v.back());
}
