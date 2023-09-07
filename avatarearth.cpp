// PEG Test '14 - Earth
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int x, y,x1,y1,x2,y2;
  scanf("%d %d %d %d %d %d",&x,&y,&x1,&y1,&x2,&y2);
  if(x1<=x&&x2>=x&&y1<=y&&y2>=y) printf("Yes\n");
  else printf("No\n");
}
