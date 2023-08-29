// Battleship Counting
// By: Dan Shan 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int x,y,c=0;
  scanf("%d %d",&x,&y);
  vector<vector<bool>> v;
  for(int i=0;i<x;i++){
    v.push_back({});
    char in[y];
    scanf("%s",in);
    for(int j=0;j<=strlen(in);j++){
      if(in[j]=='#')v[i].push_back(1);
      else v[i].push_back(0);
    }
  }
  for(int i=0;i<x;i++){
    for(int j=0;j<y;j++){
      if(v[i][j]){if(i>0&&j>0){if(!v[i-1][j]&&!v[i][j-1]){c++;}}
                 else if(j>0){if(!v[i][j-1]) {c++;}}
                 else if(i>0){if(!v[i-1][j]) {c++;}}
                 else c++;
                 }
    }
  }
  printf("%d\n",c);
}
