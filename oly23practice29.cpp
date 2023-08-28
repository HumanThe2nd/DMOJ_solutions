// Angry Kids
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,s,c=1;
  scanf("%d %d",&n,&s);
  set<int> kids = {s};
  for(int i=1;i<n;i++){
    int in;
    scanf("%d",&in);
    if(in<*kids.begin()) c++;
    kids.insert(in);
  }
  printf("%d\n",c);
}
