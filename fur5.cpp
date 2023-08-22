// PEG Test '11 - Cyclopian Puzzle
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
void hanoi(int n,char s, char e, char h){
  if(!n) return;
  hanoi(n-1,s,h,e);
  printf("%c%c\n",s,e);
  hanoi(n-1,h,e,s);
}
int main(){
  int n;
  scanf("%i",&n);
  hanoi(n,'A','C','B');
}
