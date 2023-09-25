// CCC '16 S1 - Ragaman
// By: Dan Shan
// Approach: Map each character to its number of occurences then go over list 2 and breaking if a character appears more than in map(excludes asterisks)
#include <iostream>
#include <unordered_map>
#include <cstring>
using namespace std;
using ll = long long;
int main(){
	char l1[101],l2[101];
  scanf("%s %s",l1,l2);
  unordered_map<char, int> m;
  for(int i=0;i<strlen(l1);i++){
    char c = l1[i];
    if(m.find(l1[i])==m.end())m[l1[i]]=1;
    else m[l1[i]]++;
  }
  bool a=1;
  for(int i=0;i<strlen(l2);i++){
    char c = l2[i];
    if(l2[i]=='*')continue;
    if(m.find(l2[i])==m.end())a=0;
    else if(m[l2[i]]==0)a=0;
    else m[l2[i]]--;
  }
  if(a)printf("A\n");
  else printf("N\n");
}
