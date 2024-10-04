// CCC '04 S1 - Fix
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  unordered_set<string> s;
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    bool p=1;
    for(int j=0;j<3;j++){
    string in;
    cin >> in;
    if(s.find(in)!=s.end()) p=0;
    else s.insert(in);
    }
    for(auto x:s){
    for(int k=0;k<x.length()-1;k++){
    if(s.find(x.substr(0,k))!=s.end())
    p=0;
    if(s.find(x.substr(x.length()-k-1,x.length()))!=s.end()) p=0;
    }
  }
    if(p) printf("Yes\n");
    else printf("No\n");
    s.clear();
    
  }
}
