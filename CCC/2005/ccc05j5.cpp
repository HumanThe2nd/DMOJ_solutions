// CCC '05 J5 - Bananas
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int main(){
  bool r=1;
  while(r){
  bool monkey=1; 
  char word[10001]="";
  vector<char> w;
  scanf("%s",word);
  int s = strlen(word);
  if(word[0]=='X'&&s==1) break;
  for(int i=0;i<s;i++){
    w.push_back(word[i]);
  }
  while(w.size()>2&&monkey==1){
    int s2 = w.size();
    for(int i=0;i<s2-2;i++){
      if(w[i]=='B'&&w[i+1]=='A'&&w[i+2]=='S'){
        w.erase(w.begin()+i);
        w.erase(w.begin()+i+1);
      }
      if(w[i]=='A'&&w[i+1]=='N'&&w[i+2]=='A'){
        w.erase(w.begin()+i);
        w.erase(w.begin()+i);
      }
    }
    if(w.size()==s2) monkey=0;
  }
  if(w.size()>1) monkey =0;
  if(monkey==1) printf("YES\n");
  else printf("NO\n");
  }
}
