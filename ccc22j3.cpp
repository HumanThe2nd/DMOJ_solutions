// CCC '22 J3 - Harp Tuning
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int main(){
  char in[10001];
  scanf("%s",in);
  vector<char> s;
  vector<char> n;
  unordered_set<char> nums ={'0','1','2','3','4','5','6','7','8','9'};
  for(int i=0;i<strlen(in);i++){
    if(in[i]=='+') {
    for(auto x:s)printf("%c",x);
    s.clear(); printf(" tighten "); }
    else if(in[i]=='-') {
    for(auto x:s)printf("%c",x);
    s.clear(); printf(" loosen "); }
    else if(nums.find(in[i])!=nums.end()) n.push_back(in[i]);
    else if(i!=0&&nums.find(in[i-1])!=nums.end()){
    for(auto x:n) printf("%c",x); printf("\n"); n.clear();
    s.push_back(in[i]);}
    else s.push_back(in[i]);
  }
  for(auto x:n) printf("%c",x); printf("\n"); n.clear();
}
