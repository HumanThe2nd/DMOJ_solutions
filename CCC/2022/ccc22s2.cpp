// CCC '22 S2 - Good Groups
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int X,Y,n,c=0;
  unordered_map<string, set<string>> l,b; // l: links, b: bans
  scanf("%d",&X);
  for(int i=0;i<X;i++){
    char c1[11]="",c2[11]="";
    string n1="",n2="";
    scanf("%s %s",c1,c2);
    for(auto x:c1) if(x!=*"") n1+=x;
    for(auto x:c2) if(x!=*"") n2+=x;
    l[n1].insert(n2);
  }
  scanf("%d",&Y);
  for(int i=0;i<Y;i++){
    char c1[11]="",c2[11]="";
    string n1="",n2="";
    scanf("%s %s",c1,c2);
    for(auto x:c1) if(x!=*"") n1+=x;
    for(auto x:c2) if(x!=*"") n2+=x;
    b[n1].insert(n2);
  }
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    char c1[11]="",c2[11]="",c3[11]="";
    string n1="",n2="",n3="";
    scanf("%s %s %s",c1,c2,c3);
    for(auto x:c1) if(x!=*"") n1+=x;
    for(auto x:c2) if(x!=*"") n2+=x;
    for(auto x:c3) if(x!=*"") n3+=x;
    
    if(l.find(n1)!=l.end()){
    auto it = l.find(n1);
    for(auto x: it->second) if(x!=n2&&x!=n3)c++; // link broken
    }
    if(b.find(n1)!=b.end()){
    auto it = b.find(n1);
    for(auto x: it->second) if(x==n2||x==n3)c++; // link broken
    }
    if(l.find(n2)!=l.end()){
    auto it = l.find(n2);
    for(auto x: it->second) if(x!=n1&&x!=n3)c++; // link broken
    }
    if(b.find(n2)!=b.end()){
    auto it = b.find(n2);
    for(auto x: it->second) if(x==n1||x==n3)c++; // link broken
    }
    if(l.find(n3)!=l.end()){
    auto it = l.find(n3);
    for(auto x: it->second) if(x!=n1&&x!=n2)c++; // link broken
    }
    if(b.find(n3)!=b.end()){
    auto it = b.find(n3);
    for(auto x: it->second) if(x==n1||x==n2)c++; // link broken
    }
  }
  printf("%d",c);
}
