// COCI '16 Contest 2 #3 Nizin
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n,b=0,c=0;
  deque<int> a;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    int in;
    scanf("%d",&in);
    a.push_back(in);
  }
  while(b==0){
    if(a.size()<2) break;
    if(a.front()==a.back()){
      a.pop_back();
      a.pop_front();
    }
    if(a.front()>a.back()){
      int h = a.back();
      c++;
      a.pop_back();
      a.back()+=h;
    }
    if(a.front()<a.back()){
      int h = a.front();
      c++;
      a.pop_front();
      a.front()+=h;
    }
  }
  printf("%d",c);
}
