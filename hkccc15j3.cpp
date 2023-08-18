// CCCHK '15 J3 - Queens can't attack me!
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m,c=0;
  scanf("%d %d",&n,&m);
  vector<vector<bool>> board;
  for(int i=0;i<n;i++){
    vector<bool> row (n,false);
    board.push_back(row);
  }
  for(int i=0;i<m;i++){
    int x,y;
    scanf("%d %d",&x,&y);
    x--;
    y--;
    for(int i=0;i<n;i++){
      if(board[i][x]==false) board[i][x] = true;
      if(board[y][i]==false) board[y][i] = true;
      if(x+i<n&&y+i<n) 
      if(board[y+i][x+i]==false) board[y+i][x+i]=true;
      if(x+i<n&&y-i>-1) 
      if(board[y-i][x+i]==false) board[y-i][x+i]=true;
      if(x-i>-1&&y+i<n) 
      if(board[y+i][x-i]==false) board[y+i][x-i]=true;
      if(x-i>-1&&y-i>-1) 
      if(board[y-i][x-i]==false) board[y-i][x-i]=true;
    }
  }
  for(auto x:board) for(auto y:x) if(y==false)c++;
  printf("%d",c);
}
